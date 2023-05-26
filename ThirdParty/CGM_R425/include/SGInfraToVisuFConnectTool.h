#ifndef SGInfraToVisuFConnectTool_H
#define SGInfraToVisuFConnectTool_H

#include "SGInfra.h"
#include "list.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATBoolean.h"
#include "CATVisRepresentationRole.h"
#include "CATVisInvalidationToken.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATListPV.h"

#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
//#include <X11/Xlib.h>
//#include <Xm/Xm.h>
//No need to spread X11 header like a cancer througout the visu classes
struct _XtAppStruct;
#endif
#endif

class CATViewpoint;
class CAT2DViewpoint;
class CATViewer;
class CATPathElementRep;
class CATCommand;
class CATString;
class CATRep;
class CATSelector;
class CATVizViewer;
class CATGraphicPathElement;
class CATBaseUnknown;
class CATIndicator;
class CATSupport;
class CATMetaClass;
class CATGraphicWindow;
class VisMultipipeData;
class CATFrameManager;
class CATVisualizationDeferredScheduler;
class CATCacheOfDestroyedElements;
class l_CATSupport;
class CATVisInfiniteEnvironmentStack;
class CAT3DScalePlaneRep;
class CATRepPath; 
class CATVizDisplayContext;
class CATUpdateEvent;
class CATSwapEvent;
class CATCullingRender;
class CATEPickingAlgo;
class CATRender;
class CATVisIntrospectionData;
class CAT3DViewpoint;
class CATManipulator;
class CATVisDynamicRenderingQualityData;
class CATDataShadowMapping;
class VisGPGPUProgram;
class VisGPGPUPrimitive;
class CATVizBasePathElementRep;
class CATVisSupportRayTracer;
class VisSubSupportData;
class CATVisInfiniteEnvironment;
class CATPolitnessHighlightCullingRender;
class CATGraphicAttributeSet;
class CATBatchGraphicWindow;
class CATViewpointEditor;

class ExportedBySGInfra SGInfraToVisuFConnectTool
{
public:
  static inline CATBoolean SetNearValue(float iFarMax, float & ioNearValue);
  static inline CATBoolean AttachIndicator_CAT3DViewpoint(CATIndicator*& indicator, CATBoolean & oIs3DIndicator);
  static inline CATBoolean GetSupport(CATVizViewer*& iVizViewer, CATSupport *& oSupport);
  static inline CATBoolean GetGraphicSize(CATVizViewer*& iVizViewer, float & oWidth, float & oHeight);
  static inline CATBoolean IsMultipipeActivated(CATVizViewer*& iVizViewer, int & oIsMultipipeActivated);
  static inline CATBoolean MetaObject_CATGraphicWindow(CATMetaClass *& oMetaObject);
  static inline CATBoolean GetGraphicWindowSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent);
  static inline CATBoolean GetGraphicWindowDeferredSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent);
  static inline CATBoolean GetVirtualWindow(CATSupport *& iSupport, CATGraphicWindow *& oGW);
  static inline CATBoolean GetListOfViewpoint(CATGraphicWindow *& iGW, list <CATViewpoint> & oViewPoints);
  static inline CATBoolean GetMultipipeData(CATGraphicWindow *& iGW, VisMultipipeData *& oVisMultipipeData);
  static inline CATBoolean IsMultipipeActivated(VisMultipipeData *& iVisMultipipeData, int & oIsMultipipeActivated);
  static inline CATBoolean IsSlaveWindow(CATGraphicWindow *& iGW, int & oIsSlaveWindow); 
  static inline CATBoolean GetSlaveWindowIndex(VisMultipipeData *& iVisMultipipeData, int & oSlaveWindowIndex);
  static inline CATBoolean GetSlaveWindow(CATGraphicWindow *& iGW, int & iIndex, CATGraphicWindow *& oSlaveWindow);
  static inline CATBoolean IsTechVizCapturedSupport(CATSupport *& iSuppoprt, unsigned int & oVal);
  static inline CATBoolean GetMasterGWForPassiveStereoCulling(CATGraphicWindow *& iGW, CATGraphicWindow *& oMasterGWForPassiveStereoCulling);
  static inline CATBoolean CreateCATFrameManager(CATFrameManager *& oFrameManager);
  static inline CATBoolean DeleteCATFrameManager(CATFrameManager *& iFrameManager);
  static inline CATBoolean DeleteInstance_CATVisuIdleListener();
  static inline CATBoolean SetNewAlgoOnGW(CATFrameManager*& iFrameManager, CATGraphicWindow*& i_prSupport);
  static inline CATBoolean NeedDrawEvent(CATFrameManager*& iFrameManager, int& oIsDrawNeeded);
  static inline CATBoolean DrawRequest(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport);
  static inline CATBoolean DoDrawJob(CATFrameManager *& iFrameManager);
  static inline CATBoolean Get_CATVisualizationDeferredScheduler(CATVisualizationDeferredScheduler *& oVisualizationDeferredScheduler);
  static inline CATBoolean DrawRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow *& i_prSupport);
  static inline CATBoolean DrawDeferredRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow* iWindow);
  static inline CATBoolean AddDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow);
  static inline CATBoolean RemoveDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow);

  static inline CATBoolean GetCallbackEvent_GRAPHICWINDOW_ENDING_DRAW(CATCallbackEvent& oEvent);

