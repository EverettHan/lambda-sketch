// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMCloneRecordWriteSetAdapter.h
// Define the CATPLMCloneRecordWriteSetAdapter interface
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMCloneRecordWriteSet
//
//===================================================================
//
// Feb 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMCloneRecordWriteSetAdapter_H
#define CATPLMCloneRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMCloneRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll
#include "CATPLMQLCommand.h"

/**
 * gives an adapter to the interface CATIPLMCloneRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMCloneRecordWriteSetAdapter : public CATIPLMCloneRecordWriteSet
{
public:
  CATPLMCloneRecordWriteSetAdapter();
  virtual ~CATPLMCloneRecordWriteSetAdapter();

  HRESULT Init(CATPLMQLCommand iCommand);

  HRESULT KeepFamily();

  /**
  * @nodoc
  */
  virtual HRESULT Next(const CATPLMID & iId, CATIPLMCompCloneRecordWrite *& oRecordWrite);

private:
  CATPLMCloneRecordWriteSetAdapter(CATPLMCloneRecordWriteSetAdapter &);
  CATPLMCloneRecordWriteSetAdapter& operator=(CATPLMCloneRecordWriteSetAdapter&);
};

#endif
