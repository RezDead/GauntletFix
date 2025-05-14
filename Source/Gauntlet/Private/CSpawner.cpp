// Fill out your copyright notice in the Description page of Project Settings.
/*

Author: Krigerm Nathan
Last Updated: 5/14/2025
Handles Spawning of Enemies
*/	

#include "CSpawner.h"
#include "TimerManager.h"
#include "NPC.h"

// Sets default values
ACSpawner::ACSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnedEnemy = nullptr;
	SpawnedObjectCount = 0;
	

}

// Called when the game starts or when spawned
void ACSpawner::BeginPlay()
{
	Super::BeginPlay();
	ACSpawner::SpawnEnemy();
	
}

// Called every frame
void ACSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACSpawner::SpawnEnemy()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();
	ANPC* SpawnedActor = GetWorld()->SpawnActor<ANPC>(SpawnedEnemy, SpawnLocation, SpawnRotation);
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("Actor spawning"));

	if (SpawnedActor) {
		SpawnedActor->Spawner = this;
		SpawnedObjectCount++;
	}

	// Ensure the timer persists
	if (SpawnedObjectCount < 8) {
		GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ACSpawner::SpawnEnemy, 5.0f, true);
	}
}

void ACSpawner::EnemyKilled()
{
	SpawnedObjectCount--;

	if (SpawnedObjectCount < 8)
	{
		if (!GetWorld()->GetTimerManager().IsTimerActive(SpawnTimerHandle))
		{
			GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ACSpawner::SpawnEnemy, 5.0f, true);
		}
	}
}



