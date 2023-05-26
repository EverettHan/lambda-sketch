#ifndef CATTechVizEngine_H
#define CATTechVizEngine_H

#include "CATBaseUnknown.h"
#include "CATProjectionType.h"
#include "CATVisFoundation.h"
class CATSupport;
class CATTechVizInstance;
class CATViewpoint;
class CATVizViewer;


//=============================================================================
/**
 * class CATTechVizDisplaySettings
 */
struct CATTechVizDisplaySettings
{
  CATProjectionType PROJECTION_TYPE;
  int               ANTIALIASING_MODE;
  unsigned int      ADVANCED_HIGHLIGHT;
};


//=============================================================================
/**
 * class CATTechVizEngine
 *
 * This component:
 * - implements the management of the TechViz cluster (start/stop/checks)
 *
 * - provides entry points for other visualizations components in order to
 *   notify key events that must be handled specifically by the TechViz
 *   manager
 *
 * You shouldnt use it direcly, use instead CATTechVizServices
 * @see CATTechVizServices
 */
class ExportedByCATVisFoundation CATTechVizEngine
{
public:

// :WARNING: Those services should be called only from the main thread
//

  /**
   * Check whether the TechViz engine is available.
   *
   * The TechViz availability depends on a proper installation of TechViz
   * configured for use with this program.
   *
   * Note: licensing are not taken into account.
   *
   * Implementation notes: once called for the first time, the TechViz engine
   * availability is never computed again until the program is relaunched (as
   * there shouldnt be any need to do so).
   *
   * @return
   * 1 The TechViz engine is available
   * 0 Otherwise
   */
  static unsigned int CheckTechVizEngineAvailability();

  /**
   * Start the TechViz cluster on the given viewer.
   *
   * The TechViz cluster will capture only this viewer.
   * Note: there can be only one captured viewer at any time.
   *
   * Note: the display properties of the viewer are backuped and then updated
   * to better suit the cluster requirements (projection type, ambiant
   * occlusion, back face culling, LOD, pixel culling, transparency,
   * anti-aliasing)
   *
   * Preconditions: 
   * - requires a Microsoft Windows plateform.
   * - requires a valid TechViz installation properly configured for use with
   *   this program.
   * - should be called only from the main thread
   * 
   * @return 
   * S_STARTED. The TechViz cluster is started and capture the given viewer
   * E_LICENSING. The licensing requirements are not met.
   * E_ERROR. Precondtions not met or internal error
   */
  enum class StartRC { S_STARTED, E_LICENSING, E_ERROR };
  static StartRC StartTechVizCapture(CATVizViewer* iViewer);

  /**
   * Stop the TechViz capture.
   *
   * Note: the display properties of the viewer are restored to their previous
   * state (see StartTechVizCapture)
   *
   * Note: It is possible to call this method even if the TechViz cluster has
   * not been started. In this case, this is a no-op.
   *
   * Preconditions:
   * - should be called only from the main thread
   *
   * @return
   * S_OK Success. The TechViz cluster is stopped.
   * S_FALSE Success. The TechViz cluster is stopped. No viewer was being captured.
   * E_XXX Internal error or preconditions not met.
   */
  static HRESULT StopTechVizCapture();
  
  /**
   * Check whether the TechViz cluster is started.
   *
   * @return
   * 1 The TechViz cluster is started.
   * 0 The TechViz cluster is not started.
   */
  static unsigned int IsTechVizCaptureOn();

private:

  // :WARNING: note that those services are NOT thread safe: it is up to the
  // callers to check that it is ok to use them (note that to date, those
  // services are already called from different threads)
  //
  // :WARNING: it is up to the callers to ensure that the given
  // viewpoints/support/vizviewer are valid (lifecycle etc). Those services used
  // to rely indirectly on a weakref to ensure lifecycle validity, however as
  // they're not thread safe, this introduced deadlocks/coredumps etc (see
  // previous :WARNING:)
  //

  friend class CATVizViewer; // OnViewerDestruction
  friend class SGInfraToVisuFConnectToolImpl; // __IsTechVizCapturedSupport (but __IsTechVizCapturedSupport is itself never called)

  /**
   * Called by CATVizViewer::~CATVizViewer
   */
  static void OnViewerDestruction(CATVizViewer* iVizViewer);

  /**
   * Check whether the given support is captured by the TechViz engine.
   * Called by CATRender::CATRender
   */
  static unsigned int IsTechVizCapturedSupport(CATSupport& iSupport);

private:
  
  CATTechVizEngine();

  // Stop the TechViz capture. Restore/update the captured vizviewer if iAbort
  // is not 0
  static HRESULT CancelTechVizCapture(unsigned int iAbort);

  // Licensing management
  //---------------------
  static unsigned int AcquireLicenseTokens(int iNb);
  static unsigned int ReleaseLicenseTokens( int iNb);

  // Visualization management
  //-------------------------

  // Extract/valuate display settings on the captured vizviewer
  // Those services are used in order to backup/restore display settings when the capture starts/ends
  static void PushDisplaySettings(CATVizViewer& iVizViewer);
  static void PopDisplaySettings(CATVizViewer& iVizViewer);

  // The address of the captured vizviewer. Must be used in order to recognize
  // the vizviewer whereas it is being deleted. Used for address
  // comparison purposes (filtering). 
  // Sometimes, we need to dereference it and call the underlying
  // vizviewer. There nothing we can do to check that the pointer is valid
  // (e.g. use of weakref introduced deadlocks and CD as the code cannot be
  // made thread safe). It's up to the users of
  // CATTechVizInstance/CATTechVizEngine to checks that the calls are "safe".
  // see :WARNINGs: in CATTechVizEngine.h
  static CATVizViewer* s_VizViewer;

  // The display settings from the vizviewer/support when the capture is
  // started. Used to restore the initial settings when the capture ends
  static CATTechVizDisplaySettings s_DisplaySettings;

  // The number of locked tokens (licensing)
  static int s_LockedTokens;
};

#endif
