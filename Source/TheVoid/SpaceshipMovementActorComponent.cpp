#include "SpaceshipMovementActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpaceshipMovingState.h"
#include "Spaceship.h"

const float USpaceshipMovementActorComponent::Acceleration = 200.0f;
const float USpaceshipMovementActorComponent::Deceleration = 50.0f;
const float USpaceshipMovementActorComponent::MaxSpeed = 1000.0f;
const float USpaceshipMovementActorComponent::RotationSpeed = 50.0f;
const float USpaceshipMovementActorComponent::ClimbSpeed = 50.0f;
const float USpaceshipMovementActorComponent::BaseSpringArmLength = 3500.0f;

USpaceshipMovementActorComponent::USpaceshipMovementActorComponent() 
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USpaceshipMovementActorComponent::BeginPlay()
{
	Super::BeginPlay();

	SpaceshipController = Cast<APlayerController>(Cast<APawn>(GetOwner())->GetController());
	SpringArmComponent = GetOwner()->FindComponentByClass<USpringArmComponent>();
	SpringArmComponent->bEnableCameraRotationLag = true;
	Cast<ASpaceship>(GetOwner())->AddObserver(this);
}

void USpaceshipMovementActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentSpaceshipSpeed = std::clamp(CurrentSpaceshipSpeed + (IsAccelerating * Acceleration - Deceleration) * DeltaTime, 0.0f, MaxSpeed);
	SpringArmComponent->TargetArmLength = BaseSpringArmLength + CurrentSpaceshipSpeed;
	GetOwner()->AddActorLocalOffset(FVector(0, CurrentSpaceshipSpeed, 0), true);
	SetForceFeedbackEffect();
}

void USpaceshipMovementActorComponent::SetForceFeedbackEffect()
{
	if (CurrentSpaceshipSpeed > 500 and IsAccelerating)
	{
		SpaceshipController->ClientPlayForceFeedback(ForceFeedbackEffect);
	}
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

void USpaceshipMovementActorComponent::OnStateChange(USpaceshipState* NewState)
{
	IsAccelerating = NewState->GetStateName() == Moving;
}