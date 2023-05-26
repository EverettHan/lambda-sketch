#ifndef CATSYPDeclareBitField_H
#define CATSYPDeclareBitField_H

#include "CATSYPHashMap.h"
#include "CATUnicodeString.h"
#include "CATDataType.h"
#include "IntroInfra.h"
#include "CATSYPArray.h"
#include "CATSysMacros.h"


/*
 * MyClass.h :
 * @code 
 * #include "CATSYPDeclareBitField.h"
 * #include "CATSYPDeclareBitFieldBoxing.h"
 * #include "CATSYPDeclareBitFieldFactory.h"
 * 
 * class ExportedByMydll MyClass
 * {
 *   (...)
 *   CATSYP_DECLARE_UINT32_BITFIELD(ExportedbyMyDll, MyBitField)
 *   (...)
 * }
 * CATSYP_DECLARE_UINT32_BITFIELDBOXING(ExportedbyMyDll, MyClass, MyBitField)
 * CATSYP_DECLARE_UINT32_BITFIELDFACTORY(ExportedbyMyDll, MyClass, MyBitField)
 * @endcode
 * 
 * MyClass.cpp :
 * #include "CATSYPImplementBitField.h"
 * #include "CATSYPImplementBitFieldBoxing.h"
 * #include "CATSYPImplementBitFieldFactory.h"
 * @code
 * CATSYP_IMPLEMENT_UINT32_BITFIELD_START(MyClass, MyBitField)
 * CATSYP_ADD_BIT(MyBitFieldValue1, 1<<0)
 * CATSYP_ADD_BIT(MyBitFieldValue2, 1<<1)
 * CATSYP_ADD_BIT(MyBitFieldValue3, 1<<2)
 * CATSYP_IMPLEMENT_UINT32_BITFIELD_END(MyClass, MyBitField)
 * 
 * CATSYP_IMPLEMENT_UINT32_BITFIELDBOXING(MyClass, MyBitField);
 * CATSYP_IMPLEMENT_UINT32_BITFIELDFACTORY(MyClass, MyBitField);
 * @endcode
 * 
 * Available functions on MyClass::MyBitField :
 *    operators ==, !=, ~, &, ^, |, &=, ^=, |=
 *    const CATUINT32& GetValue() const
 *    const CATUnicodeString GetString() const
 *    static CATBoolean CheckValid(const CATUINT32& i_input)
 *    static HRESULT GetStringFromValue(const CATUINT32& i_value, CATUnicodeString& o_string)
 *    static HRESULT GetValueFromString(const CATUnicodeString& i_string, CATUINT32& o_value)
 *    static const CATSYPDynArray<CATUnicodeString>& GetStringsList()
 * 
 * Available functions of boxing :
 *    class CATBoxingOfMyClass__MyBitField :
 *       static Box(const MyClass::MyBitField&)
 *       static HRESULT Unbox(const CATBaseUnknown_var &i_spReference, MyClass::MyBitField &oValue)
 *       int Equals(const CATBaseUnknown_var& i_spCBU)
 *       const char* GetType()
 *  
 * Available functions of factory:serializer :
 *    extern "C" ExportedByMyDll CATSYPFactoryResult CATSYPMyClass__MyBitFieldFactory(const CATUnicodeString& i_string);
 *    extern "C" ExportedByMyDll HRESULT CATSYPMyClass__MyBitFieldSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);
 *    extern "C" ExportedByMyDll const CATSYPDynArray<CATUnicodeString>& CATSYPMyClass__MyBitFieldI_BITFIELD_NAME##StringsList();
 */

