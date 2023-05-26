// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVidViewModePanel.h
// Header definition of CATVidViewModePanel
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2009  Creation: jov
//===================================================================
#ifndef CATVidViewModePanel_H
#define CATVidViewModePanel_H

#include <CATVidFraDialog.h>
#include <CATUnicodeString.h>
#include <CATVisImmersivePanel.h>

class CATString;
class CATVidCtlViewMode;
class CATVizViewer;

/**
 */
class ExportedByCATVisImmersivePanel CATVidViewModePanel: public CATVidFraDialog
{
  CATDeclareClass;
public:
  CATVidViewModePanel(CATCommand *i_pParent, const CATString & i_pIdentifier);

  void SetViewModeViewer(CATVizViewer* i_pViewModeViewer);
  CATVizViewer* GetViewModeViewer() const;

  // --------------------------------------------------------------------------
  // Flag to write or not in the settings. 
  // Default is true.
  // --------------------------------------------------------------------------
  void SetSettingsFlag(CATBoolean i_settingsFlag);
  CATBoolean GetSettingsFlag() const;
protected:
  virtual ~CATVidViewModePanel ();
  virtual void StandardButtonClicked(const CATString& i_name);
  virtual void Close();

private:
  CATVidCtlViewMode* _pViewModeWidget;
  int _initViewMode;
  CATBoolean _settingsFlag;
};

//-----------------------------------------------------------------------

#endif
