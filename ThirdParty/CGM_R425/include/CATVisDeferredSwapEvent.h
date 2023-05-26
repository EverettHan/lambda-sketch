#ifndef CATVisDeferredSwapEvent_H
#define CATVisDeferredSwapEvent_H

// Copyright Dassault Systemes 2012

#include "CATTimeStampedEvent.h"
#include "CATVisFoundation.h"
#include "list.h"
#include "CATVizDuration.h"

class ExportedByCATVisFoundation CATVisDeferredSwapEvent : public CATTimeStampedEvent
{
  CATDeclareClass;

public :
    CATVisDeferredSwapEvent();
    virtual ~CATVisDeferredSwapEvent();

    bool refreshedVisu;

    list <CATVizDuration> durationList; 
};

#endif
