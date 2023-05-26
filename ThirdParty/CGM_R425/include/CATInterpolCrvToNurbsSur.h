 // COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATInterpolCrvToNurbsSur:
// Interface class of the Interpolation Operator for Surfaces.
//
//==========================================================================
//
// Usage notes:
// This class is used in order to interpolate n curves 
// The result is a CATNurbsSurface with (n - 1) raw of patches.
// Its degree is equal to 3 . 
// The NurbsSurface has a global C2 continuity. 
//========================================================================== 
// Oct. 97     Creation                   DHN
//========================================================================== 

#ifndef CATInterpolCrvToNurbsSur_H
#define CATInterpolCrvToNurbsSur_H

class CATNurbsCurve;
class CATNurbsSurface;
class CATKnotVector;

#include "CreateInterpolCrvToNurbsSur.h"
#include "CATCGMVirtual.h"

#include "FrFOpeSur.h"


//-----------------------------------------------------------------------------
class ExportedByFrFOpeSur CATInterpolCrvToNurbsSur : public CATCGMVirtual
{
  public :

    virtual ~CATInterpolCrvToNurbsSur();
    virtual void Run()=0;
//
//  Setting the Points
//
    virtual void SetGlobal(const CATNurbsCurve **iCurve, const CATLONG32 &iNbCurves, 
                           CATKnotVector *iKnotVectorLongitudinal)=0;
// 
//  Getting the CATNurbsSurface result 
// 
    virtual CATNurbsSurface *GetNurbsSurface() const=0;
};

#endif
