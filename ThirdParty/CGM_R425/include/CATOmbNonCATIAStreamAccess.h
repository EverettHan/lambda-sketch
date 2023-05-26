#ifndef CATOmbNonCATIAStreamAccess_H_V1
#define CATOmbNonCATIAStreamAccess_H_V1

/**
* @level Protected
* @usage U1
*/

#include "CATUnicodeString.h"

#include "CATVVSUrl.h"

#include "CATOmbNonCATIADocument.h"
#include "CATIOmbStreamDescriptor.h"
#include "CATIOmbNonCATIAStreamDescriptor.h"

/**
* This static class provides specific methods on RepRef to access large files 
*
* <br><b>Role</b>: 
* <p>
*   This class allows to access into FCS Large Files eventually managed by a RepRef, allowing: 
*   <li>
*     <ul> File creation access, to get a new large file entry into the FCS </ul>
*     <ul> File read access (checkout), for a file already saved and found in the FCS </ul>    
*     <ul> File save access (checkin), for a created/modified file to be saved to the FCS </ul>    
*   </li>
*/

class ExportedByCATOmbNonCATIADocument CATOmbNonCATIAStreamAccess 
{
public :

  /**    
  * Ask for an access creation to a new large file entry into the database FCS repository
  * When the access is reserved, a file path is given as output to access the new file into the FCS file system
  *
  * @param iRepRef [in]
  *   The RepRef the large file Extended StreamDescriptor is aggregated to
  * @param iTerminalPath [in]
  *   The Name/EndPath to be assigned to the new LargeFile entry to be reserved into the FCS.
  *   examples ( "MyLargeFile.txt") or ("MyDirA\MyDirB\MyLargeFile.SMASim")
  * @param oLargePathEntryUrl [out]
  *   The complete hardlink Url computed to access the LargeFile which name/end path is given as input
  *   examples ("\\ComputedSite\..ComputedPath...\MyLargeFile.txt") or ("\\ComputedSite\..ComputedPath...\MyDirA\MyDirB\MyLargeFile.SMASim")
  *   This file is accessible with READ/WRITE rights for application purposes.
  *
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>E_FAIL</code>   An unexpected error occured
  */   
  static HRESULT CreateLargeFileAccess(CATBaseUnknown* iRepRef, const CATUnicodeString iTerminalPath, CATVVSUrl& oLargeFileEntryUrl);

  /**    
  * Ask for a working large file entry previously set on current StreamDescriptor.
  * This entry is the current working Url previously set on the StreamDescriptor modified in session,
  * at StreamDescriptor creation or imported on StreamDescriptor using ImportLargeFile.
  * This entry can be get as long as the StreamDescriptor has not been saved into the DataBase.
  * Any time the StreamDescriptor is (re-)modified in session by another ImportLargeFile and not (re-)saved,
  * its current working large file entry can be get.
  *
  * @param iRepRef [in]
  *   The RepRef the large file Extended StreamDescriptor is aggregated to
  * @param iPersistencyName [in]
  *   The name of the extended StreamDescriptor handling the large file.
  *   (as given as input to CATOmbRepRefLoadingServices::AddExtendedSDForRepRef at SD creation time)
  * @param oLargeFileWorkUrl [out]
  *   The working LargeFile Url previously set on current StreamDescriptor, as long as it is seen as modified.
  *   This file is accessible with READ/WRITE rights for application purposes.
  *   Specific case:
  *      if the extended StreamDescriptor is not modified, the oLargeFileWorkUrl returned is empty,
  *      as any working stream location is no more referenced on the StreamDescriptor.
  *      A specific error CATOmb_E_LargeFilePersistUrl is then raised.

  *
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>CATOmb_E_LargeFilePersistUrl</code> oLargeFileWorkUrl cannot be retrieved,
  *                                             as current StreamDescriptor is saved in DataBase and not modified
  *   <code>E_FAIL</code>   An unexpected error occured
  */   
  static HRESULT GetLargeFileWorkingAccess(CATBaseUnknown* iRepRef, const CATUnicodeString iPersistencyName, CATVVSUrl& oLargeFileWorkUrl);

