#ifndef CATVidMdlDnDDataEventArgs_H
#define CATVidMdlDnDDataEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
#include "CATVidDnD.h"
#include "CATVidMdlIndex.h"
class CATVidData;


/** @ingroup VIDGP
 * Base class for dispatching arguments of input events.
 *
 * It offers a common way to know when the event was emitted.
 */
class ExportedByVisuDialog CATVidMdlDnDDataEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the event dispatched.
   * @param i_pData the data dragged, if any. 
   * @param i_effect the applied drag-and-drop effect.
   * @param i_targetIndex the index of the item in which the drag would happen 
   * on release or just happened.
   * @param i_location the location in which the drag would happen on release 
   * or just happened, inside the view of the current target index.
   */
  CATVidMdlDnDDataEventArgs(CATSYPEvent * i_pEvent, CATVidData * i_pData, 
    CATVidDnD::Effect i_effect, const CATVidMdlIndex & i_targetIndex, 
    const CATVidDnD::DropLocation & i_location);
  /** Destroy this class */
  virtual ~CATVidMdlDnDDataEventArgs();
  /**
   * @param i_feedback @c TRUE if the exported data can be dropped at this 
   * position, @c FALSE else. Must be set by the handler of 
   * @ref CATVidMdlAdapter#CanImportItems.
   *
   * @see CATVidMdlAdapter#CanImportItems
   */
  void SetFeedback(const CATBoolean& i_feedback);
  /**
   * @return @c TRUE if the data exported can be dropped at this position, 
   * @c FALSE else. Used by the drag-and-drop infrastructure to determine
   * whether @ref CATVidMdlAdapter#ImportItems must be emitted by the drop 
   * target or not.
   *
   * @see CATVidMdlAdapter#CanImportItems
   * @see CATVidMdlAdapter#ImportItems
   */
  CATBoolean GetFeedback() const;
  /**
   * If the default drag-and-drop is used, the data will be of type
   * @ref CATVidMdlDnDData.
   * 
   * @return the data exported for drag-and-drop. 
   */
  CATVidData * GetSourceData() const;
  /**
   * @return the drop effect to apply depending on available effects on source 
   * and current keyboard modifiers.
   *
   * @see CATVidDnD#Effects
   */
  CATVidDnD::Effect GetAppliedEffect() const;
  /** 
   * @return the index of the item in which the drag would happen on mouse 
   * release, or just happened. 
   */
  const CATVidMdlIndex & GetTargetIndex() const;
  /** 
   * @return the location in which the drag would happen inside the view of the 
   * current target index, or just happened. 
   */
  CATVidDnD::DropLocation GetDropLocation() const;
  /** 
   * @param i_preDropFeedback @c TRUE if preDrop feedback on list/tree must be visible, @c FALSE else.
   * @ref CATVidMdlAdapter#CanImportItems.
   */
  void SetDisplayPreDropFeedback(const CATBoolean &  i_preDropFeedback);
  /** 
   * @return TRUE if preDrop feddback have to be displayed, FALSE otherwise.
   */
  CATBoolean GetDisplayPreDropFeedback() const;

private:
  CATVidMdlDnDDataEventArgs(const CATVidMdlDnDDataEventArgs &);
  CATVidMdlDnDDataEventArgs &operator=(const CATVidMdlDnDDataEventArgs &);
private:
  /** @see #GetFeedback */
  int _feedback;
  /** @see #GetSourceData */
  CATVidData * _pSourceData;
  /** @see #GetAppliedEffect */
  CATVidDnD::Effect _effect;
  /** @see #GetTargetIndex */
  CATVidMdlIndex _index;
  /** @see #GetDropLocation */
  CATVidDnD::DropLocation _dropLocation;

  CATBoolean _displayPreDropFeedback;
};

#endif // CATVidMdlDnDDataEventArgs_H
