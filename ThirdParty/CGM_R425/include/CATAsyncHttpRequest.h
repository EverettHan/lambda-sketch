//===================================================================
// COPYRIGHT Microsoft 2012/02/14
//===================================================================
// CATAsyncHttpRequest.cpp
// Header definition of class CATAsyncHttpRequest
//===================================================================
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED
//===================================================================
// -> MIGRATION MIGRATION MIGRATION (consequence of incident IR-852480 log out of dashboard)
// Suppose you use following pattern and that you are connected to 3DSpace:
// HR = AsyncTasksFactory.CreateAsyncPhysicalTask<CATAsyncHttpRequest>(HTTPTaskId, HTTPParams, *iAsyncTaskCompletionCB, HTTPParentTaskId);
// At least, please migrate on following code:
// HR = AsyncTasksFactory.CreateAsyncPhysicalTask<CATAsyncHttpOn3DSpaceRequest>(HTTPTaskId, HTTPParams, *iAsyncTaskCompletionCB, HTTPParentTaskId);
//
// If you have enough time, please migrate on following code:
// CATOmxSR<CATOmxHttpPost> spTempRequest(new CATOmxHttpPost(<url>), Steal);
// spTempRequest->SetServiceName("CloudView" or "3DSpace" or "VisuService" ...);
// {
//   CATOmxSR<CATOmxHttpEntity> spEntity(new CATOmxHttpStringEntity(<your query using MQL, JSON or any other language>), Steal);
//   spTempRequest->SetEntity(spEntity);
// }
// CATOmxSR<CATOmxHttpRequest> spRequest(spTempRequest);
//
// spRequest->AddHeader(<header 1>);
// ...
// spRequest->AddHeader(<header N>);
//
// CATOmxSR<CATOmxHttpResponse> spResponse;
// CATOmxSR<CATOmxHttpClient> spHttpClient(new CATOmxDefaultHttpClient(FALSE), Steal);// http of SYSTEM layer is used
//
// if (FAILED(spHttpClient->Execute(*spRequest, spResponse.AsPtrRef())) || !spResponse)
// {
//   return E_FAIL;
// }
//
// CATOmxHttpStatusLine httpStatus = spResponse->GetStatusLine();
// if (httpStatus.GetStatusCode() != 200)
// {
//   return E_FAIL;
// }
//
// CATOmxSR<CATOmxHttpEntity> spEntity(spResponse->GetEntity(), Steal);// MLK
// if (spEntity != NULL)
// {
//   CATOmxSR<CATIOmxInputStream> spInputStream;
//   CHK_SUCCESS_AND_RET_HR(spEntity->GetContent(spInputStream.AsPtrRef()));
//
//   CATOmxUTF8String utf8String;
//   CHK_SUCCESS_AND_RET_HR(CATOmxIOUtils::ToString(spInputStream, utf8String));
//   if (utf8String.length() == 0)
//   {
//     return E_FAIL;
//   }
// }
//
// Why do you have to perform this migration?
// Thanks to this migration, (re) authentication will be managed properly
// <-
//===================================================================
//  2012/02/14 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncHttpRequest_H
#define CATAsyncHttpRequest_H

#include "CATAsyncSplittableRequest.h"
#include "CATAsyncHttpArgs_NG.h"
#include "CATSysMultiBuffer.h"
#include "CATA5CsvRow.h"
#include "CATIAV5Level.h"

//-----------------------------------------------------------------------
typedef CATULONG64 CATAsyncHttpTaskId; // to be identical to CATAsyncRequestId

class ExportedByCATOMYHTTP CATAsyncHttpRequest: public CATAsyncSplittableRequest
{  
public:

  enum RequestType
  {
    post    =0,
    get     =1,
    put     =2,
    del     =3,
    head    =4,
    options =5,
    trace   =6,
    connect =7
  };  
  
  // Params
  // -------------------------------------
  struct ExportedByCATOMYHTTP Params : public CATAsyncRequest::Params
  {
    Params():
      CATAsyncRequest::Params(),Type(get){}
      
    RequestType      Type;
    CATAsyncHttpArgs Args;
  };


  // Context
  // -------------------------------------
  class ExportedByCATOMYHTTP Result : public CATAsyncRequest::Result
  {
    public:
      Result();
      Result(const Result&);
      ~Result();
      
      HRESULT GetHTTPFullAnswer(CATSysTSUnicodeString& oUrl, CATSysTSUnicodeString& oPostArgs, CATSysMultiBuffer*& opMultiBuffer);
      HRESULT SetHTTPFullAnswer(const CATSysTSUnicodeString& iUrl, const CATSysTSUnicodeString& iPostArgs, CATSysMultiBuffer * ipMultiBuffer);

      HRESULT GetCATA5Parser(CATA5::Parser*& opParser);
      HRESULT SetCATA5Parser(CATA5::Parser* iParser);
      
      HRESULT GetHTTPErrorCode(unsigned int& oErrorCode) {oErrorCode=_HttpErrorCode; return S_OK;}
      HRESULT SetHTTPErrorCode(unsigned int iErrorCode) {_HttpErrorCode=iErrorCode; return S_OK;}

      void GetHTTPFullHeaders(CATAsyncDictionary & oFullHeaders) {oFullHeaders=_FullHeaders;}
      void SetHTTPFullHeaders(CATAsyncDictionary & iFullHeaders) {CATAssert(_FullHeaders.Size()==0) ; _FullHeaders = iFullHeaders;}
    
    protected:    
      
      CATOmxSR<CATA5::Parser>   _spResultParser;
      
    private:
    
