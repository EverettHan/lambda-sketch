//===================================================================
// COPYRIGHT Microsoft 2014/01/10
//===================================================================
//
//  CATIPLMMLEngineAsyncTaskCB.h
//  Define  the  CATIPLMMLEngineAsyncTaskCB interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
// Usage notes:
// need to implement this interface using adapter CATPLMMLEngineSyncAsyncAdapter
// eg:
//class TSTCATPLMMLEngineAsyncTaskCB : public CATPLMMLEngineSyncAsyncAdapter
//{
//  CATDeclareClass;
//public:
//  TSTCATPLMMLEngineAsyncTaskCB();
//  ~TSTCATPLMMLEngineAsyncTaskCB();
//  HRESULT OnTaskCompleted();
//};
//
//CATImplementClass( TSTCATPLMMLEngineAsyncTaskCB,Implementation,CATPLMMLEngineSyncAsyncAdapter,CATnull );
//
//#include "TIE_CATIPLMMLEngineAsyncTaskCB.h"
//TIEchain_CATIPLMMLEngineAsyncTaskCB(TSTCATPLMMLEngineAsyncTaskCB);
//
//
//TSTCATPLMMLEngineAsyncTaskCB::TSTCATPLMMLEngineAsyncTaskCB()
//  :CATPLMMLEngineSyncAsyncAdapter(),
//{}
//
//TSTCATPLMMLEngineAsyncTaskCB::~TSTCATPLMMLEngineAsyncTaskCB()
//{}
//
//HRESULT TSTCATPLMMLEngineAsyncTaskCB::OnTaskCompleted()
//{
//  // your own code
//  // all methods provided in adapter CATPLMMLEngineSyncAsyncAdapter are available here.
//}
//===================================================================
// Jan 2014    Creation:  EPB
//=================================================================== 

#ifndef CATIPLMMLEngineAsyncTaskCB_H
#define CATIPLMMLEngineAsyncTaskCB_H

#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces

#include "CATBaseUnknown.h"

#include "CATBoolean.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineAsyncTaskCB;
#else
extern "C" const IID IID_CATIPLMMLEngineAsyncTaskCB ;
#endif

class CATIPLMMLDicoNavNode;
class CATIPLMMLTable;
class CATUnicodeString;

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineAsyncTaskCB: public CATBaseUnknown
{
  CATDeclareInterface;
  friend class CATPLMMLSendAndReceiveAsyncCB;
public:

  /**
  * <br><b>Role</b>: Need to provide and implementation of this method
  * In the implementation of this method, all methods provided in adapter CATPLMMLEngineSyncAsyncAdapter are available.
  *
  * @param 0;
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT OnTaskCompleted() = 0;

  /**
  * <br><b>Role</b>: method implemented by adapter CATPLMMLEngineSyncAsyncAdapter. Don't reimplement it...
  * No access given to CATIPLMMLDicoNavNode.h
  *
  * @param ipRootNode
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT _SetRootNode(CATIPLMMLDicoNavNode* ipRootNode)=0;

  /**
  * <br><b>Role</b>: method implemented by adapter CATPLMMLEngineSyncAsyncAdapter. Don't reimplement it...
  * No access given to CATIPLMMLTable.h
  *
  * @param ipTable
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT _SetTable(CATIPLMMLTable* ipTable)=0;

};

CATDeclareHandler( CATIPLMMLEngineAsyncTaskCB, CATBaseUnknown );

#endif
