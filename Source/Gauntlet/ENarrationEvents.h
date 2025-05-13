/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Blueprint accessible enum for player inventory
 */

#pragma once
 
#include "CoreMinimal.h"
#include "ENarrationEvents.generated.h"

UENUM(BlueprintType)
enum class ENarrationEvents : uint8
{
	PlayerDeath UMETA(DisplayName = "Player Death"),
	PlayerDamaged UMETA(DisplayName = "Player Damaged"),
	PlayerLowHP UMETA(DisplayName = "Player Low HP"),
	PotionUsed UMETA(DisplayName = "Potion Used"),
	FoodDestroyed UMETA(DisplayName = "Food Destroyed"),
	FoodUsed UMETA(DisplayName = "Food Used"),
	KeyCollected UMETA(DisplayName = "Key Collected"),
	LevelCleared UMETA(DisplayName = "Level Cleared")
};