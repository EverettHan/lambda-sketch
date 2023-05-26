#ifndef __CATDLGTREEITEM__H__
#define __CATDLGTREEITEM__H__

#include "CATDlgInclude.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDataType.h"
#ifdef _WINDOWS_SOURCE
#include <CommCtrl.h>
#endif

#define CATDLGTREEITEMROOT  ((CATDlgTreeItem *) (CATINTPTR) 1)
#define CATDLGTREEITEMFIRST ((CATDlgTreeItem *) (CATINTPTR) 2)
#define CATDLGTREEITEMLAST  ((CATDlgTreeItem *) (CATINTPTR) 3)

class ExportedByDI0PANV2 CATDlgTreeItem
{
  friend class l_CATDlgMfcTree;
  friend class l_CATDlgTree;

public:
  /*
   * Constructeur du CATDlgTreeItem
   * itemText : CATUnicodeString qui represente le texte qui apparait dans l'arbre
   * data     : CATBaseUnknown * qui represente la donnee associee à l'élément
   *              l'appelant doit faire un AddRef sur le data avant de construire l'objet
   *              l'appelant ne doit pas faire de release sur le data apres avoir construit l'objet
   */
  CATDlgTreeItem(CATUnicodeString itemText = "", CATBaseUnknown * data = NULL);

  /*
   * Destructeur
   */
  virtual ~CATDlgTreeItem();

  /*
   * Return the parent of the item, NULL if no parent
   */
  CATDlgTreeItem * GetParent();

  /*
   * Unselect all items
   */
  void UnselectAll();

  /*
   * Get the number of selected items
   */
  int GetSelectedCount();

  /*
   * Return / Sets the data associated to the item
   */
  CATBaseUnknown * GetData();
  void SetData(CATBaseUnknown * data);

  /*
   * Return / Sets the text associated to the item
   */
  CATUnicodeString GetItemText();
  void SetItemText(CATUnicodeString iText);

  /*
   * Return / Sets the selected flag associated to the item
   */
  CATBoolean IsSelected();
  void SetSelected(CATBoolean iSelected);

  /*
   * Return / Sets the color associated to the item
   */
  int GetItemColor();
  void SetItemColor(int iColor);

private:
  CATDlgTreeItem * _parent;
  CATDlgTreeItem * _prev;
  CATDlgTreeItem * _next;
  CATListPV        _children;
  CATUnicodeString _itemText;
  CATBoolean       _selected;
  int              _itemTextColor;
  CATBaseUnknown * _data;
  
#ifdef DRIVER_MOTIF
  CATBoolean	   _expanded;
#endif

#ifdef _WINDOWS_SOURCE
  HTREEITEM        _hItem;
#endif
};

#endif
