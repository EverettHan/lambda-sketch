//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/07/01
//===================================================================
// CATVidCtlListViewItem.h
// Header definition of class CATVidCtlListViewItem
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/07/01 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATVidCtlListViewItem_H
#define CATVidCtlListViewItem_H

#include <VisuDialog.h>
#include <CATVidCtlBaseViewItem.h>

class CATUnicodeString;
class CATVidWidget;
class CATBaseUnknown_var;

/**
 * A view item displayed by the listview control. It inherits CATVidCtlBaseViewItem,
 * and adds the emission of an event when the user clicks the element.
 */
class ExportedByVisuDialog CATVidCtlListViewItem : public CATVidCtlBaseViewItem
{
  CATDeclareClass;

public:
  /** Default constructor */
  CATVidCtlListViewItem (CATVidCtlAbstractItemsView & i_view);
  /** Destructor */
  virtual ~CATVidCtlListViewItem ();

private:
  // Copy constructor and assignement operator are disabled
  CATVidCtlListViewItem (CATVidCtlListViewItem &);
  CATVidCtlListViewItem& operator=(CATVidCtlListViewItem&);

};

#endif
