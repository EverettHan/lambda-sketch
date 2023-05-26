// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFitSurToPt_TgCx2:
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// Nov. 99     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitSurToPt_Tg_H
#define CATFitSurToPt_Tg_H

#include <iostream.h>
#include "CATFitSurToPt_Tg.h"
#include "CATMathGrid.h"
#include "CATMathGridOfPoints.h"
#include "CATNurbsSurface.h"
#include "CATMathPoint.h"
#include "CATKnotVector.h"
#include "CATMathMxNBandMatrix.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATMathDef.h"
#include "FrFFitting.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------

class ExportedByFrFFitting  CATFitSurToPt_Tg : public CATCGMVirtual
{
    
public :
    
 /**
 * Constructor for surface fitting. 
 */
        
    virtual ~CATFitSurToPt_Tg() {} ;    
             
    virtual CATLONG32 Run() = 0 ;
    
    virtual void SetFactory ( CATGeoFactory * iFactory ) = 0 ; 
    
    virtual void SetNewKnotVectorU ( const CATKnotVector *iKvU, CATLONG32 *ioErrU = NULL, CATLONG32 iInitializeCU = 1 ) = 0 ; 
    
    virtual void SetNewKnotVectorV ( const CATKnotVector *iKvV, CATLONG32 *ioErrV = NULL, CATLONG32 iInitializeCV = 1 ) = 0 ; 

    virtual void SetControlPoints  ( CATMathGridOfPoints *ioCtrPt ) = 0 ;

    virtual void SetNewGridAndParams( 
              CATMathGrid          *iGridOfData,
        const CATLONG32             iCrossDerivAreIncluded,
        const CATLONG32             iNbU, 
        const CATLONG32             iNbV, 
        const double               *iParU, 
        const double               *iParV ) = 0 ;

    virtual void UpdateParamUPointer ( const double *iParU ) = 0 ;    
    virtual void UpdateParamVPointer ( const double *iParV ) = 0 ;  


    virtual void SetNewTolerances(
        const double iTolPt, 
        const double iTolNo,
        const double iMeanLnDU,
        const double iMeanLnDV ) = 0 ;

    virtual void MakeFinalSurfAnyway( const CATLONG32 yes ) = 0 ;

    virtual void SetMatrices (
        CATMathMxNBandMatrix *iMatrU,
        CATMathMxNBandMatrix *iMatrV,
        CATMathMxNBandMatrix *iSolvU,
        CATMathMxNBandMatrix *iSolvV,
        CATLONG32            *iAllocated,
        double               *iWeightU,
        double               *iWeightV,
        CATLONG32            *iFU,
        CATLONG32            *iFV ) = 0 ;
    
    virtual void GetUpdatedPointers (
        CATLONG32   *ioAllocated,
        double      *&oWeightU,
        double      *&oWeightV,
        CATLONG32   *&oFU,
        CATLONG32   *&oFV ) = 0 ; 
       
    virtual CATLONG32 KvUIsOK() = 0 ;

    virtual CATLONG32 KvVIsOK() = 0 ;

} ;

//-----------------------------------------------------------------------------
ExportedByFrFFitting
CATFitSurToPt_Tg * CreateCATFitSurToPt_Tg(CATSoftwareConfiguration * iConfig) ;

#endif




