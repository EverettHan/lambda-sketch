//===================================================================
// COPYRIGHT Dassault Systemes 2014/09/16
//===================================================================
// CATPLMPolarBearHardCoding.cpp
// Header definition of class CATPLMPolarBearHardCoding
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/09/16 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATPLMPolarBearHardCoding_H
#define CATPLMPolarBearHardCoding_H

#include "CATPLMImplAdapterBase.h"

#include "CATOmxOSet.h"
#include "CATOmxKeyString.h"
#include "CATOmxOHMap.h"

class CATPLMTypeH;

//-----------------------------------------------------------------------

class ExportedByCATPLMImplAdapterBase CATPLMPolarBearHardCoding
{
public:
  static const CATPLMPolarBearHardCoding& get();

  static CATBoolean IsPolarBearType(CATPLMTypeH iType);

  static CATBoolean IsPolarBearType(const CATUnicodeString& iTypeName);

  CATOmxOSet<CATOmxKeyString> TypesSet;
  // for all polar bear
  // from ER type to PLMtype
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> BOTypesMap;
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> RelTypesMap;

  // from PLMType to ER type
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> rBOTypesMap;
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> rRelTypesMap;

  // for DEC types
  // from ER type to PLMtype
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> BODECTypesMap;
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> RelDECTypesMap;

  // from PLMType to ER type
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> rBOBECTypesMap;
  CATOmxOHMap<CATUnicodeString, CATUnicodeString> rRelDECTypesMap;
private:
  CATPLMPolarBearHardCoding();
  CATPLMPolarBearHardCoding(CATPLMPolarBearHardCoding &);
  CATPLMPolarBearHardCoding& operator=(CATPLMPolarBearHardCoding&);

  void _InitTypesSet();

  void BOTypesMapInsert(const char *ERType, const char *PLMType);
  void RelTypesMapInsert(const char *ERType, const char *PLMType);
  void _InitPolarBearTypesMaps();

  void BODECTypesMapInsert(const char *ERType, const char *PLMType);
  void RelDECTypesMapInsert(const char *ERType, const char *PLMType);
  void _InitDECTypesMaps();

};

//-----------------------------------------------------------------------

#endif