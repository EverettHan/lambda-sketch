#ifndef CATVidDnDDataEventArgs_H
#define CATVidDnDDataEventArgs_H

#include "VisuDialog.h"
#include "CATSYPEventArgs.h"
#include "CATBoolean.h"
#include "CATVidDnD.h"
#include "CATMathPoint2Df.h"
#include "CATBaseUnknown_WR.h"

class CATVidData;
class CATVidDnDEventArgs;

//-----------------------------------------------------------------------------
/** @ingroup groupVidDnD
 *
 * Dispatching events of @ref CATVidCtl#CanImportData and 
 * @ref CATVidCtl#ImportData on drop sources.
 */
class ExportedByVisuDialog CATVidDnDDataEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Constructor.
   *
   * @param i_pEvent the event dispatched. Cannot be @c NULL.
   * @param i_pData the data exported for drag-and-drop. Cannot be @c NULL. 
   * Only a weak reference is kept.
   * @param i_pCurrentGP the GP currently under the mouse pointer. Cannot be
   * @c NULL. @c AddRef will be called.
   * @param i_currentPos the current position of the mouse.
   * @param i_requestedEffect the drag-and-drop effect to apply depending
   * on available effects on source and current keyboard modifiers.
   */
  CATVidDnDDataEventArgs(CATSYPEvent * i_pEvent, 
    CATVidData * i_pData, 
    CATVidGP * i_pCurrentGP, 
    const CATMathPoint2Df& i_currentPos, 
    CATVidDnD::Effect i_appliedEffect);
  /** 
   * Destroy this class. 
   */
  virtual ~CATVidDnDDataEventArgs();
  /**
   * @param i_bFeedback @c TRUE if the exported data can be dropped at this 
   * position, @c FALSE else. Must be set by the handler of 
   * @ref CATVidCtl#CanImportData.
   *
   * @see CATVidCtl#CanImportData
   */
  void SetFeedback(const CATBoolean& i_bFeedback);
  /**
   * @return @c TRUE if the data exported can be dropped at this position, 
   * @c FALSE else. Used by the drag-and-drop infrastructure to determine
   * whether @ref CATVidCtl#ImportData must be emitted by the drop target or 
   * not.
   *
   * @see CATVidCtl#CanImportData
   * @see CATVidCtl#CanImport
   */
  CATBoolean GetFeedback() const;
  /** 
   * @return the GP currently under the mouse pointer. 
   */
  CATVidGP * GetCurrentGP() const;
  /**
   * @return the current position of the mouse pointer.
   */
  CATMathPoint2Df GetCurrentPos() const;
  /**
   * @return the drop effect to apply depending on available effects on source 
   * and current keyboard modifiers.
   *
   * @see CATVidDnD#Effects
   */
  CATVidDnD::Effect GetAppliedEffect() const;
  /**
   * @return the data exported for drag-and-drop.
   */
  CATVidData * GetSourceData() const;

private:
  /** Copy constructor. */
  CATVidDnDDataEventArgs (CATVidDnDDataEventArgs &);
  /** Equal operator. */
  CATVidDnDDataEventArgs& operator=(CATVidDnDDataEventArgs&);

private:
  /** @see #GetSourceData */
  CATVidData * _pSourceData;
  /** @see #GetCurrentGP */
  CATBaseUnknown_WR _wrCurrentGP;
  /** @see #GetCurrentPos */
  CATMathPoint2Df _currentPos;
  /** @see #GetRequestedEffect */
  CATVidDnD::Effect _appliedEffect;
  /** @see #GetFeedback */
  CATBoolean _feedback;
};

//------------------------------------------------------------------------------

#endif
