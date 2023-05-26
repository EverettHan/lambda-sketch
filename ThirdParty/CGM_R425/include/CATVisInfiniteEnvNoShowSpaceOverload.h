// COPYRIGHT Dassault Systemes 2008

#ifndef CATVisInfiniteEnvNoShowSpaceOverload_H
#define CATVisInfiniteEnvNoShowSpaceOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATVisInfiniteEnvironmentOverload.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvNoShowSpaceOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvNoShowSpaceOverload* Create();

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload(CATVisAmbiance& ioData) const;

private:
  CATVisInfiniteEnvNoShowSpaceOverload();
  virtual ~CATVisInfiniteEnvNoShowSpaceOverload();
};

//-----------------------------------------------------------------------

#endif
