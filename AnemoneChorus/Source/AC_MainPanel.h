/*
  ==============================================================================

    AC_MainPanel.h
    Created: 29 Jul 2019 3:27:48pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "AC_PanelBase.h"

#include "AC_TopPanel.h"
#include "AC_GainPanel.h"
#include "AC_CenterPanel.h"

class AC_MainPanel
:   public AC_PanelBase
{
    
public:
    AC_MainPanel(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_MainPanel();
    
private:
    
    ScopedPointer<AC_TopPanel> mTopPanel;
    ScopedPointer<AC_GainPanel> mInputGainPanel;
    ScopedPointer<AC_GainPanel> mOutputGainPanel;
    ScopedPointer<AC_CenterPanel> mCenterPanel;
};
