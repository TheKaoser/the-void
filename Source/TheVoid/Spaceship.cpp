// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<USpaceshipMovementActorComponent>(TEXT("MovementComponent"));

	// UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	// OurCamera->SetupAttachment(RootComponent);
	// OurCamera->SetRelativeLocation(FVector(-10000.0f, 0.0f, 100000.0f));
	// OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	SpaceshipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceshipMesh"));
    SpaceshipMesh->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	SetupPlayerInputComponent(InputComponent);

	MovementComponent->SetPlayerInputComponent(InputComponent);
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

	PlayerInputComponent->BindAxis("SpaceshipMoveX", MovementComponent, &USpaceshipMovementActorComponent::MoveX);
	PlayerInputComponent->BindAxis("SpaceshipMoveY", MovementComponent, &USpaceshipMovementActorComponent::MoveY);
}