#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
  static inline CATBoolean SetAppContext(CATFrameManager *& iFrameManager, _XtAppStruct* & appContext);
#endif
#endif

  static inline CATBoolean ActivateDynamicMode(CATVisualizationDeferredScheduler *& iDeferedScheduler, unsigned int iOnOff);
  static inline CATBoolean IsDynamicMode(const l_CATSupport * iCATSupport, int & oVal);
  static inline CATBoolean CAT2DViewpoint_AttachIndicator(CAT2DViewpoint * i2dViewPoint, CATIndicator*& indicator);
  static inline CATBoolean ComputeScaleInCylindric(CAT3DScalePlaneRep * i3dScalePlaneRep, CATVizViewer *& iViewer);
  static inline CATBoolean ResetAndRedraw(CATFrameManager *& iFrameManager);
  static inline CATBoolean StartAnimation(CATViewpoint * iViewPoint, void *& From);
  static inline CATBoolean StopAnimation(CATViewpoint * iViewPoint, void *& From);
  static inline CATBoolean GetCATViewer(CATVizViewer * iVizViewer, CATViewer *& oViewer);
  static inline CATBoolean Invalidate(CATViewpoint * iViewpoint, CATVisInvalidationToken & i_invalidationToken, CATVisRepresentationRole & i_repType);
  static inline CATBoolean CATVizViewer_GetCurrentViewer(CATVizViewer *& oVizViewer);
  static inline CATBoolean GetDisplayContext(CATVizViewer *& iViewer, CATVizDisplayContext *& oVDC);
  static inline CATBoolean CATVizViewer_GetNextClassElement(CATVizViewer *& oVizViewer);
  static inline CATBoolean CATVizViewer_InitViewerClassList();
  static inline CATBoolean CreateCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent);
  static inline CATBoolean CreateCATSwapEvent(CATSwapEvent *& ioSwapEvent);
  static inline CATBoolean ReleaseCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent);
  static inline CATBoolean ReleaseCATSwapEvent(CATSwapEvent *& ioSwapEvent);
  static inline CATBoolean Picking(CATEPickingAlgo * iPickingAlgo, float i_x, float i_y, CATRender* i_pRender, CATRepPath *i_pPath,list<CATViewpoint> &i_viewpointList, int forceFullPick, int iOnlyDialogPicking);
  static inline CATBoolean DereferenceRep(CATManipulator *& iManipulator, CATRep * iRep);
  static inline CATBoolean InvalidInfiniteEnv(CATVizViewer* iViewer, int iForceUpdate);
	static inline CATBoolean GetMainViewpoint(CATVizViewer*& iViewer, CATViewpoint *& oViewpoint);
  static inline CATBoolean GetMain2DViewpoint(CATVizViewer*& iViewer, CAT2DViewpoint *& o2DViewpoint);
  static inline CATBoolean ReleaseVisGPGPUProgram(VisGPGPUProgram *& iVisGPGPUProgram);
  static inline CATBoolean Compute(VisGPGPUPrimitive * iVisGPGPUPrimitive, HRESULT & oRet);
  static inline CATBoolean SetVisGPGPUProgram(VisGPGPUPrimitive * iVisGPGPUPrimitive, VisGPGPUProgram *& iVisGPGPUProgram, HRESULT & ret);
  static inline CATBoolean GetGraphicCardDriverPackage(unsigned char * GraphicsCardPackage);
  static inline CATBoolean GetGraphicCardDriver(unsigned short * GraphicsCardPackage);
  static inline CATBoolean GetHardwareVideoMemorySize(unsigned int & hardwareVideoMemorySize);
  static inline CATBoolean AddRepToManipulate(CATManipulator * iManip, CATRep *& iRep);
  static inline CATBoolean RemoveRepToManipulate(CATManipulator * iManip, CATRep *& iRep);
  static inline CATBoolean UpdateBoundingElementOfPathElementRep(CATVizBasePathElementRep*& pPER);
  static inline CATBoolean GetPickWindowSize(CATVizViewer*& iVizViewer, int & oPickWindowSize);
  static inline CATBoolean Prepare(VisGPGPUPrimitive * iVisGPGPUPrimitive, void * iPrepareContext, void * iShaderOptions);
  static inline CATBoolean IsA(CATManipulator * iManip, char * oClassName);
  static inline CATBoolean IsDrawingDeferredDraw(CATSupport* iSupport, int& oRes);

  static inline CATBoolean ComputePoliteAlpha(CATPolitnessHighlightCullingRender* iRender, const CATGraphicAttributeSet& iAtt, int iOccludedMode, int& oRes);
  static inline CATBoolean SetPoliteOccludedMode(CATPolitnessHighlightCullingRender* iRender,int iValue);
  static inline CATBoolean GetPoliteFaceMode(CATPolitnessHighlightCullingRender* iRender, int& oRes);
  static inline CATBoolean MetaObject_CATPolitnessHighlightCullingRender(CATMetaClass *& oMetaObject);
  static inline CATBoolean UpdateStereoOnCIDViewers();

  static inline CATBoolean CreateCATBatchGraphicWindow(const int width, const int height, CATBatchGraphicWindow *& ioBatchGraphicWindow);

  static inline CATBoolean DispatchViewModeModifiedEvent(CATVizViewer* iVizViewer);
  static inline CATBoolean DispatchInfiniteEnvModifiedEvent(CATVizViewer* iVizViewer);

  static inline CATBoolean GetViewpointEditor(CATVizViewer* iVizViewer, CATViewpoint* iViewpoint, CATViewpointEditor*& oViewpointEditor);
  static inline CATBoolean GetTransformationLocks(CATViewpointEditor* iViewpointEditor, int& oTransformationLocks);
  static inline CATBoolean GetDefinedVPList(CATVizViewer* iVizViewer, CATListPV& oDefinedVPList);
  static inline CATBoolean GetMultiviewSyncMode(CATVizViewer* iVizViewer, int& oSyncMode);
  
