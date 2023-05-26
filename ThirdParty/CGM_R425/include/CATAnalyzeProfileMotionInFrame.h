/*-*-c++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATAnalyzeProfileMotionInFrame :
// Evaluate and differentiate a profile position and motion in a moving frame. 
//
//=============================================================================
// Dec 02  Creation                          Daniel Johansson  
//=============================================================================

#ifndef CATAnalyzeProfileMotionInFrame_H  
#define CATAnalyzeProfileMotionInFrame_H 

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

class ExportedByFrFOpeCrv CATAnalyzeProfileMotionInFrame : public CATCGMVirtual

{
public:
    
    
/**
 *Destructor
 */    
    virtual ~CATAnalyzeProfileMotionInFrame () {} ;

/**
 * Before Initialize() 
 * If iVariablePtAtX is zero, the parameter value iFixProfileParamX is relevant.
 * (If no guideH is used iVariablePtAtH and iFixProfileParamH can be ignored.)
 */
    virtual void SetProfile (
        CATCurve      *iProfile, 
        CATMathPoint  &iProfileOrigo, 
        CATLONG32      iVariablePtAtG = 1,
        double         iFixProfileParamG = 0.0, 
        CATLONG32      iVariablePtAtH = 1,
        double         iFixProfileParamH = 0.0 ) = 0 ; 
    
/**
 * In the frame where the profile is analyzed, set three points that "fairly"
 * represent the extention of the profile. These points will then be used to
 * create a new moving frame. See "GetNewMFLocalData(...)" below.
 */
    virtual void SetNewMFOrigin(
        CATMathPoint  &iNewMFOrigo,
        CATMathPoint  &iNewMFV,
        CATMathPoint  &iNewMFW ) = 0 ;
        
    virtual void SetGuideG ( CATCurve   *iCrvGuideG ) = 0 ;

    virtual void SetGuideG ( CATPCurve  *iPCrvGuideG, CATLONG32 iG1Contact = 1 ) = 0 ;
    
    virtual void SetGuideG ( CATSurface *iSurGuideG, CATLONG32 iG1Contact = 0 ) = 0 ;
    
    virtual void SetNoGuideH() = 0 ;
    
    virtual void SetGuideH ( CATCurve   *iCrvGuideH ) = 0 ;
    
    virtual void SetGuideH ( CATPCurve  *iPCrvGuideH, CATLONG32 iG1Contact = 1 ) = 0 ;

    virtual void SetGuideH ( CATSurface *iSurGuideH, CATLONG32 iG1Contact = 0 ) = 0 ; 
    
/**
 * Number of equation rows:
 * Each given guide adds three equations. Each G1Contact adds one equation.
 * Thus, possible numbers of equations are 3, 4, 6, 7 and 8.
 *
 * Number of equation variables:
 * Each guide adds one variable for iVariablePtAtX = 1. If the guide is a
 * curve or a surf one or two oter variable are added. So far we have 1 to 6
 * numbers of variables. To make sense the number of variables, so far, is 
 * less than the number of equations. 
 * 
 * Now, we add 1 2 or three variables by iNbInternTransl and iInternRotation.
 * if the numbers of variables and numbers of equations not become the same,
 * a zero is returned and the object is useles.
 *
 * Particularly, if ONE internal translation is used in combination with rotation,
 * EITHER the translation vector must also rotate (case 1), OR the rotation centre
 * must follow the translation of the profile (default).
 */
    virtual CATLONG32 Initialize( CATLONG32 iNbInternTransl, CATLONG32 iInternRotation = 0, CATLONG32 iFixRotCenterInMF = 0 ) = 0 ;

/**
 * After "Initialize(...)" we may read:
 */    
    virtual CATLONG32 GetEQSize() = 0 ;

/**
 * These set method has to be used at new U value,i.e. at new instant of moving frame.
 */    
    virtual void SetInternRotationFreedom(
        CATMathPoint     *iRotCentre, 
        CATMathDirection *iRotAxis ) = 0 ;
    
    virtual void SetInternTranslationFreedom(
        CATMathDirection *iDir1, 
        CATMathDirection *iDir2 = NULL ) = 0 ;
        
    virtual void SetLocalCoord (
        CATMathPoint     *iOrigo, 
        CATMath3x3Matrix *iTransf ) = 0 ;
        
/**
 * ioPt: Remaining differences between profile and guide
 * ioDx: Suggested changes of equation variables
 * iodFdX: A copy of the internal dF/dX may be retreived.
 */
    virtual CATLONG32 GetPtAndPx(
        double           *iParamX, 
        double           *ioPt, 
        double           *ioDx,
        CATMathNxNMatrix *iodFdX = NULL ) = 0 ;
    
/**
 * When ioPt (above) is very small ---
 * Before "Get ...", set changes concerning the moving frame.  
 */
    virtual void SetLocalCoordChanges(
        CATMathVector *iDOrigoDU, 
        CATMathVector *iD2OrigoDU2, 
        CATMathVector *iTurn,
        CATMathVector *iDTurnDU ) = 0 ;

    virtual CATLONG32 GetDxDuAndD2xDu2(
        double *iParamX, 
        double *ioDxDu, 
        double *ioD2xDu2 ) = 0 ;

/**
 * Finally, new moving frame origin points are transformed and differentiated
 * See "SetNewMFOrigin(iNewMFOrigo, iNewMFV, iNewMFW)" above.
 */
    virtual void GetNewMFLocalData(
        const double  *iParamX, 
        const double  *iDxDu, 
        const double  *iD2xDu2,
        CATMathPoint  &oNewO,
        CATMathPoint  &oNewV,
        CATMathPoint  &oNewW,
        CATMathVector &oNewDODU,
        CATMathVector &oNewDVDU,
        CATMathVector &oNewDWDU,
        CATMathVector &oNewD2ODU2,
        CATMathVector &oNewD2VDU2,
        CATMathVector &oNewD2WDU2 ) = 0 ;

};

/**
 * Creator ...
 */
ExportedByFrFOpeCrv  
CATAnalyzeProfileMotionInFrame * CreateCATAnalyzeProfileMotionInFrame() ;     

#endif
