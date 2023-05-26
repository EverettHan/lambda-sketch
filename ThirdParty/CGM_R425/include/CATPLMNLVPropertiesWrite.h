// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATPLMNLVPropertiesWrite.h
//
//===================================================================
//
// Usage notes:
//    Specify options that can be set during the copy:
//    For references, options are:
//    KeepOwnership,KeepLock,KeepMaturity,KeepVersioning
//    For instances,options are:
//    KeepOwnership,KeepLock
//
//===================================================================
// June 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMNLVPropertiesWrite_H
#define CATPLMNLVPropertiesWrite_H

#include "CATPLMServicesItf.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxCollecManager.h"
#include "CATOmxArray.h"
#include "CATPLMOmxCollections.h"

class ExportedByCATPLMServicesItf CATPLMNLVPropertiesWrite
{
public:

  enum class eRIOptions
  {
    Unset = 1,
    Reset = 2,
    Inherit = 3
  };

  enum class eKROptions
  {
    Unset = 1,
    Keep = 2,
    Reset = 3
  };

  enum class eBoolOptions
  {
    Unset = 1,
    True = 2,
    False = 3
  };

  CATPLMNLVPropertiesWrite();
  ~CATPLMNLVPropertiesWrite();
  CATPLMNLVPropertiesWrite(const CATPLMNLVPropertiesWrite &);
  CATPLMNLVPropertiesWrite & operator =(const CATPLMNLVPropertiesWrite &);

  void KeepFamily();
  void ResetFamily();
  CATPLMNLVPropertiesWrite::eBoolOptions GetFamily() const;

  void KeepVersioning();
  void ResetVersioning();
  CATPLMNLVPropertiesWrite::eBoolOptions GetVersioning() const;

  void InheritLock();
  void ResetLock();
  CATPLMNLVPropertiesWrite::eRIOptions GetLock() const;

  void KeepConfiguration();
  void ResetConfiguration();
  CATPLMNLVPropertiesWrite::eKROptions GetConfiguration() const;

  void KeepMaturity();
  void ResetMaturity();
  CATPLMNLVPropertiesWrite::eKROptions GetMaturity() const;

  void KeepUpdateStamp();
  void ResetUpdateStamp();
  CATPLMNLVPropertiesWrite::eKROptions GetUpdateStamp() const;

  void SetOwner();
  void SetOrg();
  void SetCollabspace();
  void SetSov();

  void ResetOwner();
  void ResetOrg();
  void ResetCollabspace();
  void ResetSov();

  CATPLMNLVPropertiesWrite::eBoolOptions GetOwner() const;
  CATPLMNLVPropertiesWrite::eBoolOptions GetOrg() const;
  CATPLMNLVPropertiesWrite::eBoolOptions GetCollabspace() const;
  CATPLMNLVPropertiesWrite::eBoolOptions GetSov() const;

  CATOmxArray<int> GetOwnerships() const;

  void InheritEIN();
  void ResetEIN();
  CATPLMNLVPropertiesWrite::eRIOptions GetEIN() const;

  static HRESULT Convert(eRIOptions ieRIOptions, CATUnicodeString& oeRIOptionsCUS);
  static HRESULT Convert(eKROptions ieKROptions, CATUnicodeString& oeKROptionsCUS);
  static HRESULT Convert(eBoolOptions ieBoolOptions, CATUnicodeString& oeBoolOptionsCUS);

  static HRESULT Convert(const CATUnicodeString& ieRIOptionsCUS, eRIOptions& oeRIOptions);
  static HRESULT Convert(const CATUnicodeString& ieKROptionsCUS, eKROptions& oeKROptions);
  static HRESULT Convert(const CATUnicodeString& ieBoolOptionsCUS, eBoolOptions& oeBoolOptions);


private:

  eBoolOptions _family;
  eBoolOptions _versioning;

  eRIOptions _lock;
  eKROptions _configuration;

  eKROptions _maturity;
  eKROptions _updatestamp;
  CATOmxArray<int> _ownerships;

  eRIOptions _EIN;
};

#endif
