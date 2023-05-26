#ifndef CATVizBaseManipulatorMediator_H
#define CATVizBaseManipulatorMediator_H

/* COPYRIGHT DASSAULT SYSTEMES 2002 */

#include "CATVisFoundation.h"
#include "CATBaseUnknown.h"
#include "CATVizViewer.h"
#include "CATViewpoint.h"
#include "CAT2DIndication.h"

class ExportedByCATVisFoundation CATVizBaseManipulatorMediator : public CATBaseUnknown
{
public :
  CATVizBaseManipulatorMediator();
  virtual ~CATVizBaseManipulatorMediator();
  void SetViewer(CATVizViewer *pVizViewer);
  void SetViewpoint(CATViewpoint *pViewpoint);

  virtual void *DecodeInfo(const char *iUuid, CATNotification *iGraphicNotification);
  void SetIndication2D(CAT2DIndication i_indication);
  CAT2DIndication *GetIndication2DPtr();

  protected:
  CATViewpoint *_pViewpoint;
  CATVizViewer *_pVizViewer;
};

#endif
