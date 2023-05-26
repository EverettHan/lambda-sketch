// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyFromRepBuilder.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Feb 2010 Creation:  zfi
// Oct 2022 JXO: SetEdgesImport
//===================================================================

#ifndef CATPolyBodyFromRepBuilder_H
#define CATPolyBodyFromRepBuilder_H

#include "CATPolyVisuBuildOper.h"
#include "CATErrorDef.h" // HRESULT
#include "CATListPV.h"
#include "CATBoolean.h"

class CATPolyBody;
class CATMapOfPtrToPtr;
class CAT3DRep;
class CATPolyBodyImportVizLayer;
class CATSurfacicRep;

class ExportedByPolyVisuBuildOper CATPolyBodyFromRepBuilder
{

  //constructor/destructor
public:
  CATPolyBodyFromRepBuilder();
  virtual ~CATPolyBodyFromRepBuilder();

public:
  HRESULT Build (const CAT3DRep& iRep, 
                 CATPolyBody*& oEditablePolyBody,
                 CATListPV& oNonImportedReps,
                 CATPolyBodyImportVizLayer* ioVizLayer = 0)const;

  inline HRESULT SetTolerance(const float iTolerance);

  //deperectated
public:
  HRESULT Build (const CATSurfacicRep& iRep,
                 CATPolyBody*& oPolyBody,
                 CATPolyBodyImportVizLayer* ioVizLayer = 0)const{return E_FAIL;}

  HRESULT Build (const CAT3DRep& iRep,
                 CATListPV& oPolyBodies,
                 CATListPV& oPositionMatrices,
                 CATPolyBodyImportVizLayer* ioVizLayer = 0)const{return E_FAIL;}

  // Import edges or not.
  // Default is enabled.
  inline HRESULT SetEdgesImport(int iEnable);

private:
  float _Tolerance;
  int _EdgesImport;
};

//inline
inline HRESULT CATPolyBodyFromRepBuilder::SetTolerance(const float iTolerance)
{
  _Tolerance = iTolerance;
  return S_OK;
}

inline HRESULT CATPolyBodyFromRepBuilder::SetEdgesImport(int iEnable)
{
  _EdgesImport = iEnable;
  return S_OK;
}

#endif
