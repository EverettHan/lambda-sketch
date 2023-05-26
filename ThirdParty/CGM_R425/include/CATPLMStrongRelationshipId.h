// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATPLMStrongRelationshipId
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
// April 2014  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMStrongRelationshipId_H
#define CATPLMStrongRelationshipId_H

#include "CATPLMIdentificationAccess.h"

#include "CATSysErrorDef.h"

#include "CATString.h"

#include "CATOmxKeyString.h"

class CATPLMTypeH;

class ExportedByCATPLMIdentificationAccess CATPLMStrongRelationshipId
{
public:

  // eci and eiob are internal values, please do not use.
  enum eStrongRelId { eV_InstanceOf, eV_Owner, eIsOwnedBy, eIsCacheInstanceOf, efrom, efromrel, eto, etorel, eci, eiob, eUndefined };

  static const CATString sV_Owner;
  static const CATString sV_InstanceOf;
  static const CATString sIsOwnedBy;
  static const CATString sIsInstanceOf;
  static const CATString sIsCacheInstanceOf;
  static const CATUnicodeString cusIsOwnedBy;
  static const CATUnicodeString cusIsCacheInstanceOf;
  static const CATString sfrom;
  static const CATString sfromrel;
  static const CATString sto;
  static const CATString storel;
  static const CATString sci;
  static const CATString siob;
  static const CATString sUndefined;

  static const CATOmxKeyString ksV_Owner;
  static const CATOmxKeyString ksV_InstanceOf;
  static const CATOmxKeyString ksIsOwnedBy;
  static const CATOmxKeyString ksIsCacheInstanceOf;
  static const CATOmxKeyString ksfrom;
  static const CATOmxKeyString ksfromrel;
  static const CATOmxKeyString ksto;
  static const CATOmxKeyString kstorel;
  static const CATOmxKeyString ksci;
  static const CATOmxKeyString ksiob;
  static const CATOmxKeyString ksUndefined;

  /**
  * <br><b>Role</b>: Convert
  * @param iRelId
  *   eV_InstanceOf, eV_Owner, efrom, efromrel, eto, etorel are expected.
  * @param oRelId
  *   sV_InstanceOf, sV_Owner, sfrom, sfromrel, sto, storel are expected
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_INVALIDARG</code>if oRelId.GetLengthInChar()==0<dd>
  * <dt><code>E_INVALIDARG</code>if iRelId is invalid, oRelId=="Undefined"<dd>
  * </dl>
  */
  static HRESULT Convert(eStrongRelId iRelId, CATString& oRelId);

  /**
  * <br><b>Role</b>: Convert
  * @param iRelId
  *   eV_InstanceOf, eV_Owner, efrom, efromrel, eto, etorel are expected
  * @param oRelId
  *   sV_InstanceOf, sV_Owner, sfrom, sfromrel, sto, storel are expected
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_INVALIDARG</code>oRelId==CATPLMStrongRelationshipId::eUndefined<dd>
  * </dl>
  */
  static HRESULT Convert(const CATString& iRelId, eStrongRelId& oRelId);

  /**
  * <br><b>Role</b>: Convert
  * @param iRelId
  *   eV_InstanceOf, eV_Owner, efrom, efromrel, eto, etorel eci are expected
  * @param oRelId
  *   sV_InstanceOf, sV_Owner, sfrom, sfromrel, sto, storel and ksci are expected
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_INVALIDARG</code>if oRelId.isNull()!=1<dd>
  * <dt><code>E_INVALIDARG</code>if iRelId is invalid, oRelId=="Undefined"<dd>
  * </dl>
  */
  static HRESULT Convert(eStrongRelId iRelId, CATOmxKeyString& oRelId);

  /**
  * <br><b>Role</b>: Convert
  * @param iRelId
  *   ksV_InstanceOf, ksV_Owner, ksfrom, ksfromrel, ksto, kstorel and ksci are expected
  * @param oRelId
  *   sV_InstanceOf, sV_Owner, sfrom, sfromrel, sto, storel and eci are expected
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_INVALIDARG</code>oRelId==CATPLMStrongRelationshipId::eUndefined<dd>
  * </dl>
  */
  static HRESULT Convert(const CATOmxKeyString& iRelId, eStrongRelId& oRelId);

  static CATBoolean IsStrongRelationShip(const CATString& iAttrNameOrRelName);

  static CATBoolean IsStrongRelationShip(const CATOmxKeyString& iAttrNameOrRelName);

  static CATBoolean IsValid(const CATPLMTypeH& iType, const CATString& iRelName);

  static CATBoolean IsValid(const CATPLMTypeH& iType, const CATOmxKeyString& iRelName);

  static CATBoolean IsValid(const CATPLMTypeH& iType, eStrongRelId& iRelId);

private:

  CATPLMStrongRelationshipId();

  ~CATPLMStrongRelationshipId();

  CATPLMStrongRelationshipId(const CATPLMStrongRelationshipId&);

  int operator=(const CATPLMStrongRelationshipId&);

};

#endif  
