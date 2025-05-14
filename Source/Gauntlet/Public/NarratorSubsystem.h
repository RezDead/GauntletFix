/*
* Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Implementation of getting Data Tables for Narrator to say on given events
 */

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/DataTable.h"
#include "Gauntlet/ENarrationEvents.h"
#include "NarratorSubsystem.generated.h"

UCLASS()
class GAUNTLET_API UNarratorSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//Properties
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* PlayerDeath;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* PlayerDamaged;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* PlayerLowHP;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* PotionUsed;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* FoodDestroyed;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* FoodUsed;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* KeyCollected;
	UPROPERTY(EditDefaultsOnly, Category = "Data Tables")
	UDataTable* LevelCleared;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Output Text")
	FText OutputText;
	
	//Functions
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	void UpdateText(const ENarrationEvents EventType);
	
};
