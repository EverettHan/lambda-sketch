#pragma once

#include <IntroInfra.h>
#include <nlohmann/json_fwd.hpp>

class CATUnicodeString;

class ExportedByIntroInfra UIVCoreJsonUtilities
{
public:
  static nlohmann::json LoadJSONModelIntoMemory(const CATUnicodeString &ifileName);

private:
  UIVCoreJsonUtilities();
  ~UIVCoreJsonUtilities();
  UIVCoreJsonUtilities(const UIVCoreJsonUtilities &);
  UIVCoreJsonUtilities& operator=(const UIVCoreJsonUtilities &);
};
