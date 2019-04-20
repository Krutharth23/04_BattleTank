// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.h"

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
		
		if (aimingcomponent->GetFiringState() == EFiringState::Locked) {
			aimingcomponent->fire();
		}
	}


}

void ATankAIController::SetPawn(APawn * InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);

	}
}

void ATankAIController::OnTankDeath(){
	UE_LOG(LogTemp, Warning, TEXT("recived"))
		if (!(GetPawn())) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
}




