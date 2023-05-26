// COPYRIGHT Dassault Systemes 2006
//===================================================================
#ifndef CATVidFraDlgWidget_H
#define CATVidFraDlgWidget_H

#include "VisuDialog.h"
#include "CATDlgFrame.h"

class CATDialog;
class CATString;
class CATVidModelWidget;
class CATViz3DViewer;
class CATVidFraBindToViewer;
//-----------------------------------------------------------------------
/**
 * This class allows to create wa bridge between Dialog and VID.
 */
class ExportedByVisuDialog CATVidFraDlgWidget: public CATDlgFrame
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidFraDlgWidget (CATDialog* i_pDialogFather, const CATString & i_pIdentifier, CATVidModelWidget* i_pHandledWidget, const CATUnicodeString& i_title, int i_dontLayoutVIDFlag=0);

  CATVidModelWidget* GetHandledWidget() const{return _pHandledWidget;}
protected:
  virtual ~CATVidFraDlgWidget ();

  void ResizingDialog (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );
  void HandledWidgetDeletedCB(CATCallbackEvent, void*, CATNotification* i_pNotification, CATSubscriberData , CATCallback OnHandledWidgetModify);
  void HandledWidgetModifiedCB(CATCallbackEvent, void*, CATNotification* i_pEvent, CATSubscriberData , CATCallback);
  /**
   * @param i_deltaX in dialog pixels
   * @param i_deltaY in dialog pixels
   */
  void ApplyOffsetDimension (float i_deltaX, float i_deltaY);

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidFraDlgWidget (CATVidFraDlgWidget &);
  CATVidFraDlgWidget& operator=(CATVidFraDlgWidget& original);

  CATViz3DViewer* _pVizViewer;
  CATVidFraBindToViewer* _pBindToViewer;
  CATVidModelWidget* _pHandledWidget;

  CATDialog* _pMotif;
  DRECT _dialogRectangle;
  CATCallback _handledWidgetModifiedCB;
  CATBoolean _resizingHandledWidget;
  CATCallback _handledWidgetDeletedCB;
};
//-----------------------------------------------------------------------

#endif
