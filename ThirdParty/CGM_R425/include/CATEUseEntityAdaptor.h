
#ifndef __CATEUseEntityAdaptor_h__
#define __CATEUseEntityAdaptor_h__

// COPYRIGHT DASSAULT SYSTEMES 2009  

/**
 * @level Protected
 * @usage U2
 */

class CATBaseUnknown;
class CATIUseEntity;

// BSFBuildtimeData
#include "CATIAV5Level.h"
// SpecialAPI
#include "CATSysBoolean.h" // CATBoolean
#include "CATSysErrorDef.h" // HRESULT
// System
#include "CATLISTV_CATBaseUnknown.h"
// DataCommonProtocolUse
#include "CATIUseEntity.h"
#include "CATLISTV_CATIUseEntity.h" // CATListOfCATIUseEntity_var
#include "DataCommonProtocolUse.h"

/**
 * Basic and Mandatory adaptor required to implement the services defined in DataCommonProtocolServices.
 * Default implementation returns E_NOTIMPL for all methods. You have to return the same for not implemented aspects.
 * Other return codes will be changed to either S_OK or E_FAIL.
 * @see CATIUseEntity
 * @see DataCommonProtocolServices
 */
class ExportedByDataCommonProtocolUse CATEUseEntityAdaptor : public CATIUseEntity
{
  CATDeclareClass;

public:
 
  // Services related to the Update protocol.

  /**
   * Override this method to implement DataCommonProtocolServices::IsUpToDate on your CATIUseEntity.
   * Default implementation returns E_NOTIMPL.
   */
  virtual HRESULT IsUpToDate(CATBoolean & oUpToDate) const;
  /**
   * Override this method to implement DataCommonProtocolServices::Update on your CATIUseEntity.
   * Default implementation returns E_NOTIMPL.
   */
  virtual HRESULT Update();

  // Services related to the Delete protocol.

  /**
   * Override this method to implement DataCommonProtocolServices::CanDelete on your CATIUseEntity.
   * Default implementation returns E_NOTIMPL.
   */
  virtual HRESULT CanDelete(CATBoolean & oDeletable) const;
  /**
   * Override this method to implement DataCommonProtocolServices::Delete on your CATIUseEntity.
   * Default implementation returns E_NOTIMPL.
   */
  virtual HRESULT Delete();

  // Services related to the CPP protocol.

  /**
   * Override this method to prevent a CCP operation on your enity(ies).
   * - You may prevent such an operation either because your object cannot be duplicated at all,
   *   or because of it cannot be pasted in/under the target, or because there is another incompatible
   *   object in the list of entities to copy.
   * - Each enity in the list of entities to copy plus the paste target will be queried in turn.
   * - Others entities (aggregated elements, additional elemnts included by CATICutAndPastable::BoundaryExtract...)
   *   will not be queried.
   *   This is a pre-check. In case of denial, no CATICutAndPastable implementation will get called.
   * - Default implementation returns E_NOTIMPL, which allows copy operations.
   * @param
   *   iEntitiesToCopy: the value of the same argument in the call to any of the DataCommonProtocolCCPServices services.
   *   iPasteTarget: the value of the same argument in the call to any of the DataCommonProtocolCCPServices services.
   *   oForbid (out): if is TRUE the CCP operation will be refused.
   * @return
   *   S_OK, S_FALSE...: the value of oForbid will be used (and if is TRUE will prevent the CCP operation).
   *   E_FAIL, E_NOTIMPL...: the CCP operation will be allowed.
   */
  virtual HRESULT ForbidCCPServices(const CATListValCATBaseUnknown_var & iEntitiesToCopy, const CATBaseUnknown * iPasteTarget, CATBoolean & oForbid) const;
};


#endif // __CATEUseEntityAdaptor_h__
