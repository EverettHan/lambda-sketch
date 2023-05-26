// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMChangeControlAdapter.h
// Define the CATPLMChangeControlAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
//  Feb 2009  virtual added because it is an adapter.
//  Feb 2009  Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMChangeControlAdapter_H
#define CATPLMChangeControlAdapter_H

#include "CATIPLMChangeControl.h"

#include "CATPLMImplAdapterClass.h"

/** 
* Adapter to implement the CATIPLMChangeControl interface.
*/
class ExportedByCATPLMImplAdapterClass CATPLMChangeControlAdapter: public CATIPLMChangeControl
{
public:
  CATPLMChangeControlAdapter ();
  virtual ~CATPLMChangeControlAdapter ();

  virtual HRESULT ActivateModificationUnderAction(const CATLISTV(CATPLMID) & iInputIDs,
                                            CATIPLMRecordReadSet ** oRecordSet);

  virtual HRESULT DeactivateModificationUnderAction(const CATLISTV(CATPLMID) & iInputIDs,
                                            CATIPLMRecordReadSet ** oRecordSet);

private:
  CATPLMChangeControlAdapter (CATPLMChangeControlAdapter &);
  CATPLMChangeControlAdapter& operator=(CATPLMChangeControlAdapter&);

};
#endif
