// Fill out your copyright notice in the Description page of Project Settings.

#include "NarratorSubsystem.h"
#include "Engine/DataTable.h"
#include "Dialog.h"

void UNarratorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UNarratorSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UNarratorSubsystem::UpdateText(const ENarrationEvents EventType)
{
	UDataTable* SelectedData = nullptr;

	//Select Data based on Event Type
	switch (EventType)
	{
	case ENarrationEvents::PlayerDeath:
		SelectedData = PlayerDeath;
		return;
	case ENarrationEvents::PlayerDamaged:
		SelectedData = PlayerDamaged;
		return;
	case ENarrationEvents::PlayerLowHP:
		SelectedData = PlayerLowHP;
		return;
	case ENarrationEvents::PotionUsed:
		SelectedData = PotionUsed;
		return;
	case ENarrationEvents::FoodDestroyed:
		SelectedData = FoodDestroyed;
		return;
	case ENarrationEvents::FoodUsed:
		SelectedData = FoodUsed;
		return;
	case ENarrationEvents::KeyCollected:
		SelectedData = KeyCollected;
		return;
	case ENarrationEvents::LevelCleared:
		SelectedData = LevelCleared;
		return;
	default:
		UE_LOG(LogTemp, Error, TEXT("Unrecognized ENarrationEvents in UNarratorSubsystem::UpdateText"));
	}

	//Verification data has something there
	if (SelectedData == nullptr)
		return;
	
	//Roundabout method for getting num rows as data table has no GetNumRows()
	const TArray<FName> RowNames = SelectedData->GetRowNames();
	const int NumRows = RowNames.Num();

	//Parameters to randomly select row.
	const int8 RowIndex = FMath::RandRange(0, NumRows - 1);
	const FName RowKey = RowNames[RowIndex];
	static const FString Context(TEXT("UNarratorSubsystem::UpdateText"));

	FDialog* DialogStruct = SelectedData->FindRow<FDialog>(RowKey, Context, true);
	if (!DialogStruct)
		return;

	OutputText = DialogStruct->DisplayText;
	
}
