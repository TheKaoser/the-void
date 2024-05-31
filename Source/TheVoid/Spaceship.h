// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceshipInput.h"
#include "Spaceship.generated.h"

UCLASS()
class THEVOID_API ASpaceship : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	class USpaceshipMovementActorComponent* MovementComponent;
private:
	void MoveForward();
	void StopMoveForward();
	void HandleInput(SpaceshipInput Input);
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpaceshipMesh;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	class SpaceshipState* CurrentState;

	static const int NumObservers = 1;
	class StateObserver* Observers[NumObservers];
};
