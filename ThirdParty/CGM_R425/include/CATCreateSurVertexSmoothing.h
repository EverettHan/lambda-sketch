// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreateSurVertexSmoothing :
// Declaration of global functions used to create and destroy
// an instance of the Vertex Smoothing operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
//   /01/98 NDN Creation
// 11/03/15 NLD Detabulation
//              Smart indent
//              Reception de la configuration
// 13/03/15 NLD XScaleRules
//=============================================================================
#ifndef CATCreateSurVertexSmoothing_H 
#define CATCreateSurVertexSmoothing_H 
//
#include "FrFOpeSur.h"
#include "CATSkillValue.h"
#include "CATMathMxNFullMatrix.h"
//
class CATNurbsSurface;
class CATSurVertexSmoothing;
class CATSoftwareConfiguration;
//
//                        (XScaleRules) iSmooth must be independent from factory scale. NLD130315
//                        see CATSurVertexSmoothing class definition for iTargetPoints  NLD031116
ExportedByFrFOpeSur
CATSurVertexSmoothing * CATCreateSurVertexSmoothing  (CATSoftwareConfiguration* iSoftwareConfiguration,
                                                      CATNurbsSurface         * iNurbsSurface         ,
                                                      double                    iSmooth               ,
                                                      CATLONG32                 iBorderU1             ,
                                                      CATLONG32                 iBorderU2             ,
                                                      CATLONG32                 iBorderV1             ,
                                                      CATLONG32                 iBorderV2             ,
                                                      CATMathMxNFullMatrix    * iTargetPoints         ,
                                                      CATSkillValue             iMode                 = BASIC);

#endif


