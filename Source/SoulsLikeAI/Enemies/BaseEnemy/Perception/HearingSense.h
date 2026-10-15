// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSense.h"
#include "HearingSense.generated.h"

/** Hearing entry for an enemy's Senses list. Hears hostile noises only (a noise with no team counts as hostile); that rule is in code, not data. */
UCLASS(meta = (DisplayName = "Hearing"))
class SOULSLIKEAI_API UHearingSense : public UBaseSense
{
	GENERATED_BODY()
	
public:
	UHearingSense();
	
protected:
	virtual UAISenseConfig* NewSenseConfig(UObject& Outer) const override;
	
	/** Farthest distance at which this enemy hears a noise of loudness 1; the noise's loudness multiplies it. A noise's Max Range can shorten this distance, never extend it. */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float HearingRange = 1000.f;
};
