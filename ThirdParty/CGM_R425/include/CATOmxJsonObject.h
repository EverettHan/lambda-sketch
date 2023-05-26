//===================================================================
// COPYRIGHT Dassault Systemes 2017/06/06
//===================================================================
// CATOmxJsonObject.cpp
// Header definition of class CATOmxJsonObject
//===================================================================
//
// Description:
//    This class is an above-CATOmxAny API, which provide methods to manipulate JSON Object more easily.
//    It is inspired from Java JSONObject APIs:
//      https://developer.android.com/reference/org/json/JSONObject.html
//
//    It can be seen as a modifiable set of name/value mappings. Names are unique, non-null strings.
//    Values may be any mix of JsonObjects, JsonArrays, Strings, Booleans, Integers, Longs or Doubles.
//
//    JsonObject example: {"query":"Pizza","locations":[94043,90210]}
//
// /!\ CATOmxJsonObject is a copy-on-write data structure.
//
//===================================================================
//
// Related classes:
//    CATOmxJsonArray
//    CATOmxJsonType
//    CATOmxJsonItem
//
//===================================================================
//
// This is a fluent API.
// You can build complex JsonObject or JsonArray easily.
//
// For example:
//  CATOmxJsonObject johnSmithObject = CATOmxJsonObject()
//    .PutString("firstName", "John")
//    .PutString("lastName", "Smith")
//    .PutInteger("age", 25)
//    .PutJsonObject("address", CATOmxJsonObject()
//      .PutString("streetAddress", "21 2nd Street")
//      .PutString("city", "New York")
//      .PutString("state", "NY")
//      .PutString("postalCode", "10021"))
//    .PutJsonArray("phoneNumber", CATOmxJsonArray()
//      .PutJsonObject(CATOmxJsonObject()
//        .PutString("type", "home")
//        .PutString("number", "212 555-1234"))
//      .PutJsonObject(CATOmxJsonObject()
//        .PutString("type", "fax")
//        .PutString("number", "646 555-4567"))
//    );
//
// Will build the following Json:
//  {
//    "firstName":"John",
//    "lastName":"Smith",
//    "age":25,
//    "address":{
//      "streetAddress":"21 2nd Street",
//      "city":"New York",
//      "state":"NY",
//      "postalCode":"10021"
//    },
//    "phoneNumber":[
//      {
//        "type":"home",
//        "number":"212 555-1234"
//      },
//      {
//        "type":"fax",
//        "number":"646 555-4567"
//      }
//    ]
//  }
//
//===================================================================
//
// Summary:
//    - Getters for each supported types:
//        HRESULT GetBoolean(const CATOmxKeyString& iName, bool& oValue) const
//        HRESULT GetDouble(const CATOmxKeyString& iName, double& oValue) const
//        HRESULT GetInteger(const CATOmxKeyString& iName, int& oValue) const
//        HRESULT GetLong(const CATOmxKeyString& iName, CATLONG64& oValue) const
//        HRESULT GetString(const CATOmxKeyString& iName, CATUnicodeString& oValue) const
//        HRESULT GetJsonArray(const CATOmxKeyString& iName, CATOmxJsonArray& oValue) const
//        HRESULT GetJsonObject(const CATOmxKeyString& iName, CATOmxJsonObject& oValue) const
//        HRESULT GetJsonItem(const CATOmxKeyString& iName, CATOmxJsonItem& oValue) const
//
//    - Getters with fallbacks:
//        bool OptBoolean(const CATOmxKeyString& iName, bool iFallback) const;
//        bool OptBoolean(const CATOmxKeyString& iName) const;
//        double OptDouble(const CATOmxKeyString& iName, double iFallback) const;
//        double OptDouble(const CATOmxKeyString& iName) const;
//        int OptInteger(const CATOmxKeyString& iName, int iFallback) const;
//        int OptInteger(const CATOmxKeyString& iName) const;
//        CATLONG64 OptLong(const CATOmxKeyString& iName, CATLONG64 iFallback) const;
//        CATLONG64 OptLong(const CATOmxKeyString& iName) const;
//        CATUnicodeString OptString(const CATOmxKeyString& iName, const CATUnicodeString& iFallback) const;
//        CATUnicodeString OptString(const CATOmxKeyString& iName) const;
//        CATOmxJsonArray OptJsonArray(const CATOmxKeyString& iName) const
//        CATOmxJsonObject OptJsonObject(const CATOmxKeyString& iName) const
//        CATOmxJsonItem OptJsonItem(const CATOmxKeyString& iName) const
//
//    - Setters for each supported types:
//        CATOmxJsonObject& PutBoolean(const CATOmxKeyString& iName, bool iValue)
//        CATOmxJsonObject& PutDouble(const CATOmxKeyString& iName, double iValue)
//        CATOmxJsonObject& PutInteger(const CATOmxKeyString& iName, int iValue)
//        CATOmxJsonObject& PutLong(const CATOmxKeyString& iName, CATLONG64 iValue)
//        CATOmxJsonObject& PutString(const CATOmxKeyString& iName, CATUnicodeString& iValue)
//        CATOmxJsonObject& PutJsonArray(const CATOmxKeyString& iName, CATOmxJsonArray& iValue)
//        CATOmxJsonObject& PutJsonObject(const CATOmxKeyString& iName, CATOmxJsonObject& iValue)
//
//    - Tool:
//        CATOmxJsonType::Type GetJsonType(const CATOmxKeyString& iName) const
//          Returns the type of the value associated to the given name
//
//        CATOmxAny::MapIteratorType GetIterator() const
//          Returns a key/value iterator on this object
//
//        void GetKeys(CATOmxOSet<CATUnicodeString>& oKeys) const
//          Returns available keys in this object
//
//        CATOmxAny AsCATOmxAny()
//          Returns the object as CATOmxAny
//
//        bool IsEmpty() const
//          Returns true if the object is empty, which means there is no key on this object
//
//        int Size() const
//          Returns the size of this object (the number of keys)
//
//        bool Has(const CATOmxKeyString& iName) const
//          Returns true of the given name is found on this object
//
//        bool IsValidJsonObject() const
//          Returns true if this object is valid json. Use this after initializing the object with CATUnicodeString/CATOmxAny constructor
//
//        CATUnicodeString ToString() const;
//          Returns the this object as json string format
//
//        CATHashKey Hash() const;
//        static CATHashKey Hash(const CATOmxJsonObject* ipObject);
//          Returns the hash code of the current object
//
//        int CompareTo(const CATOmxJsonObject* ipOther) const;
//        static int Compare(const CATOmxJsonObject* ipLeft, const CATOmxJsonObject* ipRight);
//          Compares the two given objects
//
//===================================================================
//  2017/06/06 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxJsonObject_H
#define CATOmxJsonObject_H

