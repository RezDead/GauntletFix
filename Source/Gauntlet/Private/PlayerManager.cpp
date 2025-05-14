/*
* Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Handles the current player states (Dead or alive) (singleton)
 */

#include "PlayerManager.h"

#include "NarratorSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

void UPlayerManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	//Sets default status to dead for all.
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

/**
 * Updates a players status
 * @param PlayerType Player status to update
 * @param NewPlayerStatus Status updated to
 */
void UPlayerManager::SetPlayerStatus(EPlayerTypes PlayerType, EPlayerStatus NewPlayerStatus)
{
	if (PlayerStatus[PlayerType] == EPlayerStatus::Alive && NewPlayerStatus == EPlayerStatus::Dead)
	{
		GetGameInstance()->GetSubsystem<UNarratorSubsystem>()->UpdateText(ENarrationEvents::PlayerDeath);
		CheckIfGameOver();
	}

	PlayerStatus[PlayerType] = NewPlayerStatus;
}

/**
 * Gets current player status
 * @param PlayerType Player checked
 * @return Player status
 */
EPlayerStatus UPlayerManager::GetPlayerStatus(EPlayerTypes PlayerType)
{
	return PlayerStatus[PlayerType];
}

/**
 * Currently unimplemented check for game over
 */
void UPlayerManager::CheckIfGameOver()
{
	/*
	for (TTuple<EPlayerTypes, EPlayerStatus> PlayerStatusCheck : PlayerStatus)
	{
		if (PlayerStatusCheck.Value != EPlayerStatus::Dead)
		{
			return;
		}
	}
	
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
	*/
}
