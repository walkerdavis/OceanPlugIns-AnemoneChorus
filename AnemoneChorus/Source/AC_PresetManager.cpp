/*
  ==============================================================================

    AC_PresetManager.cpp
    Created: 29 Jul 2019 4:04:47pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_PresetManager.h"

#if JUCE_WINDOWS
    static const String directorySeperator = "\\";
#else //JUCE_MAC
    static const String directorySeperator = "/";
#endif

AC_PresetManager::AC_PresetManager(AudioProcessor* inProcessor)
:   mCurrentPresetSaved(false),
    mCurrentPresetName(" --- "),
    mProcessor(inProcessor)
{
    const String pluginName = (String) mProcessor->getName();
    
    mPresetDirectory =
    (File::getSpecialLocation(File::userDesktopDirectory)).getFullPathName() + directorySeperator + pluginName;
    
    if(~File(mPresetDirectory).exists()){
        File(mPresetDirectory).createDirectory();
    }
    
    storeLocalPreset();
}
AC_PresetManager::~AC_PresetManager()
{
    
}


void AC_PresetManager::getXmlForPreset(XmlElement* inElement)
{
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++){
        AudioProcessorParameterWithID* parameter =
        (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        inElement->setAttribute(parameter->paramID, parameter->getValue());
    }
}


void AC_PresetManager::loadPresetForXml(XmlElement* inElement)
{
    mCurrentXmlPreset = inElement;
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < mCurrentXmlPreset->getNumAttributes(); i++){
        
        const String paramID = mCurrentXmlPreset->getAttributeName(i);
        const float value = mCurrentXmlPreset->getDoubleAttribute(paramID);
        
        for (int j = 0; j < mProcessor->getParameters().size(); j ++){
            AudioProcessorParameterWithID* parameter =
            (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
            
            if(paramID == parameter->paramID){
                parameter->setValueNotifyingHost(value);
            }
        }
    }
}


int AC_PresetManager::getNumberOfPresets()
{
    return mLocalPresets.size();
}

String AC_PresetManager::getPresetName(int inPresetIndex)
{
    return mLocalPresets[inPresetIndex].getFileNameWithoutExtension();
}

void AC_PresetManager::createNewPreset()
{
    
    auto& parameters = mProcessor->getParameters();
    
    for (int i = 0; i < parameters.size(); i++){
        AudioProcessorParameterWithID* parameter =
        (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
        
        const float defaultValue = parameter->getDefaultValue();
        parameter->setValueNotifyingHost(defaultValue);
    }
    
    mCurrentPresetSaved = false;
    mCurrentPresetName = "Untitled Preset";
}

void AC_PresetManager::savePreset()
{
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    mCurrentlyLoadedPreset.deleteFile();
    
    mCurrentlyLoadedPreset.appendData(destinationData.getData(),
                                      destinationData.getSize());
    
    mCurrentPresetSaved = true;
}

void AC_PresetManager::saveAsPreset(String inPresetName)
{
    
    File presetFile = File(mPresetDirectory + directorySeperator + inPresetName + PRESET_FILE_EXTENSION);
    
    if (!presetFile.exists()){
        presetFile.create();
    } else {
        presetFile.deleteFile();
    }
    
    MemoryBlock destinationData;
    mProcessor->getStateInformation(destinationData);
    
    presetFile.appendData(destinationData.getData(),
                          destinationData.getSize());
    
    mCurrentPresetSaved = true;
    mCurrentPresetName = inPresetName;
    
    storeLocalPreset();
    
}

void AC_PresetManager::loadPreset(int inPresetIndex)
{
    mCurrentlyLoadedPreset = mLocalPresets[inPresetIndex];
    
    MemoryBlock presetBinary;
    
    if (mCurrentlyLoadedPreset.loadFileAsData(presetBinary)){
        mCurrentPresetSaved = true;
        mCurrentPresetName = getPresetName(inPresetIndex);
        mProcessor->setStateInformation(presetBinary.getData(),
                                        (int)presetBinary.getSize());
    }
}

bool AC_PresetManager::getIsCurrentPresetSaved()
{
    return mCurrentPresetSaved;
}

String AC_PresetManager::getCurrentPresetName()
{
    return mCurrentPresetName;
}


void AC_PresetManager::storeLocalPreset()
{
    mLocalPresets.clear();
    
    for(DirectoryIterator di (File(mPresetDirectory),
                              false,
                              "*"+(String)PRESET_FILE_EXTENSION,
                              File::TypesOfFileToFind::findFiles); di.next();)
    {
        File preset = di.getFile();
        mLocalPresets.add(preset);
    }
}
