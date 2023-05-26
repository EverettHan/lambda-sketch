/**
* @level Private
* @usage U1
*/
#ifndef CATVVSUrlAndStreamManager_H_V2
#define CATVVSUrlAndStreamManager_H_V2

#include "CATIAV5Level.h"
#include "VVSStreamConsumer.h"

#include "CATUnicodeString.h"
#include "CATVVSUrl.h"
#include "CATVVSURLConnection.h"
#include "CATListOfCATVVSUrl.h"
#include "CATIVVSVaultCheck.h"
#include "CATIVVSVaultAccess.h"
#include "CATVVSUtils.h"
#include "CATOmxArray.h"
#include "CATMD5.h"

class CATVVSStreamSizes;
class CATVVSTransaction;
class CATUuid;

#ifndef CATIAR423
class CATVVSAsyncTransfertQuery;
#endif

/**
* Enable Consumer Applications (Cache, PDM System)
* to Create, Clone , Release URLs and Access Streams for Read or Write Purpose.
*/
class ExportedByVVSStreamConsumer CATVVSUrlAndStreamManager
{
public:

  /** 
  * Create a new URL in a given Vault Site.
  * @param iTargetVaultSiteIdentifier 
  *   The identifier of the Target Vault Site where we want to create the url.
  *   The identifer is the result of the registration in CATVVSPLMAndVaultManager::RegisterVaultSiteDescriptor.
  * @param iUrlPattern
  *   A pattern to construct a new URL.
  * @param oUrl  
  *   The new created URL.
  * @param iTransaction   
  *   Will be used in a later release.
  * @return
  * S_OK if the url was succesfully created, or E_FAIL otherwise
  */
  HRESULT CreateUrlFromUrlPattern(int iTargetVaultSiteIdentifier, const CATVVSUrl& iUrlPattern, CATVVSUrl& oUrl,CATVVSTransaction* iTransaction = NULL);

  /** 
  * Create a new URL in a given Vault Site.
  * @param iUrlPattern
  *   A pattern to construct a new URL.
  * @param oUrl  
  *   The new created URL.
  * @param iTransaction   
  *   Will be used in a later release.
  * @return
  * S_OK if the url was succesfully created, or E_FAIL otherwise
  */
  HRESULT CreateUrlFromUrlPattern(const CATVVSUrl& iUrlPattern, CATVVSUrl& oUrl,CATVVSTransaction* iTransaction = NULL);

  /** 
  * Duplicates a stream identified by an URL into a new stream pointed by a new URL.  *
  * @param iTargetVaultSiteIdentifier 
  *   The identifier of the Target Vault Site where we want to create the url.
  *   The identifer is the result of the registration in CATVVSPLMAndVaultManager::RegisterVaultSiteDescriptor.
  * @param iUrl 
  *   The URL of the stream we want to clone.
  * @param iUrlPattern
  *   A pattern to construct a new URL.
  * @param oUrl  
  *   The new created URL.
  * @param iTransaction   
  *   Will be used in a later release.
  * @return
  * S_OK if the URL was succesfully cloned, or E_FAIL otherwise.
  */
  HRESULT CloneURL(int iTargetVaultSiteIdentifier, const CATVVSUrl& iUrl, const CATVVSUrl& iUrlPattern, CATVVSUrl& oUrl, CATVVSTransaction* iTransaction = NULL);

  /** 
  * Release a URL
  * @param iUrl 
  * The identifier of the URL the PLM site will not use no more.
  * @param iTransaction   
  * Will be used in a later release
  * @return
  * S_OK if the url was succesfully released, or E_FAIL otherwise
  */
  HRESULT ReleaseURL(const CATVVSUrl& iUrl,CATVVSTransaction* iTransaction=NULL) ;

  /** 
  * Opens a Connection
  * @param iUrl 
  * The identifier of the URL we want to open
  * @param oConnection  
  * The returned Connection
  * Notice that opening the connection does not mean to connect to the server.
  * @param iTransaction   
  * Will be used in a later release
  * @return
  * S_OK if the urlConnection was succesfully opened, or E_FAIL otherwise
  */
  HRESULT OpenConnection(const CATVVSUrl& iUrl,CATVVSURLConnection& oConnection,CATVVSTransaction* iTransaction=NULL) ;

