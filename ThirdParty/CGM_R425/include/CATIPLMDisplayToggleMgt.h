#ifndef CATIPLMDisplayToggleMgt_h
#define CATIPLMDisplayToggleMgt_h
// COPYRIGHT DASSAULT SYSTEMES   2008

#include "CATBaseUnknown.h"
#include "CATInteractiveInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIPLMDisplayToggleMgt;
#else
extern "C" const IID IID_CATIPLMDisplayToggleMgt;
#endif
/**
 * Interface to allow the switch of DisplayName on a dedicated window.
 * <b>Role</b>: Call this interface when pushing F6 Button.
 */
class ExportedByCATInteractiveInterfaces CATIPLMDisplayToggleMgt : public CATBaseUnknown
{
 CATDeclareInterface;

public:
 
  /**
  * Prevent the display engine that it has to be changed.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SwitchDisplayMode() = 0 ; 

  /**
  * forces the view to refresh its display name.
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT InvalidateView() = 0 ;

};

CATDeclareHandler(CATIPLMDisplayToggleMgt, CATBaseUnknown);
#endif
