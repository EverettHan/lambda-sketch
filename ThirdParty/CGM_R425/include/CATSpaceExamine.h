// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATSpaceExamine_H
#define CATSpaceExamine_H

#include "CATEventSubscriber.h"
#include "CATVisFoundation.h"
#include "CATMathVectorf.h"

class CAT3DViewpoint;
class CATVizViewer;
class CAT3DViewpointEditor;

class ExportedByCATVisFoundation CATSpaceExamine : public CATEventSubscriber
{
public:
  CATSpaceExamine(CAT3DViewpoint *viewpoint, CATVizViewer *viewer, CAT3DViewpointEditor *viewpointEditor);
  virtual ~CATSpaceExamine(void);

  void StartSpaceExamine(void);
  void EndSpaceExamine(void);
  void InitSpaceExamine( void);
  void CleanSpaceExamine( void);

  void SetData(CATMathVectorf& trans, CATMathVectorf& rot);

  static int GetFastZoom(void) {return _fastzoom;};
  static void SetFastZoom(int fastzoom) { _fastzoom = fastzoom;};

private:
  void ComputeNextStep(CATCallbackEvent Id, void *From, CATNotification *Event, CATSubscriberData Data, CATCallback Callback);
  void ComputeImmediateNextStep();

  CAT3DViewpoint *_3DViewpoint;
  CATVizViewer *_pVizViewer;
  CAT3DViewpointEditor *_3DViewpointEditor;

  CATMathVectorf _translation;
  CATMathVectorf _rotation;

  CATCallback _AnimationCB;
  CATUINTPTR  _UpdateTime;
  static int _fastzoom;

  // Not implemented
  CATSpaceExamine(const CATSpaceExamine &);
  CATSpaceExamine & operator= (const CATSpaceExamine &);
};

#endif // CATSpaceExamine_H
