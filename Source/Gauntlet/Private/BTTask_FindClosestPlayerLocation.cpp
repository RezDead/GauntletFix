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
	//get player character
	if (auto* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		//get player location
		auto const PlayerLocation = Player->GetActorLocation();

		if (SearchRandom) {
			FNavLocation Loc;

			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				if (NavSys->GetRandomPointInNavigableRadius(PlayerLocation, SeachRadius, Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
					
				}
			}
		}
		else {
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerLocation);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
