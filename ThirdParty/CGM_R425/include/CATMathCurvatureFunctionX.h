/* -*-C++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
// CATMathCurvatureFunctionX:
//=============================================================================
//=============================================================================
//   /10/03 OAU Creation                                                AAD OAU
// 16/11/18 NLD Deplacement en ProtectedInterfaces pour utilisation externe
//              et suppression de la duplication CATMathCurvFunc1D
//              Mise au propre
// 07/09/22 Q48 Add option to compute in UV space (for pCurves)
//=============================================================================

#ifndef CATMathCurvatureFunctionX_h
#define CATMathCurvatureFunctionX_h

// Base class
#include "CATMathBasisFunctionX.h"

// ExportedBy
#include "Y30UIUTI.h"

// Basic types
#include "CATBoolean.h"

// Mathematics
#include "CATTolerance.h"
class CATMathFunctionX;

// Geometric Objects
class CATCurve;
class CATPCurve;
class CATSurface;

// Versioning
class CATSoftwareConfiguration;

class ExportedByY30UIUTI CATMathCurvatureFunctionX : public CATMathBasisFunctionX
{
public:

                     CATMathCurvatureFunctionX(      CATSoftwareConfiguration *  iSoftwareConfiguration,
                                                     CATCurve                 *  iCurve                ,
                                               const CATTolerance              & iTolObject            );

                     CATMathCurvatureFunctionX(      CATSoftwareConfiguration *  iSoftwareConfiguration,
                                                     CATPCurve                *  iPCurve               ,
                                               const CATTolerance              & iTolObject            ,
                                                     short                       iOrientation          = 0);

                     CATMathCurvatureFunctionX(const CATMathCurvatureFunctionX & F                     );

                    ~CATMathCurvatureFunctionX();

  CATMathClassId     IsA                      () const;

  CATBoolean         IsAKindOf                (const CATMathClassId              iClassId              ) const;

  CATMathFunctionX * Duplicate                () const;

  double             Eval                     (const double                    & t                     ) const;

  void               UseSpaceUV               ();

private:

   void SetPCurveData(CATPCurve* iPCurve);

   double Eval3D(const double & t) const;
   double Eval2D(const double & t) const;

private:

  CATSoftwareConfiguration * _iSoftwareConfiguration;
  
  CATCurve                 * _iCurve;
  CATPCurve                * _iPCurve;
  CATSurface               * _iSurface;
  
  const short _iOrientation;
  CATBoolean  _ComputeInSpaceUV;
};
#endif
