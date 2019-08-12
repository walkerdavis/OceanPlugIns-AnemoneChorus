/*
  ==============================================================================

    AC_EnvelopeFollower.h
    Created: 5 Aug 2019 2:31:33pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_AudioHelpers.h"

enum kAC_EnvState
{
    kAC_EnvState_Attack,
    kAC_EnvState_Hold,
    kAC_EnvState_Release,
    kAC_EnvState_TotalNumStyles
};

class AC_EnvelopeFollower
{
public:
    AC_EnvelopeFollower();
    ~AC_EnvelopeFollower();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float inThreshold,
                 float inAttackTime,
                 float inHoldTime,
                 float inReleaseTime,
                 float inFloor,
                 float* inData,
                 int inNumSamples);
    
    float* getBuffer();
    
private:

    
    double mSampleRate;
    float mBuffer[maxBufferDelaySize];
    
    int mHoldCounter;
    float mCurrentPeak;
    float mValue;
    
    kAC_EnvState mEnvState;
    
};
