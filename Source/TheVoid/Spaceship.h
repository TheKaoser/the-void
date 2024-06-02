// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StateNotifier.h"
#include "Spaceship.generated.h"

UCLASS()
class THEVOID_API ASpaceship : public APawn
{
	GENERATED_BODY()

public:
	ASpaceship();
	
	void AddObserver(UStateObserver* Observer)
    {
        StateNotifier->AddObserver(Observer);
    }

    void RemoveObserver(UStateObserver* Observer)
    {
        StateNotifier->RemoveObserver(Observer);
    }

protected:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void PressForward();
	void ReleaseForward();
	void HandleInput(struct FSpaceshipInput Input);
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpaceshipMesh;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	class USpaceshipState* CurrentState;

	UPROPERTY()
	UStateNotifier* StateNotifier;

	UPROPERTY(VisibleAnywhere)
	class USpaceshipMovementActorComponent* MovementComponent;
};
