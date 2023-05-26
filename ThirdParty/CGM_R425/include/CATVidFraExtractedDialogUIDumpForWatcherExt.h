// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <CATVidUIDumpForWatcherAdapter.h>
#include <CATBoolean.h>

/**
 * CodeExtension implementing the CATISYPUIDumpForWatcher interface for CATVidFraExtractedDialog components.
 */
class ExportedByVisuDialog CATVidFraExtractedDialogUIDumpForWatcherExt : public CATVidUIDumpForWatcherAdapter
{
  CATDeclareClass;

public:
  CATVidFraExtractedDialogUIDumpForWatcherExt();
  virtual ~CATVidFraExtractedDialogUIDumpForWatcherExt();

  virtual CATBoolean CanDump() override;

private:
  CATVidFraExtractedDialogUIDumpForWatcherExt(const CATVidFraExtractedDialogUIDumpForWatcherExt&);
  CATVidFraExtractedDialogUIDumpForWatcherExt&operator=(const CATVidFraExtractedDialogUIDumpForWatcherExt&);
};
