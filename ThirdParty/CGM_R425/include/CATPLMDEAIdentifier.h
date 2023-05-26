#ifndef _CATPLMDEAIdentifier_H
#define _CATPLMDEAIdentifier_H

// COPYRIGHT DASSAULT SYSTEMES 2005
/**
 * @level Private
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "CATPLMTypeH.h"
#include "CATOmxSharable.h"
#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATOmxList.h"

/**
 * normally reroute uses logicalid as equivalence class
 * for some types it uses a set of specific attributes (for example V_Identifier attribute on some RFLP types)
 */
class CATPLMDEAIdentifier : public CATOmxSharable
{
  const CATPLMTypeH Type;
  const CATOmxArray<CATOmxKeyString> Attributes; //at least 1, probably never more than 1
public:
  /*
   * Return the list of types logically identified by an attribute set (instead of logical ID)
   * and the attribut set to use for that identification
   */
  static CATOmxArray<CATOmxKeyString> GetIdSet(const CATPLMTypeH& iType);

  /*
   * see CATXPLMDEAIdentifier::ChangeDEA
   */
  static ExportedByCATPLMIdentification HRESULT ChangeDEA(CATIPLMComponent* ipObject, const CATString& iAttr, const CATUnicodeString& value);

  static ExportedByCATPLMIdentification void  Reset();
private:
  inline CATPLMDEAIdentifier(const CATPLMTypeH& iType, const CATOmxArray<CATOmxKeyString>& iAttributes) :Type(iType), Attributes(iAttributes) {}
  CATPLMDEAIdentifier(const CATPLMDEAIdentifier&) = delete;
  CATPLMDEAIdentifier& operator=(const CATPLMDEAIdentifier&) = delete;
  static CATOmxList<CATPLMDEAIdentifier> Parse(const char* types, const char* attributes);
};

#endif
