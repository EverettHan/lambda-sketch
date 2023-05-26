// COPYRIGHT DASSAULT SYSTEMES 1999-2015
//=============================================================================
//
// CATPlanarMatchFunctionCx2 :
// Implementation class for Planar Matching with Non Linear Optimization.
//
//=============================================================================
//
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// Sept  99 ALM Creation                                  Paul-Alexandre LOURME
// Nov   03 NDN Ajout de ExportedByFrFAdvancedOpeSur
//              et deplacement dans protected
// Avr   15 MMO Migration Xscale (small) Ajout de la configuration et de la CATTolerance
// 25/10/18 NLD Suppression des arguments par défaut pour configuration
//              et bloc de tolerances
//=============================================================================
#ifndef CATPlanarMatchFunctionCx2_H
#define CATPlanarMatchFunctionCx2_H

#include "CATMathFunctionRN.h"
#include "CATCrvEvalLocal.h"
#include "CATTolerance.h"

class CATGeoFactory;
class CATMathDirection;
class CATMathPoint;
class CATMathNurbsBipar;
class CATNurbsSurface;
class CATPLine;
class CATCrvParam;
class CATSurParam;
class CATFrFCompositeCurve;
class CATFrFCCvParam;
class CATFrFCoupling;

#include "FrFAdvancedOpeSur.h"

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATPlanarMatchFunctionCx2 : public CATMathFunctionRN
{
public :

//=================
//  M E T H O D S  
//=================
    // Constructor
    //------------
    CATPlanarMatchFunctionCx2(      CATGeoFactory            * iFactory,
                                    CATLONG32                  iDimension,
                                    CATLONG32                  iContinuity,
                                    CATMathDirection         * iDirection,
                                    CATLONG32                  iDiscretDim,
                                    CATSurParam              * iSurParam,
                                    CATMathDirection         * iRefG1Dir,
                                    CATMathDirection         * iRefG2CurDir,
                                    double                   * iRefG2Cur,
                                    CATMathNurbsBipar        * iBiPar,
                                    CATNurbsSurface          * iSurface,
                                    CATLONG32                  iCote,
                                    CATLONG32                  iDirUV,
                                    double                   * iParametrization,
                                    CATSoftwareConfiguration * iConfig    , //= 0,
                              const CATTolerance             & iTolObject );  //= CATGetDefaultTolerance() );

    // Destructor 
    //-----------
    virtual ~CATPlanarMatchFunctionCx2();

    // Evaluator  
    //----------
    virtual double Eval(const double * iX) const;

    // Duplicator
    //-----------
    virtual CATMathFunctionRN * Duplicate() const;

    // Information method
    //-------------------
    virtual CATMathClassId IsA() const;

protected:

//=================
//  M E T H O D S  
//=================
    // Evaluators
    double MonEval(const double * iX);
    // Data management
    void InitData();
    void FillData(CATGeoFactory          * iFactory,
                  CATLONG32                iContinuity,
                  CATMathDirection       * iDirection,
                  CATLONG32                iDiscretDim,
                  CATSurParam            * iSurParam,
                  CATMathDirection       * iRefG1Dir,
                  CATMathDirection       * iRefG2CurDir,
                  double                 * iRefG2Cur,
                  CATMathNurbsBipar      * iBiPar,
                  CATNurbsSurface        * iSurface,
                  CATLONG32                iCote,
                  CATLONG32                iDirUV,
                  double                 * iParametrization);
    void           ComputeData1();
    void           CleanData1();
    // Control Points management
    CATMathPoint * GetControlPoint(int iRank, int iCont);
    void           SetControlPoint(int iRank, int iCont, CATMathPoint* Pt);

//===========
//  D A T A  
//===========
    // --- Input
    CATGeoFactory          * _Factory;
    CATLONG32                _Continuity;
    CATMathDirection       * _Direction;
    CATLONG32                _DiscretDim;
    CATSurParam            * _SurParam;
    CATMathDirection       * _RefG1Dir;
    CATMathDirection       * _RefG2CurDir;
    double                 * _RefG2Cur;
    CATMathNurbsBipar      * _StockBiPar;
    CATNurbsSurface        * _Surface;
    CATLONG32                _Cote;
    CATLONG32                _DirUV;
    double                 * _Parametrization;
    // --- Local
    CATMathNurbsBipar      * _WorkingBiPar;
    CATLONG32                _NbCPU;
    CATLONG32                _NbCPV;
};

#endif


