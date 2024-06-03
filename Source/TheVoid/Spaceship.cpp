#include "Spaceship.h"
#include "Camera/CameraComponent.h"
#include "SpaceshipMovementActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpaceshipInput.h"
#include "SpaceshipIdleState.h"
#include "StateNotifier.h"

ASpaceship::ASpaceship()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MovementComponent = CreateDefaultSubobject<USpaceshipMovementActorComponent>(TEXT("MovementComponent"));
	SpaceshipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceshipMesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	StateNotifier = CreateDefaultSubobject<UStateNotifier>(TEXT("StateNotifier"));
	
	SpaceshipMesh->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
}

void ASpaceship::AddObserver(UStateObserver* Observer)
{
	StateNotifier->AddObserver(Observer);
}

void ASpaceship::RemoveObserver(UStateObserver* Observer)
{
	StateNotifier->RemoveObserver(Observer);
}

void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	SetupPlayerInputComponent(InputComponent);
	CurrentState = new USpaceshipIdleState();
}

void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("SpaceshipMoveForward", IE_Pressed, this, &ASpaceship::PressForward);
	PlayerInputComponent->BindAction("SpaceshipMoveForward", IE_Released, this, &ASpaceship::ReleaseForward);
	PlayerInputComponent->BindAxis("SpaceshipMoveX", MovementComponent, &USpaceshipMovementActorComponent::MoveX);
	PlayerInputComponent->BindAxis("SpaceshipMoveY", MovementComponent, &USpaceshipMovementActorComponent::MoveY);
	PlayerInputComponent->BindAction("SpaceshipFire", IE_Pressed, this, &ASpaceship::PressFire);
}

void ASpaceship::PressForward()
{
	HandleInput({EInputType::PressForward, 1.0f});
}

void ASpaceship::ReleaseForward()
{
	HandleInput({EInputType::ReleaseForward, 0.0f});
}

void ASpaceship::PressFire()
{
	HandleInput({EInputType::PressFire, 0.0f});
}

void ASpaceship::HandleInput(FSpaceshipInput Input)
{
	USpaceshipState* SpaceshipState = CurrentState->HandleInput(this, Input);
	if (SpaceshipState)
	{
		CurrentState->Exit(this);
		delete CurrentState;
		CurrentState = SpaceshipState;
		CurrentState->Enter(this);
		StateNotifier->NotifyObservers(CurrentState);
	}
}