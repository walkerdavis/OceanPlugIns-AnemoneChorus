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
    mWidthSmoothed(0.01),
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
                      float inWidth,
                      float inFeedback,
                      float inWetDry,
                      float* inModulationBuffer,
                      float *outAudio,
                      int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0 - wet;
    
    float feedbackMapped = 0;
    feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.f, 1.2f);
    
    float widthMapped = 0;
    widthMapped = jmap(inWidth, 0.0f, 1.0f, 0.003f, 0.02f);
    
    for (int i = 0; i < inNumSamplesToRender; i++){
        
        const double delayTimeModulation = (widthMapped + (0.002 * inModulationBuffer[i]));
        mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Fine * (mTimeSmoothed - (delayTimeModulation));
        
        const double delayTimeInSamples = ((mTimeSmoothed) * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        
        mFeedbackSample = sample;
        
        outAudio[i] = (inAudio[i] * dry) + (sample * wet);
        
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
