/*
  ==============================================================================

    AC_PanelBase.h
    Created: 29 Jul 2019 3:26:07pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "AC_InterfaceDefines.h"

class AC_PanelBase
:   public Component
{
public:
    
    AC_PanelBase(AnemoneChorusAudioProcessor* inProcessor);
    ~AC_PanelBase();
    
    void mouseEnter (const MouseEvent& event) override;
    
    void mouseExit (const MouseEvent& event) override;
    
    void paint(Graphics& g) override;
    
    
protected:
    
    AnemoneChorusAudioProcessor* mProcessor;
};
