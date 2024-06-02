#include "SpaceshipState.h"

class USpaceshipIdleState : public USpaceshipState
{
public:
    USpaceshipIdleState();
    virtual ~USpaceshipIdleState();

    virtual USpaceshipState* HandleInput(class ASpaceship* Spaceship, FSpaceshipInput Input) override;
    virtual void Enter(class ASpaceship* Spaceship) override;
    virtual void Update(class ASpaceship* Spaceship) override;
    virtual void Exit(class ASpaceship* Spaceship) override;

    virtual EStateName GetStateName() override;
};