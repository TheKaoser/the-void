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

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay()"));
}


// Called every frame
void USpaceshipMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//UE_LOG(LogTemp, Warning, TEXT("%d"), 1);

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	GetOwner()->AddActorLocalOffset(FVector(0, PlayerInputComponent->GetAxisValue("SpaceshipMoveForward") * 1000 * DeltaTime, 0), true);
}


void USpaceshipMovementActorComponent::SetPlayerInputComponent(UInputComponent* SpaceshipInputComponent)
{
	this->PlayerInputComponent = SpaceshipInputComponent;
}
