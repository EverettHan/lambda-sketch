// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATVisUIVizViewer_H
#define CATVisUIVizViewer_H

#include "CATVizBaseCodeExtension.h"
#include "CATVisFoundation.h"

class CATDialog;
class CATDlgDialog;
class CATViz3DViewer;
class CATDlgFrame;

class ExportedByCATVisFoundation CATVisUIVizViewer : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATVisUIVizViewer);

public:  

  CATVisUIVizViewer();
  virtual ~CATVisUIVizViewer();

  virtual void InstantiatePanel(CATDlgDialog* i_pDialog, float i_width, float i_height, CATViz3DViewer** i_ppViz3DViewer, CATDialog** o_ppCursorDialog = NULL) = 0;
  virtual void InstantiateDlgWidget(CATDlgFrame* i_pFather, float i_width, float i_height, CATViz3DViewer** i_ppViz3DViewer, CATDialog** o_ppCursorDialog = NULL) = 0;
};

#endif
