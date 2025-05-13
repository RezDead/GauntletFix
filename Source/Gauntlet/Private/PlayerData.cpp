/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Handles player taking damage, broadcasting death event, taking damage every second, and holds player stats/data.
 * Shows how to call events, call functions after delay, and print to screen.
 */

#include "PlayerData.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

void UPlayerData::BeginPlay()
{
	Super::BeginPlay();

	//Start decreasing health every second
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UPlayerData::ReduceHealthEverySecond, 1.0f,true);
	
}


// Sets default values for this component's properties
UPlayerData::UPlayerData()
{
	PlayerScore = 0;
	HealthDecreaseRate = 1;
	PlayerHealth = 700;
	PlayerSpeed = 400;
	PlayerArmor = 100;
	DamagePower = 1;
	MagicPower = 1;
	ShotSpeed = 1.0f;
	ShotSize = 1.0f;
}

/**
 * 
 * @param Score 
 */
void UPlayerData::IncreaseScore(const int Score)
{
	PlayerScore += Score;
}

void UPlayerData::TakeDamage(const int Damage)
{
	PlayerHealth -= Damage;
	if (PlayerHealth <= 0)
	{
		PlayerHealth = 0;
		//Calls player death event, to be processed in blueprint on actor
		OnPlayerDeath.Broadcast();
	}
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("PlayerHealth: %i"), PlayerHealth));
}

void UPlayerData::AddHealth(const int Health)
{
	PlayerHealth += Health;
}

void UPlayerData::ReduceHealthEverySecond()
{
	TakeDamage(HealthDecreaseRate);
}
