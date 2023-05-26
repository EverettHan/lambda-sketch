#pragma once

#include "IntroInfra.h"
#include "string"
#include "vector"
#include "tuple"
#include "map"
#include "set"
#include <nlohmann/json_fwd.hpp>

class CATISYPIntrospectable_var;
class CATSYPMetaClass;
class CATBaseUnknown;

class ExportedByIntroInfra CATSYPIntroDumpServices
{
public:
	
	static nlohmann::json DumpJSONStructure(CATBaseUnknown* i_pobject);
  static nlohmann::json GetJSONDumpedPropertiesOnChild(CATBaseUnknown * i_pParent, CATBaseUnknown * i_pChild);
	static const nlohmann::json & GetNativeToGenericModel(const std::string& dumpModelName);
	static const std::map<std::string, std::set<std::string>> & GetSYPPropertiesToWatchOnClasses();
	static nlohmann::json GetRelatedGenericProperties(CATBaseUnknown* i_pObject, const std::string& i_propertyName);
	static const std::set<std::string>& GetSetOfPropertiesToWatchOnMetaClass(const CATSYPMetaClass* i_metaClass);
	static nlohmann::json GetDumpRelatedToPropertyChange(CATBaseUnknown* i_pObject, const std::string& i_propertyName);
	static nlohmann::json GetDumpRelatedToChildPropertyChange(CATBaseUnknown *i_pObject, CATBaseUnknown *i_pParentObject, const std::string &i_propertyName);
	
  /**
   * Returns the generic type corresponding to the given native type name.
   * For example, this method returns "string" for the native type "CATUnicodeString"
   */
  static std::string GetGenericTypeFromNativeTypeName(const std::string& i_nativeTypeName);

  /**
  * Returns the generic type corresponding to the given CATSYPMetaClass.
  * For example, this method returns "button" for the native type "CATVidCtlButton"
  */
  static std::string GetGenericTypeFromNativeClass(const CATSYPMetaClass *i_metaClass);

  static nlohmann::json GetPropertiesToBeDumpedByChildren(const CATSYPMetaClass *i_metaClass);
	static const std::vector<std::string>& GetOrderedNativeToGenericModelNameList();
	static void LoadModel(const std::string& modelName);

protected:
	static const std::vector<std::string> ComputeRelatedGenericProperties(CATBaseUnknown* i_pObject, const std::string& i_propertyName, const CATSYPMetaClass* i_metaClass);

private:
	CATSYPIntroDumpServices();
  ~CATSYPIntroDumpServices();
  
  static void ComputeSYPPropertiesByClassArray(const std::string& dumpModelName);
	
	static std::vector<std::string> s_nativeToGenericModelNameList;
  static nlohmann::json s_NativeToGenericModel;
	static std::map<std::string, std::set<std::string>> s_SYPPropertiesToWatchOnClasses;
	static std::map<std::string, std::set<std::string>> s_CompleteSYPPropertiesToWatchOnClasses;
};
