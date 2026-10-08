// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy_BaseSense.h"
#include "Perception/AISenseConfig.h"

UAISenseConfig* UBaseEnemy_BaseSense::CreateSenseConfig(UObject& Outer) const
{
	UAISenseConfig* Config = NewSenseConfig(Outer);
	if (Config)
	{
		Config->SetMaxAge(MaxAge);
	}
	return Config;
}

