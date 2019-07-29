/*
  ==============================================================================

    AC_GainPanel.cpp
    Created: 29 Jul 2019 3:33:07pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_GainPanel.h"
#include "AC_Parameters.h"
#include "AC_HelperFunctions.h"

AC_GainPanel::AC_GainPanel(AnemoneChorusAudioProcessor* inProcessor)
:   AC_PanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH,
            GAIN_PANEL_HEIGHT);
    
    const int meter_width = 64;
    mVuMeter = new AC_VuMeter(mProcessor);
    mVuMeter->setBounds((getWidth() * 0.5) - (meter_width * 0.5),
                        (getHeight() * 0.55) - (meter_width * 0.5),
                        meter_width,
                        getHeight() * 0.45);
    addAndMakeVisible(mVuMeter);
    
}
AC_GainPanel::~AC_GainPanel(){
    
}

void AC_GainPanel::paint(Graphics& g)
{
    AC_PanelBase::paint(g);
    
    if (mSlider){
        paintComponentLabel(g, mSlider);
    }
}

void AC_GainPanel::setParameterID(int inParameterID)
{
    mSlider = new AC_ParameterSlider(mProcessor->parameters,
                                      AC_ParameterID[inParameterID],
                                      AC_ParameterLabel[inParameterID]);
    
    const int sliderSize = 54;
    
    mSlider->setBounds((getWidth() * .5) - (sliderSize * .5),
                       (getHeight() * .25) - (sliderSize * .5) - 10,
                       sliderSize,
                       sliderSize);
    
    addAndMakeVisible(mSlider);
    
    mVuMeter->setParameterID(inParameterID);
}
