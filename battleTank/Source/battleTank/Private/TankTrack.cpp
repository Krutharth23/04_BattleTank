// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
UTankTrack::UTankTrack() {

	PrimaryComponentTick.bCanEverTick = false;

}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	ApplySideWaysForce();
	DriveTrack();
	currentThrottle = 0;
}

void UTankTrack::ApplySideWaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcc = -SlippageSpeed / DeltaTime * GetRightVector();
	auto RootTank = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (RootTank->GetMass() * CorrectionAcc) / 2;
	RootTank->AddForce(CorrectionForce);
}
void UTankTrack::DriveTrack() {
	auto ForceApplied = GetForwardVector()*currentThrottle*TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
void UTankTrack::SetThrottle(float Throttle) {
	currentThrottle = FMath::Clamp<float>(currentThrottle + Throttle, -1, 1);
}


