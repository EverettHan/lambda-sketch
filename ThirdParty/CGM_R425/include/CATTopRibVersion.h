/* -*-C++-*- */
#ifndef CATTopRibVersion_H
#define CATTopRibVersion_H

// COPYRIGHT DASSAULT SYSTEMES  2001

//----------------------------------------------------------------------
//- Software Modifications for Rib-based operators
//----------------------------------------------------------------------
// Dec. 2001    Creation                         Joran Maille
// 02/02/09 NLD Ajout GetControlledConfiguration_R19SP4Deployment()
//----------------------------------------------------------------------
#include "RibbonLight.h"
#include "CATCGMModif.h"
#include "CATTopRibDef.h"

class CATSoftwareConfiguration;

// FBZ  - Activation de detection de nouveaux vertex d'extrapolation pour
//        la relimitation  - Objectif = V5R8GA
#define CATTopRibRelimExtrapolationVertex 32000

//------------------------------------------------------------------------------
// Teste si un flag de versionning est actif
//------------------------------------------------------------------------------
/**
 * @nodoc
 */	
ExportedByRibbonLight CATBoolean CATTopCheckRibVersion(int                       iFlag,
                                                  CATSoftwareConfiguration *iConfig,
                                                  char                     *iModifId);

//------------------------------------------------------------------------------
// Rend la configuration recue, a partir de R19SP4
//------------------------------------------------------------------------------
/**
 * @nodoc
 */	
ExportedByRibbonLight CATSoftwareConfiguration* GetControlledConfiguration_R19SP4Deployment(CATSoftwareConfiguration* iControllingConfig) ;

#endif
