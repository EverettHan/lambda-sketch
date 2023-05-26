// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIOmbCheckDownward.h
// Define the CATIOmbCheckDownward interface
//
//===================================================================
//
// Usage notes:
//   New interface: This interface offers OmbDownwardData services
//
//===================================================================
//
//===================================================================

/**
* @level Private
* @usage U3
*/

#ifndef CATIOmbCheckDownward_H
#define CATIOmbCheckDownward_H

#include "CATBaseUnknown.h"
#include "CATOmbDWC.h"
#include "CATDocument.h"
#include "IUnknown.h"
class CATOmxKeyValueBlock;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbDWC IID IID_CATIOmbCheckDownward;
#else
extern "C" const IID IID_CATIOmbCheckDownward;
#endif

//------------------------------------------------------------------

/**
* This interface offers to check if content of a container is compliant with CATBack Operation
*
* Please Derive from Adapter CATEOmbCheckDownward
*/

class  ExportedByCATOmbDWC CATIOmbCheckDownward : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Check if content of a container is compliant with DonwwardAsSpec operation
  * @param iParamList
  *  some subsequent parameter
  * @return
  *  <UL>
  *    <LI>TRUE all data inside container are compliant</LI>
  *    <LI>FALSE, there are non compliant content in this container.</LI>
  *  </UL>
  */
  virtual CATBoolean ContentCompliantForDownwardAsSpec(CATOmxKeyValueBlock& iParamList) = 0;
};

#endif 
