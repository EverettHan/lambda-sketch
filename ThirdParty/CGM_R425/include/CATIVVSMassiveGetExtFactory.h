/**
 * @level Private
 * @usage U3
 */
// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATIVVSMassiveGetExtFactory.h
// Define the CATIVVSMassiveGetExtFactory interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2007  Creation: Code generated by the CAA wizard  NLZ
//===================================================================
#ifndef CATIVVSMassiveGetExtFactory_H
#define CATIVVSMassiveGetExtFactory_H

#include "VVSCoreProtocol.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVVSCoreProtocol IID IID_CATIVVSMassiveGetExtFactory;
#else
extern "C" const IID IID_CATIVVSMassiveGetExtFactory ;
#endif

class CATIVVSMassiveCopy;
class CATVVSTransaction;

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* CATIVVSMassiveGetExtFactory are ...
* <p>
* Do not use the CATIVVSMassiveGetExtFactory interface for such and such

*
* @example
*  // example is optional
*  CATIVVSMassiveGetExtFactory* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_CATIVVSMassiveGetExtFactory,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByVVSCoreProtocol CATIVVSMassiveGetExtFactory: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

   /** 
   * Create a massive get
   * @param opMassiveCopy [out, IUnknown#Release] 
   * The massive get.
   * @param iTransaction [in]
   * The transaction.
   * @return
   * S_OK if the get was succesfully created, or E_FAIL otherwise
  */  
   virtual HRESULT CreateCopy(CATIVVSMassiveCopy *&opMassiveCopy,CATVVSTransaction* iTransaction=NULL) const = 0;

};

//------------------------------------------------------------------

#endif