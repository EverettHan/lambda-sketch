/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATEPLMDisplayToggleMgt_h
#define _CATEPLMDisplayToggleMgt_h

#include "CATBaseUnknown.h"

/**
 * Adaptor for CATIReorderList interface
 */
#include "CATInteractiveInterfaces.h"
#include "CATIPLMDisplayToggleMgt.h"

class CATUnicodeString;
class CATBaseUnknown_var;

class ExportedByCATInteractiveInterfaces CATEPLMDisplayToggleMgt : public CATIPLMDisplayToggleMgt
{ 
public:
  /**
  * Constructor
  */
  CATEPLMDisplayToggleMgt();

  /**
  * Prevent the display engine that it has to be changed.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  HRESULT SwitchDisplayMode();

  /**
  * forces the view to refresh its display name.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  HRESULT InvalidateView();

private:


  CATEPLMDisplayToggleMgt(const CATEPLMDisplayToggleMgt&);
  CATEPLMDisplayToggleMgt& operator=(const CATEPLMDisplayToggleMgt&);

};

#endif      

