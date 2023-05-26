/* -*-C++-*- */

#ifndef CATIMoreProperties_H
#define CATIMoreProperties_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
  * @CAA2Level L1
  * @CAA2Usage U5
  */

#include "CATAfrProperties.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrProperties IID IID_CATIMoreProperties;
#else
extern "C" const IID IID_CATIMoreProperties;
#endif

/**
* Interface to manage tabpages displayed after clicking on 'More' button.
* <br><b>Role:</b> Give the list of forbidden editors.
*/

class ExportedByCATAfrProperties CATIMoreProperties : public CATBaseUnknown
{
  CATDeclareInterface;
  
public:

  /**
  * Returns the list of editors that mustn't be displayed when clicking on 'More'
  */
  virtual CATListOfCATString GetListOfForbiddenEditors()= 0;
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIMoreProperties, CATBaseUnknown);

#endif
