//===================================================================
// COPYRIGHT Dassault Systemes 2017/06/06
//===================================================================
// CATOmxJsonArray.cpp
// Header definition of class CATOmxJsonArray
//===================================================================
//
// Usage notes:
//    This class is an above-CATOmxAny API, which provide methods to manipulate JSON Array more easily.
//    It is inspired from Java JSONArray APIs:
//      https://developer.android.com/reference/org/json/JSONArray.html
//
//    It can be seen as a dense indexed sequence of values.
//    Values may be any mix of JSONObjects, other JSONArrays, Strings, Booleans, Integers, Longs or Doubles.
//
//    JsonArray example: [94043,90210]
//
// /!\ CATOmxJsonArray is a copy-on-write data structure.
//
//===================================================================
// Related classes:
//    CATOmxJsonObject
//    CATOmxJsonType
//    CATOmxJsonItem
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
//        HRESULT GetBoolean(int iIndex, bool& oValue) const
//        HRESULT GetDouble(int iIndex, double& oValue) const
//        HRESULT GetInteger(int iIndex, int& oValue) const
//        HRESULT GetLong(int iIndex, CATLONG64& oValue) const
//        HRESULT GetString(int iIndex, CATUnicodeString& oValue) const
//        HRESULT GetJsonArray(int iIndex, CATOmxJsonArray& oValue) const
//        HRESULT GetJsonObject(int iIndex, CATOmxJsonObject& oValue) const
//        HRESULT GetJsonItem(int iIndex, CATOmxJsonItem& oValue) const
//
//    - Setters for each supported types (append and at index)
//        CATOmxJsonObject& PutBoolean(bool iValue)
//        CATOmxJsonObject& PutBoolean(int iIndex, bool iValue)
//        CATOmxJsonObject& PutDouble(double iValue)
//        CATOmxJsonObject& PutDouble(int iIndex, double iValue)
//        CATOmxJsonObject& PutInteger(int iValue)
//        CATOmxJsonObject& PutInteger(int iIndex, int iValue)
//        CATOmxJsonObject& PutLong(CATLONG64 iValue)
//        CATOmxJsonObject& PutLong(int iIndex, CATLONG64 iValue)
//        CATOmxJsonObject& PutString(CATUnicodeString& iValue)
//        CATOmxJsonObject& PutString(int iIndex, CATUnicodeString& iValue)
//        CATOmxJsonObject& PutJsonArray(CATOmxJsonArray& iValue)
//        CATOmxJsonObject& PutJsonArray(int iIndex, CATOmxJsonArray& iValue)
//        CATOmxJsonObject& PutJsonObject(CATOmxJsonObject& iValue)
//        CATOmxJsonObject& PutJsonObject(int iIndex, CATOmxJsonObject& iValue)
//        HRESULT Remove(int iIndex)
//
//    - Utilities:
//        CATOmxJsonType::Type GetJsonType(int iIndex) const
//          Returns the type of the value associated to the given index
//
//        CATOmxAny AsCATOmxAny()
//          Returns the object as CATOmxAny
//
//        bool IsEmpty() const
//          Returns true if the object is empty, which means there is no key on this object
//
//        int Length() const
//          Returns the size of this array
//
//        bool IsValidJsonArray() const
//          Returns true if this array is valid json. Use this after initializing the object with CATUnicodeString/CATOmxAny constructor
//
//        CATUnicodeString ToString() const;
//          Returns the this array as json string format
//
//        CATHashKey Hash() const;
//        static CATHashKey Hash(const CATOmxJsonArray* ipArray);
//          Returns the hash code of the current array
//
//        int CompareTo(const CATOmxJsonArray* ipOther) const;
//        static int Compare(const CATOmxJsonArray* ipLeft, const CATOmxJsonArray* ipRight);
//          Compares the two given arrays
//
//===================================================================
//  2017/06/06 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxJsonArray_H
#define CATOmxJsonArray_H

#include "CATOMY.h"
#include "CATOmxJsonItem.h"
#include "CATLib.h"

#include "CATOmxJsonEncoding.h"

