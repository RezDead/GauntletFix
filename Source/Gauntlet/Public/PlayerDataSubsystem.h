/*
* Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Handles saving and loading the players data in between level transitions and periods of death. (Singleton)
 */

#pragma once

#include "CoreMinimal.h"
#include "PlayerStatsStruct.h"
#include "Gauntlet/EPlayerTypes.h"
#include "Gauntlet/ItemType.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerDataSubsystem.generated.h"

UCLASS()
class GAUNTLET_API UPlayerDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	//PlayerData
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Data")
	TMap<EPlayerTypes, FPlayerStatsStruct> PlayerStats;

	//Functions (Setting Data)
	UFUNCTION(BlueprintCallable, Category="Update Data")
	void NewPlayerAdded(const int InitialHealth, const int InitialScore, const TArray<EItemType> InitialInventory, const EPlayerTypes PlayerType);
	UFUNCTION(BlueprintCallable, Category="Update Data")
	void SetAll(EPlayerTypes PlayerType, const int Health, const int Score, const TArray<EItemType> Inventory);
	UFUNCTION(BlueprintCallable, Category="Update Data")
	void SetPlayerHealth(const EPlayerTypes PlayerType, const int Health);
	UFUNCTION(BlueprintCallable, Category="Update Data")
	void SetPlayerScore(const EPlayerTypes PlayerType, const int Score);
	UFUNCTION(BlueprintCallable, Category="Update Data")
	void SetPlayerInventory(const EPlayerTypes PlayerType, const TArray<EItemType> Inventory);

	//Functions (Getting Data)
	UFUNCTION(BlueprintCallable, Category="Get Data")
	int GetPlayerHealth(const EPlayerTypes PlayerType);
	UFUNCTION(BlueprintCallable, Category="Get Data")
	int GetPlayerScore(const EPlayerTypes PlayerType);
	UFUNCTION(BlueprintCallable, Category="Get Data")
	TArray<EItemType> GetPlayerInventory(const EPlayerTypes PlayerType);

private:
	int MaxPlayers = 4;
};
