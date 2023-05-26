#ifndef CATOmbSessionCapability_H
#define CATOmbSessionCapability_H

/*
* CATOmbSessionCapability
* 
* This class will give you access to the information of what are the capability of the session.
* Use the setter and getter to get or set these capabilities
* This API is based on CATSysSettingRepository but offer a memory cache to enhance performance.
* See available sessionCapabilityNames in omb_cst.h, section OMB Session Capabilities keywords :
* omb_cst().OMB_Outliner => Boolean
* omb_cst().OMB_AccessMode => enum RepRefDataAccess

*/

#include "IUnknown.h"
#include "CATSysBoolean.h"
#include "AD0XXBAS.h"
class CATOmxKeyString;
class CATOmxKeyValueBlock;


class ExportedByAD0XXBAS CATOmbSessionCapability
{
public:
  /*
  * Getter
  * iSessionCapabilityName : name of the capability
  * oCapabilityValue : the capability value.
  * return
          S_OK : the capability is set
          S_FALSE : the capability is set but a data-loosing cast has to be done (int to boolean for instance)
          E_FAIL : capability not available or unknown
  */
  static HRESULT GetCapability(const CATOmxKeyString& iSessionCapabilityName, CATBoolean& oCapabilityValue);
  static HRESULT GetCapability(const CATOmxKeyString& iSessionCapabilityName, int& oCapabilityValue);

  /*
  * SETTER
  * iSessionCapabilityName : name of the capability
  * iIsCapabilityAvailable : TRUE if capability available else FALSE
  *
  * return 
  *         S_OK if capability availableness well recorded
  *         E_FAIL if record failed
  */

  static HRESULT SetCapability(const CATOmxKeyString& iSessionCapabilityName, CATBoolean iIsCapabilityAvailable);
  static HRESULT SetCapability(const CATOmxKeyString& iSessionCapabilityName, int iCapabilityValue);

private:
  static CATOmxKeyValueBlock _keyValueBlock;
  static void Init();
};



#endif // CATOmbSessionCapability_H