protected:
  virtual CATBoolean __SetNearValue(float iFarMax, float & ioNearValue) = 0;
  virtual CATBoolean __AttachIndicator_CAT3DViewpoint(CATIndicator*& indicator, CATBoolean & oIs3DIndicator) = 0;
  virtual CATBoolean __GetSupport(CATVizViewer*& iVizViewer, CATSupport *& oSupport) = 0;
  virtual CATBoolean __GetGraphicSize(CATVizViewer*& iVizViewer, float & oWidth, float & oHeight) = 0;
  virtual CATBoolean __IsMultipipeActivated(CATVizViewer*& iVizViewer, int & oIsMultipipeActivated) = 0;
  virtual CATBoolean __MetaObject_CATGraphicWindow(CATMetaClass *& oMetaObject) = 0;
  virtual CATBoolean __GetGraphicWindowSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent) = 0;
  virtual CATBoolean __GetGraphicWindowDeferredSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent) = 0;
  virtual CATBoolean __GetVirtualWindow(CATSupport *& iSupport, CATGraphicWindow *& oGW) = 0;
  virtual CATBoolean __GetListOfViewpoint(CATGraphicWindow *& iGW, list <CATViewpoint> & oViewPoints) = 0;
  virtual CATBoolean __GetMultipipeData(CATGraphicWindow *& iGW, VisMultipipeData *& oVisMultipipeData) = 0;
  virtual CATBoolean __IsMultipipeActivated(VisMultipipeData *& iVisMultipipeData, int & oIsMultipipeActivated) = 0;
  virtual CATBoolean __IsSlaveWindow(CATGraphicWindow *& iGW, int & oIsSlaveWindow) = 0;
  virtual CATBoolean __GetSlaveWindowIndex(VisMultipipeData *& iVisMultipipeData, int & oSlaveWindowIndex) = 0;
  virtual CATBoolean __GetSlaveWindow(CATGraphicWindow *& iGW, int & iIndex, CATGraphicWindow *& oSlaveWindow) = 0;
  virtual CATBoolean __IsTechVizCapturedSupport(CATSupport *& iSuppoprt, unsigned int & oVal) = 0;
  virtual CATBoolean __GetMasterGWForPassiveStereoCulling(CATGraphicWindow *& iGW, CATGraphicWindow *& oMasterGWForPassiveStereoCulling) = 0;
  virtual CATBoolean __CreateCATFrameManager(CATFrameManager *& oFrameManager) = 0;
  virtual CATBoolean __DeleteCATFrameManager(CATFrameManager *& iFrameManager) = 0;
  virtual CATBoolean __DeleteInstance_CATVisuIdleListener() = 0;
  virtual CATBoolean __SetNewAlgoOnGW(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport) = 0;
  virtual CATBoolean __NeedDrawEvent(CATFrameManager*& iFrameManager, int& oIsDrawNeeded) = 0;
  virtual CATBoolean __DrawRequest(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport) = 0;
  virtual CATBoolean __DoDrawJob(CATFrameManager *& iFrameManager) = 0;
  virtual CATBoolean __Get_CATVisualizationDeferredScheduler(CATVisualizationDeferredScheduler *& oVisualizationDeferredScheduler) = 0;
  virtual CATBoolean __DrawRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow *& i_prSupport) = 0;
  virtual CATBoolean __DrawDeferredRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow* iWindow) = 0;
  virtual CATBoolean __AddDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow) = 0;
  virtual CATBoolean __RemoveDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow) = 0;
   
  virtual CATBoolean __GetCallbackEvent_GRAPHICWINDOW_ENDING_DRAW(CATCallbackEvent& oEvent) = 0;
   
