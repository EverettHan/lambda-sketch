// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATIVidWindow_H
#define CATIVidWindow_H

// Local framework
#include "VisuDialog.h"

// VisualizationFoundation framework
#include "CATVizBaseCodeExtension.h"

// System framework
#include "CATString.h"

class CATDialog;
class CATVizViewer;
class CATViewer;

/**
 * @ingroup VIDCore
 */
class ExportedByVisuDialog CATIVidWindow : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATIVidWindow);

public:  

  CATIVidWindow();
  virtual ~CATIVidWindow();

  /**
   * Returns the viewer of the active document and the active Dialog.
   * This method is called when building an immersive window. 
   * If the returned viewer is not null, the created window will be inserted in it.
   * If the viewer is null but the retrieved o_ppActiveDialog is valid, the window
   * will be extracted and its life cycle will be bound to the dialog one if it is of type DocumentLC.
   */
  virtual CATVizViewer * GetActiveWindowVizViewer(CATDialog** o_ppActiveDialog = NULL) = 0;

  /**
   * Returns the main application dialog.
   */
  virtual CATDialog * GetApplicationDialog() = 0;

  /**
   * Returns the type name of the window corresponding to the given viewer.
   * For example, it can be the workshop name.
   */
  virtual CATString GetType(CATVizViewer* i_pVizViewer);

  /**
   * Returns the CATVizViewer corresponding to the given CATViewer.
   */
  virtual CATVizViewer * GetVizViewer(CATViewer* i_pViewer);
};

#endif
