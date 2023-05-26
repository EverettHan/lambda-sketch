#ifndef CATVidDnDEventArgs_H
#define CATVidDnDEventArgs_H

#include "VisuDialog.h"
#include "CATVidMouseEventArgs.h"
#include "CATVidDnD.h"

//-----------------------------------------------------------------------------
/** @ingroup VIDGP
 * Dispatching arguments for mouse events of @ref CATVidGP during 
 * drag-and-drop.
 *
 * @see CATVidGP#BeginPreDrop 
 * @see CATVidGP#EndPreDrop 
 * @see CATVidGP#PreDrop 
 * @see CATVidGP#Drop
 */
class ExportedByVisuDialog CATVidDnDEventArgs: public CATVidMouseEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the event dispatched. Cannot be @c NULL.
   * @param i_timestamp the timestamp in milli-seconds of the
   * interaction represented by the dispatch of the event.
   * @param i_pViewer the viewer in which the event occured. Can't be
   * @c NULL.
   * @param i_positionInViewer the position of the mouse in the viewer.
   * @param i_modifiers keyboard modifiers bitfield.
   * @param i_sourceEffects bit field representing the DnD effects available 
   * for the control being dragged 
   *
   * @see CATVidMouseEventArgs
   */
  CATVidDnDEventArgs(CATSYPEvent *i_pEvent,
                     CATULONG32 i_timestamp,
                     CATVizViewer *i_pViewer,
                     const CATMathPoint2Df &i_positionInViewer,
                     Modifiers i_modifiers,
                     unsigned int i_touchFlag,
                     unsigned int i_stylusFlag,
                     unsigned int i_winTabFlag,
                     CATVidDnD::Effects i_sourceEffects);
  /**deprecated*/
  CATVidDnDEventArgs(CATSYPEvent *i_pEvent,
                     CATULONG32 i_timestamp,
                     CATVizViewer *i_pViewer,
                     const CATMathPoint2Df &i_positionInViewer,
                     Modifiers i_modifiers,
                     CATVidDnD::Effects i_sourceEffects);
  /** Destroy this class. */
  virtual ~CATVidDnDEventArgs();
  /** 
   * @return a bit field representing the DnD effects available 
   * for the control being dragged.
   *
   * @see CATVidDnD#Effects
   */
  CATVidDnD::Effects GetSourceEffects() const;
  /**
   * @return the effect that corresponds to the current mouse modifiers.
   *
   * @see CATVidDnD#Effects
   */
  CATVidDnD::Effect GetRequestedEffect() const;
  /**
   * @return applied effect calculated from available source effects and 
   * current requested effect.
   *
   * @see CATVidDnD#ComputeAppliedEffect
   */
  CATVidDnD::Effect GetAppliedEffect() const;
  /**
   * @return the data exported for drag-and-drop.
   */
  CATVidData *GetSourceData() const;

private:
  /** Copy constructor. */
  CATVidDnDEventArgs (CATVidDnDEventArgs &);
  /** Equal operator. */
  CATVidDnDEventArgs& operator=(CATVidDnDEventArgs&);

private:
  /** @see #GetSourceEffects */
  const CATVidDnD::Effects _sourceEffects;
  /** @see #GetSourceData */
  CATVidData * _pSourceData;
};

//------------------------------------------------------------------------------

#endif
