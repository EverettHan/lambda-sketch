/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATOmbDocIdFinder_H
#define CATOmbDocIdFinder_H

/**
* @level Private
* @usage U1
*/

#include "AC0XXLNK.h"
#include "CATUnicodeString.h"
class CATIDocId;

  /**
  * @nodoc
  * Class to retrieve a CATIDocId pointer from a document's identifier.
  * <b>Role:</b>This class enables you to retrieve a @href CATIDocId interface
  * pointer from a document identifier streamed as a <tt>CATUnicodeString</tt>.
  */
class ExportedByAC0XXLNK CATOmbDocIdFinder
{
 public:

  /**
  * @nodoc 
  * Retrieves a CATIDocId pointer from a document's identifier.
  * @param iDocEnvironmentIdentifier
  *    It is the identifier of the environment. For a "File" environment, the value
  * of this string is "File".
  * @param iDocumentIdentifier
  *    It is the document's identifier under <tt>CATUnicodeString</tt> format. For the
  * "File" environment, the string is the path of the document. 
  *   <br>You can retrieve this information using the @href CATIDocId#GetIdentifier 
  * method. The @href CATIDocId interface pointer is first retrieved using the 
  * @href CATDocument#GetDocId method.
  * @param iDocType
  *    It is the extension of the document. <tt>CATPart</tt>, <tt>CATProduct</tt>,...
  * @param oDocId
  *    The unique document's identifier.
  */
  static HRESULT RecoverDocId(const CATUnicodeString& iDocEnvironmentIdentifier,
                              const CATUnicodeString& iIdentifier, 
                              const CATUnicodeString& iDocType, 
                              CATIDocId ** oDocId);
  
};
#endif
