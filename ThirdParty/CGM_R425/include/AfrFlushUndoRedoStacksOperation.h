//===================================================================
// COPYRIGHT Dassault Systemes 2015/07/29
//===================================================================
// AfrFlushUndoRedoStacksOperation.cpp
// Header definition of class AfrFlushUndoRedoStacksOperation
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2015/07/29 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef AfrFlushUndoRedoStacksOperation_H
#define AfrFlushUndoRedoStacksOperation_H

#include "AfrInternalOperation.h"
#include "AfrComputeServer.h"

#include "CSIParameters.h"
#include "CSIMessage.h"

class l_AfrInternalOperation;

//-----------------------------------------------------------------------

class ExportedByAfrComputeServer AfrFlushUndoRedoStacksOperation: public AfrInternalOperation
{
  public:

    // Standard constructors and destructors
    // -------------------------------------
    AfrFlushUndoRedoStacksOperation (CSI::Node* ipNode);
    AfrFlushUndoRedoStacksOperation(CSI::Node& iNode);
    virtual ~AfrFlushUndoRedoStacksOperation ();

    HRESULT OnCommand(const CSI::Parameters& inputs, CSI::Channel& origin);
    HRESULT OnDisconnect();

  private:

    // Copy constructor and equal operator
    // -----------------------------------
    AfrFlushUndoRedoStacksOperation (AfrFlushUndoRedoStacksOperation &);
    AfrFlushUndoRedoStacksOperation& operator=(AfrFlushUndoRedoStacksOperation&);
        
};

  //-----------------------------------------------------------------------

#endif
