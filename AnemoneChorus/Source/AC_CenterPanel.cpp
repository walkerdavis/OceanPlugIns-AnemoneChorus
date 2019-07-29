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
    
    mMenuBar = new AC_CenterPanelMenuBar(inProcessor);
    mMenuBar->setTopLeftPosition(0,0);
    addAndMakeVisible(mMenuBar);
    
    mFXPanel = new AC_FXPanel(inProcessor);
    mFXPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mFXPanel);
    
    mMenuBar->addFXTypeComboBoxListener(mFXPanel);
}
AC_CenterPanel::~AC_CenterPanel()
{
    mMenuBar->removeFXTypeComboBoxListener(mFXPanel);
}
