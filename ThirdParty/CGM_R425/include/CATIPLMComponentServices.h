// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMComponentServices.h
// Header definition of CATIPLMComponentServices
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2006  Creation: Code generated by the CAA wizard  ECN
//===================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATIPLMComponentServices_H
#define CATIPLMComponentServices_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"  
#include "CATLISTV_CATIPLMComponent.h" 

class CATIPLMComponent;



#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMComponentInterfaces IID IID_CATIPLMComponentServices;
#else
extern "C" const IID IID_CATIPLMComponentServices ;
#endif
/**
* Interface to access services on PLM component in current session.
*
* <br><b>Role</b>: Provides a service class to access PLM component.
*
*/

class ExportedByCATPLMComponentInterfaces CATIPLMComponentServices: public CATBaseUnknown
{
  CATDeclareInterface;
   public:

/**
* Retrieves the list of PLM component in current session.
* <br><b>Role:</b> Retrieves the enumeration of PLM entities in session of kind Representation or Reference (according
*                  to the vocabulary of PLM abstract Model referential).
*
* @param oList 
*		The list of PLM component.
* @return
*      <ul>
*       <li>S_OK if the .</li>
*       <li>E_FAIL. Unexpected errors</li>
*      </ul>  
*/

virtual HRESULT GetPLMComponentsInSession(CATLISTV( CATIPLMComponent_var ) & oList )=0;

/**  
 *  For an object inside a stream, retrieves the PLM Component agregrating that stream.  
 *  
 *    @param    ipObject  
 *            An object inside the stream)  
 *    @param    oPLMComponent  
 *            The  corresponding  PLM  Component.  
 *    @return  
 *            <code>S_OK</code>  if  the  methods  succeeds.  
 *            <code>E_FAIL</code>  otherwise.  <br>  
 */  
virtual HRESULT  GetPLMComponentOf(CATBaseUnknown  *ipObject,  CATIPLMComponent_var  &oPLMComponent) = 0;

   
};
#endif