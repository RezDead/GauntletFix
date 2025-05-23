/*
 * Author: Kroeger-Miller, Julian
 * Last Updated: 5/14/2025
 * Handles player taking damage, broadcasting death event, taking damage every second, and holds player stats/data.
 * Shows how to declare an event, declare variables, allow event to be called in BP,declare functions, and put categories on variables.
 */

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gauntlet/EPlayerTypes.h"
#include "Gauntlet/ItemType.h"
#include "PlayerData.generated.h"

//Declares an event
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_API UPlayerData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerData();
	
	//UProperties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerType)
	EPlayerTypes PlayerType;

	//Initial Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int InitialPlayerHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int InitialPlayerScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	TArray<EItemType> InitialInventory;
	
	//Player Stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	bool DecreaseHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	int HealthDecreaseRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerArmor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int DamagePower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float MagicPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float ShotSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	float ShotSize;

	//Working Player Stats
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PlayerStats)
	int PlayerScore;

	//Allows event to be called/processed in blueprint
	UPROPERTY(BlueprintAssignable)
	FOnPlayerDeath OnPlayerDeath;

	//Functions
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int Damage);

	UFUNCTION(BlueprintCallable)
	void IncreaseScore(int Score);

	UFUNCTION(BlueprintCallable)
	void AddHealth(int Health);

	UFUNCTION()
	void ReduceHealthEverySecond();
	
	//Inventory Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInventory)
	int InventorySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInventory)
	TArray<EItemType> Inventory;

	//Inventory Functions
	UFUNCTION(BlueprintCallable)
	bool AddToInventory(const EItemType Item);
	UFUNCTION(BlueprintCallable)
	bool CheckIfInInventory(const EItemType Item) const;
	UFUNCTION(BlueprintCallable)
	bool RemoveFromInventory(const EItemType Item);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
