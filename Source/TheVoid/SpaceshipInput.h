#include "SpaceshipInput.generated.h"

UENUM()
enum EInputType
{
    PressForward,
    ReleaseForward,
    PressX,
    PressY
};

USTRUCT()
struct FSpaceshipInput
{
    GENERATED_BODY()

    EInputType InputType;
    float Intensity;
};