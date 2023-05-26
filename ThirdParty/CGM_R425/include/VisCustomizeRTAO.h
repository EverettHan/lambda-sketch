#pragma once

#include "SGInfra.h"

struct VisRTAOInfo;

class ExportedBySGInfra VisCustomizeRTAO
{

public :

  enum struct ETechnique
  {
    eRTAO, eHRTAO
  };

  enum struct EFilter
  {
    eRaw, eDenoised
  };

  enum struct ECacheSize
  {
    eLow, eHigh
  };

  enum struct EQuality
  {
    eLow, eMedium, eHigh, eUltra
  };
};

