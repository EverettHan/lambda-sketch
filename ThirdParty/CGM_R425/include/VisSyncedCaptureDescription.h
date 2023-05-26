#pragma once

#include "CATVisFoundation.h"

#include "IVisTexturePtr.h"

#include <mutex>
#include <memory>
#include <condition_variable>

#include "CATEvent.h"

class ExportedByCATVisFoundation VisSyncedCaptureDescription
{
public:
  VisSyncedCaptureDescription();

  //Thread syncing
  std::shared_ptr<std::mutex>              m_Lock;
  std::shared_ptr<std::condition_variable> m_Cond;
  std::uint8_t                             m_FrameReady = 0;

  //Double buffering
  std::uint8_t                             m_BufferIndex = 0;
};
