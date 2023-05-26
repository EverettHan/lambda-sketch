#pragma once

#include "VisTextureFactory.h"
#include "VisPrivateServices.h"
#include "CATSupport.h"

class VisSyncedCaptureDescription;

class ExportedByVisPrivateServices VisOpenGLInterop
{

public :


  /// @brief Creates a texture in NRE that will sync with the texture provided by external context
  /// @param iSyncFenceCallback This callback is called by NRE to provide with a OpenGL Sync object
  /// The sync callback is called from a render thread for a given device, as such it should be made thread safe
  /// The idea is to store the sync object somewhere and then sync with it before destroying the texture.
  /// If no callback is provided, no sync object is created.
  static IVisTexturePtr CreateTextureFromExternalGLCtx(const IVisTextureFormat::Type iFormat, unsigned int iWidth, unsigned int iHeight,
    OpenGLSharing::Context iContext, OpenGLSharing::Fence iFence, OpenGLSharing::TextureName iTexName, OpenGLSharing::SyncCallback iSyncFenceCallback = {});

  static VisSyncedCaptureDescription* EnablePixelStreaming(
    CATSupport* iSupport,
    OpenGLSharing::Context iContext,
    OpenGLSharing::TextureName iBuffers[]);

  static void DisablePixelStreaming(CATSupport* iSupport, VisSyncedCaptureDescription* iDesc);
};

