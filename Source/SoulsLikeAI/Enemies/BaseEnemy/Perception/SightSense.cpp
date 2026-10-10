// Fill out your copyright notice in the Description page of Project Settings.


#include "SightSense.h"
#include "Perception/AISenseConfig_Sight.h"

USightSense::USightSense()
{
	MaxAge = 5.f;
}

UAISenseConfig* USightSense::NewSenseConfig(UObject& Outer) const
{
	UAISenseConfig_Sight* Config = NewObject<UAISenseConfig_Sight>(&Outer);
	
	Config->SightRadius = SightRadius;
	Config->LoseSightRadius = SightRadius + LoseSightMargin;
	Config->PeripheralVisionAngleDegrees = PeripheralVisionHalfAngle;
	
	Config->DetectionByAffiliation.bDetectEnemies = true;
	Config->DetectionByAffiliation.bDetectNeutrals = false;
	Config->DetectionByAffiliation.bDetectFriendlies = false;
	
	return Config;
}
