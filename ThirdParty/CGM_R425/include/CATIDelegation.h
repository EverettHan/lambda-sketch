#ifndef CATIDelegation_h
#define CATIDelegation_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATBaseUnknown.h"

/** @nodoc */
extern "C" ExportedByJS0CORBA IID IID_CATIDelegation;

/**
 * @nodoc
 * Interface to manage delegated object.
 * <b>Role</b>: This interface must be used to activate delegating extension.
 * @see CATMacForDelegation.
 */
class CATIDelegation :public CATBaseUnknown
{
	/**
	 * @nodoc
	*/
	CATDeclareInterface;

public:
	/**
	 * @nodoc
	 *  To declare the delegated object.
	 * @param iPt
	 *  Pointer to the delegated object,
	 * @return
	 *  S_OK if the method is successful 
	 *  E_FAIL otherwise.
	*/
	virtual HRESULT putDelegate(CATBaseUnknown*iPt)=0;
	
	/**
	 * @nodoc
	 *  To get the delegated object.
	 * @param oPt
	 *  Address to the pointer to the delegated object,
	 * @return
	 *  S_OK if the method is successful 
	 *  E_NOINTERFACE if there is no delegated object
	 *  E_FAIL otherwise.
	*/
	virtual HRESULT getDelegate(CATBaseUnknown**oPt)=0;
};

#endif
