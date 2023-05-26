// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATPLMRecordReadExtraInfoAdapter.h
// Provide implementation to interface CATIPLMRecordReadExtraInfo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2013  Creation: EPB
//===================================================================
#ifndef CATPLMRecordReadExtraInfoAdapter_H
#define CATPLMRecordReadExtraInfoAdapter_H

#include "CATPLMImplAdapterClass.h"

#include "CATIPLMRecordReadExtraInfo.h"
#include "CATOmxKeyValueBlock.h"

/**
 * @level Private
 * @usage U3
 */

class ExportedByCATPLMImplAdapterClass CATPLMRecordReadExtraInfoAdapter: public CATIPLMRecordReadExtraInfo
{
  friend class CATPLMDataSetQueryRecord;
  friend class CATPLMRecordReadAdapterImpl;
  
  CATDeclareClass;
  
public:

  CATPLMRecordReadExtraInfoAdapter ();
  virtual ~CATPLMRecordReadExtraInfoAdapter ();

  virtual HRESULT GetAttributeBlock (CATOmxKeyValueBlock& oAttrAccess);
  
protected:  
  
  virtual HRESULT SetAttributeBlock (const CATOmxKeyValueBlock& iAttrAccess);
  CATOmxKeyValueBlock _attrBlock;
};

#endif
