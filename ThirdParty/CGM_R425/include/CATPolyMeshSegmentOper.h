// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshSegmentOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Aug 2007  Creation: ZFI
//===================================================================

#ifndef CATPolyMeshSegmentOper_H
#define CATPolyMeshSegmentOper_H

#include "CATPolySegmentOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATListOfInt.h"


class CATIPolyMesh;
class CATPolyFacetsPatch;
class CATPolyFrontsPropagation;
class CATPolyFacetsPropagation;
class CATPolyIntegerSetPartition;
class CATPolySegmentOperOptions;
class CATPolySegmentOperData;
class CATPolySharpSegmentOperMain;
class CATPolySegmentOperMain;
class CATPolySegmentLayer;

class ExportedByCATPolySegmentOperators CATPolyMeshSegmentOper : public CATPolyAnalyzeOper
{

public:
  //constructor and destrcutor
  CATPolyMeshSegmentOper ();
  virtual ~CATPolyMeshSegmentOper ();

  //main method
  HRESULT Set(CATIPolyMesh &iMesh,
              const CATListOfInt& iIdxSeeds, 
              CATPolyIntegerSetPartition* iFacetPartition);

  HRESULT Run();
  HRESULT FillSegmentLayer(CATPolySegmentLayer& ioSegmentLayer);

  CATPolyFrontsPropagation* GetFrontsPropagation();
  CATPolyFacetsPropagation* GetFacetsPropagation();

  HRESULT Clear();


  //set options
  HRESULT SetSharpEdges(int iSharpEdges);
  HRESULT SetUpdateSeed(int iUpdateSeed);
  HRESULT SetFarthestNewSeed(int iFarthestNewSeed);
  HRESULT SetMaxNbPatchs(int iMaxNbPatchs);
  HRESULT SetMaxFitting(double iMaxFitting);
  HRESULT SetDefaultFitting(double iDefaultFitting);
  HRESULT SetOldAlgo(int iOldAlgo);

private:
  CATPolySegmentOperOptions* _Options;
  CATPolySegmentOperData* _Data;
  CATPolySharpSegmentOperMain* _Segmenter;
  CATListOfInt _Seeds;

};

#endif
