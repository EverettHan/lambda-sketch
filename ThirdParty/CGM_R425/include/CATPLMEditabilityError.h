#ifndef CATPLMEditabilityError_H
#define CATPLMEditabilityError_H
//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//----------------------------------------------------------------
// Editability error class management
//----------------------------------------------------------------
/**
* @level Protected
* @usage U1
*/

#include "CATPLMComponentInterfaces.h"
#include "CATError.h"
#include "CATListOfInt.h"
#include "CATPLMID.h"
#include "CATOmxSR.h"

class CATBaseUnknown;

class ExportedByCATPLMComponentInterfaces CATPLMEditabilityError : public CATError
{
public:
  CATDeclareError(CATPLMEditabilityError, CATError);

  /**
  * Create an editability error
  * CATBaseUnknown* iInvolvedEntity : the entity in error
  * @param iMsgId, iMsgCatalog
  *   The message key and catalog
  * OR
  * @param pError error coming from PLMIntegration or PLMAdapter
  *
  * @param oEditabilityError [out, CATBaseUnknown#Release]
  *	The created error
  */
  static HRESULT CreateEditabilityError(CATBaseUnknown* iInvolvedEntity, const CATPLMID& iId, const char * iMsgId, const char * iMsgCatalog, CATPLMEditabilityError*& oEditabilityError);
  static HRESULT CreateEditabilityError(CATBaseUnknown* iInvolvedEntity, const CATPLMID& iId, CATError * iError, CATPLMEditabilityError*& oEditabilityError);
  //only used by CATEAsdUpdtFakeError
  static HRESULT CreateEditabilityError(CATBaseUnknown* iInvolvedEntity, const char * iMsgId, const char * iMsgCatalog, CATPLMEditabilityError*& oEditabilityError);

  /**
   * destructor
   */
  ~CATPLMEditabilityError();

  /**
   * Get the entity responsible for the non editability.
   * @return CATBaseUnknown#Release
   */
  CATBaseUnknown* GetInvolvedEntity() const;

  /** unusable */
  CATListOfInt GetListOfInvolvedIndexes() const { return m_InvolvedIndexes; }
  inline void AppendInvolvedIndex(int iIndex) { m_InvolvedIndexes.Append(iIndex); }

  inline CATPLMID GetAssociatedObjectId() const { return m_id; }

private:
  CATPLMEditabilityError();
  CATPLMEditabilityError(const CATError & iError);
  CATOmxSR<CATBaseUnknown> m_InvolvedEntity;
  CATListOfInt m_InvolvedIndexes;
  CATPLMID m_id;
};

#endif
