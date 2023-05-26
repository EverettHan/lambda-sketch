/* -*-C++-*- */

#ifndef CATIRootProperties_H
#define CATIRootProperties_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
  * @CAA2Level L1
  * @CAA2Usage U5
  */

#include "CATAfrProperties.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProperties IID IID_CATIRootProperties;
#else
extern "C" const IID IID_CATIRootProperties;
#endif

/**
* Interface to manage priorities beetwen the Edit Properties editors of a workshop.
* <br><b>Role:</b> each workshop's root object has to implement it.
* @see CATIEditProperties
*/

class  ExportedByCATAfrProperties CATIRootProperties :  public CATBaseUnknown

{
  CATDeclareInterface;
  
public:

  /**
  * Returns the list of editors associated to the selection.
  */
  virtual CATListOfCATString GetListOfEditors ()= 0;
  
  /**
   * Gives the father associated to the selection.
   *<br><b>Role:</b> Do nothing in this method.
   */
  virtual void GetAssociatedObject ()= 0; 

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(  CATIRootProperties, CATBaseUnknown ) ;

#endif
