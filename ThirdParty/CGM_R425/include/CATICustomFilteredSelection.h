#ifndef CATICustomFilteredSelection_h
#define CATICustomFilteredSelection_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATAfrSelection.h"

#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATICustomFilteredSelection;

class CATUnicodeString;
class CATPathElement;
 
class ExportedByCATAfrSelection CATICustomFilteredSelection : public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    virtual CATPathElement * PrecheckPath (CATPathElement *PathToCheck) = 0;
    virtual CATPathElement * CheckPath (CATPathElement *PathToCheck, int ElementTypeListPosition) = 0;
};
#endif
