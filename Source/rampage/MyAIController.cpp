// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "AICharacter.h"

AMyAIController::AMyAIController() {

	// Initialize the behavior tree and blackboard components
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

}

void AMyAIController::Possess(APawn* Pawn) {
	Super::Possess(Pawn);

	// Get the possessed Pawn.If it's the AI Character we created 
	// Initialize it's blackboard and start it's corresponding behavior tree
	AAICharacter* AICharacter = Cast<AAICharacter>(Pawn);
	if (AICharacter) {
		if (AICharacter->BehaviorTree->BlackboardAsset) {
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
			BehaviorComp->StartTree(*AICharacter->BehaviorTree);
		}
	}
}

void AMyAIController:: SetSeenTarget(APawn* Pawn) {
	//Registers the Pawn that the AI has seen in the blackboard
	if (BlackboardComp) {
		BlackboardComp->SetValueAsObject(BlackboardKey, Pawn);
	}
}