  /*
  * Finds an url in Vault site.
  * @param iTargetVaultSiteIdentifier
  *   the index of the vault site that manages the searched url.
  * @param iUrl
  *  The url to find.
  * @param iTransaction   
  *  Will be used in a later release.
  * @return
  *  <UL>
  *    <LI><code>S_OK</code>:if the url has been found.</LI>
  *    <LI><code>S_FALSE</code>:if the url has not been found.</LI>
  *    <LI><code>E_FAIL</code>:if an error occurs.</LI>
  *  </UL>
  */
  HRESULT QueryUrl(int iTargetVaultSiteIdentifier, const CATVVSUrl& iUrl,CATVVSTransaction* iTransaction=NULL) ;

  /*
  * Finds an url in Vault site.
  * @param iUrl
  *  The url to find.
  * @param iTransaction   
  *  Will be used in a later release.
  * @return
  *  <UL>
  *    <LI><code>S_OK</code>:if the url has been found.</LI>
  *    <LI><code>S_FALSE</code>:if the url has not been found.</LI>
  *    <LI><code>E_FAIL</code>:if an error occurs.</LI>
  *  </UL>
  */
  HRESULT QueryUrl(const CATVVSUrl& iUrl,CATVVSTransaction* iTransaction=NULL) ;

  /* Retrieve the physical path of files that could not be transferred.
  * Calls CATIVVSVaultCheck::CheckURLs to get information about URLs (including the real physical path of the stream).
  * @param iUrls
  *   the list of URL to check
  * @oCheckReport
  *   Output structure that provides information for each provided URL.
  *   - Is it missing in the vault (if info not already provided as a specific error code during transfer) ?
  *   - The real physical path of the stream
  */
  HRESULT CheckURLs(const CATListOfCATVVSUrl &iUrls, CATVVSReports &oCheckReport ) ;

  /** 
  * Create a Url For a Url
  * @param iUrlToCache 
  * The url to cache
  * @param iTargetVaultSiteIdentifier
  * The identifier of the vault site that plays the role of the cache
  * @param oCachedUrl
  * The returned url
  * @param iTransaction   
  * Will be used in a later release
  * @return
  * S_OK if the url has been cached ,E_FAIL otherwise
  */
  HRESULT CreateUrlForUrlInCache(const CATVVSUrl& iUrlToCache,int iTargetVaultSiteIdentifier,CATVVSUrl& oCachedUrl,CATVVSTransaction* iTransaction=NULL) ;

  /** 
  * Copy a url on another url
  * @param iSourceURL 
  * The url to copy
  * @param iTargetURL
  * The url on to copy
  * @param iTransaction   
  * Will be used in a later release
  * @param iLockSrcIlb   
  * Is the source URL need to be locked when copying to dest URL (OS exclusif access)
  * @return
  * S_OK if it worked ,E_FAIL otherwise
  */
  HRESULT CopyUrlToUrl (const CATVVSUrl& iSourceURL, const CATVVSUrl& iTargetURL, CATVVSTransaction* iTransaction=NULL, CATBoolean iLockSrcIlb=TRUE);

  /**
  * Copy a list of Urls to a list of Urls
  *  <b>Role</b>:Copy a list of URls to a list of URLs with performance.
  * @param iSourceListURL [in]
  * The list of urls to read
  * @param iTargetListURL [in]
  * The list of urls to write
  * @param ipTransaction [in]
  * The transaction will be used in a later release
  * @return
  * S_OK if the urls have been copied ,E_FAIL otherwise
  */
#ifndef CATIAR423
  HRESULT CopyUrlsToUrls (const CATOmxArray<CATVVSUrl> & iSourceListURL, const CATOmxArray<CATVVSUrl>& iTargetListURL, CATVVSTransaction* iTransaction=NULL, CATVVSAsyncTransfertQuery* pMessage=NULL);
#else
  HRESULT CopyUrlsToUrls (const CATOmxArray<CATVVSUrl> & iSourceListURL, const CATOmxArray<CATVVSUrl>& iTargetListURL, CATVVSTransaction* iTransaction=NULL);
#endif   
  
