
#pragma once

#include <SGInfra.h>

#include <cstdint>
#include <optional>
#include <array>

// API to retrieve Video Memory Occupation

struct VisGpuMemoryStatus
{  
  // Total memory occupied may not be simply (totalTextureMemoryOccupied + totalBufferMemoryOccupied), in Vulkan, it  gives the total
  // memory pre allocated on GPU, some of which may not be in use.
  std::size_t totalMemoryOccupied        = 0;
  std::size_t totalTextureMemoryOccupied = 0;
  std::size_t totalBufferMemoryOccupied  = 0;

  std::uint32_t totalBufferCount  = 0;
  std::uint32_t totalTextureCount = 0;

  static ExportedBySGInfra VisGpuMemoryStatus GetStatus(uint32_t iDevIdx);
};

struct VisGpuMemoryPerDev
{
  std::array<VisGpuMemoryStatus, 8> status;
  uint32_t nbDevice = 0;

  static ExportedBySGInfra VisGpuMemoryPerDev GetStatus();
};
