// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStatsStruct.h"
#include "Gauntlet/EPlayerTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerDataSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GAUNTLET_API UPlayerDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	//PlayerStats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayerData")
	TMap<EPlayerTypes, FPlayerStatsStruct> PlayerStats;

	//Functions (Setting Data)
	UFUNCTION(BlueprintCallable, Category="UpdateData")
	void NewPlayerAdded(const int InitialHealth, const int InitialScore, const EPlayerTypes PlayerType);
	UFUNCTION(BlueprintCallable, Category="UpdateData")
	void SetPlayerHealth(const EPlayerTypes PlayerType, const int Health);
	UFUNCTION(BlueprintCallable, Category="UpdateData")
	void SetPlayerScore(const EPlayerTypes PlayerType, const int Score);

	//Functions (Getting Data)
	UFUNCTION(BlueprintCallable, Category="GetData")
	int GetPlayerHealth(const EPlayerTypes PlayerType);
	UFUNCTION(BlueprintCallable, Category="GetData")
	int GetPlayerScore(const EPlayerTypes PlayerType);

private:
	int MaxPlayers = 4;
};
