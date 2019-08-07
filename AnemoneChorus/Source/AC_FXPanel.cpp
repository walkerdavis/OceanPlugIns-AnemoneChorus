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
    
//    const float slider_size = 56.f;
//    const float slider_offset = 1.5f;
//    int x = 50;

    
    switch (mStyle)
    {
            
        case (kAC_FXPanelStyle_Chorus):{
            
            // CHORUS ROTARY SLIDERS
            
            // chorus rate
            AC_ParameterSlider* rate = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationRate],
                                                                 AC_ParameterLabel[kAC_ModulationRate]);
            rate->setBounds(130, 70, 59, 59);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            
            // chorus depth
            AC_ParameterSlider* depth = new AC_ParameterSlider(mProcessor->parameters,
                                                                 AC_ParameterID[kAC_ModulationDepth],
                                                                 AC_ParameterLabel[kAC_ModulationDepth]);
            depth->setBounds(240, 70, 46, 46);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            
            // chorus feedback
            AC_ParameterSlider* feedback = new AC_ParameterSlider(mProcessor->parameters,
                                                                      AC_ParameterID[kAC_ParameterFeedback],
                                                                      AC_ParameterLabel[kAC_ParameterFeedback]);
            feedback->setBounds(130, 175, 49, 49);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            
            // chorus phase offset
            AC_ParameterSlider* phase_offset = new AC_ParameterSlider(mProcessor->parameters,
                                                               AC_ParameterID[kAC_ModulationPhaseOffset],
                                                               AC_ParameterLabel[kAC_ModulationPhaseOffset]);
            phase_offset->setBounds(200, 120, 53, 53);
            addAndMakeVisible(phase_offset);
            mSliders.add(phase_offset);
            
            // chorus wetdry
            AC_ParameterSlider* wetdry = new AC_ParameterSlider(mProcessor->parameters,
                                                                  AC_ParameterID[kAC_ParameterWetDry],
                                                                  AC_ParameterLabel[kAC_ParameterWetDry]);
            wetdry->setBounds(232, 180, 59, 59);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            
            
            // ENVELOPE FOLLOWER ROTARY SLIDERS
            
            // threshold
            AC_ParameterSlider* threshold = new AC_ParameterSlider(mProcessor->parameters,
                                                               AC_ParameterID[kAC_ParameterThreshold],
                                                               AC_ParameterLabel[kAC_ParameterThreshold]);
            threshold->setBounds(620, 55, 36, 36);
            addAndMakeVisible(threshold);
            mSliders.add(threshold);
            
            // attack
            AC_ParameterSlider* attack = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterAttack],
                                                                   AC_ParameterLabel[kAC_ParameterAttack]);
            attack->setBounds(685, 105, 39, 39);
            addAndMakeVisible(attack);
            mSliders.add(attack);
            
            // hold
            AC_ParameterSlider* hold = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterHold],
                                                                   AC_ParameterLabel[kAC_ParameterHold]);
            hold->setBounds(605, 140, 34, 34);
            addAndMakeVisible(hold);
            mSliders.add(hold);
            
            // release
            AC_ParameterSlider* release = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterRelease],
                                                                   AC_ParameterLabel[kAC_ParameterRelease]);
            release->setBounds(680, 170, 29, 29);
            addAndMakeVisible(release);
            mSliders.add(release);
            
            // floor
            AC_ParameterSlider* floor = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterFloor],
                                                                   AC_ParameterLabel[kAC_ParameterFloor]);
            floor->setBounds(590, 200, 37, 37);
            addAndMakeVisible(floor);
            mSliders.add(floor);
            
            
            // CHORUS AMOUNT ROTARY SLIDERS
            
            // rate amount
            AC_ParameterSlider* rate_amnt = new AC_ParameterSlider(mProcessor->parameters,
                                                              AC_ParameterID[kAC_ParameterRateAmount],
                                                              AC_ParameterLabel[kAC_ParameterRateAmount]);
            rate_amnt->setBounds(160, 50, 20, 20);
            addAndMakeVisible(rate_amnt);
            mSliders.add(rate_amnt);
            
            // depth amount
            AC_ParameterSlider* depth_amnt = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterDepthAmount],
                                                                   AC_ParameterLabel[kAC_ParameterDepthAmount]);
            depth_amnt->setBounds(235, 55, 17, 17);
            addAndMakeVisible(depth_amnt);
            mSliders.add(depth_amnt);
            
            // feedback amount
            AC_ParameterSlider* feedback_amnt = new AC_ParameterSlider(mProcessor->parameters,
                                                                   AC_ParameterID[kAC_ParameterFeedbackAmount],
                                                                   AC_ParameterLabel[kAC_ParameterFeedbackAmount]);
            feedback_amnt->setBounds(175, 170, 19, 19);
            addAndMakeVisible(feedback_amnt);
            mSliders.add(feedback_amnt);
            
        } break;
            
        default:
        case (kAC_FXPanelStyle_TotalNumStyles):{
            
            
            jassertfalse;
        } break;
    }
    
    repaint();
    
}
