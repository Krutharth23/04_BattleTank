// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto controlledTank = GetPawn();
	if ((playerPawn)){
		//TODO move towards player
		MoveToActor(playerPawn, acceptanceRadius);
		//aim towards player
		auto aimingcomponent = controlledTank->FindComponentByClass<UTankAimingComponent>();
		aimingcomponent->AimAt(playerPawn->GetActorLocation());

		//fire when ready
		aimingcomponent->fire();
	}


}




