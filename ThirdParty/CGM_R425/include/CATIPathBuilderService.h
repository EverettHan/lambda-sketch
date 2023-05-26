// COPYRIGHT Dassault Systemes 2009
#ifndef CATIPathBuilderService_H
#define CATIPathBuilderService_H

/**
* @level Private
* @usage U3
*/

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_CATIPathBuilderService;
#else
extern "C" const IID IID_CATIPathBuilderService;
#endif

class CATListValCATBaseUnknown_var;

/**
* Interface to build a path (CATListValCATBaseUnknown_var) from an object in a given context.
*/

class ExportedByCATPLMModelerBaseInterfaces CATIPathBuilderService : public CATBaseUnknown
{
	CATDeclareInterface;

public : 

	/**  
	* Builds a path from an object.
	*  @param iObject  
	*		The input object.
	*  @param iContext    
	*     The input context : path added at the top of the computed path.  
	*  @param oPath    
	*			The computed path.    
	*/   
	virtual HRESULT ExtractPathElement(const CATBaseUnknown_var& iObject, CATListValCATBaseUnknown_var& iContext, CATListValCATBaseUnknown_var& oPath) = 0;
};

CATDeclareHandler(CATIPathBuilderService, CATBaseUnknown);

#endif
