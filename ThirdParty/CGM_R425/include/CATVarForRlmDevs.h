/* -*-C++-*- */

#ifndef CATFx_RlmDraftMergeEdges_H
#define CATFx_RlmDraftMergeEdges_H

// COPYRIGHT DASSAULT SYSTEMES 2012

//=============================================================================
//=============================================================================
//
// CATVarForRlmDevs : Gestion centralisee des activations des developpements 
//                    pour la relim
//
//=============================================================================

//=============================================================================
// Jan  2012  Creation                               P. Rossignol
//=============================================================================

#include "RibbonLight.h"
#include "CATBoolean.h"

class CATSoftwareConfiguration;

extern ExportedByRibbonLight CATBoolean CATVarRlm_MergeEdForDraft(CATSoftwareConfiguration * iConfig);

#endif

