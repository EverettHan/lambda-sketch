//===================================================================
// COPYRIGHT Dassault Systemes 2015/07/08
//===================================================================
// AfrMessageCompiler.h
// Definition of Publisher for AfrMessageNotification Allowing
// Services to append parameter for the client's response.
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/07/08 Creation: Code generated by HEB
//===================================================================

#ifndef AfrMessageCompiler_H
#define AfrMessageCompiler_H

#include "AfrComputeServer.h"
#include "CATCallbackManager.h"

class ExportedByAfrComputeServer AfrMessageCompiler: public CATCallbackManager
{
    public:
      CATDeclareClass;
      static AfrMessageCompiler& GetAfrMsgCompiler();
    private:
        AfrMessageCompiler();
        AfrMessageCompiler(AfrMessageCompiler const&);   // Do not implement
        void operator=(AfrMessageCompiler const&);       // Do not implement

};
#endif
