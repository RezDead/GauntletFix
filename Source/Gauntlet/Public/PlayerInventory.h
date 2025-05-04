// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gauntlet/ItemType.h"
#include "PlayerInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAUNTLET_API UPlayerInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInventory();

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
	
};
