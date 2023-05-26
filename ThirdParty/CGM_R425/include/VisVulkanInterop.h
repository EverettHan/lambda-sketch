#pragma once

#include "IVisTextureFormat.h"
#include "VisTextureFactory.h"
#include "VisPrivateServices.h"



class ExportedByVisPrivateServices VisVulkanInterop
{

public:


  static IVisTexturePtr CreateTextureFromExternalVKCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight, 
                                                       const VulkanSharing::MemoryObject & iMemoryObject, VulkanSharing::Semaphore iFence);
  static IVisTexturePtr CreateTextureFromExternalVKCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight,
    const VulkanSharing::MemoryObject& iMemoryObject, VulkanSharing::TimelineSemaphore iFence);

};

