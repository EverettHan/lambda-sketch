#ifndef CATPLMMinorRelWithExpectedMinorOrder_H
#define CATPLMMinorRelWithExpectedMinorOrder_H

#include "CATPLMServicesItf.h"

// CATPLMServices
#include "CATPLMOmxCollections.h"
#include "CATIPLMError.h"

// CATPLMIdentificationAccess
#include "CATPLMRepositoryName.h"

// SpecialAPI
#include "CATSysErrorDef.h" // SpecialAPI PublicInterfaces for HRESULT

class ExportedByCATPLMServicesItf CATPLMMinorRelWithExpectedMinorOrder
{
public:
  // Note: Types that inherits from RelationType are supported (both IRPC and historical ER)
  // 
  // Suppose you have:
  // Root
  //   + Inst_A   - Ref_A   (minororder = 0)
  // Root
  //   + Inst_A'  - Ref_A'  (minororder = 1)
  // Root
  //   + Inst_A'' - Ref_A'' (minororder = 2)
  // Suppose that iListOfPairPlmidOfRelMinorOrderOfParentBo contains Inst_A, minororder = 2, then oPlmIdOfRelToMinorOrderToRel contains Inst_A, minororder = 2 and Inst_A''
  //
  // note: We only support M1 provider
  static HRESULT BuildAndExecute(const CATPLMArrayPairPLMIDInt& iListOfPairPlmidOfRelMinorOrderOfParentBo, CATPLMIDToIntToPLMID& oPlmIdOfRelToMinorOrderToRel, CATIPLMError*& opError, const CATPLMRepositoryName& iRepo = CATPLMRepositoryName_Null);

private:
  static CATBoolean _IsLimitReachedRegardingSizeOfWhereClause(int iLength);

  static HRESULT _QueryRels(const CATPLMTypeH& iType, const CATUnicodeString& iWhereClause, CATPLMUuidToIntToPLMID& ioMajorIdOfRelToMinorOrderToRel, CATIPLMError*& opError);
};

#endif
