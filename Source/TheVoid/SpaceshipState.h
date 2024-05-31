#include "Spaceship.h"

#ifndef SPACESHIPSTATE_H
#define SPACESHIPSTATE_H

class SpaceshipState
{
public:
    enum StateName
    {
        Idle,
        Moving
    };

    // Destructor
    virtual ~SpaceshipState() {};

    // Member functions
    virtual SpaceshipState* HandleInput(class ASpaceship* Spaceship, SpaceshipInput Input) = 0;
    virtual void Enter(class ASpaceship* Spaceship) = 0;
    virtual void Update(class ASpaceship* Spaceship) = 0;
    virtual void Exit(class ASpaceship* Spaceship) = 0;

    virtual StateName GetStateName() = 0;
};

#endif