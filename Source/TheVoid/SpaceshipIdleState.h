#include "SpaceshipState.h"

class USpaceshipIdleState : public USpaceshipState
{
public:
    USpaceshipIdleState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, struct FSpaceshipInput Input) override;
    virtual EStateName GetStateName() override;
};