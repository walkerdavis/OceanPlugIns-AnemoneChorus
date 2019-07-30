/*
  ==============================================================================

    AC_PanelBase.cpp
    Created: 29 Jul 2019 3:26:07pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#include "AC_PanelBase.h"
#include "AC_InterfaceDefines.h"

AC_PanelBase::AC_PanelBase(AnemoneChorusAudioProcessor* inProcessor)
:   mProcessor(inProcessor)
{
    
}

AC_PanelBase::~AC_PanelBase()
{
    
}

void AC_PanelBase::mouseEnter (const MouseEvent& event)
{
    repaint();
}

void AC_PanelBase::mouseExit (const MouseEvent& event)
{
    repaint();
}


void AC_PanelBase::paint(Graphics& g)
{
//    if(isMouseOver(true)){
//        const Colour hoverColour = Colour(Colours::black).withAlpha(0.4f);
//        g.setColour(hoverColour);
//        g.fillAll();
//    }
    
}