#include "CATOMY.h"
#include "CATOmxHRESULT.h"
#include "CATOmxOMap.h"
#include "CATOmxClassManager.h"
#include "CATOmxJson.h"
#include "CATOmxJsonItem.h"
#include "CATOmxOSet.h"
#include "CATOmxKeyString.h"// it should be replaced by class CATOmxKeyString;
#include "CATOmxJsonEncoding.h"

class CATBinary;
//class CATOmxKeyString;

struct CATOmxFilePath;

class ExportedByCATOMY CATOmxJsonObject
{
  friend CATOmxJsonItem;

public:
  CATOmxJsonObject();
  CATOmxJsonObject(const CATUnicodeString& iJsonString);
  CATOmxJsonObject(const CATOmxUTF8String& iJsonString);
  CATOmxJsonObject(const CATOmxFilePath& iFilePath);
  CATOmxJsonObject(const CATOmxAny& iMap);
  CATOmxJsonObject(const CATOmxJsonObject& iJsonObject);
  CATOmxJsonObject& operator=(const CATOmxJsonObject& iJsonObject);
  virtual ~CATOmxJsonObject();

  /*
  * Loads the JsonObject from the given string.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The given string is a valid json. CATOmxJsonObject has been correctly built.
  *   <dt> <code>E_FAIL/code>           <dd> The given string is not a valid json. CATOmxJsonObject cannot be built.
  */
  HRESULT LoadFromString(const CATOmxUTF8String& iJsonString);

  /*
  * Loads the JsonObject from the given file path.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The given file exists and contains a valid json. CATOmxJsonObject has been correctly built.
  *   <dt> <code>E_FAIL/code>           <dd> The given file doesn't exist or doesn't contain a valid json. CATOmxJsonObject cannot be built.
  */
  HRESULT LoadFromFilePath(const CATOmxFilePath& iFilePath);

  /*
  * Returns the boolean value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetBoolean(const CATOmxKeyString& iName, bool& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is a boolean or can be coerced to a boolean, or fallback otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  * @param iFallback [in]
  *   The fallback value.
  */
  bool OptBoolean(const CATOmxKeyString& iName, bool iFallback) const;

  /*
  * Returns the value mapped by name if it exists and is a boolean or can be coerced to a boolean, or false otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  bool OptBoolean(const CATOmxKeyString& iName) const;

  /*
  * Returns the double value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetDouble(const CATOmxKeyString& iName, double& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is a double or can be coerced to a double, or fallback otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  * @param iFallback [in]
  *   The fallback value.
  */
  double OptDouble(const CATOmxKeyString& iName, double iFallback) const;

