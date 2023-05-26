#ifndef CATXMQLRequestFlatTable_H
#define CATXMQLRequestFlatTable_H

#include "CATPLMAsyncRequestServices.h"

#include "CATPLMAsync.h"
#include "CATPLMOmxCollections.h"
#include "CATPLMFTFilterOnAttrNodeDesc.h"

#include "CATUnicodeString.h"

#include "CATOmxArray.h"
#include "CATOmxKeyString.h"

//////////////////////////////////////////
/// Generic Interface XMQL to manage flattable ///
//////////////////////////////////////////
class ExportedByCATPLMAsync CATXMQLRequestFlatTable: public CATXMQLRequestBase
{
public:
  /**
  * Create a Flat Table request.
  *
  * @param
  * <br/> [in] ilAttrDesc : Request selectors (see CATPLMArrayOfAttrDesc).
  *            eg: in MQL declaration, we find for ChangeLog attribute ActionPhysicalId. ilAttr contains ActionPhysicalId
  *                in XMQL request, we find Column[ActionPhysicalId]. CATOmxArray<CATXMQLRequestSelector> iSelectors contains Column[ActionPhysicalId].
  * <br/> [in] iTableName : Flat Table name. eg: ChangeLog
  * <br/> [in] iTableViewValue : Single Select clause Master,View...
  * <br/> [in] iWhereClause : Single Where clause in XMQL format.
  */
  //CATXMQLRequestFlatTable(const CATUnicodeString &iTableName,
  //  const CATOmxArray<CATOmxKeyString>& ilAttrDesc,
  //  eTableViewsR iTableViewValue,
  //  const CATUnicodeString& iWhereClause);
  
  CATXMQLRequestFlatTable(const CATOmxKeyString &iTableName,
    const CATOmxArray<CATOmxKeyString>& ilAttrDesc,
    TableViewsCRUD::eProp iTableViewValue,
    const CATPLMFTFilterOnAttrNodeDesc& iWhereClause);

  ~CATXMQLRequestFlatTable();

  const CATOmxKeyString& GetTableName() const;

  TableViewsCRUD::eProp GetTableView() const;

  const CATOmxArray<CATOmxKeyString>& GetListAttrName() const;

  HRESULT GetWhereClause(CATUnicodeString& oWhereClause) const;

private:

  CATXMQLRequestFlatTable(CATXMQLRequestFlatTable&);
  CATXMQLRequestFlatTable& operator=(CATXMQLRequestFlatTable&);

  CATOmxKeyString TableName;
  TableViewsCRUD::eProp TableViewValue;

  CATPLMFTFilterOnAttrNodeDesc _WhereClauseTree;
  CATOmxArray<CATOmxKeyString> lAttrDesc;
};

#endif
