// Fill out your copyright notice in the Description page of Project Settings.


#include "DEPRECATED_PlayerInventory.h"

#include "PlayerDataSubsystem.h"

void UDEPRECATED_PlayerInventory::BeginPlay()
{
	Super::BeginPlay();

	
}

// Sets default values for this component's properties
UDEPRECATED_PlayerInventory::UDEPRECATED_PlayerInventory(): PlayerType()
{
	InventorySize = 12;
}

bool UDEPRECATED_PlayerInventory::AddToInventory(const EItemType Item)
{
	if (Inventory.Num() < InventorySize)
	{
		Inventory.Add(Item);
		return true;
	}
	
	return false;
}

bool UDEPRECATED_PlayerInventory::CheckIfInInventory(const EItemType Item) const
{
	if (Inventory.Contains(Item))
	{
		return true;
	}
	return false;
}

bool UDEPRECATED_PlayerInventory::RemoveFromInventory(const EItemType Item)
{
	if (Inventory.Contains(Item))
	{
		Inventory.Remove(Item);
		return true;
	}
	return false;
}
