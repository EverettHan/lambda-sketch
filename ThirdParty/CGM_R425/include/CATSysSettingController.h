/* -*-c++-*- */
#ifndef CATSysSettingController_H
#define CATSysSettingController_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "CATEventSubscriber.h"   // Derive from CATEventSubscriber
#include "CATDataType.h"          // For CATULONG32
#include "JS0SETT.h"
#include "CATCallbackManager.h"
#include "CATSettingInfo.h"

class CATSettingRepository;
class CATString;
class CATUnicodeString;
class CATSysParamMap;
class CATSysSettingRepository;

/**
 * Adapter class to implement setting controller C++ interfaces.
 * <b>Role</b>: CATSysSettingController should be derived by a data extension 
 * class which is part of your setting controller component to help implement 
 * two interfaces:
 * <ol>
 *  <li>@href CATISysSettingController </li>
 *  <li>Your setting controller interface</li>
 * </ol>
 * <p><It offers the implementations of the CATISysSettingController methods:
 * <ul>
 *  <li>@href #Commit </li>
 *  <li>@href #Rollback </li> 
 *  <li>@href #ResetToAdminValues </li>
 *  <li>@href #SaveRepository </li>
 * </ul>
 * <p>You usually should not re-implement these methods, except if you create
 * a bufferized setting controller. Refer to the CAA Encyclopedia to know
 * about such controllers.</p>
 * <p>CATSysSettingController also offers you a couple of <code>ReadAttr/WriteAttr</code> methods
 * that encapsulates the access to the setting repository for each setting attribute supported type:</p>
 * <ul>
 *  <li>A pointer to, or a table of pointers to @href CATBaseUnknown </li>
 *  <li>A pointer to, or a table of pointers to @href CATString </li>
 *  <li>A pointer to, or a table of pointers to @href CATUnicodeString </li>
 *  <li>A table of pointers to simple types: char, double, float, int, short, and unsigned int</li>
 * </ul>
 * <p>Use these methods when implementing your setting controller interface.</p>
 * <p>CATSysSettingController offers some other methods to implement 
 * <ul>
 *  <li>@href #Initialize
 *   <br>Re-implemement it with bufferized setting controller only
 *  </li>
 *  <li>@href #GetInfo
 *   <br>Use it to implement the <code>GetXxxInfo</code> methods of your setting controller
 *  </li>
 *  <li>@href #Lock and @href #Unlock
 *   <br>Use them to implement the <code>SetXxxLock</code> methods of your setting controller
 *  </li>
 * </ul>
 * <p>CATSysSettingController defines events you can use to warn subscriber that either:
 * <ul>
 *  <li>The setting repository managed by the setting controller is updated:
 *   the SettingCtrl_Updated event is automatically sent
 *  </li>
 *  <li>A given setting attribute is updated:
 *   use the Param_Updated to send such event for the appopriate setting attribute.
 *  </li>
 * </ul>
 * @see CATSettingRepository, CATISysSettingController
 */
