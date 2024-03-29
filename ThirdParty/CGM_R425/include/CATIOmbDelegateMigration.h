/**
* @level Protected
* @usage U5
*/


// COPYRIGHT Dassault Systemes 2009
//===================================================================
//  Jan 2009  Creation: Code generated by the CAA wizard  KWU
//===================================================================
#ifndef CATIOmbDelegateMigration_H
#define CATIOmbDelegateMigration_H

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbDelegateMigration;
#else
extern "C" const IID IID_CATIOmbDelegateMigration ;
#endif

/**
* Function Call with NULL function can be created from CATIOmbDelegateMigration objects. 
* It enables to migrate from old delegate with NULL update contract to new Function Call.
*/

class CATIOmbFunction_var;

class ExportedByCATObjectModelerBase CATIOmbDelegateMigration: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
       virtual int GetFactoryID() = 0;
       virtual HRESULT GetFunctionForMigration(CATIOmbFunction_var& oFunction)=0;


};
#endif
