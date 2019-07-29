/*
  ==============================================================================

    AC_CenterPanelMenuBar.cpp
    Created: 29 Jul 2019 3:38:52pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_CenterPanelMenuBar.h"
#include "AC_Parameters.h"

AC_CenterPanelMenuBar::AC_CenterPanelMenuBar(AnemoneChorusAudioProcessor* inProcessor)
:   AC_PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
    
    const int width = 85;
    
    mFXTypeComboBox = new AC_ParameterComboBox(mProcessor->parameters,
                                                AC_ParameterID[kAC_ParameterDelayType]);
    mFXTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
    mFXTypeComboBox->addItem("DELAY", 1);
    mFXTypeComboBox->addItem("CHORUS", 2);
    
    float delayType = *mProcessor->parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterDelayType]);
    mFXTypeComboBox->setSelectedItemIndex((int)delayType,
                                          dontSendNotification);
    addAndMakeVisible(mFXTypeComboBox);
}
AC_CenterPanelMenuBar::~AC_CenterPanelMenuBar()
{
    
}


void AC_CenterPanelMenuBar::addFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->addListener(inListener);
}


void AC_CenterPanelMenuBar::removeFXTypeComboBoxListener(ComboBox::Listener* inListener)
{
    mFXTypeComboBox->removeListener(inListener);
}
