// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseAIController.h"

#include "SoulsLikeAI.h"
#include "SoulsLikeAITeams.h"

#include "Perception/AISenseConfig.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AIPerceptionComponent.h"

#include "Enemies/BaseEnemy/BaseEnemy.h"
#include "Enemies/BaseEnemy/BaseEnemyData.h"
#include "Enemies/BaseEnemy/Perception/BaseSense.h"

#include "VisualLogger/VisualLogger.h"

ABaseAIController::ABaseAIController(){
	/** Set before perception registers: SetGenericTeamId doesn't notify it,
	 * and its listener copies the team only when it registers or updates. */
	AAIController::SetGenericTeamId(SoulsLikeTeams::Enemies);
	
	UAIPerceptionComponent* Perception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
	// Registered in SetupPerception, once the pawn's data is known.
	Perception->bAutoRegister = false;
	SetPerceptionComponent(*Perception);
}

void ABaseAIController::SetNewState(ECombatState NewState)
{
	// Callers may report the current state again (every footstep heard while investigating),
	// so only a change counts.
	if (NewState == CombatState)
	{
		return;
	}
	
	const ECombatState OldState = CombatState;
	CombatState = NewState;
	
	const UEnum* StateEnum = StaticEnum<ECombatState>();
	UE_VLOG_UELOG(this, LogEnemyAI, Log, TEXT("%s: %s -> %s"), *GetName(),
		   *StateEnum->GetNameStringByValue(static_cast<int64>(OldState)),
		   *StateEnum->GetNameStringByValue(static_cast<int64>(NewState)));
}

void ABaseAIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UE_LOG(LogEnemyAI, Log, TEXT("%s possessed %s"), *GetName(), *GetNameSafe(InPawn));
	
	SetupPerception();
}

void ABaseAIController::OnUnPossess()
{
	
	
	Super::OnUnPossess();
}

void ABaseAIController::SetupPerception()
{
	UAIPerceptionComponent* Perception = GetAIPerceptionComponent();
	// Only the first pawn sets up perception: an AI controller is destroyed along with its pawn.
	if (Perception == nullptr || Perception->IsRegistered() || GetPawn() == nullptr)
	{
		return;
	}
	
	const ABaseEnemy* Enemy = Cast<ABaseEnemy>(GetPawn());

	if (const UBaseEnemyData* EnemyData = Enemy ? Enemy->GetEnemyData() : nullptr; EnemyData == nullptr)
	{
		UE_LOG(LogEnemyAI, Warning, TEXT("%s: %s has no enemy data, so its perception has no senses"), *GetName(), *GetPawn()->GetName());
	}
	else
	{
		// Config classes added so far: ConfigureSense would replace an earlier config of the same class.
		TSet<const UClass*> ConfigClasses;
		for (const UBaseSense* Sense : EnemyData->GetSenses())
		{
			if (Sense == nullptr)
			{
				continue;
			}
			
			UAISenseConfig* Config = Sense->CreateSenseConfig(*Perception);
			if (!ensureMsgf(Config, TEXT("%s created no sense config"), *Sense->GetClass()->GetName()))
			{
				continue;
			}
			
			bool bAlreadyAdded = false;
			ConfigClasses.Add(Config->GetClass(), &bAlreadyAdded);
			if (bAlreadyAdded)
			{
				UE_LOG(LogEnemyAI, Warning, TEXT("%s: %s has more than one %s entry; only the first is used"), *GetName(), *EnemyData->GetName(), *Sense->GetClass()->GetName());
				continue;
			}
			// Before registration this only stores the config; RegisterComponent then sets up every sense at once.
			Perception->ConfigureSense(*Config);
		}
	}
	
	Perception->OnTargetPerceptionInfoUpdated.AddDynamic(this, &ABaseAIController::HandleTargetPerceptionInfoUpdated);
	Perception->RegisterComponent();
}

void ABaseAIController::HandleTargetPerceptionInfoUpdated(const FActorPerceptionUpdateInfo& UpdateInfo)
{
	const AActor* Target = UpdateInfo.Target.Get();
	const FAIStimulus& Stimulus = UpdateInfo.Stimulus;
	UE_LOG(LogEnemyAI, Verbose, TEXT("%s: %s %s (%s)"), *GetName(), Stimulus.WasSuccessfullySensed() ? TEXT("sensed") : TEXT("lost"), *GetNameSafe(UpdateInfo.Target.Get()), *GetNameSafe(UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus).Get()));
	
	if (Target == nullptr)
	{
		return;
	}
	
	if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
	{
		SetNewState(ECombatState::Combat);
	}
	
}