class CATOmxJsonObject;
class CATOmxJsonArray;
struct CATOmxFilePath;

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxJsonArray>::manager();

class ExportedByCATOMY CATOmxJsonArray
{

  friend CATOmxJsonItem;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATOmxJsonArray();
  CATOmxJsonArray(const CATUnicodeString& iJsonString);
  CATOmxJsonArray(const CATOmxFilePath& iFilePath);
  CATOmxJsonArray(const CATOmxAny& iArray);
  CATOmxJsonArray(const CATOmxJsonArray& iJsonArray);
  CATOmxJsonArray& operator=(const CATOmxJsonArray& iJsonArray);
  CATOmxJsonArray& operator=(const CATOmxAny& iArray);
  virtual ~CATOmxJsonArray ();

  /*
  * Returns the boolean value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a boolean.
  */
  HRESULT GetBoolean(int iIndex, bool& oValue) const;

  /*
  * Returns the double value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a double.
  */
  HRESULT GetDouble(int iIndex, double& oValue) const;

  /*
  * Returns the integer value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an integer.
  */
  HRESULT GetInteger(int iIndex, int& oValue) const;

  /*
  * Returns the long value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a long.
  */
  HRESULT GetLong(int iIndex, CATLONG64& oValue) const;

  /*
  * Returns the string value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a string.
  */
  HRESULT GetString(int iIndex, CATUnicodeString& oValue) const;

  /*
  * Returns the string value at the given index or empty string if no such mapping exists
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  */
  CATUnicodeString OptGetString(int iIndex) const;

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
  *
  * Remark 1: Only base 64 and base 16 are supported <=> iFormat == 64 and iFormat == 16
  * Remark 2: PLM attributes declared in metadata like binary are encode in base 16 <=> iFormat == 16
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLV) || defined(__TSTCATOmxJsonObject) || defined(__CATPLMServicesOmx)
  HRESULT GetBinary(int iIndex, CATBinary& oValue, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncodingExpected) const;
#endif

  /*
  * Returns the JsonArray value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an array.
  */
  HRESULT GetJsonArray(int iIndex, CATOmxJsonArray& oValue) const;

  /*
  * Returns the JsonObject value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an object.
  */
  HRESULT GetJsonObject(int iIndex, CATOmxJsonObject& oValue) const;

  /*
  * Returns the JsonItem value at the given index.
  * iIndex must be in [1, Length()]
  *
  * @param iIndex [in]
  *   The index of the value.
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  */
  HRESULT GetJsonItem(int iIndex, CATOmxJsonItem& oValue) const;

  /*
  * Returns the value's type associated to the given index.
  * Returns type Null if the type is not recognized or index out of bound.
  *
  * @param iIndex [in]
  *   The index of the value.
  *
  * @return
  *   The value type
  */
  CATOmxJsonType::Type GetJsonType(int iIndex) const;

  /*
  * Returns true if the current JsonArray is valid array, false otherwise.
  * It can be invalid if the constructor using CATUnicodeString or CATOmxAny are used with an invalid passed value.
  *
  * @return
  *   is the given json object valid
  */
  bool IsValidJsonArray() const;

  /*
  * Returns the length of the array.
  */
  int Length() const;

  /*
  * Returns the JsonArray as a CATOmxAny copy
  */
  CATOmxAny AsCATOmxAny() const;

  /*
  * Appends the given integer at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutInteger(int iValue);

  /*
  * Insert the given integer at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutInteger(int iIndex, int iValue);

  /*
  * Appends the given long at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutLong(CATLONG64 iValue);

  /*
  * Insert the given long at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutLong(int iIndex, CATLONG64 iValue);

  /*
  * Appends the given double at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutDouble(double iValue);

  /*
  * Insert the given double at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutDouble(int iIndex, double iValue);

  /*
  * Appends the given boolean at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutBoolean(bool iValue);

  /*
  * Insert the given boolean at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutBoolean(int iIndex, bool iValue);

  /*
  * Appends the given string at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutString(const CATUnicodeString& iValue);

  /*
  * Insert the given string at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutString(int iIndex, const CATUnicodeString& iValue);

  /*
  * Puts the given binary value on the given name.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLV) || defined(__TSTCATOmxJsonObject) || defined(__CATPLMServicesOmx)
  CATOmxJsonArray& PutBinary(const CATBinary& iValue, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncoding);
#endif

  /*
  * Insert the given string at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  *
  * Remark 1: Only base 64 and base 16 are supported <=> iFormat == 64 and iFormat == 16
  * Remark 2: PLM attributes declared in metadata like binary are encode in base 16 <=> iFormat == 16
  */
