/*
* Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Struct for use in Narrator Data Tables
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Dialog.generated.h"

USTRUCT(BlueprintType)
struct GAUNTLET_API FDialog : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText  DisplayText;
};