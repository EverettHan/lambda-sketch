// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATVisProtocolUIPanels_H
#define CATVisProtocolUIPanels_H

#include "CATVizBaseCodeExtension.h"
#include "CATVisController.h"

class CATDlgDialog;
class CATDialog;
class CAT3DViewer;

class ExportedByCATVisController CATVisProtocolUIPanels : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATVisProtocolUIPanels);

public:  

  CATVisProtocolUIPanels();
  virtual ~CATVisProtocolUIPanels();

  virtual CATDlgDialog* InstantiatePanel(CAT3DViewer* ipViewer) = 0;
  virtual CATDlgDialog* InstantiatePanel(CATDialog* ipFather, CAT3DViewer* ipViewer) = 0;

  virtual CAT3DViewer* GetViewer() = 0;

  virtual void CancelPanel() = 0;
  virtual void DestroyPanel() = 0;
};

#endif
