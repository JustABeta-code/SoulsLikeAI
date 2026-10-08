// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseEnemy_BaseSense.generated.h"

class UAISenseConfig;

/**
 * 
 */
UCLASS(Abstract, EditInlineNew)
class SOULSLIKEAI_API UBaseEnemy_BaseSense : public UObject
{
	GENERATED_BODY()
	
public:
	/** Creates the engine config for this sense, owned by Outer and filled with this entry's values. */
	UAISenseConfig* CreateSenseConfig(UObject& Outer) const;
	
protected:
	/** Creates the matching engine config and fills the fields only this sense has. */
	virtual UAISenseConfig* NewSenseConfig(UObject& Outer) const PURE_VIRTUAL(UBaseEnemy_BaseSense::NewSenseConfig, return nullptr;);
	
	/** Seconds before a stimulus from this sense expires. 0 means never. */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Seconds"))
	float MaxAge = 0.f;
};
