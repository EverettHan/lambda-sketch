#ifndef __CATIDelegate_h
#define __CATIDelegate_h

// COPYRIGHT DASSAULT SYSTEMES 2000 

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"


extern ExportedByCATAfrItf IID IID_CATIDelegate;


/**
 * @nodoc
 * Interface allowing interface implementation delegation
 * on an object
 */
class ExportedByCATAfrItf CATIDelegate : public CATBaseUnknown {
	
  CATDeclareInterface;
  
public:

	/**
	 * @nodoc
	 * Get the object which the interface iInterface implementation must
	 * be delegated to.
	 * @param The double pointer ioDelegate must be valuated to the 
	 * delegate object's pointer if delegation of the interface iInterfaces
	 * is supported, ot to NULL otherwise. <b>Important note :</b> the
	 * delegate must be AddRef'ed before being returned.
	 * @param iInterface is the interfaces IID which implementation must
	 * be delegated.
	 * @return S_OK if the delegation succeeded, E_FAIL if the delegation
	 * is not possible.
	 */
  virtual HRESULT GetDelegate (CATBaseUnknown ** ioDelegate, const IID & iInterface) = 0;

};

CATDeclareHandler (CATIDelegate, CATBaseUnknown);

#endif
