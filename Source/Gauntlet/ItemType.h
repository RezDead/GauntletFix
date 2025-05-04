/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Blueprint accessible enum for player inventory
 */

#pragma once
 
#include "CoreMinimal.h"
#include "ItemType.generated.h"
 
/*
 * Custom enum to demonstrate how to expose enums to Blueprints.
 */
UENUM(BlueprintType)
enum class EItemType : uint8
{
	Key UMETA(DisplayName = "Key"),
	Potion UMETA(DisplayName = "Potion"),
};