template <class Key, class Value>
void CATSYPBitFieldFillMap(CATSYPHashMap<Key, Value>& io_mapToFill, const CATSYPHashMap<Key, Value>& i_map)
{
  CATSYPConstIteratorItf<CATSYPMapEntry<Key, Value> >* iterator = i_map.newConstIterator();
  while(iterator && !iterator->IsDone())
  {
    const CATSYPMapEntry<Key, Value>* pEntry = iterator->CurrentItem();
    if(pEntry)
    {
      io_mapToFill.Put(pEntry->key, pEntry->value);
    }
    iterator->Next();
  }
  CATSysDeletePtr(iterator);
}
//ExportTemplateInstantiation template ExportedByIntroInfra void CATSYPBitFieldFillMap<CATUINT32, CATUnicodeString>(CATSYPHashMap<CATUINT32, CATUnicodeString>& io_mapToFill, const CATSYPHashMap<CATUINT32, CATUnicodeString>& i_map);
//ExportTemplateInstantiation template ExportedByIntroInfra void CATSYPBitFieldFillMap<CATUnicodeString, CATUINT32>(CATSYPHashMap<CATUnicodeString, CATUINT32>& io_mapToFill, const CATSYPHashMap<CATUnicodeString, CATUINT32>& i_map);
//ExportTemplateInstantiation template ExportedByIntroInfra void CATSYPBitFieldFillMap<CATULONG64, CATUnicodeString>(CATSYPHashMap<CATULONG64, CATUnicodeString>& io_mapToFill, const CATSYPHashMap<CATULONG64, CATUnicodeString>& i_map);
//ExportTemplateInstantiation template ExportedByIntroInfra void CATSYPBitFieldFillMap<CATUnicodeString, CATULONG64>(CATSYPHashMap<CATUnicodeString, CATULONG64>& io_mapToFill, const CATSYPHashMap<CATUnicodeString, CATULONG64>& i_map);


#define CATSYP_DECLARE_UINT32_BITFIELD(EXPORTED_BY, NAME)\
  class EXPORTED_BY NAME \
  {\
    INTERNAL_CATSYP_DECLARE_BITFIELD(NAME, CATUINT32)\
  };

#define CATSYP_DECLARE_ULONG64_BITFIELD(EXPORTED_BY, NAME)\
  class EXPORTED_BY NAME \
  {\
    INTERNAL_CATSYP_DECLARE_BITFIELD(NAME, CATULONG64)\
  };


#define CATSYP_DECLARE_UINT32_BITFIELD_INHERIT(EXPORTED_BY, NAME, FATHER_CLASS, FATHER_BITFIELD)\
  class EXPORTED_BY NAME : public FATHER_CLASS::FATHER_BITFIELD \
  {\
    INTERNAL_CATSYP_DECLARE_BITFIELD_INHERIT(NAME, CATUINT32, FATHER_CLASS, FATHER_BITFIELD)\
  };

#define CATSYP_DECLARE_ULONG64_BITFIELD_INHERIT(EXPORTED_BY, NAME, FATHER_CLASS, FATHER_BITFIELD)\
  class EXPORTED_BY NAME : public FATHER_CLASS::FATHER_BITFIELD \
  {\
    INTERNAL_CATSYP_DECLARE_BITFIELD_INHERIT(NAME, CATULONG64, FATHER_CLASS, FATHER_BITFIELD)\
  };


#define INTERNAL_CATSYP_DECLARE_BITFIELD(NAME, TYPE)\
  INTERNAL_CATSYP_DECLARE_BITFIELD_1(NAME, TYPE)\
  INTERNAL_CATSYP_DECLARE_BITFIELD_2(NAME, TYPE)

#define INTERNAL_CATSYP_DECLARE_BITFIELD_INHERIT(NAME, TYPE, FATHER_CLASS, FATHER_BITFIELD)\
  INTERNAL_CATSYP_DECLARE_BITFIELD_1(NAME, TYPE)\
  INTERNAL_CATSYP_DECLARE_BITFIELD_2_INHERIT(NAME, TYPE, FATHER_CLASS, FATHER_BITFIELD)