#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
  virtual CATBoolean __SetAppContext(CATFrameManager *& iFrameManager, _XtAppStruct* & appContext) = 0;
#endif
#endif

  virtual CATBoolean __ActivateDynamicMode(CATVisualizationDeferredScheduler *& iDeferedScheduler, unsigned int iOnOff) = 0;
  virtual CATBoolean __IsDynamicMode(const l_CATSupport * iCATSupport, int & oVal) = 0;
  virtual CATBoolean __CAT2DViewpoint_AttachIndicator(CAT2DViewpoint * i2dViewPoint, CATIndicator*& indicator) = 0;
  virtual CATBoolean __ComputeScaleInCylindric(CAT3DScalePlaneRep * i3dScalePlaneRep, CATVizViewer *& iViewer) = 0;
  virtual CATBoolean __ResetAndRedraw(CATFrameManager *& iFrameManager) = 0;
  virtual CATBoolean __StartAnimation(CATViewpoint * iViewPoint, void *& From) = 0;
  virtual CATBoolean __StopAnimation(CATViewpoint * iViewPoint, void *& From) = 0;
  virtual CATBoolean __GetCATViewer(CATVizViewer * iVizViewer, CATViewer *& oViewer) = 0;
  virtual CATBoolean __Invalidate(CATViewpoint * iViewpoint, CATVisInvalidationToken & i_invalidationToken, CATVisRepresentationRole & i_repType) = 0;
  virtual CATBoolean __CATVizViewer_GetCurrentViewer(CATVizViewer *& oVizViewer) = 0;
  virtual CATBoolean __GetDisplayContext(CATVizViewer *& iViewer, CATVizDisplayContext *& oVDC) = 0;
  virtual CATBoolean __CATVizViewer_GetNextClassElement(CATVizViewer *& oVizViewer) = 0;
  virtual CATBoolean __CATVizViewer_InitViewerClassList() = 0;
  virtual CATBoolean __CreateCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent) = 0;
  virtual CATBoolean __CreateCATSwapEvent(CATSwapEvent *& ioSwapEvent) = 0;
  virtual CATBoolean __ReleaseCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent) = 0;
  virtual CATBoolean __ReleaseCATSwapEvent(CATSwapEvent *& ioSwapEvent) = 0;
  virtual CATBoolean __Picking(CATEPickingAlgo * iPickingAlgo, float i_x, float i_y, CATRender* i_pRender, CATRepPath *i_pPath,list<CATViewpoint> &i_viewpointList, int forceFullPick, int iOnlyDialogPicking) = 0;
  virtual CATBoolean __DereferenceRep(CATManipulator *& iManipulator, CATRep * iRep) = 0;
  virtual CATBoolean __InvalidInfiniteEnv(CATVizViewer* iViewer, int iForceUpdate) = 0;
	virtual CATBoolean __GetMainViewpoint(CATVizViewer*& iViewer, CATViewpoint *& oViewpoint) = 0;
  virtual CATBoolean __GetMain2DViewpoint(CATVizViewer*& iViewer, CAT2DViewpoint *& o2DViewpoint) = 0;
  virtual CATBoolean __ReleaseVisGPGPUProgram(VisGPGPUProgram *& iVisGPGPUProgram) = 0;
  virtual CATBoolean __Compute(VisGPGPUPrimitive * iVisGPGPUPrimitive, HRESULT & oRet) = 0;
  virtual CATBoolean __SetVisGPGPUProgram(VisGPGPUPrimitive * iVisGPGPUPrimitive, VisGPGPUProgram *& iVisGPGPUProgram, HRESULT & ret) = 0;
  virtual CATBoolean __CATGetGraphicCardDriverPackage(unsigned char * GraphicsCardPackage) = 0;
  virtual CATBoolean __CATGetGraphicCardDriver(unsigned short * GraphicsCardPackage) = 0;
  virtual CATBoolean __GetHardwareVideoMemorySize(unsigned int & hardwareVideoMemorySize) = 0;
  virtual CATBoolean __AddRepToManipulate(CATManipulator * iManip, CATRep *& iRep) = 0;
  virtual CATBoolean __RemoveRepToManipulate(CATManipulator * iManip, CATRep *& iRep) = 0;
  virtual CATBoolean __UpdateBoundingElementOfPathElementRep(CATVizBasePathElementRep*& pPER) = 0;
  virtual CATBoolean __GetPickWindowSize(CATVizViewer*& iVizViewer, int & oPickWindowSize) = 0;
  virtual CATBoolean __Prepare(VisGPGPUPrimitive * iVisGPGPUPrimitive, void * iPrepareContext, void*iShaderOptions) = 0;
  virtual CATBoolean __IsA(CATManipulator * iManip, char * oClassName) = 0;
  virtual CATBoolean __IsDrawingDeferredDraw(CATSupport* iSupport, int& oResg) = 0;

  virtual CATBoolean __ComputePoliteAlpha(CATPolitnessHighlightCullingRender* iRender, const CATGraphicAttributeSet& iAtt, int iOccludedMode, int& oRes) = 0;
  virtual CATBoolean __SetPoliteOccludedMode(CATPolitnessHighlightCullingRender* iRender,int iValue) = 0;
  virtual CATBoolean __GetPoliteFaceMode(CATPolitnessHighlightCullingRender* iRender, int& oRes) = 0;
  virtual CATBoolean __MetaObject_CATPolitnessHighlightCullingRender(CATMetaClass *& oMetaObject) = 0;
  virtual CATBoolean __UpdateStereoOnCIDViewers() = 0;

  virtual CATBoolean __CreateCATBatchGraphicWindow(const int width, const int height, CATBatchGraphicWindow *& ioBatchGraphicWindow) = 0;
  
  virtual CATBoolean __DispatchViewModeModifiedEvent(CATVizViewer* iVizViewer) = 0;
  virtual CATBoolean __DispatchInfiniteEnvModifiedEvent(CATVizViewer* iVizViewer) = 0;

  virtual CATBoolean __GetViewpointEditor(CATVizViewer* iVizViewer, CATViewpoint* iViewpoint, CATViewpointEditor*& oViewpointEditor) = 0;
  virtual CATBoolean __GetTransformationLocks(CATViewpointEditor* iViewpointEditor, int& oTransformationLocks) = 0;
  virtual CATBoolean __GetDefinedVPList(CATVizViewer* iVizViewer, CATListPV& oDefinedVPList) = 0;
  virtual CATBoolean __GetMultiviewSyncMode(CATVizViewer* iVizViewer, int& oSyncMode) = 0;

  SGInfraToVisuFConnectTool() 
  {
    RegisterImplInstance(this);
  }

