// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<USpaceshipMovementActorComponent>(TEXT("Spaceship Movement Component"));
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	// UInputComponent* SpaceshipInputComponent = new UInputComponent();

	SetupPlayerInputComponent(SpaceshipInputComponent);

	MovementComponent->SetPlayerInputComponent(SpaceshipInputComponent);
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

	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent()"));
	
	PlayerInputComponent->BindAxis("SpaceshipMoveForward");
	PlayerInputComponent->BindAxis("SpaceshipMoveBackwards");
	PlayerInputComponent->BindAxis("SpaceshipMoveLeft");
	PlayerInputComponent->BindAxis("SpaceshipMoveRight");
}
