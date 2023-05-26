/**
 * @fullreview SGT  SGT 01:06:27
 */
#
#ifndef CATDisconnectionSettings_H
#define CATDisconnectionSettings_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0ERROR.h"
#include "CATUnicodeString.h"
#include "CATSettingRepository.h"

class ExportedByJS0ERROR CATDisconnectionSettings 
{
  public: 
   CATDisconnectionSettings();
   ~CATDisconnectionSettings();
  /*
   * HRESULT ReadActivationState(int *oActivationState, int iFlags=0 , int *oFlags=NULL)=0;
   * Read the setting to tell  the stat is active or no
   * PARAMETERS 
   * int  *oActivationState
   *               !=0 => active
   *               ==0 => inactive
   *
   * int iFlags : let it to the value 0 for now
   * int *oFlags : let it to the value NULL for now
   * 
   */
  virtual HRESULT ReadActivation(int *oActivationState, int iFlags=0, int *oFlags=NULL);


  /*
   * HRESULT ReadInactivityDuration(int *oMaxInactivity, int iFlags=0, int *oFlags=NULL)=0;
   * Read the setting to tell  the stat is active or no
   * PARAMETERS 
   * int *oMaxInactivity 
   *               number of seconds of authorized user inactivity 
   *               if  user  is inactive longer than that CATIA session ends
   *
   * int iFlags : let it to the value 0 for now
   * int *oFlags : let it to the value NULL for now
   *
   */
  virtual HRESULT ReadInactivityDuration(int *oMaxInactivity, int iFlags=0, int *oFlags=NULL);


  /** 
   *  To write the settings
  **/


  /*
   * HRESULT WriteActivation(int iActivationState, int iFlags=0)=0;
   * Writes the setting to tell  the stat is active or no
   * PARAMETERS 
   * int  iActivationState
   *               !=0 => active
   *               ==0 => inactive
   *
   * int iFlags : let it to the value 0 for now
   * 
   *  NB : changing this value will impact the current session
   */
  virtual HRESULT WriteActivation(int iActivationState, int iFlags=0);

  /*
   * HRESULT WriteInactivityDuration(int iMaxInactivity, int iFlags=0)=0;
   * Writes the setting to tell  the stat is active or no
   * PARAMETERS 
   * int  iMaxInactivity 
   *               number of seconds of authorized user inactivity 
   *               if  user  is inactive longer than that CATIA session ends
   *
   * int iFlags : let it to the value 0 for now
   *
   *  NB : changing this value will not impact the current session
   */
  virtual HRESULT WriteInactivityDuration(int iMaxInactivity, int iFlags=0);

  virtual HRESULT Save( int iFlags=0);
  /**
   * To manage the settings administration
   */

   virtual HRESULT Lock(  int iFlags=0 );

   virtual HRESULT Unlock(  int iFlags=0 );
   

   virtual HRESULT IsLocked(char *oLockVal,int iFlags=0);

   virtual HRESULT ResetToAdminValues(int iFlags=0);
   virtual HRESULT ResetToDefautValues(int iFlags=0);

   virtual HRESULT Commit(int iFlags=0);
   virtual HRESULT Rollback(int iFlags=0);
   virtual HRESULT GetCATSettingInfo (CATSettingInfo & OutputSettingInfo) ;

   private: 
   int m_Version; // stores the read setting version
   
};
#endif
