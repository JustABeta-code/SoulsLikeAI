// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * Perception team IDs. By the engine's default rule, different IDs are hostile and equal IDs friendly.
 * 255 is reserved for the engine's NoTeam.
 */
namespace SoulsLikeTeams
{
	constexpr uint8 Player = 0;
	constexpr uint8 Enemies = 1;
}