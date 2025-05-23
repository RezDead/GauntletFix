﻿/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Blueprint accessible enum for item types
 */

#pragma once
 
#include "CoreMinimal.h"
#include "ItemType.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Key UMETA(DisplayName = "Key"),
	Potion UMETA(DisplayName = "Potion")
};