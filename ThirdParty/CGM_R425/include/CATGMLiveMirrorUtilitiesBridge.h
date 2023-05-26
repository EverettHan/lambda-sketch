#ifndef CATGMLiveMirrorUtilitiesBridge_H
#define CATGMLiveMirrorUtilitiesBridge_H

#include "CATCGMNewArray.h"
#include "AdvTrimOpe.h"
#include "CATLISTP_CATMathPlane.h"

class CATSoftwareConfiguration;
class CATBody;
class CATGMLiveMirrorUtilitiesBridge;

typedef CATGMLiveMirrorUtilitiesBridge*  (*CATGMLiveMirrorUtilitiesBridgeCreator) (CATBody & iBody, CATSoftwareConfiguration * iConfig);

class ExportedByAdvTrimOpe CATGMLiveMirrorUtilitiesBridge
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  virtual ~CATGMLiveMirrorUtilitiesBridge() {};

  virtual void ComputePlaneOfSymmetryList(CATLISTP(CATMathPlane) & oMathPlaneList)=0;

};

ExportedByAdvTrimOpe CATGMLiveMirrorUtilitiesBridge * CATCreateGMLiveMirrorUtilitiesBridge(CATBody & iBody, CATSoftwareConfiguration * iConfig);

#endif 

