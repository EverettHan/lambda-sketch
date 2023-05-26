// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATEVidAfrWindow_H
#define CATEVidAfrWindow_H

// VisuImmersiveDialog framework
#include "CATIVidWindow.h"

// System framework
#include "CATString.h"

class CATVizViewer;
class CATViewer;

class CATEVidAfrWindow : public CATIVidWindow
{
  CATVizDeclareExtension(CATEVidAfrWindow, CATEVidAfrWindow, CATIVidWindow);

public:

  CATEVidAfrWindow();
  virtual ~CATEVidAfrWindow();

  virtual CATVizViewer * GetActiveWindowVizViewer(CATDialog** o_ppActiveDialog = NULL);
  virtual CATDialog * GetApplicationDialog();
  virtual CATDialog * GetMotifDialog(CATVizViewer* i_pVizViewer);
  virtual CATString GetType(CATVizViewer* i_pVizViewer);
  virtual CATVizViewer * GetVizViewer(CATViewer* i_pViewer);


  
  /**
  * Initialize the "software record level" of the CATEVidAfrWindow if we are
  * capturing a record ODT.
  * @see s_IsReplayingCATVidFraGridWindowOfOldOdt
  */
  static void s_InitializeCATEVidAfrWindowSRL();

  /**
  * Check if we are replaying an old Record ODT.
  *
  * The "software record level" used for versioning this modification
  * is named CATVidFraGridWindow and is positioned in the constructor of this
  * class (only once, for the first instance).
  *
  * @return @c != 0 if we are replaying and if the odt has been recorded
  * before the modification has been made.
  *
  * @see s_InitializeCATEVidAfrWindowSRL
  */
  static int s_IsReplayingCATEVidAfrWindowOfOldOdt(int i_level);
};

#endif
