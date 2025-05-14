/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Handles player taking damage, broadcasting death event, taking damage every second, and holds player stats/data.
 * Shows how to call events, call functions after delay, and print to screen.
 */

#include "PlayerData.h"

#include "PlayerDataSubsystem.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

void UPlayerData::BeginPlay()
{
	Super::BeginPlay();

	//Only actually works once but needs to be called like this
	GetWorld()->GetGameInstance()->GetSubsystem<UPlayerDataSubsystem>()
	->NewPlayerAdded(InitialPlayerHealth,InitialPlayerScore,Inventory,PlayerType);

	//Snags player stats from persistant storage
	PlayerHealth = GetWorld()->GetGameInstance()->GetSubsystem<UPlayerDataSubsystem>()->GetPlayerHealth(PlayerType);
	PlayerScore = GetWorld()->GetGameInstance()->GetSubsystem<UPlayerDataSubsystem>()->GetPlayerScore(PlayerType);
	Inventory = GetWorld()->GetGameInstance()->GetSubsystem<UPlayerDataSubsystem>()->GetPlayerInventory(PlayerType);

	//Start decreasing health every second
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UPlayerData::ReduceHealthEverySecond, 1.0f,true);
	
}

void UPlayerData::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetGameInstance()->GetSubsystem<UPlayerDataSubsystem>()
	->SetAll(PlayerType, PlayerHealth, PlayerScore, Inventory);
}


// Sets default values for this component's properties + Initializes player stats
UPlayerData::UPlayerData(): PlayerType(), PlayerHealth(0), PlayerScore(0)
{
	InitialPlayerScore = 0;
	HealthDecreaseRate = 1;
	DecreaseHealth = false;
	InitialPlayerHealth = 700;
	PlayerSpeed = 400;
	PlayerArmor = 100;
	DamagePower = 1;
	MagicPower = 1;
	ShotSpeed = 1.0f;
	ShotSize = 1.0f;
	InventorySize = 12;
}

/**
 * Increases the score by a given amount.
 * @param Score Score added.
 */
void UPlayerData::IncreaseScore(const int Score)
{
	PlayerScore += Score;
}

/**
 * Causes the player to take damage and checks if player is dead.
 * @param Damage Amount of damage taken
 */
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

/**
 * Adds health to the player.
 * @param Health Health to be added.
 */
void UPlayerData::AddHealth(const int Health)
{
	PlayerHealth += Health;
}

/**
 * Function used decrease player health every second
 */
void UPlayerData::ReduceHealthEverySecond()
{
	if (DecreaseHealth)
		TakeDamage(HealthDecreaseRate);
}

bool UPlayerData::AddToInventory(const EItemType Item)
{
	if (Inventory.Num() < InventorySize)
	{
		Inventory.Add(Item);
		return true;
	}
	
	return false;
}

bool UPlayerData::CheckIfInInventory(const EItemType Item) const
{
	if (Inventory.Contains(Item))
	{
		return true;
	}
	return false;
}

bool UPlayerData::RemoveFromInventory(const EItemType Item)
{
	if (Inventory.Contains(Item))
	{
		Inventory.Remove(Item);
		return true;
	}
	return false;
}