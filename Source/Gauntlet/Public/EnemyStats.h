// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_API UEnemyStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyStats();

	UFUNCTION(BlueprintCallable, Category = "DamageSystem")
	void TakeDamage(int Damage);

	UFUNCTION(BlueprintCallable, Category = "StateEvents")
	int Death();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float Speed;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Damage System")
	int EnemyCurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Damage System")
	int EnemyMaxHealth;

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	int PointsWorth;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
