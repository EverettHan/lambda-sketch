#ifndef SGInfraToVisuFConnectToolImpl_H
#define SGInfraToVisuFConnectToolImpl_H

#include "CATVisFoundation.h"
#include "list.h"
#include "SGInfraToVisuFConnectTool.h"
#include "CATBaseUnknown.h"
#include "CATEventSubscriberTypedefs.h"
class CATViewpoint;
class CATViewer;
class CATPathElementRep;
class CATCommand;
class CATString;
class CATRep;
class CATSelector;
class CATIndicator;
class CATFrameManager;
class CATVisualizationDeferredScheduler;
class CATCacheOfDestroyedElements;
class CATPolitnessHighlightCullingRender;

class ExportedByCATVisFoundation SGInfraToVisuFConnectToolImpl : public SGInfraToVisuFConnectTool
{
private:
  virtual CATBoolean __SetNearValue(float iFarMax, float & ioNearValue);
  virtual CATBoolean __AttachIndicator_CAT3DViewpoint(CATIndicator*& indicator, CATBoolean & oIs3DIndicator);
  virtual CATBoolean __GetSupport(CATVizViewer*& iVizViewer, CATSupport *& oSupport);
  virtual CATBoolean __GetGraphicSize(CATVizViewer*& iVizViewer, float & oWidth, float & oHeight);
  virtual CATBoolean __IsMultipipeActivated(CATVizViewer*& iVizViewer, int & oIsMultipipeActivated);
  virtual CATBoolean __MetaObject_CATGraphicWindow(CATMetaClass *& oMetaObject);
  virtual CATBoolean __GetGraphicWindowSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent);
  virtual CATBoolean __GetGraphicWindowDeferredSwapEvent(CATGraphicWindow* iGW, CATCallbackEvent& oCallbackEvent);
  virtual CATBoolean __GetVirtualWindow(CATSupport*& iSupport, CATGraphicWindow*& oGW);
  virtual CATBoolean __GetListOfViewpoint(CATGraphicWindow *& iGW, list <CATViewpoint> & oViewPoints);
  virtual CATBoolean __GetMultipipeData(CATGraphicWindow *& iGW, VisMultipipeData *& oVisMultipipeData);
  virtual CATBoolean __IsMultipipeActivated(VisMultipipeData *& iVisMultipipeData, int & oIsMultipipeActivated);
  virtual CATBoolean __IsSlaveWindow(CATGraphicWindow *& iGW, int & oIsSlaveWindow);
  virtual CATBoolean __GetSlaveWindowIndex(VisMultipipeData *& iVisMultipipeData, int & oSlaveWindowIndex);
  virtual CATBoolean __GetSlaveWindow(CATGraphicWindow *& iGW, int & iIndex, CATGraphicWindow *& oSlaveWindow);
  virtual CATBoolean __IsTechVizCapturedSupport(CATSupport *& iSuppoprt, unsigned int & oVal);
  virtual CATBoolean __GetMasterGWForPassiveStereoCulling(CATGraphicWindow *& iGW, CATGraphicWindow *& oMasterGWForPassiveStereoCulling);
  virtual CATBoolean __CreateCATFrameManager(CATFrameManager *& oFrameManager);
  virtual CATBoolean __DeleteCATFrameManager(CATFrameManager *& iFrameManager);
  virtual CATBoolean __DeleteInstance_CATVisuIdleListener();
  virtual CATBoolean __SetNewAlgoOnGW(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport);
  virtual CATBoolean __NeedDrawEvent(CATFrameManager*& iFrameManager, int& oIsDrawNeeded);
  virtual CATBoolean __DrawRequest(CATFrameManager *& iFrameManager, CATGraphicWindow *& i_prSupport);
  virtual CATBoolean __DoDrawJob(CATFrameManager *& iFrameManager);
  virtual CATBoolean __Get_CATVisualizationDeferredScheduler(CATVisualizationDeferredScheduler *& oVisualizationDeferredScheduler);
  virtual CATBoolean __DrawRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow *& i_prSupport);
  virtual CATBoolean __DrawDeferredRequest(CATVisualizationDeferredScheduler *& iDeferedScheduler, CATGraphicWindow* iWindow);
  virtual CATBoolean __AddDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow);
  virtual CATBoolean __RemoveDeferredWindow(CATVisualizationDeferredScheduler* iDeferedScheduler, CATSupport* iWindow);

  virtual CATBoolean __GetCallbackEvent_GRAPHICWINDOW_ENDING_DRAW(CATCallbackEvent& oEvent);

#if !defined (_NO_X11_SOURCE) && (defined (_LINUX_SOURCE) || defined (_AIX_SOURCE) || (defined (_DARWIN_SOURCE) && !defined (_COCOA_SOURCE)) || defined (_IRIX_SOURCE) || defined (_SUNOS_SOURCE) || defined (_HPUX_SOURCE))
  virtual CATBoolean __SetAppContext(CATFrameManager *& iFrameManager, _XtAppStruct* & appContext);
