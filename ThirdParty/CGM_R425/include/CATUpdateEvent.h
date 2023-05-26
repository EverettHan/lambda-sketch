#ifndef CATUpdateEvent_H
#define CATUpdateEvent_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Event send by the GraphicWindow to the viewer to inform
//		about the end of update.
//------------------------------------------------------------------------------
// Usage :	Event necessary to be able to record animations based on
//		the last update duration to start immediately the movement.
//		by multiplying this duration by the speed.
//------------------------------------------------------------------------------
// Class :	CATUpdateEvent
//		  CATTimeStampedEvent
//------------------------------------------------------------------------------

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"
#include "list.h"
#include "CATVizDuration.h"

class ExportedByCATVisFoundation CATUpdateEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

    CATUpdateEvent();
    virtual ~CATUpdateEvent();

    float TotalDuration;
    float cpuTotalDuration;
    float CullingDuration;	
    float cpuCullingDuration;
    float DrawDuration;		 
    float cpuDrawDuration;
    float OCullingDuration;
    float cpuOCullingDuration;
    float ODrawingDuration;
    float cpuODrawingDuration;
    float  nb_culling;
    float cullingThreadDuration[30];
    int   update_state;
    int   on_culling;

    list <CATVizDuration> durationList; 
};

#endif
