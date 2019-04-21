// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//max force in Newtons
	UPROPERTY(EditDefaultsOnly, Category = setup)
	float TrackMaxDrivingForce = 40000;

	UTankTrack();

	TArray<class ASprungWheel*> GetWheels()const;
	
	void DriveTrack(float currentThrottle);
};
