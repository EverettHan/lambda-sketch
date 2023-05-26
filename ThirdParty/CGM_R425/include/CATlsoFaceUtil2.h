#ifndef CATlsoFaceUtil2_H
#define CATlsoFaceUtil2_H

#include "AdvTrimOpe.h"

class CATFace;
class CATSoftwareConfiguration;
class CATBody;

class ExportedByAdvTrimOpe CATlsoFaceUtil2
{
public:
  // only static methods
  static double   ComputeArea          (CATFace* ipFace, CATSoftwareConfiguration* ipConfig, double iPercentageTolerance=0.05); // 0.05 to balance accuracy and performance, default value in CATIPGMDynMassProperties3DAPP is 0.01 .
  static double   ComputePerimeter     (CATFace* ipFace, CATSoftwareConfiguration* iConfig);
  static CATFace* CreateFaceWithoutHole(CATFace* ipFace, CATBody* ipBody, CATSoftwareConfiguration* iConfig);
};

#endif /* CATlsoFaceUtil_H */
