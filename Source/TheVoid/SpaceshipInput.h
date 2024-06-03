#include "SpaceshipInput.generated.h"

UENUM()
enum EInputType
{
    PressForward,
    ReleaseForward,
    PressFire
};

USTRUCT()
struct FSpaceshipInput
{
    GENERATED_BODY()

    EInputType InputType;
    float Intensity;
};