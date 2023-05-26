#ifndef SGToVisuConnectTool_H
#define SGToVisuConnectTool_H

#include "SceneGraphManager.h"
#include "CATBoolean.h"
#include "IUnknown.h"
class CATViewpoint;
class CATViewer;
class CATPathElementRep;
class CATCommand;
class CATString;
class CATRep;
class CATSelector;
class CATVizViewer;
class CATGraphicPathElement;
class CATBaseUnknown;

class ExportedBySceneGraphManager SGToVisuConnectTool
{
public:
  static inline CATBoolean DrawWithSprites(CATViewpoint* iViewpoint);

  static inline CATBoolean AddManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep);

  static inline CATBoolean RemoveManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep);

  static inline CATBoolean CreateCATSelector(CATCommand *iFather, const CATString &iName, CATRep *iRepresentation, CATSelector *& oSelector);

  static inline CATBoolean DestroyCATSelector(CATSelector * iSelector);

  static inline CATBoolean GetFatherOfCATSelector(CATSelector * iSelector, CATCommand *& oFather);

  static inline CATBoolean SetFatherOfCATSelector(CATSelector * iSelector, CATCommand * iFather);

  static inline CATBoolean AssociateCATSelectorToRep(CATSelector * iSelector, CATRep * iRep);

  static inline CATBoolean ViewerDraw(CATViewer * iViewer);

  static inline CATBoolean CATSelectorIsA(CATSelector * iSelector, const char * oIsA);

  static inline CATBoolean CATGetVizViewer(CATViewer * iViewer, CATVizViewer *& oVizViewer);

  static inline CATBoolean RemoveSubscriberCallbacks(CATGraphicPathElement * iGraphicPathElement, CATViewer* iViewer);

  static inline CATBoolean FindElement(CATViewer *iViewer, const IID &iid, CATBaseUnknown *& oElement);

protected:
  virtual CATBoolean __DrawWithSprites(CATViewpoint* iViewpoint) = 0;
  virtual CATBoolean __AddManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep) = 0;
  virtual CATBoolean __RemoveManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep) = 0;
  virtual CATBoolean __CreateCATSelector(CATCommand *iFather, const CATString &iName, CATRep *iRepresentation, CATSelector *& oSelector) = 0;
  virtual CATBoolean __DestroyCATSelector(CATSelector * iSelector) = 0;
  virtual CATBoolean __GetFatherOfCATSelector(CATSelector * iSelector, CATCommand *& oFather) = 0;
  virtual CATBoolean __SetFatherOfCATSelector(CATSelector * iSelector, CATCommand * iFather) = 0;
  virtual CATBoolean __AssociateCATSelectorToRep(CATSelector * iSelector, CATRep * iRep) = 0;
  virtual CATBoolean __ViewerDraw(CATViewer * iViewer) = 0;
  virtual CATBoolean __CATSelectorIsA(CATSelector * iSelector, const char * oIsA) = 0;
  virtual CATBoolean __CATGetVizViewer(CATViewer * iViewer, CATVizViewer *& oVizViewer) = 0;
  virtual CATBoolean __RemoveSubscriberCallbacks(CATGraphicPathElement * iGraphicPathElement, CATViewer* iViewer) = 0;
  virtual CATBoolean __FindElement(CATViewer *iViewer, const IID &iid, CATBaseUnknown *& oElement) = 0;

  SGToVisuConnectTool() 
  {
    RegisterImplInstance(this);
  }

private:    
  static void RegisterImplInstance(SGToVisuConnectTool * pConnectTool) 
  {
    _implInstance = pConnectTool;
  }
  static SGToVisuConnectTool * _implInstance;
  static CATBoolean _isNonVisuMode;
};

inline CATBoolean SGToVisuConnectTool::DrawWithSprites(CATViewpoint* iViewpoint)
{
  return (!_isNonVisuMode && _implInstance) ? _implInstance->__DrawWithSprites(iViewpoint) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::AddManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__AddManipOnRepPath(iViewer, iPathElementRep) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::RemoveManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__RemoveManipOnRepPath(iViewer, iPathElementRep) : FALSE;
} 

inline CATBoolean SGToVisuConnectTool::CreateCATSelector(CATCommand *iFather, const CATString &iName, CATRep *iRepresentation, CATSelector *& oSelector)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__CreateCATSelector(iFather, iName, iRepresentation, oSelector) : FALSE;
} 

inline CATBoolean SGToVisuConnectTool::DestroyCATSelector(CATSelector * iSelector)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__DestroyCATSelector(iSelector) : FALSE;
} 

inline CATBoolean SGToVisuConnectTool::GetFatherOfCATSelector(CATSelector * iSelector, CATCommand *& oFather)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__GetFatherOfCATSelector(iSelector, oFather) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::SetFatherOfCATSelector(CATSelector * iSelector, CATCommand * iFather)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__SetFatherOfCATSelector(iSelector, iFather) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::AssociateCATSelectorToRep(CATSelector * iSelector, CATRep * iRep)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__AssociateCATSelectorToRep(iSelector, iRep) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::ViewerDraw(CATViewer * iViewer)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__ViewerDraw(iViewer) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::CATSelectorIsA(CATSelector * iSelector, const char * oIsA)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__CATSelectorIsA(iSelector, oIsA) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::CATGetVizViewer(CATViewer * iViewer, CATVizViewer *& oVizViewer)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__CATGetVizViewer(iViewer, oVizViewer) : FALSE;
}

inline CATBoolean SGToVisuConnectTool::RemoveSubscriberCallbacks(CATGraphicPathElement * iGraphicPathElement, CATViewer* iViewer)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__RemoveSubscriberCallbacks(iGraphicPathElement, iViewer) : FALSE;
}  

inline CATBoolean SGToVisuConnectTool::FindElement(CATViewer *iViewer, const IID &iid, CATBaseUnknown *& oElement)
{
  return (!_isNonVisuMode &&_implInstance) ? _implInstance->__FindElement(iViewer, iid, oElement) : FALSE;
} 

#endif


