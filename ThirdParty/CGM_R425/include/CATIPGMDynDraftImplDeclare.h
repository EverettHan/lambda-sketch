#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATIPGMDynOperatorImplDeclare.h"

  // ---------- CATDynDraft

  virtual void Add(
    CATBody *iPartingElement,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil);

  virtual void Add(
    CATSurface *iPartingSurface,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil);

  virtual void Add(
    CATPlane *iPartingPlane,
    CATOrientation iPartingOrientation,
    CATBoolean iIsPartingUntil);

  virtual void AddLimiting(
    CATBody *iLimitingElement,
    CATOrientation iLimitingOrientation,
    CATBoolean iIsLimitingUntil);

  virtual CATOrientation GetCalculatedOrientationOnParting();

  virtual void Add(CATDynDraftDomain *iDraftDomain);

  virtual void Add(
    CATDynDraftDomain *iDraftDomain1,
    CATDynDraftDomain *iDraftDomain2,
    CATDynDraftBothSidesType iBothSidesType,
    double iIdealRadius);

  virtual void SetPrevisualizationOnly();

  virtual void SetPrevisualizationMode(CATDynDraftPrevisualization iMode);

  virtual void SetJunctionMode(CATBoolean iJunctionMode);

  virtual CATDynValidShellType ValidateShellOutput(CATLISTP(CATBody) &oListBody);

  virtual void SetJournalInfoMode(CATPGMDynDraftJournalInfoMode iInfoMode);

  virtual CATDynDraftFillFunction GetUntwistDraftFillFunction() const;

  virtual CATBoolean IsUntwistDraftFillFunctionUsed() const;

  virtual void SetUntwistDraftFillFunction(CATDynDraftFillFunction iFillFct);

  /* Already defined in a parent class
  virtual CATContextForFastRun *GetContextForFastRun(CATBoolean iGetOnly);
  */

  virtual CATDynDraftContextForFastRun *GetDynDraftContextForFastRun(
    CATBoolean iGetOnly);

#ifdef CATIACGMR214Code  
  virtual void SetInitialFacePropag( CATBoolean iActive);
#endif
  
  virtual void SetStepDraftMode( CATDynDraftStepDraftMode iStepDraftMode);



