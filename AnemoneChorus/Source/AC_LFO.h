/*
  ==============================================================================

    AC_LFO.h
    Created: 29 Jul 2019 2:14:00pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_AudioHelpers.h"

class AC_LFO
{
public:
    
    AC_LFO();
    ~AC_LFO();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate,
                 float inDepth,
                 float inPhaseOffset,
                 float inRateAmount,
                 float inDepthAmount,
                 float* inEnvFolBuffer,
                 int inNumSamples);
    
    float* getBuffer();
    
private:
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferDelaySize];
    
    float mRateSmoothed;
    float mDepthSmoothed;
};