  /**
  * @deprecated V6R2020x 
  * Use CopyUrlToUrl with CATOmxArray<CATVVSUrl>
  */  

#ifndef CATIAR423
  HRESULT CopyUrlToUrl (const CATListOfCATVVSUrl& iSourceListURL, const CATListOfCATVVSUrl& iTargetListURL, CATVVSTransaction* iTransaction=NULL,CATVVSAsyncTransfertQuery* pMessage=NULL)
#else
  HRESULT CopyUrlToUrl (const CATListOfCATVVSUrl& iSourceListURL, const CATListOfCATVVSUrl& iTargetListURL, CATVVSTransaction* iTransaction=NULL)
#endif
    {
      CATOmxArray<CATVVSUrl> omxListSourceofURL = VVS::Sys2Omx_Urls(iSourceListURL);
      CATOmxArray<CATVVSUrl> omxListTargerofURL = VVS::Sys2Omx_Urls(iTargetListURL);
      return CopyUrlsToUrls(omxListSourceofURL,omxListTargerofURL,iTransaction);
    }
  
  /**
  * Download a list of Urls to a list of Urls
  *  <b>Role</b>:Download a list of URls to a list of URLs with MassiveCopy call
  * @param iSourceListURL [in]
  * The list of urls to read
  * @param iTargetListURL [in]
  * The list of urls to write
  * @param ipTransaction [in]
  * The transaction will be used in a later release
  * @return
  * S_OK if the urls have been downloaded ,E_FAIL otherwise
  */
  HRESULT DownloadUrls(const CATOmxArray<CATVVSUrl>& iSourceListURL, const CATOmxArray<CATVVSUrl>& iTargetListURL, CATVVSTransaction* ipTransaction=NULL,
                       CATBoolean iMD5CheckedByFCS=TRUE);

  /**
  * Check out files using the FCS ticket asyncronously
  *  <b>Role</b>:Check out files using the FCS ticket asyncronously
  * @param iSourceListURL [in]
  * The list of urls to read
  * @param iTargetListURL [in]
  * The list of urls to write
  * @return
  * S_OK if the urls have been downloaded ,E_FAIL otherwise
  */
  HRESULT DownloadUrlsAsync(const CATOmxArray<CATVVSUrl> &iFromUrlList,const CATOmxArray<CATVVSUrl> &iToUrlList,
                            CATVVSAsyncObject& iVVSAsyncObject);
  
  /**
  * Upload a list of Urls to a list of Urls
  *  <b>Role</b>:Upload a list of URls to a list of URLs with MassiveSend call
  * @param iSourceListURL [in]
  * The list of urls to read
  * @param iTargetListURL [in]
  * The list of urls to write
  * @param ipTransaction [in]
  * The transaction will be used in a later release
  * @return
  * S_OK if the urls have been uploaded ,E_FAIL otherwise
  */
  HRESULT UploadUrls(const CATOmxArray<CATVVSUrl>& iSourceListURL, const CATOmxArray<CATVVSUrl>& iTargetListURL, CATVVSTransaction* ipTransaction=NULL,const CATOmxArray<CATMD5>* iSourceMD5List=NULL);

  /**S
  * Copy an ILB2 data to an other ILB2
  * @param iSourceILB2
  *        The data will be copied from this ILB2
  * @param iTargetILB2
  *        The data will be copied to this ILB2
  */
  HRESULT CopyILB2ToILB2 (CATILockBytes2 * iSourceILB2, CATILockBytes2 * iTargetILB2, DWORD iMode=0);  

  /** 
  * Get URL prefixes managed by a Vault Site.
  * <br><b>Role</b>: This method helps to create an URL template in order to create an URL in a Vault Site (via CreateUrlFromUrlWithinSite)
  * @param iTargetVaultSiteIdentifier [in]
  *   The vault site.
  * @param oListofURLPrefix [out]
  *   The list of Url Prefixes.
  * @param iTransaction [in]
  *   The transaction will be used in a later release.
  * @return
  *   <code>S_OK</code> if everything ran ok, E_FAIL otherwise.
  */
  HRESULT GetVaultSiteUrlPrefixes(int iTargetVaultSiteIdentifier, CATListOfCATVVSUrl& oListofURLPrefix, CATVVSTransaction* iTransaction = NULL);

