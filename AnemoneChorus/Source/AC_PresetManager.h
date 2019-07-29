/*
  ==============================================================================

    AC_PresetManager.h
    Created: 29 Jul 2019 4:04:47pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#define PRESET_FILE_EXTENSION ".opf"

class AC_PresetManager
{
public:
    AC_PresetManager(AudioProcessor* inProcessor);
    ~AC_PresetManager();
    
    void getXmlForPreset(XmlElement* inElement);
    
    void loadPresetForXml(XmlElement* inElement);
    
    int getNumberOfPresets();
    
    String getPresetName(int inPresetIndex);
    
    void createNewPreset();
    
    void savePreset();
    
    void saveAsPreset(String inPresetName);
    
    void loadPreset(int inPresetIndex);
    
    bool getIsCurrentPresetSaved();
    
    String getCurrentPresetName();
    
    
private:
    
    void storeLocalPreset();
    
    bool mCurrentPresetSaved;
    
    File mCurrentlyLoadedPreset;
    
    Array<File> mLocalPresets;
    
    String mCurrentPresetName;
    
    String mPresetDirectory;
    
    XmlElement* mCurrentXmlPreset;
    
    AudioProcessor* mProcessor;
};
