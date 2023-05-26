#pragma once

#include "CATCommand.h"
#include "CATString.h"
#include "CATVidWidget.h"
#include "CATVidCtlPopup.h"

#include "VisuDialog.h"

#include "CATVidMdlMenu.h"

/**
* @ingroup VIDControls
*/
class ExportedByVisuDialog CATVidCtlMenuPopup : public CATVidCtlPopup
{
  CATDeclareClass;

public:
  // Standard constructors
  CATVidCtlMenuPopup();

  void SetMenu(CATVidMdlMenu* i_pMenu);
  CATVidMdlMenu* GetMenu();

protected:

  virtual ~CATVidCtlMenuPopup();

  CATVidCtlMenuPopup(CreateLetterFunc i_pCreateLetterFunc);

private:
  // Copy constructor and equal operator
  CATVidCtlMenuPopup(CATVidCtlPopup &);
  CATVidCtlMenuPopup& operator=(CATVidCtlMenuPopup&);
};

