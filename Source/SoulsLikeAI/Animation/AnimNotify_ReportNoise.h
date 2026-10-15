// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_ReportNoise.generated.h"

/**
 * Reports a noise to AI hearing, with the mesh's owner as the instigator: the owner's team decides who hears it.
 */
UCLASS(const, HideCategories = Object, CollapseCategories, meta = (DisplayName = "Report Noise"))
class SOULSLIKEAI_API UAnimNotify_ReportNoise : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
protected:
	/** Scales the listener's hearing range: the noise is heard within hearing range × loudness. */
	UPROPERTY(EditAnywhere, Category = "Noise", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float Loudness = 1.f;
	
	/** The flat distance at which this noise is heard, the same for every enemy; 0 means Loudness decides. */
	UPROPERTY(EditAnywhere, Category = "Noise", meta = (ClampMin = "0.0", UIMin = "0.0", Units = "Centimeters"))
	float MaxRange = 0.f;
	
};
