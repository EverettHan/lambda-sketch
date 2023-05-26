//===================================================================
//
// CATIPLMApplicativeContainerServices.h
// Define the CATIPLMApplicativeContainerServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jan 2006  Creation: ECN
//===================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATIPLMApplicativeContainerServices_H
#define CATIPLMApplicativeContainerServices_H


#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"
#include  "CATUnicodeString.h"  



class CATIPLMComponent;
class CATIContainer;  


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMApplicativeContainerServices;
#else
extern "C" const IID IID_CATIPLMApplicativeContainerServices ;
#endif
/**
* Interface allowing to access services on container in PLM environment.
*
* <br><b>Role</b>: This class gives a list of service on container in PLM environment.
*
*/

class ExportedByCATPLMComponentInterfaces CATIPLMApplicativeContainerServices: public CATBaseUnknown
{
  CATDeclareInterface;
   public:




/**
  * Creates an applicative container in the authoring document.
  * <br><b>Role:</b>This method creates an applicative container in the authoring document associated 
  * to the given PLM component.  
  * Note that inside this method , after the container creation , the followings steps are included :
  *  <ul>
  *  <li>The applicative container is initialized thanks to the <tt>CATInit</tt> interface, 
  *       if it implements it. </li>
  *  <li>The undo/redo mechanism is also initialized 
  * @param oApplicativeContainer [out, CATBaseUnknown#Release]
  *      the created applicative container.
  * @param ipiComponent 
  *      gives the authoring document inside which the applicative container has to be created.
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
  *	 <br><tt> E_INVALIDARG </tt>: in such cases :
  *           <ul>
  *            <li> ipiComponent is null</li> 
  *            <li> the document associated to the stream authoring is not loaded</li> 
  *            <li> ipiComponent base type is not rep ref</li>
  *           </ul>
  */

 

virtual HRESULT Create(CATBaseUnknown ** oApplicativeContainer,
				      CATIPLMComponent* ipiCompo,
				      const CATIdent iContainerType,
				      const IID& iInterfaceId,
				      const CATIdent iContainerSuperType="",
				      const CATUnicodeString& iIdentifier="")=0;

/**  
* Gets an applicative container in the authoring document.
* <br><b>Role:</b>This method gets an applicative container in the authoring document associated 
* to the given PLM component.  

*  @param  oApplicativeContainer [out, CATBaseUnknown#Release] 
*            applicative  container.  
*  @param  ipiComponent    
*            gives the authoring document inside which the applicative container has to be retrieved.  
*  @param  iInterfaceId  
*            the  interface  type  returned  through  oApplicativeContainer  parameter.  
*  @param  iIdentifier  
*            name  of  the  applicative  container.  
*  @return  
*            <tt>S_OK</tt>:  the  applicative  container  has  been  successfuly  retrieved.  
*          <br><tt>  E_FAIL</tt>:  the  operation  has  failed.  
*          <br><tt> E_INVALIDARG </tt>: in such cases :
*           <ul>
*            <li> ipiComponent is null</li> 
*            <li> the document associated to the stream authoring is not loaded</li> 
*            <li> ipiComponent base type is not rep ref</li>
*           </ul>
*/  

virtual HRESULT Retrieve(CATBaseUnknown ** oApplicativeContainer,
				        CATIPLMComponent* ipiComponent,
				        const IID& iInterfaceId,
				        const CATUnicodeString& iIdentifier)=0;
   
};
#endif
