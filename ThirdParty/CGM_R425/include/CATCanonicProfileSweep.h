// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATCanonicProfileSweep:
// Interface class of the SWEEP Operator with CanonicProfile Profile
// ( Segment, circle, conic Sweep Operators )
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Generalized Sweep or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
//   Sep 98 CPL Creation                       Christophe Pradal -- CPL
//   Mar 99 CPL Add SetSolutionChoice
//   May 99 CPL Add GetImplicitProfileCrv
//   May 00 CPL Add Conic Case
//   Sep 00 CPL Add InterpolCase
//   Sep 03 JSX Add BlendType and Continuity Arg for SetXXXSlope
//   Jan 04 JSX Add SetNoCombDeformationOnC0Vertex for Extrapolation
// 18/01/05 NLD SetNoSpineBlend()
// 14/06/05 NLD GetImplicitGuideCcv()
// 01 12 05 JSX Add SetDevelopOption
// 06 09 07 JSX Ajout de SetMappingLaw
// 06/05/14 NLD Ajout de SetRidgeOption()
// 19/11/14 NLD Smart indent
// 02/06/17 NLD Ajout SetRadiusLaw2()
// 08/06/17 NLD Ajout SetRoadWidthOption()
// 19/12/19 NLD Ajout SetPyramidOption()
//==========================================================================
//
// Usage notes:
//
//==========================================================================

#ifndef CATCanonicProfileSweep_H
#define CATCanonicProfileSweep_H

#include "CATGeneralizedSweepSurface.h"
#include "FrFAdvancedOpeSur.h"
#include "CATMathDef.h"
#include "CATFreeFormDef.h"

#include "CreateCanonicProfileSweep.h"
#include <CATListOfCATGeometries.h>
#include "CATLISTV_CATMathPoint.h"

class CATSurface;
class CATLaw;
class CATMathAxis;
class CATFrFCompositeCurve;
class CATGeometry;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATMathDirection;
class CATFrFProfile;
class CATFrFMovingFrame;
class CATFrFRefElement;

//-----------------------------------------------------------------------------

class ExportedByFrFAdvancedOpeSur CATCanonicProfileSweep : public CATGeneralizedSweepSurface
{
  public :

    virtual                                ~CATCanonicProfileSweep();


    /////////////////////////////////////////////////////////////////////////
    enum CATCanonicProfileSweepType 
      {
        C_P_Sweep_Seg     = 1,     // Sweep Segment  Type = 1
        C_P_Sweep_Circle  ,        // Sweep Circle   Type = 2
        C_P_Sweep_Conic   ,        // Sweep Conic    Type = 3
        C_P_Sweep_Interpol,        // Sweep Interpol Type = 4
        C_P_Sweep_Blend            // Sweep Blend    Type = 5
      };

    /////////////////////////////////////////////////////////////////////////
    virtual       void                      SetProfileType             (      CATCanonicProfileSweepType iType                        )                    = 0;


    /////////////////////////////////////////////////////////////////////////
    // Set Geometry
    /////////////////////////////////////////////////////////////////////////

    virtual       void                      SetLimitGuides             (      CATFrFCompositeCurve   **  iGuides                      ,
                                                                              CATLONG32                  iNbGuides                    )                    = 0;
    virtual       void                      SetMiddleGuides            (      CATFrFCompositeCurve    *  iGuide                       )                    = 0;
    virtual       void                      SetFunctionalGuides        (      CATFrFCompositeCurve    *  iGuide                       )                    = 0;

    virtual       void                      SetLimitSurfaces           (      CATGeometry            **  iSurfaces                    ,
                                                                              CATLONG32                  iNbSurfaces                  )                    = 0;
    virtual       void                      SetMiddleSurfaces          (      CATGeometry             *  iSurfaces                    )                    = 0;
    virtual       void                      SetFunctionalSurfaces      (      CATGeometry             *  iSurfaces                    )                    = 0;


    /////////////////////////////////////////////////////////////////////////
    // Set Laws
    /////////////////////////////////////////////////////////////////////////

    virtual       void                      SetAngularLaws             (      CATLaw                 **  iLaws                        ,
                                                                              CATLONG32                  iNbLaws                      )                    = 0;
    virtual       void                      SetReference               (      CATFrFRefElement        *  iReference                   )                    = 0;

