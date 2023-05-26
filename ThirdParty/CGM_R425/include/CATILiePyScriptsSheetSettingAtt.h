// COPYRIGHT Dassault Systemes 2003

//===================================================================
//
// CATILiePyScriptsSheetSettingAtt.h
// Define the CATILiePyScriptsSheetSettingAtt interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Dec 2003  Creation: Code generated by the CAA wizard  sob
//===================================================================
#ifndef CATILiePyScriptsSheetSettingAtt_H
#define CATILiePyScriptsSheetSettingAtt_H

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATILiePyScriptsSheetSettingAtt;
#else
extern "C" const IID IID_CATILiePyScriptsSheetSettingAtt;
#endif

class CATSettingInfo;
class CATUnicodeString;

//------------------------------------------------------------------

/**
* The interface to access a CATIAPyScriptsSheetSettingAtt.
* This interface may be used to read or modify in the CATIA\Tools\Option the settings values
* of PyScripts sheet.
*/

class ExportedByKnowledgeItf CATILiePyScriptsSheetSettingAtt : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  //***********************************************************************
  // Ensure consistency with the IDL interface that will delegate its work
  // Check allowed signatures in System.CATSysSettingController
  //***********************************************************************

  /**
   * Retrieves the ExternalPyLibsDirectory attribute.
   * <br><b>Role</b>:Return the ExternalPyLibsDirectory parameter if it is possible
   * in the current administrative context.
   * @param oExternalPyLibsDirectory
   *    The directory in which the external packages are stored.
   */
  virtual HRESULT GetExternalPyLibsDirectory(CATUnicodeString& oExternalPyLibsDirectory) = 0;

  /**
   * Sets the ExternalPyLibsDirectory attribute.
   * <br><b>Role</b>:Set the ExternalPyLibsDirectory parameter if it is possible
   * in the current administrative context.
   * @param iExternalPyLibsDirectory
   *    The directory in which the external packages are stored.
   */
  virtual HRESULT SetExternalPyLibsDirectory(CATUnicodeString& iExternalPyLibsDirectory) = 0;

  /**
   * Retrieves the state of the ExternalPyLibsDirectory attribute.
   * @param oInfo
   *	Address of an object CATSettingInfo.
   * @return
   *	<b>Legal values</b>:
   *	<br><tt>S_OK :</tt>   on Success
   * 	<br><tt>E_FAIL:</tt>  on failure
   */
  virtual HRESULT GetExternalPyLibsDirectoryInfo(CATSettingInfo* oInfo) = 0;

  /**
   * Locks or unlocks the ExternalPyLibsDirectory parameter.
   * <br><b>Role</b>: Locks or unlocks the ExternalPyLibsDirectory parameter if the
   * operation is allowed in the current administrated environment. In user mode
   * this method will always return E_FAIL.
   * @param iLocked
   *	the locking operation to be performed
   *	<b>Legal values</b>:
   *	<br><tt>1 :</tt>   to lock the parameter.
   * 	<br><tt>0:</tt>   to unlock the parameter.
   * @return
   *	<b>Legal values</b>:
   *	<br><tt>S_OK :</tt>   on Success
   * 	<br><tt>E_FAIL:</tt>  on failure
   */
  virtual HRESULT SetExternalPyLibsDirectoryLock(unsigned char  iLocked) = 0;

  /**
   * Retrieves the ExternalPyLibsUse attribute.
   * <br><b>Role</b>:Return the ExternalPyLibsUse parameter if it is possible
   * in the current administrative context
   * @param oExternalPyLibsUse
   *    The integer indicating if the user requests the use of external python libraries.
   */
  virtual HRESULT GetExternalPyLibsUse(int* oUsed) = 0;

  /**
   * Sets the ExternalPyLibsUse attribute.
   * <br><b>Role</b>:Set the ExternalPyLibsUse parameter if it is possible
   * in the current administrative context
   * @param iExternalPyLibsDirectory
   *    The integer indicating if the user requests the use of external python libraries.
   */
  virtual HRESULT SetExternalPyLibsUse(int* iUsed) = 0;

  /**
   * Retrieves the state of the ExternalPyLibsUse attribute.
   * @param oInfo
   *	Address of an object CATSettingInfo.
   * @return
   *	<b>Legal values</b>:
   *	<br><tt>S_OK :</tt>   on Success
   * 	<br><tt>E_FAIL:</tt>  on failure
   */
  virtual HRESULT GetExternalPyLibsUseInfo(CATSettingInfo* oInfo) = 0;

  /**
   * Locks or unlocks the ExternalPyLibsUse parameter.
   * <br><b>Role</b>: Locks or unlocks the ExternalPyLibsUse parameter if the
   * operation is allowed in the current administrated environment. In user mode
   * this method will always return E_FAIL.
   * @param iLocked
   *	the locking operation to be performed
   *	<b>Legal values</b>:
   *	<br><tt>1 :</tt>   to lock the parameter.
   * 	<br><tt>0:</tt>   to unlock the parameter.
   * @return
   *	<b>Legal values</b>:
   *	<br><tt>S_OK :</tt>   on Success
   * 	<br><tt>E_FAIL:</tt>  on failure
   */
  virtual HRESULT SetExternalPyLibsUseLock(unsigned char  iLocked) = 0;
  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif