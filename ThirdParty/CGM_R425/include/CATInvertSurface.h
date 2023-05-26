#ifndef CATInvertSurface_H
#define CATInvertSurface_H 

#include "FrFOpeSur.h"
#include "CATGeoOperator.h"
#include "CreateInvertSurface.h"

class CATGeoFactory;
class CATSurface;
class CATSurLimits;
class CATMathTransformation2D;

class ExportedByFrFOpeSur CATInvertSurface : public CATGeoOperator
{
public:

  CATInvertSurface(CATGeoFactory* iFactory);
  ~CATInvertSurface();

  // can be called before run 
  // returns 0 if approx is necessary, 1 if type of surafce can be kept
  virtual CATBoolean IsInputSurfaceTypeKept()=0;

  // returns 0 if run failed (= no solution)
  virtual CATBoolean IsInvertOK()=0;

  // get result surface created After Run
  virtual CATSurface* GetInvertedSurface(CATSurLimits & oLimits, CATMathTransformation2D & oMappingUV)=0;


};

#endif

