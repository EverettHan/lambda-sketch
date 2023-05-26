// COPYRIGHT Dassault Systemes 2008

#ifndef CATVisInfiniteEnvColorBgOverload_H
#define CATVisInfiniteEnvColorBgOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATVisInfiniteEnvironmentOverload.h"
#include "CATVisColor.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvColorBgOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvColorBgOverload* Create(const CATVisColor& iColor);
  void SetColor(const CATVisColor& iColor);

protected:
  virtual void Overload(CATVisInfiniteEnvironmentExtendedData& ioData) const;
  virtual void Overload(CATVisAmbiance& ioData) const;

private:
  CATVisInfiniteEnvColorBgOverload(const CATVisColor& iColor);
  virtual ~CATVisInfiniteEnvColorBgOverload();

  CATVisColor _color;
};

//-----------------------------------------------------------------------

#endif
