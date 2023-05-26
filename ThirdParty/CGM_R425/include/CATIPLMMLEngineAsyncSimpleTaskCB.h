//===================================================================
// COPYRIGHT Microsoft 2014/01/10
//===================================================================
//
//  CATIPLMMLEngineAsyncSimpleTaskCB.h
//  Define  the  CATIPLMMLEngineAsyncSimpleTaskCB interface
//
//===================================================================
// http://osmwebdsy/wiki/index.php/1-Modeler_Language_ML_or_MeuL:_Navigation
//===================================================================
// Usage notes:
//===================================================================
// Jan 2014    Creation:  EPB
//=================================================================== 

#ifndef CATIPLMMLEngineAsyncSimpleTaskCB_H
#define CATIPLMMLEngineAsyncSimpleTaskCB_H

#include "CATPLMModelerLanguage.h"          // CATPLMModelerLanguage ProtectedInterfaces

#include "CATBaseUnknown.h"

class CATIPLMCompRecordReadSet;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerLanguage IID IID_CATIPLMMLEngineAsyncSimpleTaskCB;
#else
extern "C" const IID IID_CATIPLMMLEngineAsyncSimpleTaskCB ;
#endif

class ExportedByCATPLMModelerLanguage CATIPLMMLEngineAsyncSimpleTaskCB: public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
  * <br><b>Role</b>: Need to provide and implementation of this method
  *
  * @param ipRecordSet
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT OnTaskCompleted(CATIPLMCompRecordReadSet* ipRecordSet) = 0;
};

CATDeclareHandler( CATIPLMMLEngineAsyncSimpleTaskCB, CATBaseUnknown );

#endif
