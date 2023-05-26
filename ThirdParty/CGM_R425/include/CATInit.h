/* -*-c++-*- */
#ifndef CATInit_h
#define CATInit_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @CAA2Level L1
  * @CAA2Usage U5
  */

#include "CATBaseUnknown.h"
#include "booleanDef.h"


#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATInit ;

/**
* Interface to define initialization of a document's data.
* <b> Role: </b> The Init method is called at File/New or File/Open.
* In this method, each application usually creates its root element. To get it, 
* use GetRootContainer method.
*/

class ExportedByAD0XXBAS CATInit : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
	* Initializes data of this document.
	* @param iDestroyExistingData
	*         FALSE : Initialization is done only if there is no existing data.
	*     <br>TRUE  :  Existing data is destroyed before new initialization.
    */
    virtual void Init (CATBoolean iDestroyExistingData)=0 ;

	/**
	* Returns the root element of the given document.
    * <br> Note that the return pointer type corresponds to the iInterfaceID
    * argument. However, given the L1 exposition constraints, it is not possible
    * to convert a CATIdent to an IID, which means that the only return possible
    * is a CATBaseUnknown pointer which must then be cast to the proper interface
    * handle.
	* @param iInterfaceID
  	*        chosen interface to handle the root element.
	* @return 
	*       the root element 
  	*/
    virtual CATBaseUnknown* GetRootContainer (const CATIdent iInterfaceID)=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATInit, CATBaseUnknown ) ;


#endif



