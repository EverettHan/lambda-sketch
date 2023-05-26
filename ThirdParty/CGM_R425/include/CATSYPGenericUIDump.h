// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <CATBaseUnknown.h>
#include <CATBoolean.h>
#include <nlohmann/json_fwd.hpp>

class CATSYPGenericUIDump : public CATBaseUnknown
{
public:
  /**
   * @brief Specifies if component can be dumped
   * @return CATBoolean TRUE if the method Dump can be called FALSE otherwise (content is not dumped too)
   */
  virtual CATBoolean CanDump() = 0;

  /**
   * @brief Get component dump. Dump content is detailled in each interface.
   * The Dump result must not contain dump of any child element. Use the CATSYPVisitor dedicated to interface.
   * Returned object must be a nlohmann::json::object or a null one.
   * If null, it won't be added to the visitor dump result.
   * @return nlohmann::json
   */
  virtual nlohmann::json Dump() = 0;

  /**
   * @brief Get component dump. Dump content is detailled in each interface.
   * The Dump result must not contain dump of any child element. Use the CATSYPVisitor dedicated to interface.
   * Returned object must be a nlohmann::json::object or a null one.
   * If null, it won't be added to the visitor dump result.
   * @return CATBoolean TRUE if content (children) must be dumped, FALSE otherwise
   */
  virtual CATBoolean DumpContent() = 0;

};
