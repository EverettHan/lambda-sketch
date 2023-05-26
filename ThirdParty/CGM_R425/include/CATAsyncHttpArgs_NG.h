#ifndef CATAsyncHttpArgs_H
#define CATAsyncHttpArgs_H

#include "CATOMYHTTP.h"
#include "CATSysTSUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxPair.h"
#include "CATBoolean.h"
#include "CATA5Parser.h"
#include "CATOmxSR.h"
#include "CATAsyncHttpCollections.h"
#include "DSYSysDlgServices.h"
#include "CATIAV5Level.h"

class ExportedByCATOMYHTTP CATAsyncHttpParserBase : public CATOmxSharable
{

public:
  /**
    * CTOR 
    * @param iThreadSafe. If TRUE, the method ScanChunk will be possibly called in a secondary thread.
    * @param iSupportMultipleCalls. If TRUE, the method ScanChunk will be possibly called multiple times with p
    */
  CATAsyncHttpParserBase(CATBoolean iThreadSafe=FALSE, CATBoolean iSupportMultipleCalls=FALSE) : 
    _IsThreadSafe(iThreadSafe), _IsMultiCall(iSupportMultipleCalls)
    {}
  virtual ~CATAsyncHttpParserBase() 
    {}
  
  /**
    * Method to implement in specialized classes.
    * Parse the return headers.
    * Be aware that an unsucessful return code will stop the HTTP request and make it fail.
    */
  virtual HRESULT ScanHeaders(const char *iData, CATLONG64 iLen) = 0;
  
  /**
    * Method to implement in specialized classes.
    * Parse the returned data.
    * @param iData the UTF8 encoded data
    * @param iLen the data length
    * @param iLast notify the last chunk
    * Be aware that an unsucessful return code will stop the HTTP request and make it fail
    */ 
  virtual HRESULT ScanData(const char *iData, CATLONG64 iLen) = 0;
  
  /**
    * Called when the parsing is finished, i.e. all the data has been received or an error has occured.
    * In case of error, all the information is stored by the CATAsyncHttpRequest object.
    * Be aware that an unsucessful return code will stop the HTTP request and make it fail
    */ 
  virtual HRESULT DataScanningIsFinished() {return S_OK;} ;

private:

  CATBoolean _IsThreadSafe;
  CATBoolean _IsMultiCall;
};

class ExportedByCATOMYHTTP CATAsyncHttpArgs
{
public:

  CATAsyncHttpArgs();
  virtual ~CATAsyncHttpArgs();

#ifdef CATIAR423
  inline void SetAuthenticationType(DSYSysIsTimeoutService iServiceType) {
    _AuthenticationType = iServiceType;
  }

  inline DSYSysIsTimeoutService GetAuthenticationType() const{
    return _AuthenticationType;
  }
#endif
  
  CATSysTSUnicodeString            _url;
  
  CATOmxSR<CATA5::Parser>          _spParserToUse;
  
  ListOfRequestHeaders             _RequestHeaders; //devrait être CATSysTSUnicodeString mais en attendant la remonté du code d'OMCollection
    
  CATSysTSUnicodeString            _PostArgsString;  
  ListOfPostParams                 _PostArgsList; //devrait être CATSysTSUnicodeString mais en attendant la remonté du code d'OMCollection
  ListOfPostParams                 _FilesToUpload;//name;filepath filename is auto computed

  CATBoolean                       _PartialCB;
  CATBoolean                       _CompressionStatus;
  CATBoolean                       _ConnectIfNecessary;

private:
#ifdef CATIAR423
  DSYSysIsTimeoutService           _AuthenticationType;
#endif
};


#endif
