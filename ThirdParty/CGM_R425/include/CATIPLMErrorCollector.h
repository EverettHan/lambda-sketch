#ifndef CATIPLMErrorCollector_H
#define CATIPLMErrorCollector_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATComponentId.h"
#include "CATLISTV_CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATIPLMErrorCollector;
#else
extern "C" const IID IID_CATIPLMErrorCollector;
#endif

/**
* Interface to collect PLM Errors.
*/
class ExportedByCATPLMTos CATIPLMErrorCollector : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Create an error cell for a CATError.
  *
  * @param iErrorToDuplicate
  *        The Error to duplicate. The life cycle must be managed by caller.
  * @param iInvolvedComponent
  *        The component associated to this error
  * @return
  *		 S_OK : ErrorCell successfully created
  *  E_FAIL : ErrorCell creation failed
  */
  virtual HRESULT CreateErrorCell (CATError & iErrorToDuplicate, const CATComponentId & iInvolvedComponent) = 0;

  /**
  * Create an error cell for a CATError.
  *
  * @param iErrorToDuplicate
  *        The Error to duplicate. The life cycle must be managed by caller.
  * @param iInvolvedComponents
  *        The list of components associated to this error
  * @return
  *		 S_OK : ErrorCell successfully created
  *  E_FAIL : ErrorCell creation failed
  */
  virtual HRESULT CreateErrorCell (CATError & iErrorToDuplicate, const CATLISTV(CATComponentId) & iInvolvedComponents) = 0;

  virtual HRESULT CreateCoreOpenErrorCell (const CATUnicodeString &iErrorName, const CATComponentId &iCID, const CATOmxKeyValueBlock &iBlock) = 0; //try to get display name from iBlock, then iCID
  virtual HRESULT CreateCoreOpenErrorCell (const CATUnicodeString &iErrorName, const CATComponentId &iCID) = 0; //try to get display name from iCID

};

CATDeclareHandler(CATIPLMErrorCollector, CATBaseUnknown);

#endif
