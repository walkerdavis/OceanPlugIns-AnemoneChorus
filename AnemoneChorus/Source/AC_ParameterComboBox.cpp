/*
  ==============================================================================

    AC_ParameterComboBox.cpp
    Created: 29 Jul 2019 3:44:58pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_ParameterComboBox.h"

AC_ParameterComboBox::AC_ParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                                             const String& parameterID)
:   juce::ComboBox(parameterID)
{
    
//    mAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterID, *this);
    mAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterID, *this));
}

AC_ParameterComboBox::~AC_ParameterComboBox()
{
    
}
