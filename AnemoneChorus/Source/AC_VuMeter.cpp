/*
  ==============================================================================

    AC_VuMeter.cpp
    Created: 29 Jul 2019 2:24:42pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_VuMeter.h"
#include "AC_InterfaceDefines.h"
#include "AC_Parameters.h"
#include "AC_AudioHelpers.h"

AC_VuMeter::AC_VuMeter(AnemoneChorusAudioProcessor* inProcessor)
:   mParameterID(-1),
    mCh0Level(0),
    mCh1Level(0),
    mProcessor(inProcessor)
{
    
}

AC_VuMeter::~AC_VuMeter()
{
    
}

void AC_VuMeter::paint(Graphics& g)
{
    const int meter_width = getWidth() / 3;
    
    g.setColour(AC_Colour_6);
    // left
    g.fillRect(0, 0, meter_width, getHeight());
    //right
    g.fillRect(meter_width * 2, 0, meter_width, getHeight());
    
    int ch0fill = getHeight() - (getHeight() * mCh0Level);
    int ch1fill = getHeight() - (getHeight() * mCh1Level);
    
    if (ch0fill < 0){
        ch0fill = 0;
    }
    
    if (ch1fill < 0){
        ch1fill = 0;
    }
    
    g.setColour((AC_Colour_7));
    g.fillRect(0, ch0fill, meter_width, getHeight());
    g.fillRect(meter_width * 2, ch1fill, meter_width, getHeight());
    
}

void AC_VuMeter::timerCallback()
{
    float updatedCh0Level = 0.0f;
    float updatedCh1Level = 0.0f;
    
    switch(mParameterID)
    {
        case (kAC_ParameterInputGain):{
            updatedCh0Level = mProcessor->getInputGainMeterLevel(0);
            updatedCh1Level = mProcessor->getInputGainMeterLevel(1);
        } break;
            
        case (kAC_ParameterOutputGain):{
            updatedCh0Level = mProcessor->getOutputGainMeterLevel(0);
            updatedCh1Level = mProcessor->getOutputGainMeterLevel(1);
        } break;
    }
    
    
    if(updatedCh0Level > mCh0Level){
        mCh0Level = updatedCh0Level;
    } else {
        mCh0Level = kMeterSmoothingCoeff*(mCh0Level - updatedCh0Level) + updatedCh0Level;
    }
    
    if(updatedCh1Level > mCh1Level){
        mCh1Level = updatedCh1Level;
    } else {
        mCh1Level = kMeterSmoothingCoeff*(mCh1Level - updatedCh1Level) + updatedCh1Level;
    }
    
    mCh0Level = ac_denormalize(mCh0Level);
    mCh1Level = ac_denormalize(mCh1Level);
    
    if (mCh0Level || mCh1Level){
        repaint();
    }
}

void AC_VuMeter::setParameterID(int inParameterID)
{
    mParameterID = inParameterID;
    
    startTimerHz(15);
}
