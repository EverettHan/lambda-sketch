#ifndef CATVidDroppedEventArgs_H
#define CATVidDroppedEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
#include "CATVid.h"
#include "CATVidDnD.h"
#include "CATBaseUnknown_WR.h"
#include "CATMathPoint2Df.h"
class CATSYPEvent;
class CATVidGP;
class CATVidData;

//-----------------------------------------------------------------------------
/**
 * @ingroup groupVIDDnD
 * 
 * Dispatching events of @ref CATVidCtl#Dropped on drag sources.
 * 
 * @see CATVidCtl#Dropped
 */
class ExportedByVisuDialog CATVidDroppedEventArgs: public CATSYPEventArgs
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
   */
  CATVidDroppedEventArgs(CATSYPEvent * i_pEvent, 
    CATVidData * i_pData,
    CATVidGP * i_pPressGP, 
    const CATMathPoint2Df & i_pressPos, 
    CATBoolean i_success,
    CATVidDnD::Effect i_effect);
  /** Destroys this class. */
  virtual ~CATVidDroppedEventArgs();
  /**
   * @return the data exported for drag-and-drop.
   */
  CATVidData * GetSourceData() const;
  /** 
   * @return @c TRUE if the drop succeeded, @c FALSE if th edrag has been
   * canceled. 
   */
  CATBoolean GetSuccess() const;
  /** 
   * @return the drag and drop effect that corresponds to effect applied on 
   * drop.
   *
   * @see CATVidDnD#Effect
   */
  CATVidDnD::Effect GetAppliedEffect() const;
  /** 
   * @return the last GP to have been pressed. @c NULL if the GP has been 
   * destroyed. 
   */
  CATVidGP * GetPressGP() const;
  /** @return the position of the last press. */
  CATMathPoint2Df GetPressPos() const;

private:
  /** Copy constructor. */
  CATVidDroppedEventArgs (CATVidDroppedEventArgs &);
  /** Assignment operator. */
  CATVidDroppedEventArgs& operator=(CATVidDroppedEventArgs&);

  /** @see #GetEffect */
  const CATVidDnD::Effect _appliedEffect;
  /** @see #GetPressGP */
  CATBaseUnknown_WR _wrPressGP;
  /** @see #GetPressPos */
  const CATMathPoint2Df _pressPos;
  /** @see #GetSourceData */
  CATVidData * _pSourceData;
  /** @see #GetSuccess */
  CATBoolean _success;
};

//-----------------------------------------------------------------------

#endif
