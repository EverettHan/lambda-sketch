#ifndef CATPContactLocation_h
#define CATPContactLocation_h

#include "CATBaseUnknown.h"
#include "CATMathDef.h"

class CATMathPoint;
class CATMathPoint2D;


class CATPContactLocation : public CATBaseUnknown
 {
 public :

virtual void Set(const CATMathPoint * iP) =0;
virtual void Set(const CATMathPoint2D * iP2d) =0;


virtual void  Get(CATMathPoint2D * oP2d, CATBoolean * IsDefined) const =0;
virtual void  Get(CATMathPoint   * oP  , CATBoolean * IsDefined) const =0;
};
#endif
