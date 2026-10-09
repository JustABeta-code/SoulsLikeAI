// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSense.h"
#include "SightSense.generated.h"

/**
 * 
 */

UCLASS(meta = (DisplayName = "Sight"))
class SOULSLIKEAI_API USightSense : public UBaseSense
{
	GENERATED_BODY()
	
public:
	USightSense();
	
protected:
	virtual UAISenseConfig* NewSenseConfig(UObject& Outer) const override;
	
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float SightRadius = 1500.f;
	
	/** Extra distance beyond Sight Radius before a target already seen is lost. Sight Radius (1500) + this (500) = Lose-sight radius (2000).
	 */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float LoseSightMargin = 500.f;
	
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", ClampMax = "360.0", UIMax = "360.0", Units = "Degrees"))
	float PeripheralVisionAngle = 120.f;
};
