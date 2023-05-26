//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMNewVersionRecordWriteSetAdapter.h
// Define the CATPLMNewVersionRecordWriteSetAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter for interface CATIPLMNewVersionRecordWriteSet
//
//===================================================================
//
// Feb 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMNewVersionRecordWriteSetAdapter_H
#define CATPLMNewVersionRecordWriteSetAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMNewVersionRecordWriteSet.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

/**
 * gives an adapter to the interface CATIPLMNewVersionRecordWriteSet
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMNewVersionRecordWriteSetAdapter : public CATIPLMNewVersionRecordWriteSet
{
public:
  CATPLMNewVersionRecordWriteSetAdapter();
  virtual ~CATPLMNewVersionRecordWriteSetAdapter();

  virtual HRESULT Init(CATPLMQLCommand iCommand);

  /**
  * @nodoc
  */
  virtual HRESULT Next(const CATPLMID & iId, CATIPLMCompNewVersionRecordWrite **pWrite);

private:
  CATPLMNewVersionRecordWriteSetAdapter(CATPLMNewVersionRecordWriteSetAdapter &);
  CATPLMNewVersionRecordWriteSetAdapter& operator=(CATPLMNewVersionRecordWriteSetAdapter&);
};

#endif
