// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseAIController.h"

#include "SoulsLikeAI.h"
#include "SoulsLikeAITeams.h"
#include "Enemies/BaseEnemy/BaseEnemy.h"
#include "Perception/AIPerceptionComponent.h"

ABaseAIController::ABaseAIController(){
	// Set before perception registers: SetGenericTeamId doesn't notify it, and its listener copies the team only when it registers or updates.
	AAIController::SetGenericTeamId(SoulsLikeTeams::Enemies);
	
	UAIPerceptionComponent* Perception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
	// Registered in SetupPerception, once the pawn's data is known.
	Perception->bAutoRegister = false;
	SetPerceptionComponent(*Perception);
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
	
	Perception->RegisterComponent();
}
