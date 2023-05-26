// COPYRIGHT Dassault Systemes 2018
//===================================================================
//
// CATXMQLRequestFlatTableSplitQuery.h
//
//===================================================================
//
// Usage notes:
//   Ability give to extract rows of a flat table reducing server load
//
//===================================================================
// context:
// Suppose you want to retrieve P attributes defined using "const CATOmxArray<CATOmxKeyString>& ilAttrDesc"
// of many rows of a flat table respecting a criteria defined using "const CATPLMFTFilterOnAttrNodeDesc& iWhereClause"
//
// Job made:
// To reduce server load, we will first request rowuuids of flat table respecting criteria.
// Once we have retrieved N rowuuids, we do additional queries to retrieve attributes defined in "const CATPLMFTFilterOnAttrNodeDesc& iWhereClause" on known rowuuids:
// At the end, you have following exchanges:
// -> ONE BASIC query requesting rowuuid respecting criteria defined "const CATPLMFTFilterOnAttrNodeDesc& iWhereClause"
// -> N   OPEN  queries requesting attributes defined in "const CATOmxArray<CATOmxKeyString>& ilAttrDesc" on [rowuuid_1,rowuuid_500]
// Remark:
// int limit = 500 can be changed using CATPLMServicesToolboxEnv::s()._FTMAXOperators;
//===================================================================
// Restriction:
// We are not able to extract 20 millions of lines, we are just able to go further then if we use CATXMQLRequestFlatTable
// Test has been made on 300 000 lines: we have been able to extract them
//===================================================================
// August 2018  Creation: EPB
//===================================================================

#ifndef CATXMQLRequestFlatTableSplitQuery_H
#define CATXMQLRequestFlatTableSplitQuery_H

#include "CATPLMAsync.h"
#include "CATPLMOmxCollections.h"
#include "CATPLMFTFilterOnAttrNodeDesc.h"
#include "CATAsyncXMQLCollections.h"

#include "CATUnicodeString.h"

#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATOmxOMap.h"

class CATIXMQLCallBack;
class CATXMQLOpenInternalCallBack;

//////////////////////////////////////////
/// Generic Interface XMQL to manage a big extract of flattable ///
//////////////////////////////////////////
/// Restriction:
/// We are not able to extract 20 millions of lines, we are just able to go further then if we use CATXMQLRequestFlatTable
/// Test has been made on 300 000 lines: we have been able to extract them
//////////////////////////////////////////
class ExportedByCATPLMAsync CATXMQLRequestFlatTableSplitQuery
{
public:
  /**
  * Create a Flat Table request.
  *
  * @param
  * <br/> [in] iTableName : Flat Table name. eg: ChangeLog
  * <br/> [in] ilAttrDesc : Request selectors (see CATPLMArrayOfAttrDesc).
  *            eg: in MQL declaration, we find for ChangeLog attribute ActionPhysicalId. ilAttr contains ActionPhysicalId
  *                in XMQL request, we find Column[ActionPhysicalId]. CATOmxArray<CATXMQLRequestSelector> iSelectors contains Column[ActionPhysicalId].
  * <br/> [in] iTableViewValue : Single Select clause Master,View...
  * <br/> [in] iWhereClause : Single Where clause in XMQL format.
  */
  // Restriction:
  // For iTableViewValue, we only support enoneTableViewsCRUD::eNone 
  CATXMQLRequestFlatTableSplitQuery(const CATOmxKeyString &iTableName,
    const CATOmxArray<CATOmxKeyString>& ilAttrDesc,
    TableViewsCRUD::eProp iTableViewValue,
    const CATPLMFTFilterOnAttrNodeDesc& iWhereClause);

  ~CATXMQLRequestFlatTableSplitQuery();

  // Restriction:
  // For isAsync, we only support FALSE
  HRESULT ExecuteXMQLQueries(CATIXMQLCallBack* iopCB, CATBoolean isAsync = FALSE);

private:

  CATXMQLRequestFlatTableSplitQuery(CATXMQLRequestFlatTableSplitQuery&);
  CATXMQLRequestFlatTableSplitQuery& operator=(CATXMQLRequestFlatTableSplitQuery&);

  HRESULT _OpenQuery(const CATOmxArray<CATUnicodeString>& iListRowUuid,
    int iStartPosition,
    int NbOfElementPerOpenQuery,
    CATXMQLOpenInternalCallBack* iopOpenCB);

  HRESULT _TreatOpenCB(CATXMQLOpenInternalCallBack* ipOpenCB, CATPLMStringToCATA5CsvRow& iomRowUuidWithRow);

  CATOmxKeyString _TableName;
  TableViewsCRUD::eProp _TableViewValue;

  CATPLMFTFilterOnAttrNodeDesc _WhereClauseTree;
  CATOmxArray<CATOmxKeyString> _lAttrDesc;
};

#endif
