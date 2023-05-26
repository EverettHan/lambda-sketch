//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATCreateFrFNetFill :
// Declaration of global functions used to create and destroy
// an instance of the Fill sub-operator of the Net operator
// 
//=========================================================================
// Assumptions :
// both sets of curves are supposed to have been 
//      well-oriented, 
//      well-ordered,
//      extrapolated and trimmed if necessary,
//      homogenized 
//      and adapted
// during the mesh step.
//
//==========================================================================
// 24/10/05 : MMO : Je coupe l'utilisation de CATFrFNetMeshSubdivision pour le moment
// April,   2005 : ANR/FZA : Creation        (D'apres  CreateLoftFill ) 
//==========================================================================
 
#ifndef CATFrFCreateNetFill_H
#define CATFrFCreateNetFill_H 

#include "CATFrFNetSurface.h"

#include "CATFrFNetFill.h"
#include "CATSkillValue.h"
#include "CATDataType.h"
#include "CATMovingFrameType.h"
#include "CATFrFLoftWeightFunctionDef.h"
#include "CATFrFLoftMappingLawDef.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATFrFCompositeCurve;
class CATMathFunctionX;

#ifdef CATFrfUnused
class CATFrFNetMeshSubdivision; // (FZA) pour le test
#endif

class CATFrFNetMesh;


ExportedByCATFrFNetSurface
CATFrFNetFill* CATFrFCreateNetFill(CATGeoFactory              * ifactory,
                                   CATSoftwareConfiguration   * iconfig,
                                   CATLONG32                         inbOfGuides,
                                   CATFrFCompositeCurve      ** iguideCCvs,
                                   CATLONG32                         iNumDomGuide,
                                   CATLONG32                         inbOfBases,
                                   CATFrFCompositeCurve      ** ibaseCCVs,
                                   CATLONG32                         iNumdomBase,
                                   double                     * iglobalGuideMinDistParams,
                                   double                     * iglobalBaseMinDistParams,
                                   CATMovingFrameType           iMvFOption,
                                   CATFrFLoftWeightFunctionDef* iWeightFunctionTypes,
                                   CATFrFLoftMappingLawDef      iMLOption,
                                   const CATSkillValue          iMode=BASIC);

ExportedByCATFrFNetSurface
CATFrFNetFill* CATFrFCreateNetFill(CATFrFNetMesh              * imesh,
                                   CATMovingFrameType           iMvFOption,
                                   CATFrFLoftWeightFunctionDef* iWeightFunctionTypes,
                                   CATFrFLoftMappingLawDef      iMLOption,
                                   const CATSkillValue          iMode=BASIC);

#ifdef CATFrfUnused
// Rajour (FZA) pour le test
ExportedByCATFrFNetSurface
CATFrFNetFill* CATFrFCreateNetFill(CATFrFNetMeshSubdivision     * imesh,
                                   CATMovingFrameType           iMvFOption,
                                   CATFrFLoftWeightFunctionDef* iWeightFunctionTypes,
                                   CATFrFLoftMappingLawDef      iMLOption,
                                   const CATSkillValue          iMode=BASIC);
#endif

ExportedByCATFrFNetSurface
void Remove(CATFrFNetFill *&iLoftFill);

#endif