#endif

  virtual CATBoolean __ActivateDynamicMode(CATVisualizationDeferredScheduler *& iDeferedScheduler, unsigned int iOnOff);
  virtual CATBoolean __IsDynamicMode(const l_CATSupport * iCATSupport, int & oVal) override;
  virtual CATBoolean __CAT2DViewpoint_AttachIndicator(CAT2DViewpoint * i2dViewPoint, CATIndicator*& indicator);
  virtual CATBoolean __ComputeScaleInCylindric(CAT3DScalePlaneRep * i3dScalePlaneRep, CATVizViewer *& iViewer);
  virtual CATBoolean __ResetAndRedraw(CATFrameManager *& iFrameManager);
  virtual CATBoolean __StartAnimation(CATViewpoint * iViewPoint, void *& From);
  virtual CATBoolean __StopAnimation(CATViewpoint * iViewPoint, void *& From);
  virtual CATBoolean __GetCATViewer(CATVizViewer * iVizViewer, CATViewer *& oViewer);
  virtual CATBoolean __Invalidate(CATViewpoint * iViewpoint, CATVisInvalidationToken & i_invalidationToken, CATVisRepresentationRole & i_repType);
  virtual CATBoolean __CATVizViewer_GetCurrentViewer(CATVizViewer *& oVizViewer);
  virtual CATBoolean __GetDisplayContext(CATVizViewer *& iViewer, CATVizDisplayContext *& oVDC);
  virtual CATBoolean __CATVizViewer_GetNextClassElement(CATVizViewer *& oVizViewer);
  virtual CATBoolean __CATVizViewer_InitViewerClassList();
  virtual CATBoolean __CreateCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent);
  virtual CATBoolean __CreateCATSwapEvent(CATSwapEvent *& ioSwapEvent);
  virtual CATBoolean __ReleaseCATUpdateEvent(CATUpdateEvent *& ioUpdateEvent);
  virtual CATBoolean __ReleaseCATSwapEvent(CATSwapEvent *& ioSwapEvent);
  virtual CATBoolean __Picking(CATEPickingAlgo * iPickingAlgo, float i_x, float i_y, CATRender* i_pRender, CATRepPath *i_pPath,list<CATViewpoint> &i_viewpointList, int forceFullPick, int iOnlyDialogPicking);
  virtual CATBoolean __DereferenceRep(CATManipulator *& iManipulator, CATRep * iRep);
  virtual CATBoolean __InvalidInfiniteEnv(CATVizViewer* iViewer, int iForceUpdate);
	virtual CATBoolean __GetMainViewpoint(CATVizViewer*& iViewer, CATViewpoint *& oViewpoint);
  virtual CATBoolean __GetMain2DViewpoint(CATVizViewer*& iViewer, CAT2DViewpoint *& o2DViewpoint);
  virtual CATBoolean __ReleaseVisGPGPUProgram(VisGPGPUProgram *& iVisGPGPUProgram);
  virtual CATBoolean __Compute(VisGPGPUPrimitive * iVisGPGPUPrimitive, HRESULT & oRet);
  virtual CATBoolean __SetVisGPGPUProgram(VisGPGPUPrimitive * iVisGPGPUPrimitive, VisGPGPUProgram *& iVisGPGPUProgram, HRESULT & ret);
  virtual CATBoolean __CATGetGraphicCardDriverPackage(unsigned char * GraphicsCardPackage);
  virtual CATBoolean __CATGetGraphicCardDriver(unsigned short * GraphicsCardPackage);
  virtual CATBoolean __GetHardwareVideoMemorySize(unsigned int & hardwareVideoMemorySize);
  virtual CATBoolean __AddRepToManipulate(CATManipulator * iManip, CATRep *& iRep);
  virtual CATBoolean __RemoveRepToManipulate(CATManipulator * iManip, CATRep *& iRep);
  virtual CATBoolean __UpdateBoundingElementOfPathElementRep(CATVizBasePathElementRep*& pPER);
  virtual CATBoolean __GetPickWindowSize(CATVizViewer*& iVizViewer, int & oPickWindowSize);
  virtual CATBoolean __Prepare(VisGPGPUPrimitive * iVisGPGPUPrimitive, void * iPrepareContext, void * iShaderOptions);
  virtual CATBoolean __IsA(CATManipulator * iManip, char * oClassName);
  virtual CATBoolean __IsDrawingDeferredDraw(CATSupport* iSupport, int& oRes);

  virtual CATBoolean __ComputePoliteAlpha(CATPolitnessHighlightCullingRender* iRender, const CATGraphicAttributeSet& iAtt, int iOccludedMode, int& oRes);
  virtual CATBoolean __SetPoliteOccludedMode(CATPolitnessHighlightCullingRender* iRender,int iValue);
  virtual CATBoolean __GetPoliteFaceMode(CATPolitnessHighlightCullingRender* iRender, int& oRes);
  virtual CATBoolean __MetaObject_CATPolitnessHighlightCullingRender(CATMetaClass *& oMetaObject);
  virtual CATBoolean __UpdateStereoOnCIDViewers();

  virtual CATBoolean __CreateCATBatchGraphicWindow(const int width, const int height, CATBatchGraphicWindow *& ioBatchGraphicWindow);
  
  virtual CATBoolean __DispatchViewModeModifiedEvent(CATVizViewer* iVizViewer);
  virtual CATBoolean __DispatchInfiniteEnvModifiedEvent(CATVizViewer* iVizViewer);

  virtual CATBoolean __GetViewpointEditor(CATVizViewer* iVizViewer, CATViewpoint* iViewpoint, CATViewpointEditor*& oViewpointEditor);
  virtual CATBoolean __GetTransformationLocks(CATViewpointEditor* iViewpointEditor, int& oTransformationLocks);
  virtual CATBoolean __GetDefinedVPList(CATVizViewer* iVizViewer, CATListPV& oDefinedVPList);
  virtual CATBoolean __GetMultiviewSyncMode(CATVizViewer* iVizViewer, int& oSyncMode);

  static SGInfraToVisuFConnectToolImpl _SGInfraToVisuFConnectToolImpl; //global object
};

#endif 
