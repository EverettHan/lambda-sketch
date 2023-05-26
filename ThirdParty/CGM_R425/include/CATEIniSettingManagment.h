/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef CATEIniSettingManagment_H
#define CATEIniSettingManagment_H

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */
   

// System Framework
#include "CATBaseUnknown.h"
#include "CATEventSubscriber.h"
class CATSettingRepository;

#include "CATInteractiveInterfaces.h"

/**
  * Adapter class for the CATIIniSettingManagment interface.
  * <b>Role</b>: You must derive this class and the derived class is a Data Extension
  * of your component. This component is the object which controls the setting file. 
  * @see CATIIniSettingManagment, CATSettingRepository , CATIniCleanerSettingCtrl
  */
class ExportedByCATInteractiveInterfaces CATEIniSettingManagment: public CATBaseUnknown
{
public:
  
  /** 
    * Constructs an instance.
    * @param iSettingFileName
    * The name of the setting file.
    */
  CATEIniSettingManagment(const char * iSettingFileName);
  
  /**
  * Desctructs an instance
  * DO no use this method.
  */
  virtual ~CATEIniSettingManagment();
  
  /** 
   * Committes the attribute values.
   * Do not overwrite this method. 
   */
  virtual  HRESULT   Commit()             ;

  /** 
   * Restores the administration attribute values.
   * Do not overwrite this method. 
   */
  virtual  HRESULT   ResetToAdminValues() ;
  /** 
   * Retrieves the last committed attribute values.
   * Do not overwrite this method. 
   */
  virtual  HRESULT   Rollback()           ;
  /** 
   * Saves the attribute values on the disk.
   * Do not overwrite this method. 
   */
  virtual  HRESULT   SaveRepository()     ;
  
  
private:
  
  CATSettingRepository *   _pSettingRep     ;
  
  void RepositoryModified (CATCallbackEvent  iEvent,
                           void             *iPublisher,
                           CATNotification  *iNotification,
                           CATSubscriberData iUsefulData,
                           CATCallback       iCallBack );
  
  // Default constructor
  // Set as private to prevent from compiler automatic creation as public.
  CATEIniSettingManagment();
  
  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATEIniSettingManagment(const CATEIniSettingManagment &iObjectToCopy);
  CATEIniSettingManagment& operator=(const CATEIniSettingManagment&);
  
};
#endif
