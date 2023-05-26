// COPYRIGHT Dassault Systemes 2023
//-------------------------------------------------------------------------------------------------
#pragma once

#include <CATVidUIDumpForWatcherAdapter.h>
#include <CATBoolean.h>

/**
 * CodeExtension implementing the CATISYPUIDumpForWatcher interface for CATVidCtlMenuView components.
 */
class ExportedByVisuDialog CATVidCtlMenuViewUIDumpForWatcherExt : public CATVidUIDumpForWatcherAdapter
{
  CATDeclareClass;

public:
  CATVidCtlMenuViewUIDumpForWatcherExt();
  virtual ~CATVidCtlMenuViewUIDumpForWatcherExt();

  virtual CATBoolean CanDump() override;

private:
  CATVidCtlMenuViewUIDumpForWatcherExt(const CATVidCtlMenuViewUIDumpForWatcherExt&);
  CATVidCtlMenuViewUIDumpForWatcherExt& operator=(const CATVidCtlMenuViewUIDumpForWatcherExt&);
};
