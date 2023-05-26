//=============================================================================
// COPYRIGHT Microsoft 2012/08/28 
//=============================================================================
// CATVidDefaultTransferHandler.cpp
// Header definition of class CATVidDefaultTransferHandler
//=============================================================================
//  2012/08/28 Creation: LD5
//=============================================================================

#ifndef CATVidDefaultTransferHandler_H
#define CATVidDefaultTransferHandler_H

#include "CATVidDnDTransferHandler.h"
#include "CATVidDnDDataSupport.h"

/**
 * @deprecated Use @ref CATVidCtl drag-and-drop instead.
 *
 * This class provides a default support of drag and drop operation for all
 * CID controls (@c CATVidCtl). It is overidden for customization on some 
 * controls and can be overidden by anyone on any control.  
 *
 * @par Drag
 * This transfer handler allows its owner control to be dragged and exports all 
 * its introspectable properties in the form of a properties dictionary.
 *
 * @par Drop
 * This transfer handler disallow drop on its owner control.
 *
 * @par
 * This transfer handler implements a drag cursor that follows the mouse cursor
 * when the owner of the handler is the source of a drag. This default cursor 
 * is composed of semi-transparent image of the control being dragged.
 *
 * @see CATVidDnDTransferHandler
 */
class ExportedByVisuDialog CATVidDefaultTransferHandler: public CATVidDnDTransferHandler
{
  CATDeclareClass;
public:
  /** 
   * Constructor.
   *
   * @param i_pOwner the control whose data needs to be transfered. A weak 
   * reference is kept on the input pointer.
   */
  CATVidDefaultTransferHandler(CATVidCtl * i_pOwner);
  /** Destructor. */
  virtual ~CATVidDefaultTransferHandler();

  /** @copydoc CATVidDnDTransferHandler#InitFeedback */
  virtual void InitFeedback();
  /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
  virtual void OnGiveFeedback(DROPEFFECT i_dropEffect, int i_xPos, int i_yPos);
  /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
  virtual void DropDone(CATBoolean i_bDropSuccess);
  /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
  virtual CATBoolean CanImport();
  /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
  virtual CATBoolean ImportData();

protected:
  /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
   virtual CATVidDnDDataSupport * CreateDataSupport();
   /** @copydoc CATVidDnDTransferHandler#OnGiveFeedback */
   virtual void Cleanup();

private:
  /**
   * Creates a drag cusor when the owner control is dragged. Only works on 
   * Windows.
   *
   * @return the drag cursor (a semi-transparent image of the control) as a 
   * HWND.
   */
  void * CreateCursor();

private:
  /** 
   * Relative abscissa of the mouse cursor inside the viewer on last press
   * over the owner control. 
   */
  int _curPosX;
  /** 
   * Relative ordinate of the mouse cursor inside the viewer on last press
   * over the owner control. 
   */
  int _curPosY;
  /** 
   * Constant used when coordinates (@ref #_curPosX, @ref #_curPosY) are 
   * currently undefined. 
   */
  static const int _curPosUNDEF;
  /** HWND displaying the drag cursor during drag and drop. */
  void * _dragCursor;
  /** @c TRUE once the cursor is created. */
  CATBoolean _bCursorCreated;
};
//-----------------------------------------------------------------------------
#endif
