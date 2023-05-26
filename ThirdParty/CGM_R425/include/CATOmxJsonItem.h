//===================================================================
// COPYRIGHT Dassault Systemes 2017/06/23
//===================================================================
// CATOmxJsonItem.cpp
// Header definition of class CATOmxJsonItem
//===================================================================
//
// Usage notes:
//  CATOmxJsonItem is an API over CATOmxAny to manipulate it as a JsonItem
//  JsonItem can be:
//    integer
//    long
//    double
//    boolean
//    string
//    JsonObject
//    JsonArray
//===================================================================
//  2017/06/23 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmxJsonItem_H
#define CATOmxJsonItem_H

#include "CATOMY.h"
#include "CATUnicodeString.h"
#include "CATOmxAny.h"
#include "CATOmxJsonType.h"
#include "CATOmxClassManager.h"
#include "CATOmxTextStream.h"

class CATOmxJsonObject;
class CATOmxJsonArray;
class CATOmxJsonItem;

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxJsonItem>::manager();

class ExportedByCATOMY CATOmxJsonItem
{
  friend CATOmxJsonObject;
  friend CATOmxJsonArray;

public:
  CATOmxJsonItem();
  CATOmxJsonItem(const CATOmxAny& iItem);
  CATOmxJsonItem(const CATOmxJsonObject& iItem);
  CATOmxJsonItem(const CATOmxJsonArray& iItem);
  CATOmxJsonItem(const CATOmxJsonItem& iCopy);
  CATOmxJsonItem& operator=(const CATOmxJsonItem& iCopy);
  virtual ~CATOmxJsonItem ();

  /*
  * Returns the current value's type.
  * Returns type Null if the type is not recognized.
  *
  * @return
  *   The value type
  */
  CATOmxJsonType::Type GetJsonType() const;

  /*
  * Returns the value as boolean.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a boolean.
  */
  HRESULT GetBoolean(bool& oValue) const;

  /*
  * Returns the value if it is a boolean or can be coerced to a boolean, or fallback otherwise.
  *
  * @param iFallback [in]
  *   The fallback value.
  */
  bool OptBoolean(bool iFallback) const;

  /*
  * Returns the value if it is a boolean or can be coerced to a boolean, or false otherwise.

  */
  bool OptBoolean() const;

  /*
  * Returns the value as double.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a double.
  */
  HRESULT GetDouble(double& oValue) const;

  /*
  * Returns the value if it is a double or can be coerced to a double, or fallback otherwise.
  *
  * @param iFallback [in]
  *   The fallback value.
  */
  double OptDouble(double iFallback) const;

  /*
  * Returns the value if it is a double or can be coerced to a double, or 0.0 otherwise.
  */
  double OptDouble() const;

  /*
  * Returns the value as integer.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an integer.
  */
  HRESULT GetInteger(int& oValue) const;

  /*
  * Returns the value if it is an int or can be coerced to an int, or fallback otherwise.
  *
  * @param iFallback [in]
  *   The fallback value.
  */
  int OptInteger(int iFallback) const;

  /*
  * Returns the value if it is an int or can be coerced to an int, or 0 otherwise.
  */
  int OptInteger() const;

  /*
  * Returns the value as long.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a long.
  */
  HRESULT GetLong(CATLONG64& oValue) const;

  /*
  * Returns the value if it is a long or can be coerced to a long, or fallback otherwise
  *
  * @param iFallback [in]
  *   The fallback value.
  */
  CATLONG64 OptLong(CATLONG64 iFallback) const;

  /*
  * Returns the value if it is a long or can be coerced to a long, or 0 otherwise
  */
  CATLONG64 OptLong() const;

  /*
  * Returns the value as string.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not a string.
  */
  HRESULT GetString(CATUnicodeString& oValue) const;

  /*
  * Returns the value if it is a string, or fallback otherwise.
  *
  * @param iFallback [in]
  *   The fallback value.
  */
  CATUnicodeString OptString(const CATUnicodeString& iFallback) const;

  /*
  * Returns the value if it is a string, or empty string otherwise.
  */
  CATUnicodeString OptString() const;

  /*
  * Returns the value as JsonArray.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an array.
  */
  HRESULT GetJsonArray(CATOmxJsonArray& oValue) const;

  /*
  * Returns the value if it is a JsonArray, or an empty JsonArray otherwise.
  */
  CATOmxJsonArray OptJsonArray() const;

  /*
  * Returns the value as JsonObject.
  *
  * @param oValue [out]
  *   The returned value.
  *
  * @return
  *   <dt> <code>S_OK</code>            <dd> The value has been returned correctly.
  *   <dt> <code>E_TYPEMISMATCH/code>   <dd> The actual value type is not an object.
  */
  HRESULT GetJsonObject(CATOmxJsonObject& oValue) const;

  /*
  * Returns the value if it is a JsonObject, or an empty JsonObject otherwise.
  */
  CATOmxJsonObject OptJsonObject() const;

  /*
  * Returns the JsonObject as CATOmxAny copy
  */
  CATOmxAny AsCATOmxAny() const;

  /*
  * Encodes this json item as a compact JSON string, depending on the item's type, such as:
  *   {"query":"Pizza","locations":[94043,90210]}
  *
  * @return
  *   The compact json string.
  */
  CATUnicodeString ToString() const;

  /*
  * Encodes this object as a pretty printed JSON string, depending on the item's type, such as:
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
  *   the computed hash code or 0 if given object is NULL
  */
  static CATHashKey Hash(const CATOmxJsonItem* ipInstance);

  /*
  * Compares the current instance with the given one.
  *
  * @return
  * Return  1 if this > other,
  *         0 if this == other,
  *        -1 if this < other.
  */
  int CompareTo(const CATOmxJsonItem* ipOther) const;

  /*
  * Compares the two given instances.
  *
  * @return
  * Return  1 if left > right,
  *         0 if left == right,
  *        -1 if left < right.
  */
  static int Compare(const CATOmxJsonItem* ipLeft, const CATOmxJsonItem* ipRight);

  /*
  * Returns true if the given CATOmxAny's type and given type match.
  * Returns false otherwise.
  */
  static bool IsType(CATOmxAny& iAny, CATOmxJsonType::Type iType);
  static bool IsType(CATOmxJsonItem& iItem, CATOmxJsonType::Type iType);

private:
  static void _PrettyPrint(CATOmxTextStream& iTextStream, const CATOmxJsonItem& iJsonItem, int iIndent = 0, bool iNewLine = false);
  static void _PrettyPrintNewLine(CATOmxTextStream& iTextStream, int iIndent);

  CATOmxAny _Value;
};

#endif