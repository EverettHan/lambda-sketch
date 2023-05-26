#ifndef CSISentRequest_H
#define CSISentRequest_H

#include "CSIParameters.h"

namespace CSI
{
class ExportedByCSIBinderModule SentRequest
{
public:
  SentRequest(const Parameters& beginParams, const Parameters& commandParams, const Parameters& endParams, const CATUnicodeString& name, int version);
  ~SentRequest();

  SentRequest(const SentRequest&) = delete;
  SentRequest& operator=(const SentRequest&) = delete;

public:
  const Parameters getBeginParameters() const;
  const Parameters getCommandParameters() const;
  const Parameters getEndParameters() const;
  const CATUnicodeString getCommandName() const;
  const int getVersion() const;

private:
  const Parameters beginParameters_;
  const Parameters commandParameters_;
  const Parameters endParameters_;
  const CATUnicodeString commandName_;
  const int version_;
};
}

#endif /*CSISentRequest_H*/
