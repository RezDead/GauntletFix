// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"
//#include "NPC.h"
#include "CSpawner.generated.h"
class ANPC;

UCLASS()
class GAUNTLET_API ACSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACSpawner();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle SpawnTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ACSpawner* Spawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ANPC> SpawnedEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 SpawnedObjectCount;
	
	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnEnemy();

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void EnemyKilled();
};
