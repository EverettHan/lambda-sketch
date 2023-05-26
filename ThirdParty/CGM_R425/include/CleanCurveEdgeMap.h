// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CleanCurveEdgeMap :
// Utility class to store mapping between original wire and cleaned wire...
// currently used for Parallel Operator
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 2003  Creation                          SUH
//=============================================================================
#ifndef CleanCurveEdgeMap_H
#define CleanCurveEdgeMap_H

#include "AnalysisToolsLight.h"


class CATEdge;

#include "CATCrvLimits.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"


class ExportedByAnalysisToolsLight CleanCurveEdgeMap
{
public:
  CleanCurveEdgeMap( CATEdge * iEdge3D, const CATCrvLimits &iCrv3DLims, CATEdge * iEdge2D, 
           const CATLISTP(CATCell) &iSuppFaces, const CATListOfInt &iOriSurVsShell, CATEdge * iPrevEdge2D = NULL );

  virtual ~CleanCurveEdgeMap();

  CATEdge * GetEdge2D();
  CATListOfInt GetFaces(CATLISTP(CATCell) &oSuppFaces);
  CATEdge * GetEdge3D(CATCrvLimits * oLims3D = 0);
  void SetEdge3D(CATEdge * iEdge3D, const CATCrvLimits &iLims3D);
  CATEdge * GetPrevEdge();

private:
  CATEdge * _Edge3D;
  CATCrvLimits _Crv3DLims;
  
  CATEdge * _Edge2D;
  CATLISTP(CATCell) _SuppFaces;
  CATListOfInt _OriSurVsShell;
  //REN Sep 12'05
  CATEdge * _PrevEdge2D;

};

#endif
