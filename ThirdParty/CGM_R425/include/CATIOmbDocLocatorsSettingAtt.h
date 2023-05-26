#ifndef CATIOmbDocLocatorsSettingAtt_H
#define CATIOmbDocLocatorsSettingAtt_H

// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================
//
// Interface d'accès au setting DocLocators du repository SymbolicLinks
// Implémentée par CATOmbDocLocatorsSettingCtrl
//
//=============================================================================
// Jun. 04   Creation                                                 O.PERIOU
//=============================================================================

/**
 * @level Private
 * @usage U3
 */

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATString.h"

class CATSettingInfo;

extern ExportedByAC0XXLNK IID IID_CATIOmbDocLocatorsSettingAtt;

/** 
 * Interface representing the doc locators setting controller object.
 * <b>Role</b>: The doc locators setting controller object deals with the setting
 * parameter Linked Document Localization displayed in the property page.
 * To access this property page:
 * <ul>
 *  <li>Click the <b>Options</b> command in the <b>Tools</b> menu</li>
 *  <li>Click + left of <b>General</b> to unfold the workbench list</li>   
 *  <li>Select the <b>Document </b> tabpage</li>
 * </ul> 
 */

class ExportedByAC0XXLNK CATIOmbDocLocatorsSettingAtt: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Retrieves the Linked Document Localization parameter value.
     * @param oLocators
     *   The Linked Document Localization parameter value.
	 *   Indicates the strategies and the order used to localize documents.
     * @return
     *   S_OK if the Linked Document Localization setting parameter value
     *   is successfully retrieved, and E_FAIL otherwise   
     */

     virtual HRESULT GetDocLocators (CATString&  oLocators) = 0;

    /**
     * Sets Linked Document Localization parameter value.
     * @param iLocators
     *   The Linked Document Localization parameter value.
	 *   Indicates the strategies and the order used to localize documents.
     * @return
     *   S_OK if the Linked Document Localization setting parameter value
     *   is successfully set, and E_FAIL otherwise   
     */

     virtual HRESULT SetDocLocators (const CATString& iLocators) = 0;

	/** 
	* Retrieves information about the Linked Document Localization setting parameter.
	* <br>Refer to @href CATSysSettingController for a detailed description.
	*/

     virtual HRESULT GetDocLocatorsInfo (CATSettingInfo* oInfo) = 0;

	/** 
	* Locks or unlocks the Linked Document Localization setting parameter.
	* <br>Refer to @href CATSysSettingController for a detailed description.
	*/

     virtual HRESULT SetDocLocatorsLock (unsigned char   iLocked) = 0;

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
     virtual HRESULT ResetToAdminValues(char** iAttList, int iNbAtt) = 0;

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
  virtual HRESULT Commit(int iNoEvent=0)=0;
};
#endif

