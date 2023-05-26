// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected
* @usage U3
*/
//===================================================================
//
// CATIOmbUpdateContract.h
// Define the CATIOmbUpdateContract interface.
//
// A Delegate pointed by a Product Linkable Object is impacted by
// the modifications of its reference object in the Stream Descriptor. 
// The CATIOmbUpdateContract defines the propagation of this impact.
//
//===================================================================
#ifndef CATIOmbUpdateContract_H
#define CATIOmbUpdateContract_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbUpdateContract;
#else
extern "C" const IID IID_CATIOmbUpdateContract ;
#endif

class CATIOmbFunction_var;

//------------------------------------------------------------------

/**
* Interface creating and handling a contract.
*
* <br><b>Role</b>: Sets/Gets updatecontract-sensitiveness
* @see CATIOmbDelegateBuilder
*/
class ExportedByAC0XXLNK CATIOmbUpdateContract: public CATBaseUnknown
{
    friend class CATOmbUniversalLinkImpl;
    friend class CATEPrdMMServices ; // Compute function for Pub ... // To clean
    friend class CATEModeler3DMMServices ;

    CATDeclareInterface;

 protected :
    // method for mechmod delegate migration
    virtual HRESULT PrivateGetFctForDlgMigration(CATIOmbFunction_var& oFunction) = 0; 
};

CATDeclareHandler(CATIOmbUpdateContract, CATBaseUnknown);

#endif
