/*-*-c++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATAnalyzeProfileMotionAlongMF :
// Create a new moving frame  describing motion along a moving frame. 
//
//=============================================================================
// Jan 03  Creation                          Daniel Johansson  
//=============================================================================

#ifndef CATAnalyzeProfileMotionAlongMF_H  
#define CATAnalyzeProfileMotionAlongMF_H 

#include "CATInterpolate.h"
#include "CATAnalyzeProfileMotionInFrame.h"
#include "CATCurve.h"
#include "CATSurface.h"
#include "CATPCurve.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATMath3x3Matrix.h"
#include "CATMathNxNMatrix.h"
#include "FrFOpeCrv.h"
#include "CATCGMVirtual.h"

class ExportedByFrFOpeCrv CATAnalyzeProfileMotionAlongMF : public CATCGMVirtual

{
public:
        
/**
 *Destructor
 */    
    virtual ~CATAnalyzeProfileMotionAlongMF () {} ;

/**
 * Set Frame definition by a spine an a normal to a plane. V-axis will be // to plane
 */    
    virtual void SetMFFrameDefI( const CATCurve *iSpine, CATMathDirection &iPlnNormal ) = 0 ;
    
/**
 * These two will probably be different later ...
 */    
    virtual void SetMFStartParamAndInterval(
        double iStartU,
        double iLoU,
        double iHiU ) = 0 ;

    virtual void SetSlidingStartParam( double *iStartParam ) = 0 ;

/**
 * Set origin of analyzsis (where the profile is analyzed where the local motions must
 * be defined).
 */    
    virtual void SetProfileAnalysis(
        CATMathPoint     &iOrigo,
        CATMath3x3Matrix &iONSysem ) = 0 ;

/**
 * Set local motion, defined at the original location of the profile. See
 * "SetProfileAnalysis(...)" above. This must also agree with the initialization
 * data of the "iAnalyzer"
 */    
    virtual void SetInternRotationFreedom(
        CATMathPoint     *iRotCentre, 
        CATMathDirection *iRotAxis ) = 0 ;
    
    virtual void SetInternTranslationFreedom(
        CATMathDirection *iDir1, 
        CATMathDirection *iDir2 = NULL ) = 0 ;

/**
 * Run ... Returns zero if faliure.
 */
    virtual CATLONG32 Run() = 0 ;
};

/**
 * Creator.
 * *iAnalyzer must be initialized
 * *ioNewMF is to replace another moving frame 
 */
ExportedByFrFOpeCrv  
CATAnalyzeProfileMotionAlongMF * CreateCATAnalyzeProfileMotionAlongMF(CATAnalyzeProfileMotionInFrame * iAnalyzer,
                                                                      CATInterpolate                 * ioNewMF) ;     

#endif
