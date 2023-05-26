#ifndef CATVIZPERFOINTERACTION_H
#define CATVIZPERFOINTERACTION_H

// COPYRIGHT DASSAULT SYSTEMES 2003

//==============================================================================
// Inheritance
// -----------
// CATVizPerfoInteraction
//
//==============================================================================

#include "SGInfra.h"
#include "CATVizTimerInteraction.h"

class ExportedBySGInfra CATVizPerfoInteraction : public CATVizTimerInteraction
{
  public :

    CATVizPerfoInteraction();
    virtual ~CATVizPerfoInteraction();

    virtual HRESULT StartInteraction(const char* iInteractionName);
    virtual HRESULT StopInteraction(CATULONG32 &cpu_time, CATULONG32 &elapsed_time);

    HRESULT GetMemoryUsed(CATULONG32 &memory_used);
};

#endif


