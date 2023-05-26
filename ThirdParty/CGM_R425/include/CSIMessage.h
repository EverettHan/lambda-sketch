#ifndef CSIMessage_H
#define CSIMessage_H

#include "CSICommandBinderModule.h"
#include "CSIParameters.h"
#include "DSUnicodeString.h"
#include <vector>

namespace CSI
{
class Commands;
class Types;

class ExportedByCSIBinderModule Message
{
public:
  explicit Message(const Commands& commands);
  explicit Message(const Types& types);
          ~Message();

  Message(const Message& msg);
  Message& operator=(const Message&);

  HRESULT AnswerDomain(const CATUnicodeString& domain, const Parameters& parameters); //NOT RECOMMENDED
  bool HasDomains() const;
  const Parameters& GetDomains() const;
  Parameters ToParameters() const;

private:
  HRESULT GetDomainNames(std::vector<CATUnicodeString>& domainNames) const;

private:
  Parameters parameters_;
};
}

#endif
