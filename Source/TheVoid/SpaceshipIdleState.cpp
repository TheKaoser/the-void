#include "SpaceshipIdleState.h"
#include "SpaceshipMovingState.h"
#include "SpaceshipInput.h"

USpaceshipIdleState::USpaceshipIdleState()
{
}

USpaceshipIdleState::~USpaceshipIdleState()
{
}

USpaceshipState* USpaceshipIdleState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == PressForward)
    {
        return new USpaceshipMovingState();
    }
    return nullptr;
}

void USpaceshipIdleState::Enter(ASpaceship* Spaceship)
{
}

void USpaceshipIdleState::Update(ASpaceship* Spaceship)
{
}

void USpaceshipIdleState::Exit(ASpaceship* Spaceship)
{
}

EStateName USpaceshipIdleState::GetStateName()
{
    return Idle;
}