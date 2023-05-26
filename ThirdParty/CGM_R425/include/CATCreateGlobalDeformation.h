// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATCreateGlobalDeformation :
// Declaration of global functions used to create and destroy
// an instance of the Global Deformation  operator
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// July. 97  Creation                          Daniel Roudil
//=============================================================================
#ifndef CATCreateGlobalDeformation_H 
#define CATCreateGlobalDeformation_H 

#include "FrFOpeSur.h"
#include "CATGeometry.h"
#include "CATSkillValue.h"

class CATGeoFactory;
class CATNurbsSurface;
class CATNurbsCurve;
class CATGlobalDeformation;
class CATMathAxis;

//-----------------------------------------------------------------------------
//Cartesian deformation: StartAxis and TargetAxis define a linear transformation
//-----------------------------------------------------------------------------

ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,  
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATGeometry     **iGeometricElementsToMove,
                                                          CATSkillValue     iMode = BASIC);


//-----------------------------------------------------------------------------
//Cartesian deformation with adjustment surface(s) . The linear transformation
//first define by  StartAxis and TargetAxis is modified by guiding constraints.  
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,  
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATGeometry     **iGeometricElementsToMove,
                                                          CATSkillValue     iMode = BASIC);
//-----------------------------------------------------------------------------
//Cartesian deformation with adjustment surface(s) . The linear transformation
//first define by  StartAxis and TargetAxis is modified by guiding constraints.  
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATGeometry     **iGeometricElementsToMove,
                                                 const    CATLONG32         iConstraintOnGuide,
                                                          CATSkillValue     iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32         iNbOfGeometricElementsToDeform,
                                                          CATGeometry     **iGeometricElementsToDeform,
                                                          CATSkillValue     iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATGeometry     **iGeometricElementsToDeform,
                                                          CATSkillValue     iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface  **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATGeometry      **iGeometricElementsToDeform,
                                                 const    CATLONG32          iConstraintOnGuide,
                                                          CATSkillValue      iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsCurve     *iStartParametrisationSpineCurve,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsCurve     *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATGeometry      **iGeometricElementsToDeform,
                                                          CATSkillValue      iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface  with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsCurve     *iStartParametrisationSpineCurve, 
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsCurve     *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface  **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATGeometry      **iGeometricElementsToDeform,
                                                          CATSkillValue      iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface  with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsCurve     *iStartParametrisationSpineCurve, 
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsCurve     *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface  **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATGeometry      **iGeometricElementsToDeform,
                                                 const    CATLONG32          iConstraintOnGuide,
                                                          CATSkillValue      iMode = BASIC);


//-----------------------------------------------------------------------------
// Curve Wrap   
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory    *iFactory,
                                                  CATNurbsCurve    *iStartParametrisationSpine,
                                                  CATNurbsCurve    *iStartProjDirectionCrv,
                                            const CATLONG32         iNbOfReferenceCrv,
                                                  CATNurbsCurve   **iStartReferenceCrv,
                                                  CATNurbsCurve    *iTargetParametrisationSpine,
                                                  CATNurbsCurve    *iTargetProjDirectionCrv,
                                                  CATNurbsCurve   **iTargetReferenceCrv,
                                            const CATLONG32         iNbOfGeometricObjectsToDeform,
                                                  CATGeometry     **iGeometricObjectsToDeform,
                                                  CATSkillValue     iMode ) ;


//-----------------------------------------------------------------------------
// Curve Wrap  with Guids 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory    *iFactory,
                                                  CATNurbsCurve    *iStartParametrisationSpine,
                                                  CATNurbsCurve    *iStartProjDirectionCrv,
                                            const CATLONG32         iNbOfReferenceCrv,
                                                  CATNurbsCurve   **iStartReferenceCrv,
                                                  CATNurbsCurve    *iTargetParametrisationSpine,
                                                  CATNurbsCurve    *iTargetProjDirectionCrv,
                                                  CATNurbsCurve   **iTargetReferenceCrv,
                                            const CATLONG32         iNbOfAdjustmentSurfaces,  
                                                  CATNurbsSurface **iAdjustmentSurfaces,
                                            const CATLONG32         iNbOfGeometricObjectsToDeform,  
                                                  CATGeometry     **iGeometricObjectsToDeform,
                                                  CATSkillValue     iMode ) ;


//-----------------------------------------------------------------------------
// Curve Wrap  with Guids & constraint on first guide
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory    *iFactory,
                                                  CATNurbsCurve    *iStartParametrisationSpine,
                                                  CATNurbsCurve    *iStartProjDirectionCrv,
                                            const CATLONG32         iNbOfReferenceCrv,
                                                  CATNurbsCurve   **iStartReferenceCrv,
                                                  CATNurbsCurve    *iTargetParametrisationSpine,
                                                  CATNurbsCurve    *iTargetProjDirectionCrv,
                                                  CATNurbsCurve   **iTargetReferenceCrv,
                                            const CATLONG32         iNbOfAdjustmentSurfaces,  
                                                  CATNurbsSurface **iAdjustmentSurfaces,
                                            const CATLONG32         iNbOfGeometricObjectsToDeform,  
                                                  CATGeometry     **iGeometricObjectsToDeform,
                                            const CATLONG32         iConstraintOnGuide,
                                                  CATSkillValue     iMode ) ;








//****************Temporary solution to handle the fact that **CATNurbsSurface
//is not recognised as **GATGeometry: *****************************************
//-----------------------------------------------------------------------------
//Cartesian deformation: StartAxis and TargetAxis define a linear transformation
//-----------------------------------------------------------------------------

ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,  
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATNurbsSurface **iGeometricElementsToMove,
                                                          CATSkillValue     iMode = BASIC);


