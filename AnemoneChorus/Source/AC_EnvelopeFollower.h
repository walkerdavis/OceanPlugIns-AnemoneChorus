/*
  ==============================================================================

    AC_EnvelopeFollower.h
    Created: 5 Aug 2019 2:31:33pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_AudioHelpers.h"

class AC_EnvelopeFollower
{
public:
    AC_EnvelopeFollower();
    ~AC_EnvelopeFollower();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float inThreshold,
                 float inAttackTime,
                 float inReleaseTime,
                 int inNumSamples);
    
    float* getBuffer();
    
private:

    
    double mSampleRate;
    float mBuffer[maxBufferDelaySize];
    
    bool mDirection;
    float mCurrentPeak;
    float mValue;
    
};
