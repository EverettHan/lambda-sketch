#ifndef CATSwapEvent_H
#define CATSwapEvent_H

//
// Copyright Dassault Systemes 2006

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"
#include "list.h"
#include "CATVizDuration.h"

class ExportedByCATVisFoundation CATSwapEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

  public :

    CATSwapEvent();
    virtual ~CATSwapEvent();

    list <CATVizDuration> durationList; 
};

#endif
