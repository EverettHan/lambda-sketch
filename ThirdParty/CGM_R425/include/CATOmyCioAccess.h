// COPYRIGHT Dassault Systemes 2005
//===================================================================
/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyCioAccess_H
#define CATOmyCioAccess_H

#include "CATOMYCuteIOAccess.h"

// CATVirtualVaultSystem
#include "CATVVSFileDescriptionServices.h"
#include "CATVVSUrl.h"

// ObjectModelerCollection
#include "CATOmxList.h"

// ObjectModelerSystem
#include "CATAsyncBasicTypes.h"
#include "CATListOfCATOmyCioUrlUsageCtx.h"

class CATIOmyCioNotifier;
class CATOmyStreamSizes;

/**
 * Enable Consumer Applications (Cache, PDM System)
 * to Create, Clone , Release URLs and Access Streams for Read or Write Purpose.
 */
class ExportedByCATOMYCuteIOAccess CATOmyCioAccess
{
  public:

   /** 
     * Duplicates given URL list in local cache.
     * <br><b>Role</b>: This method tries to copy all asked URL in appropriate caches and 
     * set the statuts of all duplication in <code>iCallBack</code> notifier.
     * @param ioCallBack [inout]
     *   This notifier indicates for each URL, if CuteIO has opened successfully the connection on cached stream or not.
     * @param iSelection [in]
     *   The list of URL to cache.
     * @param oMissingSelection[out]
     *   The list of URL requested that couldn't be cached
     * @return
     *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL.
     */
   HRESULT OpenConnections(const CATIOmyCioNotifier* iCallBack, const CATListOfCATOmyCioUrlUsageCtx& iSelection);
   HRESULT OpenConnections(const CATIOmyCioNotifier* iCallBack, const CATOmxList<CATOmyCioUrlUsageCtx>& iSelection);
   HRESULT OpenConnections(const CATIOmyCioNotifier* iCallBack, const CATOmxList<CATOmyCioUrlUsageCtx>& iSelection, CATOmxList<CATOmyCioUrlUsageCtx>& oMissingSelection);
   
   /** 
     * @deprecated : to be removed shortly
     * Asserts when used
     */
   HRESULT FetchStreamsInCache (const CATIOmyCioNotifier* iCallBack, const CATListOfCATOmyCioUrlUsageCtx& iSelection);
        
   /**
    * Get the size of streams identified by their URL.
    * @param iUrls [in]
    *	The list of Urls that identifies streams.
    * @param oStreamSizes
    *	The list of streams size.
    */
   HRESULT GetSizeOfStreams(const CATListOfCATOmyCioUrlUsageCtx& iUrlCtxs, CATOmyStreamSizes& oStreamSizes) const;
   HRESULT GetSizeOfStreams(const CATOmxList<CATOmyCioUrlUsageCtx>& iUrlCtxs, CATOmyStreamSizes& oStreamSizes) const;  

   /**
    * Get the pointed urls of the of streams identified by their URL.
    * @param iUrlCtxs [in]
    *	The list of Urls that identifies streams.
    * @param oPointedUrl
    *	The list of pointed url.
    */   
   HRESULT GetPointedUrls(const CATOmxList<CATOmyCioUrlUsageCtx>& iUrlCtxs, CATOmxArray<CATVVSUrl> &oPointedUrl, CATOmxArray<HRESULT>& oFilesStatus);     
    
   HRESULT GetPointedLocalData(const CATOmxList<CATOmyCioUrlUsageCtx>& iUrlCtxs, CATOmxList<FileDescriptionData>& oLocalData, CATOmxArray<HRESULT>& oResults);
    
    CATOmyCioAccess();
   ~CATOmyCioAccess();
};

#endif


