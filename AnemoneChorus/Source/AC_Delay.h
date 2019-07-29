/*
  ==============================================================================

    AC_Delay.h
    Created: 29 Jul 2019 2:13:54pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_AudioHelpers.h"

enum AC_DelayType
{
    kAC_DelayType_Delay = 0,
    kAC_DelayType_Chorus,
};


class AC_Delay
{
public:
    AC_Delay();
    ~AC_Delay();
    
    void setSampleRate(double inSampleRate);
    
    void reset();
    
    void process(float *inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModulationBuffer,
                 float *outAudio,
                 int inNumSamplesToRender);
    
private:
    /** internal */
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
    
    
};
