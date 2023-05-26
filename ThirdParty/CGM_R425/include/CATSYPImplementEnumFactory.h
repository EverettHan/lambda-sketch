// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPImplementEnumFactory.h
// Header definition of CATSYPImplementEnumFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYPImplementEnumFactory_H
#define CATSYPImplementEnumFactory_H


#include <CATBasicBoxing.h>
#include <CATListOfCATUnicodeString.h>
#include <nlohmann/json.hpp>


#define CATSYP_IMPLEMENT_ENUMFACTORY(I_ENUM_NAME, I_VALUES) \
CATSYPFactoryResult CATSYP##I_ENUM_NAME##Factory(const CATUnicodeString& i_string)\
{\
  int value = -1;\
  int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
\
  for (int i=0; i < nbElem; i++)\
  {\
    if (i_string == I_VALUES[i])\
    {\
      value = i;\
      break;\
    }\
  }\
  if (value == -1)\
  {\
    int resultConvert = i_string.ConvertToNum(&value);\
    if(!resultConvert || value < 0 || value >= nbElem)\
    {\
      CATUnicodeString enumName = CATUnicodeString(#I_ENUM_NAME);\
      enumName.ReplaceSubString("__", "::");\
      CATUnicodeString message = "The enum value '"+i_string+"' is invalid for enum '"+enumName+"'.\n";\
      message += "Possible values :\n" ;\
      for(int i=0; i< nbElem; i++)\
      {\
        message += " * '"+I_VALUES[i]+"'\n";\
      }\
      message += "Either this value doesn't exist anymore, or you forgot to add it to CATSYP_IMPLEMENT_ENUMFACTORY(..).";\
      return CATSYPFactoryResult(0, CATSYPFactoryResult::InvalidEnumValue, message);\
    }\
  }\
  return CATSYPFactoryResult(CATBoxingOfint::Box(value));\
}\
HRESULT CATSYP##I_ENUM_NAME##Serializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string)\
{\
  HRESULT result = E_FAIL;\
  int value;\
  o_string = "";\
  if (CATBoxingOfint::Unbox(i_spCBU, value)==S_OK)\
  {\
    int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
    if (value>=0 && value < nbElem)\
    {\
      o_string = I_VALUES[value];\
      result = S_OK;\
    }\
  }\
  return result;\
}\
\
void CATSYP##I_ENUM_NAME##EnumValues(const CATUnicodeString*& o_pValues, unsigned int& o_nbValues)\
{\
  o_pValues = I_VALUES;\
  o_nbValues = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
}\
\
HRESULT CATSYP##I_ENUM_NAME##JsonBuilder(const CATBaseUnknown_var& i_spCBU, nlohmann::json& o_json)\
{\
  HRESULT result = E_FAIL;\
  int value;\
  if (CATBoxingOfint::Unbox(i_spCBU, value) == S_OK)\
  {\
    int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
    if (value>=0 && value < nbElem)\
    {\
      o_json = I_VALUES[value];\
      result = S_OK;\
    }\
  }\
  return result;\
}


//-------------------------------------------------------------------


#define CATSYP_IMPLEMENT_ENUMFACTORY_CUSTOM(I_ENUM_NAME, I_VALUES, I_CUSTOM_VALUES) \
CATSYPFactoryResult CATSYP##I_ENUM_NAME##Factory(const CATUnicodeString& i_string)\
{\
  int value = -1;\
  int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
\
  for (int i=0; i < nbElem; i++)\
  {\
    if (i_string == I_VALUES[i])\
    {\
      value = I_CUSTOM_VALUES[i];\
      break;\
    }\
  }\
  if (value == -1)\
  {\
    int resultConvert = i_string.ConvertToNum(&value);\
    if(!resultConvert || value < 0 || value >= nbElem)\
    {\
      CATUnicodeString enumName = CATUnicodeString(#I_ENUM_NAME);\
      enumName.ReplaceSubString("__", "::");\
      CATUnicodeString message = "The enum value '"+i_string+"' is invalid for enum '"+enumName+"'.\n";\
      message += "Possible values :\n" ;\
      for(int i=0; i< nbElem; i++)\
      {\
        message += " * '"+I_VALUES[i]+"'\n";\
      }\
      message += "Either this value doesn't exist anymore, or you forgot to add it to CATSYP_IMPLEMENT_ENUMFACTORY(..).";\
      return CATSYPFactoryResult(0, CATSYPFactoryResult::InvalidEnumValue, message);\
    }\
  }\
  return CATSYPFactoryResult(CATBoxingOfint::Box(value));\
}\
\
HRESULT CATSYP##I_ENUM_NAME##Serializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string)\
{\
  HRESULT result = E_FAIL;\
  int value;\
  if (CATBoxingOfint::Unbox(i_spCBU, value)==S_OK)\
  {\
    int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
    for (int i=0; i < nbElem; i++)\
    {\
      if (value == I_CUSTOM_VALUES[i])\
      {\
        o_string = I_VALUES[i];\
        result = S_OK;\
        break;\
      }\
    }\
  }\
  return result;\
}\
\
void CATSYP##I_ENUM_NAME##EnumValues(const CATUnicodeString*& o_pValues, unsigned int& o_nbValues)\
{\
  o_pValues = I_VALUES;\
  o_nbValues = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
}\
\
HRESULT CATSYP##I_ENUM_NAME##JsonBuilder(const CATBaseUnknown_var& i_spCBU, nlohmann::json& o_json)\
{\
  HRESULT result = E_FAIL;\
  int value;\
  if (CATBoxingOfint::Unbox(i_spCBU, value)==S_OK)\
  {\
    int nbElem = sizeof(I_VALUES)/sizeof(CATUnicodeString);\
    for (int i=0; i < nbElem; i++)\
    {\
      if (value == I_CUSTOM_VALUES[i])\
      {\
        o_json = I_VALUES[i];\
        result = S_OK;\
        break;\
      }\
    }\
  }\
  return result;\
}



#endif
