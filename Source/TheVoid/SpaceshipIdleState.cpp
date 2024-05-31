#include "SpaceshipIdleState.h"
#include "SpaceshipMovingState.h"

SpaceshipIdleState::SpaceshipIdleState()
{
}

SpaceshipIdleState::~SpaceshipIdleState()
{
}

SpaceshipState* SpaceshipIdleState::HandleInput(ASpaceship* Spaceship, SpaceshipInput Input)
{
    if (Input.InputType == SpaceshipInput::InputType::PressForward)
    {
        return new SpaceshipMovingState();
    }
    return nullptr;
}

void SpaceshipIdleState::Enter(ASpaceship* Spaceship)
{
}

void SpaceshipIdleState::Update(ASpaceship* Spaceship)
{
}

void SpaceshipIdleState::Exit(ASpaceship* Spaceship)
{
}

SpaceshipState::StateName SpaceshipIdleState::GetStateName()
{
    return SpaceshipState::StateName::Idle;
}