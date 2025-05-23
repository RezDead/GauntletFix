// Fill out your copyright notice in the Description page of Project Settings.
/*
Kriger, Nathan

*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "CSpawner.h"
#include "NPC.generated.h"

UCLASS()
class GAUNTLET_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();
	UBehaviorTree* GetBehaviorTree() const;
	ACSpawner* Spawner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* Tree;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	//TSubclassOf<ACSpawner> Spawner;

};
