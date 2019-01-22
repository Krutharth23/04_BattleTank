// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Math.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto rotate= RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, rotate, 0));

}


