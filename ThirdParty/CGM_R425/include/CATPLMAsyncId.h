//===================================================================
// CATPLMAsyncId.h
//===================================================================
//
// Do not derive this class, there is no virtual destructor.
//
// CATPLMAsyncId is a projection of a CATPLMID.
// Contrary to CATPLMID, it can be partial, it means following properties may be empty:
//    - logicalid
//    - majorid
//
// The only mandatory properties are physicalid and type, otherwise the CATPLMAsyncId is considered as unset (UnsetMode).
// CATPLMAsyncId can have different modes, explained in the dedicated enum: AsyncIdMode
//
//===================================================================

#ifndef CATPLMASYNCID_H_
#define CATPLMASYNCID_H_

#include "CATPLMServicesItf.h"

#include "CATSysErrorDef.h"
#include "CATA5TCLIdentifierStatus.h"

#include "CATPLMID.h"
#include "CATPLMID_Any.h"
#include "CATPLMTypeIdClassificationEnum.h"
#include "CATPLMTypeId.h"
#include "CATPLMTypeH.h"

#include "CATOmxKeyString.h"
#include "CATWOmxBinaryStream.h"
#include "CATOmxArray.h"
#include "CATOmxOSet.h"

class CATPLMAsyncId;

extern const ExportedByCATPLMServicesItf CATPLMAsyncId   CATPLMAsyncId_Null;

class ExportedByCATPLMServicesItf CATPLMAsyncId
{
public:

  enum AsyncIdMode
  {
    PhysicalIdAndTypeIdMode,          // Stores only physicalid and type (legacy mode)
    SimplePLMIDMode,                  // Stores a simple PLMID (ie. the PLMID contains only one PLMID -> only one object)
    ComplexPLMIDMode,                 // Stores a complex PLMID (ie. the PLMID contains a path of PLMIDs -> multiple objects)
    PhysicalIdAndClassificationMode,  // Stores only physicalid and Classification
    PhysicalIdMode,                   // Stores only physicalid         
    UnsetMode                         // Stores nothing
  };

  CATPLMAsyncId();
  CATPLMAsyncId(const CATPLMID_Any& iPhysicalId, const CATPLMTypeId_Classification& iClassification, CATA5TCLIdentifierStatus::eError iStatus = CATA5TCLIdentifierStatus::eUndefined);
  CATPLMAsyncId(const CATPLMID_Any& iPhysicalId, const CATPLMTypeId& iTypeId, CATA5TCLIdentifierStatus::eError iStatus = CATA5TCLIdentifierStatus::eUndefined);
  CATPLMAsyncId(const CATPLMID& iPLMID, CATA5TCLIdentifierStatus::eError iStatus = CATA5TCLIdentifierStatus::eUndefined);

  CATPLMAsyncId(const CATPLMAsyncId &);
  CATPLMAsyncId & operator =(const CATPLMAsyncId &);

  const CATPLMID& GetPLMID() const { return _Plmid; };
  const CATPLMTypeId& GetTypeId() const { return _TypeId; };
  const CATPLMID_Any& GetPhysicalId() const { return _PhysicalId; };
  const CATPLMID_Any GetMajorId() const;
  const CATPLMID_Any GetLogicalId() const;
  const CATPLMTypeH GetTypeH() const;
  const CATPLMTypeId_Classification& GetClassification() const { return _Classification; };

  HRESULT Stream(CATWOmxBinaryStream & ioStream) const;
  HRESULT Unstream(CATWOmxBinaryStream & ioStream);
  static HRESULT Stream(const CATPLMID & iPLMID, CATWOmxBinaryStream & ioStream);
  static HRESULT Unstream(CATPLMID& oPLMID, CATWOmxBinaryStream & ioStream);

  HRESULT IsEqual(const CATPLMAsyncId & iOtherRRId, CATBoolean &oIsEqual) const;
  CATBoolean IsSet() const { return (_StatusAsyncID != UnsetMode) ? (TRUE) : (FALSE); }
  AsyncIdMode GetMode() const { return _StatusAsyncID; }

  CATBoolean IsBroken(CATA5TCLIdentifierStatus::eError& oErrorStatus);

  // Equals if same physicalid.
  /*
  *  0 if physical id is different from iOther's one<br>
  *  1 if physical id is equal to iOther's one<br>
  */
  int operator==(const CATPLMAsyncId &) const;

  /*
  *  1 if physical id is different from iOther's one<br>
  *  0 if physical id is equal to iOther's one<br>
  */
  inline int operator!=(const CATPLMAsyncId & iOtherPLMAsyncID) const { return this->Compare(iOtherPLMAsyncID) ? 1 : 0; }

  /**
  * Comparison of identifier, total order.
  *
  * @return
  *      -1 if physical id is is inferior to iOther's one<br>
  *       1 if physical id is is superior to iOther's one<br>
  *       0 if physical id is equal to iOther's one<br>
  */
  int Compare(const CATPLMAsyncId &) const;

private:
  // Methods
  void _Clone(const CATPLMAsyncId &);
  HRESULT _BuildStatusAsyncID();
  HRESULT _GetPhysicalIdAndTypeFromPLMID(const CATPLMID& plmid, CATPLMTypeId& oTypeId, CATPLMID_Any& ophysicalId);
  HRESULT _GetPLMMetaType(const CATPLMTypeId& iTypeId, CATPLMTypeId_Classification& oClassification) const;

  // Attributes
  CATPLMID_Any _PhysicalId;   // Used for: PhysicalIdAndTypeIdMode | SimplePLMIDMode | ComplexPLMIDMode
  CATPLMTypeId _TypeId;       // Used for: PhysicalIdAndTypeIdMode | SimplePLMIDMode
  CATPLMID _Plmid;            // Used for: SimplePLMIDMode | ComplexPLMIDMode
  CATPLMTypeId_Classification _Classification;

  AsyncIdMode _StatusAsyncID;

  CATA5TCLIdentifierStatus::eError _errorStatus;//if CATPLMID is null
};

#include "CATOmxCollecManager.h"
template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAsyncId>::manager();
typedef CATOmxArray<CATPLMAsyncId> CATPLMAsyncIds;
typedef CATOmxOSet<CATPLMAsyncId, CATOmxDefaultCollecManager<CATPLMAsyncId>::manager> CATPLMAsyncIdSet;
#endif /* CATPLMASYNCID_H_ */
