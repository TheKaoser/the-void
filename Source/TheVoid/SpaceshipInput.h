#ifndef SPACESHIPINPUT_H
#define SPACESHIPINPUT_H

struct SpaceshipInput
{
    enum InputType
    {
        PressForward,
        ReleaseForward,
        PressX,
        PressY
    };
    
    InputType InputType;
    float Intensity;
};

#endif // SPACESHIPINPUT_H