#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

USTRUCT(BlueprintType)
struct GAUNTLET_API FPlayerStatsStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerData)
	int PlayerScore;
};