/*
  ==============================================================================

    AC_CenterPanel.h
    Created: 29 Jul 2019 3:36:59pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_PanelBase.h"
#include "AC_FXPanel.h"

class AC_CenterPanel
:   public AC_PanelBase
{
    
public:
    AC_CenterPanel(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_CenterPanel();

private:
    ScopedPointer<AC_FXPanel> mFXPanel;
};
