/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Blueprint accessible enum for player types
 */

#pragma once
 
#include "CoreMinimal.h"
#include "EPlayerTypes.generated.h"

UENUM(BlueprintType)
enum class EPlayerTypes : uint8
{
	Warrior UMETA(DisplayName = "Warrior"),
	Wizard UMETA(DisplayName = "Wizard"),
	Valkyrie UMETA(DisplayName = "Valkyrie"),
	Elf UMETA(DisplayName = "Elf")
};