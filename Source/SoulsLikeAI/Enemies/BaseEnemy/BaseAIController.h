
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOULSLIKEAI_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABaseAIController();
	
protected:
	
	virtual void OnPossess(class APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
