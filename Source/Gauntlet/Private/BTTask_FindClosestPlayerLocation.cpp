// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindClosestPlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

UBTTask_FindClosestPlayerLocation::UBTTask_FindClosestPlayerLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Player Location");

}

EBTNodeResult::Type UBTTask_FindClosestPlayerLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	TArray<AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Player"), FoundPlayers);

	if (FoundPlayers.Num() > 0) // Check if array is not empty
	{
		int32 RandomIndex = FMath::RandRange(0, FoundPlayers.Num() - 1); // Generate random index
		AActor* RandomPlayer = FoundPlayers[RandomIndex]; // Get the random actor

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Found Player: %s"), *RandomPlayer->GetName()));
		

		OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), RandomPlayer->GetActorLocation());
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
		
	}
	else {
		
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
