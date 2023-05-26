// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFixSmallAngleTrianglesOper.h
// Header definition of CATPolyFixSmallAngleTrianglesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Jul 2004 Creation: dhp
//===================================================================
#ifndef CATPolyFixSmallAngleTrianglesOper_H
#define CATPolyFixSmallAngleTrianglesOper_H

#include "CATPolyRegularizeOperators.h"
#include "CATPolyModOper.h"

#include "CATListOfInt.h"
#include "CATBooleanDef.h"
#include "CATechExt.h"

class CATPolyFixSmallAngleTrianglesOperObserver;
class CATIPolyMesh;
class CATPolyBarCollapseOper;
class CATechExt_CATPolyFixSmallAngleTrianglesOper;
class CATPolyFace;
class CATIPolySurfaceVertexCellConstLayer;

class ExportedByCATPolyRegularizeOperators CATPolyFixSmallAngleTrianglesOper : public CATPolyModOper
{

public:

  CATPolyFixSmallAngleTrianglesOper ();
  ~CATPolyFixSmallAngleTrianglesOper (void);

  void SetTolerance (const double tolerance);

  void SetMesh (CATIPolyMesh* iMesh);

  // 3 Run methods needed for implementation of CATPolyModOper
  HRESULT Run ();

  HRESULT RunOnSelectedTriangles (const CATListOfInt & triangles);

  HRESULT RunOnSelectedTriangles (const CATListOfInt & triangles, CATListOfInt & decimatedTriangles);

  void GetSmallAngleTriangles (CATListOfInt & triangles);
  

  // Methods with cell layer: prevent modifying the macro topology.
  HRESULT Run (CATPolyFace * pFace);
  HRESULT RunOnSelectedTriangles (const CATListOfInt & triangles, CATPolyFace * pFace);
  HRESULT RunOnSelectedTriangles (const CATListOfInt & triangles, CATListOfInt & decimatedTriangles, CATPolyFace * pFace);



  //For internal use
public:
  inline void SetOperatorObserver (CATPolyFixSmallAngleTrianglesOperObserver* iObs);
  inline CATPolyFixSmallAngleTrianglesOperObserver* GetOperatorObserver () const;
  inline CATechExt *& GetPhoenixExtension() {return _PhoenixExtension;}

protected:
	
	// for phoneix
	CATPolyFixSmallAngleTrianglesOperObserver * _OperObserver;
  CATechExt * _PhoenixExtension;

private:

  void ConstructCollapser ();

  HRESULT InternalRun (const CATListOfInt & triangles,
    CATListOfInt & decimatedTriangles, CATPolyFace * pFace);

  void ClassifyTriangles (const CATListOfInt & triangles,
    CATListOfInt & trianglesToFlip,
    CATListOfInt & trianglesToBarCollapse) const;

  CATBoolean HasSmallAngle (const int triangle, double & smallest) const;

  void GetSmallAngleTriangles (const CATListOfInt & triangles,
    CATListOfInt & smallAngleTriangles);

  HRESULT CollapseBars (const CATListOfInt & trianglesToCollapse,
    CATListOfInt & decimatedTriangles, CATIPolySurfaceVertexCellConstLayer * pLayer);

  CATBoolean CollapseBar (CATListOfInt & triangles,
    const int triangle,
    CATListOfInt & decimatedTriangles, CATIPolySurfaceVertexCellConstLayer * pLayer);

  HRESULT FlipBars (const CATListOfInt & trianglesToFlip);

  CATBoolean OkToFlip (const CATListOfInt & smallAngleTriangles,
    const int triangle,
    int & vertexIndex,
    double & maxAngle) const;

  CATBoolean FlipBar (const int triangle,
    const int vertexIndex);

  double _angleTolerance;
  int _numTriangles;

  CATPolyBarCollapseOper * _BarCollapser;
};


inline void CATPolyFixSmallAngleTrianglesOper::SetOperatorObserver (CATPolyFixSmallAngleTrianglesOperObserver* iOperObserver)
{
  _OperObserver = iOperObserver;
}

inline CATPolyFixSmallAngleTrianglesOperObserver* CATPolyFixSmallAngleTrianglesOper::GetOperatorObserver () const
{
  return _OperObserver;
}
#endif

