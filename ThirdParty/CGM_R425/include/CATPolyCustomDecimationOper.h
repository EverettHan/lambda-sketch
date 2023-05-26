// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyCustomDecimationOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Mars 2009 : ZFI
//===================================================================

#ifndef CATPolyCustomDecimationOper_h
#define CATPolyCustomDecimationOper_h

#include "CATPolyDecimateOperators.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATPolyBaseOper.h"
#include "CATListPV.h"


class CATPolyBody;
class CATIPolyMesh;
class CATPolyCustomDecimationAreaObserver;
class CATPolyBarCollapseBase;

class ExportedByCATPolyDecimateOperators CATPolyCustomDecimationOper : public CATPolyBaseOper
{
public:
  CATPolyCustomDecimationOper ();
  virtual ~CATPolyCustomDecimationOper ();

public:
  HRESULT AddPolyBody(CATPolyBody* iPolyBody);

  int GetMaxLevel()const{return _MaxLevel;}
  HRESULT SetMaxLevel(int iMaxLevel);//accepted values : MaxLevel>=0 and MaxLevel<=10, default 4


  HRESULT SetAutoMode(const int iLevel);

  /*AutoMode
  iBeginningLevel : between 0 and MaxLevel  
  iMaxNbTriangles :  nb target triangles
  */
  HRESULT SetAutoMode(const int iBeginningLevel, 
                      const int iTargetNbTriangles);

  HRESULT SetChordalDeviationMode(const double iChordalDev,  
                                  const double iChordalDevEdges);
  HRESULT SetFreezeNonEdgeFreeBars(CATBoolean iFreezeNonEdgeFreeBars);

  HRESULT SetWithAreaObserver(CATBoolean iWithAreaObserver);

  HRESULT Run();

private:
  CATPolyBarCollapseBase*  ConstructCollapser (CATIPolyMesh& ioMesh) ;

  HRESULT RunOnPolyBody (CATPolyBody& ioPolyBody);
  HRESULT RunOnPolyMesh (CATIPolyMesh& ioPolyMesh);

  HRESULT UpdateChordalDev();
  HRESULT UpdateBoundingSize();
  HRESULT UpdateNumberOfTriangles();
  
  HRESULT UpdateScales(CATIPolyMesh& ioMesh,
                       const double iChordalDeviation,
                       double& oNormalScaling,
                       double& textureCoordsScaling);
private:
  CATListPV _PolyBodies;
  
  int _MaxLevel;
  int _Level;

  double _MaxSize;

  int _NbTriangles;
  int _TargetNbTriangles;
  
  int _DecimationMode;
  
  CATBoolean _WithAreaObserver;
  CATBoolean _FreezeNonEdgeFreeBars;

  double  _ChordalDeviation;
  double  _ChordalDeviationForFreeBars;

  CATPolyCustomDecimationAreaObserver* _AreaObserver;
  
};

#endif
