
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
#ifndef CATIOmbConverterDefinition_H
#define CATIOmbConverterDefinition_H

#include "CATOmbConverterForRestrictedClients.h"
#include "CATBaseUnknown.h"
#include "CATOmbStreamDescriptorProperties.h"
#include "CATOmxVector.h"
#include "CATOmbXConverterManager.h"
#include "CATOmxArray.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbConverter IID IID_CATIOmbConverterDefinitions;
#else
extern "C" const IID IID_CATIOmbConverterDefinitions ;
#endif

/*
  This interface allows to enrich the ConverterDictionnary
*/
class ExportedByCATOmbConverter CATIOmbConverterDefinitions : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /*
    This method returns the list of converter format to declare for a specify CATOmbStreamDescriptorProperties and Capability
  */
  virtual CATOmxArray<CATUnicodeString> GetListConverterFormatToRegister(CATOmbStreamDescriptorProperties iProp, ConverterCapability iCapability) = 0;

  /*
    This method allows to add applicative information on a CATOmbXConverterInfo
  */
  virtual HRESULT RegisterFormatFamilyMembers(CATOmxSR<CATOmbXConverterInfo>& ioListInfos) = 0;
};
CATDeclareHandler( CATIOmbConverterDefinitions, CATBaseUnknown );

#endif
