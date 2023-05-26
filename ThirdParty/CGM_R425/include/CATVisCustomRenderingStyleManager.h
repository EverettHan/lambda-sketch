#ifndef CATVisCustomRenderingStyleManager_H
#define CATVisCustomRenderingStyleManager_H

// COPYRIGHT DASSAULT SYSTEMES 2010

#include "CATBaseUnknown.h"
#include "CATVisController.h"
#include "CATEventSubscriber.h"

class CATRep;
class CAT3DViewer;
class CATVisPLMRenderingStyleData;
class CATVisRenderingStyleSet;
class ExportedByCATVisController CATVisCustomRenderingStyleManager : public CATBaseUnknown
{
public :
  static CATVisCustomRenderingStyleManager* Create(CAT3DViewer* iViewer);

  void Activate(unsigned int iOnOff);

  void SetRenderingStyle(unsigned int iID, const CATVisPLMRenderingStyleData&  iData);
  void ResetRenderingStyles(); 

  void ModifyObject(CATBaseUnknown* iObject, unsigned int iID);
  void RestoreSceneToDefault();

private:
  void OnViewerDestroyedCB(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback); 

  CATVisCustomRenderingStyleManager(CAT3DViewer* iViewer);
  ~CATVisCustomRenderingStyleManager();

  CATVisRenderingStyleSet*    _renderingStyle;
  unsigned int                _activation;
  CAT3DViewer*                _viewer;
  CATCallback                 _viewerDestroyCB;
  unsigned int                _versionNumber;
};


#endif
