// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "../Public/Tank.h"


// Sets default values
ATank::ATank() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Tank Aiming Compoent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector OutHitLocation){
	TankAimingComponent->RegisterComponent();
	TankAimingComponent->AimAT(OutHitLocation, LaunchSpeed);
}

void ATank::fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: tank firing"), Time)
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

