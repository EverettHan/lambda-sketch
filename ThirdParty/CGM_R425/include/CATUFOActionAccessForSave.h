#ifndef CATUFOActionAccessForSave_H
#define CATUFOActionAccessForSave_H
/**
 * @level Protected
 * @usage U1
 */

#include "ExportedByCATPLMIdentification.h"
#include "IUnknown.h"
#include "CATComponentId.h"
#include "CATBoolean.h"
#include "CATOmxVector.h"
#include "CATOmxSharable.h"
#include "CATPLMID.h"

class CATUFOLogElementaryAction;
class CATUFOOccurrenceEquivalence;
class CATPLMIDMappingTable;

/**
* UFO Action access for save.
*/
class CATUFOActionAccessForSave : public CATOmxSharable
{
public:

  inline CATBoolean IsCreate() const { return _IsCreate; }
  inline CATBoolean IsUpdate() const { return _IsUpdate; }
  inline CATBoolean IsDelete() const { return _IsDelete; }
  inline CATBoolean IsRoot()   const { return _IsRoot; }

  /*
  * Get the PLMID of the action
  *
  * @param oPLMID
  *   the PLMID
  *
  * @return
  *   S_OK if the action was correctly initialised
  *   E_FAIL otherwise
  */
  inline HRESULT GetPLMID(CATPLMID & oPLMID) const
  {
    if (!_PLMID) return E_FAIL;
    oPLMID = _PLMID;
    return S_OK;
  }

  /*
  * Get the derived from plmid if any
  *
  * @param oDerivedFrom
  *   the derived from plmid
  *
  * @return
  *   S_OK if everything is OK and a derived from plmid was found
  *   S_FALSE if everything is OK and no derived from plmid was found
  *   E_UNEXPECTED otherwise
  */
  inline HRESULT GetDerivedFrom(CATPLMID & oDerivedFrom) const
  {
    if (!_DerivedFrom) return S_FALSE;
    oDerivedFrom = _DerivedFrom;
    return S_OK;
  }

  friend class CATPLMUFOLogSaver;
  friend class CATUFOUserActionAccessForSave;
  friend class CATUFOLogAccessForSave;

  CATPLMID GetOwner() const { return _Owner; }
  CATPLMID GetInstanceOf() const { return _InstanceOf; }

  CATUFOActionAccessForSave();
  CATUFOActionAccessForSave(const CATUFOLogElementaryAction& iAction);
  ~CATUFOActionAccessForSave();

  void AddEquivalence(CATUFOOccurrenceEquivalence& iEquivalence);

  void ApplyPLMIDMappingTable(const CATPLMIDMappingTable& table);

private:
  CATOmxVector<CATUFOOccurrenceEquivalence> _Equivalences;

  void FixOwnerAndInstanceOf();
  void SetPLMID(const CATPLMID & iPLMID) { _PLMID = iPLMID; }
  void SetCreate() { _IsCreate = TRUE; }
  void SetUpdate() { _IsUpdate = TRUE; }
  void SetDelete() { _IsDelete = TRUE; }
  void SetRoot() { _IsRoot = TRUE; }
  void SetOwner(const CATPLMID & iPLMId) { _Owner = iPLMId; }
  void SetInstanceOf(const CATPLMID & iPLMId) { _InstanceOf = iPLMId; }

  CATPLMID _PLMID;
  CATPLMID _DerivedFrom;
  CATPLMID _Owner;
  CATPLMID _InstanceOf;

  CATBoolean _IsCreate;
  CATBoolean _IsUpdate;
  CATBoolean _IsDelete;
  CATBoolean _IsRoot;
};

#endif

