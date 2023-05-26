/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIContext_h
#define _CATIContext_h

#include "CATBaseUnknown.h"

/**
 * Retrieves the context of the element.
 * <b>Role</b>: Retrieves the context of the element.
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIContext;
#else
extern "C" const IID IID_CATIContext;
#endif

class ExportedByCATInteractiveInterfaces CATIContext : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Retrieves the context of the element.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT GetContext(CATBaseUnknown** oContext) = 0;
};

#endif