class ExportedByJS0SETT CATSysSettingController : public CATEventSubscriber
{
  CATDeclareClass;
  friend  class CATUserSettingsManager;
  friend  class CATSettingRepository;
  friend  class CATSysSettingRepository;
  friend  class CATSysTOEditor;
  friend  class CATCacheSetting;
  friend  class CATSysDLNameSettingCtrl;
  friend  class CATCafGeneralSettingCtrl;
  friend  class CATCafGeneralSessionSettingCtrl;
  friend  class CATDrmCredentialsSettingCtrl;
  friend  class CATCAfrPreferencesManager;

public :
/**
 * Declares the SettingCtrl_Updated event for a global update of the setting 
 * repository managed by the setting controller.
 * <br><b>Role</b>: A global update of the setting repository managed by the 
 * setting controller happens, and the SettingCtrl_Updated event is sent,
 * whenever one of the methods @href #Commit, @href #Rollback, 
 * @href #SaveRepository and @href #ResetToAdminValues are called. 
 * 
 */
   CATDeclareCBEvent(SettingCtrl_Updated);

/**
 * Declares the Param_Updated event for an attribute update in the setting repository managed by the setting controller.
 * <br><b>Role</b>: A setting attribute update happens whenever the Set method 
 * that deals with this attribute is called. This is not automatic. You need to 
 * dispatch this event in that Set method
 * if you want to warn subscribers that this parameter is updated. 
 */
  CATDeclareCBEvent(Param_Updated);

public :
  virtual ~CATSysSettingController();
  

/**
 * Makes a memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Commit</code> saves the current values of the setting
 * attributes managed by the setting controller in a specific memory area.
 * Successive calls to <code>Commit</code> overwrite the memory area.
 * The values saved by the last call to <code>Commit</code> can be restored from
 * that memory area using the @href #Rollback method.
 * @param iNoEvent [in]
 *	Reserved for internal use. Do not use. Should always be set to 0
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Commit(int iNoEvent=0);

/**
 * Restores the last memory copy of the setting attribute values.
 * <br><b>Role</b>: <code>Rollback</code> restores the values of the 
 * setting attributes managed by the setting controller from the
 * memory area.
 * All values of the 
 * setting attributes managed by the setting controller modified since the last
 * call to @href #Commit are restored to the values they had when this last 
 * @href #Commit was called.
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Rollback();

/**
 * Restores the administrated values of the attributes.
 * <br><b>Role</b>: <code>ResetToAdminValues</code> restores all
 * the values of the setting attributes managed by the setting controller
 * to either the values set by the setting administrator, or to their default 
 * values if the setting administrator did not change them. 
 * @param iAttList [in]
 *	Reserved for internal use. Do not use. Should always be set to NULL
 * @param iNbAtt [in]
 *	Reserved for internal use. Do not use. Should always be set to 0
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT ResetToAdminValues(char** iAttList, int iNbAtt);
  

/**
 * Makes a persistent copy of the setting attribute values on file.
 * <br><b>Role</b>: <code>SaveRepository</code> saves the current values of the
 * setting attributes managed by the setting controller in a setting repository 
 * file.
 * To avoid inconsistencies, <code>SaveRepository</code> first saves the values 
 * in the memory area used by the @href #Commit method by calling @href #Commit 
 * before writing the values in the setting repository file.
 * @param iTmp [in]
 *	Reserved for internal use. Do not use. Should always be set to NULL
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT SaveRepository(const char *itmp=NULL);
 


protected:
/**
 * Initializes the setting controller.
 * <br><b>Role</b>: Initializing a setting controller may be necessary
 * if you need to create a bufferized setting controller.
 * Some setting attributes may be bufferized, that is, the setting controller
 * reads and keeps their values in a buffer without needing to read the setting 
 * repository whenever it is asked for the values of these setting attributes.
 * The first call to the Get method of a bufferized setting attribute value 
 * initializes the buffer from the setting repository, a call to a Set method 
 * updates the buffer, and a flag is set up and managed to indicate whether the 
 * bufferized value is up-to-date.
 * The flag can be a data member of the setting controller (unsigned char) per 
 * bufferized attribute. This flag is read by the attribute Get method to 
 * determine whether the value is up-to-date, and accesses the setting 
 * repository if it is not. 
 * This value may be out-of-date when the @href #RollBack and 
 * @href #ResetToAdminValues methods are called. The setting controller must 
 * subscribe to @href #Rollback and @href #Reset events to change the flag to 
 * "out-of-date", and the next call to Get will access the setting repository
 * to update the buffer value and the flag.
 * <p><code>Initialize</code> is always called when the setting controller is 
 * instantiated.
 * Initializing the setting controller means initializing the setting attribute 
 * values in the buffer by calling the Get methods of all the bufferized setting
 * attributes.
 * Redefine <code>Initialize</code> implementation if you want to bufferize one 
 * or several setting attributes.
 * The default implementation of <code>Initialize</code> for non-bufferized 
 * setting controllers returns S_OK without initializing anything.</p>
 * @return
 * <b>Legal values</b>: S_OK on success, and E_FAIL otherwise
 */
  virtual HRESULT Initialize();
    
/**
 * Constructs an empty setting controller.
 * @param iSettingName [in]
 *  The name of the setting repository that the setting controller is intended 
 *   to handle
 */
  CATSysSettingController ( const char *iSettingName);
  


/**
 * Retrieves the value of a setting attribute made up of a pointer to 
 * CATBaseUnknown.
 * <br><b>Role</b>: Retrieves, using its name, the value of an attribute 
 * made up of a pointer to a CATBaseUnknown instance. A pointer to an intialized
 * and constructed object of type CATBaseUnknown must be given as argument,
 * because this object is used to set the default value of the attribute, if it 
 * does not yet exist. In this last case, the method calls WriteSetting to
 * initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	A pointer on an initialized and constructed CATBaseUnknown instance. 
 *      If the attribute has not been yet created, then <tt>ioAttrValue</tt> 
 *      is used as default, otherwise <tt>ioAttrValue</tt> is overwritten by
 *      the retrieved value.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success 
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, CATBaseUnknown * ioAttrValue);

/**
 * Sets the value of a setting attribute made up of a pointer to CATBaseUnknown.
 * <br><b>Role</b>: Sets the value of an attribute
 * made up of a pointer to a CATBaseUnknown instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than
 *	or equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	A pointer to an initialized and constructed CATBaseUnknown instance 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATBaseUnknown *iAttrValue);



/**
 * Retrieves the value of a setting attribute made up of an array of pointers to CATBaseUnknown.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of pointers to 
 * constructed CATBaseUnknown instances, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than
 *	or equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of pointers to initialized and constructed CATBaseUnknown instances.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements of 
 *	<tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, CATBaseUnknown ** ioAttrValue, 
		     CATLONG32 iSize);

/**
 * Sets the value of a setting attribute made up of an array of pointers to CATBaseUnknown.
 * <br><b>Role</b>: Sets the values of each element of the array making up the
 * attribute. Each of these elements is a pointer to a constructed 
 * CATBaseUnknown instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of pointers to initialized and constructed CATBaseUnknown instances
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATBaseUnknown **iAttrValue,  
		      CATLONG32 iSize);



/**
 * Retrieves the value of a setting attribute made up of a pointer to CATString.
 * <br><b>Role</b>: Retrieves, using its name, the value of an attribute 
 * made up of a pointer to a CATString instance. A pointer to an intialized and 
 * constructed object of type CATString must be given as argument, because this
 * object is used to set the default value of the attribute, if it does not yet 
 * exist. In this last case, the method calls WriteSetting to initialize the 
 * setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	A pointer on a constructed CATString. If the attribute has not
 *	been yet created, then <tt>ioAttr</tt> is used as default values,
 *	otherwise <tt>ioAttrValue</tt> is overwritten by the retrieved value.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, CATString * ioAttrValue);

/**
 * Sets the value of a setting attribute made up of a pointer to CATString.
 * <br><b>Role</b>: Sets the value of an attribute
 * made up of a pointer to a CATString instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than
 *	or equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	A pointer to an initialized CATString instance 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATString * iAttrValue);



/**
 * Retrieves the value of a setting attribute made up of an array of pointers to CATString.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of pointers 
 * to constructed CATString, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of pointers to initialized and constructed CATString instances.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char*iAttrName, CATString **ioAttrValue,
		     CATLONG32 iSize);

/**
 * Sets the value of a setting attribute which is an array of CATString.
 * <br><b>Role</b>: Sets the values of each element of the array making up the
 * attribute. Each of these elements is a pointer to a constructed 
 * CATString instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of pointers to initialized and constructed CATString instances
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATString ** iAttrValue, 
		      CATLONG32 iSize);


/**
 * Retrieves the value of a setting attribute made up of a pointer to CATUnicodeString.
 * <br><b>Role</b>: Retrieves, using its name, the value of an attribute 
 * constituted by one CATUnicodeString. A pointer on a intialized and constructed
 * object of type CATUnicodeString must be given as argument, because this object
 * is used to set the default value of the attribute, if it does not yet exist.
 * In this last case the method calls WriteAttr () to initialize the setting 
 * attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	A pointer to an initialized and constructed CATUnicodeString instance.
 *	If the attribute has not been yet created, then <tt>ioAttrValue</tt>
 *	is used as default value, otherwise <tt>ioAttrValue</tt> is overwritten 
 *	by the retrieved value.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, CATUnicodeString * ioAttrValue);

/**
 * Sets the value of a setting attribute made up of a pointer to 
 * CATUnicodeString.
 * <br><b>Role</b>: Sets the value of an attribute
 * made up of a pointer to a CATUnicodeString instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	A pointer to an initialized and constructed CATUnicodeString instance.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATUnicodeString * iAttrValue);


/**
 * Retrieves the value of a setting attribute made up of an array of pointers to CATUnicodeString.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of pointers 
 * to constructed CATUnicodeString, because it is used to set the default value 
 * of the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than 
 *	or equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of pointers to initialized and constructed CATUnicodeString 
 *      instances
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, CATUnicodeString ** ioAttrValue, 
		     CATLONG32 iSize);
/**
 *@nodoc
  */
  CATLONG32 ReadAttr(const char* iAttrName, CATUnicodeString ** ioAttr, 
		     CATLONG32 iSize, int iDef);
/**
 * Sets the value of a setting attribute made up of an array of pointers to CATUnicodeString.
 * <br><b>Role</b>: Sets the values of each element of the array making up the
 * attribute. Each of these elements is a pointer to a constructed 
 * CATUnicodeString instance.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of pointers to initialized and constructed CATUnicodeString 
 *      instances
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, CATUnicodeString ** iAttrValue, 
		      CATLONG32 iSize);
 


/**
 * Retrieves the value of a setting attribute made up of an array of chars.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized chars, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized chars.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char* iAttrName, char * ioAttrValue, 
		     CATLONG32 iSize=1);


/**
 * Sets the value of a setting attribute made up of an array of chars.
 * <br><b>Role</b>: Sets the values of each element of the array making up the
 * attribute. The array is defined as an array of initialized chars.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized chars
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char* iAttrName, char *iAttrValue, 
		      CATLONG32 iSize=1);




/**
 * Retrieves the value of a setting attribute made up of an array of doubles.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized doubles, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized doubles.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
  */
  CATLONG32 ReadAttr(const char*iAttrName, double *ioAttrValue, 
		     CATLONG32 iSize=1);

/**
 * Sets the value of a setting attribute made up of an array of doubles.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized doubles.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized doubles
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
  */
  CATLONG32 WriteAttr(const char*iAttrName, double *iAttrValue, 
		      CATLONG32 iSize=1);


/**
 * Retrieves the value of a setting attribute made up of an array of floats.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized floats, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized floats.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char*iAttrName, float *ioAttrValue, 
		     CATLONG32 iSize=1);

/**
 * Sets the value of a setting attribute made up of an array of floats.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized floats.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized floats
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char*iAttrName, float *iAttrValue, 
		      CATLONG32 iSize=1);



/**
 * Retrieves the value of a setting attribute made up of an array of ints.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized ints, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized ints.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
  */
  CATLONG32 ReadAttr(const char*iAttrName, int *ioAttrValue, CATLONG32 iSize=1);

/**
 * Sets the value of a setting attribute made up of an array of ints.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized ints.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized ints
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char*iAttrName, int *iAttrValue, CATLONG32 iSize=1);



/**
 * @nodoc 
 * 64 bits
 * Retrieves the value of a setting attribute made up of an array of longs.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized longs, because it is used to set the default value of the
 * attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized longs.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char*iAttrName, long *ioAttrValue, CATLONG32 iSize=1);

/**
 * @nodoc 
 * 64 bits
 * Sets the value of a setting attribute made up of an array of longs.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized longs.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized longs
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char*iAttrName, long *iAttrValue, CATLONG32 iSize=1);



/**
 * Retrieves the value of a setting attribute made up of an array of shorts.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized shorts, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or 
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized shorts.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char*iAttrName, short *ioAttrValue, 
		     CATLONG32 iSize=1);

/**
 * Sets the value of a setting attribute made up of an array of shorts.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized shorts.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized shorts
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char*iAttrName, short *iAttrValue, 
		      CATLONG32 iSize=1);
  


/**
 * Retrieves the value of a setting attribute made up of an array of unsigned ints.
 * <br><b>Role</b>: Retrieves, using its name, the values of each element of the
 * array making up the attribute. The array is defined as an array of 
 * initialized unsigned ints, because it is used to set the default value of 
 * the attribute, if it does not yet exist. In this last case the method calls
 * WriteAttr to initialize the setting attribute.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be retrieved or created.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param ioAttrValue [inout]
 *	An array of initialized unsigned ints.
 *	If the attribute has not been yet created, then the elements of
 *	<tt>ioAttrValue</tt> are used as default values, otherwise the elements 
 *      of <tt>ioAttrValue</tt> are overwritten by the retrieved values.
 * @param iSize [in]
 *	The size of the array
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>>0:</tt>  on success, returns the number of elements really read
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 ReadAttr(const char*iAttrName, unsigned int*ioAttrValue, 
		     CATLONG32 iSize=1);
/**
 * Sets the value of a setting attribute made up of an array of unsigned ints.
 * <br><b>Role</b>: Sets the values of each element of the array constituting the
 * attribute. The array is defined as an array of initialized unsigned ints.
 * @param iAttrName [in]
 *	The name of the attribute whose value is to be set.
 *	<br><b>Legal values</b>: The name length must be less than or
 *	equal to  @href MAXSETTINGNAME
 * @param iAttrValue [in] 
 *	An array of initialized unsigned ints
 * @param iSize [in]
 *	The size of the array
 * @return 
 *	<b>Legal values</b>:
 *	<br><tt> 1:</tt>  on success
 *	<br><tt> 0:</tt>  if a class conflict on the attribute has occurred
 * 	<br><tt>-1:</tt>  on failure
 */
  CATLONG32 WriteAttr(const char*iAttrName, unsigned int*iAttrValue, 
		      CATLONG32 iSize=1);



/**
 * Retrieves information associated with a given setting attribute.
 * <br><b>Role</b>:Information that may be associated with a setting 
 * attribute consists in:
 * <ul>
 *   <li>Whether the setting attribute is locked</li>
 *   <li>Its default value</li> 
 * </ul>
 * <p>This information is retrieved as a pointer to a @href CATSettingInfo class instance.
 * Depending on whether the setting attribute is locked, you can unlock or lock it using the
 * retrieved pointer, like you can do it using the @href #Lock or @href #Unlock methods
 * of CATSysSettingController, providing the methods are called in the Administrator mode.
 * @param iAttributeName [in]
 *	The name of the attribute.
 *	<br><b>Legal values</b>: The length of this name must be less than 
 *	or equal to @href MAXSETTINGNAME
 * @param oInfo [out]
 *	The retrieved information
 * @param iFlag [in]
 *	Reserved for internal use. Do not use. Should always be set to 0
 * @return
 * <b>Legal values</b>: S_OK if the information is successfully retrieved, and E_FAIL otherwise
 */
  HRESULT GetInfo ( const char* iAttributeName, CATSettingInfo* oInfo,
		    int iFlag=0);

/**
 * Locks a given setting attribute.
 * <br><b>Role</b>: Locking a given attribute enables you to prevent any further
 * modifications of its value.
 * Locking setting attribute is dedicated to setting administrators,
 * and is thus available in the Administrator mode only.
 * Otherwise <code>Lock</code> simply returns S_OK without locking the setting 
 * attribute.
 * @param iAttributeName [in]
 *	The name of the attribute to be locked.
 *	<br><b>Legal values</b>: The length of this name must be less than
 *	or equal to @href MAXSETTINGNAME
 * @return
 * <b>Legal values</b>: S_OK if the attribute was successfully locked, and 
 * E_FAIL otherwise
 */	

