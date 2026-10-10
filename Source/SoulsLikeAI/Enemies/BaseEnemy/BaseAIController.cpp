// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseAIController.h"

#include "SoulsLikeAI.h"
#include "SoulsLikeAITeams.h"
#include "Perception/AIPerceptionComponent.h"

ABaseAIController::ABaseAIController(){
	// Set before perception registers: the listener copies the team only then.
	SetGenericTeamId(SoulsLikeTeams::Enemies);
	
	UAIPerceptionComponent* Perception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
	SetPerceptionComponent(*Perception);
}

void ABaseAIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UE_LOG(LogEnemyAI, Log, TEXT("%s possessed %s"), *GetName(), *GetNameSafe(InPawn));
}

void ABaseAIController::OnUnPossess()
{
	
	
	Super::OnUnPossess();
}
