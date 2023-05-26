
// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected 
* @usage U3
*/ 
//===================================================================
//
// CATIOmbConverterDefinition.h
// Define the CATIOmbConverterDefinition interface
//
//===================================================================
//
// Interface enabling to create delegate objects
//
//===================================================================
#ifndef CATEOmbConverterDefinition_H
#define CATEOmbConverterDefinition_H

#include "CATOmbConverterForRestrictedClients.h"
#include "CATBaseUnknown.h"
#include "CATOmbStreamDescriptorProperties.h"
#include "CATOmxVector.h"
#include "CATOmbXConverterManager.h"
#include "CATOmxArray.h"
#include "CATUnicodeString.h"


/*
  This interface allows to enrich the ConverterDictionnary
*/
class ExportedByCATOmbConverter CATEOmbConverterDefinitions : public CATIOmbConverterDefinitions
{
public:
  /*
    This method returns the list of converter format to declare for a specify CATOmbStreamDescriptorProperties and Capability
  */
  virtual CATOmxArray<CATUnicodeString> GetListConverterFormatToRegister(CATOmbStreamDescriptorProperties iProp, ConverterCapability iCapability)
  {
    return CATOmxArray<CATUnicodeString>();
  }

  /*
    This method allows to add applicative information on a CATOmbXConverterInfo
  */
  virtual HRESULT RegisterFormatFamilyMembers(CATOmxSR<CATOmbXConverterInfo>& ioListInfos)
  {
    return E_FAIL;
  }
};
#endif
