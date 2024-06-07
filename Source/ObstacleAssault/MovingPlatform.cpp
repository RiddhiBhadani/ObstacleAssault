// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotatePlatform(DeltaTime);

	//check the DistanceMoved with MoveDistance
	// If it should be moved or it's not too far than MoveDistance, call MovePlatform()
	if (ShouldPlatformMove())
	{
		MovePlatform(DeltaTime);
	}
	//else Move platform in Reverse direction until the start position
	else
	{
		//return;
		FVector MovingDirection = MovingVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MovingDirection * MoveDistance);
		//SetActorLocation(StartLocation);
		MovingVelocity = -MovingVelocity;
	}
}

void AMovingPlatform::MovePlatform(float deltaTime)
{
	FVector currentLocation = GetActorLocation();
	currentLocation = currentLocation + (MovingVelocity * deltaTime);
	SetActorLocation(currentLocation);
}

void AMovingPlatform::RotatePlatform(float deltaTime)
{
	FRotator rotation = RotatingVelocity * deltaTime;
	AddActorLocalRotation(rotation);
}

float AMovingPlatform::GetDistanceMoved() const
{
	FVector currentPosition = GetActorLocation();
	float movedDistance = FVector::Dist(StartLocation, currentPosition);
	UE_LOG(LogTemp, Display, TEXT("Distance Moved: %f"), movedDistance);
	return movedDistance;
}

bool AMovingPlatform::ShouldPlatformMove() const
{
	if (GetDistanceMoved() > MoveDistance)
	{
		return false;
	}
	return true;
}