// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMClientTaskMessage.h
// Header definition of CATPLMClientTaskMessage
//
//===================================================================
//
// Usage notes:
// Current class is used to store a client tasks containing a message
// CATPLMClientTaskMessage respect copy and write pattern
//
//===================================================================
// September 2022  Creation: EPB
//===================================================================
#ifndef CATPLMClientTaskMessage_H
#define CATPLMClientTaskMessage_H

#include "CATPLMServicesItf.h"

#include "CATOmxSR.h"

class CATPLMClientTaskMessageInt;
class CATUnicodeString;

class ExportedByCATPLMServicesItf CATPLMClientTaskMessage
{
  friend class CATPLMClientTaskFactory;
  friend class CATPLMClientTaskMessageInt;
public:
  ~CATPLMClientTaskMessage();

  CATPLMClientTaskMessage(const CATPLMClientTaskMessage&);
  CATPLMClientTaskMessage& operator=(const CATPLMClientTaskMessage&);

  CATUnicodeString GetMessage() const;

  CATUnicodeString GetAdditionalInfo() const;

  CATUnicodeString GetErrorKey() const;

  CATUnicodeString GetCatalogName() const;

  CATUnicodeString GetNLSRequest() const;

  static CATPLMClientTaskMessage Parse(const CATUnicodeString& iMessage);
private:
  enum eSeverity { Undefined = 1, Error = 2, Notice = 3 };

  eSeverity GetSeverity() const;

  CATPLMClientTaskMessage(eSeverity iSeverity, const CATUnicodeString& iAdditionalInfo, const CATUnicodeString& iMessage);

  CATOmxSR<CATPLMClientTaskMessageInt> _spCTMessage;
};

#endif
