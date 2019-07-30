/*
  ==============================================================================

    AC_LookAndFeel.h
    Created: 29 Jul 2019 3:50:03pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "AC_InterfaceDefines.h"

class AC_LookAndFeel
:   public LookAndFeel_V4
{
public:
    AC_LookAndFeel()
    {
        // store image assests
        mSliderImage = ImageCache::getFromMemory(BinaryData::ac_knob_png,
                                                 BinaryData::ac_knob_pngSize);
        
        //ComboBox Colours
        setColour(ComboBox::backgroundColourId, AC_Colour_3);
        setColour(ComboBox::outlineColourId, AC_Colour_2);
        setColour(ComboBox::arrowColourId, AC_Colour_1);
        setColour(ComboBox::textColourId, AC_Colour_1);
        
        // button text colours
        setColour(TextButton::buttonColourId, AC_Colour_1);
        setColour(TextButton::textColourOnId, AC_Colour_1);
        setColour(TextButton::textColourOffId, AC_Colour_1);
    }
    virtual ~AC_LookAndFeel() {};
    
    /** buttons */
    Font getTextButtonFont (TextButton&, int buttonHeight) override
    {
        return font_1;
    }
    
    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) override
    {
        Colour fillColour;
        
        if(isButtonDown){
            fillColour = AC_Colour_6;
        } else if(isMouseOverButton){
            fillColour = AC_Colour_3;
        } else {
            fillColour = AC_Colour_5;
        }
        
        const float cornerSize = 6.0f;
        const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5f, 0.5f);
        
        g.setColour(fillColour);
        g.fillRoundedRectangle(bounds.reduced(1), cornerSize);
    }
    
    /** comboboxs */
    Font getLabelFont(Label& label) override
    {
        return font_1;
    }
    
    void drawPopupMenuItem (Graphics& g, const Rectangle<int>& area,
                            bool isSeparator, bool isActive, bool isHighlighted, bool isTicked, bool hasSubMenu,
                            const String& text, const String& shortcutKeyText,
                            const Drawable* icon, const Colour* textColour) override
    {
        juce::Rectangle<int> r (area);
        
        Colour fillColour = isHighlighted ? AC_Colour_5 : AC_Colour_4;
        g.setColour(fillColour);
        
        g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight() - 1);
        
        Colour myTextColour = isTicked ? AC_Colour_7 : AC_Colour_1;
        g.setColour(myTextColour);
        g.setFont(font_1);
        
        r.setLeft(10);
        r.setY(1);
        g.drawFittedText(text, r, Justification::left, 1);
    }
    
    void drawComboBox (Graphics& g, int width, int height, bool isButtonDown,
                       int buttonX, int buttonY, int buttonW, int buttonH,
                       ComboBox& box) override
    {
        const float cornerSize = 3.0f;
        const juce::Rectangle<int> boxBounds (0, 0, width, height);
        
        g.setColour(AC_Colour_3);
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);
        
        juce::Rectangle<int> arrow (width - 30, 0, 20, height);
        
        Path path;
        
        path.startNewSubPath(arrow.getX() + 3.0f, arrow.getCentreY() - 2.0f);
        path.lineTo(arrow.toFloat().getCentreX(), arrow.toFloat().getCentreY() + 3.0f);
        path.lineTo(arrow.toFloat().getRight() - 3.0f, arrow.toFloat().getCentreY() - 2.0f);
        
        Colour arrowColour = box.findColour(ComboBox::arrowColourId).withAlpha(box.isEnabled() ? 0.9f : 0.2f);
        g.setColour(arrowColour);
        g.strokePath(path, PathStrokeType(2.0f));
        
        
    }
    
    /** sliders */
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, Slider& slider) override
    {

        const int numFrames = mSliderImage.getHeight()/mSliderImage.getWidth();
        const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));
        
        const float radius = jmin(width*0.5, height*0.5);
        const float centreX = x + width * 0.5f;
        const float centreY = x + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(mSliderImage,
                    rx,
                    ry,
                    2*radius,
                    2*radius,
                    0,
                    frameIndex * mSliderImage.getWidth(),
                    mSliderImage.getWidth(),
                    mSliderImage.getWidth());
    }
    
    
private:
    
    Image mSliderImage;
};


class AC_OtherLookAndFeel
:   public LookAndFeel_V4
{
public:
    AC_OtherLookAndFeel()
    {
        // store image assests
        mSliderImage = ImageCache::getFromMemory(BinaryData::ac_knob2_png,
                                                 BinaryData::ac_knob2_pngSize);
    }
    virtual ~AC_OtherLookAndFeel() {};
    
    /** sliders */
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height,
                           float sliderPosProportional, float rotaryStartAngle,
                           float rotaryEndAngle, Slider& slider) override
    {
        
        const int numFrames = mSliderImage.getHeight()/mSliderImage.getWidth();
        const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));
        
        const float radius = jmin(width*0.5, height*0.5);
        const float centreX = x + width * 0.5f;
        const float centreY = x + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(mSliderImage,
                    rx,
                    ry,
                    2*radius,
                    2*radius,
                    0,
                    frameIndex * mSliderImage.getWidth(),
                    mSliderImage.getWidth(),
                    mSliderImage.getWidth());
    }
    
    
private:
    
    Image mSliderImage;
};
