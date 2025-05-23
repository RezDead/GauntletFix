// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gauntlet/EPlayerTypes.h"
#include "Gauntlet/ItemType.h"
#include "DEPRECATED_PlayerInventory.generated.h"


UCLASS(Deprecated, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_API UDEPRECATED_PlayerInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDEPRECATED_PlayerInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerType)
	EPlayerTypes PlayerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	int InventorySize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerData)
	TArray<EItemType> Inventory;

	UFUNCTION(BlueprintCallable)
	bool AddToInventory(const EItemType Item);

	UFUNCTION(BlueprintCallable)
	bool CheckIfInInventory(const EItemType Item) const;

	UFUNCTION(BlueprintCallable)
	bool RemoveFromInventory(const EItemType Item);

protected:
	virtual void BeginPlay() override;
};
