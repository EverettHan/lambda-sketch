// *****************************************************************
// COPYRIGHT DASSAULT SYSTEMES 2016
// *****************************************************************
//
//   Identification :
//   ---------------
//
//      RESPONSIBLE : SANDEEP SWAMI
//      FUNCTION    : DLNAME UTILITY SERVICES  
//      USE         : ENOVIA
//
// *****************************************************************
//
//   Description :
//   ------------
//
//    Class providing utility services for DLNAME, like :
//             - Checking if DLName Setting is activaed.
//             - Fetching DLName for the absolute path.
//             - Fetching path for the DLName, etc... 
// *****************************************************************
//
//   Story :
//   -------
//   Revision 1.0  January    2016  (ZUK) Initial Revision for V6R2017x
//
// ****************************************************************

#ifndef PLMExchangeExperienceDLNameServices_H
#define PLMExchangeExperienceDLNameServices_H

#include "PLMExchangeFileServices.h"
#include "CATSysBoolean.h"                      //
#include "CATListOfCATUnicodeString.h"

//-----------------------------------------------------------------------

class ExportedByPLMExchangeFileServices PLMExchangeExperienceDLNameServices

{

public:

   /**
   * <b> GetRealPathfromDLName </b> : This method will return absolute path for the DLName.
   *
   * <br><b>Role</b>: This method will return absolute path for the DLName.
   *
   * @param iusDLNamePath  [in]
   * input DLName
   *
   * @param ousRealPath  [out]
   * output absolute path for the input DLName.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>If wrong input</dd>
      *   </dl>
   */
   static HRESULT GetRealPathfromDLName(CATUnicodeString & iusDLNamePath, CATUnicodeString & ousRealPath);

   /**
   * <b> GetExistingDLNameforFilePath </b> : This method will return DLName for the absolute file path.
   *
   * <br><b>Role</b>: This method will return DLName for the absolute file path.
   *
   * @param iusFilePath  [in]
   * input absolute file path.
   *
   * @param ousDLName  [out]
   * Existing DLName associated with the input file path
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>If wrong input</dd>
      *   </dl>
   */
   static HRESULT GetExistingDLNameforFilePath(CATUnicodeString & iusFilePath, CATUnicodeString & ousDLName);

   /**
   * <b> GetDLNameSettingActivationStatus </b> : This method will return DLName setting activation status.
   *
   * <br><b>Role</b>: This method will return DLName setting activation status.
   *
   * @param obDLNameSettingActivated  [out]
   * TRUE if setting is activated , FALSE otherwise
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   </dl>
   */
   static HRESULT GetDLNameSettingActivationStatus(CATBoolean & obDLNameSettingActivated);

   /**
   * <b> GetRealNameIfDLName </b> : This method will return absolute path for the DLName.
   *
   * <br><b>Role</b>: This method will return absolute path for the DLName.
   *
   * @param iusPath  [in]
   * input DLName
   *
   * @param oRealName  [out]
   * output absolute path for the input DLName.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>If wrong input</dd>
      *   </dl>
   */
   static void GetRealNameIfDLName(CATUnicodeString & iusPath, CATUnicodeString &oRealName);

   /**
   * <b> CheckIfDLNameExists </b> : This method will check if the input DLName exists or not.
   *
   * <br><b>Role</b>: This method will check if the input DLName exists or not.
   *
   * @param iusPath  [in]
   * input DLName
   *
   * @param obDLName  [out]
   * TRUE if it exists, FALSE otherwise.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>If wrong input</dd>
      *   </dl>
   */
   static void CheckIfDLNameExists(CATUnicodeString & iusPath, CATBoolean & obDLName);

   /**
   * <b> SetReportLocationDLName </b> : This method will create DLName for default CATReport location.
   *
   * <br><b>Role</b>: This method will create DLName for default CATReport location.
   *
   * @param ousReportLocationPath  [out]
   * output DLName created for the default CATReport location.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   </dl>
   */
   static HRESULT SetReportLocationDLName(CATUnicodeString & ousReportLocationPath);

   /**
   * <b> SetDLNameForPath </b> : This method will create DLName for input absolute path.
   *
   * <br><b>Role</b>: This method will create DLName for input absolute path.
   *
   * @param iusDLNameToSet  [in]
   * DLName to be created.
   *
   * @param iusForPath  [in]
   * inpit file path for which DLName is to be created.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   <dt>E_INVALIDARG</dt>  <dd>If wrong input</dd>
      *   </dl>
   */
   static HRESULT SetDLNameForPath(const CATUnicodeString &iusDLNameToSet, CATUnicodeString &iusForPath);

   /**
   * <b> GetDLNames </b> : This method will return list of existing DLNames.
   *
   * <br><b>Role</b>: This method will return list of existing DLNames.
   *
   * @param iusParentDLName [in]
   * Pass NULL if parent DLName is not known
   *
   * @param ousListOfDLNames  [out]
   * List of DLNames.
   *
   * @return
   *   An HRESULT value.
      *   <br><b>Legal values</b>:
      *   <dl>
      *   <dt>S_OK</dt>          <dd>If test succeeds.</dd>
      *   <dt>E_FAIL</dt>        <dd>Failure encountered during processing.</dd>
      *   </dl>
   */
   static HRESULT GetDLNames( CATUnicodeString * iusParentDLName, CATListOfCATUnicodeString & ousListOfDLNames);
};
//-----------------------------------------------------------------------
#endif
