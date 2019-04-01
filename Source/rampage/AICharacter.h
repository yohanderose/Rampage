// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICharacter.generated.h"

UCLASS()
class RAMPAGE_API AAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacter();

private:
	UFUNCTION()
		void OnSeePlayer(APawn* Pawn);

public:	
	virtual void BeginPlay() override;

	// Component which is used for the "seeing" sense of the AI
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	// Behavior Tree of character 
	UPROPERTY(EditAnywhere, Category = "AI")
		class UBehaviorTree* BehaviorTree;
	
};
