// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDataSubsystem.h"

void UPlayerDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UPlayerDataSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

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

void UPlayerDataSubsystem::SetAll(const EPlayerTypes PlayerType, const int Health, const int Score,
	const TArray<EItemType> Inventory)
{
	SetPlayerHealth(PlayerType, Health);
	SetPlayerScore(PlayerType, Score);
	SetPlayerInventory(PlayerType, Inventory);
}

void UPlayerDataSubsystem::SetPlayerHealth(const EPlayerTypes PlayerType, const int Health)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].PlayerHealth = Health;
}

void UPlayerDataSubsystem::SetPlayerScore(const EPlayerTypes PlayerType, const int Score)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].PlayerScore = Score;
}

void UPlayerDataSubsystem::SetPlayerInventory(const EPlayerTypes PlayerType, const TArray<EItemType> Inventory)
{
	if (PlayerStats.Contains(PlayerType))
		PlayerStats[PlayerType].Inventory = Inventory;
}

int UPlayerDataSubsystem::GetPlayerHealth(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].PlayerHealth;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting health"));
	return 0;
}

int UPlayerDataSubsystem::GetPlayerScore(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].PlayerScore;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting score"));
	return 0;
}

TArray<EItemType> UPlayerDataSubsystem::GetPlayerInventory(const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return PlayerStats[PlayerType].Inventory;
	UE_LOG(LogTemp, Error, TEXT("Player stats failure getting inventory"));
	return TArray<EItemType>();
}
