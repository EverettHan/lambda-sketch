#ifndef _CATGPShareCountHandler_H_
#define _CATGPShareCountHandler_H_

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "SGInfra.h"

class CATGraphicPrimitive;

class ExportedBySGInfra CATGPShareCountHandler
{
public:
  static void IncreaseShareCount(CATGraphicPrimitive& );
  static void DecreaseShareCount(CATGraphicPrimitive& );
private:
  CATGPShareCountHandler();
  CATGPShareCountHandler(CATGPShareCountHandler const&);
  CATGPShareCountHandler& operator=(CATGPShareCountHandler const&);
};

#endif
