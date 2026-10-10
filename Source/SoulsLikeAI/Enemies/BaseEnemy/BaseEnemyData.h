// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BaseEnemyData.generated.h"

class UBaseSense;

/**
 * Everything one enemy type is built from. Each enemy gets its own asset, duplicated from DA_BaseEnemy.
 * Shared by every enemy that uses it, so it is read-only at runtime.
 */
UCLASS()
class SOULSLIKEAI_API UBaseEnemyData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	/** This enemy's sense entries. May contain empty entries. */
	const TArray<TObjectPtr<UBaseSense>>& GetSenses() const {return Senses;}
	
protected:
	/** Senses this enemy perceives with, one entry per sense. Each new entry starts with that sense's defaults. */
	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Senses", meta = (NoElementDuplicate))
	TArray<TObjectPtr<UBaseSense>> Senses;
};
