#include "SpaceshipMovingState.h"
#include "SpaceshipMovementActorComponent.h"
#include "SpaceshipIdleState.h"
#include "SpaceshipInput.h"

USpaceshipMovingState::USpaceshipMovingState()
{
}

USpaceshipMovingState::~USpaceshipMovingState()
{
}

USpaceshipState* USpaceshipMovingState::HandleInput(ASpaceship* Spaceship, FSpaceshipInput Input)
{
    if (Input.InputType == ReleaseForward)
    {
        return new USpaceshipIdleState();
    }
    return nullptr;
}

void USpaceshipMovingState::Enter(ASpaceship* Spaceship)
{
}

void USpaceshipMovingState::Update(ASpaceship* Spaceship)
{
}

void USpaceshipMovingState::Exit(ASpaceship* Spaceship)
{
}

EStateName USpaceshipMovingState::GetStateName()
{
    return Moving;
}