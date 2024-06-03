#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Spaceship.generated.h"

UCLASS()
class THEVOID_API ASpaceship : public APawn
{
	GENERATED_BODY()

public:
	ASpaceship();
	
	void AddObserver(class UStateObserver* Observer);
    void RemoveObserver(class UStateObserver* Observer);

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

	UPROPERTY(VisibleAnywhere)
	class USpaceshipMovementActorComponent* MovementComponent;

	class USpaceshipState* CurrentState;
	
	UPROPERTY()
	class UStateNotifier* StateNotifier;
};