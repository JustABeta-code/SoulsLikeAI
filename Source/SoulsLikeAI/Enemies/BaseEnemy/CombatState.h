// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatState.generated.h"

/** The enemy's phase of awareness, driven by its senses. Only ABaseAIController::SetNewState changes it. */
UENUM()
enum class ECombatState : uint8
{
	/** Idle: Nothing known, standing still, the starting state. */
	/** Patrol: Nothing known, following its route. */
	/** Investigate: Something heard, or the target lost, checking a location. */
	/** Combat: The target is known, fighting it. */
	
	Idle,
	Patrol,
	Investigate,
	Combat
};
