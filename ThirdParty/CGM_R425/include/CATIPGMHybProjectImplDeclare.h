#include "CATIPGMHybOperatorImpImplDeclare.h"

  // ---------- CATHybProject

/* Already defined in a parent class
  virtual int Run();
*/

  virtual void SetDomainToProject(CATDomain *iDomain);

  virtual void SetDomainSupport(CATDomain *iDomain);

/* Already defined in a parent class
  virtual double GetDistance(CATDomain *iDomainOfResultBody);
*/

  virtual void SetSuppressFlattenDomainMode(int yes_or_no);

  virtual int GetSuppressFlattenDomainMode() const;

  virtual void SetCoveredFaces(CATLISTP(CATFace) &iCoveredFaces);

  virtual int IsCoveredFacesActive() const;

  virtual void SetMaxDistanceValue(double iMaxDistance);

  virtual double GetMaxDistanceValue() const;

  virtual int IsMaxDistanceActive() const;

  virtual CATHybProjectionContext GetContext();

  virtual void SetContext(CATHybProjectionContext iContext);

  virtual void SetSimplificationMode(CATBoolean iSimplification);

  virtual CATBoolean GetSimplificationMode() const;

  virtual CATBoolean IsCompletelyLaidDown();

  virtual CATExtHybProject *GetHybProjectExtensible() const;

  virtual void SetNewSmoothing(CATLONG32 iSmooth);

  virtual void GetNewSmoothing(CATLONG32 &oSmooth);

  virtual void SetOutputWireCleaning3DMode(CATLONG32 iOutputWireCleaning3DMode);

  virtual void GetOutputWireCleaning3DMode(CATLONG32 &oOutputWireCleaning3DMode);

  virtual void SetExtrapolationMode(short iExtrapolationMode);

  virtual void GetExtrapolationMode(short &oExtrapolationMode);

