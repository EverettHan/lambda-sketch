
#ifndef CATDelegation_h
#define CATDelegation_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATSysWeakRef.h"
#include "CATAssert.h"
#include "CATBaseUnknown.h"
#include "CATIDelegation.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "JS0CORBA.h"

/**
 * @nodoc
 * Class for internal delegation.
 * <b>Role</b>: CATDelegation is dedicated to manage the delegation.
 */

class ExportedByJS0CORBA CATDelegation:public CATIDelegation
{
private:
	/** @nodoc */
        CATSysWeakRef *m_WeakOnComponentForRealInterfaces;
public:
	/** @nodoc */
        CATDeclareClass;
public:
	/** @nodoc */
        virtual HRESULT putDelegate(CATBaseUnknown*);
	/** @nodoc */
        virtual HRESULT getDelegate(CATBaseUnknown**);
	/** @nodoc */
        virtual ~CATDelegation();
	/** @nodoc */
        CATDelegation();
	/** @nodoc */
	static HRESULT canDelegate(const char*TheDelegatingObject,CATBaseUnknown*TheObject,CATBaseUnknown**ptRealInterface,const IID &TheIID);
	
	/** @nodoc */
   static int _New_Delegation_System; // _New_Delegation_System is now useless
   
	/** @nodoc */
  static HRESULT SetDelegate(CATBaseUnknown* iDelegator,CATBaseUnknown* iDelegate);
	/** @nodoc */
  static HRESULT RemoveDelegate(CATBaseUnknown* iDelegator,CATBaseUnknown* iDelegate);
	/** @nodoc */
  static inline HRESULT GetInterfaceOnDelegate(CATBaseUnknown* iDelegator,CATBaseUnknown**oDelegate);
};

extern "C" ExportedByJS0CORBA const IID IID_CATInterfaceOnDelegate;
inline HRESULT CATDelegation::GetInterfaceOnDelegate(CATBaseUnknown* iDelegator,CATBaseUnknown**oDelegate)
{
	if (!iDelegator || !oDelegate)
		return E_FAIL;
	return iDelegator->QueryInterface(IID_CATInterfaceOnDelegate,(void**)oDelegate);
}

#endif
