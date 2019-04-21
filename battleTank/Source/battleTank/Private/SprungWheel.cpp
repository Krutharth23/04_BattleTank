// Fill out your copyright notice in the Description page of Project Settings.

#include "SprungWheel.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("constraint"));
	SetRootComponent(constraint);

	Axal = CreateDefaultSubobject<USphereComponent>(FName("Axal"));
	Axal->SetupAttachment(constraint);

	Wheal = CreateDefaultSubobject<USphereComponent>(FName("Wheal"));
	Wheal->SetupAttachment(Axal);

	AxelConstriant = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxelConstriant"));
	AxelConstriant->SetupAttachment(Axal);

	
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();
	
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	constraint->SetConstrainedComponents(BodyRoot, NAME_None, Axal, NAME_None);

	AxelConstriant->SetConstrainedComponents(Axal, NAME_None, Wheal, NAME_None);
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

