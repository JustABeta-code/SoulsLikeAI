// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/BaseEnemy/BaseEnemy_AIController.h"

#include "SoulsLikeAI.h"

ABaseEnemy_AIController::ABaseEnemy_AIController(){
	
}

void ABaseEnemy_AIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	UE_LOG(LogEnemyAI, Log, TEXT("%s possessed %s"), *GetName(), *GetNameSafe(InPawn))
}

void ABaseEnemy_AIController::OnUnPossess()
{
	
	
	Super::OnUnPossess();
}