#if !defined(_WINDOWS_SOURCE) || defined(__CATOMYUtils) || defined(__CATPLMxNLV) || defined(__TSTCATPLMxVersioningNLV) || defined(__TSTCATOmxJsonObject)
  CATOmxJsonArray& PutBinary(int iIndex, const CATBinary& iValue, int iFormat, CATOmxJsonEncoding::eEncodingForBinary iEncoding);
#endif

  /*
  * Appends the given object at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  *
  * Remark 1: Only base 64 and base 16 are supported <=> iFormat == 64 and iFormat == 16
  * Remark 2: PLM attributes declared in metadata like binary are encode in base 16 <=> iFormat == 16
  */
  CATOmxJsonArray& PutJsonObject(const CATOmxJsonObject& iValue);

  /*
  * Insert the given object at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutJsonObject(int iIndex, const CATOmxJsonObject& iValue);

  /*
  * Appends the given array at the end of the array.
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutJsonArray(const CATOmxJsonArray& iValue);

  /*
  * Insert the given array at the given index.
  * index must be in [1, Length() + 1].
  *
  * @return
  *   The JsonObject instance (fluent api)
  */
  CATOmxJsonArray& PutJsonArray(int iIndex, const CATOmxJsonArray& iValue);

  /*
  * Removes the value at the given index.
  * index must be in [1, Length()].
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value correctly removed.
  *   <dt> <code>E_OUTOFBOUND/code>     <dd> Index out of bound.
  */
  HRESULT Remove(int iIndex);

  /*
  * Encodes this array as a compact JSON string, such as:
  *   [94043,90210]
  *
  * @return
  *   The JsonArray string.
  */
  CATUnicodeString ToString() const;

  /*
  * Encodes this array as a pretty printed JSON string, such as:
  *   [
  *     94043,
  *     90210
  *   ]
  *
  * @return
  *   The JsonArray string.
  */
  CATUnicodeString PrettyPrint() const;

  /*
  * Returns the hash code of the current instance.
  *
  * @return
  *   the computed hash code
  */
  CATHashKey Hash() const;

  /*
  * Returns the hash code of the given instance.
  *
  * @return
  *   the computed hash code or 0 if given instance is NULL
  */
  static CATHashKey Hash(const CATOmxJsonArray* ipInstance);

  /*
  * Compares the current instance with the given one.
  *
  * @return
  * Return  1 if this > other,
  *         0 if this == other,
  *        -1 if this < other.
  */
  int CompareTo(const CATOmxJsonArray* ipOther) const;

  /*
  * Compares the two given instances.
  *
  * @return
  * Return  1 if left > right,
  *         0 if left == right,
  *        -1 if left < right.
  */
  static int Compare(const CATOmxJsonArray* ipLeft, const CATOmxJsonArray* ipRight);

  /*
  * DEPRECATED
  */
  CATOmxJsonArray& PutObject(CATOmxJsonObject& iValue);
  CATOmxJsonArray& PutObject(int iIndex, CATOmxJsonObject& iValue);
  CATOmxJsonArray& PutArray(CATOmxJsonArray& iValue);
  CATOmxJsonArray& PutArray(int iIndex, CATOmxJsonArray& iValue);

private:
  HRESULT _LoadFromString(CATOmxUTF8String& iJsonString);
  CATOmxJsonArray& _AppendOrInsertAtIndex(const CATOmxAny& iAny, int iIndex = -1);

  CATOmxAny _Array;
};

#endif
