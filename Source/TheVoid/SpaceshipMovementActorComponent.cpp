// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipMovementActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpaceshipMovingState.h"

const float USpaceshipMovementActorComponent::Acceleration = 200.0f;
const float USpaceshipMovementActorComponent::Deceleration = 50.0f;
const float USpaceshipMovementActorComponent::MaxSpeed = 1000.0f;
const float USpaceshipMovementActorComponent::RotationSpeed = 50.0f;
const float USpaceshipMovementActorComponent::ClimbSpeed = 50.0f;

const float USpaceshipMovementActorComponent::BaseSpringArmLength = 3500.0f;

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

	SpaceshipController = Cast<APlayerController>(Cast<APawn>(GetOwner())->GetController());
	SpringArmComponent = GetOwner()->FindComponentByClass<USpringArmComponent>();
}

// Called every frame
void USpaceshipMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentSpaceshipSpeed = std::clamp(CurrentSpaceshipSpeed + (IsAccelerating * Acceleration - Deceleration) * DeltaTime, 0.0f, MaxSpeed);
	SpringArmComponent->TargetArmLength = BaseSpringArmLength + CurrentSpaceshipSpeed;
	SpringArmComponent->bEnableCameraRotationLag = true;
	GetOwner()->AddActorLocalOffset(FVector(0, CurrentSpaceshipSpeed, 0), true);
	SetForceFeedbackEffect();
}

void USpaceshipMovementActorComponent::SetForceFeedbackEffect()
{
	FForceFeedbackParameters Params = FForceFeedbackParameters();

	if (CurrentSpaceshipSpeed > 500 and IsAccelerating)
	{
		SpaceshipController->ClientPlayForceFeedback(ForceFeedbackEffect, Params);
	}
}

void USpaceshipMovementActorComponent::Accelerate()
{
	IsAccelerating = true;
}

void USpaceshipMovementActorComponent::Decelerate()
{
	IsAccelerating = false;
}

void USpaceshipMovementActorComponent::MoveY(float InputValue)
{
	GetOwner()->AddActorLocalRotation(FRotator(0, 0, InputValue * RotationSpeed * GetWorld()->DeltaTimeSeconds), true);
	if (IsAccelerating)
		GetOwner()->AddActorLocalOffset(FVector(0, 0, InputValue * ClimbSpeed * GetWorld()->DeltaTimeSeconds), true);
}

void USpaceshipMovementActorComponent::MoveX(float InputValue)
{
	GetOwner()->AddActorLocalRotation(FRotator(InputValue * RotationSpeed * GetWorld()->DeltaTimeSeconds, 0, 0), true);
	if (IsAccelerating)
		GetOwner()->AddActorLocalRotation(FRotator(0, InputValue * RotationSpeed * GetWorld()->DeltaTimeSeconds, 0), true);
}

void USpaceshipMovementActorComponent::OnStateChange(SpaceshipState* NewState)
{
	IsAccelerating = NewState->GetStateName() == SpaceshipState::StateName::Moving;
}