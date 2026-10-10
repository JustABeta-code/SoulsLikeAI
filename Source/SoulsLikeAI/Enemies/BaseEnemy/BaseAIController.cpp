// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseAIController.h"

#include "SoulsLikeAI.h"
#include "Perception/AIPerceptionComponent.h"

ABaseAIController::ABaseAIController(){
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
