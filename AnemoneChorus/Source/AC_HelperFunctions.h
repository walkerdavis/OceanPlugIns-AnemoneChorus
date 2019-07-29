/*
  ==============================================================================

    AC_HelperFunctions.h
    Created: 29 Jul 2019 2:22:30pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once
#include "AC_InterfaceDefines.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent)
{
    const int x = (inComponent->getX()) - (inComponent->getWidth() * 0.25f);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    
    const float cornerSize = 3.0f;
    const String label = inComponent->getName();
    
    g.setColour(AC_Colour_3);
    g.fillRoundedRectangle(x, y, w, h, cornerSize);
    
    g.setColour(AC_Colour_1);
    g.setFont(font_1);
    g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}
