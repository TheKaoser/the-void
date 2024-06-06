#include "SpaceshipState.h"

class USpaceshipFiringState : public USpaceshipState
{
public:
    USpaceshipFiringState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, struct FSpaceshipInput Input) override;
    virtual EStateName GetStateName() override;
};