#define INTERNAL_CATSYP_DECLARE_BITFIELD_1(NAME, TYPE)                                                                                                                                                                                               \
  public:                                                                                                                                                                                                                                                       \
    explicit NAME(){value=0;};                                                                                                                                                                                                                                          \
    NAME(TYPE i_value){if(!CheckValid(i_value))AssertBitFieldInputValue(i_value, "constructor"); value = i_value & GetAvailableValues();}                                                                                                                        \
                                                                                                                                                                                                                                                                \
  public:                                                                                                                                                                                                                                                       \
    const TYPE& GetValue() const{return value;}                                                                                                                                                                                                           \
    const CATUnicodeString GetString() const{CATUnicodeString str; GetStringFromValue(value, str); return str;}                                                                                                                                                 \
                                                                                                                                                                                                                                                                \
  public: /* operators */                                                                                                                                                                                                                                      \
    friend int operator== (const NAME& i_leftBF, const NAME& i_rightBF){return i_leftBF.value == i_rightBF.value;}                                                                                                                                              \
    friend int operator== (const NAME& i_leftBF, const TYPE& i_rightValue){return i_leftBF.value == i_rightValue;}                                                                                                                                              \
    friend int operator== (const TYPE& i_leftValue, const NAME& i_rightBF){return i_leftValue == i_rightBF.value;}                                                                                                                                              \
                                                                                                                                                                                                                                                                \
    NAME& operator= (const TYPE& i_value){if(!CheckValid(i_value))AssertBitFieldInputValue(i_value, "operator="); value = i_value & GetAvailableValues(); return *this;}                                                                                   \
                                                                                                                                                                                                                                                                \
    friend const NAME operator~ (const NAME& i_BF){return NAME(i_BF.value ^ GetAvailableValues());}                                                                                                                                                                   \
                                                                                                                                                                                                                                                                \
    friend int operator!= (const NAME& i_leftBF, const NAME& i_rightBF){return i_leftBF.value != i_rightBF.value;}                                                                                                                                              \
    friend int operator!= (const NAME& i_leftBF, const TYPE& i_rightValue){return i_leftBF.value != i_rightValue;}                                                                                                                                        \
    friend int operator!= (const TYPE& i_leftValue, const NAME& i_rightBF){return i_leftValue != i_rightBF.value;}                                                                                                                                        \
                                                                                                                                                                                                                                                                \
    friend NAME& operator|= (NAME& i_leftBF, const NAME& i_rightBF){i_leftBF.value |= i_rightBF.value; return i_leftBF;}                                                                                                                                        \
    friend NAME& operator|= (NAME& i_leftBF, const TYPE& i_rightValue){ if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator|="); i_leftBF.value |= (i_rightValue & GetAvailableValues()); return i_leftBF;}             \
                                                                                                                                                                                                                                                                \
    friend const NAME operator| (const NAME& i_leftBF, const NAME& i_rightBF){return NAME(i_leftBF.value | i_rightBF.value);}                                                                                                                                     \
    friend const NAME operator| (const NAME& i_leftBF, const TYPE& i_rightValue){if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator|"); return NAME(i_leftBF.value | (i_rightValue & GetAvailableValues()));}                 \
    friend const NAME operator| (const TYPE& i_leftValue, const NAME& i_rightBF){if(!CheckValid(i_leftValue)) AssertBitFieldInputValue(i_leftValue, "operator|"); return NAME((i_leftValue & GetAvailableValues()) | i_rightBF.value);}                   \
                                                                                                                                                                                                                                                                \
    friend NAME& operator&= (NAME& i_leftBF, const NAME& i_rightBF){i_leftBF.value &= i_rightBF.value; return i_leftBF;}                                                                                                                                        \
    friend NAME& operator&= (NAME& i_leftBF, const TYPE& i_rightValue){ if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator&="); else i_leftBF.value &= i_rightValue; return i_leftBF;}                                \
                                                                                                                                                                                                                                                                \
    friend const NAME operator& (const NAME& i_leftBF, const NAME& i_rightBF){return NAME(i_leftBF.value & i_rightBF.value);}                                                                                                                                     \
    friend const TYPE operator& (const NAME& i_leftBF, const TYPE& i_rightValue){if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator&"); return i_leftBF.value & i_rightValue;}                                         \
    friend const TYPE operator& (const TYPE& i_leftValue, const NAME& i_rightBF){if(!CheckValid(i_leftValue)) AssertBitFieldInputValue(i_leftValue, "operator&"); return i_leftValue & i_rightBF.value;}                                           \
                                                                                                                                                                                                                                                                \
    friend NAME& operator^= (NAME& i_leftBF, const NAME& i_rightBF){i_leftBF.value ^= i_rightBF.value; return i_leftBF;}                                                                                                                                        \
    friend NAME& operator^= (NAME& i_leftBF, const TYPE& i_rightValue){ if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator^="); else i_leftBF.value ^= i_rightValue; return i_leftBF;}                                \
                                                                                                                                                                                                                                                                \
    friend const NAME operator^ (const NAME& i_leftBF, const NAME& i_rightBF){return NAME(i_leftBF.value ^ i_rightBF.value);}                                                                                                                                     \
    friend const NAME operator^ (const NAME& i_leftBF, const TYPE& i_rightValue){if(!CheckValid(i_rightValue)) AssertBitFieldInputValue(i_rightValue, "operator^"); return NAME(i_leftBF.value ^ (i_rightValue & GetAvailableValues()));}                \
    friend const NAME operator^ (const TYPE& i_leftValue, const NAME& i_rightBF){if(!CheckValid(i_leftValue)) AssertBitFieldInputValue(i_leftValue, "operator^"); return NAME((i_leftValue & GetAvailableValues()) ^ i_rightBF.value);}                  \
                                                                                                                                                                                                                                                                \
  public: /* static methods */                                                                                                                                                                                                                                  \
    static CATBoolean CheckValid(const TYPE& i_input);                                                                                                                                                                                                    \
    static HRESULT GetStringFromValue(const TYPE& i_value, CATUnicodeString& o_string);                                                                                                                                                                   \
    static HRESULT GetValueFromString(const CATUnicodeString& i_string, TYPE& o_value);                                                                                                                                                                   \
    static const CATSYPDynArray<CATUnicodeString>& GetStringsList();                                                                                                                                                                \
                                                                                                                                                                                                                                                                \
  protected: /* for inherited bitfield classes */                                                                                                                                                                                                                \
    static CATSYPHashMap<TYPE, CATUnicodeString>& GetValueToStringHashMap();                                                                                                                                                                               \
    static CATSYPHashMap<CATUnicodeString, TYPE>& GetStringToValueHashMap();                                                                                                                                                                               \
    static TYPE& GetAvailableValues();                                                                                                                                                                                                              \
                                                                                                                                                                                                                                                                \
  private:                                                                                                                                                                                                                                                      \
    static void AssertBitFieldInputValue(const TYPE& i_input, const CATUnicodeString& i_methodName);                                                                                                                                                       \
    static void AssertBitFieldInputValueString(const CATUnicodeString& i_input, const CATUnicodeString& i_methodName);                                                                                                                                          \
    /*static HRESULT GetStringFromSingleValue(const TYPE& i_value, CATUnicodeString& o_string);*/                                                                                                                                                             \
    /*static HRESULT GetValueFromSingleString(const CATUnicodeString& i_string, TYPE& o_value);*/                                                                                                                                                              \
                                                                                                                                                                                                                                                               \
  private:                                                                                                                                                                                                                                                      \
    static CATBoolean _isInitialized;                                                                                                                                                                                                                                                           \
                                                                                                                                                                                                                                                               \
  private:                                                                                                                                                                                                                                                      \
    TYPE value;

#define INTERNAL_CATSYP_DECLARE_BITFIELD_2(NAME, TYPE) \
  private:\
    static void inline Init(){};

#define INTERNAL_CATSYP_DECLARE_BITFIELD_2_INHERIT(NAME, TYPE, FATHER_CLASS, FATHER_BITFIELD)                                                          \
  private:                                                                                                                      \
    static void inline Init(){if(_isInitialized)return;\
                       _isInitialized=1;\
                       CATSYPBitFieldFillMap(GetValueToStringHashMap(), FATHER_CLASS::FATHER_BITFIELD::GetValueToStringHashMap());\
                       CATSYPBitFieldFillMap(GetStringToValueHashMap(), FATHER_CLASS::FATHER_BITFIELD::GetStringToValueHashMap());\
                       GetAvailableValues() |= FATHER_CLASS::FATHER_BITFIELD::GetAvailableValues();\
                       }

#endif
