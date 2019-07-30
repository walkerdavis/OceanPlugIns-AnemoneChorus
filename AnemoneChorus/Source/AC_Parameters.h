/*
  ==============================================================================

    AC_Parameters.h
    Created: 29 Jul 2019 2:19:54pm
    Author:  Walker R. Davis

  ==============================================================================
*/

#pragma once
enum AC_Parameters
{
    kAC_ParameterInputGain = 0,
    kAC_ModulationRate,
    kAC_ModulationWidth,
    kAC_ModulationDepth,
    
    kAC_ParameterFeedback,
    kAC_ModulationPhaseOffset,
    kAC_ParameterWetDry,
    kAC_ParameterOutputGain,
    
    kAC_Parameter_TotalNumParameters
};

static String AC_ParameterID [kAC_Parameter_TotalNumParameters] =
{
    "InputGain",
    "ModulationRate",
    "ModulationWidth",
    "ModulationDepth",
    
    "Feedback",
    "ModulationPhaseOffset",
    "WetDry",
    "OutputGain",
};

static String AC_ParameterLabel [kAC_Parameter_TotalNumParameters] =
{
    "Input Gain",
    "Mod Rate",
    "Mod Width",
    "Mod Depth",
    
    "Mod Fdbk",
    "Mod Phase Offset",
    "Wet Dry",
    "Output Gain",
};

static float AC_ParameterDefaultValue [kAC_Parameter_TotalNumParameters] =
{
    0.5f,
    0.2f,
    0.6f,
    0.4f,
    
    0.25f,
    0.5,
    0.5f,
    0.5f,
};
