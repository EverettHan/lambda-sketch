// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATPsiPLMFactory.h
// Header definition of CATPsiPLMFactory
//
//===================================================================
//
// Usage notes:
//   Component implementation for Product and Representation Reference Factory.
//
//===================================================================

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATPsiPLMFactory_H
#define CATPsiPLMFactory_H

#include "PLMPSISessionInterfaces.h"
#include "CATBaseUnknown.h"

/**
 * @deprecated R211 Use @href CATPrdFactory <br>
 * Class to retrieve the Product Reference or Representation Reference factory.<br>
 * <b>Role</b>: This class provides the factory object that will enable
 * to create Product References or Representation References.
 */
class ExportedByPLMPSISessionInterfaces CATPsiPLMFactory: public CATBaseUnknown
{

public:

   CATDeclareClass;

	/**
	 * @deprecated R211 Use @href CATPrdFactory#CreatePrdFactory <br>
	 * Retrieves a pointer on a factory interface.
	 *
	 * @param iIID 
	 *		The factory interface identifier.
	 *		<ul>
	 *       <li>For Representation Reference: IID_CATIPsiRepRefFactory or IID_CATIPsiPLMRepRefFactory.</li>
	 *       <li>For Product Reference: IID_CATIPrdFactory or IID_CATIPLMPrdFactory.</li>
	 *    </ul> 
	 *
	 * @param opFactory 
	 *			The pointer on the factory interface.
	 *
	 * @return
	 *      <ul>
	 *       <li>S_OK if the interface pointer has been successfully created.</li>
	 *       <li>E_FAIL if an unexpected error occured.</li>
	 *      </ul>  
	 */ 
	 static HRESULT CreateFactoryObject(const IID& iIID, void** opFactory);


  /**
	 * Constructs an empty CATPsiPLMFactory.
	 */
   CATPsiPLMFactory ();

	/**
	 * Destructs a CATPsiPLMFactory pointer.
	 */
   virtual ~CATPsiPLMFactory ();      

private:
   
   // Copy constructor and equal operator
   // -----------------------------------
   CATPsiPLMFactory (CATPsiPLMFactory &);
   CATPsiPLMFactory& operator=(CATPsiPLMFactory&);
   
};

#endif
