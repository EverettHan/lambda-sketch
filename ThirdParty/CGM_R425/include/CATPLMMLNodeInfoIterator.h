#ifndef CATPLMMLNodeInfoIterator_H
#define CATPLMMLNodeInfoIterator_H

#include "CATPLMModelerLanguage.h"

#include "CATIPLMMLDicoNavNodeCollec.h"

#include "CATOmxList.h"

#include "CATSysErrorDef.h"

class CATIPLMMLDicoNavNode;
class CATPLMMLNodeInfo;
class CATIPLMMLDicoNavNode;

class ExportedByCATPLMModelerLanguage CATPLMMLNodeInfoIterator
{
friend class CATPLMMLEngineSyncAsyncAdapter;
public:
  CATPLMMLNodeInfoIterator();
  virtual ~CATPLMMLNodeInfoIterator();

  /*
  * iterator giving Alias declared in Modeler Language (ML).
  * <br><b>Role</b>: iterator giving declared in Modeler Language (ML).
  *
  * ORDER CAN CHANGE AT ANY TIME!
  * ORDER CAN CHANGE AT ANY TIME!
  * ORDER CAN CHANGE AT ANY TIME!
  * 
  * <dt><code>S_OK</code><dd>
  * <dt><code>E_FAIL</code>end of iterator reached<dd>
  */
  HRESULT Next(CATPLMMLNodeInfo& oNode);

  // restart at the beginning
  void Reset();

private:
  void Init(CATOmxList<CATIPLMMLDicoNavNode>& iListNode);

  CATPLMMLNodeInfoIterator(const CATPLMMLNodeInfoIterator&);
  CATPLMMLNodeInfoIterator& operator=(const CATPLMMLNodeInfoIterator&);

  int _Pos;
  CATOmxList<CATIPLMMLDicoNavNode> _ListNode;
};
#endif

