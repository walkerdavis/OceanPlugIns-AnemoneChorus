/*
  ==============================================================================

    AC_EnvelopeFollower.cpp
    Created: 5 Aug 2019 2:31:33pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_EnvelopeFollower.h"

AC_EnvelopeFollower::AC_EnvelopeFollower()
:   mSampleRate(-1),
    mDirection(false),
    mCurrentPeak(0.0f),
    mValue(0.01f)
{
    
};

AC_EnvelopeFollower::~AC_EnvelopeFollower()
{
    
};

void AC_EnvelopeFollower::reset()
{
    mDirection = false;
    mCurrentPeak = 0.0f;
    mValue = 0.0f;
    zeromem(mBuffer, sizeof(float)* maxBufferDelaySize);
    
};

void AC_EnvelopeFollower::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
};


void AC_EnvelopeFollower::process(float inThreshold,
                                     float inAttackTime,
                                     float inReleaseTime,
                                     float* inData,
                                     int inNumSamples)
{
    const float ms = mSampleRate/1000;
    const float attack = jmap(inAttackTime, 0.0f, 1.0f, 1.0f, 40.0f);
    const float release = jmap(inReleaseTime, 0.0f, 1.0f, 5.0f, 500.0f);
    
    for (int i = 0; i < inNumSamples; i++){
        
        if (mDirection){
            mValue += 1/(attack*ms);
            
            if (fabs(inData[i]) > mCurrentPeak){
                mCurrentPeak = fabs(inData[i]);
            }
            
            if (mValue > mCurrentPeak){
                mDirection = false;
                mValue = mCurrentPeak;
                mCurrentPeak = 0.;
            }
            
        } else {
            mValue -= 1/(release*ms);
            
            if (fabs(inData[i]) < inThreshold){
                if (mValue < 0.){
                    mValue = 0.;
                }
                
            } else {
                if (fabs(inData[i]) > mCurrentPeak){
                mCurrentPeak = fabs(inData[i]);
                }
                mDirection = true;
            }
        }
        mBuffer[i] = mValue;
    }
    
}

float* AC_EnvelopeFollower::getBuffer(){
    return mBuffer;
}
