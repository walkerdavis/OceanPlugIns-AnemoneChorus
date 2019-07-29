/*
  ==============================================================================

    AC_LFO.cpp
    Created: 29 Jul 2019 2:14:00pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_LFO.h"
#include "JuceHeader.h"

AC_LFO::AC_LFO()
{
    
};

AC_LFO::~AC_LFO()
{
    
};

void AC_LFO::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float)* maxBufferDelaySize);
    
};

void AC_LFO::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
};

void AC_LFO::process(float inRate, float inDepth, float inPhaseOffset, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 5.0f);
    
    for (int i = 0; i < inNumSamples; i++){
        mPhase = mPhase + (rate / mSampleRate);
        
        if (mPhase> 1){
            mPhase -= 1;
        }
        
        float phaseWithOffset = mPhase + inPhaseOffset;
        
        if (phaseWithOffset> 1){
            phaseWithOffset -= 1;
        }
        
        const float lfoPosition = sinf(phaseWithOffset * k2PI) * inDepth;       //kadenze sin function
        //        const float lfoPosition = inDepth * sinf((k2PI * rate) + mPhase);
        mBuffer[i] = lfoPosition;
        
    }
};

float* AC_LFO::getBuffer(){
    return mBuffer;
}
