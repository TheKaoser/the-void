class StateObserver
{
public:
    virtual void OnStateChange(class SpaceshipState* NewState) = 0;
};