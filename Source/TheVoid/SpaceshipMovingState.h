#include "SpaceshipState.h"

class USpaceshipMovingState : public USpaceshipState
{
public:
    USpaceshipMovingState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, struct FSpaceshipInput Input) override;
    virtual EStateName GetStateName() override;
};