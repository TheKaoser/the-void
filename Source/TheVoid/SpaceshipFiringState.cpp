#include "SpaceshipInput.h"
#include "SpaceshipIdleState.h"
#include "SpaceshipFiringState.h"

USpaceshipFiringState::USpaceshipFiringState()
{
}

USpaceshipState* USpaceshipFiringState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == ReleaseFire)
    {
        return new USpaceshipIdleState();
    }
    return nullptr;
}

EStateName USpaceshipFiringState::GetStateName()
{
    return Firing;
}