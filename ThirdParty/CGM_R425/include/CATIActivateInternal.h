// COPYRIGHT DASSAULT SYSTEMES	2004
//===================================================================
#ifndef _CATIActivateInternal_h
#define _CATIActivateInternal_h

/**
 */

#include "CATBaseUnknown.h"

/**
 * Internal Interface to activate/deactivate an element.
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIActivateInternal;
#else
extern "C" const IID IID_CATIActivateInternal;
#endif
 
class ExportedByCATInteractiveInterfaces CATIActivateInternal : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Retrieves the break status.
   * @param oActivateStatus
   * The activate status.
   * <br><b>Legal values </b>:
   * <br>0 : the element is activated. 
   * <br>1 : the element is deactivated. 
   * <br>2 : the status is unknown. 
   */
  virtual HRESULT ActivateStatus(int* oActivateStatus) = 0;

  /**
   * Activate the element.
   */
  virtual HRESULT Activate() = 0;

   /**
   * Deactivate the element.
   */
  virtual HRESULT Deactivate() = 0;
  
};

#endif
