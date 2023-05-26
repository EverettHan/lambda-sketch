// COPYRIGHT DASSAULT SYSTEMES 2001
//======================================================================
//
// CATConvertMultiCcvToNurbs:
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
//    01 01 CPL Creation                                             CPL
// 20 02 03 MNA Ajout des methodes relatives au Smooth
// 28 09 05 NLD Suppression (mise en commentaires) de _Invert et IsInvert() inutiles
//              Ajout de _TotalApproxTolForEachCcv
//              Possibilité de combiner SetTolerance() et SetSmoothOption()
//              Ajout de ApplyTolerance()
// 06 11 07 NLD Le constructeur recoit une CATSoftwareConfiguration
//              On rend privee SetSoftwareConfiguration()
// 12 11 09 JSX Ajout _listOfAllCCvFunc pour détruire les MathCurve parametrées en abscisses curviligne
// 17 05 10 JSX Ajout SetSideContinuity
// 13/11/14 NLD _Smooth devient _SmoothOption
// 30/06/17 NLD Le constructeur peut rendre une erreur
//======================================================================

#ifndef CATConvertMultiCcvToNurbs_H
#define CATConvertMultiCcvToNurbs_H

#include "FrFAdvancedOpeCrv.h"

#include "CATListOfCATCurves.h"
#include "CATListOfCATFrFNurbsMultiForm.h"

#include "CATGeoFactory.h"
#include "CATFrFNurbsMultiForm.h"
#include "CATFrFCCvParam.h"
#include "CATFrFCompositeCurve.h"
#include "CATMultiCurveFitting.h"
#include "CATCGMVirtual.h"

class CATSoftwareConfiguration;
class CATError;

//----------------------------------------------------------------------
class ExportedByFrFAdvancedOpeCrv CATConvertMultiCcvToNurbs: public CATCGMVirtual
{
  public :

    CATConvertMultiCcvToNurbs(CATGeoFactory           *  iFactory        ,
                              CATSoftwareConfiguration*  iConfig         ,
                              CATLONG32                  iNumberOfCcv    ,
                              CATFrFCompositeCurve   **  iCcv            ,
                              CATLONG32               *  iCcvOrientations,
                              CATLONG32                  iMasterCcvIndex ,
                              double                     iTolerance      ,
                              CATError                *& oError          );

    virtual ~CATConvertMultiCcvToNurbs();


//
//  Run methods
//
//  1. Standard run
    void Run();

//
// Returns the resulting List Of MultiForm for a given Ccv.
//
// Invert each Nurbs in Result when :
//   Ccv->GetOrientation(i) * iCcvOrientation= -1
//
#define  CATConvertMultiCcvToNurbs_ListPOfCATFrFNurbsMultiForm CATLISTP(CATFrFNurbsMultiForm)
CATConvertMultiCcvToNurbs_ListPOfCATFrFNurbsMultiForm* GetResult(int iCcvRank);

//
// ...................................................................
//  Getting a parameter on the Ccv(Nurbs) corresponding to a given
//  parameter on the Ccv to convert
// ..................................................................
//
    double ComputeNewParameter( const CATFrFCCvParam& iParamOnCcv );

//
// ...................................................................
//  Setting iRationalAllowed :
//    iRationalAllowed = 1 -> the output curve will be rational (default)
//    iRationalAllowed = 0 -> the output curve will be non rational
// ...................................................................
//
    void      SetRationalAllowed  (CATLONG32        AllowRational);

    void      SetTolerance        (double           iTolerance, int iCcvRank );
    void      SetInternalMinLength(double           InternalMinLength);
    void      SetSideContinuity   (CATFrFContinuity iCont);

    double    GetMaxDeviation();
    double    GetCcvMaxDeviation  (int              iCcvRank);

    void      SetReferenceCcv     (int              iCurveRank );

    //Methodes relatives au Smooth MNA 200203
    void      SetSmoothOption     (CATLONG32        iSmoothOption);
    CATLONG32 GetSmoothOption     ();


    /*
    CATBoolean IsInvert() const
    {return _Invert;}
    */

// The value 1 if the transformation is exact, the value 0 otherwise. 
    CATLONG32 IsExactTransformation();
private:
    void      ComputeContinuity(CATLONG32 * ioGlobalCont);

    // Applique la tolerance relative a une CCV
    void      ApplyTolerance   (int         iCcvRank) ;

    void      SetSoftwareConfiguration(CATSoftwareConfiguration* Config);

//=========================================================================
// DATA
//=========================================================================
  private :


    CATGeoFactory*                  _Factory;
    CATFrFCompositeCurve**          _Ccv;
    CATLONG32                       _NbCcv;
    CATLONG32*                      _Orientation;
    // CATBoolean                      _Invert;
    CATLONG32                       _MasterCcvIndex;

    CATLONG32                       _Size; // CCV->GetNumberOfCurves();
    CATMultiCurveFitting**          _FittingOpe;
    CATCrvLimits*                   _Limits;
    double                          _InternalMinLength;
    CATFrFContinuity                _SideContinuity;

    CATLONG32                       _SmoothOption; //default is 0 (i.e. no smoothing applied on input)
    double                          _InputTol;
    double*                         _TotalApproxTolForEachCcv ;

    CATSoftwareConfiguration*       _Config;
    
    CATLISTP(CATMathCurveFunction)  _listOfAllCCvFunc;
    // Array Offset: Crv index -> CrvRank; -1 if degenerated
    CATLONG32*                      _aOffset; 
};
#endif
