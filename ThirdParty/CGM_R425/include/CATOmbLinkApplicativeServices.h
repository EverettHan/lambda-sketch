#ifndef CATOmbLinkApplicativeServices_H
#define CATOmbLinkApplicativeServices_H

// COPYRIGHT Dassault Systemes 2005
/**
* @level Protected
* @usage U1
*/

// System
#include "CATLISTV_CATBaseUnknown.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbFilterOnInverseLink.h"
#include "PLMIOmbVirtualObjectDescriptor.h"

class CATILinkableObject;
class CATIComponent_var;

/**
* Applicative services for link management.
*/
class ExportedByCATObjectModelerBase CATOmbLinkApplicativeServices
{
public:

  /** @deprecated */
  static HRESULT FindPointingObjectsInSession(CATILinkableObject * iPointedObject, CATLISTV(CATBaseUnknown_var) & ioPointingObjects, char const * iLateTypeFilter = NULL, CATBoolean iIncludingVO = FALSE);

  /**
  * Retrieves all objects that point a given object.
  * @param iPointedObject
  *	The given pointed object.
  * @param ioPointingObjects
  *	The list of pointing objects.
  *	<br>The objects are appended to the list given as argument.
  * @param iFilter
  *	A filter on links to process.
  * @return
  *	An HRESULT value:
  *	<dl>
  *		<dt>S_OK</dt>
  *			<dd>The list was built successfuly and it is not empty.</dd>
  *		<dt>S_FALSE</dt>
  *			<dd>The list is empty.</dd>
  *		<dt>E_INVALIDARG</dt>
  *			<dd>iPointedObject is NULL.</dd>
  *	</dl>
  */
  static HRESULT FindPointingObjectsInSession(CATILinkableObject * iPointedObject, CATLISTV(CATBaseUnknown_var) & ioPointingObjects, CATOmbFilterOnInverseLink const & iFilter);

  /**
  * Retrieves all objects that point a given object. PC2 Safe.
  * @param iPointedObject
  *	The given pointed object.
  * @param ioPointingObjects
  *	The list of pointing objects.
  *	<br>The objects are appended to the list given as argument.
  * @param iFilter
  *	A filter on links to process.
  * @return
  *	An HRESULT value:
  *	<dl>
  *		<dt>S_OK</dt>
  *			<dd>The list was built successfuly and it is not empty.</dd>
  *		<dt>S_FALSE</dt>
  *			<dd>The list is empty.</dd>
  *		<dt>E_INVALIDARG</dt>
  *			<dd>iPointedObject is NULL.</dd>
  *	</dl>
  */
  static HRESULT FindPointingObjectsInSessionV2(CATILinkableObject * iPointedObject, CATLISTV(CATBaseUnknown_var) & ioPointingObjects, CATOmbFilterOnInverseLink const & iFilter = CATOmbFilterOnInverseLink(NULL, CATOmbFilterOnInverseLink::External, FALSE));

  static HRESULT FindPointingObjectsInSessionV3(PLMIOmbVirtualObjectDescriptor_var & iPointedObject, CATLISTV(CATBaseUnknown_var) & oPointingObjects, CATOmbFilterOnInverseLink const & iFilter = CATOmbFilterOnInverseLink(NULL, CATOmbFilterOnInverseLink::External, TRUE));
  enum SearchBehaviour { PointingExactly, AllPointing, PointingAsLastElement};
  /**
   * New version of FindingPointingObjectsInSession
   * The aim of the method is to provide the objects (feature) that have a link pointing towards the given input iPointedObject
   * Input iPointedObject allows you to specify a Path of instance, a repInstance and a target that can be a PLM object or pointable object located inside a stream
   *      Note that you only need to specify at least one for the VO to be valid
   *      You can also fill a context path if you are looking for contextual relations and links
   *      For more info on iPointedOnject take a look at ObjectModelerBase\ProtectedInterfaces\PLMIOmbVirtualObjectDescriptor.h
   * New parameter: SearchBehaviour to filter how the returned object will be pointing the given input
   *               -AllPointing: All objects having links pointing to AND through iPointedObject will be taken into account
   *               -PointingAsLastElement: Only objects having links with a path being exactly or terminating by iPointedObject will be taken into account
   *               -PointingExactly: Only objects having links with the path being exactly iPointedObject will be take into account
   *
   * Note that this new version provides :
   *  - Improved filter support : filter criteria are properly taken into account. Note that includingVO filter is deprecated and not taken into account anymore.
   *  - Contextual link support :
   *  	-if iPointedObject is a simple link description: Applicative features pointing through contextual links with a filter compliant Input relation pointing towards iPointedObject will be returned.
   *		-if iPointedObject is a contextual link description (i.e. a context path is provided), the context path will be taken into account and only the applicative features pointing through contextual links with same context and filter compliant Input relation will be returned.
   */
  static HRESULT FindPointingObjectsInSessionV4(PLMIOmbVirtualObjectDescriptor* iPointedObject, CATLISTV(CATBaseUnknown_var) & oPointingObjects, CATOmbFilterOnInverseLink const & iFilter = CATOmbFilterOnInverseLink(NULL, CATOmbFilterOnInverseLink::External, TRUE), SearchBehaviour iBehaviour = AllPointing);

private:
  /**
   * Retrieve the Specialized Entity of a pcc component
   *   S_OK    if the CBU is a pcc component AND the specialized entity is found
   *   E_FAIL  if the CBU is a pcc component AND the specialized entity is NOT found
   *   S_FALSE if the CBU is not a pcc component
   */
  friend class CATOmbRelationSnapshotImpl;
  static HRESULT GetPCCSpecializedEntity(CATBaseUnknown_var & cbu, CATIComponent_var & oComponent);
  
};


#endif


