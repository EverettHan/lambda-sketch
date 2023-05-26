#ifndef CATPLMMinorBoRelResultOfMinVersion_H
#define CATPLMBoRelResultOfMinorVersioning_H

#include "CATPLMServicesItf.h"

// CATPLMServices
#include "CATPLMOmxCollections.h"
#include "CATIPLMError.h"

// CATPLMIdentificationAccess
#include "CATPLMRepositoryName.h"

// SpecialAPI
#include "CATBoolean.h"
#include "CATSysErrorDef.h" // SpecialAPI PublicInterfaces for HRESULT

class CATPLMMinorFamilyMemberCB;

typedef HRESULT(*pQueryOnBoOrRelFunc)(const CATPLMTypeH& iType, const CATPLMOrderedOSetOfPLMID& iPlmIdSet, CATPLMIDToBool& ioPlmIdToIsMemberOfMinorFamily, CATIPLMError*& opError);

class ExportedByCATPLMServicesItf CATPLMMinorFamilyMember
{
public:
  // iPlmIdSet:
  // note: - We only accept PLMReference/PLMInstance
  // 
  // oPlmIdToIsMemberOfMinorFamily:
  // if result of request made on "majorid of one given Bo && (minororder != 0 || attribute[PLMReference.V_isLastMinorVersion] == FALSE)" is empty then FALSE
  // if result of request made on "majorid of one given Bo && (minororder != 0 || attribute[PLMReference.V_isLastMinorVersion] == FALSE)" is NOT empty then TRUE
  //
  // if result of request made on "majorid of one given Bo && (from.minororder != 0 || from.attribute[PLMReference.V_isLastMinorVersion] == FALSE)" is empty then FALSE
  // if result of request made on "majorid of one given Bo && (from.minororder != 0 || from.attribute[PLMReference.V_isLastMinorVersion] == FALSE)" is NOT empty then TRUE
  //
  // note: We only support M1 provider
  static HRESULT BuildAndExecute(const CATPLMOrderedOSetOfPLMID& iPlmIdSet, CATPLMIDToBool& oPlmIdToIsMemberOfMinorFamily, CATIPLMError*& opError, const CATPLMRepositoryName& iRepo = CATPLMRepositoryName_Null);

private:
  static HRESULT _SplitQuery(const CATPLMTypeH& iType, const CATPLMArrayOfPLMID& iArrayOfPlmId, CATPLMIDToBool& ioPlmIdToIsMemberOfMinorFamily, pQueryOnBoOrRelFunc iMyFunc, CATIPLMError*& opError);

  static CATBoolean _IsLimitReachedRegardingINOperator(int iIterNbForMql);

  // Retrieve Bos which ( minororder != 0 || attribute[PLMReference.V_isLastMinorVersion] == FALSE)
  static HRESULT _QueryBos(const CATPLMTypeH& iType, const CATPLMOrderedOSetOfPLMID& iPlmIdSet, CATPLMIDToBool& ioPlmIdToIsMemberOfMinorFamily, CATIPLMError*& opError);

  // Retrieve Rels which ( from.minororder != 0 || from.attribute[PLMReference.V_isLastMinorVersion] == FALSE)
  static HRESULT _QueryRels(const CATPLMTypeH& iType, const CATPLMOrderedOSetOfPLMID& iPlmIdSet, CATPLMIDToBool& ioPlmIdToIsMemberOfMinorFamily, CATIPLMError*& opError);

  static HRESULT _Fill(const CATPLMOrderedOSetOfPLMID& iPlmIdSet, CATPLMMinorFamilyMemberCB* ipCB, CATPLMIDToBool& ioPlmIdToIsMemberOfMinorFamily);
};

#endif