    // Valid only for Sweep Segment
    virtual       void                      SetLengthLaws              (      CATLaw                 **  iLaws                        ,
                                                                              CATLONG32                  iNbLaws                      )                    = 0;

    // Valid only for Sweep Circle
    virtual       void                      SetRadiusLaw               (      CATLaw                  *  iRadiusLaw                   )                    = 0;
    virtual       void                      SetRadiusLaw2              (      CATLaw                  *  iRadiusLaw2                  )                    = 0;

    // Valid only for Sweep Conic
    virtual       void                      SetRhoLaw                  (      CATLaw                  *  iRhoLaw                      )                    = 0;

    /////////////////////////////////////////////////////////////////////////
    // Methods for Conic & Circle
    /////////////////////////////////////////////////////////////////////////
    
    virtual       void                      SetFirstSlope              (      CATLaw                  *  iAngularLaw                  ,
                                                                              CATFrFCompositeCurve    *  iFunctionalGuide             = 0,
                                                                              CATFrFRefElement        *  iReference                   = 0,
                                                                              CATFrFContinuity           iContinuity                  = CATFrFTangentCont) = 0;
    virtual       void                      SetLastSlope               (      CATLaw                  *  iAngularLaw                  ,
                                                                              CATFrFCompositeCurve    *  iFunctionalGuide             = 0,
                                                                              CATFrFRefElement        *  iReference                   = 0,
                                                                              CATFrFContinuity           iContinuity                  = CATFrFTangentCont) = 0;

    /////////////////////////////////////////////////////////////////////////
    // Methods for Segment Only
    /////////////////////////////////////////////////////////////////////////

    virtual       void                      SetConeOption              ()                                                               = 0;
    virtual       void                      SetRidgeOption             ()                                                               = 0;
    virtual       void                      SetRoadWidthOption         ()                                                               = 0;
    virtual       void                      SetPyramidOption           ()                                                               = 0;

    virtual       void                      SetLimitingElements        (const CATLISTP(CATGeometry)    & iRelimitingPlane             )                    = 0;

    /////////////////////////////////////////////////////////////////////////
    // Methods for Blend Only
    /////////////////////////////////////////////////////////////////////////
    // blend with no spine, computed with imposed point coupling
    virtual       void                      SetNoSpineBlend            (      int                        iOption                      = 1)                 = 0 ;

    virtual       void                      SetDirectionOnRefElements  (      CATLONG32                  FirstLast                    ,
                                                                        const CATListValCATMathPoint   & LPoint                       ,
                                                                        const CATListValCATMathPoint   & LDir                         ,
                                                                        const CATListOfInt             & LKind                        )                    = 0;

    /////////////////////////////////////////////////////////////////////////
    // Validate return 0 if the case is not implemented
    //                    or if datas are not valid
    //          else return the Case Number
    /////////////////////////////////////////////////////////////////////////
    virtual       CATLONG32                 ValidateCaseNumber         (      CATLONG32                  iCase                        = 0)                 = 0;

    /////////////////////////////////////////////////////////////////////////
    virtual       void                      SetNoCombDeformationOnC0Vertex()                                                                               = 0;
    /////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////
    // Reset Data
    //   Object= 0: Reset Laws
    //   Object= 1: Reset Geometry
    /////////////////////////////////////////////////////////////////////////
    virtual       void                      Reset                      (      CATLONG32                  iObject                      = 0)                 = 0;

    /////////////////////////////////////////////////////////////////////////
    // Choose Solution
    //   Sol= 1, 2, 3, 4
    /////////////////////////////////////////////////////////////////////////
    virtual       void                      SetSolutionChoice          (      CATLONG32                  iSol                         )                    = 0;

    // Do not Delete
    virtual       CATCurve                * GetImplicitProfileCrv      ()                                                                                  = 0;
    // Implicit guide ccv computation in case of degenerated edges in all guides
    // implemented in blend case only
    virtual       CATFrFCompositeCurve    * GetImplicitGuideCcv        ()                                                                                  = 0 ;

    // Activate the develop mode : Only for Blend without guide
    virtual       void                      SetDevelopOption           (      CATBoolean                 iSet                         ,
                                                                              double                     iClearance                   )                    = 0;

    // Specfiy the mappingLaw
    virtual       void                      SetMappingLaw              (      CATLaw                 **  iMappingLaw                  )                    = 0;

};

#endif


