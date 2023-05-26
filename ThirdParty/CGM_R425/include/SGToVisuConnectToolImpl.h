#ifndef SGToVisuConnectToolImpl_H
#define SGToVisuConnectToolImpl_H

#include "CATVisController.h"
#include "SGToVisuConnectTool.h"
class CATViewpoint;
class CATViewer;
class CATPathElementRep;
class CATCommand;
class CATString;
class CATRep;
class CATSelector;

class ExportedByCATVisController SGToVisuConnectToolImpl : public SGToVisuConnectTool
{
private:
  virtual CATBoolean __DrawWithSprites(CATViewpoint* iViewpoint); 

  virtual CATBoolean __AddManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep);

  virtual CATBoolean __RemoveManipOnRepPath(CATViewer * iViewer, CATPathElementRep* iPathElementRep); 

  virtual CATBoolean __CreateCATSelector(CATCommand *iFather, const CATString &iName, CATRep *iRepresentation, CATSelector *& oSelector);

  virtual CATBoolean __DestroyCATSelector(CATSelector * iSelector);

  virtual CATBoolean __GetFatherOfCATSelector(CATSelector * iSelector, CATCommand *& oFather);

  virtual CATBoolean __SetFatherOfCATSelector(CATSelector * iSelector, CATCommand * iFather);

  virtual CATBoolean __AssociateCATSelectorToRep(CATSelector * iSelector, CATRep * iRep);

  virtual CATBoolean __ViewerDraw(CATViewer * iViewer);

  virtual CATBoolean __CATSelectorIsA(CATSelector * iSelector, const char * oIsA);

  virtual CATBoolean __CATGetVizViewer(CATViewer * iViewer, CATVizViewer *& oVizViewer);

  virtual CATBoolean __RemoveSubscriberCallbacks(CATGraphicPathElement * iGraphicPathElement, CATViewer* iViewer);

  virtual CATBoolean __FindElement(CATViewer *iViewer, const IID &iid, CATBaseUnknown *& oElement);

  static SGToVisuConnectToolImpl _SGToVisuConnectToolImpl; //global object
};

#endif
 
