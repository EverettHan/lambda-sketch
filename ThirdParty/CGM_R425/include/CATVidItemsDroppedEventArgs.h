#ifndef CATVidItemsDroppedEventArgs_H
#define CATVidItemsDroppedEventArgs_H

#include "VisuDialog.h"
#include "CATVidDroppedEventArgs.h"
#include "CATVidMdlIndex.h"
#include "CATSYPArray.h"

//-----------------------------------------------------------------------------
/**
 * @ingroup groupVIDDnD
 * 
 * Dispatching events of @ref CATVidCtl#Dropped on model/view drag sources.
 * 
 * @see CATVidCtl#Dropped
 * @see CATVidCtlAbstractItemsView#ItemsDropped
 */
class ExportedByVisuDialog CATVidItemsDroppedEventArgs: public CATVidDroppedEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initializes this class.
   *
   * @param i_pEvent the dispatched event. Cannot be @c NULL.
   * @param i_pData the data dropped. @c AddRef will be called. Cannot be 
   * @c NULL.
   * @param i_pPressGP the last GP to have been pressed. May be @c NULL.
   * Only a weak reference is kept.
   * @param i_pressPos the position of the last press.
   * @param i_success the success of the drop.
   * @param i_effect the drag-and-drop effect.
   * @param i_droppedElements the elements of the items dropped.
   * @param i_spTargetElement the element of the target item. Cannot be 
   * @c NULL_var.
   * @param i_dropLocation the location of the drop in the target item 
   * (see @ref CATVidDnD#DropLocation)
   */
  CATVidItemsDroppedEventArgs(CATSYPEvent * i_pEvent, 
    CATVidData * i_pData,
    CATVidGP * i_pPressGP, 
    const CATMathPoint2Df & i_pressPos, 
    CATBoolean i_success,
    CATVidDnD::Effect i_effect,
    CATSYPDynArray<CATBaseUnknown_var> i_droppedElements,
    CATBaseUnknown_var i_spTargetElement,
    CATVidDnD::DropLocation i_dropLocation);

  /** Destroys this class. */
  virtual ~CATVidItemsDroppedEventArgs();

  /**
   * @return the element of the item on which the drop happened.
   *
   * @see CATVidMdlIndex#GetElement
   */
  CATBaseUnknown_var GetTargetElement() const;
  /** 
   * @return the location of the mouse over the target item at the time of
   * the drop (see @ref CATVidDnD#DropLocation).
   */
  CATVidDnD::DropLocation GetDropLocation() const;
  /** 
   * @return the number of items that have been dropped. 
   */
  int GetElementsNb() const;
  /**
   * @param i_i must be in <tt>[0, this->GetDroppedElementsNb() - 1]</tt>
   *
   * @return the element of the i-th item dropped.  
   *
   * @see #GetDroppedItemsNb
   * @see CATVidMdlIndex#GetElement
   */
  CATBaseUnknown_var GetElement(int i_i) const;

private:
  /** Copy constructor. */
  CATVidItemsDroppedEventArgs (CATVidItemsDroppedEventArgs &);
  /** Assignment operator. */
  CATVidItemsDroppedEventArgs& operator=(CATVidItemsDroppedEventArgs&);

  /** @see #GetDroppedElement */
  CATSYPDynArray<CATBaseUnknown_var> _Elements;
  /** @see #GetTargetElement */
  CATBaseUnknown_var _spTargetElement;
  /** @see #GetDropLocation */
  CATVidDnD::DropLocation _dropLocation;
};

//-----------------------------------------------------------------------

#endif
