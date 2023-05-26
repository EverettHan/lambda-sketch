/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef  _CATIExternalLinks_h
#define  _CATIExternalLinks_h

/**
 * Interface CATIExternalLinks.
 * <b>Role</b>: Interface to retrieve a list of external links.
 *             
 */
/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "AC0XXLNK.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIExternalLinks;
#else
extern "C" const IID IID_CATIExternalLinks;
#endif

class CATListValCATBaseUnknown_var;

class ExportedByAC0XXLNK CATIExternalLinks : public CATBaseUnknown
{ 
  public :

  CATDeclareInterface;

  /**
  * Retrieves a list of external links.
  * @param oExternalLinks
  * The list of external links.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetExternalLinks(CATListValCATBaseUnknown_var& oExternalLinks) = 0;


};

#endif      

