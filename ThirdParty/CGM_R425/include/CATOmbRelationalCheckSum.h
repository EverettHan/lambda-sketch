#ifndef _CATOmbRelationalCheckSum_H
#define _CATOmbRelationalCheckSum_H

/**
 * @level Private
 * @usage U1
 */

 // SystemTS
#include "CATBoolean.h"
// System
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
// ObjectModelerCollection
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxOrderedOSet.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATPLMSemanticRelation.h"
#include "CATPLMID.h"
#include "CATPLMID_Any.h"
#include "CATPLMSemanticRelation.h"
#include "CATPLMTypeH.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbRelationalImportFormat;
class CATSysSimpleHashTable;
class CATOmbRelationalCheckSumItem;
class CATIPLMRecordRead;
class CATPLMSemanticRelation;
class CATPLMID;
class CATPLMSemanticRelationData;
class CATComponentId;

typedef CATOmxOHMap<CATPLMID_Any, CATOmxOrderedOSet<CATPLMTypeH> > MapTypesByPhysical;

class ExportedByCATObjectModelerBase CATOmbRelationalCheckSum
{
public:
  CATOmbRelationalCheckSum();
  ~CATOmbRelationalCheckSum();

  HRESULT BuildFromComponent(const CATComponentId & iCID);
  HRESULT BuildFromFormat(const CATPLMID & iPLMID, CATOmbRelationalImportFormat & iFormat, const int iMode = 0 /*0:check;1:recovery*/);

  CATBoolean IsValid();
  CATBoolean AreMetadatasCorrupted();
  HRESULT GetPhysicalToCheck(CATOmxArray<CATPLMID_Any> &oPids);
  HRESULT ValidatePhysicalIdAndType(CATOmxOHMap<CATPLMID_Any, CATPLMID> & iPLMIdsByPhysical);

  void PushUnicodeDump(CATListOfCATUnicodeString & ioDump) const;

private:

  HRESULT RegisterSemanticRelation(const CATPLMSemanticRelation & iSemanticRelation);

  HRESULT RegisterSingleSemanticRelation(const CATPLMID & iPointedPLMID, const CATPLMSemanticRelationData & iSRData);

  HRESULT CheckSemanticRelations();

  friend class CATOmbRelationalCheckSumComparator;

  unsigned int Size() const;

  MapTypesByPhysical GetTypesByPhysicalIds() { return _typesByPhysical; };

  // starting at zero
  CATOmbRelationalCheckSumItem * GetItem(unsigned int iRank) const;

  CATOmbRelationalCheckSumItem * Locate(CATOmbRelationalCheckSumItem * iItem) const;

  CATSysSimpleHashTable & HashTable();

  /* forbidden operations */
  CATOmbRelationalCheckSum(CATOmbRelationalCheckSum &);
  CATOmbRelationalCheckSum& operator=(CATOmbRelationalCheckSum&);

  int                        _ComputationDone;
  CATBoolean                 _IsValid;
  CATBoolean                 _AreMetadatasCorrupted;
  CATBoolean                 _AreTypesCorrupted;
  CATSysSimpleHashTable *    _HashTable;
  CATListOfInt               _LinkedIDRel;
  CATPLMID                   _PLMID;
  CATOmxArray<CATPLMSemanticRelation> _LSRs;
  MapTypesByPhysical _typesByPhysical;
  CATOmxOHMap<CATPLMID_Any, CATPLMID> _MapPLMIdByPhysical;
};

#endif
