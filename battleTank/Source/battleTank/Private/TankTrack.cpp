// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
UTankTrack::UTankTrack() {

	PrimaryComponentTick.bCanEverTick = true;

}
void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto CorrectionAcc = -SlippageSpeed / DeltaTime * GetRightVector();
	auto RootTank = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (RootTank->GetMass() * CorrectionAcc)/2;
	RootTank->AddForce(CorrectionForce);
}
void UTankTrack::SetThrottle(float Throttle) {
	//auto Time = GetWorld()->GetTimeSeconds();

	auto ForceApplied = GetForwardVector()*Throttle*TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


