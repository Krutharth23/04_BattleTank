// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
public:

	void AimAt(FVector OutHitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent=nullptr;

	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void fire();

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditAnywhere, Category = setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//local barrel reference
	UTankBarrel* Barrel = nullptr;
};
