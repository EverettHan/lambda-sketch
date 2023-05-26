#ifndef CSIResponse_H
#define CSIResponse_H

#include "CSICommandBinderModule.h"

#include "EKStringComparator.h"

#include "DSUnicodeString.h"
#include "CATSysErrorDef.h"

#include <functional>
#include <map>

namespace CSI
{
class Parameters;

/** Storage of multiple callbacks per domain
you can add callbacks (method, instance) with OnAnswerDomain()
and call these with parameters of a specific format (created by Message) with CallDomains()
*/
class ExportedByCSIBinderModule Response
{
public:
   Response() = default;
  ~Response() = default;

  Response(const Response&);
  Response& operator=(const Response&);

  /** Register a callback for a specified domain name
  \param domainName: the domain name
  \param method callback from a instance + method
  \param instance callback from a instance + method
  \return E_FAIL if domain already registered
  */
  template <class T>
  HRESULT OnAnswerDomain(const CATUnicodeString& domainName, HRESULT (T::*method)(const Parameters&), T& instance);

  /** Check a domain is managed by thus response
  \param domainName: the domain name
  \return true if domain is managed by this response
  */
  bool HasDomain(const CATUnicodeString& domainName) const;

  /** Return the number of domain managed by this response
  \return the number of domain
  */
  size_t GetDomainCount() const;

  /** Dispatch data from the input parameters to each registered domain
  \param parameters: the parameters containing data to dispatch to registered domains
  \return combined result from callbacks, or E_FAIL if not managed
  */
  HRESULT CallDomains(const Parameters& parameters) const;

private:
  std::map<CATUnicodeString, std::function<HRESULT(const Parameters&)>, EK::StringComparator> domainMap_;
};
}

#include "CSIResponse.hxx"

#endif
