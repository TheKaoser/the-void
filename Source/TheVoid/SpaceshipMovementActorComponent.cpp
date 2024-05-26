// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipMovementActorComponent.h"

// Sets default values for this component's properties
USpaceshipMovementActorComponent::USpaceshipMovementActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USpaceshipMovementActorComponent::BeginPlay()
{
	Super::BeginPlay();

	SpaceshipSpeed = 0;

	UE_LOG(LogTemp, Warning, TEXT("SpaceshipSpeed: %f"), SpaceshipSpeed);
}


// Called every frame
void USpaceshipMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	SpaceshipSpeed = std::clamp(SpaceshipSpeed - 30 * DeltaTime, static_cast<float>(0), static_cast<float>(10000));

	GetOwner()->AddActorLocalOffset(FVector(0, SpaceshipSpeed, 0), true);
}


void USpaceshipMovementActorComponent::SetPlayerInputComponent(UInputComponent* SpaceshipInputComponent)
{
	this->PlayerInputComponent = SpaceshipInputComponent;
}


void USpaceshipMovementActorComponent::MoveForward()
{
	SpaceshipSpeed += 1000 * GetWorld()->DeltaTimeSeconds;
}


void USpaceshipMovementActorComponent::MoveY(float InputValue)
{
	GetOwner()->AddActorLocalOffset(FVector(0, InputValue * 1000 * GetWorld()->DeltaTimeSeconds, 0), true);
}


void USpaceshipMovementActorComponent::MoveX(float InputValue)
{
	GetOwner()->AddActorLocalOffset(FVector(InputValue * 1000 * GetWorld()->DeltaTimeSeconds, 0, 0), true);
}