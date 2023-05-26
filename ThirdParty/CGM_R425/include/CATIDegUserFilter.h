#ifndef CATIDegUserFilter_h
#define CATIDegUserFilter_h

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATDialogEngine.h"

#include "IUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATIDegUserFilter;
#else
extern "C" const IID IID_CATIDegUserFilter;
#endif

class CATUnicodeString;
class CATPathElement;
 
class ExportedByCATDialogEngine CATIDegUserFilter : public IUnknown
{
  public:
  virtual CATPathElement * PrecheckPath (CATPathElement *PathToCheck) = 0;
  virtual CATPathElement * CheckPath (CATPathElement *PathToCheck, int ElementTypeListPosition) = 0;
};
#endif
