// COPYRIGHT Dassault Systemes 2005
#ifndef CATIListViewCtxMenuModel_H
#define CATIListViewCtxMenuModel_H

#include "CATViewItf.h"
#include "CATBaseUnknown.h"
#include "CATDlgContextualMenu.h"
#include "CATString.h"

extern ExportedByCATViewItf IID IID_CATIListViewCtxMenuModel;

/**
 * CATIListViewCtxMenuModel. Interface to be implemented to add application specific commands
 * to a CATListView's contextual menus.  Should be implemented on the model (CATIListViewModel)
 * used by the ListView.  It is not necessary to implement this IF on your model if you need
 * no additional menu commands.
 **/
class ExportedByCATViewItf CATIListViewCtxMenuModel: public CATBaseUnknown
{
    CATDeclareInterface;
public:

   /**
    * Add a set of application-specific commands to a ListView's contextual menu, when
    * a user right clicks on a column header.  Implementer is expected to set  up any
    * needed callbacks.  It can be useful to use CATRemotePushItem as the menu button
    * instead of CATDlgPushItem, since you will need to manage the callback from outside of
    * the CATCommand heirarchy. CATRemotePushItem makes this easy.<br>
    * Menu items added within this method's implementation will be added to the beginning
    * of the menu.
    */
   virtual void AddColHeaderCommands( const CATString& iColumnID,
                                      CATDlgContextualMenu*& iMenu )=0;

   /**
    * Add a set of application-specific commands to a ListView's contextual menu, when
    * a user right clicks on a row header.  Implementer is expected to set  up any
    * needed callbacks.  It can be useful to use CATRemotePushItem as the menu button
    * instead of CATDlgPushItem, since you will need to manage the callback from outside of
    * the CATCommand heirarchy. CATRemotePushItem makes this easy.<br>
    * Menu items added within this method's implementation will be added to the beginning
    * of the menu.
    */
   virtual void AddRowHeaderCommands( const CATBaseUnknown_var& iObj,
                                      CATDlgContextualMenu*& iMenu )=0;


   /**
    * Add a set of application-specific commands to a ListView's contextual menu, when
    * a user right clicks on a table cell.  Implementer is expected to set  up any
    * needed callbacks.  It can be useful to use CATRemotePushItem as the menu button
    * instead of CATDlgPushItem, since you will need to manage the callback from outside of
    * the CATCommand heirarchy. CATRemotePushItem makes this easy.<br>
    * Menu items added within this method's implementation will be added to the beginning
    * of the menu.<br>
    * In the current implemntation, all row header commands are shown when on a cell as well,
    * so there is no need to duplicate commands you want in both places.
    */
   virtual void AddCellCommands( const CATBaseUnknown_var& iObj,
                                 const CATString& iColumnID,
                                 CATDlgContextualMenu*& iMenu )=0;

};

CATDeclareHandler( CATIListViewCtxMenuModel, CATBaseUnknown );

#endif
