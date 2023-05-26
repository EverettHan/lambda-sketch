#ifndef CATCContactLocation_h
#define CATCContactLocation_h

#include "CATMathDef.h"
#include "CATBaseUnknown.h"

class CATCrvLimits;
class CATPCurve ;
class CATCurve ;



class CATCContactLocation : public CATBaseUnknown
 {
 public :

 virtual void Set(CATPCurve * iPcurve, const CATCrvLimits * iLim) = 0;
 virtual void Set(CATCurve * iCurve,   const CATCrvLimits * iLim) = 0;

 // Selecteur le resultat peut etre nulle...
 virtual void Get(CATPCurve ** oPCurve, CATCrvLimits * oLim) const  =0;
 virtual void Get(CATCurve  ** oCurve , CATCrvLimits * oLim) const  =0;

 // To manage Contact at the bound or not.
 virtual void Set(const CATBoolean * isBound) =0;
 virtual void Get(CATBoolean * oIsBound) const=0;

 //To manage procedural Location (defined by the init Contact)
 virtual void SetProc(const CATBoolean * isProc) =0;
 virtual void IsProcedural(CATBoolean * oIsProc) const=0;
 };
#endif
