#ifndef CATTessSurfaceDiscretizer_H
#define CATTessSurfaceDiscretizer_H


#include "TessCacheEngine.h"

class CATSurface;
class CATSurLimits;
class CATMathSetOfPointsND;

/**
* Interface for discretization of a CATSurface.
*/
class ExportedByTessCacheEngine CATTessSurfaceDiscretizer
{

public:

  virtual ~CATTessSurfaceDiscretizer () {}

public:

  virtual int Discretize (const CATSurface * iSurfaceToDiscretize, 
													const CATSurLimits & iSurLimits, 
													int iIsoparDir, // 1: IsoparU  -  2: IsoparV
													CATMathSetOfPointsND * &oWIsopar, CATMathSetOfPointsND ** &oTabIsopar) = 0;

};


#endif // !CATTessSurfaceDiscretizer_H
