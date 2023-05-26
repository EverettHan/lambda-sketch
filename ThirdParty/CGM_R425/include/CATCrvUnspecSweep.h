// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATCrvUnspecSweep:
// Interface class of the SWEEP Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Generalized Sweep or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
// March 98 CPL Creation
// 12/01/99 CPL Add SetReference
// 25/09/99 CPL Add GetLocalFrame
// 09/05/00 CPL Add GetProfileParameter
// 26 10 03 MNA Ajout de SetIndexOfPackedcrvInCcvProfile (Pour le Sweep Checker)
// 01/04/05 NLD Ajout argument oUnknown à GetProfileParameter()
// 10/03/11 NLD Ajout SetSectionSolverEngine()
// 01/06/17 NLD Mise au propre
//              - smart indent
//==========================================================================
//
// Usage notes:
//
//==========================================================================

#ifndef CATCrvUnspecSweep_H
#define CATCrvUnspecSweep_H

#include "CATGeneralizedSweepSurface.h"
#include "FrFAdvancedOpeSur.h"
#include "CATMathDef.h"

#include "CreateCrvUnspecSweep.h"

//class CATBody;
class CATSurface;
class CATLaw;
class CATMathAxis;
class CATFrFCompositeCurve;
class CATGeometry;
class CATSurface;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATMathDirection;
class CATFrFProfile;
class CATFrFMovingFrame;
class CATFrFRefElement;
class CATFrFCCvParam;
class CATSectionSolverEngine;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATCrvUnspecSweep : public CATGeneralizedSweepSurface
{
  public :

  virtual ~CATCrvUnspecSweep();

  //----------------------------
  // Set the Sweep Configuration
  //----------------------------

  // Guide
  //------
  virtual void                   SetGuide                (      CATFrFCompositeCurve  *  iGuide            )       = 0;

  virtual CATFrFCompositeCurve * GetGuide                ()                                                  const = 0;

  // Profile : the profile axis move on the Guide
  //---------------------------------------------
  virtual CATFrFProfile        * GetProfile              ()                                                        = 0;

  // return profile's parameter 
  virtual double                 GetProfileParameter     (      CATBoolean             & oUnknown          )       = 0;

  // iPositionType= 1 : Sweep surface begin at the user profile
  // iPositionType= 2 : Sweep surface pass throw the user surface
  //                    (profile axis is calculated by intersection
  //                     between mean plan profile and the Guide)
  virtual void                   SetProfilePositionType  (      CATLONG32                iPositionType     )       = 0;

  virtual void                   SetIndexOfPackedcrvInCcvProfile(CATListOfInt          * iListOfPackedcrvInCcv)    = 0;

    // Constraints : Angle Law, Scaling Law
    //------------

  virtual void                   SetAngleLaw             (      CATLaw                *  iAngleLaw         ,
                                                                CATFrFRefElement      *  iReference        )       = 0;
  virtual void                   SetReference            (      CATFrFRefElement      *  iReference        )       = 0;

    // iReference have to be a surface
  virtual void                   SetReference            (      CATGeometry           *  iReference        )       = 0;

  virtual void                   SetAngleLaw             (      CATLaw                *  iAngleLaw         ,
                                                                CATGeometry           *  iReference        )       = 0;

  virtual void                   SetScalingLaw           (      CATLaw                *  iScalingLaw       )       = 0;


  virtual void                   SetSectionSolverEngine  (      CATSectionSolverEngine*  iSolver           )       = 0;

};

#endif

