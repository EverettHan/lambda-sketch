// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <VisuDialog.h>
#include <CATSYPUIDumpForWatcherAdapter.h>
#include <nlohmann/json_fwd.hpp>
#include <CATBoolean.h>

/**
 * CodeExtension implementing the CATISYPUIDumpForWatcher interface for CID components.
 */
class ExportedByVisuDialog CATVidUIDumpForWatcherAdapter : public CATSYPUIDumpForWatcherAdapter
{
public:
  CATVidUIDumpForWatcherAdapter();
  virtual ~CATVidUIDumpForWatcherAdapter();

  virtual CATBoolean CanDump() override;
  virtual nlohmann::json Dump() override;
  virtual CATBoolean DumpContent() override;

private:
  CATVidUIDumpForWatcherAdapter(const CATVidUIDumpForWatcherAdapter &);
  CATVidUIDumpForWatcherAdapter &operator=(const CATVidUIDumpForWatcherAdapter &);
};
