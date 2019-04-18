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
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	

	UFUNCTION(BlueprintCallable)
	void fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeSEC = 3;

	UPROPERTY(EditAnywhere, Category = setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
	//local barrel reference
	UTankBarrel* Barrel = nullptr;//TODO remove
};
