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
    kAC_ModulationDepth,
    
    kAC_ParameterFeedback,
    kAC_ParameterFeedbackAmount,
    kAC_ModulationPhaseOffset,
    
    kAC_ParameterThreshold,
    kAC_ParameterAttack,
    kAC_ParameterRelease,
    kAC_ParameterRateAmount,
    kAC_ParameterDepthAmount,
    
    kAC_ParameterWetDry,
    kAC_ParameterOutputGain,
    
    kAC_Parameter_TotalNumParameters
};

static String AC_ParameterID [kAC_Parameter_TotalNumParameters] =
{
    "InputGain",
    "ModulationRate",
    "ModulationDepth",
    
    "Feedback",
    "EnvelopeFeedbackAmount",
    "ModulationPhaseOffset",
    
    "EnvelopeThreshold",
    "EnvelopeAttack",
    "EnvelopeRelease",
    "EnvelopeRateAmount",
    "EnvelopeDepthAmount",
    
    "WetDry",
    "OutputGain",
    
    
};

static String AC_ParameterLabel [kAC_Parameter_TotalNumParameters] =
{
    "Input Gain",
    "Mod Rate",
    "Mod Depth",
    
    "Mod Fdbk",
    "Env Fdbk Amnt",
    "Mod Phase Offset",
    
    "Env Thrshld",
    "Env Atk",
    "Env Rel",
    "Env Rate Amnt",
    "Env Depth Amnt",
    
    "Wet Dry",
    "Output Gain",
};

static float AC_ParameterDefaultValue [kAC_Parameter_TotalNumParameters] =
{
    0.5f,
    0.2f,
    0.4f,
    
    0.25f,
    0.5f,
    0.5f,
    
    0.2f,
    0.01f,
    0.3f,
    0.5f,
    0.5f,
    
    0.5f,
    0.5f,
};
