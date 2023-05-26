/* -*-c++-*- */
#ifndef CATIDocLocator_h
#define CATIDocLocator_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Private
  * @usage U5
  */

#include "CATBaseUnknown.h"
class CATIDocId;
class CATIDocDescriptor;
class CATUnicodeString;
class CATDocument;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocLocator;

/**
* Interface allowing access to the document locator's name and descriptor element.
*/

class ExportedByAD0XXBAS CATIDocLocator: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
    *  Retrieves the name of the document's locator.
	*  <br><b>Note:</b>This is the name that appears in the panel listing available locators.
	*  @param oName
	*         The document locator's name.
    */
  virtual HRESULT GetName(CATUnicodeString& oName) = 0;

  /**
    *  Retrieves the document's descriptor element.
	*  @param iDocId
	*         The document's identification element.
	*  @param oDocDescriptor
	*         The returned document descriptor element.
	*  @param iPointingDocId
	*         The pointing document's identification element.
    */
  virtual HRESULT RetrieveDocDescriptor(CATIDocId * iDocId, CATIDocDescriptor ** oDocDescriptor, CATIDocId * iPointingDocId = NULL) = 0;
};

CATDeclareHandler(CATIDocLocator, CATBaseUnknown);

#endif
