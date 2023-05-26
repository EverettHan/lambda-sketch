/**
 * @level Private
 * @usage U3
 */
/* -*-c++-*- */
#ifndef CATIVVSURLStreamHandler_h
#define CATIVVSURLStreamHandler_h

// COPYRIGHT DASSAULT SYSTEMES 2004


#include "CATBaseUnknown.h"
#include "CATVVSUrl.h"
#include "CATVVSURLConnection.h"

#include "CATVVSNetBase.h"
#include "CATIVVSURLStreamHandler.h"
extern ExportedByVVSNetBase IID IID_CATIVVSURLStreamHandler;

/**
 * Interface .
 */

class ExportedByVVSNetBase CATIVVSURLStreamHandler: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
   * Returns an object that represents the connection to the stream identified by the url
   * @param iUrl 
   * The retrieved connection
   * @param oConnection 
   * The retrieved connection .
   * The responsible of the lifecycle of this connection is the caller of this method.
   * This object is not managed by AddRef/Release.
   * The lifecycle of the connection is done by the caller of this method.
   * @return
   * S_OK if the connection was succesfully created, or E_FAIL otherwise
  */  
  virtual HRESULT OpenConnection(const CATVVSUrl& iUrl,CATVVSURLConnection& oConnection) = 0;

};

CATDeclareHandler(CATIVVSURLStreamHandler, CATBaseUnknown);

#endif
