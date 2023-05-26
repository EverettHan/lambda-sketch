// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATICompletionServices.h
// Define the CATICompletionServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================

#ifndef CATICompletionServices_H
#define CATICompletionServices_H

#include "ExportedByPLMExchangeCompletionServices.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATPLMID.h"
#include "CATListPtrCATIPLMComponent.h"

class CATUnicodeString;
class CATIPLMExportEngineDeviation;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMExchangeCompletionServices IID IID_CATICompletionServices;
#else
extern "C" const IID IID_CATICompletionServices;
#endif


class ExportedByPLMExchangeCompletionServices CATICompletionServices : public CATBaseUnknown
{
	CATDeclareInterface;

public:



	virtual HRESULT CompletionForExport(const CATListPtrCATIPLMComponent & iList
								  , const CATUnicodeString           & iExportType
									, const CATUnicodeString           & iChosenOption
									, const CATString                  & iExtendOptions
									, CATIPLMExportEngineDeviation     * iExportEngineDeviation
									, CATListPtrCATIPLMComponent       & oCompletedList
									, const CATBoolean                   ibConfigCompletion
									, int iContextForCompletion) = 0;





};

//------------------------------------------------------------------

#endif
