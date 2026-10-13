// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_ReportNoise.h"
#include "Components/SkeletalMeshComponent.h"
#include "Perception/AISense_Hearing.h"

void UAnimNotify_ReportNoise::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	// No Super call: the base only forwards to the Blueprint event, as in the engine's Play Sound notify.
	AActor* Owner = MeshComp ? MeshComp->GetOwner() : nullptr;
	if (Owner == nullptr)
	{
		// Without an owner the noise would have no team, which enemies hear as hostile.
		return;
	}
	
	// At the mesh origin, a character's feet.
	UAISense_Hearing::ReportNoiseEvent(MeshComp, MeshComp->GetComponentLocation(), Loudness, Owner, MaxRange);
}
