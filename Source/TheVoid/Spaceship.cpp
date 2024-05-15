// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(0, 1000 * DeltaTime, 0), true);
}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

