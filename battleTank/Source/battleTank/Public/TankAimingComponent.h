// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankAimingComponent;

UENUM()
enum class EFiringState : uint8 {Reloading, Aiming, Locked};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "state")
	EFiringState FiringState = EFiringState::Reloading;


public:	

	UFUNCTION(BlueprintCallable)
	void fire();


	UFUNCTION(BlueprintCallable, Category = Setup)
	void initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	void AimAt(FVector OutHitLocation);

private:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeSEC = 3;
	
	double LastFireTime = 0;
	bool IsBarrelMoviong();
	FVector AimDirection;
};
