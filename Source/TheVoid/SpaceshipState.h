#pragma once

UENUM()
enum EStateName
{
    Idle,
    Moving
};

class USpaceshipState
{
public:
    virtual ~USpaceshipState() {}

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, struct FSpaceshipInput Input) = 0;
    virtual void Enter(class ASpaceship* Spaceship) {}
    virtual void Update(class ASpaceship* Spaceship) {}
    virtual void Exit(class ASpaceship* Spaceship) {}
    virtual EStateName GetStateName() = 0;
};