#ifndef CATOmbLocalSaveSessionInfoServices_H
#define CATOmbLocalSaveSessionInfoServices_H


/**
* @level Protected 
* @usage U1
*/
#include "CATOmbSwitchEngine.h"
#include "IUnknown.h"

class CATOmbLocalSaveSessionInfo;
class CATUnicodeString;

/**
* This class allows retrieving an unique instance of CATOmbLocalSaveSessionInfo object. 
*
*/
class ExportedByCATOmbSwitchEngine CATOmbLocalSaveSessionInfoServices
{
 public:
  
  /** 
  * Retrieves the unique instance of the CATOmbLocalSaveSessionInfo object
  *  
  * @param iLocalSaveDirectory [in]
  *   Directory in which the LocalSave Data has been/will be saved
  * @param opSessionInfo [out]
  *   The CATOmbLocalSaveSessionInfo object
  *
  * @return
  *   <code>S_OK</code> New instance has been created
  *   <code>S_FALSE</code> Previous instance has been returned
  *
  */
  static HRESULT RetrieveOmbLocalSaveSessionInfo(const CATUnicodeString& iLocalSaveDirectory, CATOmbLocalSaveSessionInfo*& opSessionInfo);
  
  
  /** 
  * Deletes the CATOmbLocalSaveSessionInfo instance at the end of the LocalSaveSession  
  *
  * @return
  *   <code>S_OK</code> always
  *
  */
  static HRESULT RemoveOmbLocalSaveSessionInfo();
};

#endif


