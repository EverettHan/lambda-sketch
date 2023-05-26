#ifndef _CATTosSynchronizationListener_H
#define _CATTosSynchronizationListener_H
/**
 * @level Private
 * @usage U5
 */
#include "CATBaseUnknown.h"
#include "ExportedByCATPLMTos.h"
#include "CATBoolean.h"

class CATTosSynchronizationItem;

/**
* To be used for driving synchronization operation
*/
class ExportedByCATPLMTos CATTosSynchronizationListener
{
public:

  CATTosSynchronizationListener(){}
  virtual ~CATTosSynchronizationListener(){}

  /**
  * Delegate validation to listener.
  * In that case, validation is managed by using OnValidationStarting, Validate, OnValidationEnding
  *
  * @return 
  *       TRUE  : Delegation to listener for acceptance
  *       FALSE : All changes are automatically accepted
  */
  virtual CATBoolean IsValidationActivated() = 0;

  /**
  * Event send before validation if validation is delegated to listener
  * 
  * @return 
  *      S_OK   : succeeded
  *      E_FAIL : failed
  */
  virtual HRESULT OnValidationStarting(){return S_OK;}

  /**
  * Validation if validation is delegated to listener
  * 
  * @param iChanges
  *        Requested changes
  * @param oAccepted
  *        Validation result
  * @return 
  *      S_OK   : succeeded
  *      E_FAIL : failed
  */
  virtual HRESULT Validate(const CATTosSynchronizationItem & iChanges, CATBoolean & oAccepted){oAccepted = FALSE; return E_NOTIMPL;}

  /**
  * Event send after validation if validation is delegated to listener
  * 
  * @return 
  *      S_OK   : succeeded
  *      E_FAIL : failed
  */
  virtual HRESULT OnValidationEnding(CATBoolean & oAccepted){oAccepted = TRUE; return S_OK;}
};

#endif
