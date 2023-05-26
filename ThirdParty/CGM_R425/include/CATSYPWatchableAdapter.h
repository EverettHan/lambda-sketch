#ifndef CATSYPWatchableAdapter_h
#define CATSYPWatchableAdapter_h

// IntrospectionInfrastructure framework
#include <IntroInfra.h>
#include <CATISYPWatchable.h>

/**
 * @ingroup groupCIDIntrospection
 * Adapter for CATISYPWatchable implementation.
 * @see CATISYPWatchable
 */
class ExportedByIntroInfra CATSYPWatchableAdapter: public CATISYPWatchable
{
public:
  CATSYPWatchableAdapter();
  virtual ~CATSYPWatchableAdapter();

  // Implementation of CATISYPWatchable
  virtual CATBoolean IsWatchable() const override;
  virtual CATBoolean IsBlackBox() const override;
  virtual CATBaseUnknown_var GetWatchableParent() const override;
  virtual std::string GetGenericType() const override;
  virtual nlohmann::json GetJSONDumpedProperties() override;
  virtual nlohmann::json GetJSONDumpedPropertiesOnChild(const std::string &i_genericType, const CATBaseUnknown_var &iChild, const nlohmann::json& listOfPropertiesToDump) override;
  virtual nlohmann::json GetPropertyInJSON(const std::string& i_propertyName) override;
  virtual nlohmann::json GetPropertyOnChildInJSON(const CATBaseUnknown_var& iChild, const std::string& i_propertyName) override;

private:
  CATSYPWatchableAdapter(const CATSYPWatchableAdapter&);
  CATSYPWatchableAdapter& operator=(const CATSYPWatchableAdapter&);
};

#endif
