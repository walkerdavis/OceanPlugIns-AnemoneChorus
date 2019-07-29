/*
  ==============================================================================

    AC_FXPanel.cpp
    Created: 29 Jul 2019 3:40:51pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_FXPanel.h"
#include "AC_Parameters.h"
#include "AC_HelperFunctions.h"

AC_FXPanel::AC_FXPanel(AnemoneChorusAudioProcessor* inProcessor)
:   AC_PanelBase(inProcessor)
{
    setSize(FX_PANEL_WIDTH,
            FX_PANEL_HEIGHT);
    
    const int currentStyle = (int)*mProcessor->parameters.getRawParameterValue(AC_ParameterID[kAC_ParameterDelayType]);
    setFXPanelStyle((AC_FXPanelStyle)currentStyle);
}

AC_FXPanel::~AC_FXPanel()
{
}

void AC_FXPanel::paint(Graphics& g)
{
    AC_PanelBase::paint(g);
    
    String label;
    
    switch (mStyle)
    {
        case (kAC_FXPanelStyle_Delay):{
            label = "DELAY";
        } break;
            
        case (kAC_FXPanelStyle_Chorus):{
            label = "CHORUS";
        } break;
            
        default:
        case (kAC_FXPanelStyle_TotalNumStyles):{
            jassertfalse;
        } break;
    }
    
    
    g.setColour(AC_Colour_5);
    g.setFont(font_3);
    
    g.drawText(label, 0, 0, getWidth(), 80, Justification::centred);
    
    
    //paint labels for each slider
    for (int i = 0; i < mSliders.size(); i ++)
    {
        paintComponentLabel(g, mSliders[i]);
    }
    
}

void AC_FXPanel::setFXPanelStyle(AC_FXPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mSliders.clear();
    
    const int slider_size = 56;
    int x = 130;
    int y = (getHeight() * .5) - (slider_size * .5);
    
    switch (mStyle)
    {
        case (kAC_FXPanelStyle_Delay):{
            
            //delay time //follow order create, set bounds, addAndMakeVisible
            AC_ParameterSlider* time = new AC_ParameterSlider(mProcessor->parameters,
                                                                AC_ParameterID[kAC_ParameterDelayTime],
                                                                AC_ParameterLabel[kAC_ParameterDelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            x = x + (slider_size * 2);
            
            //delay feedback
            AC_ParameterSlider* feedback = new AC_ParameterSlider(mProcessor->parameters,
                                                                    AC_ParameterID[kAC_ParameterFeedback],
                                                                    AC_ParameterLabel[kAC_ParameterFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x = x + (slider_size * 2);
            
            //delay wetdry
            AC_ParameterSlider* wetdry = new AC_ParameterSlider(mProcessor->parameters,
                                                                  AC_ParameterID[kAC_ParameterWetDry],
                                                                  AC_ParameterLabel[kAC_ParameterWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            x = x + (slider_size * 2);
            
            
        } break;
            
        case (kAC_FXPanelStyle_Chorus):{
            
            //chorus rate
            AC_ParameterSlider* rate_ = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationRate],
                                                                 AC_ParameterLabel[kAC_ModulationRate]);
            rate_->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate_);
            mSliders.add(rate_);
            x = x + (slider_size * 2);
            
            //chorus depth
            AC_ParameterSlider* depth = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationDepth],
                                                                 AC_ParameterLabel[kAC_ModulationDepth]);
            depth->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            x = x + (slider_size * 2);
            
            //chorus wetdry
            AC_ParameterSlider* wetdry = new AC_ParameterSlider(mProcessor->parameters,
                                                                  AC_ParameterID[kAC_ParameterWetDry],
                                                                  AC_ParameterLabel[kAC_ParameterWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            x = x + (slider_size * 2);
            
        } break;
            
        default:
        case (kAC_FXPanelStyle_TotalNumStyles):{
            
            
            jassertfalse;
        } break;
    }
    
    repaint();
    
}


void AC_FXPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    AC_FXPanelStyle style = (AC_FXPanelStyle)comboBoxThatHasChanged->getSelectedItemIndex();
    
    setFXPanelStyle(style);
}
