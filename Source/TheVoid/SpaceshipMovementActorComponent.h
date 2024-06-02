// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateObserver.h"
#include "SpaceshipMovementActorComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEVOID_API USpaceshipMovementActorComponent : public UActorComponent, public UStateObserver
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpaceshipMovementActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void SetForceFeedbackEffect();

	void Accelerate();
	void Decelerate();

	UFUNCTION()
	void MoveX(float InputValue);
	
	UFUNCTION()
	void MoveY(float InputValue);

	void OnStateChange(class USpaceshipState* NewState);

private:
	bool IsAccelerating = false;

	static const float Acceleration;
	static const float Deceleration;
	static const float MaxSpeed;
	static const float RotationSpeed;
	static const float ClimbSpeed;

	APlayerController* SpaceshipController;

	UPROPERTY(EditAnywhere)
	UForceFeedbackEffect* ForceFeedbackEffect;

	UPROPERTY(VisibleAnywhere, Category = "Spaceship Movement")
	float CurrentSpaceshipSpeed = 0.0f;

	static const float BaseSpringArmLength;

	UPROPERTY()
	class USpringArmComponent* SpringArmComponent;
};
