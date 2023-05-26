// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATVidCursor.h
// Header definition of selection cursor for resizing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jun 2005  Creation: Code generated by the CAA wizard  azi
//===================================================================
#ifndef CATVidCursor_H
#define CATVidCursor_H

#include <CATDialog.h>
#include <CATSYPDeclareEnumFactory.h>
#include <CATVid.h>
class CATVidWidget;

/**
* This class is a singleton, used for cursor management in CID
* It creates vid cursors from ascii or images, and then is called by widgets to change the cursor of the mouse.
* It calls CATDialog::UseCursor, not CATDialog::SetCursor ; a side effect of CATDialog is that user-defined cursors
* override change of cursors made by SetCursor (for example called by Visualization). Hence, it's a way for vid to be
* responsible for cursor management when the mouse is on top of cid dialog/widgets
*/
class CATVidCursor
{
friend class CATVidWidget;
friend class l_CATVidWidget;

public:
  CATVidCursor();
  ~CATVidCursor();
  
  /**
  * @deprecated
  * use CATVid::MouseCursorShape instead
  */
  enum CATVidCursorStyle {VidNorthWestArrow=1, VidNorthSouthArrow, VidEastWestArrow, VidNorthEastSouthWestArrow, VidNorthWestSouthEstArrow, VidFourArrows, VidEditCursor, VidRotateCursor, VidNorthHand};
  
private:
  /**
  * Change the cursor of the mouse for the given dialog
  * This function calls CATDialog::UseCursor (user-defined cursor, in the sense of CATDialog).
  * This cursor will be the current cursor until another has been set with UseCursor (or by this function),
  * or reseted by ResetCursor.
  * Note that in the case of vid, the i_pDialog given as parameter is often retrieved on the CATVidFraBindToViewer on top of the widget hierarchy.
  * This is a private function, call CATVidWidget::SetCursor instead.
  * @see l_CATDialog::UseCursor
  * @see l_CATDialog::SetCursor
  * @see l_CATDialog::update
  * @see l_CATDialog::OnSetCursor
  */
  void SetCursor(CATDialog* i_pDialog, CATVid::MouseCursorShape i_cursorShape);
  /**
  * Creates vid cursors from ascii or images.
  * This function is called once, by the constructor of CATVidWidget (i.e. the first we construct a widget
  */
  void DefineVidCursors();
  /**
  * @deprecated
  * use the other SetCursor instead
  */
  void SetCursor(CATDialog* i_pDialog, CATVidCursor::CATVidCursorStyle i_style);

private:
  CATDialog::CATDlgHCursor        _vidFourArrows;
  CATDialog::CATDlgHCursor        _vidNorthWestArrow;
  CATDialog::CATDlgHCursor        _vidNorthSouthArrow;  
  CATDialog::CATDlgHCursor        _vidEastWestArrow;  
  CATDialog::CATDlgHCursor        _vidNorthEastSouthWestArrow;  
  CATDialog::CATDlgHCursor        _vidNorthWestSouthEstArrow; 
  CATDialog::CATDlgHCursor        _vidEditCursor;
  CATDialog::CATDlgHCursor        _vidNorthHandCursor;
  CATDialog::CATDlgHCursor        _vidRotateCursor;
  CATDialog::CATDlgHCursor        _vidPinnedCursor;
  CATDialog::CATDlgHCursor        _vidUnpinnedCursor;
  CATDialog::CATDlgHCursor        _vidColResizeCursor;
  CATDialog::CATDlgHCursor        _vidRowResizeCursor;
  CATDialog::CATDlgHCursor        _vidCrosshairCursor;
  CATDialog::CATDlgHCursor        _vidOpenedHandCursor;
  CATDialog::CATDlgHCursor        _vidClosedHandCursor;
  CATDialog::CATDlgHCursor        _vidNoDropCursor;
  CATDialog::CATDlgHCursor        _vidNotAllowedCursor;
  CATDialog::CATDlgHCursor        _vidAliasCursor;
  CATDialog::CATDlgHCursor        _vidCellCursor;
  CATDialog::CATDlgHCursor        _vidDragCopyCursor;
  CATDialog::CATDlgHCursor        _vidDragLinkCursor;
  CATDialog::CATDlgHCursor        _vidDragMoveCursor;
  CATDialog::CATDlgHCursor        _vidDragNoneCursor;
  CATDialog::CATDlgHCursor        _vidHelpCursor;
  CATDialog::CATDlgHCursor        _vidNoneCursor;
  CATDialog::CATDlgHCursor        _vidProgressCursor;
  CATDialog::CATDlgHCursor        _vidVerticalEditCursor;
  CATDialog::CATDlgHCursor        _vidWaitCursor;
  // CATDialog::CATDlgHCursor        _vidZoomInCursor;
  // CATDialog::CATDlgHCursor        _vidZoomOutCursor;
};

#endif
