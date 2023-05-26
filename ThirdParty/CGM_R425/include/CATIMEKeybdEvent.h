// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATIMEKeybdEvent_H
#define CATIMEKeybdEvent_H

#include "CATVisFoundation.h"

#include "CATNotification.h"
#include "CATDataType.h"
#include "CATKeybdEventType.h" // def of CATKeyCode, CATModifier

class ExportedByCATVisFoundation CATIMEKeybdEvent : public CATNotification
{
  CATDeclareClass;

public:

#ifdef _WINDOWS_SOURCE
  CATIMEKeybdEvent (UINT nMsg, WPARAM wParam, LPARAM lParam, HWND m_hCompositionWindow)
  {
    this->nMsg = nMsg;
    this->wParam = wParam;
    this->lParam = lParam;
    this->m_hCompositionWindow = m_hCompositionWindow;
  }

#endif  
  CATIMEKeybdEvent()
  {

  }

#ifdef _WINDOWS_SOURCE
  WPARAM wParam;
  LPARAM lParam;
  UINT nMsg;
  HWND m_hCompositionWindow;
#endif
};

#endif
