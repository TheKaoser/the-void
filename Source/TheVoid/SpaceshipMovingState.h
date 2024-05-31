#include "SpaceshipState.h"

class SpaceshipMovingState : public SpaceshipState
{
    public:
    SpaceshipMovingState();
    virtual ~SpaceshipMovingState();

    virtual SpaceshipState* HandleInput(class ASpaceship* Spaceship, SpaceshipInput Input) override;
    virtual void Enter(class ASpaceship* Spaceship) override;
    virtual void Update(class ASpaceship* Spaceship) override;
    virtual void Exit(class ASpaceship* Spaceship) override;
};