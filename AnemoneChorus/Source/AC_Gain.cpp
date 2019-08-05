/*
  ==============================================================================

    AC_Gain.cpp
    Created: 29 Jul 2019 2:13:47pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_Gain.h"
#include "AC_AudioHelpers.h"

AC_Gain::AC_Gain()
:   mOutputSmoothed(0),
    mGainSmoothed(0)
{
    
}
AC_Gain::~AC_Gain()
{
    
}

void AC_Gain::process(float* inAudio,
                       float inGain,
                       float* outAudio,
                       int inNumSamplesToRender)
{
    
    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
    
    for (int i = 0; i < inNumSamplesToRender; i++){
        mGainSmoothed = mGainSmoothed - kParameterSmoothingCoeff_Fine * (mGainSmoothed - (gainMapped));
        
        outAudio[i] = inAudio[i] * mGainSmoothed;
    }
    
    float absValue = fabs(outAudio[0]);
    mOutputSmoothed = kMeterSmoothingCoeff* (mOutputSmoothed - absValue) + absValue;
    
}

float AC_Gain::getMeterLevel()
{
    return mOutputSmoothed;
}
