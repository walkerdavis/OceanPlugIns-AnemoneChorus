/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AC_Parameters.h"

//==============================================================================
AnemoneChorusAudioProcessor::AnemoneChorusAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
                parameters(*this,
                           nullptr,
                           juce::Identifier("AC"),
                           createParameterLayout())
#endif
{
    initializeDSP();
}

AnemoneChorusAudioProcessor::~AnemoneChorusAudioProcessor()
{
}

//==============================================================================
const String AnemoneChorusAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AnemoneChorusAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AnemoneChorusAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AnemoneChorusAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AnemoneChorusAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AnemoneChorusAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AnemoneChorusAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AnemoneChorusAudioProcessor::setCurrentProgram (int index)
{
}

const String AnemoneChorusAudioProcessor::getProgramName (int index)
{
    return {};
}

void AnemoneChorusAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AnemoneChorusAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int i = 0; i < 2; ++i){
        mDelay[i]->setSampleRate(sampleRate);
        mLFO[i]->setSampleRate(sampleRate);
    }
}

void AnemoneChorusAudioProcessor::releaseResources()
{
    for (int i = 0; i < 2; ++i){
        mDelay[i]->reset();
        mLFO[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AnemoneChorusAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AnemoneChorusAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    //clear garbage
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        float inputGain = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterInputGain]);
        mInputGain[channel]->process(channelData,
                                     inputGain,
                                     channelData,
                                     buffer.getNumSamples());
        
        
        float rate = *parameters.getRawParameterValue(AC_ParameterID[kAC_ModulationRate]);
        if (channel==0){
            rate = 0;
        }
        
        float modulationDepth = *parameters.getRawParameterValue(AC_ParameterID[kAC_ModulationDepth]);
        mLFO[channel]->process(rate,
                               modulationDepth,
                               buffer.getNumSamples());
        
        float delayTime = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterDelayTime]);
        float delayFeedback = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterFeedback]);
        float wetDry = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterWetDry]);
        float delayType = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterDelayType]);
        mDelay[channel]->process(channelData,
                                 delayTime,
                                 delayFeedback,
                                 wetDry,
                                 delayType,
                                 mLFO[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
        
        float outputGain = *parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterOutputGain]);
        mOutputGain[channel]->process(channelData,
                                      outputGain,
                                      channelData,
                                      buffer.getNumSamples());
    }
}

//==============================================================================
bool AnemoneChorusAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AnemoneChorusAudioProcessor::createEditor()
{
    return new AnemoneChorusAudioProcessorEditor (*this);
}

//==============================================================================
void AnemoneChorusAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AnemoneChorusAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

float AnemoneChorusAudioProcessor::getInputGainMeterLevel(int inChannel)
{
    const float normalizeddB = dBToNormalizedGain(mInputGain[inChannel]->getMeterLevel());
    return normalizeddB;
}

float AnemoneChorusAudioProcessor::getOutputGainMeterLevel(int inChannel)
{
    const float normalizeddB = dBToNormalizedGain(mOutputGain[inChannel]->getMeterLevel());
    return normalizeddB;
}

void AnemoneChorusAudioProcessor::initializeDSP()
{
    for (int i = 0; i < 2; ++i){
        
        mInputGain[i].reset(new AC_Gain());
        mOutputGain[i].reset(new AC_Gain());
        mDelay[i].reset(new AC_Delay());
        mLFO[i].reset(new AC_LFO());
    }
}

AudioProcessorValueTreeState::ParameterLayout AnemoneChorusAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for (int i = 0; i < kAC_Parameter_TotalNumParameters; ++i){
        
        params.push_back(std::make_unique<AudioParameterFloat>(AC_ParameterID[i],
                                                               AC_ParameterLabel[i],
                                                               NormalisableRange<float>(0.0f,1.0f),
                                                               AC_ParameterDefaultValue[i]));
    }
    return { params.begin(), params.end() };
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AnemoneChorusAudioProcessor();
}
