// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include"SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack() {

	PrimaryComponentTick.bCanEverTick = false;

}


void UTankTrack::SetThrottle(float Throttle) {
	float currentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(currentThrottle);
}

void UTankTrack::DriveTrack(float currentThrottle) {
	auto ForceApplied = currentThrottle*TrackMaxDrivingForce;
	auto wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / wheels.Num();
	for (ASprungWheel*Wheel : wheels) {
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for (USceneComponent* Child : Children)
	{
		USpawnPoint* SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedComponent();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) continue;

		ResultArray.Add(SprungWheel);
	}
	return ResultArray;
}