  /** 
  * Get the size of streams identified by Urls.
  * @param iListofURL [in]
  *   The list of Urls
  * @param oStreamSizes [out]
  *   The size of streams
  * @param iTransaction [in]
  *   The transaction will be used in a later release.
  * @return
  *   <UL>
  *     <LI><code>S_OK</code> if everything ran ok, E_FAIL otherwise.</LI>
  *     <LI><code>E_INVALIDARG</code> if everything iListOfUrl is empty, or oStreamSizes is not empty.</LI>
  *     <LI><code>E_FAIL</code> if an error occured.</LI>
  *   </UL>
  */
  HRESULT GetSizeOfAWStream(const CATVVSUrl &iURL, CATVVSStreamSizes &oStreamSizes);
  HRESULT GetSizeOfStreams(CATListOfCATVVSUrl& iListofURL, CATVVSStreamSizes& oStreamSizes, CATVVSTransaction* iTransaction = NULL);
  HRESULT GetSizeOfStreams(const CATOmxArray<CATVVSUrl> &iListofURL, CATVVSStreamSizes& oStreamSizes, CATVVSTransaction* iTransaction = NULL);

  /**
  * Start a Virtual Vault System transaction.
  * This might be needed if your operations involve working with a
  * transactional vault site.
  *
  * You must have obtained a correct CATVVSTransaction from the Adapter
  * before starting to work with the VirtualVaultSystem that way.
  *
  * @param iTransaction [in]
  *   The transaction object to identify this transaction.
  * @return
  *   <code>S_OK</code> if everything ran ok, E_FAIL otherwise.
  */
  HRESULT StartTransaction(CATVVSTransaction* iTransaction);

  /**
  * End a Virtual Vault System transaction.
  * This might be needed if your operations involve working with a
  * transactional vault site.
  *
  * You must have obtained a correct CATVVSTransaction from the Adapter
  * before starting to work with the VirtualVaultSystem that way.
  *
  * @param iTransaction [in]
  *   The transaction object to identify this transaction.
  * @return
  *   <code>S_OK</code> if everything ran ok, E_FAIL otherwise.
  */
  HRESULT EndTransaction(CATVVSTransaction* iTransaction);

  /** 
  * Indicate whether the vault site in charge of the input url support LargeFile protocol
  *
  * @param iUrl
  *  LargeFile Url
  * @return
  *  <ul><li><code>S_OK</code>: the vault site supports LargeFile protocol</li>
  *      <li><code>S_FALSE</code>: the vault site does not support LargeFile protocol</li>
  *      <li><code>E*</code>: unexpected error.</li>
  *  </ul>
  */
  HRESULT SupportLargeFile(const CATVVSUrl& iUrl);

  /** 
  * Creates an URL that can be used to create Hardlink.
  * <role/>
  * The path is implicitly stored in the output url, it can be retrieve with the service <code>ConvertHardLinkUrlToPath</code>
  * In M1, this url contains the path of the WorkingDir and of the StagingDir
  * @param iRelativeUrl
  *  Callers must provide a file name and eventually some subdirectories in which the hard link has to be created via the Identifier field of the VVSUrl. 
  *  For Example : dir1/dir2/file.extension
  * @param oCompleteUrl  
  *  Url containing the file access.
  *  Note: The Site field of the Url indicates which logical file system stores the file
  * @return
  *  <ul><li><code>S_OK</code>: the file was successfully created.</li>
  *      <li><code>E_ACCESSDENIED</code>: The path already contains a file .</li>
  *      <li><code>E*</code>: unexpected error.</li>
  *  </ul>
  */
  HRESULT ComputeURLForLargeFileAccess(const CATVVSUrl& iRelativeUrl, CATVVSUrl& oCompleteUrl);

