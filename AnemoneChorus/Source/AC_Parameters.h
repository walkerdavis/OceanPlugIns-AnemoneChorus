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
    kAC_ParameterHold,
    kAC_ParameterRelease,
    kAC_ParameterFloor,
    kAC_ParameterRateAmount,
    kAC_ParameterDepthAmount,
    
    kAC_ParameterSoftClip,
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
    "EnvelopeHold",
    "EnvelopeRelease",
    "EnvelopeFloor",
    "EnvelopeRateAmount",
    "EnvelopeDepthAmount",
    
    "SoftClip",
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
    "Env Hold",
    "Env Rel",
    "Env Floor",
    "Env Rate Amnt",
    "Env Depth Amnt",
    
    "Soft Clip",
    "Wet Dry",
    "Output Gain",
};

static float AC_ParameterDefaultValue [kAC_Parameter_TotalNumParameters] =
{
    0.5f,
    0.1f,
    0.1f,
    
    0.1f,
    0.7f,
    0.5f,
    
    0.7f,
    0.5f,
    0.5f,
    0.7f,
    0.1f,
    0.9f,
    0.9f,
    
    0.01f,
    0.5f,
    0.5f,
};
