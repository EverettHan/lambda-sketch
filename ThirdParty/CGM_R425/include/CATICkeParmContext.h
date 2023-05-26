// COPYRIGHT Dassault Systemes 2012
//===================================================================//===================================================================
// CATICkeParmContext.h
// Header definition of class CATICkeParmContext
//===================================================================

#ifndef CATICkeParmContext_H
#define CATICkeParmContext_H

/** 
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"


extern ExportedByCATLifSpecs  IID IID_CATICkeParmContext ;

/**
* This interface allows to specify the edition context of a parameter
* to allow computing the way the parameter has to be displayed depending
* on options retrieved on the component (design ranges/scale)
* This interface is not implemented on all parameters types. It is implemented
* at least on volatile parameters that have a literal value
*/
class ExportedByCATLifSpecs CATICkeParmContext: public CATBaseUnknown
{
CATDeclareInterface;

public:

	/**
	* Sets the edition context of a parameter
	* @param iContext
	* the context can be a PLM Component or any linkable object (@see CATICkeScalesServices)
	* @return
	* S_OK if the method succeeds, E_FAIL otherwise
	*/
	virtual HRESULT SetContext(const CATBaseUnknown_var &iContext) = 0;

	/**
	* Gets the edition context of a parameter
	* @param oContext
	* after the method has been called, this argument contains the context that has been set with SetContext method, or NULL_var if SetContext has never been called
	* @return
	* S_OK if the method succeeds, E_FAIL otherwise
	*/
	virtual HRESULT GetContext(CATBaseUnknown_var &oContext) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATICkeParmContext, CATBaseUnknown );

#endif
