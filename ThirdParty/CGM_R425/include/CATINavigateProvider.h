
#ifndef CATINavigateProvider_H
#define CATINavigateProvider_H

// COPYRIGHT DASSAULT SYSTEMES 2000
//===================================================================
//

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#include "CATProviderItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

extern ExportedByCATProviderItf IID IID_CATINavigateProvider;

/**
 * Interface used to delegate to application the addition of children in CATINavigateObject implementation.
 * <b>Role:</b> the provider algorithm handles the applicative children in order to
 * display them in the navigation tree. 
 * @see CATINavigateObject
 */
class ExportedByCATProviderItf CATINavigateProvider : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Returns a list of the children of a base object.
   * @param iObj
   *   The base feature object.
   *   <br><b>Legal values</b>: it must not be NULL.
   * @param ioProvidedChildren
   *   The list of the children of the base object known by applicative code.
   *   <br><b>Legal values</b>: 
   *     ioProvidedChildren must not be NULL. *ioProvidedChildren may be NULL or a pointer to a valid CATLISTP(CATBaseUnknown).
   *   <br><b>Lifecycle rules deviation</b>
   *     When *ioProvidedChildren is not NULL, it has to be kept by callee as input argument. 
   * @return
	 *   The code error. 
	 *   <dl>
	 *   <dt><tt>S_OK</tt></dt><dd>the method is successful</dd>
	 *   <dt><tt>E_FAIL</tt></dt><dd>otherwise</dd>
	 *   </dl>
   */
  virtual HRESULT GetChildren(CATBaseUnknown * iObj, CATLISTP(CATBaseUnknown) ** ioProvidedChildren) = 0;
};

//------------------------------------------------------------------

CATDeclareHandler( CATINavigateProvider, CATBaseUnknown );

#endif
