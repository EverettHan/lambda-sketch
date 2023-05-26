#ifndef VISANTIALIASINGINFO_H_
#define VISANTIALIASINGINFO_H_

#include "VisPostProcessAntialisingInfo.h"

struct VisAntialiasingInfo
{
  VisAntialiasingInfo()
  {
    msaa.nbSample = 0;
    msaa.aaOnSSAO = false;
    ssaa.factor = SSAA::eNone;
  }

  struct MSAA
  {
    unsigned int nbSample;
    bool         aaOnSSAO;
  }msaa;

  struct SSAA
  {
    enum Factor
    {
      eNone,
      e4x,
      e16x
    }factor;
  }ssaa;

  VisPostProcessAntialisingInfo postProcess;
};



#endif //VISANTIALIASINGINFO_H_
