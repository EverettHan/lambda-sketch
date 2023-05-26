// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <CATBaseUnknown.h>
#include <CATBoolean.h>
#include <string>
#include <nlohmann/json_fwd.hpp>
#include <IntroInfra.h>

extern ExportedByIntroInfra IID IID_CATISYPWatchable;

/** 
 * Interface implemented by components that can be watched by the CATSYPWatcher.
 */
class ExportedByIntroInfra CATISYPWatchable : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Returns TRUE if the widget can be managed by the CATSYPWatcher, FALSE otherwise.
  * For example an object can decide that it is not (temporarily) watchable because it is not visible.
  */
  virtual CATBoolean IsWatchable() const = 0;

  /**
  * Returns TRUE if the component must be seen as a black box, i.e its children must not be watched by the CATVidWatcher, FALSE otherwise.
  */
  virtual CATBoolean IsBlackBox() const = 0;

  /**
   * Returns the widget parent. 
   */
  virtual CATBaseUnknown_var GetWatchableParent() const = 0;
  
  /**
  * Returns the generic type of the object.
  */
  virtual std::string GetGenericType() const = 0;
  
  /**
   * Returns the widget properties dumped in a JSON format. 
   */
  virtual nlohmann::json GetJSONDumpedProperties() = 0;

  /**
   * Returns the properties relative to a child which should be calculated by the parent. Ex: grid constraints
   */
  virtual nlohmann::json GetJSONDumpedPropertiesOnChild(const std::string &i_genericType, const CATBaseUnknown_var &iChild, const nlohmann::json& listOfPropertiesToDump) = 0;

  /**
   * Returns the given widget property dumped in a JSON format.
   */
  virtual nlohmann::json GetPropertyInJSON(const std::string& i_propertyName) = 0;

  /**
   * Returns the given child property dumped in a JSON format.
   */
  virtual nlohmann::json GetPropertyOnChildInJSON(const CATBaseUnknown_var& iChild, const std::string& i_propertyName) = 0;
};

CATDeclareHandler(CATISYPWatchable, CATBaseUnknown);
