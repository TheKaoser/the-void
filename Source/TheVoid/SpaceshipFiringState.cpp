#include "SpaceshipIdleState.h"
#include "SpaceshipInput.h"

USpaceshipFiringState::USpaceshipFiringState()
{
}

USpaceshipState* USpaceshipFiringState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == ReleaseForward)
    {
        return new USpaceshipIdleState();
    }
    return nullptr;
}

EStateName USpaceshipFiringState::GetStateName()
{
    return Firing;
}