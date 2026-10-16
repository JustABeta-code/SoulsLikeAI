// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatState.generated.h"

/** The enemy's phase of awareness, driven by its senses. Only ABaseAIController::SetNewState changes it. */
UENUM()
enum class ECombatState : uint8
{
	/** Nothing known, standing still: the starting state. */
	Idle,
	/** Nothing known: following its route. */
	Patrol,
	/** Something heard, or the target lost: checking a location. */
	Investigate,
	/** The target is known: fighting it. */
	Combat
};
