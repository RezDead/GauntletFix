// Fill out your copyright notice in the Description page of Project Settings.
/*

Author: Kriger Nathan
Last Updated: 5/16/2025
Handles Updating Tree AI
*/
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "NPC_AIController.generated.h"


UCLASS()
class GAUNTLET_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()
public:
	explicit ANPC_AIController(FObjectInitializer const& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	class UAISenseConfig* SightConfig;

	//void SetupPerceptionSystem();

	//UFUNCTION()
	//void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);
	
	
};