  /*
  * Returns the value mapped by name if it exists and is a double or can be coerced to a double, or 0.0 otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  double OptDouble(const CATOmxKeyString& iName) const;

  /*
  * Returns the integer value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetInteger(const CATOmxKeyString& iName, int& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is an int or can be coerced to an int, or fallback otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  * @param iFallback [in]
  *   The fallback value.
  */
  int OptInteger(const CATOmxKeyString& iName, int iFallback) const;

  /*
  * Returns the value mapped by name if it exists and is an int or can be coerced to an int, or 0 otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  int OptInteger(const CATOmxKeyString& iName) const;

  /*
  * Returns the long value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetLong(const CATOmxKeyString& iName, CATLONG64& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is a long or can be coerced to a long, or fallback otherwise
  *
  * @param iName [in]
  *   The name of the value.
  * @param iFallback [in]
  *   The fallback value.
  */
  CATLONG64 OptLong(const CATOmxKeyString& iName, CATLONG64 iFallback) const;

  /*
  * Returns the value mapped by name if it exists and is a long or can be coerced to a long, or 0 otherwise
  *
  * @param iName [in]
  *   The name of the value.
  */
  CATLONG64 OptLong(const CATOmxKeyString& iName) const;

  /*
  * Returns the string value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetString(const CATOmxKeyString& iName, CATUnicodeString& oValue) const;

  /*
  * Returns the value mapped by name if it exists, coercing it if necessary, or fallback if no such mapping exists.
  *
  * @param iName [in]
  *   The name of the value.
  * @param iFallback [in]
  *   The fallback value.
  */
  CATUnicodeString OptString(const CATOmxKeyString& iName, const CATUnicodeString& iFallback) const;

  /*
  * Returns the binary value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLVStep1) || defined(__TSTCATOmxJsonObject)
  HRESULT GetBinary(const CATOmxKeyString& iName, CATBinary& oValue, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncodingExpected) const;
#endif

  /*
  * Returns the value mapped by name if it exists and is a binary or can be coerced to a binary, or empty otherwise
  *
  * @param iName [in]
  *   The name of the value.
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLV) || defined(__TSTCATOmxJsonObject)
  CATBinary OptBinary(const CATOmxKeyString& iName, const CATBinary& iFallback, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncodingExpected) const;
#endif

  /*
  * Returns the value mapped by name if it exists, coercing it if necessary, or fallback to empty binary if no such mapping exists.
  *
  * @param iName [in]
  *   The name of the value.
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLV) || defined(__TSTCATOmxJsonObject)
  CATBinary OptBinary(const CATOmxKeyString& iName, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncodingExpected) const;
#endif

  /*
  * Returns the value mapped by name if it exists, coercing it if necessary, or empty string if no such mapping exists.
  *
  * @param iName [in]
  *   The name of the value.
  */
  CATUnicodeString OptString(const CATOmxKeyString& iName) const;

  /*
  * Returns the JsonArray value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetJsonArray(const CATOmxKeyString& iName, CATOmxJsonArray& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is a JsonArray, or an empty JsonArray otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  CATOmxJsonArray OptJsonArray(const CATOmxKeyString& iName) const;

  /*
  * Returns the JsonObject value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The value's type is not correct.
  */
  HRESULT GetJsonObject(const CATOmxKeyString& iName, CATOmxJsonObject& oValue) const;

  /*
  * Returns the value mapped by name if it exists and is a JsonObject, or an empty JsonObject otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  CATOmxJsonObject OptJsonObject(const CATOmxKeyString& iName) const;

  /*
  * Returns the JsonItem value associated to the given name.
  *
  * @param iName [in]
  *   The name of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_FAIL/code>           <dd> The name doesn't exist.
  */
  HRESULT GetJsonItem(const CATOmxKeyString& iName, CATOmxJsonItem& oValue) const;

  /*
  * Returns the value mapped by name if it exists, or an empty JsonItem otherwise.
  *
  * @param iName [in]
  *   The name of the value.
  */
  CATOmxJsonItem OptJsonItem(const CATOmxKeyString& iName) const;

  /*
  * Returns the value's type associated to the given name.
  * Returns type Null if the type is not recognized or the given name doesn't exist.
  *
  * @param iName [in]
  *   The name of the value.
  *
  * @return
  *   The value type
  */
  CATOmxJsonType::Type GetJsonType(const CATOmxKeyString& iName) const;

