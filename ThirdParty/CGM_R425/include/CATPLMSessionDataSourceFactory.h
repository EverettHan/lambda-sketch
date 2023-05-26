#ifndef _CATPLMSessionDataSourceFactory_H
#define _CATPLMSessionDataSourceFactory_H
// COPYRIGHT DASSAULT SYSTEMES 2005
/*
// COPYRIGHT DASSAULT SYSTEMES 2007
/**
* @level Private
* @usage U1
*/
#include "ExportedByCATPLMIdentification.h"
#include "CATBaseUnknown.h"
#include "CATPLMSessionDataSourceStatus.h"
#include "CATBinary.h"
#include "CATPLMCompletionLevel.h"
#include "CATIPLMSessionDataSource.h"

class CATIPLMRecordRead;

class CATPLMSessionDataSourceFactory
{
public:

  /**
  * The data source is created for loading an Activated component in session without managing any memory state
  */
  inline static CATIPLMSessionDataSource_var Bind(CATIPLMRecordRead * iRecordRead) { return Bind(CATPLMCompletionLevel(), iRecordRead); }

  /**
  * The data source is created for loading an Activated component in session without managing any memory state
  * The completion level of record contents is defined.
  */
  inline static CATIPLMSessionDataSource_var Bind(const CATPLMCompletionLevel & iCompletionLevel, CATIPLMRecordRead * iRecordRead) { return Bind(CATPLMSessionDataSourceStatus_Activated, CATBinary(), iCompletionLevel, iRecordRead); }

  /**
  * The data source is created for loading Activated or Destroyed component in session with memory state management
  */
  inline static CATIPLMSessionDataSource_var Bind(CATPLMSessionDataSourceStatus iDataSourceStatus, const CATBinary & iSessionMemoryState, CATIPLMRecordRead * iRecordRead) { return Bind(iDataSourceStatus, iSessionMemoryState, CATPLMCompletionLevel(), iRecordRead); }

  /**
   * The data source is created for loading Activated or Destroyed component in session with memory state management
   */
  ExportedByCATPLMIdentification static CATIPLMSessionDataSource_var Bind(CATPLMSessionDataSourceStatus iDataSourceStatus, const CATBinary & iSessionMemoryState, const CATPLMCompletionLevel & iCompletionLevel, CATIPLMRecordRead * iRecordRead);
};

#endif
