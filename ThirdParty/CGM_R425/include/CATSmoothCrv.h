// COPYRIGHT DASSAULT SYSTEMES 2002 
//=============================================================================
//
// CATSmoothCrv: .
//
//=============================================================================
//
// Usage notes:
// MMO : Je laisse l'ancienne version de CreateCATSmoothCrv() le temps de faire
// migrer 
// FreeFormOperators.tst\FrFFittingTSTSh.m\src\CATFitToPtsAndDerivTest07.cpp
//
//=============================================================================
// 29/12/03 : MMO : Versionning pour CATDistanceMinPtCrv (_Config)
// 01/01/02 : DJ  : Creation
//=============================================================================
#ifndef CATSmoothCrv_H
#define CATSmoothCrv_H "NLD230512 pour NDNCoverage021205 voila une maniere de shunter beaucoup plus fiable et elegante"
#endif

#ifndef CATSmoothCrv_H
#define CATSmoothCrv_H

#include "CATCurve.h"
#include "CATNurbsCurve.h"
#include "CATKnotVector.h"
#include "FrFFitting.h"
#include "CATGeoFactory.h"
#include "CATCGMVirtual.h"

class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------

class ExportedByFrFFitting CATSmoothCrv  : public CATCGMVirtual
 
{

public :
        
    virtual ~CATSmoothCrv () {} ;
    
/**
 * Before Run().
 */

/**
 *  If (global) parameter limits are not set, the curve max limits are used. Observe
 *  that the result curve isn't connected to any possible segments outside this
 *  interval
 */
    virtual void SetRefCurve( CATCurve * iRefCurve,
                              double     LoParam =  1.0, 
                              double     HiParam = -1.0,
                              CATLONG32       iNbGridPtsPerCpt = 6 )        = 0 ;
/**
 *  Optional method, particularly if "iRefCurve" is not a nurbs curve or if
 *  further refinement, refering to  "iRefCurve", is wanted
 *  If this and the next metod, both are intended, only the latest call will be valid. 
 */
    virtual void SetStartCurve( CATNurbsCurve * iStartCurve,
                                CATLONG32            iNbGridPtsPerCpt = 6 ) = 0 ;

/**
 *  Optional method, particularly if "iRefCurve" is not a nurbs curve or if
 *  an internal start curve is to be made using "iKvU".
 *  If this and the previous metod, both are intended, only the latest call will be valid. 
 */    
    virtual void SetStartKnotVector (const CATKnotVector * iKvU,
                                     CATLONG32                  iNbGridPtsPerCpt = 6 ) = 0 ;

// to be deleted
    virtual void SetNbGridPtOnICRV (CATLONG32 NbGridPt = 101 )              = 0 ;

    virtual void SetSmoothingCoef(double iSmoothCoefOnPoints,
                                  double iSmoothCoefOnTangents,
                                  double iSmoothCoefOnCurvatures,
                                  double iSmoothMagnitud )             = 0 ;

    virtual void SetNiceCPFactor ( double iNiceCPFactor )              = 0 ;

    virtual void SetFitStiffFactor ( double iFitStiffFactor )          = 0 ;


    
/**
 * Run() :
 */
    virtual void Run()                                                 = 0 ;
    
/**
 * After Run()
 */
    
    virtual void GetResultCrv ( CATNurbsCurve *& oCurve )              = 0 ; 

    virtual void GetMaxDev ( double & oMaxErr,
                             double & oParam )                         = 0 ;                            

};

ExportedByFrFFitting CATSmoothCrv * CreateCATSmoothCrv(CATSoftwareConfiguration * iConfig) ;

ExportedByFrFFitting CATSmoothCrv * CreateCATSmoothCrv() ; // Ancienne version a tuer 

#endif

