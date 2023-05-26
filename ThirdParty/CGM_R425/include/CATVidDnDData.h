#ifndef CATVidDnDData_H
#define CATVidDnDData_H

#include "VisuDialog.h"
#include "CATVidData.h"
#include "CATBaseUnknown_WR.h"
class CATVidCtl;
class CATPixelImage;
class CATVidWidget;

/** @ingroup groupVidDnD
 * 
 * Stores the data exported when a drag-and-drop is initialized from a CID 
 * control.
 *
 * @see CATVidCtl#Dragged
 */
class ExportedByVisuDialog CATVidDnDData: public CATVidData
{
  CATDeclareClass;

public:
  /** Default constructor. */
  CATVidDnDData();
  /** 
   * Constructor. 
   *
   * @param i_pDataBlock the data block exported for drag-and-drop. Will be
   * @c AddRefed. @c CATSYPDataBlock#BeginUpdateTransaction will be called on
   * the data block, to make it read-only. Cannot be @c NULL.
   */
  CATVidDnDData(CATSYPDataBlock * i_pDataBlock);
  // LD5 TODO
  //CATVidDnDData(CATSYPDataBlock * i_pDataBlock, void * i_pExternalData);
  //CATVidDnDData(void * i_pExternalData);
  /** Destructor. */
  virtual ~CATVidDnDData();
  /** @return the source from which the data has been extracted. */
  CATVidCtl * GetSourceCtl() const;
  /** @return image with which the drag cursor must be built. */
  CATPixelImage * GetCursorImage() const;
  /** 
   * The image to use to create a drag cursor. Typically, an picture of
   * the widget in which the dragged data is visualized; for example,
   * the dragged list item when @c i_pSourceCtl is a list.
   *
   * The drag cursor will be a semi-transparent copy of the input image.
   *
   * If @c NULL (default outside of model-view), a semi-transparent image
   * of the source control will be used instead. 
   *
   * @param i_pImg the cursor image to use. Will be @c AddRef-ed.
   */
  void SetCursorImage(CATPixelImage * i_pImg);
  /**
   * @return the offset of the cursor image to the mouse control. 
   * <tt>(0, 0)</tt> by default.
   */
  CATMathPoint2Df GetCursorOffset() const;
  /** 
   * @param i_flag set to @c 0 to disallow the use of a drag cursor during drag-and-drop.
   */
  void SetCursorFlag(int i_flag);
  /**
   * @return @c 1 (default) if a drag cursor is used during drag-and-drop; @c 0 else.
   */
  int GetCursorFlag() const { return _cursorFlag; }
  /**
   * @param i_offset the offset that the drag cursor must have to the mouse
   * cursor.
   */
  void SetCursorOffset(const CATMathPoint2Df& i_offset);
  /** 
   * Initializes the cursor offset to the offset of a widget -- typically, a
   * widget representing the drag data, which may be directly the source 
   * control or a child (eg. list item when the source control is the whole 
   * list). 
   *
   * @param i_pWidget the widget from which the offset must be calculated.
   * Cannot be @c NULL. @c AddRef will not be called.
   */
  void InitializeCursorOffset(CATVidWidget * i_pWidget);

protected:
  /**
   * @param i_pSourceCtl source of the drag. Set by the
   * @ref CATVidDnDSourceFactory, a reliable friend, before creating the
   * @ref CATVidDnDSource.
   */
  void SetSourceCtl(CATVidCtl * i_pSourceCtl);
  /**
   * Updates the position of the drag cursor. Rebuilds it in case the cursor 
   * image has been updated. Called by a friend, the @ref CATVidDnDSource.
   */
  void MoveCursor();

private:
  /** Copy constructor. */
  CATVidDnDData (CATVidDnDData &);
  /** Equal operator. */
  CATVidDnDData& operator=(CATVidDnDData&);
  /**
   * Creates a drag cusor when the owner control is dragged. Only works on 
   * Windows.
   */
  void BuildCursor();
 /**
  * Resets the drag cursor. 
  */
  void CleanCursor();

private:
  /** @see #GetSourceCtl */
  CATBaseUnknown_WR _wrSourceCtl;
  /** @see #GetCursorImage */
  CATPixelImage * _pCursorImg;
  /** @see #GetCursorImageOffset */
  CATMathPoint2Df _cursorOffset;
  /** HWND displaying the drag cursor during drag and drop. */
  void * _dragCursor;
  /** @see #SetCursorFlag */
  int _cursorFlag;

  friend class CATVidDnDSourceFactory;
  friend class CATVidMdlDnDSourceFactory;
  friend class CATVidDnDSource;
  friend class CATVidTstDnDData;
};

//-----------------------------------------------------------------------------

#endif
