#ifndef A2XVisibleComponents_H
#define A2XVisibleComponents_H
#include <nlohmann/json.hpp>
#include <UIVCoreTools.h>

#include <string>
#include <map>

class CATUnicodeString;
class CATBaseUnknown;
/**
 * This class is used to generate A2X elements
 */
class ExportedByUIVCoreTools A2XVisibleComponents
{
public:
  static void RegisterObject(std::string identifier, CATBaseUnknown * object);
  static void RemoveRegisteredObject(std::string identifier);
  static nlohmann::json Flush();
  static bool IsEmpty();
private:
  static std::map<std::string, CATBaseUnknown *> _visibleComponents;
};
#endif