private:    
  static void RegisterImplInstance(SGInfraToVisuFConnectTool * pConnectTool) 
  {
    _implInstance = pConnectTool;
  }
  static SGInfraToVisuFConnectTool * _implInstance;
  static CATBoolean _isNonVisuMode;
};
    

inline CATBoolean SGInfraToVisuFConnectTool::SetNearValue(float iFarMax, float & ioNearValue)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__SetNearValue(iFarMax, ioNearValue) : FALSE;
} 

inline CATBoolean SGInfraToVisuFConnectTool::AttachIndicator_CAT3DViewpoint(CATIndicator*& indicator, CATBoolean & oIs3DIndicator)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__AttachIndicator_CAT3DViewpoint(indicator, oIs3DIndicator) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetSupport(CATVizViewer*& iVizViewer, CATSupport *& oSupport)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetSupport(iVizViewer, oSupport) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetGraphicSize(CATVizViewer*& iVizViewer, float & oWidth, float & oHeight)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetGraphicSize(iVizViewer, oWidth, oHeight) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsMultipipeActivated(CATVizViewer*& iVizViewer, int & oIsMultipipeActivated)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsMultipipeActivated(iVizViewer, oIsMultipipeActivated) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::MetaObject_CATGraphicWindow(CATMetaClass *& oMetaObject)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__MetaObject_CATGraphicWindow(oMetaObject) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetGraphicWindowSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetGraphicWindowSwapEvent(iGW, oCallbackEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetGraphicWindowDeferredSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetGraphicWindowDeferredSwapEvent(iGW, oCallbackEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetVirtualWindow(CATSupport *& iSupport, CATGraphicWindow *& oGW)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetVirtualWindow(iSupport, oGW) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetListOfViewpoint(CATGraphicWindow *& iGW, list <CATViewpoint> & oViewPoints)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetListOfViewpoint(iGW, oViewPoints) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetMultipipeData(CATGraphicWindow *& iGW, VisMultipipeData *& oVisMultipipeData)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetMultipipeData(iGW, oVisMultipipeData) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsMultipipeActivated(VisMultipipeData *& iVisMultipipeData, int & oIsMultipipeActivated)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsMultipipeActivated(iVisMultipipeData, oIsMultipipeActivated) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsSlaveWindow(CATGraphicWindow *& iGW, int & oIsSlaveWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsSlaveWindow(iGW, oIsSlaveWindow) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetSlaveWindowIndex(VisMultipipeData *& iVisMultipipeData, int & oSlaveWindowIndex)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetSlaveWindowIndex(iVisMultipipeData, oSlaveWindowIndex) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetSlaveWindow(CATGraphicWindow *& iGW, int & iIndex, CATGraphicWindow *& oSlaveWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetSlaveWindow(iGW, iIndex, oSlaveWindow) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsTechVizCapturedSupport(CATSupport *& iSuppoprt, unsigned int & oVal)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsTechVizCapturedSupport(iSuppoprt, oVal) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetMasterGWForPassiveStereoCulling(CATGraphicWindow *& iGW, CATGraphicWindow *& oMasterGWForPassiveStereoCulling)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetMasterGWForPassiveStereoCulling(iGW, oMasterGWForPassiveStereoCulling) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CreateCATFrameManager(CATFrameManager *& oFrameManager)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CreateCATFrameManager(oFrameManager) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DeleteCATFrameManager(CATFrameManager *& iFrameManager)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DeleteCATFrameManager(iFrameManager) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DeleteInstance_CATVisuIdleListener()
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DeleteInstance_CATVisuIdleListener() : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::SetNewAlgoOnGW(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__SetNewAlgoOnGW(iFrameManager, i_prSupport) : FALSE;
}
inline CATBoolean SGInfraToVisuFConnectTool::NeedDrawEvent(CATFrameManager*& iFrameManager, int& oIsDrawNeeded)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__NeedDrawEvent(iFrameManager, oIsDrawNeeded) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DrawRequest(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DrawRequest(iFrameManager, i_prSupport) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DoDrawJob(CATFrameManager *& iFrameManager)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DoDrawJob(iFrameManager) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::Get_CATVisualizationDeferredScheduler(CATVisualizationDeferredScheduler *& oVisualizationDeferredScheduler)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__Get_CATVisualizationDeferredScheduler(oVisualizationDeferredScheduler) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DrawRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow *& i_prSupport)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DrawRequest(iDeferedScheduler, i_prSupport) : FALSE;
} 

inline CATBoolean SGInfraToVisuFConnectTool::DrawDeferredRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow* iWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DrawDeferredRequest(iDeferedScheduler, iWindow) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::AddDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__AddDeferredWindow(iDeferedScheduler, iWindow) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::RemoveDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__RemoveDeferredWindow(iDeferedScheduler, iWindow) : FALSE;
}

#if defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE)
#ifndef _NO_X11_SOURCE
  inline CATBoolean SGInfraToVisuFConnectTool::SetAppContext(CATFrameManager *& iFrameManager, _XtAppStruct* & appContext)
  {
    return (!_isNonVisuMode && _implInstance) ? _implInstance->__SetAppContext(iFrameManager, appContext) : FALSE;
  }
#endif
#endif
  
inline CATBoolean SGInfraToVisuFConnectTool::ActivateDynamicMode(CATVisualizationDeferredScheduler *& iDeferedScheduler, unsigned int  iOnOff)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ActivateDynamicMode(iDeferedScheduler, iOnOff) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsDynamicMode(const l_CATSupport * iCATSupport, int & oVal)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsDynamicMode(iCATSupport, oVal) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CAT2DViewpoint_AttachIndicator(CAT2DViewpoint * i2dViewPoint, CATIndicator*& indicator)
{ 
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CAT2DViewpoint_AttachIndicator(i2dViewPoint, indicator) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ComputeScaleInCylindric(CAT3DScalePlaneRep * i3dScalePlaneRep, CATVizViewer *& iViewer)
{ 
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ComputeScaleInCylindric(i3dScalePlaneRep, iViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ResetAndRedraw(CATFrameManager *& iFrameManager)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ResetAndRedraw(iFrameManager) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::StartAnimation(CATViewpoint * iViewPoint, void *& From)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__StartAnimation(iViewPoint, From) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::StopAnimation(CATViewpoint * iViewPoint, void *& From)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__StopAnimation(iViewPoint, From) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetCATViewer(CATVizViewer * iVizViewer, CATViewer *& oViewer)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetCATViewer(iVizViewer, oViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::Invalidate(CATViewpoint * iViewpoint, CATVisInvalidationToken & i_invalidationToken, CATVisRepresentationRole & i_repType)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__Invalidate(iViewpoint, i_invalidationToken, i_repType) : FALSE;
}    

inline CATBoolean SGInfraToVisuFConnectTool::CATVizViewer_GetCurrentViewer(CATVizViewer *& oVizViewer)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CATVizViewer_GetCurrentViewer(oVizViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetDisplayContext(CATVizViewer *& iVizViewer, CATVizDisplayContext *& oVDC)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetDisplayContext(iVizViewer, oVDC) : FALSE;
} 

inline CATBoolean SGInfraToVisuFConnectTool::CATVizViewer_InitViewerClassList()
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CATVizViewer_InitViewerClassList() : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CATVizViewer_GetNextClassElement(CATVizViewer *& oVizViewer)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CATVizViewer_GetNextClassElement(oVizViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CreateCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CreateCATUpdateEvent(ioUpdateEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CreateCATSwapEvent(CATSwapEvent *& ioSwapEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CreateCATSwapEvent(ioSwapEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ReleaseCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ReleaseCATUpdateEvent(ioUpdateEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ReleaseCATSwapEvent(CATSwapEvent *& ioSwapEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ReleaseCATSwapEvent(ioSwapEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::Picking(CATEPickingAlgo * iPickingAlgo, float i_x, float i_y, CATRender* i_pRender, CATRepPath *i_pPath,list<CATViewpoint> &i_viewpointList, int forceFullPick, int iOnlyDialogPicking)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__Picking(iPickingAlgo, i_x, i_y, i_pRender, i_pPath, i_viewpointList, forceFullPick, iOnlyDialogPicking) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DereferenceRep(CATManipulator *& iManipulator, CATRep * iRep)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DereferenceRep(iManipulator, iRep) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::InvalidInfiniteEnv(CATVizViewer* iViewer, int iForceUpdate)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__InvalidInfiniteEnv(iViewer, iForceUpdate) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetMainViewpoint(CATVizViewer*& iViewer, CATViewpoint *& oViewpoint)
{
	return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetMainViewpoint(iViewer, oViewpoint) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetMain2DViewpoint(CATVizViewer*& iViewer, CAT2DViewpoint *& o2DViewpoint)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetMain2DViewpoint(iViewer, o2DViewpoint) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ReleaseVisGPGPUProgram(VisGPGPUProgram *& iVisGPGPUProgram)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ReleaseVisGPGPUProgram(iVisGPGPUProgram) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::Compute(VisGPGPUPrimitive * iVisGPGPUPrimitive, HRESULT & oRet)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__Compute(iVisGPGPUPrimitive, oRet) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::SetVisGPGPUProgram(VisGPGPUPrimitive * iVisGPGPUPrimitive, VisGPGPUProgram *& iVisGPGPUProgram, HRESULT & ret)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__SetVisGPGPUProgram(iVisGPGPUPrimitive, iVisGPGPUProgram, ret) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetGraphicCardDriverPackage(unsigned char * GraphicsCardPackage)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CATGetGraphicCardDriverPackage(GraphicsCardPackage) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetGraphicCardDriver(unsigned short * GraphicsCardPackage)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CATGetGraphicCardDriver(GraphicsCardPackage) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetHardwareVideoMemorySize(unsigned int & hardwareVideoMemorySize)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetHardwareVideoMemorySize(hardwareVideoMemorySize) : FALSE;
} 

inline CATBoolean SGInfraToVisuFConnectTool::AddRepToManipulate(CATManipulator * iManip, CATRep *& iRep)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__AddRepToManipulate(iManip, iRep) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::RemoveRepToManipulate(CATManipulator * iManip, CATRep *& iRep)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__RemoveRepToManipulate(iManip, iRep) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::UpdateBoundingElementOfPathElementRep(CATVizBasePathElementRep*& pPER)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__UpdateBoundingElementOfPathElementRep(pPER) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetPickWindowSize(CATVizViewer*& iVizViewer, int & oPickWindowSize)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetPickWindowSize(iVizViewer, oPickWindowSize) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::Prepare(VisGPGPUPrimitive * iVisGPGPUPrimitive, void * iPrepareContext, void * iShaderOptions)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__Prepare(iVisGPGPUPrimitive, iPrepareContext, iShaderOptions) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsA(CATManipulator * iManip, char * oClassName)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsA(iManip, oClassName) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::IsDrawingDeferredDraw(CATSupport* iSupport, int& oRes)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__IsDrawingDeferredDraw(iSupport, oRes) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::ComputePoliteAlpha(CATPolitnessHighlightCullingRender* iRender, const CATGraphicAttributeSet& iAtt, int iOccludedMode, int& oRes)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__ComputePoliteAlpha(iRender, iAtt, iOccludedMode, oRes) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::SetPoliteOccludedMode(CATPolitnessHighlightCullingRender* iRender,int iValue)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__SetPoliteOccludedMode(iRender, iValue) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetPoliteFaceMode(CATPolitnessHighlightCullingRender* iRender, int& oRes)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetPoliteFaceMode(iRender, oRes) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::MetaObject_CATPolitnessHighlightCullingRender(CATMetaClass *& oMetaObject)
{
   return (!_isNonVisuMode && _implInstance) ? _implInstance->__MetaObject_CATPolitnessHighlightCullingRender(oMetaObject) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::UpdateStereoOnCIDViewers()
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__UpdateStereoOnCIDViewers() : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::CreateCATBatchGraphicWindow(const int width, const int height, CATBatchGraphicWindow *& ioBatchGraphicWindow)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__CreateCATBatchGraphicWindow(width, height, ioBatchGraphicWindow) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DispatchViewModeModifiedEvent(CATVizViewer* iVizViewer)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DispatchViewModeModifiedEvent(iVizViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::DispatchInfiniteEnvModifiedEvent(CATVizViewer* iVizViewer)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DispatchInfiniteEnvModifiedEvent(iVizViewer) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetCallbackEvent_GRAPHICWINDOW_ENDING_DRAW(CATCallbackEvent& oEvent)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetCallbackEvent_GRAPHICWINDOW_ENDING_DRAW(oEvent) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetViewpointEditor(CATVizViewer* iVizViewer, CATViewpoint* iViewpoint, CATViewpointEditor*& oViewpointEditor)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetViewpointEditor(iVizViewer, iViewpoint, oViewpointEditor) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetTransformationLocks(CATViewpointEditor* iViewpointEditor, int& oTransformationLocks)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetTransformationLocks(iViewpointEditor, oTransformationLocks) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetDefinedVPList(CATVizViewer* iVizViewer, CATListPV& oDefinedVPList)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetDefinedVPList(iVizViewer, oDefinedVPList) : FALSE;
}

inline CATBoolean SGInfraToVisuFConnectTool::GetMultiviewSyncMode(CATVizViewer* iVizViewer, int& oSyncMode)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__GetMultiviewSyncMode(iVizViewer, oSyncMode) : FALSE;
}

#endif
