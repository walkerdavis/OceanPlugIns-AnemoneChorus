/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "AC_LookAndFeel.h"

//==============================================================================
AnemoneChorusAudioProcessorEditor::AnemoneChorusAudioProcessorEditor (AnemoneChorusAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (MAIN_PANEL_WIDTH,
             MAIN_PANEL_HEIGHT);
    
    mLookAndFeel.reset(new AC_LookAndFeel);
    setLookAndFeel(mLookAndFeel.get());
    LookAndFeel::setDefaultLookAndFeel(mLookAndFeel.get());
    
    mBackgroundImage = ImageCache::getFromMemory(BinaryData::ac_bg_png,
                                                 BinaryData::ac_bg_pngSize);
    
    mMainPanel.reset(new AC_MainPanel(&processor));
    addAndMakeVisible(mMainPanel.get());
    
}

AnemoneChorusAudioProcessorEditor::~AnemoneChorusAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
    LookAndFeel::setDefaultLookAndFeel(nullptr);
    mLookAndFeel.reset();
}

//==============================================================================
void AnemoneChorusAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.drawImage(mBackgroundImage, getLocalBounds().toFloat());
}

void AnemoneChorusAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
