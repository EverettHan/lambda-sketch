/**
* @level Private
* @usage U3
*/

#ifndef VVSDummyVSCpt_H
#define VVSDummyVSCpt_H

#include "VVSDummyVaultSite.h"

#include "CATBaseUnknown.h"
#include "CATVVSUrl.h"
#include "CATListOfCATVVSUrl.h"
#include "CATIVVSVaultAccess.h"

class CATUnicodeString;
class CATVVSUnicodeStringHashtable;
class CATVVSUrl;
class CATVVSTransaction;
class CATVVSURLConnection;
class CATIVVSMassiveCopy;
class CATIVVSMassiveCopyAsync;
class CATVVSStreamSizes;
class CATUuid;

class ExportedByVVSDummyVaultSite VVSDummyVSCpt: public CATBaseUnknown
{
	CATDeclareClass;

public:

	VVSDummyVSCpt ()
    {}
	virtual ~VVSDummyVSCpt ()
    {}

	//CATIVVSSoftComponent
	virtual CATUnicodeString Get_ComponentName () const ;
	virtual CATUnicodeString Get_Version() const;
	virtual HRESULT Get_Property(const CATUnicodeString& iKey, CATUnicodeString& iValue) const
    {return E_NOTIMPL;}
	virtual HRESULT Set_Property(const CATUnicodeString& iKey, const CATUnicodeString& iValue) const
    {return E_NOTIMPL;}

	//CATIVVSSoftComponentLifeCycle
	virtual HRESULT Init (const CATVVSUnicodeStringHashtable&  iInitParameters ) ;
	virtual HRESULT Shutdown(const CATVVSUnicodeStringHashtable& iShutdownParameters) ;

	//CATIVVSVaultAccess
	virtual HRESULT OpenConnection (const CATVVSUrl&  iUrl  , CATVVSURLConnection&  oConnection  , CATVVSTransaction*  iTransaction =NULL)
    {return E_NOTIMPL;}
	virtual HRESULT CreateCopy(CATIVVSMassiveCopy *&opMassiveCopy,CATVVSTransaction* ipTransaction=NULL) const
    {return E_NOTIMPL;}
	virtual HRESULT GetSizeOfStreams(CATListOfCATVVSUrl& iUrls, CATVVSStreamSizes& oStreamSizes) const
    {return E_NOTIMPL;}
  virtual HRESULT CreateCopyAsync(CATIVVSMassiveCopyAsync *&opMassiveCopy, CATUuid& iTransactionId) const 
    {return E_NOTIMPL;}
  virtual HRESULT GetStreamMD5(const CATVVSUrl& iUrl,CATMD5& oMD5) const
    {return E_NOTIMPL;}
  virtual HRESULT CheckStreamIntegrity(const CATVVSUrl& iUrl) const
    {return E_NOTIMPL;}
    
	//CATIVVSVaultQueryByPLMId
	virtual HRESULT QueryUrl(const CATVVSUrl& iUrl , CATVVSTransaction* iTransaction=NULL)
    {return E_NOTIMPL;}
    
	//CATIVVSVaultUrlLifeCycleManager
	virtual HRESULT CreateUrlFromUrlPattern(const CATVVSUrl& iUrlPattern, CATVVSUrl& oUrl, CATVVSTransaction* iTransaction = NULL);
	virtual HRESULT CloneURL(const CATVVSUrl& iUrlSource, const CATVVSUrl& iUrlPattern, CATVVSUrl& oDuplicatedUrl, CATVVSTransaction* iTransaction = NULL)
    {return E_NOTIMPL;}
	virtual HRESULT ReleaseURL (const CATVVSUrl&  iUrl  , CATVVSTransaction*  iTransaction =NULL)
    {return E_NOTIMPL;}
	virtual HRESULT UrlPrefixToRegister (CATListOfCATVVSUrl&  oPrefixToRegister ) ;
	
	//CATIVVSHardLinkManager
  virtual HRESULT SupportLargeFile(const CATVVSUrl& iUrl)
    {return E_NOTIMPL;}
  virtual HRESULT ComputeURLForLargeFileAccess (const CATUnicodeString& iSubPath, CATVVSUrl& oCompleteUrl) 
    {return E_NOTIMPL;} 
  virtual HRESULT ConvertHardLinkUrlToPath(const CATVVSUrl& iSrcUrl, CATUnicodeString & oFullPath)
    {return E_NOTIMPL;}

private:

	VVSDummyVSCpt (const VVSDummyVSCpt &) = delete ;
	VVSDummyVSCpt& operator=(const VVSDummyVSCpt&) = delete ;

	CATVVSUrl _VaultUrlPattern;
};

#endif

