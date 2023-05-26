//===================================================================
// COPYRIGHT Microsoft 2012/02/09
//===================================================================


#ifndef CATPLMRepositoryDef_H
#define CATPLMRepositoryDef_H

#include "CATUnicodeString.h"
#include "CATUuid.h"
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATPLMIdentificationAccess.h"
#include "CATPLMRepositoryDefCollections.h"
class CATOmxKeyValueBlock;

class ExportedByCATPLMIdentificationAccess RepositoryItemDef
{
public:
  RepositoryItemDef();
  RepositoryItemDef(const CATUuid& PhysicalId, const CATUuid& ContentId);
  CATUuid _PhysicalId;
  CATUuid _ContentId;
  HRESULT ToAny(CATOmxAny &result) const;
  HRESULT FromKVB(const CATOmxKeyValueBlock& KVB);
  static HRESULT ToAny(CATOmxAny &result, const CATOmxArray<RepositoryItemDef>& Branches);
  static HRESULT ToAny(CATOmxAny &result, const CATOmxArray<CATUuid>& Uuids);

};

class ExportedByCATPLMIdentificationAccess RepositoryBranchDef
{
public:
  enum field { RepositoryId = 0x01, BranchId = 0x02, CEStamp = 0x04, CommitRef = 0x08, IterationRef = 0x10 };
  CATUuid _RepositoryId;
  CATUuid _BranchId;
  CATUuid _CEStamp;
  CATUnicodeString _CommitRef;
  CATUnicodeString _IterationRef;
  RepositoryBranchDef();
  HRESULT ToAny(CATOmxAny &result, unsigned int fields) const;
  HRESULT FromKVB(const CATOmxKeyValueBlock& KVB);
  static HRESULT ToAny(CATOmxAny &result, const CATOmxArray<RepositoryBranchDef>& Branches, unsigned int fields);
};

class ExportedByCATPLMIdentificationAccess RepositoryCheckoutResult
{
public:
  RepositoryBranchDef _RepBranchId;
  CATOmxArray<RepositoryItemDef> _ObjectsId;
  HRESULT FromKVB(const CATOmxKeyValueBlock& KVB);
};

class ExportedByCATPLMIdentificationAccess RepositoryCheckinInput
{
public:
  RepositoryBranchDef _RepBranchId;
  CATOmxArray<RepositoryItemDef> _UpdatedIds;
  CATOmxArray<RepositoryItemDef> _CreatedIds;
  CATOmxArray<RepositoryItemDef> _DeletedIds;
  HRESULT ToAny(CATOmxAny &result) const;
  static HRESULT ToAny(CATOmxAny &result, const CATOmxArray<RepositoryCheckinInput>& Branches);
};

#endif
