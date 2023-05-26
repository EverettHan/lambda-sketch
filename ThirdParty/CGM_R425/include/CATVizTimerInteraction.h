#ifndef CATVIZTIMERINTERACTION_H
#define CATVIZTIMERINTERACTION_H

// COPYRIGHT DASSAULT SYSTEMES 2004

//==============================================================================
// Inheritance
// -----------
// CATVizTimerInteraction
//
//==============================================================================

#include "SGInfra.h"
#include "IUnknown.h"
#include "CATLib.h"
#include "CATDataType.h"
#include "CATMutex.h"

class DSYSysTimer;

class ExportedBySGInfra CATVizTimerInteraction
{
  public :

    CATVizTimerInteraction();
    virtual ~CATVizTimerInteraction();

    virtual HRESULT StartInteraction(const char* iInteractionName);
    virtual HRESULT StopInteraction(CATULONG32 &cpu_time, CATULONG32 &elapsed_time);

    const char* GetInteractionName();

  protected :

    DSYSysTimer * _Timer;

    char* _InteractionName;

    static CATMutex _InteractionMutex;
};

#endif


