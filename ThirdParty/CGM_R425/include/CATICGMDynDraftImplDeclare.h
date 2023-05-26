#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATICGMDynOperatorImplDeclare.h"

  // ---------- CATDynDraft

  virtual void Add(
    CATBody *iPartingElement,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil);

#ifdef CATIACGMV5R23
  virtual void AddLimiting(
    CATBody *iLimitingElement,
    CATOrientation iLimitingOrientation,
    CATBoolean iIsLimitingUntil);
#endif

  virtual void Add(CATDynDraftDomain *iDraftDomain);

  virtual void SetPrevisualizationOnly();

#ifdef CATIACGMV5R23
  virtual void SetPrevisualizationMode(CATDynDraftPrevisualization iMode);
#endif

  virtual void SetJunctionMode(CATBoolean iJunctionMode);

