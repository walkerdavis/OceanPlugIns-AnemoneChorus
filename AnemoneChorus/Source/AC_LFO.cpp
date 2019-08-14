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
: mRateSmoothed(0.5)
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

void AC_LFO::process(float inRate,
                     float inDepth,
                     float inPhaseOffset,
                     float inRateAmount,
                     float inDepthAmount,
                     float* inEnvFolBuffer,
                     int inNumSamples)
{
    
    const float rateAmountMapped = jmap(inRateAmount, 0.0f, 1.0f, -2.0f, 2.0f);
    const float depthAmountMapped = jmap(inDepthAmount, 0.0f, 1.0f, -2.0f, 2.0f);
    const float phaseOffsetMapped = jmap(inPhaseOffset, 0.0f, 1.0f, 0.0f, 0.25f);
    
    for (int i = 0; i < inNumSamples; i++){
        float rateCurrent = inRate + (inEnvFolBuffer[i] * rateAmountMapped);
        mRateSmoothed = mRateSmoothed - kParameterSmoothingCoeff_Fine * (mRateSmoothed - (rateCurrent));
        
        if (rateCurrent < 0.){
            rateCurrent = 0.;
        }
        
        float rateMapped = jmap(mRateSmoothed, 0.0f, 1.0f, 0.01f, 8.0f);
        mPhase = mPhase + (rateMapped / mSampleRate);
        
        if (mPhase> 1){
            mPhase -= 1;
        }
        
        float phaseWithOffset = mPhase + phaseOffsetMapped;
        
        if (phaseWithOffset> 1){
            phaseWithOffset -= 1;
        }
        
        float depthCurrent = inDepth + (inEnvFolBuffer[i] * depthAmountMapped);
        mDepthSmoothed = mDepthSmoothed - kParameterSmoothingCoeff_Fine * (mDepthSmoothed - (depthCurrent));
        const float lfoPosition = sinf(phaseWithOffset * k2PI) * mDepthSmoothed;
        mBuffer[i] = lfoPosition;
        
    }
};

float* AC_LFO::getBuffer(){
    return mBuffer;
}
