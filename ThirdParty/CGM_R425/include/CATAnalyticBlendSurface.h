// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATAnalyticBlendSurface:
// Interface class of the Analytic Blend Surface Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Blend or derived
// in order to implement specific algorithm or capabilities.
//
//========================================================================== 
// May. 97     Creation                       Tuan Phung
//========================================================================== 

#ifndef CATAnalyticBlendSurface_H
#define CATAnalyticBlendSurface_H

#include "CATBlendSurface.h"
#include "CATBlendValue.h"

class CATCurve;
class CATCrvLimits;

#include "CreateAnalyticBlendSurface.h"

//-----------------------------------------------------------------------------
class CATAnalyticBlendSurface : public CATBlendSurface
  {
  public :
    
    virtual ~CATAnalyticBlendSurface();
    //
    //  Setting the blend limit curves 
    //
    virtual void SetCurve(const CATLONG32 iSide, const CATCurve *iCurve)=0;
    virtual void SetCurveLimits(const CATLONG32 iSide, const CATCrvLimits &iCrvLimits)=0;
    //
    //  Setting the analytic blend parameters 
    // 
    virtual void SetTangencyContinuityMode(const CATBlendTgContMode blendtgcontmode)=0;
    //
    //  Setting the Support Trimming Mode 
    //
    //  iMode = 0 : Off 
    //  iMode = 1 : On
    //  
    virtual void SetSupportTrimmingMode(const CATLONG32 iMode)=0;
    //
    //  Get Trimmed Support 
    // 
    virtual CATSurface *GetFirstTrimmedSurface() const=0;
    virtual CATSurface *GetSecondTrimmedSurface() const=0;
  };

#endif
