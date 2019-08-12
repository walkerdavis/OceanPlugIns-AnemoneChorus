/*
  ==============================================================================

    AC_ParameterSlider.h
    Created: 29 Jul 2019 3:35:41pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class AC_ParameterSlider
:   public Slider
{
public:
    AC_ParameterSlider(AudioProcessorValueTreeState& stateToControl,
                        const String& parameterID,
                        const String& parameterLabel);
    
    ~AC_ParameterSlider();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AC_ParameterSlider);
    
};
