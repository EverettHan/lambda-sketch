// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyVisuMeshDecimateOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2010 Creation:  zfi
//===================================================================

#ifndef CATIPolyVisuMeshDecimateOper_H
#define CATIPolyVisuMeshDecimateOper_H

#include "CATPolyVisuDistiller.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATBoolean.h"
#include "CATVizPtrList.h"

class CAT3DRep;
class CATPolyBody;
class CATPolyCustomDecimationOper;
class CATPolyBodyImportVizLayer;

class ExportedByPolyVisuDistiller CATIPolyVisuMeshDecimateOper
{
  //constructor/destructor
public:
  CATIPolyVisuMeshDecimateOper(){}
  virtual ~CATIPolyVisuMeshDecimateOper(){}

public:
  //////////////////////
  //Init
  //Provide a 3D rep to join and decimate 
  //////////////////////
  virtual HRESULT Init(CAT3DRep& iRep)=0;

  //////////////////////
  //Run Simple
  //////////////////////
  virtual HRESULT Run(CAT3DRep*& oResultRep)=0;

  /////////////////////
  //Run Iterative
  ////////////////////
  // if returned result=S_FALSE, the end has been reached without further decimation of the model.
  // Percentage gives the percentage of decimation
  virtual HRESULT Step(float& oPercentage)=0;
  virtual HRESULT Finalize(CAT3DRep*& oResultRep)=0;

  //////////////////////
  //options
  //////////////////////
  // Configure the way operator will be used : 
  //     - iChordalDev : Chordal deviation in mm (computed by the application according to model size
  //     - iJoinTolerance : Tolerance used during join phase
  virtual HRESULT SetChordalDeviation(double iFaceChordalDeviation, double iEdgeChordalDeviation)=0;
  virtual HRESULT SetJoinTolerance(double iJoinTolerance)=0;

  //Freeze boundary bars exclude edge bars
  virtual HRESULT DoFreezeFreeBoundarBars(CATBoolean iFreezeFreeBoundarBars)=0;

  //////////////////////
  //version
  //////////////////////
  virtual HRESULT SetVersion(int iVersion)=0;
  virtual int GetVersion()const=0;
};

#endif
