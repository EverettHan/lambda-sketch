//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2020
//-----------------------------------------------------------------------------
#ifndef vOpenXRCompositor_H
#define vOpenXRCompositor_H

#ifdef _WINDOWS_SOURCE

#undef THROW
#include <openxr/openxr.h>
#include <openxr/pch.h>
#include "OpenXRRendering.h"
#undef THROW


#define V_USE_VULKAN

struct OpenXRRenderResourcesD3D11 {
  XrViewState ViewState{ XR_TYPE_VIEW_STATE };
  std::vector<XrView> Views;
  std::vector<XrViewConfigurationView> ConfigViews;
  std::vector<XrCompositionLayerProjectionView> ProjectionLayerViews;
};

//=============================================================================
/**
 * vOpenXRCompositor
 *
 * DirectX Rendering for OpenXR.
 *
 */
class ExportedByIVOpenXRRendering vOpenXRCompositor
{
  //--------------------------------------------------
public:

  /** Returns the instance if it was created, NULL otherwise
    */
  static vOpenXRCompositor* GetInstance();

  /** Create the instance if not already created
  */
  static bool CreateInstance();

  /** Destroy the instance if it exists
  */
  static bool DestroyInstance();

  /** */
  vOpenXRCompositor(vOpenXRCompositor const&) = delete;
  vOpenXRCompositor& operator=(vOpenXRCompositor const&) = delete;

  void WaitGetPoses(std::vector<XrPosef>& oViewPose);
  void GetViews(std::vector<XrView>& oViews);
  void GetConfigViews(std::vector<XrViewConfigurationView>& oConfigViews);

  void PrepareSessionRestart();

  void Submit(void* iLeft = NULL, void* iRight = NULL);

  void CreateSwapchains(xr::InstanceHandle& iInstance, uint64_t& iSystemId);

  void SetData(xr::SessionHandle& iSession, XrViewConfigurationType& iprimaryViewConfigType, XrEnvironmentBlendMode& iBlendMode,
    xr::SpaceHandle& iSceneSpace, xr::ExtensionDispatchTable& iExtensions);

  void GetHiddenAreaMesh(uint32_t iEye, uint32_t& oVertexCount, XrVector2f* oVertices);

  void GetFrameState(XrFrameState &oFrameState);

  void InitFrame();

  XrResult InitializeSession(xr::ExtensionDispatchTable& iExtensions, xr::InstanceHandle& iInstance, uint64_t& iSystemId, xr::SessionHandle& iSession);
  void GetEyeToHeadTransform(std::vector<XrView>& oViews);
  void GetProjectionRaw(uint32_t iEye, float* oLeft, float* oRight, float* oTop, float* oBottom);

  void ToggleSession(bool iStartStop);

  XrSwapchain GetSwapchain();
  XrSession GetSession();

  struct SwapChainInfo
  {
    std::uint32_t Format; //EColorFormat
    std::uint32_t ColorSpace; //EColorSpace
    std::uint32_t Width;
    std::uint32_t Height;
    std::uint32_t ArraySize;
    std::uint32_t UsageFlags;
    std::uint32_t CreateFlags;
    std::uint32_t InnerViewWidth; //For Varjo view
    std::uint32_t InnerViewHeight; //For Varjo view[2]
  };

  SwapChainInfo GetSwapChainInfo() const
  {
    return m_swapChainCreateInfo;
  }

  XrEnvironmentBlendMode GetBlendMode() const
  {
    return m_environmentBlendMode;
  }

  XrFrameState GetFrameState() const
  {
    return m_frameState;
  }

  XrInstance GetXrInstance() const
  {
    return m_instance;
  }

  void GetLayerInformation(XrCompositionLayerFlags& oLayerFlag, std::vector<XrCompositionLayerProjectionView>& oCompoistionLayer, XrSpace & oSpace) const;

  XrViewConfigurationType GetViewConfigurationType() const
  {
      return m_primaryViewConfigType;
  }

  int GetViewCount();

  //--------------------------------------------------  
private:

  /** */
  vOpenXRCompositor();
  virtual ~vOpenXRCompositor();

  static vOpenXRCompositor* _sInstance;


  void RenderFrame();

private:
  OpenXRRenderResourcesD3D11* m_renderResources;

  XrSession m_session;
  XrViewConfigurationType m_primaryViewConfigType;
  XrEnvironmentBlendMode m_environmentBlendMode;
  XrSpace m_sceneSpace;
  xr::ExtensionDispatchTable m_extensions;
  XrFrameState m_frameState;
  xr::SpaceHandle m_viewSpace;
  std::vector<XrView> m_eyeToHeadViews;
  XrInstance m_instance;

  SwapChainInfo m_swapChainCreateInfo;

  bool m_sessionRunning;
};

#endif // _WINDOWS_SOURCE

#endif
