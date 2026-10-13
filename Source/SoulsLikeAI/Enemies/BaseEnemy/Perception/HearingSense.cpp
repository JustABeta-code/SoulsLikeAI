// Fill out your copyright notice in the Description page of Project Settings.


#include "HearingSense.h"
#include "Perception/AISenseConfig.h"
#include "Perception/AISenseConfig_Hearing.h"

UHearingSense::UHearingSense()
{
	// A heard noise is never "lost", only expired; with 0 it would stay sensed forever.
	MaxAge = 3.f;
}

UAISenseConfig* UHearingSense::NewSenseConfig(UObject& Outer) const
{
	UAISenseConfig_Hearing* Config = NewObject<UAISenseConfig_Hearing>(&Outer);
	Config -> HearingRange = HearingRange;
	
	Config->DetectionByAffiliation.bDetectEnemies		= true;
	Config->DetectionByAffiliation.bDetectNeutrals		= false;
	Config->DetectionByAffiliation.bDetectFriendlies	= false;
	
	return Config;
}
