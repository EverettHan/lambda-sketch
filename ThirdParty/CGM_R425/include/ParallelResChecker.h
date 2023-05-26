#ifndef ParallelResChecker_H
#define ParallelResChecker_H

// COPYRIGHT DASSAULT SYSTEMES 2004
#include "CATBoolean.h"
#include "CATListOfInt.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"

class CATSurface;
class CATEdge;
class CATFace;
class CATWire;
class CATBody;
class CATCGMJournalList;
class CATPlane;
class CATVertex;
class CATMathDirection;
class CATGeoFactory;
class CATSoftwareConfiguration;
//------------------------------------------------------------------------------

class ParallelResChecker{

  //Class restricted to ParallelResChecker
  //save some time by keeping memebers public
  class ParallelUnit{

    public:

    ParallelUnit(CATSoftwareConfiguration* iConfig, CATEdge* iEdge, CATFace* iFace, CATVertex* iVertex, CATBoolean isPrevSharp);

    ~ParallelUnit();
  
    void UpdateResult(CATWire* iParallelWire, CATListOfInt &iRanks);

    //returns TRUE if pcurves of the edgecurve are plines
    CATBoolean HasPLines(CATEdge* iEdge);

    void Init();

    CATEdge* _pEdge;//original planar edge
    CATFace* _pFace;//face defining shape of planar edge
    CATVertex* _pVertex;//previous vertex
    CATSurface* _pSurf;
    //_ParallelEdges [ _LowRank, _HighRank] are not G1 extrapolation edges, but are origianal parallel edges
    CATLONG32  _LowRank; //low rank of edge which is not a line
    CATLONG32  _HighRank; //high rank of edge which is not a line
    CATBoolean _IsPrevSharp; //if the vertex between previous ParallelResUnit and this ParallelResUnit is sharp in parallel input
    CATBoolean _IsG1ExtrPossible;//check if there is possibility of parallel performing G1 extrapolaion
    CATListOfInt _ParallelEdges;//ranks of result of parallel operation of _pEdge, sorted according to G0 continuity
    CATSoftwareConfiguration* _pConfig;
  };

  public:

  ParallelResChecker(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATSurface* iSupport, int iNumUnits);

  ~ParallelResChecker();

  //cannot call this after CheckResult is called
  CATBoolean AddParallelUnit(CATEdge* iEdge, CATFace* iFace, CATVertex* iVertex, CATBoolean isPrevSharp);

  //returns TRUE if the parallel result is OK
  CATBoolean CheckResult(CATBody* iInputBody, CATBody* iResultBody, CATCGMJournalList* iParallelJournal, double iOffset);

  private:

  //returns TRUE if the parallel result is OK even after usage of G1 extrapolation
  CATBoolean CheckG1Extrapolation(int iCurrIndex, int iPrevIndex);

  //create an circle at vertex tangent to given edge
  void CreateInstantaneousCircle(CATVertex* iVertex, CATEdge* iEdge, CATSurface* iSurface
                                ,CATMathPoint &oCircleCenter, double &oCircleRadius
                                ,CATMathDirection &oCircleAxis1, CATMathDirection &oCircleAxis2);

  void Init();

  int _NumUnits;
  int _NumAdded;
  CATLONG32 _NumEdgeResParallel; //number of edges in parallel result
  ParallelUnit** _pParallelUnits;
  CATGeoFactory* _pFactory;
  CATSoftwareConfiguration* _pConfig;

  CATWire* _pInputWire;
  CATWire* _pParWire;
  double _Offset;
  CATBoolean _ResRanksParallel; //True if parallel wire is oriented in the same sense as _pParallelUnits
  CATMathPoint _SuppPlaneOrigin;
  CATMathVector _SuppPlaneNormal;

};

#endif
