// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
//forward declaration

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

protected:
	//how close can ai can come
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float acceptanceRadius = 8000;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnTankDeath();
};