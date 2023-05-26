// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvGroundOverload_H
#define CATVisInfiniteEnvGroundOverload_H

//-----------------------------------------------------------------------

#include "SGInfra.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATMathPoint.h"
#include "CATMathDirectionf.h"
#include "CATMathVector2Df.h"

class CATSupport;

class ExportedBySGInfra CATVisInfiniteEnvGroundOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvGroundOverload* Create(CATSupport& iSupport);

  void SetOrigin    (const CATMathPoint& iOrigin);
  void SetRadius    (float iRadius);
  void Reset        (CATSupport& iSupport);

  enum EMode
  {
    eDefault,
    eFilter,
    eOverload
  };
  void SetMode (EMode iMode);
    
  inline EMode                    GetMode()       { return m_Mode; }
  inline float                    GetRadius()     { return m_Radius; }
  inline const CATMathPoint&      GetOrigin()     { return m_Origin; }
    
protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload(CATVisAmbiance& ioData) const;

private:
  CATVisInfiniteEnvGroundOverload();
  virtual ~CATVisInfiniteEnvGroundOverload();

  void _ComputeFromSupport(CATSupport& iSupport);

  CATMathPoint      m_Origin;
  float             m_Radius;
    
  EMode             m_Mode;

};

//-----------------------------------------------------------------------

#endif
