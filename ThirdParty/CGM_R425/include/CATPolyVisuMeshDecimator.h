// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuMeshDecimator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2010 Creation:  zfi
//===================================================================

#ifndef CATPolyVisuMeshDecimator_H
#define CATPolyVisuMeshDecimator_H

#include "CATPolyVisuDistiller.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"
#include "CATVizPtrList.h"

class CAT3DRep;

class CATechExt;

class ExportedByPolyVisuDistiller CATPolyVisuMeshDecimator
{
  //constructor/destructor
public:
  CATPolyVisuMeshDecimator();
  virtual ~CATPolyVisuMeshDecimator();

public:
  //////////////////////
  //Run Simple
  //////////////////////
  HRESULT Run(CAT3DRep* iRep, CAT3DRep*& oResultRep);

  /////////////////////
  //Run Multi
  ////////////////////
  HRESULT Run(CATVizPtrList<CAT3DRep>& iReps, CAT3DRep*& oResultRep);

  //////////////////////
  //options
  //////////////////////
  inline HRESULT SetChordalDeviation(double iChordalDev){_MaxDeviation=iChordalDev;if (_MaxDeviation)_AutoMode=0; return S_OK;}
  inline double GetChordalDeviation()const{return _MaxDeviation;}

  inline HRESULT CreateTopology(int iActivate=1) {_CreateTopology=iActivate;return S_OK;}
  inline int GetCreateTopology()const{return _CreateTopology;}

  inline HRESULT SetVersion(int iVersion){_Version=iVersion;return S_OK;}
  inline int GetVersion()const{return _Version;}

public:
  //deprecated
  HRESULT Run(const CAT3DRep* iRep, double iChordalDeviation, CAT3DRep*& oResultRep){return E_FAIL;}
  inline HRESULT ActivatePolyBody(CATBoolean iActivate=1) {return E_FAIL;}

public:
  //////////////////////
	// Phoenix extension
	//////////////////////
	void SetPhoenixExtension (CATechExt* iExtension, CATBoolean iDeleteBuilder = FALSE);
	CATechExt* HasPhoenixExtension (CATBoolean iForceCreation = FALSE);

private:
  CAT3DRep* GetResultRep(){return _ResultRep;}
  CATVizPtrList<CAT3DRep>& GetInputReps(){return _InputReps;}
  friend class CATPolyVisuMeshDecimator_CATechExt;

private:
  HRESULT RunOnPolyMesh(CATVizPtrList<CAT3DRep>& iReps, CAT3DRep*& oResultRep);
  HRESULT RunOnPolyBody(CATVizPtrList<CAT3DRep>& iReps, CAT3DRep*& oResultRep);
  HRESULT RunOnBarGraph(CATVizPtrList<CAT3DRep>& iReps,  CAT3DRep*& oResultRep);

private:
  CATBoolean _CreateTopology;
  CATBoolean _AutoMode;
  int _Version;
  double _MaxDeviation;
  
  CATVizPtrList<CAT3DRep> _InputReps;
  CAT3DRep* _ResultRep;

  // Phoenix Handle
	CATechExt* _PhoenixExtension ;
};

#endif
