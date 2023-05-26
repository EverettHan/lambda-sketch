/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIBreak_h
#define _CATIBreak_h

/**
 * @level Private
 * @usage U3
 */

#include "CATBaseUnknown.h"

/**
 * Interface to break an element.
 * <b>Role</b>: For instance, it can be used to break a external link.
 */
#include "AC0XXLNK.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIBreak;
#else
extern "C" const IID IID_CATIBreak;
#endif

class ExportedByAC0XXLNK CATIBreak : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  /**
   * Retrieves the break status.
   * @param oBreakStatus
   * The break status.
   * <br><b>Legal values </b>:
   * <br>0 : the element can not be broken. 
   * <br>1 : the element can be broken. 
   * <br>2 : the element is broken. 
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT BreakStatus(int& oBreakStatus) = 0;

  /**
   * Breaks the element.
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT Break() = 0;
  
};

#endif
