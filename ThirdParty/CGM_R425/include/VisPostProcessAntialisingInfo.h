#ifndef VISPOSTPROCESSANTIALISINGINFO_H_
#define VISPOSTPROCESSANTIALISINGINFO_H_

#include "SGInfra.h"

struct ExportedBySGInfra VisPostProcessAntialisingInfo
{

  enum Technique
  {
    eNone,
    eFXAA,
    eTAA,
    eDLSS //gf8 should this be called eDLAA?
  }screenSpaceTechnique;

  struct FXAA
  {
    enum Quality
    {
      eFast,
      eDefault,
      eHigh,
      eExtreme
    }quality;
  }fxaa;

  VisPostProcessAntialisingInfo()
  {
    screenSpaceTechnique = eNone;
    fxaa.quality = FXAA::eDefault;
  }

  static const char * Convert(Technique     iTechnique);
  static const char * Convert(FXAA::Quality iQuality);

  static void Convert(const char * iName, VisPostProcessAntialisingInfo::Technique & oTechnique);
  static void Convert(const char * iName, VisPostProcessAntialisingInfo::FXAA::Quality & oQuality);

};


#endif //VISPOSTPROCESSANTIALISINGINFO_H_
