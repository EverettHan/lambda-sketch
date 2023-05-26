
// COPYRIGHT Dassault Systemes 2009

#ifndef CATSYPStream_H
#define CATSYPStream_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATSYPArray.h>
#include <CATSYPMetaClass.h>
#include <CATSYPMap.h>
#include <nlohmann/json_fwd.hpp>
#include <string>

class CATBaseUnknown_var;
class CATSYPFactoryResult;
class CATHashTableStringString;

/**
 * This class provides static methods dealing with data streaming and unstreaming.
 */
class ExportedByIntroInfra CATSYPStream
{
public:

  /**
   * Look in all .CATFactory files (found in \<os\>/code/dictionary/) for the given
   * type name and return the name of the library where the factories & unstreamers
   * can be found.
   * @param i_introType the type to look for
   * @return an empty string if the type has not been found in any dictionary, else
   * the name of the library.
   */
  static CATUnicodeString GetLibFactory(const CATUnicodeString& i_introType);
  static CATUnicodeString GetLibFactory(const CATUnicodeString& i_introTypeOrDeclarativeName, CATUnicodeString& o_introType);

  /**
   * Creates a property from a CATUnicodeString. The return class will contain the generated data
   * if succeeded, otherwise it will contain a specific error code that indicated which problem occured.
   * Note that calling this method with a type "CATUnicodeString" will create directly a box of i_value
   * An assertion will be throw if the i_propertyType or the i_value are empty.
   * @param i_propertyType the property type that will be used to find a dedicated factory
   * @param i_stringValue the string representing the value to create
   * @return a class containing the result of the factory call.
   * @see CATSYPFactoryResult
   * @see CATBoxing
   */
  static CATSYPFactoryResult CreatePropertyFromString(const CATUnicodeString& i_propertyType, const CATUnicodeString& i_stringValue);

  /** Creates a string from a boxed property. It may not succeed if the given property type is not coherent with the actual type of the boxed value.
  * @param i_propertyType the property type type that will be used to find a dedicated serializer
  * @param i_spProperty the boxed property (simple type boxed in a CATBaseUnknown instance)
  * @param o_string a string representing the data, and with a format compatible with the CreatePropertyFromString method.
  * @see CreatePropertyFromString
  * @return S_OK if the operation was successfull, E_FAIL otherwise.
  */
  static HRESULT CreateStringFromProperty(const CATUnicodeString &i_propertyType, const CATBaseUnknown_var &i_spProperty, CATUnicodeString &o_string);

  /**
  * Creates a property from a json object. The return class will contain the generated data
  * if succeeded, otherwise it will contain a specific error code that indicated which problem occured.
  * An assertion will be throw if the i_propertyType or the i_value are empty.
  * @param i_propertyType the property type that will be used to find a dedicated factory
  * @param i_jsonValue the json object representing the value to create
  * @return a class containing the result of the factory call.
  * @see CATSYPFactoryResult
  * @see CATBoxing
  */
  static CATSYPFactoryResult CreatePropertyFromJSON(const CATUnicodeString& i_propertyType, const nlohmann::json& i_jsonValue);

  /** Creates a json object from a boxed property. It may not succeed if the given property type is not coherent with the actual type of the boxed value.
   * @param i_propertyType the property type type that will be used to find a dedicated serializer
   * @param i_spProperty the boxed property (simple type boxed in a CATBaseUnknown instance)
   * @param o_json a json object that will be filled, and ready to be streamed
   * @return S_OK if the operation was successfull, E_FAIL otherwise.
   */
  static HRESULT CreateJSONFromProperty(const CATUnicodeString &i_propertyType, const CATBaseUnknown_var &i_spProperty, nlohmann::json &o_json);
  
  /** Creates a std::string from a CATUnicodeString value.
   * @param i_string the input CATUnicodeString
   * @return the std::string.
   */
  static std::string CreateStdStringFromCATUnicodeString(const CATUnicodeString& i_string);

  /** Creates a json object from a CATUnicodeString value.
  * @param i_propertyValue the input CATUnicodeString
  * @param o_json a json object that will be filled, and ready to be streamed
  * @return S_OK if the operation was successfull, E_FAIL otherwise.
  */
  static HRESULT CreateJSONFromCATUnicodeString(const CATUnicodeString& i_string, nlohmann::json& o_json);

private:

  static CATHashTableStringString _s_objectNameToLib;
  static CATHashTableStringString _s_declarativeNameToObjectName;
  static void CATReadFactoryDictionnary();
  static CATUnicodeString GetPropertyType(const CATUnicodeString &i_propertyType, bool &o_enumFlag, bool &o_bitFieldFlag);

  friend class CATSYPStreamPrivate;
};

#endif // CATSYPStream_H
