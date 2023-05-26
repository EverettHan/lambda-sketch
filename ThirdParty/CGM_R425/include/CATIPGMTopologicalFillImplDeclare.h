#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATTopologicalFill

/* Already defined in a parent class
  virtual int Run();
*/
  
  virtual void SetCanonicalDetection();

  virtual double GetG0MaxDeviation();

  virtual CATAngle GetG1MaxDeviation();

  virtual double GetG2MaxDeviation();

  virtual double GetG0MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint);

  virtual CATAngle GetG1MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint);

  virtual double GetG2MaxDeviation(
    const CATEdge *iEdge,
    CATMathPoint *ioMaxPoint);

  virtual double GetG0MaxAccuracy();

/* Already defined in a parent class
  virtual CATBody *GetResult();
*/

  virtual void SetInputValidationMode(const CATLONG32 iMode);

  virtual void SetTransitionContinuity(
    const CATLONG32 iWhichWire,
    const CATLONG32 iTransitionContinuity);

  virtual void SetSimplifyOption(CATBoolean iSimplify);

  virtual void SetTangencyParameter(
    const CATLONG32 iside,
    const double iTangencyParameter);

  virtual void GetCenterPoint(CATVertex &ioCenterPoint);

  virtual CATBoolean IsCenterPointCreated() const;

  virtual void SetCenterPoint(CATVertex &iCenterPoint);

  virtual void ResetCenterPoint();

  virtual void SetFlatFaceMode(const CATLONG32 iMode);

  virtual void SetLinkedTopology(const CATLONG32 iLevel);

  virtual void SetBody(CATBody *ioBody, CATShell *ioShell);

  virtual void OrientationByFirstEdge();

  virtual void AddInnerWires(
    CATLISTP(CATBody) const &iListOfWires,
    CATLISTP(CATBody) const &iListOfSupports,
    CATListOfInt &iListOfInnerTransitionContinuity);

  virtual void SetPassingCurves(CATLISTP(CATBody) const &iListOfWires);

  virtual void SetPassingPoints(CATLISTP(CATBody) const &iListOfVertices);

  virtual void SetGapTolerance(const double iTolerance);

  virtual void SetSurfaceParameters(
    int iDegreeU,
    int iDegreeV,
    int iNumberUOfPatch,
    int iNumberVOfPatch);

  virtual void GetSurfaceParameters(
    int &oDegreeU,
    int &oDegreeV,
    int &oNumberUOfPatch,
    int &oNumberVOfPatch);

  virtual void UsingCommonSupport();

  virtual CATLONG32 GetLinkedTopology() const;

  virtual CATLONG32 Check();

  virtual CATTopologicalFillType GetFillType();