      CATSysTSUnicodeString     _url;
      CATSysTSUnicodeString     _postArgs;
      CATSysMultiBuffer*        _pHttpFullAnswer;
      unsigned int              _HttpErrorCode;
      CATAsyncTaskStatus*       _pTaskStatus;
      CATAsyncDictionary        _FullHeaders;
  };
 
  /**
  * Constructor
  *
  * @param
  * <br/> [in] iSelection: ...
  * <br/> [in] iAsyncTaskCompletionCallBack: ...
  */
  CATAsyncHttpRequest (const Params& iParams);
  
  /**
  * Destructor
  */
  virtual ~CATAsyncHttpRequest ();

private:

  /**
  * CATAsyncRequest Implementation
  */
  virtual const char *                        GetRequestName() { return "HTTP"; }
  virtual CATAsyncRequestsPlatform_Type       GetWorkablePlatform();
  virtual CATIAsyncRequestsPlatformStrategy * CreatePlatformInstance(CATAsyncRequestsPlatform_Type platformType);

  /**
  * Return TRUE if request can be run synchronously, FALSE otherwise
  *
  * @return [CATBoolean]
  */
  virtual CATBoolean HandleSyncRun() { return FALSE; }

  /**
  * Callback with extented context
  */
  virtual void ExtendedContextCallBack(CATIAsyncTaskCompletionCallBackBase * ipAsyncTaskCompletionCallBack);

  /**
  * CATAsyncSplittableRequest
  * Not Implemented
  */
  virtual CATBoolean IsEnoughElements() { return FALSE; }

  virtual HRESULT GetSubRequests(CATOmxVector<CATAsyncRequest>& oSubRequestsvector, CATBoolean ibAllSubRequests) { return E_NOTIMPL; }

  virtual HRESULT GetElementAdder(ElementsAdder& oElementAdder) { return E_NOTIMPL;}

  virtual HRESULT SetDuplicateElementsExt(AsyncBuilderDuplicateElements iDuplicateElements) { return E_NOTIMPL;}

public:
  
  // GetUrl returns the URL specified by the caller of the request
  const CATSysTSUnicodeString& GetUrl() const       {return _HttpArgs._url;}
  // GetActualUrl returns the URL to work on. If none specified by the caller then try to select the connected server
  CATUnicodeString             GetActualUrl();
  
  virtual HRESULT SetNotifyProgress(CATBoolean ibNotifyProgress) {return E_NOTIMPL;}

  virtual void AddExecResultInContext(CATAsyncTaskContextBase & ioAsyncTaskContext) 
  {
    CATAsyncTaskContext<CATAsyncHttpRequest>::ExtendCtxBase(ioAsyncTaskContext);
  }
  
  virtual CATBoolean                  CheckValidity();
  virtual RequestType                 GetRequestType() const       {return _RequestType;}
  virtual CATSysTSUnicodeString       GetPostArg()                 {return _HttpArgs._PostArgsString; }
  virtual const ListOfPostParams_iter GetPostArgAsList()           {return _HttpArgs._PostArgsList.Iterator(); }
  virtual CATBoolean                  NeedUrlEncoding()            {return _HttpArgs._PostArgsList.Size() > 0; }
  virtual const ListOfPostParams_iter GetMultiPartInfo() const     {return _HttpArgs._FilesToUpload.Iterator();}
  virtual RequestHeaders_iter         GetRequestHeaders() const    {return _HttpArgs._RequestHeaders.Iterator();  }
  virtual CATBoolean                  RequestPartialCB() const     {return _HttpArgs._PartialCB;}  
  virtual CATA5::Parser *             GetInputParser() const       {return _HttpArgs._spParserToUse.Ref();}
  virtual CATBoolean                  GetCompressionStatus() const {return _HttpArgs._CompressionStatus;}
  virtual const char*                 GetRequestExtType() {return ".txt"; }
  virtual const char*                 GetAnswerExtType() const{return ".txt"; }
  virtual HRESULT                     Connect() {return E_NOTIMPL;}
  virtual CATBoolean ConnectIfNecessary() const   {return _HttpArgs._ConnectIfNecessary; }

#ifdef CATIAR423
  virtual void SetAuthenticationType(DSYSysIsTimeoutService iServiceType) { return _HttpArgs.SetAuthenticationType(iServiceType); }

  virtual DSYSysIsTimeoutService GetAuthenticationType() const { return _HttpArgs.GetAuthenticationType(); }
#endif

  virtual HRESULT IsHandled();

  /*
  * Returns the request's SysHttp listener.
  * It gives the ability to get called back by http layer when his lifecycle change (chunk read/sent... etc).
  * Return NULL is allowed, then the request will not be added to the http layer's listeners, and thus will not be notified of http layer's state changes.
  * The listener is addrefed and must be released (DSYSysRefCounter).
  *
  * @return
  *   The addrefed SysHttp listener. Null is allowed.
  */
  virtual CATAsyncSysHttpListener* GetSysHttpListener() { return NULL; };

protected:

  // CTOR
  CATAsyncHttpRequest (CATAsyncRequest_Type iRequestType, CATAsyncAnswer_Type iAnswerType, CATBoolean ibFinal, const CATAsyncRequest::Params& iParams);
  
  CATAsyncHttpArgs _HttpArgs;
  RequestType      _RequestType;
  CATUnicodeString _ActualUrl;

  CATBoolean IsUrlValid();
  
private:
  
  CATBoolean IsThereDataToPost();
  CATBoolean ArePostArgsAuthorized();
  
  CATAsyncHttpRequest (const CATAsyncHttpRequest &); // NOT IMPLEMENTED
  CATAsyncHttpRequest& operator=(const CATAsyncHttpRequest&); // NOT IMPLEMENTED   
};

#endif
