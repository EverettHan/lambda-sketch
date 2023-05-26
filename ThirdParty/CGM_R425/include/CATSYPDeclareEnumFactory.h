// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATSYPDeclareEnumFactory.h
// Header definition of CATSYPDeclareEnumFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2011  Creation: qf1
//===================================================================
#ifndef CATSYPDeclareEnumFactory_H
#define CATSYPDeclareEnumFactory_H


#include <CATSYPFactoryResult.h>
#include <CATISYPValues.h>
#include <CATUnicodeString.h>
#include <nlohmann/json_fwd.hpp>


#define CATSYP_DECLARE_ENUMFACTORY(I_EXPORTED_BY, I_ENUM_NAME) \
  extern "C" I_EXPORTED_BY \
  CATSYPFactoryResult CATSYP##I_ENUM_NAME##Factory(const CATUnicodeString& i_string);\
  \
  extern "C" I_EXPORTED_BY \
  HRESULT CATSYP##I_ENUM_NAME##Serializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);\
  \
  extern "C" I_EXPORTED_BY \
  void CATSYP##I_ENUM_NAME##EnumValues(const CATUnicodeString*& o_pValues, unsigned int& o_nbValues);\
  \
  extern "C" I_EXPORTED_BY \
  HRESULT CATSYP##I_ENUM_NAME##JsonBuilder(const CATBaseUnknown_var& i_spCBU, nlohmann::json& o_json);


#endif
