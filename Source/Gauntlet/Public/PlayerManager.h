// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gauntlet/EPlayerStatus.h"
#include "Gauntlet/EPlayerTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerManager.generated.h"

/**
 * 
 */
UCLASS()
class GAUNTLET_API UPlayerManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TMap<EPlayerTypes, EPlayerStatus> PlayerStatus;
	UFUNCTION(BlueprintCallable)
	void SetPlayerStatus(EPlayerTypes PlayerType, EPlayerStatus NewPlayerStatus);
	UFUNCTION(BlueprintCallable)
	EPlayerStatus GetPlayerStatus(EPlayerTypes PlayerType);
	UFUNCTION()
	void CheckIfGameOver();
	
};
