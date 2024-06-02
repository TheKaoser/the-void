#include "SpaceshipState.h"

class USpaceshipMovingState : public USpaceshipState
{
public:
    USpaceshipMovingState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, struct FSpaceshipInput Input) override;
    virtual void Enter(class ASpaceship* Spaceship);
    virtual void Update(class ASpaceship* Spaceship);
    virtual void Exit(class ASpaceship* Spaceship);
    virtual EStateName GetStateName() override;
};