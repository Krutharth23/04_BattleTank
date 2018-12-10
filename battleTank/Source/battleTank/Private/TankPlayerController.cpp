// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("player controller is not possesing the tank"))
	}

	else {
		UE_LOG(LogTemp, Warning, TEXT("player controller is possesing: %s"), *(ControlledTank->GetName()))
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
} 



void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }
	FVector OutHitLocation;
	if (GetSightRayHitLoacation(OutHitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *OutHitLocation.ToString())
	}

}

bool ATankPlayerController::GetSightRayHitLoacation(FVector& OutHitLocation) const {
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto screenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	UE_LOG(LogTemp, Warning, TEXT("screen size: %s"), *screenLocation.ToString())


	FVector LookDirection;
	if (GetLookDirection(screenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("look Direction: %s"), *LookDirection.ToString())
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& LookDirection) const {

	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, CameraWorldLocation, LookDirection);
}
