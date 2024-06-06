#include "SpaceshipInput.generated.h"

UENUM()
enum EInputType
{
    PressForward,
    ReleaseForward,
    PressFire,
    ReleaseFire
};

USTRUCT()
struct FSpaceshipInput
{
    GENERATED_BODY()

    EInputType InputType;
    float Intensity;
};