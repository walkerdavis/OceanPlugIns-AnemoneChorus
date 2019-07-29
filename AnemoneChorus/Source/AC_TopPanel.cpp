/*
  ==============================================================================

    AC_TopPanel.cpp
    Created: 29 Jul 2019 3:30:04pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_TopPanel.h"

AC_TopPanel::AC_TopPanel(AnemoneChorusAudioProcessor* inProcessor)
:   AC_PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH,
            TOP_PANEL_HEIGHT);
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPreset = new TextButton();
    mNewPreset->setButtonText("NEW");
    mNewPreset->setBounds(button_x, button_y, button_w, button_h);
    mNewPreset->addListener(this);
    addAndMakeVisible(mNewPreset);
    
    button_x = button_x + button_w;
    mSavePreset = new TextButton();
    mSavePreset->setButtonText("SAVE");
    mSavePreset->setBounds(button_x, button_y, button_w, button_h);
    mSavePreset->addListener(this);
    addAndMakeVisible(mSavePreset);
    
    button_x = button_x + button_w;
    mSaveAsPreset = new TextButton();
    mSaveAsPreset->setButtonText("SAVE AS");
    mSaveAsPreset->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPreset->addListener(this);
    addAndMakeVisible(mSaveAsPreset);
    
    const int comboBox_w = 200;
    const int comboBox_x = (TOP_PANEL_WIDTH*0.5) - (comboBox_w*0.5);
    
    mPresetDisplay = new ComboBox();
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mPresetDisplay->addListener(this);
    addAndMakeVisible(mPresetDisplay);
    
    updatePresetComboBox();
}

AC_TopPanel::~AC_TopPanel()
{
    
}

void AC_TopPanel::paint(Graphics& g)
{
    AC_PanelBase::paint(g);
    
    g.setColour(AC_Colour_1);
    g.setFont(font_2);
    const int label_w = 200;
    
    g.drawFittedText("",
                     TOP_PANEL_WIDTH - label_w,
                     0,
                     label_w,
                     getHeight(),
                     Justification::centredRight,
                     1);
}


void AC_TopPanel::buttonClicked (Button* b)
{
    AC_PresetManager* presetManager = mProcessor->getPresetManager();

    if (b == mNewPreset){
        presetManager->createNewPreset();

        updatePresetComboBox();
    } else if (b == mSavePreset){
        presetManager->savePreset();
    } else if (b == mSaveAsPreset){
        displaySaveAsPopUp();
    }
}
void AC_TopPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if(comboBoxThatHasChanged == mPresetDisplay){

        AC_PresetManager* presetManager = mProcessor->getPresetManager();

        const int index = mPresetDisplay->getSelectedItemIndex();
        presetManager->loadPreset(index);
    }
}

void AC_TopPanel::displaySaveAsPopUp()
{
    AC_PresetManager* presetManager = mProcessor->getPresetManager();

    String currentPresetName = presetManager->getCurrentPresetName();

    AlertWindow window ("Save As", "Please enter a name for your preset", AlertWindow::NoIcon);

    window.centreAroundComponent(this, getWidth(), getHeight());
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    window.addButton("Confirm", 1);
    window.addButton("Cancel", 0);

    if(window.runModalLoop()){

        String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);

        updatePresetComboBox();
    }
}
void AC_TopPanel::updatePresetComboBox()
{
    AC_PresetManager* presetManager = mProcessor->getPresetManager();
    String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(dontSendNotification);
    
    const int numPresets = presetManager->getNumberOfPresets();
    
    for (int i = 0; i < numPresets; i ++){
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i+1));
    }
    
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
}
