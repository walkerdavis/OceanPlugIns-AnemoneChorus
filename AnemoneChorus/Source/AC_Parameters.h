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
    kAC_ParameterDelayTime,
    kAC_ParameterFeedback,
    kAC_ParameterWetDry,
    kAC_ParameterDelayType,    //delay or chorus?
    kAC_ParameterOutputGain,
    kAC_ModulationRate,
    kAC_ModulationDepth,
    kAC_ModulationPhaseOffset,
    kAC_Parameter_TotalNumParameters
};

static String AC_ParameterID [kAC_Parameter_TotalNumParameters] =
{
    "InputGain",
    "Time",
    "Feedback",
    "WetDry",
    "Type",
    "OutputGain",
    "ModulationRate",
    "ModulationDepth",
    "ModulationPhaseOffset",
};

static String AC_ParameterLabel [kAC_Parameter_TotalNumParameters] =
{
    "Input Gain",
    "Delay Time",
    "Delay Feedback",
    "Wet Dry",
    "Delay Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth",
    "Modulation Phase Offset",
};

static float AC_ParameterDefaultValue [kAC_Parameter_TotalNumParameters] =
{
    0.5f,
    0.1f,
    0.6f,
    0.5f,
    0.f,
    0.5f,
    0.3f,
    0.8,
    0.f,
};
