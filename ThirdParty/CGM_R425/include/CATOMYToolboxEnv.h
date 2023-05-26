//===================================================================
// COPYRIGHT Dassault Systemes 2004
//===================================================================
// Header definition of CATOMYToolboxEnv
//===================================================================
// Usage notes:
// Runtime environment variables to activate/deactivate specific behaviors
//===================================================================
// January 2022  Creation: EPB
//===================================================================
#ifndef CATOMYToolboxEnv_H
#define CATOMYToolboxEnv_H

#include "ObjectModelerSystem.h"

#include "CATBoolean.h"

class ExportedByObjectModelerSystem CATOMYToolboxEnv
{
  friend class TSTCATPLMxConversionDoubleStringTestIsAlmostEqual;
  CATOMYToolboxEnv();
public:
  unsigned int PLM_OMXFTOA_IN_ABSTRACTION;
  CATBoolean _IS_PLM_ATTR_WITHOUT_DFLT_OF_DFLT_SUPPORTED;

  /**
  * Resets singleton for test purpose.
  */
  void reset();

  /**
  * Returns the singleton.
  */
  static const CATOMYToolboxEnv &s();

private:

  static CATOMYToolboxEnv &nocsts();
};

#endif
