// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreateCrvVertexSmoothing :
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
// 17/02/15 NLD Nouvelles signatures avec iSoftwareConfiguration et sans iMode
// 13/03/15 NLD XScaleRules
// 03/11/16 NLD Documentons ENFIN cette enigmatique matrice iTargetPoints
//              (dans la classe CATCrvVertexSmoothing a laquelle je renvoie)
//=============================================================================
#ifndef CATCreateCrvVertexSmoothing_H 
#define CATCreateCrvVertexSmoothing_H 
//
#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
#include "CATMathMxNFullMatrix.h"
//
class CATNurbsCurve;
class CATPNurbs;
class CATCrvVertexSmoothing;
class CATSoftwareConfiguration;
//

//=============================================================================

//                        (XScaleRules) iSmooth must be independent from factory scale. NLD130315
//                        see CATCrvVertexSmoothing class definition for iTargetPoints  NLD031116
ExportedByFrFOpeCrv
CATCrvVertexSmoothing * CATCreateCrvVertexSmoothing  (CATSoftwareConfiguration* iSoftwareConfiguration,
                                                      CATNurbsCurve           * iNurbsCurve           ,
                                                      double                    iSmooth               ,
                                                      CATMathMxNFullMatrix    * iTargetPoints         );

//
//                        (XScaleRules) iSmooth must be independent from factory scale. NLD130315
//                        see CATCrvVertexSmoothing class definition for iTargetPoints  NLD031116
ExportedByFrFOpeCrv
CATCrvVertexSmoothing * CATCreateCrvVertexSmoothing  (CATSoftwareConfiguration* iSoftwareConfiguration,
                                                      CATPNurbs               * iPNurbs               ,
                                                      double                    iSmooth               ,
                                                      CATMathMxNFullMatrix    * iTargetPoints         );

//=============================================================================
// DEPRECATED Creation functions
//=============================================================================
// DEPRECATED non exported see above
// NLD170215 ExportedByFrFOpeCrv
CATCrvVertexSmoothing * CATCreateCrvVertexSmoothing  (CATNurbsCurve           * iNurbsCurve           ,
                                                      double                    iSmooth               ,
                                                      CATMathMxNFullMatrix    * iTargetPoints         ,
                                                      CATSkillValue             iMode                 = BASIC);
// DEPRECATED non exported see above
// NLD170215 ExportedByFrFOpeCrv
CATCrvVertexSmoothing * CATCreateCrvVertexSmoothing  (CATPNurbs               * iPNurbs               ,
                                                      double                    iSmooth               ,
                                                      CATMathMxNFullMatrix    * iTargetPoints         ,
                                                      CATSkillValue             iMode                 = BASIC);

#endif


