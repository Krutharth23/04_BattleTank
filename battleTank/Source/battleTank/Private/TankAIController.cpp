// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	auto playerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto controlledTank = Cast<ATank>(GetPawn());
	if ((playerPawn)){
		//TODO move towards player
		MoveToActor(playerPawn, acceptanceRadius);
		//aim towards player
		controlledTank->AimAt(playerPawn->GetActorLocation());

		//fire when ready
		controlledTank->fire();
	}


}




