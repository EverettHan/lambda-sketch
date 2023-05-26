#ifndef CATSYPImplementBitField_H
#define CATSYPImplementBitField_H

#include "CATSYPHashMap.h"
#include "CATUnicodeString.h"
#include "CATDataType.h"
#include <IntroInfra.h>
#include "CATSYPUtilities.h"
#include "CATSYPUtilities.h"



ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetValueFromSingleString_CATUINT32(const CATSYPHashMap<CATUnicodeString, CATUINT32>& i_map, const CATUnicodeString& i_string, CATUINT32& o_value);
ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetValueFromSingleString_CATULONG64(const CATSYPHashMap<CATUnicodeString, CATULONG64>& i_map, const CATUnicodeString& i_string, CATULONG64& o_value);

ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetStringFromSingleValue_CATUINT32(const CATSYPHashMap<CATUINT32, CATUnicodeString>& i_map, const CATUINT32& i_value, CATUnicodeString& o_string);
ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetStringFromSingleValue_CATULONG64(const CATSYPHashMap<CATULONG64, CATUnicodeString>& i_map, const CATULONG64& i_value, CATUnicodeString& o_string);

ExportedByIntroInfra
  CATBoolean CATSYPBitFieldCheckValid_CATUINT32(const CATUINT32& i_availableValues, const CATUINT32& i_input);
ExportedByIntroInfra
  CATBoolean CATSYPBitFieldCheckValid_CATULONG64(const CATULONG64& i_availableValues, const CATULONG64& i_input);

ExportedByIntroInfra
  void CATSYPBitFieldAssertValueInput_CATUINT32(const CATUINT32& i_input, const CATUnicodeString& i_className, const CATUnicodeString& i_methodName);
ExportedByIntroInfra
  void CATSYPBitFieldAssertValueInput_CATULONG64(const CATULONG64& i_input, const CATUnicodeString& i_className, const CATUnicodeString& i_methodName);

ExportedByIntroInfra
  void CATSYPBitFieldAssertStringInput(const CATUnicodeString& i_input, const CATUnicodeString& i_className, const CATUnicodeString& i_methodName);

ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetValueFromString_CATUINT32(const CATSYPHashMap<CATUnicodeString, CATUINT32>& i_map, const CATUnicodeString& i_string, CATUINT32& o_value);
ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetValueFromString_CATULONG64(const CATSYPHashMap<CATUnicodeString, CATULONG64>& i_map, const CATUnicodeString& i_string, CATULONG64& o_value);

ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetStringFromValue_CATUINT32(const CATSYPHashMap<CATUINT32, CATUnicodeString>& i_map, const CATUINT32& i_value, CATUnicodeString& o_string);
ExportedByIntroInfra
  HRESULT CATSYPBitFieldGetStringFromValue_CATULONG64(const CATSYPHashMap<CATULONG64, CATUnicodeString>& i_map, const CATULONG64& i_value, CATUnicodeString& o_string);


// ----------------------------------

struct CATSYPBit_CATUINT32{
  const char* string;
  CATUINT32 value;
};

struct CATSYPBit_CATULONG64{
  const char* string;
  CATULONG64 value;
};

// ----------------------------------

#define CATSYP_IMPLEMENT_UINT32_BITFIELD_START(CLASS, NAME)\
  CATSYP_IMPLEMENT_BITFIELD_START(CLASS, NAME, CATUINT32)

#define CATSYP_IMPLEMENT_ULONG64_BITFIELD_START(CLASS, NAME)\
  CATSYP_IMPLEMENT_BITFIELD_START(CLASS, NAME, CATULONG64)

#define CATSYP_IMPLEMENT_BITFIELD_START(CLASS, NAME, TYPE)\
  static const CATSYPBit_##TYPE s_##CLASS##__##NAME##_Bit[] = {


// ----------------------------------

