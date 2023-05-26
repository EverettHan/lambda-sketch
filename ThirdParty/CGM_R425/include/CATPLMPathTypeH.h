#ifndef CATPLMPathTypeH_H
#define CATPLMPathTypeH_H

#include "CATPLMIdentificationAccess.h"

#include "CATSysErrorDef.h"

#include "CATOmxKind.h"
#include "CATOmxClassManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"
#include "CATOmxArray.h"
#include "CATOmxSR.h"
#include "CATOmxArray.h"

class CATIPLMPathTypeInt;
class CATOmxKeyString;
class CATPLMPathAttributeH;
class VPMIDicSubRelationship;
class VPMIDicPathType;
class IPLMPathTypeIntFactory;
class CATPLMType;

class ExportedByCATPLMIdentificationAccess CATPLMPathTypeH
{
  friend class CATPLMPathTypeHLoader;
  friend class CATPLMType;
  friend class CATPLMPathTypeIntToolsPrivateFactory;
public:
  CATPLMPathTypeH();
  CATPLMPathTypeH(const CATPLMPathTypeH&);

  ~CATPLMPathTypeH();

  CATPLMPathTypeH& operator =(const CATPLMPathTypeH & iSource);

  int operator ==(const CATPLMPathTypeH & iOther) const;

  int operator !=(const CATPLMPathTypeH & iOther) const;

  HRESULT ComputeHashKey(unsigned int & oKey) const;

  int Compare(const CATPLMPathTypeH & iOther) const;

  /*
    * for local path type that inherits from SemanticRelation
    * returns ClassA.PathTypeB
    *
    * for global path type that inherits from SemanticRelation
    * returns Role.Category
  */
  const CATOmxKeyString& GetId() const;

  /**
  * List attr found on a path type
  * Inheritance is automatically taken into account
  *
  * @param oAttrNameSet
  *  attr found on path type and on parent path type
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT ListAttrName(CATOmxOSet<CATOmxKeyString>& oAttrNameSet) const;

  /**
  * List attr found on a path type
  * Inheritance is automatically taken into account
  *
  * WARNING: Attribute ordered taking into account alphabetical order
  *
  * @param oAttrNameSet
  *  attr found on path type and on parent path type
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  HRESULT ListAttrName(CATOmxArray<CATOmxKeyString>& oListAttrName) const;

  HRESULT GetAttribute(const CATOmxKeyString& iAttrName, CATPLMPathAttributeH& oPathAttr) const;

  HRESULT GetSuperPathTypeH(CATPLMPathTypeH& oPathType) const;

  CATBoolean IsKindOf(const CATOmxKeyString& iRealName) const;

  CATBoolean IsMinorSensitive() const;


  const CATOmxKeyString& GetRole() const;

  const CATOmxKeyString& GetCategory() const;
  CATBoolean IsGlobal() const;

  HRESULT GetOwnedBy(CATPLMType*& opType) const;
private:

  CATPLMPathTypeH(VPMIDicSubRelationship*);
  CATPLMPathTypeH(VPMIDicPathType*);

  IPLMPathTypeIntFactory& _Factory() const;

  CATOmxSR<CATIPLMPathTypeInt> _spPathTypeInt;
};

extern const ExportedByCATPLMIdentificationAccess CATPLMPathTypeH CATPLMPathTypeH_Null;

template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMPathTypeH>::manager();

typedef ExportedByCATPLMIdentificationAccess CATOmxOMap<CATUnicodeString, CATPLMPathTypeH, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATOmxDefaultCollecManager<CATPLMPathTypeH>::manager> CATPLMUnicodeStringToPathTypeHMap;

typedef ExportedByCATPLMIdentificationAccess CATOmxArray<CATPLMPathTypeH, CATOmxDefaultCollecManager<CATPLMPathTypeH>::manager> CATPLMPathTypeHArray;

#endif
