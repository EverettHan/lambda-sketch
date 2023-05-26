/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2001

/** 
*@level  Private
*@usage U1
*/

#ifndef CATDocLocServices_H_
#define CATDocLocServices_H_


#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"

/**
  * @nodoc
  * Determines if a document locator is active.
  * @param iLocatorType
  *        The locator's late type.       
  * @param oResult
  *        TRUE  - the locator is active.
  *        <br>FALSE - the locator is not active.
  */

ExportedByAC0XXLNK 
HRESULT CATIsDocLocatorActive(const CATUnicodeString& iLocatorType, CATBoolean& oResult);

#endif


