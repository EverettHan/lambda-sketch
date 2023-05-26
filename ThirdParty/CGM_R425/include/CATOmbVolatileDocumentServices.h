#ifndef CATOmbVolatileDocumentServices_H
#define CATOmbVolatileDocumentServices_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U1
  */


#include "AC0XXLNK.h"
#include "CATErrorDefs.h"
class CATDocument;
class CATUnicodeString;


/**
* Services to create a volatile document
* <br><br>There is one method for creating a new volatile document in the current session.
* Only restricted classes can use this service.
* The created document cannot be saved.
* @see CATDocument
*/

class ExportedByAC0XXLNK CATOmbVolatileDocumentServices
{
  friend class CATKwdDocumentAccess;
  friend class __TA__OmbTST_CATOmbVolatileDocumentServices;

private:

  /**
  * Creates a volatile document of a given type.
  * <br><b>Role:</b>
  * Creates and initializes data of a document of the given type. The
  * initialization is done thanks to the @href CATInit#init method.
  * <br>The created document cannot be saved.
  * <br>The document must be removed from the session before exiting or when it is
  * no longer needed.
  * @param iType
  *     The string to define the kind of document to create.
  * @param opNewDoc
  *     The document created.
  * @return
  *   <code> S_OK </code>         The document has been created
  *   <code> E_INVALIDARG </code> Forbidden to create a document with the given latetype
  *   <code> E_FAIL </code>       Unexpected error
  */
  static HRESULT New(const CATUnicodeString& iType, CATDocument*& opNewDoc);


};
#endif
