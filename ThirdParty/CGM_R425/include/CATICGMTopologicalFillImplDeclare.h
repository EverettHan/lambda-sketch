#include "CATICGMTopOperatorImplDeclare.h"

  // ---------- CATTopologicalFill

/* Already defined in a parent class
  virtual int Run();
*/

  virtual double GetG0MaxDeviation();

  virtual CATAngle GetG1MaxDeviation();

  virtual double GetG0MaxAccuracy();

/* Already defined in a parent class
  virtual CATBody *GetResult();
*/

  virtual void SetInputValidationMode(const CATLONG32 iMode);

  virtual void SetTransitionContinuity(
    const CATLONG32 iWhichWire,
    const CATLONG32 iTransitionContinuity);

  virtual void GetCenterPoint(CATVertex &ioCenterPoint);

  virtual void SetCenterPoint(CATVertex &iCenterPoint);

  virtual void ResetCenterPoint();

  virtual void SetFlatFaceMode(const CATLONG32 iMode);

  virtual CATLONG32 Check();

  virtual CATTopologicalFillType GetFillType();

