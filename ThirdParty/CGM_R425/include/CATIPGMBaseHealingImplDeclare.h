#include "CATIPGMTopOperatorImplDeclare.h"

  // ---------- CATBaseHealing

  virtual int SetBodyToHeal(CATBody *iBodyToHeal);

/* Already defined in a parent class
  virtual void SetFreezeMode(CATBodyFreezeMode iFreezeMode);
*/

  virtual int SetGlobalContinuity(const short iOrder);

  virtual void SetG0Tolerance(const double iTolG0);

  virtual void SetMaxG0Tolerance(const double iTolG0Max);

  virtual void SetMaxG1Tolerance(const double iTolAngular);

  virtual void SetG1Tolerance(const double iTolAngular);

  virtual void SetSharpnessTolerance(const double iTolSharpness);

  virtual int Add(CATEdge *iE, const short iOrder);

  virtual int SetFace(
    CATFace *iF,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree);

  virtual int SetFace(
    const CATLISTP(CATFace) &iListOfFaces,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree);

  virtual int SetFace(
    const CATGeometricType iType,
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree);

  virtual int SetCanonic(
    const CATBoolean iIsGeomFree,
    const CATBoolean iIsTypeFree);

  virtual int SetEdge(CATEdge *iE, const short iOrder);

  virtual int SetEdge(const CATLISTP(CATEdge) &iListOfEdges, const short iOrder);

  virtual int SetAdjustPCurve(const short iAdjustPCurve);

  virtual int Add(
    CATVertex *iVertexToHeal,
    CATEdge *iEdgeToFix,
    const short iOrder);

  virtual int SetVertex(
    CATVertex *iVertexToFix,
    CATEdge *iEdge,
    const short iOrder);

  virtual void SetMaxIter(const int iMaxIter);

  virtual double G0MaxError();

  virtual double G1MaxError();

  virtual CATBoolean IsSatisfied();

  virtual int G0MaxError(CATEdge *iE, double &ioG0Error);

  virtual int G1MaxError(CATEdge *iE, double &ioG1Error);

  virtual int IsSatisfied(CATEdge *iE, CATBoolean &ioIsSatisfied);

  virtual int GetOpenEdges(CATLISTP(CATEdge) &ioListOfEdges);

  virtual int GetSharpEdges(CATLISTP(CATEdge) &ioListOfEdges);

  virtual int GetMaxDeformationOnEdge(CATEdge *iE, double &oMaxDef);

  virtual int GetAutoMaxShapeDeformation(double &oMaxDef);

