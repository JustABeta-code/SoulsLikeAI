// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseEnemy.generated.h"

class UBaseEnemyData;

/**
 * Base for every enemy pawn. Holds the data asset the enemy is built from.
 */
UCLASS(Abstract)
class SOULSLIKEAI_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseEnemy();
	
	/** The data asset this enemy is built from. Null if none is assigned. */
	const UBaseEnemyData* GetEnemyData() const {return EnemyData;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** The data asset this enemy type is built from, shared by every enemy of this type. */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy")
	TObjectPtr<UBaseEnemyData> EnemyData;
	
};
