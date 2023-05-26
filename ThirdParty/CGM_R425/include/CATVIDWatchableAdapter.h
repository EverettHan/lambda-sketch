#pragma once

#include "VisuDialog.h"
#include "CATSYPWatchableAdapter.h"
#include <CATVidRGB.h>
#include <CATVidPalette.h>

class CATSYPMetaClass;
class CATISYPIntrospectable;
class CATVidColor;

/**
 * @ingroup groupCIDIntrospection
 * Adapter for CATISYPWatchable implementation.
 * @see CATSYPWatchableAdapter
 */
class ExportedByVisuDialog CATVIDWatchableAdapter: public CATSYPWatchableAdapter
{
public:
  CATVIDWatchableAdapter();
  virtual ~CATVIDWatchableAdapter();

  // Implementation of CATISYPWatchable
  virtual CATBoolean IsWatchable() const override;
  virtual nlohmann::json GetJSONDumpedProperties();
  virtual std::string GetGenericType() const;

  virtual nlohmann::json GetJSONDumpedPropertiesOnChild(const std::string &i_genericType, const CATBaseUnknown_var& i_Child, const nlohmann::json & i_listOfPropertiesToDump) override;

  virtual nlohmann::json GetPropertyInJSON(const std::string& i_propertyName) override;
  // GetComputedPropertyInJSON: Method to be implemented by the implementations to compute the value of non SYP properties
  virtual nlohmann::json GetComputedPropertyInJSON(const std::string& i_propertyName) = 0;
  
  nlohmann::json GetSYPPropertyInJSON(const std::string& i_propertyName, const std::string& i_sypPropertyName);
  nlohmann::json GetSYPPropertyInJSON(const std::string& i_propertyName, const std::string& i_sypPropertyName, const CATSYPMetaClass* i_metaClass);

  nlohmann::json GetPropertyDescription(const std::string& i_propertyName, const CATSYPMetaClass* i_metaClass);
  nlohmann::json GetJSONDumpedPropertiesFromMetaClass(const CATSYPMetaClass* i_metaClass);
  nlohmann::json DumpListOfProperties(const CATSYPMetaClass* i_metaClass, const nlohmann::json & i_listOfPropertiesToDump);

  HRESULT GetColorRGBA(const CATVidColor& i_color, CATVidColor& o_ColorRGBA) const;

  /**
  * Recover a physical color from a role.
  * @param i_role the logical role from which the color is retrieved.
  * @param o_physicalColor the color to retrieve.
  * @see CATVidPalette
  */
  virtual int GetPhysicalColorFromRole(CATVidPalette::ColorRole i_role, CATVidRGB& o_physicalColor) const;

private:
  CATVIDWatchableAdapter(const CATVIDWatchableAdapter&);
  CATVIDWatchableAdapter& operator=(const CATVIDWatchableAdapter&);
};

