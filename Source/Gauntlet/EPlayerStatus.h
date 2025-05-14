/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/3/2025
 * Blueprint accessible enum for player status
 */

#pragma once
 
#include "CoreMinimal.h"
#include "EPlayerStatus.generated.h"

UENUM(BlueprintType)
enum class EPlayerStatus : uint8
{
	Alive UMETA(DisplayName = "Alive"),
	Dead UMETA(DisplayName = "Dead")
};