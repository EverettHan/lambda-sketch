#ifndef _VisSGOccurrenceRender_H_
#define _VisSGOccurrenceRender_H_

#include "VisOccurrencesGraph.h"
#include "CATCullingRender.h"
#include "IVisSGOccurrenceNotifier.h"


class VisSGOccurrenceNode;

class DummyOccObserver : public IVisSGOccurrenceNotifier
{
public:	
  void* OnOccurrencesCreated  (VisSGOccurrenceObserver* iObs, VisSGOccurrenceNode* iNode, const VisSGOccurrenceModifiedFlag& iModifiedFlags) {return NULL;};
  void  OnOccurrencesDeleted  (VisSGOccurrenceObserver* iObs, void* iUserData) {};
  void  OnOccurrencesModified (VisSGOccurrenceObserver* iObs, VisSGOccurrenceNode* iNode, const VisSGOccurrenceModifiedFlag& iModifiedFlags, void* iData) {};

  void  OnResourcesUpdated    (VisSGOccurrenceObserver* iObs, VisSGFeatureType iFeat, CATULONG32 iBegin, CATULONG32 iEnd) {};

  void  StartTransaction() {};
  void  EndTransaction() {};
};

/**
  Render using the OccurrenceGraph to speed up attributes resolution.
  Used for test and debug purposes.
*/
class ExportedByVisOccurrencesGraph VisSGOccurrenceRender : public CATCullingRender
{
public:
  VisSGOccurrenceRender (const CATSupport &support,bool iDrawCompiled = true);

  void Draw (list<CATViewpoint> &viewpointL, const int, const float);

  void DrawViewpoint(CATViewpoint* iVp);

  void DrawOccurrenceGraph(VisSGOccurrenceNode& iNode,VisSGOccurrenceObserver& iObs);

  void DrawOccurrenceGraph_Filtered(VisSGOccurrenceNode& iNode,VisSGOccurrenceObserver& iObs);
private:
  VisSGOccurrenceRender(VisSGOccurrenceRender const&);
  VisSGOccurrenceRender& operator=(VisSGOccurrenceRender const&);
  bool m_DrawCompiled;
};


#endif
