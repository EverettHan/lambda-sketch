// COPYRIGHT Dassault Systemes 2018

#ifndef CATVisInfiniteEnvBackplateOverload_H
#define CATVisInfiniteEnvBackplateOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisAmbiance.h"

class CATSupport;
class ExportedByCATVisFoundation CATVisInfiniteEnvBackplateOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvBackplateOverload* Create();
  void SetVisibleRatio(float iVisibleRatio);
  void SetAlphaBending(float iAlphaBending);
  
protected:  
  virtual void Init     (const CATVisAmbiance* iAmbianceData, const CATVisInfiniteEnvironmentExtendedData& iData);
  virtual void Overload (CATVisAmbiance& ioData) const;
  virtual void Overload (CATVisInfiniteEnvironmentExtendedData& ioData) const;
  
private:
  CATVisInfiniteEnvBackplateOverload();
  virtual ~CATVisInfiniteEnvBackplateOverload();
    
  float m_VisibleRatio;
  float m_AlphaBlending;

  bool                                  m_EnableOverload;
  CATVisAmbiance::Background            m_Bg;
  CATVisAmbiance::Background::BackPlate m_Backplate;
};

//-----------------------------------------------------------------------

#endif
