#ifndef EKAuthenticationHelpers_H
#define EKAuthenticationHelpers_H

#include "EKExportedByKernel.h"
#include <string>
#include <functional>

namespace EK
{
  class StringView;

  using ProxyAuthenticationCallback = std::function<std::string(const EK::StringView&)>;

  ExportedByKernel std::string BasicAuthentication(const std::string& username, const std::string& password);
}

#endif /*EKAuthenticationHelpers_H*/
