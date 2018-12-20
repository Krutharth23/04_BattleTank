// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere , Category = setup)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = setup)
	float MaxElevstionDegrees= 40;

	UPROPERTY(EditAnywhere, Category = setup)
	float MinElevstionDegrees = 0;
};
