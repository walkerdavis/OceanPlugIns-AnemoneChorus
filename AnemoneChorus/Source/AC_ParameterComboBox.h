/*
  ==============================================================================

    AC_ParameterComboBox.h
    Created: 29 Jul 2019 3:44:58pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class AC_ParameterComboBox
:   public ComboBox
{
public:
    AC_ParameterComboBox(AudioProcessorValueTreeState& stateToControl,
                          const String& parameterID);
    
    ~AC_ParameterComboBox();
    
private:
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AC_ParameterComboBox);
    
};
