
#ifndef CATCheckVerticesFromReference_h
#define CATCheckVerticesFromReference_h
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2019
//

#include "MathAdvMarsh.h"

#include "CATMathBox.h"
#include "CATMathPoint.h"
#include "CATMathPlane.h"

#define CATCheckVerticesFromReference_IsImplemented
    
class ExportedByMathAdvMarsh CATCheckVerticesFromReference
{
public :

  virtual  ~CATCheckVerticesFromReference();

  virtual int AddPlanReference(const CATMathPlane& iPlane)=0;

  virtual int CheckPoint(const CATMathPoint& iPoint, const bool iFilterBox = true)=0;

  virtual int GetNumberOfCheck() const = 0;

  virtual int GetNumberOfFailedCheck() const = 0;

  virtual double GetDistanceMax() const = 0;

  virtual bool  CheckOnBox(const CATMathPoint& iPoint) const = 0;

  static CATCheckVerticesFromReference* Create(const CATMathBox& iBox, const double iTolerance = -1.0);
  
protected :
  CATCheckVerticesFromReference();
  
};
#endif
