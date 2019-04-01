// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class RAMPAGE_API AMyAIController : public AAIController
{
	GENERATED_BODY()

	private: 
		UBlackboardComponent* BlackboardComp;
		UBehaviorTreeComponent* BehaviorComp;
	public:
		AMyAIController();

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName BlackboardKey = "Target";

		UPROPERTY(EditDefaultsOnly, Category = "AI")
			FName PlayerInRangeKey = "PlayerInRange";

		virtual void Possess(APawn* Pawn) override;

		void SetSeenTarget(APawn* Pawn);
};
