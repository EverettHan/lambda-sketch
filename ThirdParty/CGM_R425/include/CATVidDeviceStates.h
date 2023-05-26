#ifndef CATVidDeviceStates_H
#define CATVidDeviceStates_H

#include <VisuDialog.h>

class CATVidMouseState;

/** @ingroup VIDCore
 * Utility class that can be used to access the state of interaction
 * devices.
 *
 * The state of interaction devices is available through objects
 * implementing a specified interface. By default the returned objects
 * use the actual interaction device.
 *
 * These default objects can be replaced by new objects for
 * tests. This enables tests to simulate interaction devices without
 * having to modify the actual state of the interaction device (for
 * example without to modify the actual mouse position).
 *
 * @note
 * As of today only the mouse is handled by this class. The keyboard
 * should also be implemented.
 */
class ExportedByVisuDialog CATVidDeviceStates
{
public:
  /**
   * Get the object to use to access to the state of the mouse.
   *
   * @par Default
   * By default the returned object will use @ref
   * CATVizViewer#GetMousePosition to implement @ref
   * CATVidMouseState#GetViewerMousePosition. As a consequence during
   * the replay of a RECORD ODT the returned position will be the one
   * restored from interactions stored in the <tt>capture.rec</tt>
   * file.
   *
   * @return the state. @c NULL in case of severe internal error. Note
   * that @c AddRef has not been called on the returned pointer so the
   * caller must not @c Release it.
   */
  static CATVidMouseState *GetMouseState();

  /**
   * Overrides the object used to access the state of the mouse.
   *
   * @par For Tests Only
   * Please only use this function in tests, never in production code.
   *
   * @param i_pMouseState the new object to use to access to the state
   * of the mouse. @c NULL to reset the overriding (in that case next
   * calls to @ref #GetMouseState will return the default object).
   */
  static void SetMouseState(CATVidMouseState *i_pMouseState);
private:
  CATVidDeviceStates();
  ~CATVidDeviceStates();
  CATVidDeviceStates(const CATVidDeviceStates &);
  CATVidDeviceStates &operator=(const CATVidDeviceStates &);
};

#endif // CATVidDeviceStates_H
