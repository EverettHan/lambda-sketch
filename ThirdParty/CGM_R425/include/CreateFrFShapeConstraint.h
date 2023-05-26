// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CreateFrFShapeConstraint :
// Declaration of global functions used to create and destroy
// an instance of the ShapeConstraint Object
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Dec   97 CPL Creation                                                    CPL
// May   98 CPL Ajout Body
// Jan   99 CPL Ajout Reference Element
// 29/05/17 NLD Mise au propre
//              Numerotation des createurs en coherence avec header
//              Renommage de iType en iAngleType dans CreateSweepConstraint_6
//              Migration dans CATFrFShapeConstraint de toutes les definitions de type
// 02/06/17 NLD CreateSweepConstraint_2 et CreateSweepConstraint_3 recoivent une deuxieme
//              loi de rayon
// 27/06/17 NLD Typage plus fort: distinction CATFrFShapeConstraint_Type/CATFrFShapeConstraint_AngleType
//              Shunt de CreateShapeConstraint_1, inutilise EN ATTENTE. voir FreeFormOperators.tst
//              Shunt de CreateShapeConstraint_3, inutilise EN ATTENTE. voir FreeFormOperators.tst
//              Shunt de CreateSweepConstraint_1, inutilise EN ATTENTE. voir FreeFormOperators.tst
//              Shunt de CreateSweepConstraint_4, inutilise EN ATTENTE. voir FreeFormOperators.tst
// 13/02/18 NLD Renommage de ContinuityMode en FrFContinuityMode
//=============================================================================
#ifndef CreateFrFShapeConstraint_H
#define CreateFrFShapeConstraint_H

// Pilotage des shunts pour elimination des createurs inutiles    NLD270617
// #define CreateFrFShapeConstraint_ShuntCreateShapeConstraint_1 "NON. utilise par FreeFormOperators.tst"
// #define CreateFrFShapeConstraint_ShuntCreateShapeConstraint_2
// #define CreateFrFShapeConstraint_ShuntCreateShapeConstraint_3 "NON. utilise par FreeFormOperators.tst"

// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_1 "NON. utilise par FreeFormOperators.tst"
// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_2
// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_3
// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_4 "NON. utilise par FreeFormOperators.tst"
// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_5
// #define CreateFrFShapeConstraint_ShuntCreateSweepConstraint_6

#include "FrFAdvancedObjects.h"
#include "CATDataType.h"
#include "CATSkillValue.h"

#include "CATFrFShapeConstraint.h"

class CATGeometry;
class CATLaw;
class CATMathVector;
class CATFrFRefElement;
//
/* voir desormais CATFrFShapeConstraint.h. NLD300517
typedef const char * CATShapeConstraintClassId;
// ContinuityMode est par ailleurs renommée FrFContinuityMode le 130218
enum ContinuityMode {FrFC0,
                     FrFG0,
                     FrFC1,
                     FrFG1,
                     FrFC2,
                     FrFG2};
*/
//
//----------------------------------------------------------------------------- CreateShapeConstraint_1
#ifndef CreateFrFShapeConstraint_ShuntCreateShapeConstraint_1
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateShapeConstraint
                     (CATGeometry               * iGeometry           ,
                      CATLaw                    * iAngularLawPhi      ,
                      CATLaw                    * iAngularLawTheta    ,
                      CATLaw                    * iRadiusLaw          ,
                      FrFContinuityMode           iContinuity         = FrFG0,
                      CATLONG32                   iCurveOrientation   = 1,
                      CATLONG32                   iSupportOrientation = 1 );
#endif
//

