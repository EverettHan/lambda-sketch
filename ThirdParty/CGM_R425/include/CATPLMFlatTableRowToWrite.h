#ifndef CATPLMFlatTableRowToSave_H
#define CATPLMFlatTableRowToSave_H

#include "CATPLMServicesItf.h"

#include "CATOmxKeyValueBlock.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxSR.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxArray.h"
#include "CATPLMQueryFilterEnum.h"

class CATPLMFlatTableRowToWriteInt;
class CATPLMFTFilterOnAttrNodeDesc;
class CATUnicodeString;

class ExportedByCATPLMServicesItf CATPLMFlatTableRowToWrite
{
public:
  CATPLMFlatTableRowToWrite();

  ~CATPLMFlatTableRowToWrite();

  // ----------------------------------------------------------------------------------------------------------------------------
  // Internal structure are shared
  // Suppose you write
  // CATPLMFlatTableRowToWrite a(c);
  // Modification made on a are shared by b!
  // b cannot be modified!
  // ----------------------------------------------------------------------------------------------------------------------------
  CATPLMFlatTableRowToWrite(const CATPLMFlatTableRowToWrite &);

  // ----------------------------------------------------------------------------------------------------------------------------
  // Internal structure are shared
  // Suppose you write
  // CATPLMFlatTableRowToWrite a(c);
  // Modification made on a are shared by b!
  // b cannot be modified!
  // ----------------------------------------------------------------------------------------------------------------------------
  CATPLMFlatTableRowToWrite& operator=(const CATPLMFlatTableRowToWrite&);

  // ----------------------------------------------------------------------------------------------------------------------------
  // Create/Modify/Update
  // ----------------------------------------------------------------------------------------------------------------------------
  // C means create; U means Update; D means Delete
  enum eOperation { eCreate, eUpdate, eDelete };

  // ----------------------------------------------------------------------------------------------------------------------------
  // Jointure of Flat Table
  // ----------------------------------------------------------------------------------------------------------------------------
  // iListOfSelectCond: list of retrieved after CUD operation

  // ----------------------------------------------------------------------------------------------------------------------------
  // Suppose you modify existing line of a flattable, modification can be authorized only if some rules are verified server side.
  // ----------------------------------------------------------------------------------------------------------------------------
  // eg:
  // cestampline is an attribute that check concurrent modification.
  // You have modified an existing line of flattable retrieved from server with cestampline == uuid1
  // Now cestampline == uuid2 afterr modification
  // You can save modification only if cestampline == uuid1 in database
  // cestampline == uuid1 is set using CATPLMFTFilterOnAttrNodeDesc
  // ----------------------------------------------------------------------------------------------------------------------------
  // Init can be called only one time on a CATPLMFlatTableRowToWrite
  // ----------------------------------------------------------------------------------------------------------------------------
  HRESULT Init(const CATOmxKeyString& iTableName, eOperation iOperationValue, TableViewsCRUD::eProp iTableViewValue,
    const CATOmxKeyValueBlock& iValueBlock,
    const CATPLMFTFilterOnAttrNodeDesc& iAttrNodeFilterValue,const CATOmxArray<CATOmxKeyString>& iListOfSelectCond);


  // ----------------------------------------------------------------------------------------------------------------------------
  // Accessors
  // ----------------------------------------------------------------------------------------------------------------------------
  const CATOmxKeyString& GetTableName() const;

  eOperation GetOperationValue() const;

  TableViewsCRUD::eProp GetTableViewValue() const;

  const CATOmxKeyValueBlock& GetAttrsToWrite() const;

  const CATPLMFTFilterOnAttrNodeDesc& GetAttrFilterDesc() const;

  const CATOmxArray<CATOmxKeyString>& GetListOfSelectCond() const;

private:
  CATOmxSR<CATPLMFlatTableRowToWriteInt> _sp;
};

template <> ExportedByCATPLMServicesItf CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMFlatTableRowToWrite>::manager();

#endif
