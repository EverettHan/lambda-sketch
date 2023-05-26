#ifndef CATVidDraggedEventArgs_H
#define CATVidDraggedEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
#include "CATMathPoint2Df.h"
#include "CATVidDnD.h"
#include "CATBaseUnknown_WR.h"
class CATVidDnDData;

//-----------------------------------------------------------------------------

/** @ingroup groupVIDDnD
 * 
 * Dispatching arguments of @ref CATVidCtl#Dragged on drag sources.
 */
class ExportedByVisuDialog CATVidDraggedEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Build this class.
   *
   * @param i_pEvent the event dispatched. Cannot be @c NULL. Only a weak
   * reference is kept.
   * @param i_pCurrentGP GP currently under the mouse cursor. Cannot be 
   * @c NULL. Only a weak reference is kept.
   * @param i_pPressGP last GP pressed. Cannot be @c NULL. Only a weak 
   * reference is kept.
   * @param i_currentPos current mouse position.
   * @param i_pressPos position of the last press.
   * @param i_requestedEffect the drag-and-drop effect that corresponds to the
   * current keyboard modifier.
   */
  CATVidDraggedEventArgs(CATSYPEvent *i_pEvent, 
    CATVidGP * i_pCurrentGP, 
    CATVidGP * i_pPressGP, 
    const CATMathPoint2Df& i_currentPos, 
    const CATMathPoint2Df& i_pressPos,
    CATVidDnD::Effect i_requestedEffect);
  /** 
   * Destroy this class. 
   */
  virtual ~CATVidDraggedEventArgs();
  /**
   * @param i_pSourceData the data to export for drag-and-drop. To be filled-in
   * by the receiver of the @ref CATVidCtl#Dragged event. Will be @c AddRefed.
   *
   * @see CATVidCtl#Dragged
   */
  void SetSourceData(CATVidDnDData * i_pSourceData);
  /**
   * @return the data to export for drag-and-drop. 
   */
  CATVidDnDData * GetSourceData() const;  
  /**
   * @return the GP currently under the mouse cursor, that sent the original
   * @ref CATVidGP#Drag event to the drag-and-drop infrastructure. Cannot be
   * @c NULL. 
   */
  CATVidGP * GetCurrentGP() const;
  /**
   * @return the current position of the mouse.
   */
  CATMathPoint2Df GetCurrentPos() const;
  /**
   * @return the last GP pressed (before CATVidGP#Drag events, thus 
   * CATVidCtl#Dragged event, are emitted). Cannot be @c NULL. 
   */
  CATVidGP * GetPressGP() const;
  /**
   * @return the position of the last press.
   */
  CATMathPoint2Df GetPressPos() const;
  /**
   * @return the drag-and-drop effect currently requested (depends on the 
   * keyboard modifiers).
   *
   * @see CATVidDnD#Effect
   */
  CATVidDnD::Effect GetRequestedEffect();

private:
  /** Copy constructor. */
  CATVidDraggedEventArgs (CATVidDraggedEventArgs &);
  /** Equal operator. */
  CATVidDraggedEventArgs& operator=(CATVidDraggedEventArgs&);

private:
  /** @see #GetSourceData */
  CATVidDnDData * _pSourceData;
  /** @see #GetPressGP */
  CATBaseUnknown_WR _wrPressGP;
  /** @see #GetCurrentGP */
  CATBaseUnknown_WR _wrCurrentGP;
  /** @see #GetCurrentPos */
  const CATMathPoint2Df _currentPos;
  /** @see #GetPressPos */
  const CATMathPoint2Df _pressPos;
  /** @see #GetRequestedEffect */
  const CATVidDnD::Effect _requestedEffect;
};

//------------------------------------------------------------------------------

#endif