//----------------------------------------------------------------------------- CreateShapeConstraint_2
// Shape constraint used for Blend and Match Operators
#ifndef CreateFrFShapeConstraint_ShuntCreateShapeConstraint_2
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateShapeConstraint
                     (CATGeometry               * iGeometry           ,
                      CATLaw                    * iAngularLawPhi      ,
                      CATLaw                    * iAngularLawTheta    ,
                      CATLaw                    * iRadiusLaw          ,
                      CATLaw                    * iTensionLawDsDu     ,
                      CATLaw                    * iTensionLawD2sDu2   ,
                      FrFContinuityMode           iContinuity         ,
                      CATLONG32                   iCurveOrientation   ,
                      CATLONG32                   iSupportOrientation );
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_1
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_1
// iType==1 => surface for angle law == PCurve surface
// iType==2 => surface == iGeometry
// iType==3 => surface == plan
// iType==4 => iAngleRef is needed
// iType==5 => Body (shell)
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (CATGeometry               * iGeometry           ,
                      CATLaw                    * iAngularLawPhi      ,
                 CATFrFShapeConstraint_AngleType  iAngleType          ,
                      CATMathVector             * iAngleRef           = 0,
                      CATLaw                    * iAngularLawTheta    = 0,
                      CATLaw                    * iRadiusLaw          = 0,
                      FrFContinuityMode           iContinuity         = FrFG0,
                      CATLONG32                   iCurveOrientation   = 1,
                      CATLONG32                   iSupportOrientation = 1 );
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_5
// Shape constraint used for Crv Unspec Sweep
//             also used for Crv Crv    Sweep 9commentaire NLD270617)
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_5
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (CATFrFRefElement          * iReference          ,
                      CATLaw                    * iAngularLawPhi      ,
                      CATLaw                    * iAngularLawTheta    = 0,
                      CATLaw                    * iRadiusLaw          = 0,
                      FrFContinuityMode           iContinuity         = FrFG0,
                      CATLONG32                   iCurveOrientation   = 1,
                      CATLONG32                   iSupportOrientation = 1 );
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_2
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_2
// Shape constraint used for Segment and Circle Sweep Operators
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (CATGeometry               * iGeometry           ,
                      CATLaw                    * iAngularLawPhi      = 0,
                      CATLaw                    * iAngularLawTheta    = 0,
                      CATLaw                    * iLengthLaw1         = 0,
                      CATLaw                    * iLengthLaw2         = 0,
                      CATLaw                    * iRadiusLaw1         = 0,
                      CATLaw                    * iRadiusLaw2         = 0,
                      FrFContinuityMode           iContinuity         = FrFG0);
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_3
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_3
// Shape constraint used for Segment and Circle Sweep Operators
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (CATFrFRefElement          * iReference          ,
                      CATLaw                    * iAngularLawPhi      ,
                      CATLaw                    * iAngularLawTheta    ,
                      CATLaw                    * iLengthLaw1         ,
                      CATLaw                    * iLengthLaw2         ,
                      CATLaw                    * iRadiusLaw1         ,
                      CATLaw                    * iRadiusLaw2         ,
                      FrFContinuityMode           iContinuity         = FrFG0);
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_6
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_6
// Shape constraint used for Conic Sweep Operators
// iAngleType, anciennement iType NLD300517
// iAngleType = CATFrFShapeConstraint_Type1_FunctionalGuide: fun Guide, (1)
// iAngleType = CATFrFShapeConstraint_Type2_Surface        : Surface    (2)
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (CATGeometry                    * iGeometry           ,
                      CATLaw                         * iAngularLawPhi      = 0,
                      CATLaw                         * iRhoLaw             = 0,
                      CATFrFShapeConstraint_AngleType  iAngleType          = CATFrFShapeConstraint_Type1_FunctionalGuide
                     );
#endif
//----------------------------------------------------------------------------- CreateShapeConstraint_3
#ifndef CreateFrFShapeConstraint_ShuntCreateShapeConstraint_3
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateShapeConstraint
                     (const CATFrFShapeConstraint* iToCopy);
#endif

//----------------------------------------------------------------------------- CreateSweepConstraint_4
#ifndef CreateFrFShapeConstraint_ShuntCreateSweepConstraint_4
// iToCopy must be a CATFrFSweepConstraintCx2*
ExportedByFrFAdvancedObjects
CATFrFShapeConstraint * CreateSweepConstraint
                     (const CATFrFShapeConstraint* iToCopy);
#endif

//-----------------------------------------------------------------------------
ExportedByFrFAdvancedObjects
void Remove( CATFrFShapeConstraint *&ioFrFShapeConstraint );

#endif


