// COPYRIGHT DASSAULT SYSTEMES 2002

/**
* @level Protected
* @usage U1
*/

#ifndef _CATContainerServices_H
#define _CATContainerServices_H

#include "AD0XXBAS.h"

#include "CATIContainer.h"
#include "CATStreamArea.h"
#include "CATUnicodeString.h"

class CATDocument;

#define _CATContainerServices_H

#define vcs_IR_018992_LoadSubCont // Activates IR-018992 correction build for CATOsmObjStream in OSM

//calcule le nom du stream d'un CATIContainer_var
ExportedByAD0XXBAS CATUnicodeString GetStreamName (const CATIContainer_var& Cont, int Version);

//Service qui permet d'obtenir le CATStreamArea* correspondand a un CATIContainer*
// le cycle de vie du CATStreamArea* est a la charge de l'appelant qui doit
// avant de detruire le CATStreamArea, detruire le buffer correspondant, de la maniere suivante:
// delete StreamArea->Get(); delete StreamArea;
ExportedByAD0XXBAS HRESULT  GetStreamFromContainer(CATIContainer*  iContainer, CATStreamArea*& oStreamArea);


/**
  * Creates an applicative container in a given document.
  * <br><b>Role:</b>This method creates an applicative container. After the creation, you 
  * must in this order:
  *  <ul>
  *  <li>Initialize the applicative container thanks to the <tt>CATInit</tt> interface, 
  *       if it implements it. </li>
  *  <li>Initialize the undo/redo mechanism for it thanks to the 
  *   @href CATOmbPerformAfterContainerCreation global function.</li>
  * @param oApplicativeContainer
  *      the created applicative container.
  * @param iDocument 
  *      the document inside which the applicative container has to be created.
  * @param iContainerType
  *      a string representing the type of the applicative container.
  * @param iInterfaceId
  *      the interface type returned through oApplicativeContainer parameter.
  * @param iContainerSuperType
  *      the supertype of the applicative container.
  *      <br> "": default value, the applicative container has no supertype.
  * @param iIdentifier
  *      name of the applicative container, useful to get it later.
  *	 <br> "": default value, the name is set to the container type iContainerType.
  *      <br><b> Note: </b> If you want to create several applicative containers of
  *      <br> the same type, the parameter iIdentifier becomes mandatory, because
  *      <br> two applicative containers can not have the same name.
  * @return
  *      <tt>S_OK</tt>: the applicative container has been successfuly created.
  *      <tt>S_FALSE</tt> : the applicative container already exist. It has been returned in oApplicativeContainer
  *	 <br><tt> E_FAIL</tt>: the operation has failed.
  */
ExportedByAD0XXBAS HRESULT CATCreateContainerForApplicativeData(CATBaseUnknown ** oApplicativeContainer,
				      CATDocument * iDocument,
				      const CATIdent iContainerType,
				      const IID& iInterfaceId,
				      const CATIdent iContainerSuperType="",
    			      const CATUnicodeString &iIdentifier="");


/**
  * Checks if an applicative container with the given userid exists and is loaded in the current document.
  * <br><b>Role:</b>
  * Checks if an applicative container with the given userid exists in the document. 
  * If given container exists, it then checks if it is loaded. 
  * @param iDoc
  *       the document in which the container should be searched. 
  * @param iUserId
  *       the user id of the applicative container. 
  * @param oExist
  *       <ul>
  *         <li> TRUE  : The container exists in this document
  *         <li> FALSE : The container does not exist in the document. 
  *       </ul>
  * @param oLoaded
  *       <ul>
  *         <li> TRUE  : The container exists in the document and is loaded
  *         <li> FALSE : The container does not exist in the document or is not loaded. 
  *       </ul>
  * @return
  *      <tt>S_OK</tt> : Method succeeded. 
  *	 <br><tt> E_FAIL</tt>: unexpected error. 
  */
ExportedByAD0XXBAS HRESULT CATOmbCheckIfApplicativeContainerExistsAndIsLoaded(CATDocument& iDoc, const CATUnicodeString& iUserId, CATBoolean& oExist, CATBoolean& oLoaded);


#endif

