// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindTargetLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "NPC_AIController.h"

UBTTask_FindTargetLocation::UBTTask_FindTargetLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Location In Nav Mesh";
}

EBTNodeResult::Type UBTTask_FindTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get AI controller and its NPC

	if (auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner())) 
	{
		if (auto* const npc = cont->GetPawn())
		{
			// Obtain npc location and use as origin
			auto const Origin = npc->GetActorLocation();

			//Get auto nav system and generate a rand loc

			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld())) 
			{
				FNavLocation Loc;
				if (NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
				}

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;

			}
		}
	}
	return EBTNodeResult::Failed;
}