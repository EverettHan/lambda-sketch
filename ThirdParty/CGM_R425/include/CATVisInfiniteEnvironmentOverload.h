// COPYRIGHT Dassault Systemes 2007

#ifndef CATVisInfiniteEnvironmentOverload_H
#define CATVisInfiniteEnvironmentOverload_H

//-----------------------------------------------------------------------

#include "CATVizBaseIUnknown.h"
#include "SGInfra.h"
#include "list.h"

class CATVisInfiniteEnvironmentExtendedData;
class CATVisInfiniteEnvironmentStack;
class CATVisAmbiance;
class CATVisPostEffects;
class ExportedBySGInfra CATVisInfiniteEnvironmentOverload : public CATVizBaseIUnknown
{
  friend class CATVisInfiniteEnvironmentStack;

public:
  void SetModify();
  void DeActivate(int iOnOff);
  virtual bool IsActivated() const;

  void InitOverload       (const CATVisAmbiance* iAmbiance, const CATVisInfiniteEnvironmentExtendedData& iData);
  void ApplicateOverload  (CATVisInfiniteEnvironmentExtendedData& ioData) const;
  void ApplicateOverload  (CATVisAmbiance& ioData)    const;
  void ApplicateOverload  (CATVisPostEffects& ioData) const;

  enum EProperty
  {
    eExposure
  };

  virtual bool IsOverloaded(EProperty iProperty) const;

protected:
  CATVisInfiniteEnvironmentOverload();
  virtual ~CATVisInfiniteEnvironmentOverload();
  
  virtual void Init     (const CATVisAmbiance* iAmbianceData, const CATVisInfiniteEnvironmentExtendedData& iData);
  virtual void Overload (CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload (CATVisAmbiance& ioData)    const;
  virtual void Overload (CATVisPostEffects& ioData) const;

private:
  CATVisInfiniteEnvironmentOverload (CATVisInfiniteEnvironmentOverload &);
  CATVisInfiniteEnvironmentOverload& operator=(CATVisInfiniteEnvironmentOverload&);

  void Attach(CATVisInfiniteEnvironmentStack* iStack);
  void Detach(CATVisInfiniteEnvironmentStack* iStack);
  
  list<CATVisInfiniteEnvironmentStack> _stacks;

  unsigned int _deactivation;
};

//-----------------------------------------------------------------------


#endif
