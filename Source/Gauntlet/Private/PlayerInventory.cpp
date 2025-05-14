// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventory.h"

#include "PlayerDataSubsystem.h"

void UPlayerInventory::BeginPlay()
{
	Super::BeginPlay();

	
}

// Sets default values for this component's properties
UPlayerInventory::UPlayerInventory(): PlayerType()
{
	InventorySize = 12;
}

bool UPlayerInventory::AddToInventory(const EItemType Item)
{
	if (Inventory.Num() < InventorySize)
	{
		Inventory.Add(Item);
		return true;
	}
	
	return false;
}

bool UPlayerInventory::CheckIfInInventory(const EItemType Item) const
{
	if (Inventory.Contains(Item))
	{
		return true;
	}
	return false;
}

bool UPlayerInventory::RemoveFromInventory(const EItemType Item)
{
	if (Inventory.Contains(Item))
	{
		Inventory.Remove(Item);
		return true;
	}
	return false;
}
