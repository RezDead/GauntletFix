// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerManager.h"

#include "NarratorSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

void UPlayerManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	PlayerStatus = {
		{EPlayerTypes::Warrior, EPlayerStatus::Dead},
		{EPlayerTypes::Valkyrie, EPlayerStatus::Dead},
		{EPlayerTypes::Wizard, EPlayerStatus::Dead},
		{EPlayerTypes::Elf, EPlayerStatus::Dead}
	};
}

void UPlayerManager::Deinitialize()
{
	Super::Deinitialize();
}

void UPlayerManager::SetPlayerStatus(EPlayerTypes PlayerType, EPlayerStatus NewPlayerStatus)
{
	if (PlayerStatus[PlayerType] == EPlayerStatus::Alive && NewPlayerStatus == EPlayerStatus::Dead)
	{
		GetGameInstance()->GetSubsystem<UNarratorSubsystem>()->UpdateText(ENarrationEvents::PlayerDeath);
		CheckIfGameOver();
	}

	PlayerStatus[PlayerType] = NewPlayerStatus;
}

EPlayerStatus UPlayerManager::GetPlayerStatus(EPlayerTypes PlayerType)
{
	return PlayerStatus[PlayerType];
}

void UPlayerManager::CheckIfGameOver()
{
	for (TTuple<EPlayerTypes, EPlayerStatus> PlayerStatusCheck : PlayerStatus)
	{
		if (PlayerStatusCheck.Value != EPlayerStatus::Dead)
		{
			return;
		}
	}
	
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
