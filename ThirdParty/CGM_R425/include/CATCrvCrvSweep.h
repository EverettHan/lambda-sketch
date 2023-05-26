// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATCrvCrvSweep:
// Interface class of the SWEEP Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Generalized Sweep or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
// June  98 CPL Creation                                            Pradadou
// Feb   99 CPL Modification: Add SetTangency
// Jul   99 CPL Modification: Add SetSectionSolverEngine
// Oct   99 CPL Modification: Add SetRelimitationMode
// Feb   00 CPL Add GetImplicitProfileCcv
// Oct   00 CPL GetProfileParameter
// Oct   00 CPL SetReference
// Feb   01 CPL SetFunctionalGuide + OriginGuide
// Apr   01 CPL SetMultiFitting
// Nov   01 CPL SetMeshTolerance
// Apr   04 JSX SetAreaLaw
// 02/07/04 NLD Ajout de oFinalProfileArea à GetProfileParameter()
// 28/01/10 JSX Ajout iCaseForCurvature a SetTangency
// 11/05/10 JSX Ajout iContinuity a SetTangencyOnGuide (Pour le G2)
// 28/09/10 JSX Changement de nom  SetTangencyOnGuide=>SetContinuityOnGuide 
//                             et  SetTangency       =>SetContinuityOnProfile
// 09/12/21 NLD Mise au propre / smart indent
//==========================================================================
//
// Usage notes:
//
//==========================================================================

#ifndef CATCrvCrvSweep_H
#define CATCrvCrvSweep_H

#include "CATGeneralizedSweepSurface.h"
#include "FrFAdvancedOpeSur.h"
#include "CATMathDef.h"
#include "CATFreeFormDef.h"

#include "CreateCrvCrvSweep.h"

class CATMathAxis;
class CATMathTransformation;
class CATMathDirection;
class CATMathPlane;
class CATSurface;
class CATLaw;
class CATGeometry;
class CATCurve;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATFrFProfile;
class CATFrFMovingFrame;
class CATSectionSolverEngine;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATCrvCrvSweep : public CATGeneralizedSweepSurface
{
  public :

    virtual ~CATCrvCrvSweep();

    // (iCase == 0) => No tangency
    // (iCase == 1) => Tangency on only  First Profile
    // (iCase == 2) => Tangency on only  Last Profile
    // (iCase == 3) => Tangency on First & Last Profile
    // When iTangent == NULL, Profile have to be a "Wire Pose Sur"
    // iCaseForCurvature : Same as iCase but for Curvature Continuity
    //                     not used if iCase not set
    virtual       void                      SetContinuityOnProfile     (      CATLONG32                  iCase                        = 0,
                                                                              CATLONG32                  iCaseForCurvature            = 0,
                                                                        const CATMathPlane            *  iTangent                     = 0) = 0;

    virtual       void                      SetContinuityOnGuide       (      CATLONG32                  iGuideIndex                  ,
                                                                              CATFrFContinuity           iContinuity                  ,
                                                                        const CATMathPlane            *  iTangent                     = 0) = 0;

    virtual       void                      SetSectionSolverEngine     (      CATSectionSolverEngine  *  iSolver                      )    = 0;

    // (iRelimitationType == 0) => Off
    // (iRelimitationType == 1) => On First Profile
    // (iRelimitationType == 2) => On Last Profile
    // (iRelimitationType == 3) => On First and Last Profiles
    virtual       void                      SetRelimitationMode        (      int                        iRelimitationType            )    = 0;

    // Do not Delete
    virtual       CATFrFCompositeCurve    * GetImplicitProfileCcv      ()                                                                  = 0;

    virtual       double                    GetProfileParameter        (      CATLONG32                  iIndexProfile                ,
                                                                              double                  *  oInitialProfileArea          = 0,
                                                                              double                  *  oFinalProfileArea            = 0) = 0;
    // Area of the profile before and after AreaLaw application, in a given parameter
    // works only if SetAreaLaw has been called, even with a null law
    virtual       void                      GetProfileArea             (      double                     iProfileParameter            ,
                                                                              double                   & oInitialArea                 ,
                                                                              double                   & oFinalArea                   )    = 0;

    // Indique la normale du repere local
    // La master guide etant posee sur un shell...
    virtual       void                      SetReference               ()                                                                  = 0;

    virtual       void                      SetOriginGuide             (      CATFrFCompositeCurve    *  iGuide                       )    = 0;
    virtual       void                      SetFunctionalGuides        (      CATFrFCompositeCurve   **  iGuides                      ,
                                                                              CATLONG32                  iNbGuides                    )    = 0;
    virtual       void                      SetMultiFitting            ()                                                                  = 0;

    // Max Size of holes between guides and profils
    virtual       void                      SetMeshTolerance           (      double                     iTol                         )    = 0;

    virtual       void                      SetAreaLaw                 (      CATLaw                  *  iAeraLaw                     )    = 0;

  };

#endif

