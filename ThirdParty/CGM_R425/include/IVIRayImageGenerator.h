#ifndef IVIRayImageGenerator_H
#define IVIRayImageGenerator_H

#include "CATBaseUnknown.h"
#include "CATVisItf.h"
#include "CATCallbackManager.h"

class CATVizViewer;
class CATSupport;
class CATUnicodeString;
class CAT3DViewpoint;
class VisQualityData;
class CAT3DBagRep;

extern ExportedByCATVisItf IID IID_IVIRayImageGenerator;


enum CAPTUREMODE
{
  IV_GI_IMMERSIVE,
  IV_GI_TV
};

class ExportedByCATVisItf IVIRayImageGenerator : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  virtual HRESULT __stdcall Capture(CATUnicodeString filename)=0;

  //--------------------------------
// Associated Viewer
  virtual HRESULT __stdcall SetViewer(CATVizViewer *iViewer) = 0;
  virtual HRESULT __stdcall SetSupport(CATSupport* iSupport) = 0;
  virtual HRESULT __stdcall SetViewpoint(CAT3DViewpoint* iViewpoint) = 0;
  virtual HRESULT __stdcall DispatchRenderJobs() = 0;
  virtual HRESULT __stdcall IsCaptureStarted(bool &bIsCapture) = 0;
  virtual HRESULT __stdcall CreateSceneTranslator(CAT3DBagRep* iAmbianceRep, bool ibIsInteractive = false) = 0;
  virtual HRESULT __stdcall SetVisQualityData(const VisQualityData& iquality) = 0;
  virtual HRESULT __stdcall SetImagePath(CATUnicodeString iImagePath) = 0;
  virtual HRESULT __stdcall GetRenderRequestCount(int& ioCurrentReq, int& ioTotalReq, bool& isRenderCompleted) = 0;
  virtual HRESULT __stdcall SetRenderState(bool state) = 0;

  virtual CATCallbackManager* __stdcall GetCallbackManager() = 0;
  virtual bool __stdcall CreeteRenderingEntities() = 0;
  virtual bool __stdcall RenderingCompleted() = 0;
  virtual HRESULT __stdcall CaptureSingleImage(CATUnicodeString filename) = 0;
  virtual int GetGPUNum() = 0;

  CATDeclareCBEvent(RENDERING_FINISHED_UPDATE);
};

CATDeclareHandler(IVIRayImageGenerator, CATBaseUnknown);

#endif
