// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// PLMIBLCustoTypeMapping.h
// Define the PLMIBLCustoTypeMapping interface
//
//===================================================================
//
// Usage notes:
//   Interface to launch the integration of the business logic definition related to the PLMIBLImportExportPnOValuations.
//
//===================================================================
//
//  Apr 2021  Creation: SKN14 HQQ
//fullreview SKN14 HQQ 21:04:15 TSK6968437 CheckAccessBL
//===================================================================
/**
* @level Protected
* @usage U3
*/

#ifndef PLMIBLImportExportPnOValuations_H
#define PLMIBLImportExportPnOValuations_H

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATListValCATIInstance_var;
class CATIInstance_var;
class CATUnicodeString;
class CATIBRExecutionServices_var;
#include "CATListOfCATListOfCATUnicodeStrings.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLImportExportPnOValuations;
#else
extern "C" const IID IID_PLMIBLImportExportPnOValuations ;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Component that implement
* PLMIBLImportExportPnOValuations is PLMEBLImportExportPnOValuations
* <p>
* Do not use the PLMIBLImportExportPnOValuations interface for such and such

*
* @example
*  // example is optional
*  PLMIBLCustoTypeMapping* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_PLMIBLCustoTypeMapping,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByPLMBusinessLogicInterfaces PLMIBLImportExportPnOValuations: public CATBaseUnknown
{
  CATDeclareInterface;

public:

    
	virtual HRESULT RunPnOValuation(const CATUnicodeString& iOpeningID, const CATUnicodeString& iImportExportFormat, const CATListOfCATUnicodeString& iListOfFilesToProcess, const CATListOfCATListOfCATUnicodeString& iListOfListOfFilesToProcess, CATBoolean& BLoutput) = 0;

	virtual HRESULT GetBLContext(CATIBRExecutionServices_var& spExecutionServices,
								 CATIInstance_var& spContext) = 0;

	virtual HRESULT AddPnOInfoToContext(const CATUnicodeString& iImportExportFormat,CATIInstance_var& spContext) = 0;

	virtual HRESULT AddObjectListToContext(CATIInstance_var& spContext, const CATListOfCATUnicodeString& iImportListOfFilesToProcess) = 0;

	virtual HRESULT AddObjectListToContext(CATIInstance_var& spContext, const CATListOfCATListOfCATUnicodeString& iExportListOfAttributesOfObject) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif
