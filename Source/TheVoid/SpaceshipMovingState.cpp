#include "SpaceshipMovingState.h"
#include "SpaceshipMovementActorComponent.h"
#include "SpaceshipIdleState.h"

SpaceshipMovingState::SpaceshipMovingState()
{
}

SpaceshipMovingState::~SpaceshipMovingState()
{
}

SpaceshipState* SpaceshipMovingState::HandleInput(ASpaceship* Spaceship, SpaceshipInput Input)
{
    if (Input.InputType == SpaceshipInput::InputType::ReleaseForward)
    {
        return new SpaceshipIdleState();
    }
    return nullptr;
}

void SpaceshipMovingState::Enter(ASpaceship* Spaceship)
{
    Spaceship->MovementComponent->Accelerate();
}

void SpaceshipMovingState::Update(ASpaceship* Spaceship)
{
}

void SpaceshipMovingState::Exit(ASpaceship* Spaceship)
{
    Spaceship->MovementComponent->Decelerate();
}