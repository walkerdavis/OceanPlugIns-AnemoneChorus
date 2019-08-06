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
    mCurrentPeak(0.0f),
    mHoldCounter(0),
    mValue(0.01f)
{
    
};

AC_EnvelopeFollower::~AC_EnvelopeFollower()
{
    
};

void AC_EnvelopeFollower::reset()
{
    mEnvState = kAC_EnvState_Release;
    mCurrentPeak = 0.0f;
    mHoldCounter= 0;
    mValue = 0.0f;
    zeromem(mBuffer, sizeof(float)* maxBufferDelaySize);
    
};

void AC_EnvelopeFollower::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
};


void AC_EnvelopeFollower::process(float inThreshold,
                                     float inAttackTime,
                                     float inHoldTime,
                                     float inReleaseTime,
                                     float inFloor,
                                     float* inData,
                                     int inNumSamples)
{
    const float ms = mSampleRate/1000;
    const float attack = jmap(inAttackTime, 0.0f, 1.0f, 1.0f, 100.0f);
    const float hold = jmap(inReleaseTime, 0.0f, 1.0f, 0.f, 500.0f);
    const float release = jmap(inReleaseTime, 0.0f, 1.0f, 5.0f, 20000.0f);
    
    for (int i = 0; i < inNumSamples; i++){
        
        switch(mEnvState)
        {
            case(kAC_EnvState_Attack):{
                mValue += 1/(attack*ms);
                
                if (fabs(inData[i]) > mCurrentPeak){
                    mCurrentPeak = fabs(inData[i]);
                }
                
                if (mValue > mCurrentPeak){
                    mEnvState = kAC_EnvState_Hold;
                    mValue = mCurrentPeak;
                    mCurrentPeak = 0.;
                }
            } break;
                
            case(kAC_EnvState_Hold):{
                
                if (mHoldCounter >= (int)(hold*ms)){
                    mEnvState = kAC_EnvState_Release;
                    mHoldCounter = 0;
                } else {
                    mHoldCounter += 1;
                }
                
                
            } break;
                
            case(kAC_EnvState_Release):{
                mValue -= 1/(release*ms);
                
                if (fabs(inData[i]) < inFloor){
                    if (mValue < 0.){
                        mValue = 0.;
                    }
                    
                } else {
                    if (fabs(inData[i]) > mCurrentPeak){
                        mCurrentPeak = fabs(inData[i]);
                    }
                    mEnvState = kAC_EnvState_Attack;
                }
            } break;
                
            default:
            case (kAC_EnvState_TotalNumStyles):{
                jassertfalse;
            } break;
        }
        
//        if (mDirection){
//            mValue += 1/(attack*ms);
//
//            if (fabs(inData[i]) > mCurrentPeak){
//                mCurrentPeak = fabs(inData[i]);
//            }
//
//            if (mValue > mCurrentPeak){
//                mDirection = false;
//                mValue = mCurrentPeak;
//                mCurrentPeak = 0.;
//            }
//
//        } else {
//            mValue -= 1/(release*ms);
//
//            if (fabs(inData[i]) < inFloor){
//                if (mValue < 0.){
//                    mValue = 0.;
//                }
//
//            } else {
//                if (fabs(inData[i]) > mCurrentPeak){
//                mCurrentPeak = fabs(inData[i]);
//                }
//                mDirection = true;
//            }
//        }
        mBuffer[i] = mValue;
    }
    
}

float* AC_EnvelopeFollower::getBuffer(){
    return mBuffer;
}
