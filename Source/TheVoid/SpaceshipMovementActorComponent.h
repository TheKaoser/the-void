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
	USpaceshipMovementActorComponent();

	void OnStateChange(class USpaceshipState* NewState);
	void MoveX(float InputValue);
	void MoveY(float InputValue);

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void SetForceFeedbackEffect();

	static const float Acceleration;
	static const float Deceleration;
	static const float MaxSpeed;
	static const float RotationSpeed;
	static const float ClimbSpeed;
	static const float BaseSpringArmLength;

	UPROPERTY(VisibleAnywhere, Category = "Spaceship Movement")
	float CurrentSpaceshipSpeed = 0.0f;

	UPROPERTY()
	class USpringArmComponent* SpringArmComponent;
	
	UPROPERTY()
	APlayerController* SpaceshipController;
	
	UPROPERTY(EditAnywhere, Category = "Feedback")
	UForceFeedbackEffect* ForceFeedbackEffect;

	bool IsAccelerating = false;
};
