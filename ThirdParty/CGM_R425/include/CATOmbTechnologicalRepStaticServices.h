#ifndef CATOmbTechnologicalRepStaticServices_H
#define CATOmbTechnologicalRepStaticServices_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
* @level Private 
* @usage U1
*/

#include "ExportedByCATOmbTechnologicalRepForInfraOnly.h"
#include "CATBooleanDef.h"

#include "CATDocument.h"
#include "IUnknown.h"
#include "CATComponentId.h"

/**   
* Technological representation private service for CATILinkable::GetDocument() access control. <br>
* <b>Role:</b>This service is meant to give access to the CATData document using
* CATILinkableObject::GetDocument().
* NOTE: <i>Always instanciate this service on the stack.</i>
*/

class ExportedByCATOmbTechnologicalRepForInfraOnly CATOmbTechnologicalRepStaticServices 
{

public:


	/**
	* Tests if the provided document is a technological representation document.
	*
	* @returns
	*     S_OK if provided document is a valid technological representation document
	*     S_FALSE otherwise
	**/
	HRESULT IsATechnologicalRepDoc(CATDocument *ipDoc);

	/**
	* Initialization sequence to be called after a load for a document associated to a technologocal represenation.
	* @returns
	*     S_OK if initialization is done.
	*     S_FALSE if initialisation has already done.
	*		E_FAIL otherwise.
	*/
	HRESULT InitTechnologicalRepDocAfterLoad ( CATDocument *&iTechnoRepDoc );
	

	/**
	* Returns the status which give the autorisation to create a container (set) in a TechnologocalRepresentation.
	* @returns
	*     S_OK if the creation is avalaible.
	*	  E_FAIL otherwise.
	*/
  HRESULT CreationContainerForTechnoRepIsAvailable(CATDocument* ) {return S_OK;}


	/**
	* Returns the status which give the autorisation to create a container (set) in a TechnologocalRepresentation.
	* @returns
	*     S_OK if the creation is avalaible.
	*	  S_FALSE otherwise.
	*/
	HRESULT CreateSetofContainerForTechnoRep( CATDocument* iTechnoRepDoc, const CATUnicodeString&  Id  );

  
  /** 
  * Check whether the provided RepRef supports a Visu SD
  *
  * <br><b>Role</b>: Explain what this method does.
  *
  * @param iCID [in]
  *     The Component in TOS
  * @param oSDWillBeGenerated [out]
  *   TRUE : SD Visu is generated for this RepRef
  *   FALSE : SD Visu is not generated for this RepRef
  * @param oAsyncSDWillBeGenerated [out]
  *   TRUE : Async SD is generated for this RepRef
  *   FALSE : Async SD is not generated for this RepRef
  * @param iContainerForSDs [in]
  *   LateType of the container for which the SD Visu is generated
  *
  * @return
  *   <code>S_OK</code>SD Visu will be generated
  *   <code>E_xxx</code> Error
  *
  */
  HRESULT CheckSecondaryFormatGeneration(const CATComponentId& iCID, CATBoolean& oSDWillBeGenerated, CATBoolean& oAsyncSDWillBeGenerated, CATUnicodeString& iContainerForSDs);
	
private:

	friend class CATOmbInfraServices;
	friend class CATContainerLinkable;
	friend class CATLinkablePDMAdapter;
	friend class CATContainerAdhesion;
	friend class CATOmcV5ContainerExt;
	friend class CATContainerStgExt;
	friend class CATContainerStgExtV4;
	friend class CATContainerStgBaseV5;

};



#endif
