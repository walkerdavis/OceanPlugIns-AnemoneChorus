/*
  ==============================================================================

    AC_CenterPanelMenuBar.h
    Created: 29 Jul 2019 3:38:52pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_PanelBase.h"
#include "AC_ParameterComboBox.h"

class AC_CenterPanelMenuBar
:   public AC_PanelBase
{
    
public:
    AC_CenterPanelMenuBar(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_CenterPanelMenuBar();
    
    void addFXTypeComboBoxListener(ComboBox::Listener* inListener);
    void removeFXTypeComboBoxListener(ComboBox::Listener* inListener);
    
private:
    
    ScopedPointer<AC_ParameterComboBox> mFXTypeComboBox;
    
};
