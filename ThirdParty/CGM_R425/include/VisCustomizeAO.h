#ifndef VisCustomizeAO_H
#define VisCustomizeAO_H

#include "SGInfra.h"

class CATSupport;

class CATVisSSAOData;
class VisQualityData;
class ExportedBySGInfra VisCustomizeAO
{
public :

  struct AO
  {
    enum Mode
    {
      eSSAO,
      eHBAO,
      eHQAO,
      eHQAO_IBL
    };
  };

  struct Blur
  {
    enum Mode
    {
      eNone,
      eEdgeDetectionFromZ,
      eEdgeDetectionFromZAndNormal,
      eAccurateEdgeDetectionFromZAndNormal
    };
  };

  static void ApplyQualityOnData(CATVisSSAOData& ioData, const VisQualityData& iQuality);

};

#endif //VisCustomizeAO_H
