// COPYRIGHT Dassault Systemes 2022
//-------------------------------------------------------------------------------------------------
#pragma once

#include <UIVCoreTools.h>
#include <CATISYPUIDumpForWatcher.h>
#include <nlohmann/json_fwd.hpp>
#include <CATBoolean.h>

/**
 * CodeExtension implementing the CATISYPVisitorActor interface for CID components.
 */
class ExportedByUIVCoreTools CATSYPUIDumpForWatcherAdapter : public CATISYPUIDumpForWatcher
{
public:
  CATSYPUIDumpForWatcherAdapter();
  virtual ~CATSYPUIDumpForWatcherAdapter();

  virtual CATBoolean CanDump() override;
  virtual nlohmann::json Dump() override;
  virtual CATBoolean DumpContent() override;

private:
  CATSYPUIDumpForWatcherAdapter(const CATSYPUIDumpForWatcherAdapter &);
  CATSYPUIDumpForWatcherAdapter &operator=(const CATSYPUIDumpForWatcherAdapter &);
};
