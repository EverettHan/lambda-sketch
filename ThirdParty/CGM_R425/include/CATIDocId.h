/* -*-c++-*- */
#ifndef CATIDocId_h
#define CATIDocId_h

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Protected
  * @usage U3
  */

#include "CATBaseUnknown.h"
class CATIDocEnvironment;
class CATUnicodeString;

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIDocId;

/**
* Interface allowing access to a document's unique identification information.
*/

class ExportedByAD0XXBAS CATIDocId: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
    * @nodoc 
    *  Retrieves the document's environment element.
	*  @param oDocEnvironment
	*         The returned document environment element. 
    */
  virtual HRESULT GetDocEnvironment(CATIDocEnvironment ** oDocEnvironment) = 0;

  /**
    *  Retrieves the document's identifier. This is the storage path name of the document.
	*  @param oIdentifier
	*         The returned document identifier.
    */
  virtual HRESULT GetIdentifier(CATUnicodeString& oIdentifier) = 0;

  /**
    *  Retrieves the document's type. This is the document's suffix, such as CATPart, CATDraw, etc.
	*  @param oType
	*         The returned document type.
    */
  virtual HRESULT GetType(CATUnicodeString& oType) = 0;
};

CATDeclareHandler(CATIDocId, CATBaseUnknown);

#endif
