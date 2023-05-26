#ifndef CATIFrameController_H
#define CATIFrameController_H
/* COPYRIGHT DASSAULT SYSTEMES 1999 */


#include "IUnknown.h"

class CATDialog;


/**
 * Controls an application main window.
 * Any SDI or MDI application displays a main window to display the available
 * commands in the menu bar and in toolbars, possibly undocked. It also
 * accomodates the document window(s). CATIFrameController is the interface
 * to control this application main window.
 */
class  CATIFrameController: public IUnknown
{
public:
  
/**
 * Retrieves the application main window.
 * @param oMainWindow
 *   The application main window
 */ 
  virtual HRESULT GetFrameView(CATDialog ** oMainWindow) const =0;
};

/* 88d33543-df7d-0000-0280-030b27000000 */
extern "C" const IID IID_CATIFrameController ;


#endif
