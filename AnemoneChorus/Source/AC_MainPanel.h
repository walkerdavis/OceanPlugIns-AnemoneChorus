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
#include "AC_CenterPanel.h"

class AC_MainPanel
:   public AC_PanelBase
{
    
public:
    AC_MainPanel(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_MainPanel();
    
private:
    
    std::unique_ptr<AC_TopPanel> mTopPanel;
    std::unique_ptr<AC_CenterPanel> mCenterPanel;
};
