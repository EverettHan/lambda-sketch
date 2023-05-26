#pragma once

#include "CATVidFraPopupWindow.h"

class ExportedByVisuDialog CATVidFraMenuPopupWindow : public CATVidFraPopupWindow
{
  CATDeclareClass;

public:

  /** 
  * Initialize this class 
  *
  * @param i_pParent the CATCommand parent; can be @c NULL.
  *
  * @param i_pIdentifier the name of the CATCommand.
  *
  * @param i_pPopup the popup whose content is displayed with this
  * window; can't be @c NULL.
  */
  CATVidFraMenuPopupWindow(CATCommand * i_pParent, 
                          const CATString & i_pIdentifier, 
                          CATVidCtlPopup * i_pPopup,
                          const CATUnicodeString& i_look);

  /** 
  * Initialize this class 
  *
  * @param i_pWidget the widget whose content is displayed with this
  * window.
  */
  CATVidFraMenuPopupWindow(CATVidWidget *i_pWidget,
                         const CATString & i_pIdentifier,
                         const CATUnicodeString& i_look);


  /**
  * Default constructor 
  */
  CATVidFraMenuPopupWindow();

protected:
    virtual ~CATVidFraMenuPopupWindow();

private:

  CATVidFraMenuPopupWindow(const CATVidFraMenuPopupWindow&);
  CATVidFraMenuPopupWindow&operator=(const CATVidFraMenuPopupWindow&);
};

 
 
 