  /*
  * Returns a key/value CATOmxIter<CATOmxPair<CATOmxKeyString, CATOmxAny>> iterator on the JsonObject's map.
  *
  * Example:
  *   CATOmxAny::MapIteratorType iter = jsonObject.GetIterator();
  *   const CATOmxAny::MapPairType* pCurrentPair;
  *   while ((pCurrentPair = iter.Next()) != NULL)
  *   {
  *     CATOmxKeyString currentKey = pCurrentPair->key;
  *     ...
  *   }
  *
  * @return
  *   the CATOmxIter<CATOmxPair<CATOmxKeyString, CATOmxAny>> iterator.
  */
  CATOmxAny::MapIteratorType GetIterator() const;

  /*
  * Returns the available keys in this object.
  */
  void GetKeys(CATOmxOSet<CATUnicodeString>& oKeys) const;

  /*
  * Returns the JsonObject as CATOmxAny copy
  */
  CATOmxAny AsCATOmxAny() const;

  /*
  * Returns true is the current json object is empty, which mean it doesn't contains any property.
  * Returns false otherwise.
  */
  bool IsEmpty() const;

  /*
  * Returns the number of properties on the current json object.
  */
  int Size() const;

  /*
  * Returns TRUE if the given name exist in the JsonObject.
  * Otherwise, it returns FALSE.
  */
  bool Has(const CATOmxKeyString& iName) const;

  /*
  * Returns true if the current JsonObject is valid object, false otherwise.
  * It can be invalid if the constructor using CATUnicodeString or CATOmxAny are used with an invalid passed value.
  *
  * @return
  *   is the given json object valid
  */
  bool IsValidJsonObject() const;

  /*
  * Puts the given boolean value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutBoolean(const CATOmxKeyString& iName, bool iValue);

  /*
  * Puts the given double value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutDouble(const CATOmxKeyString& iName, double iValue);

  /*
  * Puts the given integer value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutInteger(const CATOmxKeyString& iName, int iValue);

  /*
  * Puts the given long value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutLong(const CATOmxKeyString& iName, CATLONG64 iValue);

  /*
  * Puts the given string value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutString(const CATOmxKeyString& iName, const CATUnicodeString& iValue);

  /*
  * Puts the given binary value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  *
  * Remark 1: Only base 64 and base 16 are supported <=> iFormat == 64 and iFormat == 16
  * Remark 2: PLM attributes declared in metadata like binary are encode in base 16 <=> iFormat == 16
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLVStep1) || defined(__TSTCATOmxJsonObject) || defined(__CATPLMServicesOmx)
  CATOmxJsonObject& PutBinary(const CATOmxKeyString& iName, const CATBinary& iValue, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncoding);
#endif

  /*
  * Puts the given JsonArray value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutJsonArray(const CATOmxKeyString& iName, const CATOmxJsonArray& iValue);

  /*
  * Puts the given JsonObject value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonObject& PutJsonObject(const CATOmxKeyString& iName, const CATOmxJsonObject& iValue);

  /*
  * Encodes this object as a compact JSON string, such as:
  *   {"query":"Pizza","locations":[94043,90210]}
  *
  * @return
  *   The JsonObject string.
  */
  CATUnicodeString ToString() const;

  /*
  * Encodes this object as a pretty printed JSON string, such as:
  *   {
  *     "query":"Pizza",
  *     "locations":[
  *         94043,
  *         90210
  *     ]
  *   }
  *
  * @return
  *   The JsonObject string.
  */
  CATUnicodeString PrettyPrint() const;

  /*
  * Returns the hash code of the current JsonObject.
  *
  * @return
  *   the computed hash code
  */
  CATHashKey Hash() const;

  /*
  * Returns the hash code of the given JsonObject.
  *
  * @return
  *   the computed hash code or 0 if given object is NULL
  */
  static CATHashKey Hash(const CATOmxJsonObject* ipObject);

  /*
  * Compares the current instance with the given one.
  *
  * @return
  * Return  1 if this > other,
  *         0 if this == other,
  *        -1 if this < other.
  */
  int CompareTo(const CATOmxJsonObject* ipOther) const;

  /*
  * Compares the two given instances.
  *
  * @return
  * Return  1 if left > right,
  *         0 if left == right,
  *        -1 if left < right.
  */
  static int Compare(const CATOmxJsonObject* ipLeft, const CATOmxJsonObject* ipRight);

  /*
  * CATOmxAny::MapRemoveValue not implemented
  */
  // HRESULT Remove(const CATOmxKeyString& iName);

  /*
  * DEPRECATED
  */
  CATOmxJsonObject& PutArray(const CATOmxKeyString& iName, CATOmxJsonArray& iValue);
  CATOmxJsonObject& PutObject(const CATOmxKeyString& iName, CATOmxJsonObject& iValue);

private:
  CATOmxAny _Map;
};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxJsonObject>::manager();

#endif
