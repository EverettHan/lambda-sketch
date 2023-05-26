// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// AttrTypes
// Header definition of AttrTypes
//
//===================================================================
//
// Usage notes:
//	describes type supported by simple attribute of an object type
//
//===================================================================
// September 2015  Creation: EPB
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef AttrTypes_H
#define AttrTypes_H

#include "CATPLMIdentificationAccess.h"
#include "CATBoolean.h"
#include "CATSysErrorDef.h"

class CATUnicodeString;

/** Attribute Types supported by CATPLMAttribute.
* @see GetAttributeType ( AttrTypes * oType);
*/ 
enum AttrTypes{
  /** STRING */
  PLMTYPE_STRING = 0,
  /** INTEGER */
  PLMTYPE_INTEGER = 1,
  /** BINARY */
  PLMTYPE_BINARY = 2,
  /** DOUBLE */
  PLMTYPE_DOUBLE = 3,
  /** DATE */
  PLMTYPE_DATE = 4,
  /** BOOLEAN */
  PLMTYPE_BOOLEAN = 5,
  /**  */
  PLMTYPE_VARIANT = 6,
  /** ENUM (integer value 1, key 1),...,(integer value N, key N)*/
  PLMTYPE_ENUM = 8,
  /** STRING WITH LIMITED VALUES AVAILABLE (key 1,...,key N). No integer value associated to each key*/
  PLMTYPE_STRING_WITH_AUTHORIZED_VALUES = 9,
  /*UNDEFINED*/
  PLMTYPE_UNDEFINED = 20
};

class ExportedByCATPLMIdentificationAccess CATPLMAttrTypes
{
  friend class CATPLMFilterAttribute;
  friend class CATPLMFilterFunction;
  friend class QueryFilterFromXML;
  friend class CATPLMQLStatementBuilder;
private:
  // QueryFilter to XML
  static HRESULT FromAttrTypesToString(AttrTypes iType,CATBoolean isMulti,CATUnicodeString& oStrType);
  // XML to QueryFilter
  static HRESULT FromStringToAttrTypes(const CATUnicodeString& iStrType,AttrTypes& oType,CATBoolean& oIsMulti);
};

#endif
