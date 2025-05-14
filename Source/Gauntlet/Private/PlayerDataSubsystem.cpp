/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Handles saving and loading the players data in between level transitions and periods of death. (Singleton)
 */

#include "PlayerDataSubsystem.h"

void UPlayerDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPlayerDataSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

/**
 * Sets up player data on first load of class
 * @param InitialHealth Starting HP
 * @param InitialScore Starting Score
 * @param InitialInventory Starting Inventory
 * @param PlayerType Class loaded
 */
void UPlayerDataSubsystem::NewPlayerAdded(const int InitialHealth, const int InitialScore, const TArray<EItemType> InitialInventory, const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return;
	
	FPlayerStatsStruct NewPlayerStats;
	NewPlayerStats.PlayerHealth = InitialHealth;
	NewPlayerStats.PlayerScore = InitialScore;
	NewPlayerStats.Inventory = InitialInventory;
	PlayerStats.Add(PlayerType, NewPlayerStats);
}

/**
 * Macro for setting all player data
 * @param PlayerType Player data is set for
 * @param Health HP Set
 * @param Score Score Set
 * @param Inventory Inventory Set
 */
void UPlayerDataSubsystem::SetAll(const EPlayerTypes PlayerType, const int Health, const int Score,
                                  const TArray<EItemType> Inventory)
{
	SetPlayerHealth(PlayerType, Health);
	SetPlayerScore(PlayerType, Score);
	SetPlayerInventory(PlayerType, Inventory);
}

/**
 * Sets the player health
 * @param PlayerType Player class to set health for
 * @param Health Health set
 */
void UPlayerDataSubsystem::SetPlayerHealth(const EPlayerTypes PlayerType, const int Health)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].PlayerHealth = Health;
}
/**
 * Sets the player score
 * @param PlayerType Player class to set score for
 * @param Score Score set
 */
void UPlayerDataSubsystem::SetPlayerScore(const EPlayerTypes PlayerType, const int Score)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].PlayerScore = Score;
}

/**
 * Sets the player inventory
 * @param PlayerType Player class to set inventory for
 * @param Inventory Inventory set
 */
void UPlayerDataSubsystem::SetPlayerInventory(const EPlayerTypes PlayerType, const TArray<EItemType> Inventory)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].Inventory = Inventory;
}

/**
 * Retrieves the stored player health
 * @param PlayerType Player selected
 * @return Stored HP for given player
 */
int UPlayerDataSubsystem::GetPlayerHealth(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].PlayerHealth;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting health"));
	return 0;
}

/**
 * Retrieves the stored player score
 * @param PlayerType Player selected
 * @return Stored score for given player
 */
int UPlayerDataSubsystem::GetPlayerScore(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].PlayerScore;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting score"));
	return 0;
}

/**
 * Retrieves the stored player inventory
 * @param PlayerType Player selected
 * @return Stored inventory for given player
 */
TArray<EItemType> UPlayerDataSubsystem::GetPlayerInventory(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].Inventory;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting inventory"));
	return TArray<EItemType>();
}
