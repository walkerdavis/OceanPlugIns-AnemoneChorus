/*
  ==============================================================================

    AC_Delay.cpp
    Created: 29 Jul 2019 2:13:54pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_Delay.h"
#include "JuceHeader.h"


AC_Delay::AC_Delay()
:  mSampleRate(-1),
    mFeedbackSample(0.0),
    mTimeSmoothed(0),
    mWetSmoothed(0),
    mFeedbackSmoothed(0),
    mDelayIndex(0)

{
    
};

AC_Delay::~AC_Delay()
{
    
};

void AC_Delay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
};

void AC_Delay::reset()
{
    mTimeSmoothed = 0.0f;
    zeromem(mBuffer, (sizeof(double) * maxBufferDelaySize));
};

void AC_Delay::process(float *inAudio,
                      float inFeedback,
                      float inFeedbackAmount,
                      float inWetDry,
                      float* inModulationBuffer,
                      float* inEnvelopeBuffer,
                      float *outAudio,
                      int inNumSamplesToRender)
{
    
    
    for (int i = 0; i < inNumSamplesToRender; i++){
        
        float feedbackCurrent = inFeedback + (inEnvelopeBuffer[i] * inFeedbackAmount);
        mFeedbackSmoothed = mFeedbackSmoothed - kParameterSmoothingCoeff_Fine * (mFeedbackSmoothed - feedbackCurrent);
        float feedbackMapped = 0.;
        feedbackMapped = jmap(mFeedbackSmoothed, 0.0f, 1.0f, 0.f, 1.1f);
        
        const double delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));
        mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - (delayTimeModulation));
        
        const double delayTimeInSamples = ((mTimeSmoothed) * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        
        mFeedbackSample = sample;
        
        mWetSmoothed = mWetSmoothed - kParameterSmoothingCoeff_Fine * (mWetSmoothed - (inWetDry));
        outAudio[i] = (inAudio[i] * (1.0 - mWetSmoothed)) + (sample * mWetSmoothed);
        
        mDelayIndex = mDelayIndex + 1;
        
        if (mDelayIndex >= maxBufferDelaySize) {
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        };
    };
};


double AC_Delay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if (readPosition < 0.0f){
        readPosition += maxBufferDelaySize;
    }
    
    int index_y0 = (int)readPosition - 1;
    if (index_y0 <= 0){
        index_y0 += maxBufferDelaySize;
    }
    
    int index_y1 = (int)readPosition;
    if (index_y1 > maxBufferDelaySize){
        index_y1 -= maxBufferDelaySize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float sample_t = readPosition - (int)readPosition;
    
    double outSample = AC_linear_interp(sample_y0, sample_y1, sample_t);
    
    return outSample;
};
