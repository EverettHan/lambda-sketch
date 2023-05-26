// COPYRIGHT Dassault Systemes 2011

#ifndef CATVisInfiniteEnvBoundingBoxOverload_H
#define CATVisInfiniteEnvBoundingBoxOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATMathPointf.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvBoundingBoxOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvBoundingBoxOverload* Create(const CATMathPointf& iMinPt, const CATMathPointf& iMaxPt);

  void SetBoundingBox(const CATMathPointf& iMinPt, const CATMathPointf& iMaxPt);

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;

private:
  CATVisInfiniteEnvBoundingBoxOverload(const CATMathPointf& iMinPt, const CATMathPointf& iMaxPt);
  virtual ~CATVisInfiniteEnvBoundingBoxOverload();

  CATMathPointf _boudingBox[2];
};

//-----------------------------------------------------------------------

#endif
