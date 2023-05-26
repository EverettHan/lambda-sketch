//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVRepDataType_H
#define IVRepDataType_H

#include "IVInterfaces.h"
#include "IVDeviceAtomicType.h"
#include "IVISUIInteractionContext.h"
class CATVizViewer;

/**
 * Device status
 */
enum ExportedByIVInterfaces IVRepAttachMode {
  IV_FREE_REP = 0,
  IV_ATTACH_LEFT_HAND,
  IV_ATTACH_RIGHT_HAND,
  IV_ATTACH_HEAD,
  IV_ATTACH_INTERACTION_CONTEXT
};

struct ExportedByIVInterfaces IVRepAttachModeData {
  IVRepAttachModeData(bool iActivated = false, IVRepAttachMode iAttachMode = IV_FREE_REP, IVISUIInteractionContext_var ihIC = NULL_var) :
    activated(iActivated),
    attachMode(iAttachMode),
    hIC(ihIC) {}

  bool activated;
  IVRepAttachMode attachMode;
  IVISUIInteractionContext_var hIC;
  bool operator==(IVRepAttachModeData const& iRepAttachModeData) const {
    return activated == iRepAttachModeData.activated && attachMode == iRepAttachModeData.attachMode && hIC == iRepAttachModeData.hIC;
  }
};

struct ExportedByIVInterfaces IVRepViewModeData {
  IVRepViewModeData(bool iActivated = false, int iViewMode = -1, CATVizViewer* ipVizViewer = NULL) :
    activated(iActivated),
    viewMode(iViewMode),
    pVizViewer(ipVizViewer) {}

  bool activated;
  int viewMode;
  CATVizViewer* pVizViewer;
  bool operator==(IVRepViewModeData const& iRepViewModeData) const {
    return activated == iRepViewModeData.activated && viewMode == iRepViewModeData.viewMode && pVizViewer == iRepViewModeData.pVizViewer;
  }
};

//};
struct ExportedByIVInterfaces IVRepProperties {

  IVRepProperties(IVRepAttachModeData iAttachModeData = IVRepAttachModeData(),
    IVRepViewModeData iViewModeData = IVRepViewModeData(),
    bool iUncutActivation = false,
    bool iUseBoundingBox = true) :
    attachModeData(iAttachModeData),
    viewModeData(iViewModeData),
    uncutActivation(iUncutActivation),
    useBoundingBox(iUseBoundingBox) {}


  IVRepAttachModeData attachModeData;
  IVRepViewModeData viewModeData;
  bool uncutActivation;
  bool useBoundingBox;

  bool operator==(IVRepProperties const& iRepProperties) const {
    return attachModeData == iRepProperties.attachModeData && viewModeData == iRepProperties.viewModeData && uncutActivation == iRepProperties.uncutActivation && useBoundingBox == iRepProperties.useBoundingBox;
  }
};

#endif
