//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATCacheSetting                                                 
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation fevrier  2003                                 adt         	
//===========================================================================
#ifndef __CATISYSCACHESETTINGATT
#define __CATISYSCACHESETTINGATT
#include "JS0MRSHL.h"
#include "CATBaseUnknown.h"   
#include "CATISysSettingController.h"

// COPYRIGHT DASSAULT SYSTEMES 2003


class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0MRSHL IID IID_CATISysCacheSettingAtt;
#else
extern "C" const IID IID_CATISysCacheSettingAtt;
#endif




/**
* Interface to handle the parameters of the cache.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the cache. 
* <br>This interface defines:
* <ul>
* <li>A method to set each parameter</li>
* <li>A method to get the value of each parameter</li>
* <li>A method to lock/unlock each parameter</li>
* <li>A method to retrieve the informations concerning each parameter</li>
* </ul>
*/
class ExportedByJS0MRSHL CATISysCacheSettingAtt : public CATBaseUnknown
{
  CATDeclareInterface;
  
public :
/**
 * Retrieves the value of the cache maximum size.
 * <br><b>Role</b>: Retrieves the value of the cache maximum size in Mo
 * @param oSize
 *	The maximum allowed size of the cache in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetCacheMaxSizeMo (unsigned int &oSize)=0;

/**
 * Sets the value of the cache maximum size.
 * <br><b>Role</b>: Sets the value of the cache maximum size in Mo
 * @param oSize
 *	The maximum allowed size of the cache in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetCacheMaxSizeMo (unsigned int iSize)=0;

/**
 * Retrieves informations about the parameter cache maximum size.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetCacheMaxSizeMoInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the paramater Cache maximum size.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetCacheMaxSizeMoLock (unsigned char iLock)=0;


/**
 * Retrieves the cache's activation state.
 * @param oMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   turned off
 * 	<br><tt>1:</tt>   turned on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetActivationMode (unsigned char &oMode)=0;

/**
 * Turns ON/OFF the cache activation.
 * <br><b>Role</b>: Activates or desactivates the cache mechanism.
 * @param iMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   to turn off
 * 	<br><tt>1:</tt>   to turn on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetActivationMode (unsigned char iMode)=0;

/**
 * Retrieves the state of the parameter cache activation.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetActivationModeInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the cache activation mode.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetActivationModeLock (unsigned char iLock)=0;

/**
 * Retrieves if the cache size control is activated.
 * @param oMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   turned off
 * 	<br><tt>1:</tt>   turned on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetSizeControl (unsigned char &oMode)=0;

/**
 * Turns ON/OFF the cache size control mechanism.
 * <br><b>Role</b>: Activates or desactivates the cache size control mechanism.
 * It is used in conjunction with the maxixum allowed cache size. If it is 
 * turned off, the cache size has no limit.
 * @param iMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   to turn off
 * 	<br><tt>1:</tt>   to turn on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetSizeControl (unsigned char iMode)=0;

/**
 * Retrieves the state of the parameter cache size control.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetSizeControlInfo (CATSettingInfo* oInfo)=0;
  
/** 
 * Locks or unlocks the cache size control mode.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetSizeControlLock (unsigned char iLock)=0;

/**
 * Retrieves if the timestamp control is activated.
 * <br><b>Role</b>: If the timestamp control is turned on, the cache will 
 * verify if the cached object is uptodate with the master object. If not a
 * new cached view will be generated. 
 * <br> If the timestamp control is turned off, the cache will consider that 
 * the cached views are always uptodate with their master object.
 * @param oMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   turned off
 * 	<br><tt>1:</tt>   turned on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetTimestampMode (unsigned char &oMode)=0;

/**
 * Turns ON/OFF the cache timestamp control mechanism.
 * <br><b>Role</b>: If the timestamp control is turned on, the cache will 
 * verify if the cached object is uptodate with the master object. If not a
 * new cached view will be generated. 
 * <br> If the timestamp control is turned off, the cache will consider that 
 * the cached views are always uptodate with their master object.
 * @param iMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   to turn off
 * 	<br><tt>1:</tt>   to turn on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetTimestampMode (unsigned char iMode)=0;

/**
 * Retrieves the state of the parameter timestamp control. 
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetTimestampModeInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the timestamp control mode.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetTimestampModeLock (unsigned char iLock)=0;

  

/**
 * Retrieves if the timestamp is expressed in UTC or local time.
 * <br><b>Role</b>: If the timestamp format is set to TRUE, then the time used
 * used as timestamp by the cache is expressed in UTC format (GMT), in the 
 * other case the local time is used. The default format is local time.
 * @param oMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   timestamps are in local time
 * 	<br><tt>1:</tt>   timestamps are in UTC.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetUTCTimeFormat (unsigned char &oMode)=0;

/**
 * Sets the the cache timestamp format in UTC.
 * <br><b>Role</b>: If the timestamp format is set to TRUE, then the time used
 * used as timestamp by the cache is expressed in UTC format (GMT), in the 
 * other case the local time is used. The default format is local time.
 * @param iMode
 *	<b>Legal values</b>:
 *	<br><tt>0:</tt>   to activate the Local time format.
 * 	<br><tt>1:</tt>   to activate the UTC format.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetUTCTimeFormat (unsigned char iMode)=0;

/**
 * Retrieves the state of the parameter timestamp format.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetUTCTimeFormatInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the timestamp format.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetUTCTimeFormatLock (unsigned char iLock)=0;

  
/**
 * Retrieves the cache local path.
 * <br><b>Role</b>: Retrieves the value of the cache local path. 
 * If the local path is defined with environment variables then this 
 * method return the expansed form. The unexpansed form can be retrieved 
 * with @href #GetLocalPathSymb.
 * @param oLocalPath
 *       the local path of the cache.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetLocalPath( CATUnicodeString **oLocalPath)=0;

/**
 * Retrieves the cache local path.
 * <br><b>Role</b>: Retrieves the cache local path in a symbolic format.
 * If the local path is defined with environment variables then this 
 * method return the literal form for example ${CATCache}.
 * @param oLocalPath
 *       the local path of the cache.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetLocalPathSymb (CATUnicodeString ** oLocalPath)=0;

/**
 * Sets the cache local path.
 * <br><b>Role</b>: Sets the cache local path in a symbolic format.
 * @param iLocalPath
 *       the local path of the cache.
 * @param oNew
 *       not to be used. Reserved for internal use.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetLocalPath (CATUnicodeString  &iLocalPath,
				int *oNew=0)=0;

/**
 * Retrieves the state of the parameter cache local Path.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetLocalPathInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the cache local path.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetLocalPathLock(unsigned char iLock)=0;
  



/**
 * Retrieves the session cache path.
 * <br><b>Role</b>: Retrieves the value of the session cache  path. 
 * If the session cache path is defined with environment variables then this 
 * method return the expansed form. The unexpansed form can be retrieved 
 * with @href #GetSessionCachePathSymb.
 * @param oSessionPath
 *       the path of the session cache.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetSessionCachePath( CATUnicodeString **oSessionPath) =0;

/**
 * Retrieves the session cache path.
 * <br><b>Role</b>: Retrieves the session cache path in a symbolic format.
 * If the session  path is defined with environment variables then this 
 * method return the literal form for example ${CATCache}.
 * @param oSessionPath
 *       the local path of the cache.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetSessionCachePathSymb (CATUnicodeString ** oSessionPath)=0;

/**
 * Sets the session cache path.
 * <br><b>Role</b>: Sets the session cache path in a symbolic format.
 * @param iSessionPath
 *       the local path of the cache.
 * @param oNew
 *       not to be used. Reserved for internal use.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetSessionCachePath (CATUnicodeString  &iSessionPath)=0;

/**
 * Retrieves the state of the parameter session cache Path.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetSessionCachePathInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the session cache path.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetSessionCachePathLock(unsigned char iLock)=0;
  







/**
 * Retrieves the cache release paths.
 * <br><b>Role</b>: Retrieves the cache release paths.
 * If the release paths has been defined with environment variables then this 
 * method return the expansed form.
 * @param oNbDir
 *       the number of directories in the release path.
 * @param oRelPath
 *       the method allocates an array of pointer of CATUnicodeString of
 *        oNbDir elements that must be desallocated by the caller.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetReleasePath (unsigned int &oNbDir, 
				  CATUnicodeString  **&oLocalPath)=0;
/**
 * Retrieves the cache release paths.
 * <br><b>Role</b>: Retrieves the cache release paths in a symbolic format.
 * If the release paths has been defined with environment variables then this 
 * method return the literal form for example ${CATCache}.
 * @param oNbDir
 *       the number of directories in the release path.
 * @param oRelPath
 *       the method allocates an array of pointer of CATUnicodeString of
 *        oNbDir elements that must be desallocated by the caller.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetReleasePathSymb (unsigned int &oNbDir, 
				      CATUnicodeString  **&oRelPath)=0;

/**
 * Sets the cache release paths.
 * <br><b>Role</b>: Sets the cache release paths in a symbolic format.
 * @param iNbDir
 *       the number of directories in the release path.
 * @param iRelPath
 *       an array of pointer of CATUnicodeString of iNbDir elements. 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetReleasePath (unsigned int iNbDir, 
				  CATUnicodeString  **iRelPath)=0;

/**
 * Retrieves the state of the parameter cache release paths. 
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetReleasePathInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the cache release paths. 
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetReleasePathLock (unsigned char iLock)=0;
  


/**
 * Retrieves the value of the released voxel parameter.
 * @param oVoxel
 *      the released voxel.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetReleasedVoxel (float &oVoxel)=0;

/**
 * Sets the value of the released voxel parameter.
 * @param iVoxel
 *      the released voxel.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetReleasedVoxel (float iVoxel)=0;

/**
 * Retrieves the state of the parameter released voxel.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetReleasedVoxelInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the paramater released voxel.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetReleasedVoxelLock (unsigned char iLock)=0;
  


/**
 * Retrieves the value of the LOD generation mode.
 * @param oMode
 *      the LOD generation mode for the cache content.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT GetLODMode (unsigned char  &oMode)=0;

/**
 * Sets the value of the LOD generation mode.
 * @param oMode
 *      the LOD generation mode for the cache content.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
  virtual HRESULT SetLODMode (unsigned char  iMode)=0;


/**
 * Retrieves the state of the LOD generation mode.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT GetLODModeInfo (CATSettingInfo* oInfo)=0;

/** 
 * Locks or unlocks the LOD generation mode.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
  virtual HRESULT SetLODModeLock (unsigned char iLock)=0;

};




#endif


