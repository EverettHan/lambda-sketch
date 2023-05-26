#ifndef CATPLMItgBaseTraces_h
#define CATPLMItgBaseTraces_h

#include "CATOmsXmlTraces.h"
#include "CATIntegrationDumper.h"
#include "CATLISTV_CATPLMID.h"
#include "CATComponentId.h"
#include "CATPLMIntegrationBase.h"
#include "CATPLMIDCollections.h"
#include "CATOmxSR.h"
#include "CATOmxOrderedOSet.h"
class CATPLMIDSet;
class CATBinary;

#define ITG_TRA_INIT(TAG) \
  static const CATUnicodeString CATPLMItgBaseTraceTag(TAG);


ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceInfo;
ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceItg;
ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceTag_Completion;
ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceTag_Open;
ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceTag_Save;
ExportedByCATPLMIntegrationBase extern const CATUnicodeString CATPLMItgBaseTraceTag_SessionInit;

// Trace one information line
#define ITG_TRA if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsInfoXmlTracer(CATPLMItgBaseTraceTag,CATPLMItgBaseTraceItg)
#define ITG_TRA_ERR if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsErrorXmlTracer(CATPLMItgBaseTraceTag,CATPLMItgBaseTraceItg)
#define ITG_TRA_VERB if(CATOmsXmlTraces::IsVerboseActive()) CATOmsXmlTraces::GetOmsInfoXmlTracer(CATPLMItgBaseTraceTag,CATPLMItgBaseTraceItg)

// Traces a specific function with indents. Note that it can also trace a specific block (prefer ITG_TRA_BLOCK for clarity)
// Reference usage:
// ITG_TRA_FUNC("MyFunction")<<Args<< Arg("Arg1") << ArgValue1 << Arg("Arg2") << ArgValue2 << EndArgs;
#define ITG_TRA_FUNC(NAME)  CATOmxSR<CATOmbXmlElement> tracer; if(CATOmsXmlTraces::IsActive()) tracer = CATOmsXmlTraces::BlockXmlTracer(CATPLMItgBaseTraceTag, NAME, CATPLMItgBaseTraceItg)
#define ITG_TRA_BLOCK(NAME) CATOmxSR<CATOmbXmlElement> tracer; if(CATOmsXmlTraces::IsActive()) tracer = CATOmsXmlTraces::BlockXmlTracer(CATPLMItgBaseTraceTag, NAME, CATPLMItgBaseTraceItg)

// Traces for arguments and results, using the Arg(iName) and Result(iName) is optional.
// Reference usage:
// ITG_TRA_ARG << AddArg("Arg1") << ArgValue1 << AddArg("Arg2") << ArgValue2 << EndArgs;
// ITG_TRA_RES << Result("Res1") << ResValue1 << Result("Res2") << ResValue2 << EndResult;
#define ITG_TRA_ARG if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::ArgumentXmlTracer()
#define ITG_TRA_RES if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::ResultsXmlTracer()

ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMIDs & PLMIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMIDSet & PLMIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMIDOSet & PLMIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATOmxOrderedOSet<CATPLMID> & PLMIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMIDMinorInsensitiveArray & PLMIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATLISTV(CATComponentId) & CIDs);
ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMIDMap & PLMIDs);

//ExportedByCATPLMIntegrationBase const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATBinary & iBinary);

#endif
