#ifndef CATVidMouseState_H
#define CATVidMouseState_H

#include <VisuDialog.h>

#include <CATBaseUnknown.h>
#include <CATMathPoint2Df.h>

class CATVizViewer;

/** @ingroup VIDCore
 * C++ interface for an object that can be used to access to the state
 * of the mouse.
 *
 * The object implementing this interface that should be used by VID
 * code to access to the mouse state is returned by @ref
 * CATVidDeviceStates#GetMouseState.
 *
 * @see CATVidDeviceStates
 */
class ExportedByVisuDialog CATVidMouseState : public CATBaseUnknown
{
  CATDeclareClass;
public:
  /** Initialize this class */
  CATVidMouseState();

  /** Destroy this class */
  virtual ~CATVidMouseState();

  /**
   * Get the mouse position relative to the given viewer.
   *
   * @note
   * The @ref CATVizViewer can be obtained from a @ref CATViewer by
   * calling @ref CATViewer#GetVizViewer.
   *
   * @note 
   * The returned value is expressed in device independent pixels; as
   * a consequence the value is different from the result of @ref
   * CATVizViewer#GetMousePosition that is expressed in pixels.
   *
   * @param i_pVizViewer the viewer. Can't be @c NULL.
   *
   * @return the mouse coordinates in the given viewer.
   */
  virtual CATMathPoint2Df GetViewerMousePosition(CATVizViewer *i_pVizViewer) = 0;
private:
  CATVidMouseState(const CATVidMouseState &);
  CATVidMouseState &operator=(const CATVidMouseState &);
};

#endif // CATVidMouseState_H
