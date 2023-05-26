// COPYRIGHT DASSAULT SYSTEMES 2005

#ifndef CATVisProtocolUIDrillPanels_H
#define CATVisProtocolUIDrillPanels_H

#include "CATVizBaseCodeExtension.h"
#include "CATVisController.h"

class CATDlgDialog;
class CAT3DViewer;
class CATDrillSelector;
class CATPickPath;

class ExportedByCATVisController CATVisProtocolUIDrillPanels : public CATVizBaseCodeExtension
{
  CATVizDeclareProtocol(CATVisProtocolUIDrillPanels);

public:  

  CATVisProtocolUIDrillPanels();
  virtual ~CATVisProtocolUIDrillPanels();

  virtual CATDlgDialog* InstantiatePanel(CAT3DViewer* ipViewer) = 0;

  virtual void SetDrillSelector(CATDrillSelector* ipDrillSelector) = 0;
  virtual void UnsetDrillSelector(CATDrillSelector* ipDrillSelector) = 0;

  virtual void UpdateDrill(CATPickPath* ipPath) = 0;

  virtual void CancelPanel() = 0;
  virtual void DestroyPanel() = 0;
};

#endif
