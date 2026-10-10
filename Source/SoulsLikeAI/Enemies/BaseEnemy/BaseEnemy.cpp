// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"
#include "BaseAIController.h"


// Sets default values
ABaseEnemy::ABaseEnemy()
{
	// Enemies use our controller by default; a Blueprint can still pick another.
	AIControllerClass = ABaseAIController::StaticClass();
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
