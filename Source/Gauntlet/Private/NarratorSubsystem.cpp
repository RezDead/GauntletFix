// Fill out your copyright notice in the Description page of Project Settings.

#include "NarratorSubsystem.h"
#include "Engine/DataTable.h"
#include "Dialog.h"
#include "GauntletGameInstance.h"

void UNarratorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if (auto GI = Cast<UGauntletGameInstance>(GetGameInstance()))
	{
		PlayerDeath = GI->PlayerDeath;
		PlayerDamaged = GI->PlayerDamaged;
		PlayerLowHP = GI->PlayerLowHP;
		PotionUsed = GI->PotionUsed;
		FoodDestroyed = GI->FoodDestroyed;
		FoodUsed = GI->FoodUsed;
		KeyCollected = GI->KeyCollected;
		LevelCleared = GI->LevelCleared;
	}
	//Test if at least PD is connected
	if (PlayerDeath == nullptr)
		UE_LOG(LogTemp, Error, TEXT("NarratorSubsystem::Initialize: Player Death"));
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
		break;
	case ENarrationEvents::PlayerDamaged:
		SelectedData = PlayerDamaged;
		break;
	case ENarrationEvents::PlayerLowHP:
		SelectedData = PlayerLowHP;
		break;
	case ENarrationEvents::PotionUsed:
		SelectedData = PotionUsed;
		break;
	case ENarrationEvents::FoodDestroyed:
		SelectedData = FoodDestroyed;
		break;
	case ENarrationEvents::FoodUsed:
		SelectedData = FoodUsed;
		break;
	case ENarrationEvents::KeyCollected:
		SelectedData = KeyCollected;
		break;
	case ENarrationEvents::LevelCleared:
		SelectedData = LevelCleared;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("Unrecognized ENarrationEvents in UNarratorSubsystem::UpdateText"));
	}
	
	//Verification data has something there
	if (SelectedData == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Selected data == nullptr"))
		return;
	}
	
	//Roundabout method for getting num rows as data table has no GetNumRows()
	const TArray<FName> RowNames = SelectedData->GetRowNames();
	const int NumRows = RowNames.Num();

	//Parameters to randomly select row.
	const int8 RowIndex = FMath::RandRange(0, NumRows - 1);
	const FName RowKey = RowNames[RowIndex];
	static const FString Context(TEXT("UNarratorSubsystem::UpdateText"));

	FDialog* DialogStruct = SelectedData->FindRow<FDialog>(RowKey, Context, true);
	if (!DialogStruct)
	{
		UE_LOG(LogTemp, Error, TEXT("No dialog struct"))
		return;
	}

	OutputText = DialogStruct->DisplayText;
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 6.0f, FColor::Green, FString::Printf(TEXT("%s"), *OutputText.ToString()));
	
}
