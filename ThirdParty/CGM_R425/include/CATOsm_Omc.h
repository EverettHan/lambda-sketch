#ifndef __CATOsm_Omc_h__
#define __CATOsm_Omc_h__
#include "CATBaseUnknown.h"

class CATBaseUnknown;
class CATDocument;
class CATIContainer;
class CATUuid;
class _SEQUENCE_octet;
class CATIAModel;
/**
 * This class split the Osm_Omc dependencies
 */
class CATOsm_Omc {
public:
  virtual int SaveDoc (const char* FilePath, CATDocument* doc) = 0;
  virtual int LoadDoc( const char*  iPathName, CATDocument* iDocument ) = 0;
  /**
   * @see CATIACreateRootContainer
   */
  virtual CATBaseUnknown* CreateRootContainer( CATDocument* doc, const char *containerType,const char *interfaceID,const char *containerSuperType="") = 0;
  
  /**
   * @see CATChangeContainerUUID
   * 
   */
  virtual HRESULT ChangeContainerUUID( CATIContainer* iCont, CATUuid* iNewUuid) = 0;
  /**
   * @see CATResetContainer
   * 
   */
  virtual HRESULT ResetContainer(CATIContainer *iContainer) = 0;
 /**
   * Try to load the container 
   * @see CATIPersistStorage
   */ 
  virtual HRESULT LoadContainer(CATBaseUnknown *iContainer) = 0;
 /**
   * Try to load the container 
   * @see CATIPersistStorage
   */ 
  virtual HRESULT IsContainerLoaded(CATBaseUnknown *iContainer) = 0;


  virtual HRESULT ComposeCompleteName(const _SEQUENCE_octet & iLightName, _SEQUENCE_octet & oCompleteName, int & oAmbiguities, const CATDocument * iPreferredDocument = 0) =0 ;
};
#endif
