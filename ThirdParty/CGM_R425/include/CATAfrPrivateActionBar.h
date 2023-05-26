#ifndef CATAfrPrivateActionBar__H
#define CATAfrPrivateActionBar__H

#include "CATAfrFoundation.h"

class CATISYPIntrospectable_var;

/**
 * Private services for ActionBar (mainly used by CID Frame)
 */
class ExportedByCATAfrFoundation CATAfrPrivateActionBar
{
private:
  /**
   * Get the ActionBar root view element.
   *
   * @return the ActionBar root view element.
   */
  static CATISYPIntrospectable_var GetActionBarView();

  friend class AfrWindowManagerVIDMDI;
  friend class CATAfrActionBarViewerManager;
  friend class AfrActionBarViewerManager;
};

#endif
