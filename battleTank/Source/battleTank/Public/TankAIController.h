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

public:

	void BeginPlay() override;
	void Tick(float DeltaTime) override;
private:
	//how close can ai can come
	float acceptanceRadius = 3000;
};