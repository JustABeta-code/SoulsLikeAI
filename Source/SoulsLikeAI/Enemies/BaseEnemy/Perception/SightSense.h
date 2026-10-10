// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSense.h"
#include "SightSense.generated.h"

/** Sight entry for an enemy's Senses list. Reports enemies only; that rule is in code, not data. */
UCLASS(meta = (DisplayName = "Sight"))
class SOULSLIKEAI_API USightSense : public UBaseSense
{
	GENERATED_BODY()
	
public:
	USightSense();
	
protected:
	virtual UAISenseConfig* NewSenseConfig(UObject& Outer) const override;
	
	/** Distance at which a target is first seen. */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float SightRadius = 1500.f;
	
	/** Extra distance beyond Sight Radius before a target already seen is lost. Sight Radius + this = Lose-sight radius. */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float LoseSightMargin = 500.f;
	
	/** Angle to each side of the forward direction; the whole cone is twice this. 180 sees all around. */
	UPROPERTY(EditAnywhere, Category = "Sense", meta = (ClampMin = "0.0", UIMin = "0.0", ClampMax = "180.0", UIMax = "180.0", Units = "Degrees"))
	float PeripheralVisionHalfAngle = 60.f;
};
