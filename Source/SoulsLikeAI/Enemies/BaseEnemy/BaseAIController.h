
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enemies/BaseEnemy/CombatState.h"
#include "Perception/AIPerceptionComponent.h"
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
	
	ECombatState GetCombatState() const {return CombatState;};
	
	void SetNewState(ECombatState NewState);
	
protected:
	
	virtual void OnPossess(class APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
private:
	/** Sets up perception from the possessed enemy's data and registers it. Runs once, for the first pawn. */
	void SetupPerception();
	
	/** Called when perception of a target changes; Target is null if the actor no longer exists. */
	UFUNCTION()
	void HandleTargetPerceptionInfoUpdated(const FActorPerceptionUpdateInfo& UpdateInfo);
	
	
	/** Reacts to a sight update of a target that still exists. */
	void HandleSight(const AActor& Target, const FAIStimulus& Stimulus);

	/** Reacts to a hearing update of a target that still exists. */
	void HandleHearing(const AActor& Target, const FAIStimulus& Stimulus);
	
	
	/** Changed only through SetNewState. */
	ECombatState CombatState = ECombatState::Idle;
	
	/** Sets where the enemy searches. The only writer of SearchLocation. */
	void SetSearchLocation(const FVector& Location);
	
	/** Where the enemy searches while investigating. Changed only through SetSearchLocation. */
	FVector SearchLocation = FAISystem::InvalidLocation;
};
