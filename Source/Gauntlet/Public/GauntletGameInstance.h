/*
* Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Header for game instance used to connect Data Tables from asset browser to C++
 */
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "GauntletGameInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GAUNTLET_API UGauntletGameInstance : public UGameInstance
{
	GENERATED_BODY()

	public:
	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* PlayerDeath;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* PlayerDamaged;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* PlayerLowHP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* PotionUsed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* FoodDestroyed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* FoodUsed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* KeyCollected;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data Tables")
	UDataTable* LevelCleared;
};
