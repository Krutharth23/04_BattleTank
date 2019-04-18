// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIIntentionForward = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIIntentionForward);
	auto RotationThrow = FVector::CrossProduct(TankForward, AIIntentionForward).Z;
	IntendRotate(RotationThrow);
	//UE_LOG(LogTemp,Warning,TEXT("%s going to %s") ,*TankName,*MoveVelocityString)
	IntendMoveForward(ForwardThrow);

}

void UTankMovementComponent::IntendMoveForward(float Throw) {
	
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO prevent double speed

}

void UTankMovementComponent::IntendRotate(float Throw) {

	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO prevent double speed

}



