// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPLMRepoPrivilege.h
// Provide implementation to interface
//    CATIPLMCompImportRecordWrite
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   IMPLEMENTATION
//   TIE: CATIPLMCompImportRecordWrite
//End CAA2 Wizard Generation Report
//
//  May 2007  Creation: Code generated by the CAA wizard  TBF
//===================================================================
#ifndef CATPLMRepoPrivilege_H
#define CATPLMRepoPrivilege_H

#include "CATIPLMCompImportRecordWrite.h"

#include "CATPLMServicesItf.h"

class CATPLMID;
class CATPLMCEStamp;

//-----------------------------------------------------------------------
/**
* @level Protected
* @usage U2
*/

/** @nodoc */
class ExportedByCATPLMServicesItf CATPLMRepoPrivilege
{
  // CATDeclareClass;

public:
  /** @nodoc */
  enum PrivilegeValue {
    /** @nodoc */
    Unknown = 0,
    /** @nodoc */
    Full = 1,
    /** @nodoc */
    EE = 2,
    /** @nodoc */
    None = 3
  };

  CATPLMRepoPrivilege(PrivilegeValue iValue = Full) { _privilegeValue = iValue; }
  ~CATPLMRepoPrivilege() { _privilegeValue = Unknown; };

  /** @nodoc */
  HRESULT IsNULL() const { return (_privilegeValue == Unknown) ? S_OK : S_FALSE; };
  /** @nodoc */
  HRESULT SetPrivilegeValue(PrivilegeValue iValue) { _privilegeValue = iValue; return S_OK; };
  /** @nodoc */
  HRESULT IsEEBlockEditable() const { if (_privilegeValue == Unknown) return E_FAIL; return (_privilegeValue == Full || _privilegeValue == EE) ? S_OK : S_FALSE; };
  /** @nodoc */
  HRESULT IsCDBlockEditable() const { if (_privilegeValue == Unknown) return E_FAIL; return (_privilegeValue == Full) ? S_OK : S_FALSE; };
  /** @nodoc */
  HRESULT GetPrivilegeValue(PrivilegeValue &oValue) const { oValue = _privilegeValue; return S_OK; };

private:
  PrivilegeValue _privilegeValue;
};

extern const ExportedByCATPLMServicesItf CATPLMRepoPrivilege CATPLMRepoPrivilege_Full;

//-----------------------------------------------------------------------

#endif
