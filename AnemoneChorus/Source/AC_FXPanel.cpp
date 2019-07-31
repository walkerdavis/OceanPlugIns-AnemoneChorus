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
    
    const int currentStyle = kAC_FXPanelStyle_Chorus;
    setFXPanelStyle((AC_FXPanelStyle)currentStyle);
}

AC_FXPanel::~AC_FXPanel()
{
}

void AC_FXPanel::paint(Graphics& g)
{
    AC_PanelBase::paint(g);
    
//    String label;
    
    switch (mStyle)
    {
        case (kAC_FXPanelStyle_Chorus):{
//            label = "";
        } break;
            
        default:
        case (kAC_FXPanelStyle_TotalNumStyles):{
            jassertfalse;
        } break;
    }
    
    
//    g.setColour(AC_Colour_5);
//    g.setFont(font_3);
//    
//    g.drawText(label, 0, 0, getWidth(), 80, Justification::centred);
    
    
    //paint labels for each slider
//    for (int i = 0; i < mSliders.size(); i ++)
//    {
//        paintComponentLabel(g, mSliders[i]);
//    }
    
}

void AC_FXPanel::setFXPanelStyle(AC_FXPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mSliders.clear();
    
    const float slider_size = 56.f;
    const float slider_offset = 1.5f;
    int x = 50;
    int y = (getHeight() * .5) - (slider_size * .5);
    //width = 750
    //height = 300
    
    switch (mStyle)
    {
            
        case (kAC_FXPanelStyle_Chorus):{
            
            //1 input gain
            AC_ParameterSlider* gain_in = new AC_ParameterSlider(mProcessor->parameters,
                                                               AC_ParameterID[kAC_ParameterInputGain],
                                                               AC_ParameterLabel[kAC_ParameterInputGain]);
            gain_in->setBounds(140, 160, 62, 62);
            addAndMakeVisible(gain_in);
            mSliders.add(gain_in);
            
            //2 chorus rate
            AC_ParameterSlider* rate = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationRate],
                                                                 AC_ParameterLabel[kAC_ModulationRate]);
//            rate.setLookAndFeel(&AC_OtherLookAndFeel);
            
            rate->setBounds(125, 90, 47, 47);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            
            //3 chorus depth
            AC_ParameterSlider* depth = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationDepth],
                                                                 AC_ParameterLabel[kAC_ModulationDepth]);
            depth->setBounds(200, 60, 48, 48);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            
            //4 chorus width
            AC_ParameterSlider* width = new AC_ParameterSlider(mProcessor->parameters,
                                                               AC_ParameterID[kAC_ModulationWidth],
                                                               AC_ParameterLabel[kAC_ModulationWidth]);
            width->setBounds(210, 185, 42, 42);
            addAndMakeVisible(width);
            mSliders.add(width);
            
            //5 chorus phase offset
            AC_ParameterSlider* feedback = new AC_ParameterSlider(mProcessor->parameters,
                                                                      AC_ParameterID[kAC_ParameterFeedback],
                                                                      AC_ParameterLabel[kAC_ParameterFeedback]);
            feedback->setBounds(580, 45, 47, 47);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            
            //6 chorus phase offset
            AC_ParameterSlider* phase_offset = new AC_ParameterSlider(mProcessor->parameters,
                                                               AC_ParameterID[kAC_ModulationPhaseOffset],
                                                               AC_ParameterLabel[kAC_ModulationPhaseOffset]);
            phase_offset->setBounds(585, 155, 47, 47);
            addAndMakeVisible(phase_offset);
            mSliders.add(phase_offset);
            
            //7 chorus wetdry
            AC_ParameterSlider* wetdry = new AC_ParameterSlider(mProcessor->parameters,
                                                                  AC_ParameterID[kAC_ParameterWetDry],
                                                                  AC_ParameterLabel[kAC_ParameterWetDry]);
            wetdry->setBounds(670, 80, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            
            //8 output gain
            AC_ParameterSlider* gain_out = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ParameterOutputGain],
                                                                 AC_ParameterLabel[kAC_ParameterOutputGain]);
            gain_out->setBounds(670, 160, 62, 62);
            addAndMakeVisible(gain_out);
            mSliders.add(gain_out);
            
        } break;
            
        default:
        case (kAC_FXPanelStyle_TotalNumStyles):{
            
            
            jassertfalse;
        } break;
    }
    
    repaint();
    
}
