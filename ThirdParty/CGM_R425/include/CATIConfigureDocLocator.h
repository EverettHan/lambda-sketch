/* -*-c++-*- */
#ifndef CATIConfigureDocLocator_h
#define CATIConfigureDocLocator_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
*  @level Private
*  @usage U5
*/

#include "CATBaseUnknown.h"
class CATDialog;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIConfigureDocLocator;

/**
  * Interface allowing the configuration of an interactive panel specific 
  * to a document locator. 
  */
class ExportedByAD0XXBAS CATIConfigureDocLocator: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** Configures an interactive panel specific to a document locator.
    * @param iParent
	*     The interactive panel's dialog parent.
	*/
  virtual HRESULT Configure(CATDialog* iParent)=0;
};

CATDeclareHandler(CATIConfigureDocLocator, CATBaseUnknown);

#endif
