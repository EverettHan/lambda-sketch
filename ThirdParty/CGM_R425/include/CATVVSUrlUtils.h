/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=============================================================================


#ifndef CATVVSUrlUtils_H
#define CATVVSUrlUtils_H

#include "VVSUrlUtils.h"
#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATTypUtilit.h"

class CATVVSUrlTS;
class CATSysTSUnicodeString;

/**
 * Services for URL.
 */

class ExportedByVVSUrlUtils CATVVSUrlUtils
{
public:

  // Explicit enough
  static HRESULT FromNativeFilePathToUrl(const CATUnicodeString& iFilePath,CATVVSUrl& oUrl) ;

  /**
  * Compute an url from a complete path.
  * The output url's protocol is the same as the input protocol
  * The input protocol have to support direct file access
  * Authorized protocols :
  * <ul>
  *   <li>file</li>
  *   <li>PW</li>
  *   <li>3DXMLVS</li>
  *   <li>fileTestLF</li>
  * </ul>
  *
  * @param iFilePath [in]
  *   a complete file path
  * @param iProtocol [in]
  *   the url's protocol
  * @param oUrl [out]
  *   the computed url with iProtocol as protocol
  * @return
  *   <ul>
  *     <li><code>S_OK</code>: the url is correctly computed</li>
  *     <li><code>S_FALSE</code>: the given protocol does not support direct file access</li>
  *     <li><code>E_*</code>: unexpected error</li>
  *   </ul>
  */
  static HRESULT CreateUrlFromPath(const CATUnicodeString& iFilePath, const CATUnicodeString& iProtocol, CATVVSUrl& oUrl);

  /* Compares 2 URLs.
   * @return
   *   <ul>
   *   <li><code>< 0</code>: iUrl1 is lower than iUrl2.</li>
   *   <li><code>== 0</code>: iUrl1 is equal with iUrl2.</li>
   *   <li><code>> 0</code>: iUrl1 is greater than iUrl2.</li>
   *   </ul>
   *   Note that only string comparisons are performed and that strings cases are taken into account.
   */
  static int CompareURL(const CATVVSUrl& iUrl1, const CATVVSUrl& iUrl2);

  /** 
  * Compute a Hash key for an Url.
  * @param iUrl [in]
  *   The source URL.
  * @return
  *   The computed Hash key;
  */
  static unsigned int ComputeHashKey(const CATVVSUrl& iUrl);

  /** 
  * Compute an Hash key for a CATSysSimpleHashTable.
  * @param iUrl [in]
  *   The given object. It must be a pointer on a CATVVSUrl.
  * @return
  *   The computed Hash key;
  */
  static unsigned int SimpleHTComputeHashKey(void* iUrl);
  /** 
  * Comparison method for a CATSysSimpleHashTable.
  * @param iUrl1 [in]
  *   The first given object. It must be a pointer on a CATVVSUrl.
  * @param iUrl2 [in]
  *   The second given object. It must be a pointer on a CATVVSUrl.
  * @return
  *   <UL>
  *    <LI><code>0</code>: if the Urls are equal</LI>
  *   </UL>
  */
  static int SimpleHTCompareUrl(void* iUrl1, void* iUrl2);

  /**
  * This API returns you a path from an URL. If the input URL does not support file access (ie it is an http or AW url), a local copy of the file is performed first. 
  * @param iURL[in] the url to a ressource you want to access as file
  * @param oFilePath[out] : the path to the file you can access using native file api (like fopen,fclose,fread...)
  * @return
  * @return
  *    <code>S_OK</code>: FilePath has been correctly generated
  *    <code>E_INVALIDARG</code>: Provided URL is not supported 
  *    <code>E*</code> : unexpected errror
  */
  static HRESULT RetrieveFileAccess(const CATVVSUrl& iUrl,CATUnicodeString& oFilePath);

  /*********************************************************
  *                                                        *
  *   ***    **     *   *   **  *****   *   *  ***  ****   *
  *   *  *  *  *    **  *  *  *   *     *   * *     *      *
  *   *  *  *  *    * * *  *  *   *     *   *  ***  ****   *
  *   *  *  *  *    *  **  *  *   *     *   *     * *      *
  *   ***    **     *   *   **    *      ***   ***  ****   *
  *                                                        *
  **********************************************************
  *
  * Use CATVVSUrlAndStreamManager::OpenConnection instead!!
  */
  static HRESULT FromUrlToNativeFilePath(const CATVVSUrl& iUrl,CATUnicodeString& oFilePath,unsigned short iOperatingSystem) ;
  
  /*********************************************************
  *                                                        *
  *   ***    **     *   *   **  *****   *   *  ***  ****   *
  *   *  *  *  *    **  *  *  *   *     *   * *     *      *
  *   *  *  *  *    * * *  *  *   *     *   *  ***  ****   *
  *   *  *  *  *    *  **  *  *   *     *   *     * *      *
  *   ***    **     *   *   **    *      ***   ***  ****   *
  *                                                        *
  **********************************************************
  *
  * Use CATVVSUrlAndStreamManager::CreateUrlFromUrlPattern instead!!
  */
  static HRESULT MergeUrlFromReference(const CATVVSUrl& iUrlPattern, const CATVVSUrl& iUrlPrefixReference, CATVVSUrl& oUrl);

  /*********************************************************
  *                                                        *
  *   ***    **     *   *   **  *****   *   *  ***  ****   *
  *   *  *  *  *    **  *  *  *   *     *   * *     *      *
  *   *  *  *  *    * * *  *  *   *     *   *  ***  ****   *
  *   *  *  *  *    *  **  *  *   *     *   *     * *      *
  *   ***    **     *   *   **    *      ***   ***  ****   *
  *                                                        *
  **********************************************************/
  static HRESULT FromVaultIdToUrl(const SEQUENCE_octet& iVaultId,CATVVSUrl& oUrl);

  /*********************************************************
  *                                                        *
  *   ***    **     *   *   **  *****   *   *  ***  ****   *
  *   *  *  *  *    **  *  *  *   *     *   * *     *      *
  *   *  *  *  *    * * *  *  *   *     *   *  ***  ****   *
  *   *  *  *  *    *  **  *  *   *     *   *     * *      *
  *   ***    **     *   *   **    *      ***   ***  ****   *
  *                                                        *
  **********************************************************/
  static HRESULT FromUrlToVaultId(const CATVVSUrl& iUrl,SEQUENCE_octet& oVaultId);
};

#endif
