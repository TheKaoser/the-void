#include "SpaceshipMovingState.h"
#include "SpaceshipMovementActorComponent.h"
#include "SpaceshipIdleState.h"
#include "SpaceshipInput.h"

USpaceshipState* USpaceshipMovingState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == ReleaseForward)
    {
        return new USpaceshipIdleState();
    }
    return nullptr;
}

EStateName USpaceshipMovingState::GetStateName()
{
    return Moving;
}