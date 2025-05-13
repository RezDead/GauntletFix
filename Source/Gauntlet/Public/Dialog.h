#pragma once

#include "CoreMinimal.h"
#include "Dialog.generated.h"

USTRUCT(BlueprintType)
struct FDialog
{
	GENERATED_BODY()

	// A string (localized text) you can edit anywhere
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText  DisplayText;
};