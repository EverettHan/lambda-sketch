//===================================================================
// COPYRIGHT Dassault Systemes 2020-09-08
//===================================================================

#ifndef VisViewModeServices_H
#define VisViewModeServices_H

#include "SGInfra.h"
#include "CATUnicodeString.h"
#include "CATMainwinInit.h" // HRESULT

// To avoid declaring as public this flag (in CATViewerUtility.h in PublicInterfaces)
// It is declared here with last available bit to avoid problem in the future
// 0x20000000 is taken by VIEW_WITHOUT_SMALL_CURVATURE_STEP_EDGE
#define VIEW_APPEARANCE         (0x40000000) 
#define VIEW_POLYGON_WITH_MESH  (0x10000000) 

class CATSupport;
class CATVizViewer;
class VisAppearance;
class VisMaterialApplication;
class ExportedBySGInfra VisViewModeServices
{
public:
  static void     CopyViewModeAndAppearance(CATVizViewer* iSourceViewer, CATVizViewer* iDestinationViewer);

  //-----------------------------------------
  // Appearance

  static void     ActivateAppearance    (CATVizViewer* iViewer, const VisAppearance& iAppearance);
  static void     SetAppearance         (CATVizViewer* iViewer, const VisAppearance& iAppearance);
  static void     RemoveAppearance      (CATVizViewer* iViewer);
  static HRESULT  GetAppearance         (CATVizViewer* iViewer, VisAppearance&  oAppearance);

  static VisMaterialApplication* BuildMaterialApplication(const VisAppearance&  iAppearance);

  //-----------------------------------------
  // Custom View Mode
  
  static int      ReadCustomViewModeFromSettings (const CATSupport& iSupport, const CATUnicodeString& iSuffix = "");
  static void     ApplyCustomViewMode            (CATVizViewer* iViewer); // viewmodepanel

  static void     WriteCustomViewModeToSettings  (int iViewMode, const CATSupport& iSupport, const CATUnicodeString& iSuffix = "");
  static void     WriteCustomViewModeToSettings  (int iViewMode, const VisAppearance& iAppearance, CATSupport& iSupport, const CATUnicodeString& iSuffix = ""); // viewmodepanel


  //-----------------------------------------
  // Rendering Style: 
  // it's the default view mode for new window

  static int      ReadDefaultViewModeFromSettings  (const CATSupport& iSupport, int iDefaultViewMode); // frmwindow
  static void     ApplyDefaultViewMode             (CATVizViewer* iViewer, int iDefaultViewMode);      // toolkit 
  static void     ApplyDefaultAppearance           (CATVizViewer* iViewer);                            // FrmWindow

  static void     WriteDefaultViewModeToSettings   (int iViewMode, const CATSupport& iSupport);        // frmwindow
  static void     WriteDefaultAppearanceToSettings (CATSupport& iSupport);                             // FrmWindow  Is this method really necessary ?
  static void     WriteDefaultViewModeToSettings   (int iViewMode, const VisAppearance& iAppearance, CATSupport& iSupport); // viewmodepanel  

private:
  VisViewModeServices () {};
  ~VisViewModeServices() {};
  
  static void _Init();

  enum EViewModeType
  {
    eCustomViewMode,
    eDefaultViewMode
  };
  
  static void _GetSettingsID              (CATUnicodeString& oID, EViewModeType iType, const CATSupport& iSupport, const CATUnicodeString& iSuffix);

  static void _ApplyViewMode              (CATVizViewer* iViewer, unsigned int iViewMode, const VisAppearance& iAppearance);

  static void _ApplyAppearance            (CATVizViewer* iViewer, const VisAppearance& iAppearance);
  static void _ReadAppearanceFromSettings (VisAppearance& oAppearance, const CATUnicodeString& iID);
  static void _WriteAppearanceToSettings  (const VisAppearance& iAppearance, const CATUnicodeString& iID);
};

//-----------------------------------------------------------------------

#endif
