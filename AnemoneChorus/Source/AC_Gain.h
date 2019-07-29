/*
  ==============================================================================

    AC_Gain.h
    Created: 29 Jul 2019 2:13:47pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

class AC_Gain
{
public:
    AC_Gain();
    ~AC_Gain();
    
    void process(float* inAudio,
                 float inGain,
                 float* outAudio,
                 int inNumSamplesToRender);
    
    float getMeterLevel();
    
private:
    
    float mOutputSmoothed;
    
};
