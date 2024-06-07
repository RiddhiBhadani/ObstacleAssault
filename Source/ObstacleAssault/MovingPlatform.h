// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

UPROPERTY(EditAnywhere)
	FVector MovingVelocity = FVector(100, 0, 0);
UPROPERTY(EditAnywhere)
	FRotator RotatingVelocity = FRotator(0, 0, 0);
UPROPERTY(EditAnywhere)
	float MoveDistance = 200;
UPROPERTY(EditAnywhere)
	FVector StartLocation;

	//use this function to Move Platform
	void MovePlatform(float);
	//use this function to Rotate Platform
	void RotatePlatform(float);
	//Check the DistanceMoved with MoveDistance
	bool ShouldPlatformMove() const;
	//Get the Distance Moved
	float GetDistanceMoved() const;
};
