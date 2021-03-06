// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagnitude);

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	void ApplyForce();

	float TotalForceMagnitudeTF;

private:
	UPROPERTY(VisibleAnywhere, Category = "components")
	USphereComponent* Axal;

	UPROPERTY(VisibleAnywhere, Category = "components")
	UPhysicsConstraintComponent* AxelConstriant;

	UPROPERTY(VisibleAnywhere, Category = "components")
	USphereComponent* Wheel;
	
	UPROPERTY(VisibleAnywhere, Category = "components")
	UPhysicsConstraintComponent* constraint;
};
