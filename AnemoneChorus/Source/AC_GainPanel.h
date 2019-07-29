/*
  ==============================================================================

    AC_GainPanel.h
    Created: 29 Jul 2019 3:33:07pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_PanelBase.h"
#include "AC_ParameterSlider.h"
#include "AC_VuMeter.h"

class AC_GainPanel
:   public AC_PanelBase
{
public:
    AC_GainPanel(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_GainPanel();
    
    void setParameterID(int inParameterID);
    
    void paint(Graphics& g) override;
    
private:
    
    ScopedPointer<AC_ParameterSlider> mSlider;
    ScopedPointer<AC_VuMeter> mVuMeter;
    
};
