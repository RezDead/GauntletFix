#pragma once

#include "CoreMinimal.h"
#include "Gauntlet/ItemType.h"
#include "PlayerStatsStruct.generated.h"

USTRUCT(BlueprintType)
struct GAUNTLET_API FPlayerStatsStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerData)
	int PlayerScore;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Data")
	TArray<EItemType> Inventory;
	
};