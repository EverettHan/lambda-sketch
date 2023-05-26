#ifndef CATISearchInformation_H
#define CATISearchInformation_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U4 CATCafSearchInformationAdapter
 */

#include "UIModelInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATISearchInformation;
#else
extern "C" const IID IID_CATISearchInformation;
#endif

/**
  * Interface that enables a knowledgeware package to be taken into account in
  * the Edit>Find... command.
  * <p><b>BOA information</b>: this interface CANNOT be implemented
  * using the BOA (Basic Object Adapter).
  * To know more about the BOA, refer to the "Object Modeler" chapter in the CAA Encyclopedia. </p>
  */

//-----------------------------------------------------------------------------
class ExportedByUIModelInterfaces CATISearchInformation : public CATBaseUnknown
{ 

  CATDeclareInterface;

public:

}; 

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATISearchInformation, CATBaseUnknown);

#endif
