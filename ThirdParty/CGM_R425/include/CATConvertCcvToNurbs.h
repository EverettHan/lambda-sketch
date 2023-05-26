// COPYRIGHT DASSAULT SYSTEMES 1998
//======================================================================
//
// CATConvertCcvToNurbs:
// conversion d une CATCompositeCurve en :
//     * NurbsMultiForm
//     * Liste NurbsMultiForm
//     * Ccv contenant des Nurbs Crv
//======================================================================
//
// La Methode Invert (ou SetCcvOrientation) inverse les
//   Nurbs en fonction du sens de la Ccv et des orientations de chacun
//   de ces elements.
//   En sortie, L'orientation de chaque element est +1
//
//======================================================================
// Juil  98 PRG Creation                                             PRG
// Dec   98 CPL Add functions
// Novem 99 DHN Vecteurs nodaux de reference
// 11/05/10 JSX Add SetSideContinuity
//======================================================================
#ifndef CATConvertCcvToNurbs_H
#define CATConvertCcvToNurbs_H

#include "FrFAdvancedOpeCrv.h"

#include "CATListOfCATCurves.h"
#include "CATListOfCATFrFNurbsMultiForm.h"

#include "CATGeoFactory.h"
#include "CATFrFNurbsMultiForm.h"
#include "CATFrFCCvParam.h"
#include "CATFrFCompositeCurve.h"
#include "CATConvertCrvToNurbsCrv.h"
#include "CATCrvFittingToNurbsCrv.h"
#include "CATCGMVirtual.h"

//----------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATConvertCcvToNurbs : public CATCGMVirtual
{
  public :

    CATConvertCcvToNurbs(CATGeoFactory       * iFactory,
                         CATFrFCompositeCurve* iCcv    );
    CATConvertCcvToNurbs(CATConvertCcvToNurbs& iToCopy);

    virtual ~CATConvertCcvToNurbs();

//
//  Run methods
//
//  1. Standard run
    void Run();

//  2. Run with the same parametrisation (if possible) for the curve to convert
//     and the resulting NURBS. The integer returned is 0 if the parametrisa-
//     tion is not kept, 1 if it is.
    int RunWithSameParametrisation();

//
//  Setting the output dimension
//  if 1 -> the result will be one CATFrFNurbsMultiForm
//          (Be carefull, Ccv have to be C2)
//  if 3 -> the result will be a Ccv (each curve being a CATNurbsCurve)
//          In this case, the result is accessible through GetCcvNurbs
//  (if -3 -> 3D CATListOfCATFrFNurbsMultiForm)
//
//  IMPORTANT : default Output Dimension is 3
//
    void SetOutputDimension(const CATLONG32 &iOutputDim);


//
// ............................................
//  --> Nurbs Results (PNurbs or Nurbs Curve)
// ............................................
//
//  Getting the Ccv(Nurbs) result
    CATFrFCompositeCurve* GetCcvNurbs();

//
// ............................................
//  --> MultiForm Results (2D or 3D MultiForm)
// ............................................
//
//  Getting the CATFrFNurbsMultiForm result
//
    CATFrFNurbsMultiForm* GetNurbsMultiForm() const;
//
//  Getting the list of CATFrFNurbsMultiForm result
//
    CATLISTP(CATFrFNurbsMultiForm)* GetListOfNurbsMultiForm();

//
// ...................................................................
//  Getting a parameter on the Ccv(Nurbs) corresponding to a given
//  parameter on the Ccv to convert
// ..................................................................
//
    void ComputeNewParameter(const CATFrFCCvParam& iParamOnCcv,
                             CATFrFCCvParam&       oParamOnCcvNurbs);

//
// ...................................................................
//  Impose a parametrisation and a segmentation (force fitting case)
// ..................................................................
//
    void ImposeReferenceKnotVectors(const CATKnotVector **iKnotVectors);

// ...................................................................
//  Forbidding periodic results (periodic nurbs)
//  (The default mode is "Periodicity allowed")
// ..................................................................
//
    void ForbidPeriodicity();

//
// ...................................................................
// Invert each Nurbs in Result when :
//   Ccv->GetOrientation(i) * iCcvOrientation= -1
// ..................................................................
//

    void Invert();
    void SetCcvOrientation(const CATLONG32& iCcvOrientation);

//
// ...................................................................
//  Setting iRationalAllowed :
//    iRationalAllowed = 1 -> the output curve will be rational (default)
//    iRationalAllowed = 0 -> the output curve will be non rational
// ...................................................................
//
    void SetRationalAllowed(CATLONG32 AllowRational);

    void SetMaxDeviation(double MaxDeviation);
    void SetInternalMinLength(double InternalMinLength);
    double GetMaxDeviation();

//
//  Is the transformation exact ?
//  return 1 if the transformation is exact, 0 else
//
    CATLONG32 IsExactTransformation();

    CATBoolean IsInvert() const
    {return _Invert;}

//
//  In case of fitting, impose Tangency or Curvature on extremity of original curve to be kept.
//
    void SetSideContinuity(CATFrFContinuity iSideContinuity);

//================================================================================================
// DATA
//================================================================================================
  private :

    void ComputeCcv();

    CATGeoFactory*                  _Factory;
    CATFrFCompositeCurve*           _Ccv;
    CATLONG32                       _OutputDim;
    CATLONG32                       _Orientation;
    CATBoolean                      _Invert;

    CATFrFCompositeCurve*           _ResultCcv;
    CATFrFNurbsMultiForm*           _ResultMult;
    CATLISTP(CATFrFNurbsMultiForm)* _ListOfResultMult;

    CATLONG32                       _Size;
//    CATConvertCrvToNurbsCrv**       _ConvertOpe;
    CATCrvFittingToNurbsCrv**       _FittingOpe;

    CATCurve**                      _NurbsTmp;
    CATCurve**                      _DuplicateCrv;
    double                          _InternalMinLength;
    CATFrFContinuity                _SideContinuity;
};
#endif
