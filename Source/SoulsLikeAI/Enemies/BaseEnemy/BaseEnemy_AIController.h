
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseEnemy_AIController.generated.h"

/**
 * 
 */
UCLASS()
class SOULSLIKEAI_API ABaseEnemy_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseEnemy_AIController();
	
protected:
	
	virtual void OnPossess(class APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
