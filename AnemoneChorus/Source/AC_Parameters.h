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
    
    kAC_ModulationRate = 0,
    kAC_ModulationDepth,
    kAC_ParameterFeedback,
    
    kAC_ModulationPhaseOffset,
    kAC_ParameterRateAmount,
    kAC_ParameterDepthAmount,
    kAC_ParameterFeedbackAmount,
    
    
    kAC_ParameterThreshold,
    kAC_ParameterAttack,
    kAC_ParameterHold,
    kAC_ParameterRelease,
    
    kAC_ParameterFloor,
    kAC_ParameterInputGain,
    kAC_ParameterSoftClip,
    kAC_ParameterWetDry,
    kAC_ParameterOutputGain,
    
    kAC_Parameter_TotalNumParameters
};

static String AC_ParameterID [kAC_Parameter_TotalNumParameters] =
{
    
    "ModulationRate",
    "ModulationDepth",
    "Feedback",
    
    "ModulationPhaseOffset",
    "EnvelopeRateAmount",
    "EnvelopeDepthAmount",
    "EnvelopeFeedbackAmount",
    
    
    "EnvelopeThreshold",
    "EnvelopeAttack",
    "EnvelopeHold",
    "EnvelopeRelease",
    
    "EnvelopeFloor",
    "EnvelopeGain",
    "SoftClip",
    "WetDry",
    "OutputGain",
    
    
};

static String AC_ParameterLabel [kAC_Parameter_TotalNumParameters] =
{
    
    "Rate",
    "Depth",
    "Fdbk",
    
    "Phase Offset",
    "Env Rate Amnt",
    "Env Depth Amnt",
    "Env Fdbk Amnt",
    
    
    "Env Thrshld",
    "Env Atk",
    "Env Hold",
    "Env Rel",
    
    "Env Floor",
    "Env Gain",
    "Soft Clip",
    "Wet Dry",
    "Output Gain",
};

static float AC_ParameterDefaultValue [kAC_Parameter_TotalNumParameters] =
{
    
    0.5f,
    0.5f,
    0.5f,
    
    0.5f,
    0.5f,
    0.5f,
    0.5f,
    
    
    0.7f,
    0.2f,
    0.3f,
    0.7f,
    
    0.1f,
    0.5f,
    0.f,
    0.5f,
    0.5f,
};
