#ifndef CATOracleObject_H
#define CATOracleObject_H
//=============================================================================
// COPYRIGHT Dassault Systemes 2003, 2004
//=============================================================================
//
// CATOracleObject.h
// 		
//=============================================================================
//  Oct 2003  Creation: JHG
//=============================================================================

#include "CATTopRibTraceObject.h"
#include "CATThrowForNullPointer.h"
#include "CATCGMNewArray.h"
#include "CATTopRibDef.h"
#include "CATDerefMacros.h"
#include "CATPersistentImplCell.h"
#include "CATMathInline.h"

#include "CFSEngine.h"

class CATTopOracle;

class ExportedByCFSEngine CATOracleObject: public CATTopRibTraceObject
{
public:
  CATCGMNewClassArrayDeclare; // Pool allocation

public:
  CATOracleObject(CATTopOracle &iOracle);
  virtual ~CATOracleObject();

  INLINE CATTopOracle *GetOracle() const;
  INLINE CATTopOracle &Oracle() const;

  DEFINE_ADVOP_CLASS(CATOracleObject)

public:
  void AutoFilletTrace(const char *iTxt, int iCritical = 0);
  void AutoFilletInternalError() const;

  CATCartesianPoint *ShowPoint(const CATMathPoint &iPoint, const CATAutoBaseColor &iColor);
  CATLine *ShowLine(const CATMathPoint &iStart, const CATMathPoint &iEnd, const CATAutoBaseColor &iColor);
  CATAutoBaseGeometryContainer *ShowVector(const CATMathPoint &iPoint, const CATMathVector &iVector, const CATAutoBaseColor &iColor, CATBoolean iDisplayCone = 1);
  CATAutoBaseGeometryContainer *ShowTriangle(const CATMathPoint &iP0, const CATMathPoint &iP1, const CATMathPoint &iP2, const CATAutoBaseColor &iColor);
  CATSphere *ShowSphere(const CATMathPoint &iPoint, double iRadius, const CATAutoBaseColor &iColor);
  CATAutoBaseGeometryContainer *ShowAABB(const CATMathBox &iAABB, const CATAutoBaseColor &iColor);
  CATAutoBaseGeometryContainer *ShowOBB(const CATMathBox &iAABB, const CATMathTransformation &iLocalToGlobal, const CATAutoBaseColor &iColor);

private:
  CATTopOracle &_Oracle;

#ifdef CATORACLEOBJECTMLKSHIELD
  CATTopRibMLKShield *_OracleObjectMLKShield;
#endif
};

INLINE
CATTopOracle *CATOracleObject::GetOracle() const
{
  return & _Oracle;
}

INLINE
CATTopOracle &CATOracleObject::Oracle() const
{
  return _Oracle;
}

#endif // !CATOracleObject_H
