/**
 * @fullreview HEB 15:08:14
 */
#ifndef AfrOperationDeclaration_H
#define AfrOperationDeclaration_H

// COPYRIGHT DASSAULT SYSTEMES 2015

#include "AfrComputeServer.h"
#include "CSIPool.h"
#include "CSICommands.h"


/**
 *  Undo and redo Operations Declaration
 * <b>Role</b>: Declare in ipool following Operations:
 *               AfrStartStopCommandOperation
 *               AfrUndoOperation
 *               AfrRedoOperation
 *               AfrFlushUndoRedoStacksOperation
 */

ExportedByAfrComputeServer HRESULT DeclareUndoRedoOperation (CSI::Pool& ipool, CSI::Commands& iCmd);

ExportedByAfrComputeServer HRESULT DeclareStartStopCommandOperation (CSI::Pool& ipool, CSI::Commands& iCmd);

/*class AfrOperationsParameters {
  public : 
    AfrOperationsParameters(int iMsg=-1):_msg(iMsg){}

    int GetMsg() const {return _msg;}

    bool operator == (const AfrOperationsParameters& iParams) const {return _msg == iParams._msg;}

  private:
    int _msg;
};

ExportedByAfrComputeServer HRESULT serializeAfrOperationsParameters(CSI::Parameters& oParams, AfrOperationsParameters& iParams);

ExportedByAfrComputeServer AfrOperationsParameters* unserializeAfrOperationsParameters(CSI::Parameters& iParams);*/


#endif

