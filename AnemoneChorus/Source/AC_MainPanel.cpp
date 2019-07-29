/*
  ==============================================================================

    AC_MainPanel.cpp
    Created: 29 Jul 2019 3:27:48pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_MainPanel.h"
#include "AC_Parameters.h"

AC_MainPanel::AC_MainPanel(AnemoneChorusAudioProcessor* inProcessor)
:   AC_PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH,
            MAIN_PANEL_HEIGHT);
    
    mTopPanel = new AC_TopPanel(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
    
    mInputGainPanel = new AC_GainPanel(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(kAC_ParameterInputGain);
    addAndMakeVisible(mInputGainPanel);
    
    mOutputGainPanel = new AC_GainPanel(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(kAC_ParameterOutputGain);
    addAndMakeVisible(mOutputGainPanel);
    
    mCenterPanel = new AC_CenterPanel(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel);
}
AC_MainPanel::~AC_MainPanel()
{
    
}
