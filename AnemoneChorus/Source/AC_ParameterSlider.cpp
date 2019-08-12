/*
  ==============================================================================

    AC_ParameterSlider.cpp
    Created: 29 Jul 2019 3:35:41pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_ParameterSlider.h"

AC_ParameterSlider::AC_ParameterSlider(AudioProcessorValueTreeState& stateToControl,
                                         const String& parameterID,
                                         const String& parameterLabel)
:   juce::Slider(parameterLabel)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    
    setRange(0.0f, 1.0f, 0.001f);
    
//    mAttachment = new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this);
    mAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this));
}

AC_ParameterSlider::~AC_ParameterSlider()
{
    
}
