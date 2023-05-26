#ifndef __CATISearchObject
#define __CATISearchObject


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0CORBA.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0CORBA IID IID_CATISearchObject;
#else
extern "C" const IID IID_CATISearchObject;
#endif

/**
 * Interface that implements the search method for CATPathElement objects.
 */
class ExportedByJS0CORBA CATISearchObject : public CATBaseUnknown
{
   CATDeclareInterface;
   public :
/**
 * Search for an interface supported by the objects aggregated in a
 * CATPathElement.
 * @param iid
 *   The interface identifier for which a pointer is requested.
 * @param ppv
 *   The address where the returned pointer to the interface is located.
 * @return
 *   See QueryInterface.
 */
      virtual HRESULT __stdcall Search(const IID &iid, void **ppv) = 0;
};

CATDeclareHandler(CATISearchObject,CATBaseUnknown);

#endif
