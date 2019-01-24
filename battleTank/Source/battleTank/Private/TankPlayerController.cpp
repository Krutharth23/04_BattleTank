// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

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
		GetControlledTank()->AimAt(OutHitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLoacation(FVector& OutHitLocation) const {
	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto screenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	//UE_LOG(LogTemp, Warning, TEXT("screen size: %s"), *screenLocation.ToString())


	FVector LookDirection;
	if (GetLookDirection(screenLocation, LookDirection)) {
		//LineTrince along the dot
		GetLookVectorHitLoacation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& LookDirection) const {

	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLoacation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLoacation = PlayerCameraManager->GetCameraLocation();
	auto EndLoaction = StartLoacation + (LookDirection * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLoacation,EndLoaction,ECollisionChannel::ECC_Visibility)) {
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}
