#ifndef CATIScriptMacrosSettingAtt_h
#define CATIScriptMacrosSettingAtt_h

// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System Framework
#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATScriptLanguage.h"

class CATSettingInfo;
   
/**
 * Interface to handle the parameters of the macros settings.
 * <br>This interface defines:
 * <ul>
 * <li>A method to set each parameter</li>
 * <li>A method to get the value of each parameter</li>
 * <li>A method to lock/unlock each parameter</li>
 * <li>A method to retrieve the informations concerning each parameter</li>
 * </ul>
 */
class CATIScriptMacrosSettingAtt : public IUnknown {

	public: 
	
		/**
		 * Retrieves the editor path for the specified language.
		 * @param iLanguage
		 *	The given scripting language.
		 * @param oEditorPath
		 *	The retrieved editor path.
		 */
		virtual HRESULT GetLanguageEditor(CATScriptLanguage iLanguage, CATUnicodeString& oEditorPath) = 0;
		
		/**
		 * Sets the editor path for the specified language.
		 * @param iLanguage
		 *	The given scripting language.
		 * @param iEditorPath
		 *	The editor path to set.
		 */
		virtual HRESULT SetLanguageEditor(CATScriptLanguage iLanguage, const CATUnicodeString& iEditorPath) = 0;
		
		/** 
		 * Locks or unlocks the language editors setting.
		 * <br><b>Role</b>:Locks or unlocks the language editors setting if it is possible
		 * in the current administrative context. In user mode this method will always
		 * return E_FAIL.
		 * @param iLocked
		 *	the locking operation to be performed
		 *	<b>Legal values</b>:
		 *	<br><tt>TRUE :</tt>   to lock the parameter.
		 * 	<br><tt>FALSE:</tt>   to unlock the parameter.
		 */
		virtual HRESULT SetLanguageEditorLock(unsigned char iLock) = 0;
		
		/** 
		 * Retrieves environment informations for the language editors setting.
		 * <br><b>Role</b>:Retrieves the state of the parameter language editors setting 
		 * in the current environment. 
		 * @param AdminLevel
		 *       <br>If the parameter is locked, AdminLevel gives the administration
		 *       level that imposes the value of the parameter.
		 *	 <br>If the parameter is not locked, AdminLevel gives the administration
		 *       level that will give the value of the parameter after a reset.
		 * @param oLocked
		 *      Indicates if the parameter has been locked.
		 * @param oModified
		 *      Indicates if the parameter has been explicitly modified or remain
		 *      to the administrated value.
		 */ 
		virtual HRESULT GetLanguageEditorInfo(CATSettingInfo *oInfo) = 0;
		
		
		/**
		 * Retrieves the list of external references.
		 * @param oReferences
		 *	The retrieved references.
		 */
		virtual HRESULT GetExternalReferences(CATListOfCATUnicodeString& oReferences) = 0;
		
		/**
		 * Sets the list of external references.
		 * @param iReferences
		 *	The references to set.
		 */
		virtual HRESULT SetExternalReferences(const CATListOfCATUnicodeString& iReferences) = 0;
		
		/** 
		 * Locks or unlocks the external references setting.
		 * <br><b>Role</b>:Locks or unlocks the external references setting if it is possible
		 * in the current administrative context. In user mode this method will always
		 * return E_FAIL.
		 * @param iLocked
		 *	the locking operation to be performed
		 *	<b>Legal values</b>:
		 *	<br><tt>TRUE :</tt>   to lock the parameter.
		 * 	<br><tt>FALSE:</tt>   to unlock the parameter.
		 */
		virtual HRESULT SetExternalReferencesLock(unsigned char iLock) = 0;
		
		/** 
		 * Retrieves environment informations for the external references setting.
		 * <br><b>Role</b>:Retrieves the state of the parameter external references setting 
		 * in the current environment. 
		 * @param AdminLevel
		 *       <br>If the parameter is locked, AdminLevel gives the administration
		 *       level that imposes the value of the parameter.
		 *	 <br>If the parameter is not locked, AdminLevel gives the administration
		 *       level that will give the value of the parameter after a reset.
		 * @param oLocked
		 *      Indicates if the parameter has been locked.
		 * @param oModified
		 *      Indicates if the parameter has been explicitly modified or remain
		 *      to the administrated value.
		 */ 
		virtual HRESULT GetExternalReferencesInfo(CATSettingInfo *oInfo) = 0;


		/**
		 * Retrieves the list of default macro libraries.
		 * @param oLibraries
		 *	The retrieved macro libraries.
		 */
		virtual HRESULT GetDefaultMacroLibraries(CATListOfCATUnicodeString& oLibraries) = 0;
		
		/**
		 * Sets the list of default macro libraries.
		 * @param iLibraries
		 *	The macro libraries to set.
		 */
		virtual HRESULT SetDefaultMacroLibraries(const CATListOfCATUnicodeString& iLibraries) = 0;
		
		/** 
		 * Locks or unlocks the default macro libraries setting.
		 * <br><b>Role</b>:Locks or unlocks the default macro libraries setting if it is possible
		 * in the current administrative context. In user mode this method will always
		 * return E_FAIL.
		 * @param iLocked
		 *	the locking operation to be performed
		 *	<b>Legal values</b>:
		 *	<br><tt>TRUE :</tt>   to lock the parameter.
		 * 	<br><tt>FALSE:</tt>   to unlock the parameter.
		 */
		virtual HRESULT SetDefaultMacroLibrariesLock(unsigned char iLock) = 0;
		
		/** 
		 * Retrieves environment informations for the default macro libraries setting.
		 * <br><b>Role</b>:Retrieves the state of the parameter default macro libraries setting 
		 * in the current environment. 
		 * @param AdminLevel
		 *       <br>If the parameter is locked, AdminLevel gives the administration
		 *       level that imposes the value of the parameter.
		 *	 <br>If the parameter is not locked, AdminLevel gives the administration
		 *       level that will give the value of the parameter after a reset.
		 * @param oLocked
		 *      Indicates if the parameter has been locked.
		 * @param oModified
		 *      Indicates if the parameter has been explicitly modified or remain
		 *      to the administrated value.
		 */ 
		virtual HRESULT GetDefaultMacroLibrariesInfo(CATSettingInfo *oInfo) = 0;

};

extern "C" const IID IID_CATIScriptMacrosSettingAtt;

#endif // CATIScriptMacrosSettingAtt_h
