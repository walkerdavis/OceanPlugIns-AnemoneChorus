/*
  ==============================================================================

    AC_TopPanel.h
    Created: 29 Jul 2019 3:30:04pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once
#include "AC_PanelBase.h"

class AC_TopPanel
:   public AC_PanelBase,
    public Button::Listener,
    public ComboBox::Listener

{
    
public:
    AC_TopPanel(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_TopPanel();
    
    void paint(Graphics& g) override;
    
    void buttonClicked (Button*) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    
private:
    
    void displaySaveAsPopUp();
    void updatePresetComboBox();
    
    ScopedPointer<ComboBox> mPresetDisplay;
    ScopedPointer<TextButton> mNewPreset, mSavePreset, mSaveAsPreset;
};
