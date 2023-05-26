//===================================================================
// COPYRIGHT Microsoft 2012/02/14
//===================================================================
// CATAsyncPLMRequest.cpp
// Header definition of class CATAsyncPLMRequest
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/02/14 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATAsyncPLMRequest_H
#define CATAsyncPLMRequest_H

#include "CATPLMAsync.h"
#include "CATAsyncStreamedRequest.h"
#include "CATIOmyAsyncTaskCompletionCallBack.h"
#include "CATIPLMQueryFilter.h"
#include "CATIPLMExpandResultHandler.h"
#include "CATIAsyncTaskCompletionCallBackBase.h"
#include "CATOmxSR.h"

// PLMQL Progression Data Indexes
#define APD_RECORDS_DOWNLOADED  0
#define APD_RECORDS_TO_DOWNLOAD 1

class ExportedByCATPLMAsync CATAsyncPLMRequest: public CATAsyncStreamedRequest
{
public:

  struct Params : public CATAsyncStreamedRequest::Params
  {
    CATOmxSR<CATIPLMQueryFilter> QueryFilter;
  };

  struct ProgressData : public CATAsyncRequest::ProgressData
  {
    ProgressData():RecordsDownloadedCount(-1),RecordsToDownloadCount(-1){}
    CATLONG64 RecordsDownloadedCount; // CATAsyncTaskContext.ProgressionData[0] ; -1 is not relevant
    CATLONG64 RecordsToDownloadCount; // CATAsyncTaskContext.ProgressionData[1] ; -1 is not relevant
  };

  /**
  * Destructor
  */
  virtual ~CATAsyncPLMRequest ();

  /**
  * ...
  *
  * @return [CATIPLMQueryFilter*]
  */
  CATIPLMQueryFilter * GetQueryFilter() { return _spQueryFilter; }

  ProgressData& GetProgressData() { return _PLMProgressData; }

protected:

  /**
  * Constructor
  *
  * @param
  * <br/> [in] iQueryFilter: ...
  * <br/> [in] iAsyncTaskCompletionCallBack: ...
  */
  CATAsyncPLMRequest (CATAsyncRequest_Type iType, const Params& iParams);

  virtual void AddProgressDataInContext(CATAsyncTaskContextBase & ioAsyncTaskContext);

  ProgressData _PLMProgressData; // ...

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATAsyncPLMRequest (CATAsyncPLMRequest &);
  CATAsyncPLMRequest& operator=(CATAsyncPLMRequest&);

  /**
  * CATAsyncStreamedRequest Implementation
  */
  virtual HRESULT GetStreamedQuery(CATUnicodeString& oStreamedQuery);

  CATOmxSR<CATIPLMQueryFilter> _spQueryFilter; // ...

};

//-----------------------------------------------------------------------

#endif
