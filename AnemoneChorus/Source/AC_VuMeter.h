/*
  ==============================================================================

    AC_VuMeter.h
    Created: 29 Jul 2019 2:24:42pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class AC_VuMeter
: public Component,
public Timer
{
public:
    AC_VuMeter(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_VuMeter();
    
    void paint(Graphics& g) override;
    
    void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    
    int mParameterID;
    
    float mCh0Level;
    float mCh1Level;
    
    AnemoneChorusAudioProcessor* mProcessor;
};
