//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/11/28
//===================================================================
// CATVidCtlBasicList.h
// Header definition of class CATVidCtlBasicList
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/11/28 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATVidCtlBasicList_H
#define CATVidCtlBasicList_H

#include "VisuDialog.h"
#include "CATVidCtlListView.h"
#include "CATMathPoint2Df.h"
#include "CATBaseUnknown_WR.h"

class CATUnicodeString;
class CATPixelImage;
template <class T> class CATSYPArray;
class CATVidCtlBasicListItem;
class CATVidDroppedEventArgs;
class CATVidDraggedEventArgs;
class CATVidDnDDataEventArgs;
class CATVidDnDEventArgs;
class CATVidGP;
class CATVidCtlBaseViewItem;

/**
 * CATVidCtlBasicList is the most simple list view you can use. Basically,
 * it displays several lines of text with an optional icons associated.
 *
 * To interact with this control, you just have to insert some data by
 * calling the Append member function. This member function allows you
 * to add either a single text line or a text line associated to an icon.
 *
 */
class ExportedByVisuDialog CATVidCtlBasicList : public CATVidCtlListView
{
  CATDeclareClass;
public:
  /** Default constructor */
  CATVidCtlBasicList ();
  /** Destructor */
  virtual ~CATVidCtlBasicList ();

  /**
   * Constructs a CATVidCtlBasicList with standard style.
   */
  static CATVidCtlBasicList * CreateBasicList();

  /**
   * Append a line of text with an icon.
   *
   * @param i_textLine the line to append to the list view. Can't be an empty string.
   *
   * @param i_icon the icon to display in the line. Default value is NULL (no icon is
   * displayed).
   */
  void AppendItem(const CATUnicodeString & i_textLine, CATPixelImage * i_pIcon = NULL);

  /**
   * Append a basic list view item to the list.
   *
   * @param i_pItem the basic list view item to append to the list.
   */
  void AppendItem(CATVidCtlBasicListItem * i_pItem);

  /**
   * Append several lines of text.
   *
   * @param i_textLines the text lines to append
   */
  void AppendItems(const CATSYPDynArray<CATUnicodeString> & i_textItems);

  /**
   * Insert an item at the given position.
   *
   * @param i_row the row number in which the item must be inserted. This row
   * number must be less than or equal to the number of stored items (@see GetSize).
   *
   * @param i_pItem the item to insert at the given position. Can't be a NULL
   * pointer.
   */
  void InsertItem(int i_row, CATVidCtlBasicListItem * i_pItem);

  /**
   * Insert an item at the given position.
   *
   * @param i_row the row number in which the item must be inserted. This row
   * number must be less than or equal to the number of stored items (@see GetSize).
   *
   * @param i_text the text displayed by the inserted item.
   */
  void InsertItem(int i_row, const CATUnicodeString & i_text, CATPixelImage * i_pIcon = NULL);

  /**
   * Insert an item at the given position.
   *
   * @param i_row the row number used as the beginning point to insert text items.
   * This row number must be less than or equal to the number of stored items
   * (@see GetSize).
   *
   * @param i_textLines the text lines to insert inside the basic list view.
   */
  void InsertItem(int i_row, CATSYPDynArray<CATUnicodeString> & i_textLines);

  /**
   * Get the item located at the given row number.
   *
   * @param i_row the row number used to look for the item.
   *
   * @returns a pointer on the item located at the given row number. AddRef has
   * been called on the returned pointer, so the caller is responsible to call
   * release on it.
   */
  CATVidCtlBasicListItem * GetItem(int i_row) const;

  /**
   * Remove the item located at the given row.
   *
   * @param i_row the row number used to delete
   * the associated item.
   */
  void RemoveItem(int i_row);
  
  /**
   * Get the number of stored items.
   *
   * @returns the number of stored items
   */
  int GetSize() const;

  /**
   * Get the dimension of the displayed icons.
   * All the icons must have the same size.
   *
   * @returns the dimension of the displayed icons.
   */
  const CATMathPoint2Df & GetIconSize() const;

  /**
   * Set the dimension of the displayed icons.
   *
   * @param the dimension of the displayed icon.
   */
  void SetIconSize(const CATMathPoint2Df & i_iconSize);

  /**
   * Set the item located at the i_row position to become the
   * new current item. This new current item becomes visible.
   *
   * @param i_row the position of the new current item.
   */
  void SetCurrentItem(int i_row);

private:
  // Copy constructor and assignement operator are disabled
  CATVidCtlBasicList (CATVidCtlBasicList &);
  CATVidCtlBasicList& operator=(CATVidCtlBasicList&);

  /**
   * Create a basic list view item and return it.
   *
   * @param i_text the text value to associate to this item.
   *
   * @param i_pIcon the image to use as the icon for this item. A NULL
   * pointer can be given if no icon is needed.
   *
   * @returns the created basic list view item if succeeded, otherwise
   * a NULL pointer.
   */
  CATVidCtlBasicListItem * CreateItem(const CATUnicodeString & i_text, CATPixelImage * i_pIcon);

  /**
   * Inserts a new item into the list, built from dragged data.
   *
   * @param i_row row where to insert the item. 
   * <tt>0 <= i_row <= GetSize()</tt>. Item will be appended if
   * <tt>row == GetSize()</tt>. 
   * @param i_pData the data to use to create the new item.
   */
  void InsertItemFromData(int i_row, CATVidData * i_pData);
  
  /**
   * Fills a currently existing item with dragged data.
   *
   * @param i_row row where to insert the item. 
   * <tt>0 <= i_row <= GetSize() - 1</tt>.
   * @param i_pData the data to use to modify existing item.
   */
  void FillItemWithData(int i_row, CATVidData * i_pData);

  CATMathPoint2Df _iconSize;
};

#endif