#include "SpaceshipIdleState.h"
#include "SpaceshipMovingState.h"
#include "SpaceshipInput.h"

USpaceshipState* USpaceshipIdleState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == PressForward)
    {
        return new USpaceshipMovingState();
    }
    return nullptr;
}

EStateName USpaceshipIdleState::GetStateName()
{
    return Idle;
}