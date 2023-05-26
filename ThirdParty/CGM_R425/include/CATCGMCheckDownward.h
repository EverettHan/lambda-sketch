
#ifndef CATCGMCheckDownward_H
#define CATCGMCheckDownward_H

// COPYRIGHT DASSAULT SYSTEMES 2021

/**
 * @brief     Class to check compatibilty of the whole CGM factory inside the CATBack process As Spec.
 * @date      W33-Y2021
 * @author    LAP
 */

#include "CGMV5Interop.h"
#include "CATOmbComponentDownwardServices.h"
#include "CATBaseUnknown.h"
#include "CATOmbDWC.h"
#include "CATDocument.h"
#include "IUnknown.h"

class CATOmxKeyValueBlock;
class CATGeomCGMCtr;

class ExportedByCGMV5Interop CATCGMCheckDownward : public CATEOmbCheckDownward
{
  CATDeclareClass;
public:
  CATCGMCheckDownward();
  virtual ~CATCGMCheckDownward();
  CATBoolean ContentCompliantForDownwardAsSpec(CATOmxKeyValueBlock& iParamList);

private:
  CATCGMCheckDownward(CATCGMCheckDownward &);
  CATCGMCheckDownward& operator=(CATCGMCheckDownward&);

  CATGeomCGMCtr * GetGeomCGMCtr();
  void            CreateTheWarning();
};

#endif
