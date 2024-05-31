// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "Camera/CameraComponent.h"
#include "SpaceshipMovementActorComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpaceshipIdleState.h"

// Sets default values
ASpaceship::ASpaceship()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<USpaceshipMovementActorComponent>(TEXT("MovementComponent"));

	SpaceshipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceshipMesh"));
	SpaceshipMesh->SetupAttachment(RootComponent);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	SetupPlayerInputComponent(InputComponent);
	Observers[0] = MovementComponent;
	CurrentState = new SpaceshipIdleState();
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("SpaceshipMoveForward", IE_Pressed, this, &ASpaceship::MoveForward);
	PlayerInputComponent->BindAction("SpaceshipMoveForward", IE_Released, this, &ASpaceship::StopMoveForward);
	PlayerInputComponent->BindAxis("SpaceshipMoveX", MovementComponent, &USpaceshipMovementActorComponent::MoveX);
	PlayerInputComponent->BindAxis("SpaceshipMoveY", MovementComponent, &USpaceshipMovementActorComponent::MoveY);
}

void ASpaceship::MoveForward()
{
	SpaceshipInput Input = {SpaceshipInput::PressForward, 1.0f};
	HandleInput(Input);
}

void ASpaceship::StopMoveForward()
{
	SpaceshipInput Input = {SpaceshipInput::ReleaseForward, 0.0f};
	HandleInput(Input);
}

void ASpaceship::HandleInput(SpaceshipInput Input)
{
	SpaceshipState* SpaceshipState = CurrentState->HandleInput(this, Input);
	if (SpaceshipState)
	{
		CurrentState->Exit(this);
		delete CurrentState;
		CurrentState = SpaceshipState;
		CurrentState->Enter(this);
		
		for (int i = 0; i < NumObservers; i++)
		{
			Observers[i]->OnStateChange(CurrentState);
		}
	}
}