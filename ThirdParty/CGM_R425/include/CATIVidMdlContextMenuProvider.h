//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2012/08/06
//===================================================================
// CATIVidMdlContextMenuProvider.h
// Header definition of class CATIVidMdlContextMenuProvider
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/08/06 Creation: Code generated by the 3DS wizard  VV6
//===================================================================
#ifndef CATIVidMdlContextMenuProvider_H
#define CATIVidMdlContextMenuProvider_H

#include <VisuDialog.h>
#include <CATBaseUnknown.h>
#include <CATSYPArray.h>
class CATVidMdlIndex; 
class CATVidMdlContextMenu;

extern ExportedByVisuDialog  IID IID_CATIVidMdlContextMenuProvider;


/** @ingroup groupVidModelViewModel
 * Object modeler interface to implement in order to fill in a contextual menu
 * associated to items displayed by an items-view class.
 *
 * Setting a contextual menu on an items-view control (like the listview or the
 * treeview) using the @ref CATVidCtl#SetContextMenu member function will
 * associate a contextual menu to the whole control (including its scrollbars).
 * see @ref CATVidCtlAbstractItemsView_secContextMenu.
 *
 * If you want to be more precise and only set a contextual menu on the items
 * displayed by an items-view control, you need to implement this interface
 * and set its implementation on the items-view control by calling
 * @ref CATVidCtlAbstractItemsView#SetContextMenuProvider member function.
 *
 * When used, each time a user will perform a right-click on an item displayed
 * by the items-view control, the @ref #FillContextMenu member function will be
 * called. This member function is responsible to fill in the given contextual
 * menu that corresponds to the item under the mouse pointer.
 *
 * The following sample implements the CATIVidMdlContextMenuProvider interface
 * using the BOA mechannism (however it's also possible to use the TIE
 * mechanism) to fill the content of the contextual menu of items displayed
 * by an items view control.
 *
 * @code
 * // -------------------------------------------------------------------------
 * // Header file
 * // -------------------------------------------------------------------------
 * #include <CATIVidMdlContextMenuProvider.h>
 *
 * class CATVidMdlIndex;
 * template <class T> class CATSYPArray;
 * class CATVidMdlContextMenu;
 *
 * class CATVidTstMusicContextMenuProvider : public CATIVidMdlContextMenuProvider
 * {
 *   CATDeclareClass;
 *
 * public:
 *
 *   CATVidTstMusicContextMenuProvider();
 *   virtual ~CATVidTstMusicContextMenuProvider();
 *
 *   virtual void FillContextMenu(CATVidMdlIndex & i_currentIndex,
 *                                CATSYPDynArray<CATVidMdlIndex> & i_selectedIndex,
 *                                CATVidMdlContextMenu * o_pContextMenu);
 *
 * private:
 *
 *   CATVidTstMusicContextMenuProvider(const CATVidTstMusicContextMenuProvider &);
 *   CATVidTstMusicContextMenuProvider & operator= (const CATVidTstMusicContextMenuProvider &);
 *
 * };
 *
 * // -------------------------------------------------------------------------
 * // Implementation file
 * // -------------------------------------------------------------------------
 * #include <CATVidTstMusicContextMenuProvider.h>
 * #include <CATVidMdlIndex.h>
 * #include <CATSYPArray.h>
 * #include <CATVidMdlContextMenu.h>
 * #include <CATVidMdlStandardList.h>
 * #include <CATVidTstMusicItem.h>
 * CATImplementClass(CATVidTstMusicContextMenuProvider,
 *                   Implementation,
 *                   CATBaseUnknown,
 *                   CATNull);
 *
 * CATImplementBOA(CATIVidMdlContextMenuProvider, CATVidTstMusicContextMenuProvider);
 *
 *
 * CATVidTstMusicContextMenuProvider::CATVidTstMusicContextMenuProvider()
 *   : CATIVidMdlContextMenuProvider()
 * {
 * }
 *
 * CATVidTstMusicContextMenuProvider::~CATVidTstMusicContextMenuProvider()
 * {
 * }
 *
 * void CATVidTstMusicContextMenuProvider::FillContextMenu(CATVidMdlIndex & i_currentIndex,
 *                                                         CATSYPDynArray<CATVidMdlIndex> & i_selectedIndex,
 *                                                         CATVidMdlContextMenu * o_pContextMenu)
 * {
 *   if (NULL == o_pContextMenu)
 *     return;
 *
 *   if (!i_currentIndex.IsValid())
 *     return;
 *
 *   if (NULL_var == i_currentIndex.GetElement())
 *     return;
 *
 *   // Fill in the contextual menu
 *   // For instance, append the title as header
 *   CATVidTstMusicItem * pItem = CAT_DYNAMIC_CAST(CATVidTstMusicItem, i_currentIndex.GetElement()->GetImpl());
 *   CHECK_TRUE_RET(pItem);
 *   o_pContextMenu->AppendHeader(pItem->GetTitle());
 * }
 *
 * // -------------------------------------------------------------------------
 * // How to use it
 * // -------------------------------------------------------------------------
 * CATVidTstMusicContextMenuProvider * pCtxMenuProvider = new CATVidTstMusicContextMenuProvider;
 * pListView->SetContextMenuProvider(pCtxMenuProvider);
 * pCtxMenuProvider->Release();
 * // Now each time a right click occured on an items displayed by the list view,
 * // the CATVidTstMusicContextMenuProvider::FillContextMenu is called to fill in
 * // the contextual menu associated to the item right clicked.
 * @endcode
 *
 * You can find this sample in VisuImmersiveDialog.tst/VIDModelViewSamples.m module.
 */
class ExportedByVisuDialog CATIVidMdlContextMenuProvider : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  /**
   * Fill the given context menu depending on which item has been right-clicked
   * and the content of the selection.
   *
   * @param i_currentIndex index of the item that has been right-clicked.
   *
   * @param i_selectedIndexes the content of the selection.
   *
   * @param o_pContextMenu the contextual menu to fill in. This contextual menu
   * is the one associated to the right-clicked item.
   */
  virtual void FillContextMenu(CATVidMdlIndex & i_currentIndex,
                               CATSYPDynArray<CATVidMdlIndex> & i_selectedIndexes,
                               CATVidMdlContextMenu * o_pContextMenu) = 0;
};

//-----------------------------------------------------------------------
CATDeclareHandler( CATIVidMdlContextMenuProvider, CATBaseUnknown );

#endif
