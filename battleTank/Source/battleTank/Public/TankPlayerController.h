// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward declaration
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	void Tick(float DeltaTime) override;

	void BeginPlay() override;
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLoacation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D screenLoaction, FVector & LookDirection) const;

	bool GetLookVectorHitLoacation(FVector LookDirection, FVector& OutHitLocation) const;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000.;
};
