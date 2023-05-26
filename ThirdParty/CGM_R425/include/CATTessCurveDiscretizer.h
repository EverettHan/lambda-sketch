#ifndef CATTessCurveDiscretizer_H
#define CATTessCurveDiscretizer_H


#include "TessCacheEngine.h"

class CATCurve;
class CATCrvLimits;
class CATMathSetOfPointsND;

/**
* Interface for discretization of a CATCurve.
*/
class ExportedByTessCacheEngine CATTessCurveDiscretizer
{

public:

  virtual ~CATTessCurveDiscretizer () {}

public:

  virtual int Discretize (const CATCurve *iCurve, const CATCrvLimits &iLimits,
													CATMathSetOfPointsND * &oSetOfPoints) = 0;

};


#endif // !CATTessCurveDiscretizer_H
