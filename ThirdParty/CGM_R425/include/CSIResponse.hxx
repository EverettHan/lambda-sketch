#ifndef CSIResponse_HXX
#define CSIResponse_HXX

#include "EKBind.h"

namespace CSI
{
class Parameters;

template <class T>
HRESULT Response::OnAnswerDomain(const CATUnicodeString& domain, HRESULT (T::*method)(const Parameters&), T& instance)
{
  domainMap_.erase(domain);
  domainMap_.insert(std::make_pair(domain, EK::bind(method, &instance)));
  return S_OK;
}
}

#endif
