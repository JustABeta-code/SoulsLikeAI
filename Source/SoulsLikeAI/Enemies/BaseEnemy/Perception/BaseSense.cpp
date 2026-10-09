// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSense.h"
#include "Perception/AISenseConfig.h"

UAISenseConfig* UBaseSense::CreateSenseConfig(UObject& Outer) const
{
	UAISenseConfig* Config = NewSenseConfig(Outer);
	if (Config)
	{
		Config->SetMaxAge(MaxAge);
	}
	return Config;
}
