#ifndef __CATIAfrOpenInNewWindow_h
#define __CATIAfrOpenInNewWindow_h

// COPYRIGHT DASSAULT SYSTEMES 2006
#include "CATBaseUnknown.h"
#include "UIModelInterfaces.h"
#include "CATAfrItf.h"

class CATCommand;
class CATPathElement;

extern ExportedByCATAfrItf IID IID_CATIAfrOpenInNewWindow;


/**
 * @nodoc
 * Interface to manage "Open in new window" item in contextual menu.
 * Any selectable object may implement this interface to tell the contextual menu
 * whether it wants the "Open in new window" item to be shown in the contextual menu.
 */
class ExportedByCATAfrItf CATIAfrOpenInNewWindow : public CATBaseUnknown
{
	
  CATDeclareInterface;
  
public:

  /** @nodoc
    * Controls the "Open in new window" contextual item.
    * Please return S_OK whether you want to display the contextual item.
    * Please return any value different from S_OK whether you do not want to display the contextual item.
    */
  virtual HRESULT CanBeOpenedInNewWindow (CATPathElement &IpSelectionPath) = 0;
};

#endif
