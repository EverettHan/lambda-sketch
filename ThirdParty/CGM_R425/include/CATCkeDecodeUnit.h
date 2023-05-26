
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATCkeDecodeUnit_h
#define CATCkeDecodeUnit_h
// COPYRIGHT DASSAULT SYSTEMES 1999-2001

#include "CATLifDictionary.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
class CATICkeMagnitude_var;
class CATICkeUnit_var;
class CATICkeUnit;

/**
 * decode a value which is a concatenation of a real value and a unit symbol
 * (even an "unofficial" unit)
 */
ExportedByCATLifDictionary HRESULT CATCkeDecodeValue(const CATUnicodeString& iStr,double& oValueInMKS,CATICkeMagnitude_var& oMagnitude);

struct ExportedByCATLifDictionary CATCkeUnitInfo {
  CATCkeUnitInfo(const CATICkeUnit* unit);
  CATUnicodeString name;
  double offset,factor;
  CATBoolean isAFormatUnit;
  CATBoolean isAComplexUnit;
};

#endif
