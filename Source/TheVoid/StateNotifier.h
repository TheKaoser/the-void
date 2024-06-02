#include "StateObserver.h"
#include "SpaceshipState.h"
#include "StateNotifier.generated.h"

UCLASS()
class THEVOID_API UStateNotifier : public UObject
{
    GENERATED_BODY()

public:
    void AddObserver(UStateObserver* Observer)
    {
        Observers.Add(Observer);
    }

    void RemoveObserver(UStateObserver* Observer)
    {
        Observers.Remove(Observer);
    }

    void NotifyObservers(USpaceshipState* SpaceshipState)
    {
        for (UStateObserver* Observer : Observers)
        {
            Observer->OnStateChange(SpaceshipState);
        }
    }

private:
    TArray<UStateObserver*> Observers;
};