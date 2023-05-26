// COPYRIGHT Dassault Systemes 2021

#ifndef CATVisInfiniteEnvBackgroundOverload_H
#define CATVisInfiniteEnvBackgroundOverload_H

//-----------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "IVisTexturePtr.h"
#include "CATVisInfiniteEnvironmentOverload.h"

class ExportedByCATVisFoundation CATVisInfiniteEnvBackgroundOverload : public CATVisInfiniteEnvironmentOverload
{
public:
  static CATVisInfiniteEnvBackgroundOverload* CreateStereo();
  void SetStereoTextures(const IVisTexturePtr& iLeftEye, const IVisTexturePtr& iRightEye);

protected:  
  virtual void Overload (CATVisInfiniteEnvironmentExtendedData& ioData) const;
  
private:
  CATVisInfiniteEnvBackgroundOverload();
  virtual ~CATVisInfiniteEnvBackgroundOverload();
    
  IVisTexturePtr m_Bg[2];
};

//-----------------------------------------------------------------------

#endif