  /** 
  * Ask for an output access to an existing large file stored into the database FCS repository
  * When the access is allowed, an URL file path is given as output, to access, in READ ONLY mode,
  * the existing file into the FCS file system
  *
  * @param iRepRef [in]
  *   The RepRef the large file extended SD is aggregated to 
  * @param iPersistencyName [in]
  *   The name of the extended StreamDescriptor handling the large file.
  *   (as given as input to CATOmbRepRefLoadingServices::AddExtendedSDForRepRef at SD creation time)
  * @param iTerminalPath [in]
  *   The Name/EndPath to be assigned to the hardlink path to the existing LargeFile into the FCS.
  *   examples( "MyLargeFile.txt") or ("MyDirA\MyDirB\MyLargeFile.SMASim")
  * @param oLargeFileLinkUrl [out]
  *   The complete hardlink Url computed to access the LargeFile which name/end path is given as input
  *   examples ("\\ComputedSite\..ComputedPath...\MyLargeFile.txt") or ("\\ComputedSite\..ComputedPath...\MyDirA\MyDirB\MyLargeFile.SMASim")
  *   This file is accessible with READ ONLY rights for application purposes.
  *   Specific case:
  *      if the extended StreamDescriptor is modified, the oLargeFileLinkUrl returned is empty,
  *      as no hardlink can be computed  between the stream version stored in FCS and the new version referenced on the StreamDescriptor
  *      A specific error CATOmb_E_LargeFileWorkingUrl is then raised
  *
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>CATOmb_E_LargeFileWorkingUrl</code> oLargeFileLinkUrl cannot be retrieved,
  *                                             as current StreamDescriptor is modified in Session 
  *   <code>E_FAIL</code>   An unexpected error occured
  */
  static HRESULT ExportLargeFile(CATBaseUnknown* iRepRef, const CATUnicodeString iPersistencyName, const CATUnicodeString iTerminalPath, CATVVSUrl& oLargeFileLinkUrl);


  /**
  * Ask for an input access on a large file to be saved into the database FCS repository
  * When the access is allowed, a save file path is computed into the FCS file system.
  * The next Save operation will then be able to stream the large file to the database FCS.
  *
  * @param iRepRef [in]
  *   The RepRef the large file extended SD is aggregated to
  * @param iPersistencyName [in]
  *   The name of the extended SD handling the large file.
  *   (as given as input to CATOmbRepRefLoadingServices::AddExtendedSDForRepRef at SD creation time)
  *   The large file handled by this extended SD must have been already exported 
  * @param iLargeFileUrl [in]
  *   The Url of the external file to be imported into FCS, on the same file system than the exported one.
  *     This Url should be LargeFile formatted and should have been get previously from the server
  *     using CreateLargeFileAccess or ExportLargeFile
  *
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>E_FAIL</code>   An unexpected error occured
  */
  static HRESULT ImportLargeFile(CATBaseUnknown* iRepRef, const CATUnicodeString iPersistencyName, const CATVVSUrl& iLargeFileUrl);

  /** 
  * @param iRepRef [in]
  *   The RepRef the extended authoring StreamDescriptor belongs to is to accessed
  * @param iPersistencyName [in]
  *   The name of the extended SD to be accessed from its RepRef.
  * @param ohStreamDesc [out]
  *   A handle accessing generic behaviour on the extended SD.
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>E_FAIL</code>   An unexpected error occured
  */   
  static HRESULT GetExtendedStreamDescriptor(CATBaseUnknown* iRepRef, const CATUnicodeString iPersistencyName, CATIOmbStreamDescriptor_var& ohStreamDesc);

  /** 
  * @param iRepRef [in]
  *   The RepRef the extended authoring StreamDescriptor belongs to is to accessed
  * @param iPersistencyName [in]
  *   The name of the extended SD to be accessed from its RepRef.
  * @param ohStreamDesc [out]
  *   A handle accessing specific NonCATIA behaviours on the extended SD.
  * @return
  *   <code>S_OK</code>          An I/O access to the file in FCS is computed and is valid
  *   <code>E_UNEXPECTED</code>  An unexpected error occured
  */   
  static HRESULT GetExtendedStreamHandle(CATBaseUnknown* iRepRef, const CATUnicodeString iPersistencyName, CATIOmbNonCATIAStreamDescriptor_var& ohNonCATIAStreamDesc);

private:

  /** 
  * @param iRepRef [in]
  *   RepRef managing the LargeFile wich URL is to be completed
  * @param iFileName [in]
  *   The name of the LargeFile to be handled
  * @param ioUrlPattern [inout]
  *   The LargeFile empty input URL Pattern completed as output with the file name and the FCS location 
  * @return
  *   <code>S_OK</code>     An I/O access to the file in FCS is computed and is valid
  *   <code>E_FAIL</code>   An unexpected error occured
  */   
  static HRESULT CompleteUrlPatternFromRepRef(CATBaseUnknown* & iRepRef, const CATUnicodeString iFileName, CATVVSUrl &ioUrlPattern);

  static HRESULT IsTypeLargeFileCompliant(const CATUnicodeString iFilePath, const CATUnicodeString& iLateType = "");
};
#endif
