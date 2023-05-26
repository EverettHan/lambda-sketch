#ifndef _CATOxConnectionAndPortStreamDescriptor_H
#define _CATOxConnectionAndPortStreamDescriptor_H

#include "CATOmxSharable.h"
#include "CATUnicodeString.h"
#include "ExportedByCATPLMTos.h"
#include "CATVVSUrl.h"

class CATPLMStreamDefinition;

class ExportedByCATPLMTos CATOxConnectionAndPortStreamDescriptor : public CATOmxSharable
{
public:
  CATOxConnectionAndPortStreamDescriptor(const CATPLMStreamDefinition & iSDF);
  ~CATOxConnectionAndPortStreamDescriptor();

  /**
  * @see CATPLMStreamDefinition
  */
  CATVVSUrl& GetVVSURL();

  /**
  * @see CATPLMStreamDefinition
  */
  const CATUnicodeString& GetLateType();

  /**
  * @see CATPLMStreamDefinition
  */
  int GetWatermarkStamp();


private:

  CATUnicodeString    _LateType;            // Secondary definition
  CATVVSUrl           _URL;                 // Stream access
  int                 _WS;                  // Stream access

};

#endif
