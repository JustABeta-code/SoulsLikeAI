// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AISenseConfig.h"
#include "UObject/Object.h"
#include "BaseEnemy_BaseSense.generated.h"

/**
 * 
 */
UCLASS(Abstract, EditInlineNew)
class SOULSLIKEAI_API UBaseEnemy_BaseSense : public UObject
{
	GENERATED_BODY()
	
public:
	UAISenseConfig* CreateSenseConfig(UObject& Outer) const;
	
protected:
	virtual UAISenseConfig* NewSenseConfig(UObject& Outer) const PURE_VIRTUAL(UBaseEnemy_BaseSense::NewSenseConfig, return nullptr;);
	
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Seconds"))
	float MaxAge = 0.f;
};