  HRESULT Lock  ( const char* iAttributeName);

/**
 * Unlocks a given setting attribute.
 * <br><b>Role</b>: Unlocking a given attribute enables you to authorize further
 * modifications of its value.
 * Unlocking setting attribute is dedicated to setting administrators,
 * and is thus available in the Administrator mode only.
 * Otherwise <code>Unlock</code> simply returns S_OK without unlocking the 
 * setting attribute.
 * @param iAttributeName [in]
 *	The name of the attribute to be unlocked.
 *	<br><b>Legal values</b>: The length of this name must be less than 
 *	or equal to  @href MAXSETTINGNAME
 * @return
 * <b>Legal values</b> S_OK if the attribute was successfully unlocked, and 
 * E_FAIL otherwise
 */
  HRESULT Unlock ( const char* iAttributeName);

/**
 * Browses the setting.
 * <br><b>Role</b>: Returns the Name, the type and the number of constituting 
 * elements of an attribute. The strings are copied but their allocation
 * must be done by the caller. 
 * @param oAttributeName
 *	a pointer to an allocated buffer where the attribute's name 
 *      will be copied
 * @param oAttributeClass
 *	a pointer to an allocated buffer where the attribute's type 
 *      will be copied
 * @param oAttributeSize
 *	a pointer to a CATLONG32 int to put the number of constituting elements
 * @param iReset
 *	iReset = 1 forces to begin with the first Attribute,reseting the state
 *	reached with the last call to this method, otherwise 0
 * @return
 *	<b>Legal values</b> S_OK until reaching the last Attribute and 
 *       returning E_FAIL when the last attribute is reached
*/
  HRESULT NextAttribute( char *oAttributeName, char *oAttributeClass, 
			 CATLONG32 *oAttributeSize,
			 short iReset = 0); 

public :

/**
 * @nodoc
 */
  virtual HRESULT Dump( char **iList=NULL, unsigned int iNb=0);


  
/**
 * Returns the locking state.
 * <br><b>Role</b>: Returns the locking state of an 
 * attribute from the @href CATSettingInfo instance attached to it.
 * This method is used in the macros that help you create your setting
 * controller. You should not call it explicitely outside of these macros.
 * @return
 *  The locking state
 *  <br><b>Legal values</b>:
 *  <table>
 *   <tr><td>Locked</td>       <td>The setting attribute is locked</td></tr>
 *   <tr><td>Unlocked</td>     <td>The setting attribute is not locked</td></tr>
 *   <tr><td>Upper Locked</td> <td>The setting attribute is upper locked</td></tr>
 *  </table>
 */
  static const char* MapLock(char iLock);/**
 * Returns the locking state.
 * <br><b>Role</b>: Returns the locking state and level of an 
 * attribute from the @href CATSettingInfo instance attached to it.
 * This method is used in the macros that help you create your setting
 * controller. You should not call it explicitely outside of these macros.
 * @param iInfo
 *    a CATSettingInfo Structure retrieved by a call to GetInfo.
 * @param oLockLevel
 *  <br><b>Legal values</b>:
 *  <table>
 *   <tr><td>Locked</td>       <td>The setting attribute is locked</td></tr>
 *   <tr><td>Unlocked</td>     <td>The setting attribute is not locked</td></tr>
 *   <tr><td>Locked at Admin Level i</td> <td>The setting attribute is  lockedt the level i of the CATReferenceSettingPath </td></tr>
 *  </table>
 */
  static void  MapLock(CATSettingInfo  &iInfo, CATUnicodeString &oLockLevel);




/**
 * Returns the Administration Level.
 * <br><b>Role</b>: Returns the  Administration Level of an 
 * attribute from the @href CATSettingInfo instance attached to it.
 * This method is used in the macros that help you create your setting
 * controller. You should not call it explicitely outside of these macros.
 * @param iInfo
 *    a CATSettingInfo Structure retrieved by a call to GetInfo.
 * @param oLevel
 *    a String that will be valuated.
 *  <br><b>Legal values</b>:
 *  <table>
 *   <tr><td>Not administrated</td><td>The attribute is not administrated</td></tr>
 *   <tr><td>Admin Level i</td><td>The Parameter is set at the level i of the CATReferenceSettingPath </td></tr>
 *  </table>
 */
  static void MapLevel(CATSettingInfo  &iInfo, CATUnicodeString &oLevel);
    
protected:
/**
 * @nodoc
 */
  CATSysParamMap *_ParamMap;		
/**
 * @nodoc
 */
  static int ReadDumpMode ();

private:
  CATSysSettingController ( const char *iSettingName, int iMode);
  static void SetDumpMode( int mode);
  static int _DumpMode;
  CATSysSettingRepository *_Repo;  
  
};



#endif
