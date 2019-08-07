/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "AC_Gain.h"
#include "AC_Delay.h"
#include "AC_LFO.h"
#include "AC_EnvelopeFollower.h"
#include "AC_PresetManager.h"

//==============================================================================
/**
*/
class AnemoneChorusAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AnemoneChorusAudioProcessor();
    ~AnemoneChorusAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

//   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
//   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    float getInputGainMeterLevel(int inChannel);
    float getOutputGainMeterLevel(int inChannel);
    
    AudioProcessorValueTreeState parameters;
    
    AC_PresetManager* getPresetManager(){
        return mPresetManager.get();
    }
    
private:
    
    std::unique_ptr<AC_Gain> mInputGain [2];
    std::unique_ptr<AC_Gain> mOutputGain [2];
    std::unique_ptr<AC_Delay> mDelay [2];
    std::unique_ptr<AC_LFO> mLFO [2];
    std::unique_ptr<AC_EnvelopeFollower> mEnvFol [2];
    
    std::unique_ptr<AC_PresetManager> mPresetManager;
    
    void initializeDSP();
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnemoneChorusAudioProcessor)
};
