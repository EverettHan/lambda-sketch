//===================================================================
// COPYRIGHT Microsoft 2012/12/17
//===================================================================
// CATAsyncAutoCompleteRequest.cpp
// Header definition of class CATAsyncAutoCompleteRequest
//===================================================================
//
// Usage notes:
//
//===================================================================

#ifndef CATAsyncAutoCompleteRequest_H
#define CATAsyncAutoCompleteRequest_H

#include "CATPLMAsync.h"
#include "CATAsyncStreamedRequest.h"

class CATIAsyncTaskCompletionCallBackBase;
class CATPLMCompletionSuggestionOutput;

//-----------------------------------------------------------------------

class ExportedByCATPLMAsync CATAsyncAutoCompleteRequest: public CATAsyncStreamedRequest
{
public:

  struct Params : public CATAsyncStreamedRequest::Params
  {
    CATUnicodeString StrToSearch;
  };

  struct Result : public CATAsyncRequest::Result
  {
    CATOmxSR<CATPLMCompletionSuggestionOutput> CompletionSuggestionOutput;
  };
  
  /**
  * Constructor
  *
  * @param
  * <br/> [in] iStrToSearch: ...
  */
  CATAsyncAutoCompleteRequest(const Params& iParams);
  
  /**
  * Destructor
  */
  virtual ~CATAsyncAutoCompleteRequest ();

  /**
  * ...
  *
  * @return [CATUnicodeString]
  */
  CATUnicodeString GetStrToSearch() { return _strToSearch; }

  /**
  * ...
  *
  * @return [CATPLMCompletionSuggestionOutput]
  */
  CATPLMCompletionSuggestionOutput*& GetCompletionSuggestionOutput() { return _pCompletionSuggestionOutput; }

  /**
  * ...
  *
  * return [CATAsyncTaskContext]
  */
  virtual void AddExecResultInContext(CATAsyncTaskContextBase & ioAsyncTaskContext);

  virtual HRESULT SetNotifyProgress(CATBoolean ibNotifyProgress) { return E_NOTIMPL; }

  virtual const char * GetRequestName() { return "Auto Complete"; }

  /**
  * Return TRUE if request can be run synchronously, FALSE otherwise
  *
  * @return [CATBoolean]
  */
  virtual CATBoolean HandleSyncRun() { return FALSE; }

  /**
  * Run the request synchronously
  *
  * @return [Status], the end status request
  */
  virtual void RunSync(CATIAsyncTaskCompletionCallBackBase * ipAsyncTaskCompletionCallBack);

  /**
  * Callback with extented context
  */
  virtual void ExtendedContextCallBack(CATIAsyncTaskCompletionCallBackBase * ipAsyncTaskCompletionCallBack);

private:

  virtual HRESULT GetStreamedQuery(CATUnicodeString& oStreamedInput);

  virtual HRESULT GetOutput(int iOutputIndex, void**& opStreamedOutput);

  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncAutoCompleteRequest (CATAsyncAutoCompleteRequest &);
  CATAsyncAutoCompleteRequest& operator=(CATAsyncAutoCompleteRequest&);

  CATPLMCompletionSuggestionOutput * _pCompletionSuggestionOutput; // ...
  CATUnicodeString _strToSearch;

};

//-----------------------------------------------------------------------

#endif
