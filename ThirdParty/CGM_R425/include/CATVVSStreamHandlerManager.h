/**
 * @level Private
 * @usage U1
 */

#ifndef CATVVSStreamHandlerManager_H
#define CATVVSStreamHandlerManager_H

#include "CATUnicodeString.h"
#include "CATIVVSURLStreamHandler.h"
#include "VVSVaultSiteCptConsumer.h"
/**
 * 
 */
class ExportedByVVSVaultSiteCptConsumer CATVVSStreamHandlerManager
{
public:
  
  HRESULT GetStreamHandlerByType(const CATUnicodeString& iNameOfStreamType,CATIVVSURLStreamHandler*& oStreamObject) ;

  CATVVSStreamHandlerManager(const CATUnicodeString& sessionName)
    {}
  CATVVSStreamHandlerManager()
    {}
  ~CATVVSStreamHandlerManager()
    {}
};

#endif

