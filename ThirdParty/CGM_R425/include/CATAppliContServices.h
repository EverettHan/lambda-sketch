/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Protected
  * @usage U1
  */
  
#ifndef CATAppliContServices_H
#define CATAppliContServices_H
#define CATGetApplicativeContainerByType_Sign2

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATIContainer.h"
#include "CATOmxSR.h"
class CATDocument;

/**
  * Creates an applicative container in a given document.
  * <br><b>Role:</b>This method creates an applicative container. After the creation, you 
  * must in this order:
  *  <ul>
  *  <li>Initialize the applicative container thanks to the <tt>CATInit</tt> interface, 
  *       if it implements it. </li>
  *  <li>Initialize the undo/redo mechanism for it thanks to the 
  *   @href CATOmbPerformAfterContainerCreation global function.</li>
  * @param oApplicativeContainer [AddRef'ed]
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
  *      <br> otherwise must be set to the feature container type (CATFeatCont).
  * @param iIdentifier
  *      name of the applicative container, useful to get it later.
  *	 <br> "": default value, the name is set to the container type iContainerType.
  *      <br><b> Note: </b> If you want to create several applicative containers of
  *      <br> the same type, the parameter iIdentifier becomes mandatory, because
  *      <br> two applicative containers can not have the same name.
  * @return
  *      <tt>S_OK</tt>: the applicative container has been successfuly created.
  *	 <br><tt> E_FAIL</tt>: the operation has failed.
  */
  
ExportedByAC0XXLNK
HRESULT CATCreateApplicativeContainer(CATBaseUnknown ** oApplicativeContainer,
				      CATDocument * iDocument,
				      const CATIdent iContainerType,
				      const IID& iInterfaceId,
				      const CATIdent iContainerSuperType="",
				      const CATUnicodeString& iIdentifier="");


/**
  * This service should be called after a container creation to declare this new container in the undo/redo mechanism.
  * It should be called either directly after @href CATCreateApplicativeContainer if
  * no initialization is done for this container, either after initializing 
  * this container. For example:
  * <br><br>
  * <b>Without initialization :</b>
  * <pre>
  *   CATBaseUnknown * pAppliContainer = NULL;
  *   CATDocument *pDocument = ... ;
  *   CATIdent AppliContainerType = "....";
  *   CATIdent AppliContainerSuperType = "....";
  *   CATUnicodeString AppliContainerIdentifier = "...";
  * 
  *   HRESULT hr = ::<b>CATCreateApplicativeContainer</b>(&pAppliContainer,
  *                                                 pDocument,
  *                                                 AppliContainerType,
  *                                                 IID_CATIContainer,
  *                                                 AppliContainerSuperType
  *                                                 AppliContainerIdentifier);
  *
  *   CATIContainer * pIContainer = (CATIContainer*) pAppliContainer ;
  *
  *   if( SUCCEEDED(hr) && ( NULL!=pIContainer) )
  *      hr = ::<b>CATOmbPerformAfterContainerCreation</b>( pIContainer );
  * </pre>
  * 
  * <b>With initialization</b>
  *
  * <pre>
  *   CATBaseUnknown * pAppliContainer = NULL;
  *   CATDocument *pDocument = ... ;
  *   CATIdent AppliContainerType = "....";
  *   CATIdent AppliContainerSuperType = "....";
  *   CATUnicodeString AppliContainerIdentifier = "...";
  * 
  *   HRESULT hr = ::<b>CATCreateApplicativeContainer</b>(&pAppliContainer,
  *                                                 pDocument,
  *                                                 AppliContainerType,
  *                                                 IID_CATIContainer,
  *                                                 AppliContainerSuperType
  *                                                 AppliContainerIdentifier);
  *
  *   CATIContainer * pIContainer = (CATIContainer*) pAppliContainer ;
  *
  *   if( SUCCEEDED(hr) && ( NULL!=pIContainer))
  *   {
  *      CATInit_var MyContInit(pIContainer);
  *      if(MyContInit != NULL_var)
  *      {
  *        MyContInit-><b>Init</b>(FALSE);
  *      }
  *      hr = ::<b>CATOmbPerformAfterContainerCreation</b>( pIContainer );
  *   }
  * </pre>
  * @param iContainer
  *      The created applicative container.       
  * @return
  *      <tt>S_OK</tt>: The created applicative container has been successfuly declared
  *       in undo/redo mechanism.
  *	 <br><tt> E_FAIL</tt>: the operation has failed.
  */

ExportedByAC0XXLNK
HRESULT CATOmbPerformAfterContainerCreation(CATIContainer* iContainer);

/**
  * Gets an applicative container in a given document.
  * @param oApplicativeContainer [AddRef'ed]
  *      applicative container.
  * @param iDocument 
  *      the document inside which the applicative container has to be retrieved.
  * @param iInterfaceId
  *      the interface type returned through oApplicativeContainer parameter.
  * @param iIdentifier
  *      name of the applicative container.
  * @return
  *      <tt>S_OK</tt>: the applicative container has been successfuly retrieved.
  *	 <br><tt> E_FAIL</tt>: the operation has failed.
  */

ExportedByAC0XXLNK
HRESULT CATGetApplicativeContainer(CATBaseUnknown ** oApplicativeContainer,
				   CATDocument* iDocument,
				   const IID& iInterfaceId,
				   const CATUnicodeString& iIdentifier);

/**
* Gets an applicative container of a given type in a given document. If multiple container of this type exist (it cannot happens on some unique types as CGMGeom, CATFMBRP, etc) it will fail.
* @param oApplicativeContainer [smartPointer]
*      applicative container.
* @param iDocument
*      the document inside which the applicative container has to be retrieved.
* @param iType
*      name of the type of container (implementation name).
* @param iOnlyCompoundChild
*      If set to TRUE, the search will be made only directly under the compound container (root of applicative containers). if set to FALSE, it will scan all containers under compound container, what may be more CPU expensive.
* @return
*      <tt>S_OK</tt>: the applicative container has been successfuly retrieved.
*  <br><tt> E_UNEXPECTED</tt>: unexpected situation. If multiple containers of given type exist, it returns this error code.
*	 <br><tt> E_FAIL</tt>: the operation has failed.
*/

ExportedByAC0XXLNK
HRESULT CATGetApplicativeContainerByType(CATOmxSR<CATBaseUnknown>& oApplicativeContainer, CATDocument* iDocument, const CATUnicodeString& iType, const CATBoolean iOnlyCompoundChild=FALSE);

#endif






