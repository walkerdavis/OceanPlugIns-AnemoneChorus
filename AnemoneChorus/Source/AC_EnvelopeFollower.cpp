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
    mCurrentPeak(0.0),
    mValue(0.01)
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
                                     int inNumSamples)
{
    const float attack = jmap(inAttackTime, 0.0f, 1.0f, 0.001f, .02f);
    const float release = jmap(inAttackTime, 0.0f, 1.0f, 0.005f, .4f);
    
    for (int i = 0; i < inNumSamples; i++){
        
        if (not mDirection){
            if (fabs(mBuffer[i]) < inThreshold){
                mValue -= 1/(mSampleRate*release);
                if (mValue < 0.){
                    mValue = 0.;
                }
            } else {
                mValue += 1/(mSampleRate*attack);
                if (fabs(mBuffer[i]) > mCurrentPeak){
                    mCurrentPeak = fabs(mBuffer[i]);
                }
                mDirection = true;
            }
        } else {
            mValue += 1/(mSampleRate*attack);
            
            if (fabs(mBuffer[i]) > mCurrentPeak){
                mCurrentPeak = fabs(mBuffer[i]);
            }
            
            if (mValue > mCurrentPeak){
                mValue = mCurrentPeak;
                mCurrentPeak = 0;
                mDirection = false;
            }
        }
        mBuffer[i] = mValue;
    }
    
}

float* AC_EnvelopeFollower::getBuffer(){
    return mBuffer;
}
