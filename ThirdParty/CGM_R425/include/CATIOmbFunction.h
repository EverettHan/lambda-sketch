/**
* @level Protected
* @usage U4 CATOmbFunctionAdapter
*/


// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
//  May 2008  Creation: Code generated by the CAA wizard  KWU
//===================================================================
#ifndef CATIOmbFunction_H
#define CATIOmbFunction_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
#include "sequence_octet.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbFunction;
#else
extern "C" const IID IID_CATIOmbFunction ;
#endif

/**
* Interface representing Functions for functional linking.
*
* <br><b>Role</b>: To create a @href CATIOmbUniversalLink with dynamic behavior an object of type @href CATIOmbFunction 
*                  is required. @href CATIOmbFunction is the object describing the function to apply to an argument to
*                  compute the dynamic target of the functional link. Functions are owned and called by objects
*                  of type @href CATIOmbFunctionCall. 
*                  
* <p>
* Functions are managed and marshalled by Function Calls. Each @href CATIOmbFunction can be used by a single type
* of @href CATIOmbFunctionCall. Then it is able to return the persistent ID of the associated Function Call Factory
* (@href CATIOmbFunctionCallFactory). Persistent IDs are created, assigned and managed by Omb and can be found in
* CATOmbUniversalLinkFactoryRegisterKey.h
*
* @href CATIOmbFunctionCall, @href CATIOmbFunctionCallFactory, @href CATOmbUniversalLinkResult
*/
class ExportedByCATObjectModelerBase CATIOmbFunction: public CATBaseUnknown
{

    CATDeclareInterface;

public:

    /** 
    * Returns the ID of the associated Function Call Factory
    *
    * <br><b>Role</b>: Returns the persistent ID of the only Factory (@href CATIOmbFunctionCallFactory) able to 
    *                  create Function Calls (@href CATIOmbFunctionCall) of type compatible with the use of this 
    *                  as a function. 
    *
    *
    * @return
    *   the ID of the associated Function Call Factory.
    *
    */
    virtual int GetFunctionCallFactoryID () = 0;

   /** 
    * Marshall the Function.
    *
    * <br><b>Role</b>: returns the stream of the Function for marshalling purpose.
    *                  This stream will be interpreted by associated Function Call Factory at unmarshalling.
    *
    * @param oStream [out]
    *   The stream of the Function
    *
    * @return
    *   <code>S_OK</code> if everything ran ok
    *   <code>E_FAIL</code>       otherwise
    *
    */
    virtual HRESULT MarshallFunction (SEQUENCE (octet) & oStream) const = 0 ; 

};

CATDeclareHandler(CATIOmbFunction, CATBaseUnknown);


#endif