//-----------------------------------------------------------------------------
//Cartesian deformation with adjustment surface(s) . The linear transformation
//first define by  StartAxis and TargetAxis is modified by guiding constraints.  
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATNurbsSurface **iGeometricElementsToMove,
                                                          CATSkillValue     iMode = BASIC);
//-----------------------------------------------------------------------------
//Cartesian deformation with adjustment surface(s) . The linear transformation
//first define by  StartAxis and TargetAxis is modified by guiding constraints.  
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATMathAxis      *iStartAxis,  
                                                          CATMathAxis      *iTargetAxis,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToMove,
                                                          CATNurbsSurface **iGeometricElementsToMove,
                                                 const    CATLONG32         iConstraintOnGuide,
                                                          CATSkillValue     iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface  **iGeometricElementsToDeform,
                                                          CATSkillValue      iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface  **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface  **iGeometricElementsToDeform,
                                                          CATSkillValue      iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by two parametric surfaces with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGuidingSurfaces,
                                                          CATNurbsSurface  **iGuidingSurfaces,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface  **iGeometricElementsToDeform,
                                                 const    CATLONG32          iConstraintOnGuide,
                                                          CATSkillValue      iMode = BASIC);
//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory     *ifactory,
                                                          CATNurbsCurve     *iStartParametrisationSpineCurve,
                                                          CATNurbsSurface   *iStartParametrisationSurface,
                                                          CATNurbsCurve     *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface   *iTargetParametrisationSurface,
                                                 const    CATLONG32          iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface  **iGeometricElementsToDeform,
                                                          CATSkillValue      iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface  with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATNurbsCurve    *iStartParametrisationSpineCurve, 
                                                          CATNurbsSurface  *iStartParametrisationSurface,
                                                          CATNurbsCurve    *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface  *iTargetParametrisationSurface,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface **iGeometricElementsToDeform,
                                                          CATSkillValue     iMode = BASIC);

//-----------------------------------------------------------------------------
//Deformation defined by curve and  surface  with Guiding  surfaces 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation        * CATCreateGlobalDeformation (CATGeoFactory    *ifactory,
                                                          CATNurbsCurve    *iStartParametrisationSpineCurve, 
                                                          CATNurbsSurface  *iStartParametrisationSurface,
                                                          CATNurbsCurve    *iTargetParametrisationSpineCurve,
                                                          CATNurbsSurface  *iTargetParametrisationSurface,
                                                 const    CATLONG32         iNbOfGuidingSurfaces,
                                                          CATNurbsSurface **iGuidingSurfaces,
                                                 const    CATLONG32         iNbOfGeometricElementsToDeform,
                                                          CATNurbsSurface **iGeometricElementsToDeform,
                                                 const    CATLONG32         iConstraintOnGuide,
                                                          CATSkillValue     iMode = BASIC);

//-----------------------------------------------------------------------------
// Curve Wrap   
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory    *iFactory,
                                                  CATNurbsCurve    *iStartParametrisationSpine,
                                                  CATNurbsCurve    *iStartProjDirectionCrv,
                                             const CATLONG32        iNbOfReferenceCrv,
                                                  CATNurbsCurve   **iStartReferenceCrv,
                                                  CATNurbsCurve    *iTargetParametrisationSpine,
                                                  CATNurbsCurve    *iTargetProjDirectionCrv,
                                                  CATNurbsCurve   **iTargetReferenceCrv,
                                             const CATLONG32        iNbOfGeometricObjectsToDeform,
                                                  CATNurbsSurface **iGeometricObjectsToDeform,
                                                  CATSkillValue     iMode ) ;


//-----------------------------------------------------------------------------
// Curve Wrap  with Guids 
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory    *iFactory,
                                                  CATNurbsCurve    *iStartParametrisationSpine,
                                                  CATNurbsCurve    *iStartProjDirectionCrv,
                                            const CATLONG32         iNbOfReferenceCrv,
                                                  CATNurbsCurve   **iStartReferenceCrv,
                                                  CATNurbsCurve    *iTargetParametrisationSpine,
                                                  CATNurbsCurve    *iTargetProjDirectionCrv,
                                                  CATNurbsCurve   **iTargetReferenceCrv,
                                            const CATLONG32         iNbOfAdjustmentSurfaces,  
                                                  CATNurbsSurface **iAdjustmentSurfaces,
                                            const CATLONG32         iNbOfGeometricObjectsToDeform,  
                                                  CATNurbsSurface **iGeometricObjectsToDeform,
                                                  CATSkillValue     iMode ) ;


//-----------------------------------------------------------------------------
// Curve Wrap  with Guids & constraint on first guide
//-----------------------------------------------------------------------------
ExportedByFrFOpeSur
CATGlobalDeformation * CATCreateGlobalDeformation(CATGeoFactory   *iFactory,
                                                 CATNurbsCurve    *iStartParametrisationSpine,
                                                 CATNurbsCurve    *iStartProjDirectionCrv,
                                           const CATLONG32         iNbOfReferenceCrv,
                                                 CATNurbsCurve   **iStartReferenceCrv,
                                                 CATNurbsCurve    *iTargetParametrisationSpine,
                                                 CATNurbsCurve    *iTargetProjDirectionCrv,
                                                 CATNurbsCurve   **iTargetReferenceCrv,
                                           const CATLONG32         iNbOfAdjustmentSurfaces,  
                                                 CATNurbsSurface **iAdjustmentSurfaces,
                                           const CATLONG32         iNbOfGeometricObjectsToDeform,  
                                                 CATNurbsSurface **iGeometricObjectsToDeform,
                                           const CATLONG32         iConstraintOnGuide,
                                                 CATSkillValue     iMode ) ;





#endif


