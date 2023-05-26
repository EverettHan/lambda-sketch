/**
 * @level Protected
 * @usage U1
 */

#ifndef __CATAsyncForkTaskMP_H
#define __CATAsyncForkTaskMP_H

#include "CATPLMImplAdapterAsync.h"

#include "CATBaseUnknown.h"
#include "CATIOmxBinaryStream.h"
#include "CATPLMCompForkInputs.h"
#include "CATIPLMTaskMP.h"

class CATIPLMCompRecordReadSet;

class ExportedByCATPLMImplAdapterAsync CATAsyncForkTaskMP : public CATIPLMTaskMP
{
  CATDeclareClass;
public:
  CATAsyncForkTaskMP(const CATPLMCompForkInputs & iForkInputs) :m_inputs(iForkInputs) {}
  CATAsyncForkTaskMP() = default;

  HRESULT Stream(CATIOmxBinaryStream* ipBinStream) override;
  HRESULT Unstream(CATIOmxBinaryStream* opBinStream) override;
  HRESULT Run(CATIPLMCompRecordReadSet*& opRecords) override;
  const char * GetComponentName() override { return "CATAsyncForkTaskMP"; }
private:
  CATPLMCompForkInputs m_inputs;
};

#endif
