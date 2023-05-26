/**
* @level Private
* @usage U2       
*/

#ifndef __CATIOmbRepRefModelerExposition_H
#define __CATIOmbRepRefModelerExposition_H

#include "CATOmbSelectiveLoadingForOMBOnly.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbSelectiveLoading IID IID_CATIOmbRepRefModelerExposition;
#else
extern "C" const IID IID_CATIOmbRepRefModelerExposition ;
#endif


class ExportedByCATOmbSelectiveLoading CATIOmbRepRefModelerExposition: public CATBaseUnknown
{
	CATDeclareInterface;
public:

	/** 
	* Retrieves the OMB DataExtension for Selective Loading On a RepRef. 
	*
	* @param oRepRefOmbExtension [out, CATBaseUnknown#Release]
	*   The addrefed pointer on the OMB Data Extension
	*
	* @return
	*   <code>S_OK</code> always successfull
	*
	*/	
	virtual HRESULT RetrieveSelectiveLoadingExtension(CATBaseUnknown*& oRepRefOmbExtension) = 0;
	
	/** 
	* Retrieves the BaseEntity On a RepRef. 
	*
	* @param oBaseEntity [out, CATBaseUnknown#Release]
	*   The addrefed pointer on the OMB Data Extension
	*
	* @return
	*   <code>S_OK</code> always successfull
	*
	*/	
	virtual HRESULT RetrieveModelerRepRefInternalExposition(CATBaseUnknown*& oBaseEntity) = 0;	

  /** 
	* Retrieves the SpecializedEntity On a RepRef. 
	*
	* @param oSpecializedEntity [out, CATBaseUnknown#Release]
	*   The addrefed pointer on the OMB Data Extension
	*
	* @return
	*   <code>S_OK</code> always successfull
	*
	*/	
	virtual HRESULT RetrieveModelerRepRefApplicativeExposition(CATBaseUnknown*& oSpecializedEntity) = 0;
	

};


//------------------------------------------------------------------
  CATDeclareHandler( CATIOmbRepRefModelerExposition, CATBaseUnknown );
//------------------------------------------------------------------


#endif
