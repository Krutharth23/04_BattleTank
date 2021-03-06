// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed);

private:

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit);

	void OnTimerExpire();

	UProjectileMovementComponent* projectileMovement;

	UPROPERTY(VisibleAnywhere, Category="components")
	UStaticMeshComponent* CollisionMesh;

	UPROPERTY(VisibleAnywhere, Category = "components")
	UParticleSystemComponent* LaunchBlast;

	UPROPERTY(VisibleAnywhere, Category = "components")
	UParticleSystemComponent* ImpactBlast;

	UPROPERTY(VisibleAnywhere, Category = "components")
	URadialForceComponent* ExplosionForce;

	UPROPERTY(EditDefaultsOnly , Category = "Setup")
	float DestroyDelay = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage= 20.f;
};
