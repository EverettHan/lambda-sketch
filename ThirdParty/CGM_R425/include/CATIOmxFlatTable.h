#ifndef __CATIOmxFlatTable_H
#define __CATIOmxFlatTable_H

// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxHRESULT.h"
#include "CATOmxIter.h"
#include "CATOmxKernel.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxPair.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"


#define E_OMXFT_ROWNOTFOUND E_KEYNOTFOUND
#define E_OMXFT_ROWALREADYEXISTS E_FAIL
#define E_OMXFT_ROWDELETED E_ACCESSDENIED

class CATOmxStructDescription;

/**
* A very basic flat table implementation (in memory)
* It is a a collection of "rows" (a row is a collection of properties/(key,value) pairs)
*/
class CATIOmxFlatTable : public CATOmxSharable
{
public:
  /**
  * factory:
  * @param iDescription:
  *   description of the properties exposed by your objects (use CATOmxStructDescriptionBuilder to create one)
  * @param iUniqueKey:
  *   name of the property that uniquely identifies your objects
  */
  ExportedByCATOmxKernel static CATOmxSR<CATIOmxFlatTable> Create(const CATOmxStructDescription& iDescription, const CATOmxKeyString& iUniqueKey, unsigned int iFlags = 0);
  ExportedByCATOmxKernel static CATOmxSR<CATIOmxFlatTable> Create(const CATOmxStructDescription& iDescription, const CATOmxArray<CATOmxKeyString>& iCompositeUniqueKey, unsigned int iFlags = 0);

  /** retrieve the number of rows in this table (not including deleted rows)*/
  virtual CATINTPTR GetSize() const = 0;

  /**
  * Retrieve row given its unique id
  */
  virtual HRESULT GetUniqueRow(const CATOmxAny& iRowId, CATOmxKeyValueBlock& oRow) const = 0;

  /**
  * Retrieve rows wwith a specific property value
  * Notice that there can be several matches and they are returned in unspecified order
  * For strings: search is case sensitive and there is no wildcard
  * For doubles: do not use
  * Notice that an index is created "on the fly" if necessary
  */
  virtual CATOmxIter<const CATOmxKeyValueBlock> GetRows(const CATOmxKeyString& iKey, const CATOmxAny& iValue) const = 0;

  /**
  * Searchs rows which properties match given values ("AND")
  */
  virtual CATOmxIter<const CATOmxKeyValueBlock> GetRows(const CATOmxArray<CATOmxKeyString>& iKeys,const CATOmxAny& iValues) const = 0;

  /**
  * Retrieve all rows
  */
  virtual CATOmxIter<const CATOmxKeyValueBlock> GetRows() const = 0;

  /**
  * Load a row
  * If successfull, the row is added and its modification status is "None"
  * @return:
  *   E_INVALIDARG, iRow does not hold required "unique key" property
  *   E_OMXFT_ROWALREADYEXISTS
  *   E_OMXFT_ROWDELETED: this row is in "deleted" state (use ClearRowModificationStatus to reset this state)
  */
  virtual HRESULT LoadRow(const CATOmxKeyValueBlock& iRow) = 0;
  /**
  * Unload a row, modification state is reset if any.
  */
  virtual HRESULT UnloadRow(const CATOmxAny& iRowId) = 0;

  /**
  * Create a new row.
  * If successfull the row is added.
  * If the row was in "Deleted" state its new state will be "Updated" (with all attributes modified)
  * else its new state will be "Created"
  */
  virtual HRESULT CreateRow(const CATOmxKeyValueBlock& iRow) = 0;
  /**
  * Delete a row.
  * If successfull the row is removed
  * If the row was "Created" it new state will be "None"
  * else its new state will be "Deleted"
  */
  virtual HRESULT DeleteRow(const CATOmxAny& iRowId) = 0;

  /**
  * Update an existing row with given property values (can be incomplete)
  * If successfull row properties are modified
  * If the row was "Created" it remains in this state
  * else new state is "Updated" and modified properties are stored
  */
  virtual HRESULT UpdateRow(const CATOmxKeyValueBlock& iRow) = 0;

  /**
  * Remove all rows, modification state is also cleared.
  */
  virtual void Clear() = 0;

  enum RowModificationType { None, Created, Deleted, Updated };
  struct RowModificationStatus
  {
    RowModificationType Type;
    CATOmxOrderedOSet<CATOmxKeyString> ModifiedAttributes;
  };

  /**
  * retrieve modification status of a row
  */
  virtual HRESULT GetRowModificationStatus(const CATOmxAny& iRowId, RowModificationStatus& oStatus) const = 0;

  /**
  * Retrieve modification status of all "dirty" rows (which state is not "None")
  */
  virtual CATOmxIter<const CATOmxPair<CATOmxAny, RowModificationStatus> > GetDirtyRowsModificationStatus() const = 0;

  /**
  * Clear all rows modifications status
  * All rows state will become "None"
  */
  virtual void ClearRowsModificationStatus() = 0;

  /**
  * Clear row modification status
  * If successfull new state is "None"
  */
  virtual HRESULT ClearRowModificationStatus(const CATOmxAny& iRowId) = 0;
};

#endif
