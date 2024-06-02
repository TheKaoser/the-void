#pragma once

class UStateObserver
{
public:
    virtual void OnStateChange(class USpaceshipState* NewState) = 0;
};