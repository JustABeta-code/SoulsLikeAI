// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseEnemy_AIController.h"

#include "SoulsLikeAI.h"
#include "Perception/AIPerceptionComponent.h"

ABaseEnemy_AIController::ABaseEnemy_AIController(){
	UAIPerceptionComponent* Perception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
	SetPerceptionComponent(*Perception);
	
}

void ABaseEnemy_AIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UE_LOG(LogEnemyAI, Log, TEXT("%s possessed %s"), *GetName(), *GetNameSafe(InPawn));
}

void ABaseEnemy_AIController::OnUnPossess()
{
	
	
	Super::OnUnPossess();
}
