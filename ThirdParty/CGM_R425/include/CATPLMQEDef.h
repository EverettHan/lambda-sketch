/* -*-c++-*- */
#ifndef CATPLMQEDef_H
#define CATPLMQEDef_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMQEDef"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMQEDef
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATOmxCollecManager.h"
#include "CATOmxCollecManagers.h"
#include "CATIAdpErrorMonitor.h"
#include "CATPLMQueryEngineCB.h"

/**
*  DEPRECATED - DO NOT USE !!
*  Use CATPLMQEConstants::CATPLMLoadingState instead
*/

enum ExportedByCATPLMModelBuilder CATPLMQEState { Undefined, Light, Navigation, Full };

template<> ExportedByCATPLMModelBuilder CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMQEState>::manager();

#endif