#define CATSYP_ADD_BIT(STRING, VALUE)\
  {#STRING, VALUE},


// ----------------------------------

#define CATSYP_IMPLEMENT_UINT32_BITFIELD_END(CLASS, NAME)\
  CATSYP_IMPLEMENT_BITFIELD_END(CLASS, NAME, CATUINT32)

#define CATSYP_IMPLEMENT_ULONG32_BITFIELD_END(CLASS, NAME)\
  CATSYP_IMPLEMENT_BITFIELD_END(CLASS, NAME, CATULONG32)

#define CATSYP_IMPLEMENT_ULONG64_BITFIELD_END(CLASS, NAME)\
  CATSYP_IMPLEMENT_BITFIELD_END(CLASS, NAME, CATULONG64)

#define CATSYP_IMPLEMENT_BITFIELD_END(CLASS, NAME, TYPE)\
  };                                                                                                                    \
                                                                                                                        \
  struct CLASS##__##NAME##_BitFieldManager                                                                              \
  {                                                                                                                     \
    CLASS##__##NAME##_BitFieldManager()                                                                                        \
    {                                                                                                                   \
      _stringToValueHashMap.Clear();                                                                                    \
      _valueToStringHashMap.Clear();                                                                                    \
      availableValues = 0;                                                                                              \
      for(int i=0; i< sizeof(s_##CLASS##__##NAME##_Bit)/sizeof(CATSYPBit_##TYPE); i++)                                                        \
      {                                                                                                                 \
        _valueToStringHashMap.Put(s_##CLASS##__##NAME##_Bit[i].value, s_##CLASS##__##NAME##_Bit[i].string);                               \
        _stringToValueHashMap.Put(s_##CLASS##__##NAME##_Bit[i].string, s_##CLASS##__##NAME##_Bit[i].value);                               \
        availableValues |= s_##CLASS##__##NAME##_Bit[i].value;                                                                   \
      }                                                                                                                  \
    }                                                                                                                   \
    CATSYPHashMap<TYPE, CATUnicodeString>& GetValueToStringHashMap(){ return _valueToStringHashMap;}        \
    CATSYPHashMap<CATUnicodeString, TYPE>& GetStringToValueHashMap(){ return _stringToValueHashMap;}        \
    TYPE& GetAvailableValues(){return availableValues;}                                                     \
                                                                                                                        \
    CATSYPHashMap<TYPE, CATUnicodeString> _valueToStringHashMap;                                                  \
    CATSYPHashMap<CATUnicodeString, TYPE> _stringToValueHashMap;                                                  \
    TYPE availableValues;                                                                                         \
  };                                                                                                                    \
                                                                                                                        \
  static CLASS##__##NAME##_BitFieldManager* s_##CLASS##__##NAME##_BitFieldManager = NULL;                               \
                                                                                                                        \
  static CLASS##__##NAME##_BitFieldManager* Get##CLASS##__##NAME##_BitFieldManager()                                             \
  {                                                                                                                     \
    if(s_##CLASS##__##NAME##_BitFieldManager == NULL)                                                                   \
      s_##CLASS##__##NAME##_BitFieldManager = new CLASS##__##NAME##_BitFieldManager();                                  \
    return s_##CLASS##__##NAME##_BitFieldManager;                                                                       \
  }                                                                                                                                                    \
                                                                                                                                                       \
  CATBoolean CLASS::NAME::_isInitialized = 0;                                                                                                              \
                                                                                                                                                       \
  /*HRESULT CLASS::NAME::GetValueFromSingleString(const CATUnicodeString& i_string, TYPE& o_value)                                                 \
  {                                                                                                                                                    \
    return CATSYPBitFieldGetValueFromSingleString_##TYPE(GetStringToValueHashMap(), i_string, o_value);             \
  }     */                                                                                                                                               \
                                                                                                                                                       \
  HRESULT CLASS::NAME::GetValueFromString(const CATUnicodeString& i_string, TYPE& o_value)                                                       \
  {                                                                                                                                                    \
    HRESULT hr = CATSYPBitFieldGetValueFromString_##TYPE(GetStringToValueHashMap(), i_string, o_value);             \
    /*if(FAILED(hr))                                                                                                                                     \
    {                                                                                                                                                  \
      AssertBitFieldInputValueString(i_string, s_GetValueFromString);                                                                                  \
    }      */                                                                                                                                            \
    return hr;                                                                                                                                         \
  }                                                                                                                                                    \
                                                                                                                                                       \
  HRESULT CLASS::NAME::GetStringFromValue(const TYPE& i_value, CATUnicodeString& o_string)                                                       \
  {                                                                                                                                                    \
    if(!CheckValid(i_value))                                                                                                                           \
    {                                                                                                                                                  \
      /*AssertBitFieldInputValue(i_value, s_GetStringFromValue);   */                                                                                      \
      return E_FAIL;                                                                                                                                   \
    }                                                                                                                                                  \
    return CATSYPBitFieldGetStringFromValue_##TYPE(GetValueToStringHashMap(), i_value, o_string);                   \
  }                                                                                                                                                    \
                                                                                                                                                       \
  CATSYPHashMap<CATUnicodeString, TYPE>& CLASS::NAME::GetStringToValueHashMap()                                                                 \
  {                                                                                                                                                    \
    Init(); return Get##CLASS##__##NAME##_BitFieldManager()->GetStringToValueHashMap();                                                                        \
  }                                                                                                                                                    \
                                                                                                                                                       \
  CATSYPHashMap<TYPE, CATUnicodeString>& CLASS::NAME::GetValueToStringHashMap()                                                                   \
  {                                                                                                                                                    \
    Init(); return Get##CLASS##__##NAME##_BitFieldManager()->GetValueToStringHashMap();                                                                       \
  }                                                                                                                                                    \
                                                                                                                                                       \
  CATSYPDynArray<CATUnicodeString> CLASS##__##NAME##_StringsList;                                                                                                        \
                                                                                                                                                       \
  const CATSYPDynArray<CATUnicodeString>& CLASS::NAME::GetStringsList()                                                                                      \
  {                                                                                                                                                     \
    if(CLASS##__##NAME##_StringsList.GetLength() == 0)                                                                                                                         \
    {                                                                                                                                                   \
      CATUnicodeString strStrings; GetStringFromValue(GetAvailableValues(), strStrings);                                                                 \
      CATSYPPutMembersInArray(strStrings,                                                                                                              \
                              CLASS##__##NAME##_StringsList,                                                                                                              \
                              "|");                                                                                                                   \
    }                                                                                                                                                   \
    return CLASS##__##NAME##_StringsList;                                                                                                                                \
  }                                                                                                                                                     \
                                                                                                                                                       \
  TYPE& CLASS::NAME::GetAvailableValues()                                                                                                  \
  {                                                                                                                                                    \
    Init(); return Get##CLASS##__##NAME##_BitFieldManager()->GetAvailableValues();                                                                             \
  }                                                                                                                                                    \
                                                                                                                                                       \
  CATBoolean CLASS::NAME::CheckValid(const TYPE& i_input)                                                                                        \
  {                                                                                                                                                    \
    return CATSYPBitFieldCheckValid_##TYPE(GetAvailableValues(), i_input);                                          \
  }                                                                                                                                                    \
                                                                                                                                                       \
  void CLASS::NAME::AssertBitFieldInputValue(const TYPE& i_input, const CATUnicodeString& i_methodName)                                          \
  {                                                                                                                                                    \
    CATSYPBitFieldAssertValueInput_##TYPE(i_input, #CLASS "::" #NAME, i_methodName);                                                                              \
  }                                                                                                                                                    \
                                                                                                                                                       \
  void CLASS::NAME::AssertBitFieldInputValueString(const CATUnicodeString& i_input, const CATUnicodeString& i_methodName)                              \
  {                                                                                                                                                    \
    CATSYPBitFieldAssertStringInput(i_input, #CLASS "::" #NAME, i_methodName);                                                                             \
  }                                                                                                                                                    


#endif

