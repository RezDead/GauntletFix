// Fill out your copyright notice in the Description page of Project Settings.
/*

Author: Kriger Nathan
Last Updated: 5/14/2025
Handles Updating Tree AI
*/

#include "NPC_AIController.h"
#include "NPC.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"



ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{
	//SetupPerceptionSystem();
}

void ANPC_AIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	if (ANPC* const npc = Cast<ANPC>(InPawn)) {

		if (UBehaviorTree* const tree = npc->GetBehaviorTree()) 
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
		
	}
}

/* Abandoned find player setup due to player being blueprint causing issues with C++ intergration
void ANPC_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
   if (SightConfig)
   {
	   // Ensure SightConfig is cast to UAISenseConfig_Sight to access Sight-specific properties
	   UAIPerceptionComponent* PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
	   SetPerceptionComponent(*PerceptionComp);

	   SightConfig->SightRadius = 500.f;
	   SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
	   SightConfig->PeripheralVisionAngleDegrees = 360.f; // 360 because gauntlet enemies see player always
	   SightConfig->SetMaxAge(5.f);
	   SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.f;
	   SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	   SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	   SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	   GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	   GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ANPC_AIController::OnTargetDetected);
	   GetPerceptionComponent()->ConfigureSense(*SightConfig);
   }
}


void ANPC_AIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	UClass* BPClass = LoadClass<AActor>(nullptr, TEXT("/Game/Blueprints/BP_PlayerBase.BP_PlayerBase_C"));
	if (BPClass && Actor->IsA(BPClass))
	{
		//GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}


*/

