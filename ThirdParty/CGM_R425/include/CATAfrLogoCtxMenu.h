/**
 * @fullreview ERS GDX 07:07:02
 */

#ifndef CATAfrLogoCtxMenu_H
#define CATAfrLogoCtxMenu_H

#include "CATDlgContextualMenu.h"
#include "CATAfrFoundation.h"

class CATDialog;
class CATCmdAccess;
class CATNotification;
class CATCommand;

 class ExportedByCATAfrFoundation CATAfrLogoCtxMenu: public CATDlgContextualMenu
{
  CATDeclareKindOf;
  DeclareResource(CATAfrLogoCtxMenu,CATDlgContextualMenu)

  public:
  CATAfrLogoCtxMenu(CATDialog *parent);
  virtual ~CATAfrLogoCtxMenu();
  
private:
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATAfrLogoCtxMenu ();
  CATAfrLogoCtxMenu (const CATAfrLogoCtxMenu &);
  CATAfrLogoCtxMenu & operator= (const CATAfrLogoCtxMenu &);

  void OpenCB(CATCommand *, CATNotification *, CATCommandClientData);
};
#endif
