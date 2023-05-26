#ifndef CATVisProtocolComputeLODs_H
#define CATVisProtocolComputeLODs_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "SGInfra.h"

#include "CATVizBaseCodeExtension.h"

class CATRep;

class ExportedBySGInfra CATVisProtocolComputeLODs : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATVisProtocolComputeLODs);

public:  

  CATVisProtocolComputeLODs();
  virtual ~CATVisProtocolComputeLODs();

  virtual int Compute(CATRep *ioRep, int iNbLods, double *iLodStep) = 0;

  virtual int Clean(CATRep* ioRep) = 0;

  static int sDoComputeLODs(CATRep *ioRep, int iNbLods, double *iLodStep);

  static int sDoCleanLODs(CATRep* ioRep);

private:

  static CATVisProtocolComputeLODs* _pInstance;
};

#endif
