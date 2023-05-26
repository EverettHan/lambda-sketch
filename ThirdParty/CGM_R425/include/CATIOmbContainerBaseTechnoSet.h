// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIOmbContainerBaseTechnoSet.h
// Define the CATIOmbContainerBaseTechnoSet interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jul 2006  Creation: Code generated by the CAA wizard  ycm
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIOmbContainerBaseTechnoSet_H
#define CATIOmbContainerBaseTechnoSet_H

#include "CATOmbTechnologicalRep.h"
#include "CATBaseUnknown.h"

class CATIContainer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbTechnologicalRep IID IID_CATIOmbContainerBaseTechnoSet;
#else
extern "C" const IID IID_CATIOmbContainerBaseTechnoSet ;
#endif

//------------------------------------------------------------------

/**   
 * Container based set data access. 
 * <b>Role</b>: Access to the container corresponding to a container-based Technological set.
 * <li>The set is a handler to an associated session object that holds all the applicative data created using this set.</li>
 * <li>The set data is not necessarily loaded in memory. This can be tested using @href IsSessionObjectLoaded .</li>
 * <li>Add-refing this interface does not prevent the session object from being unloaded from memory.</li>
 * <li>Some methods of this interface will trigger the load of the corresponding Technological stream desc if necessary.</li>
 * <br>
 *
 */
class ExportedByCATOmbTechnologicalRep CATIOmbContainerBaseTechnoSet: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
 /**
  * Retrieves the set's associated container. 
  *
  * <br><b>Role:</b>This method retrieves the container corresponding to the set. <br>
  * If necessary, the load of the applicative container and all its sub-containers can be requested.
  * It is add-refed before being returned. 
  *  
  * @param opContainer
  *   A CATIContainer pointer to the corresponding container, if successfully retrieved and loaded.
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The container was succesfully retrieved.</dd>
  *     <dt>S_FALSE</dt>
  *     <dd>The container was retrieved, but it is unloaded.</dd>
  *     <dt>E_FAIL</dt>
  **/
	  virtual HRESULT GetContainer (CATIContainer * &opObject) const = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif