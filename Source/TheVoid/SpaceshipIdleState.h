#include "SpaceshipState.h"

class SpaceshipIdleState : public SpaceshipState
{
    public:
    SpaceshipIdleState();
    virtual ~SpaceshipIdleState();

    virtual SpaceshipState* HandleInput(class ASpaceship* Spaceship, SpaceshipInput Input) override;
    virtual void Enter(class ASpaceship* Spaceship) override;
    virtual void Update(class ASpaceship* Spaceship) override;
    virtual void Exit(class ASpaceship* Spaceship) override;
};