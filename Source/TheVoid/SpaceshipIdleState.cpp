#include "SpaceshipIdleState.h"
#include "SpaceshipMovingState.h"
#include "SpaceshipFiringState.h"
#include "SpaceshipInput.h"

USpaceshipIdleState::USpaceshipIdleState()
{
}

USpaceshipState* USpaceshipIdleState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == PressForward)
    {
        return new USpaceshipMovingState();
    }
    else if (Input.InputType == PressFire)
    {
        return new USpaceshipFiringState();
    }
    return nullptr;
}

EStateName USpaceshipIdleState::GetStateName()
{
    return Idle;
}