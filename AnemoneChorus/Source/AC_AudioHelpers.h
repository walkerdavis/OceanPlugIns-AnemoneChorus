/*
  ==============================================================================

    AC_AudioHelpers.h
    Created: 29 Jul 2019 2:14:39pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define kParameterSmoothingCoeff_Generic 0.04
#define kParameterSmoothingCoeff_Fine 0.0002
#define kMeterSmoothingCoeff 0.2


const static int maxBufferDelaySize = 44100;

const static double kPI = 3.14159265359;

const static double k2PI = 6.28318530718;

static inline float dBToNormalizedGain(float inValue)
{
    float inValuedB = Decibels::gainToDecibels(inValue + 0.00001f); //floor to prevent negative infinity
    inValuedB = (inValuedB + 96.0f) / 96.0f;
    return inValuedB;
}

inline float AC_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
};

inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}

inline float ac_denormalize(float inValue)
{
    float absValue = fabs(inValue);
    
    if(absValue < 1e-15)
    {
        return 0.0f;
    } else {
        return inValue;
    }
}
