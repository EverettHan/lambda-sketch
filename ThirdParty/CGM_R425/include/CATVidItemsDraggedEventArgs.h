#ifndef CATVidItemsDraggedEventArgs_H
#define CATVidItemsDraggedEventArgs_H

#include "VisuDialog.h"
#include "CATVidDraggedEventArgs.h"
#include "CATVidMdlIndex.h"
#include "CATSYPArray.h"
class CATVidDnDData;

//-----------------------------------------------------------------------------

/** @ingroup groupVIDDnD
 * 
 * Dispatching arguments of @ref CATVidCtl#ItemsDragged on model/view drag 
 * sources.
 * 
 * The data dragged is positionned beforce the dispatch with all necessary
 * information for model/view.
 */
class ExportedByVisuDialog CATVidItemsDraggedEventArgs: public CATVidDraggedEventArgs
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
   * @param i_pSourceData the model data dragged. Cannot be @c NULL. Will be
   * @c AddRef-ed.
   * @param i_elements the elements currently dragged.
   */
  CATVidItemsDraggedEventArgs(CATSYPEvent *i_pEvent, 
    CATVidGP * i_pCurrentGP, 
    CATVidGP * i_pPressGP, 
    const CATMathPoint2Df& i_currentPos, 
    const CATMathPoint2Df& i_pressPos,
    CATVidDnD::Effect i_requestedEffect,
    CATVidDnDData * i_pSourceData,
    CATSYPDynArray<CATBaseUnknown_var> i_elements);
  /** 
   * Destroy this class. 
   */
  virtual ~CATVidItemsDraggedEventArgs();
  /** 
   * @return the number of items that have been dropped. 
   */
  int GetElementsNb() const;
  /**
   * @param i_i must be in <tt>[0, this->GetElementsNb() - 1]</tt>
   *
   * @return the element of the i-th item dropped.  
   *
   * @see #GetDraggedItemsNb
   * @see CATVidMdlIndex#GetElement
   */
  CATBaseUnknown_var GetElement(int i_i) const;
  /** 
   * @return the data currently being dragged. Can be enriched with custom
   * information.
   */
  CATVidDnDData * GetData();

private:
  /** Copy constructor. */
  CATVidItemsDraggedEventArgs (CATVidItemsDraggedEventArgs &);
  /** Equal operator. */
  CATVidItemsDraggedEventArgs& operator=(CATVidItemsDraggedEventArgs&);

private:
  /** @see #GetElement */
  CATSYPDynArray<CATBaseUnknown_var> _Elements;
  /** @see #GetData */
  CATVidDnDData * _pData;
};

//------------------------------------------------------------------------------

#endif
