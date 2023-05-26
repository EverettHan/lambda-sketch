#ifndef GOOptimizableParameterCodeExtension_H
#define GOOptimizableParameterCodeExtension_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"

#include "CATVizBaseCodeExtension.h"

class ExportedByGraphicsOptimizer GOOptimizableParameterCodeExtension : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(GOOptimizableParameterCodeExtension);

public:  

  GOOptimizableParameterCodeExtension();
  virtual ~GOOptimizableParameterCodeExtension();

  virtual HRESULT __stdcall CreateInstance(void** oPPV) = 0;
};

#endif
