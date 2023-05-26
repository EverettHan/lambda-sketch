//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011
//===================================================================
// CATIFrmEditorCtxMenu.h
// Header definition of class CATIFrmEditorCtxMenu
//===================================================================
//
// Usage notes: Adds contextual menu behavior to a CATFrmEditor derived class.
// (see adapter CATEFrmEditorCtxMenu)
//
// Implement this interface on your CATFrmEditor derived type if you want you editor to add contextual menu items.
// You MUST derive CATEFrmEditorCtxMenu adapter to implement this interface.
// You MUST implement this interface in a data extension and use a BOA by using the following two lines:
//   - CATImplementClass(YourExtensionClass, DataExtension, CATIFrmEditorCtxMenu, YourCATFrmEditorDerivedClass);
//   - CATImplementBOA(CATIFrmEditorCtxMenu,YourExtensionClass);
//
// Your contextual menu will be declared in an xml file named YourCATFrmEditorDerivedClass_EditorCtxMenu.xml.
//
//===================================================================
//  2011/11/02 Creation: ERS
//===================================================================
#ifndef CATIFrmEditorCtxMenu_H
#define CATIFrmEditorCtxMenu_H

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

class CATCmdAccess;
class CATString;

extern ExportedByCATAfrFoundation  IID IID_CATIFrmEditorCtxMenu ;


class ExportedByCATAfrFoundation CATIFrmEditorCtxMenu: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    // Returns the access chain to add to the contextual menu
    virtual CATCmdAccess * GetEditorContextualMenu() = 0;

    // Sets the name for the Ctx Menu declarative file.
    // The default name is the type of editor (IsA()) + 'EditorCtxMenu.xml'
    // The input string here will replace IsA().
    virtual void SetEditorContextualName (const CATString & iEditorName) = 0;

    // Asks the editor if it allows a command header to be displayed in the contextual menu.
    // This method is asked for all items of the contextual menu except the ones that are added by the window:
    // Show/No Show, Properties, Other Selections, Center Tree.
    virtual CATBoolean AllowCommandHeaderInCtxMenu (const CATString & iHeaderId) = 0;
};

//-----------------------------------------------------------------------

#endif
