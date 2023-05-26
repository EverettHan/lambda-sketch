#ifndef VISSGFACTORYCODEEXTENSION_H
#define VISSGFACTORYCODEEXTENSION_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "CATVizBaseCodeExtension.h"
#include "SGInfra.h"

class IVisSGObject;
class VisSGPrimitiveDescription;

class ExportedBySGInfra VisSGFactoryCodeExtension : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(VisSGFactoryCodeExtension);

public:  

  VisSGFactoryCodeExtension();
  virtual ~VisSGFactoryCodeExtension();

  virtual HRESULT CreateSGObject(VisSGPrimitiveDescription* ipDescription, IVisSGObject** opObject) = 0;
};

#endif // VISSGFACTORYCODEEXTENSION_H
