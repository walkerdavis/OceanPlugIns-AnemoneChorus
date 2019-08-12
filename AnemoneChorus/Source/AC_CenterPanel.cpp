/*
  ==============================================================================

    AC_CenterPanel.cpp
    Created: 29 Jul 2019 3:36:59pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_CenterPanel.h"

AC_CenterPanel::AC_CenterPanel(AnemoneChorusAudioProcessor* inProcessor)\
:   AC_PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
//    mFXPanel = new AC_FXPanel(inProcessor);
    mFXPanel.reset(new AC_FXPanel(inProcessor));
    mFXPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mFXPanel.get());
    
}
AC_CenterPanel::~AC_CenterPanel()
{
}
