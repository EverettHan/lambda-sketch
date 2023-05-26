// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATBasicMatchFrFBipar :
// Internal class for the Match operator
//   
//=============================================================================
//
// Usage notes : To match a FrFBipar on 1 CATFrFCombMF
//
// Specs :
//   - the FrFBipar and the FrFMultiForm must have identical knot vectors. 
//   - Side description :
//         
//                                  Side = 2                     
//                        +--------------------------+
//                        |                          |        
//                        |  A  V                    |       |
//                        |  |                       |       |
//                        |  |                       |       |
//             Side = 1   |  |       FrFBipar        |   Side = 3  
//                        |  |                       |
//                        |  |                       |       |
//                        |  |                       |       |
//                        |  +----------->   U       |       |
//                        |                          |       |
//                        +--------------------------+       |
//                                  Side = 0                     
//
// Sample of use :
//
//=============================================================================
// Aug 99  Creation                                                    ALM 
//=============================================================================
#ifndef CATBasicMatchFrFBipar_H
#define CATBasicMatchFrFBipar_H

// #define DEBUG_VISU_CATBasicMatchFrFBipar
// #define DEBUG_CATBasicMatchFrFBipar

#include "FrFOpeSur.h"
#include "CATFreeFormDef.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATFrFNurbsMultiForm;
class CATFrFNurbsBipar;
class CATKnotVector;
class CATFrFCombMF;

#ifdef DEBUG_VISU_CATBasicMatchFrFBipar
class CATCartesianPoint;
class CATLine;
#endif

#ifdef DEBUG_CATBasicMatchFrFBipar
#endif
 
//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATBasicMatchFrFBipar : public CATCGMVirtual
{
 public :

    //=============
    // Constructor 
    //=============
    CATBasicMatchFrFBipar(CATGeoFactory        * iFactory,
                          CATFrFNurbsBipar     * iBipar,
                          CATFrFCombMF         * iCombMF);
   
    //============
    // Destructor 
    //============
    virtual ~CATBasicMatchFrFBipar();

    //=====
    // Run
    //=====
    virtual void Run();

    //===============
    // Configuration
    //===============

    virtual void             SetMatchedSide           (CATLONG32 iSide);
    virtual CATLONG32        GetMatchedSide           () const;
    virtual void             SetConnectionContinuity  (CATFrFContinuity iContinuity);
    virtual CATFrFContinuity GetConnectionContinuity  () const;
    virtual void             SetOppositeSideContinuity(CATFrFContinuity iContinuity);
    virtual CATFrFContinuity GetOppositeSideContinuity() const;
    virtual void             SetDiffusion             (CATLONG32 iDiffusion);
    virtual CATLONG32        GetDiffusion             () const;
    virtual void             SetTension               (double iTension);
    virtual double           GetTension               () const;

 protected :
    //=======================
    //     D A T A 
    //=======================

    // Input
    //------
    CATGeoFactory          *  _Factory;
    CATFrFNurbsBipar       *  _BiparInit;
    CATFrFNurbsBipar       *  _BiparResult;
    CATFrFCombMF           *  _CombMF;
    CATFrFNurbsMultiForm   *  _MultiForm;
    CATLONG32                 _MFDegree;
    CATLONG32                 _BPDegree;
    CATLONG32                 _BPDegreeU;
    CATLONG32                 _BPDegreeV;
    double                    _MFDelta1;
    double                    _MFDelta2;
    double                    _BPDelta1;
    double                    _BPDelta2;
    double                    _BPDelta1U;
    double                    _BPDelta2U;
    double                    _BPDelta1V;
    double                    _BPDelta2V;
    CATLONG32                 _MFRational;
    CATLONG32                 _BPRational;

    // Configuration
    //--------------
    CATLONG32                 _Side;
    CATFrFContinuity          _ConnectionContinuity;
    CATFrFContinuity          _OppositeSideContinuity;
    CATLONG32                 _Diffusion;
    double                    _Tension;

    // Internal Data
    //--------------
    CATLONG32                 _NbCPU;
    CATLONG32                 _NbCPV;
    CATLONG32                 _NbCPLongi;
    CATLONG32                 _NbCPTrans;
    CATLONG32                 _rc;

    //=======================
    //     M E T H O D S
    //=======================
    void      CleanData();
    CATLONG32 InitData();
    void      GetControlPoint(CATLONG32 iRankX, CATLONG32 iRankY, CATMathPoint *& ioPoint);
    void      GetWeight      (CATLONG32 iRankX, CATLONG32 iRankY, double        & oWeight);
    void      SetControlPoint(CATLONG32 iRankX, CATLONG32 iRankY, CATMathPoint *  iPoint );
    void      SetWeight      (CATLONG32 iRankX, CATLONG32 iRankY, double          iWeight);

};

#endif
