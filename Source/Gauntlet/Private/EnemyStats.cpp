// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyStats.h"

// Sets default values for this component's properties
UEnemyStats::UEnemyStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...


	EnemyMaxHealth = 20;
	Speed = 1;
	PointsWorth = 30;


}


// Called when the game starts
void UEnemyStats::BeginPlay()
{
	Super::BeginPlay();

	// ...

	EnemyCurrentHealth = EnemyMaxHealth;
}


// Called every frame
void UEnemyStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemyStats::TakeDamage(int DamageTaken) {

	EnemyCurrentHealth -= DamageTaken;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("EnemyHealth: %i"), EnemyCurrentHealth));
	if (EnemyCurrentHealth <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("PointsWorth: %i"), Death()));
	}
}


int UEnemyStats::Death() {

	AActor* OwningActor = GetOwner();
	OwningActor->Destroy();
	return PointsWorth;
}