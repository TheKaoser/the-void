#include "SpaceshipState.h"

class USpaceshipMovingState : public USpaceshipState
{
public:
    USpaceshipMovingState();
    virtual ~USpaceshipMovingState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, FSpaceshipInput Input) override;
    virtual void Enter(class ASpaceship* Spaceship) override;
    virtual void Update(class ASpaceship* Spaceship) override;
    virtual void Exit(class ASpaceship* Spaceship) override;

    virtual EStateName GetStateName() override;
};