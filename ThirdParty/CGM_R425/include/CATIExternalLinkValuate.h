/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIExternalLinkValuate_h
#define _CATIExternalLinkValuate_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

/**
 * Interface to set the pointed document of a external link.
 * <b>Role</b>: A external link is a model link between two elements
 *              which are in different documents.
 */
#include "AC0XXLNK.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIExternalLinkValuate;
#else
extern "C" const IID IID_CATIExternalLinkValuate;
#endif

class CATUnicodeString;
class CATIDocId;

class ExportedByAC0XXLNK CATIExternalLinkValuate : public CATBaseUnknown
{
public:
  CATDeclareInterface;
  
  /**
   * Allows to change the pointed document.
   * @param iDoc
   *   The new pointed document
   * @param oMessage
   *   Explain here why you don't allow to change the pointed document (NLS).
   * @return
   *   <br><b>Legal values</b>: <ul>
   *   <li><tt>S_OK</tt>: the link allows its document to be changed.</li>
   *   <li><tt>S_FALSE</tt>: the pointed document can't be changed.</li>
   *   <li><tt>Otherwise</tt>: an error occured.</li></ul>
   */
  virtual HRESULT AllowSetDocument(CATUnicodeString& oMessage) = 0;
  
  /**
   * Accepts iDoc as the new pointed document.
   * @param iDoc
   *   The new pointed document
   * @param oMessage
   *   Explain here why you don't accept this new document (NLS).
   * @return
   *   <br><b>Legal values</b>: <ul>
   *   <li><tt>S_OK</tt>: the link accepts the document.</li>
   *   <li><tt>S_FALSE</tt>: the link refuses the document.</li>
   *   <li><tt>Otherwise</tt>: an error occured.</li></ul>
   */
  virtual HRESULT AcceptDocument(CATIDocId* iDoc, CATUnicodeString& oMessage) = 0;
  
  /**
   * Sets the pointed document.
   * @param iDoc
   *   The new pointed document
   * @return
   *   <br><b>Legal values</b>: S_OK, E_FAIL<br>
   *   If an error occurs, you should set the CATIA global error in order to inform the user.
   *   See @href CATError#CATSetLastError and @href CATError#CATReturnError.
   */
  virtual HRESULT SetDocument(CATIDocId* iDoc) = 0;
};

#endif

