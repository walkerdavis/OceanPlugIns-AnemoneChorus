/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "AC_MainPanel.h"
#include "AC_LookAndFeel.h"

//==============================================================================
/**
*/
class AnemoneChorusAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AnemoneChorusAudioProcessorEditor (AnemoneChorusAudioProcessor&);
    ~AnemoneChorusAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AnemoneChorusAudioProcessor& processor;
    
    std::unique_ptr<AC_MainPanel> mMainPanel;
    std::unique_ptr<AC_LookAndFeel> mLookAndFeel;
    
    Image mBackgroundImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnemoneChorusAudioProcessorEditor)
};
