//===================================================================
// COPYRIGHT Dassault Systemes 2016-02-08
//===================================================================
// 2016-02-08 Creation: D6K
//===================================================================

#ifndef CATVidZoomEventArgs_H
#define CATVidZoomEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
// UIVCoreTools
#include <CATSYPEventArgs.h>

class CATSYPEvent;

/**
 * Dispatching arguments for zoom change events.
 * Initial value is 0.0 for a 100% zoom factor.
 */
class ExportedByVisuDialog CATVidZoomEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidZoomEventArgs(CATSYPEvent*, const double);
  ~CATVidZoomEventArgs();

  /**
   * Returns the new zoom level that was applied in the web view.
   * 0.0 is a 100% zoom factor.
   * Going negative means reducing that factor and going positive means increasing it.
   */
  double GetZoom() const;

private:
  CATVidZoomEventArgs();
  CATVidZoomEventArgs(const CATVidZoomEventArgs&);
  CATVidZoomEventArgs& operator=(const CATVidZoomEventArgs&);

  const double _zoom;
};

#endif
