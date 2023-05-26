// COPYRIGHT DASSAULT SYSTEMES 2003

//===================================================================
//===================================================================
//
// CATSelectCurveTool
// Choice of geometric representation
//
//===================================================================

//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb 2003    Creation                              SUH
//===================================================================
#ifndef CATSelectCurveTool_H
#define CATSelectCurveTool_H

class CATGeoFactory;
class CATTopData;
class CATEdge;
class CATCurve;

#include "AnalysisToolsLight.h"
#include "CATTopDef.h"
#include "CATTopData.h"

class ExportedByAnalysisToolsLight CATSelectCurveTool
{
public:
  CATSelectCurveTool(CATGeoFactory * iFacto, CATTopData * iData);
  virtual ~CATSelectCurveTool();
  virtual void GetCurve (CATEdge * iEdge, CATCurve * &oCurve, CATOrientation & oOrient);

public:
  CATGeoFactory * _InputFactory;
  CATTopData _TopData;
};

#endif