  /** 
  * Create a hard link to an existing file
  * @param iSrcUrl
  *  Url pointing to an existing file
  * @param oTgtUrl  
  *  Url containing the hard link to the file.
  * @param iRelativeUrl
  *  Callers must provide a file name and eventually some subdirectories in which the hard link has to be created via the Identifier field of the VVSUrl. 
  *  For Example : dir1/dir2/file.extension
  *  The path is implicitly stored in the output url, it can be retrieve with the service <code>RetrieveHardLinkFromUrl</code>
  * @return
  *  <ul><li><code>S_OK</code>: the hard link was successfully created.</li>
  *      <li><code>E_UNEXCPECTED</code>: the source file does not exist.</li>
  *      <li><code>E*</code>: unexpected error.</li>
  *  </ul>
  */
  HRESULT CreateHardLink(const CATVVSUrl& iSrcUrl, const CATVVSUrl& iRelativeUrl, CATVVSUrl& oTgtUrl);

  /** 
  * Retrieve the valid full file path of the hardlink 
  *
  * @param iSrcUrl
  *  Hardlink Url pointing to an existing file 
  * @param oFullPath  
  *  The hardlink full path 
  * @return
  *  <ul><li><code>S_OK</code>: the hard link was successfully created.</li>
  *      <li><code>E_UNEXCPECTED</code>: the source file does not exist.</li>
  *      <li><code>E*</code>: unexpected error.</li>
  *  </ul>
  */
  HRESULT ConvertHardLinkUrlToPath(const CATVVSUrl& iSrcUrl, CATUnicodeString & oFullPath);


  /** 
  * Indicates whether the ressources can be accessed as a file
  *
  * @param iUrl
  *  input URL
  * @return
  *  <ul><li><code>S_OK</code>: ressources can be accessed as a file. file:// url can be converted thanks to FromUrlToNativeFilePath</li>
  *      <li><code>S_FALSE</code>ressources cannot be accessed as a file</li>
  *      <li><code>E*</code>: unexpected error.</li>
  *  </ul>
  */
  HRESULT SupportFileAccess(const CATVVSUrl& iUrl);

  /**
  * This method writes a char* buffer into a 'file' using the ILB infrastructure..
  * As a consequence, buffer can be writtent in a file, in an arhcive file, in a DRMised file.. and so on.
  * In case of error, content pointed by iTargetUrl is removed
  * @param iTargetUrl   : Where to write the buffer. It can be a file, PW, AW URL
  * @param iBuffer      : buffer to be written
  * @param iSizeToWrite : Size of the buffer to write
  * @return
  *   S_OK : success
  *   E_*  : write has failed. Content of iTargetUrl has been removed
  *   E_INVALIDARG : Unsupported target URL protocol
  */
  HRESULT AppendBufferInUrl(const CATVVSUrl& iTargetUrl,char* iBuffer, CATULONG32 sizeToWrite);
    
    
   /** 
   * Get the stream MD5. MD5 has been computed at insertion in the vault site
   * @param iUrl [in]
   *   The Url of stream
   * @param oMD5 [out]
   *   The MD5 Value
   * @return
   *   <code>S_OK</code> if everything ran ok, 
   *   <code>E_NOTIMPL</code> Vault site does not support MD5 Computation
   *   <code>E_INVALIDARG</code> MD5 is not activated for the vaultsite
   *   <code>E*</code> unexepcted error
   */
  HRESULT GetStreamMD5(const CATVVSUrl& iUrl,CATMD5& oMD5) const;

  /** 
   * Compute the MD5 of a file and check its value matches the one it had when createds
   * @param iUrl [in]
   *   The Url of stream
   * @return
   *   <code>S_OK</code> if everything ran ok, 
   *   <code>E_NOTIMPL</code> Vault site does not support MD5 Computation
   *   <code>E_INVALIDARG</code> MD5 is not activated for the vaultsite
   *   <code>E*</code> Stream is corrupted
   */
  HRESULT CheckStreamIntegrity(const CATVVSUrl& iUrl) const;

  CATVVSUrlAndStreamManager(const CATUnicodeString& iSessionName)
    {}
  CATVVSUrlAndStreamManager()
    {}
  ~CATVVSUrlAndStreamManager()
    {}
};

#endif


