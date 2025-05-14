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

void UPlayerDataSubsystem::NewPlayerAdded(const int InitialHealth, const int InitialScore, const EPlayerTypes PlayerType)
{
	if (PlayerStats.Contains(PlayerType))
		return;
	
	FPlayerStatsStruct NewPlayerStats;
	NewPlayerStats.PlayerHealth = InitialHealth;
	NewPlayerStats.PlayerScore = InitialScore;
	PlayerStats.Add(PlayerType, NewPlayerStats);
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
