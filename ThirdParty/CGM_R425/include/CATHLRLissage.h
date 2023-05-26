#ifndef CATHLRLissage_h
#define CATHLRLissage_h


// COPYRIGHT DASSAULT SYSTEMES 1999

// for drafting

#include "HLRProject.h"

#include "CATListOfCATGeometries.h"
#include "CATListOfCATCrvLimits.h"
#ifndef PLATEFORME_DS64
#include "CATListOfInt.h"
#endif
#include "CATListPV.h"
#include "CATHLRPlanarProjection.h"
#include "CATHLRObjectLinker.h"

class CATPCurve;
class CATMathPoint;
class CATMathSetOfPointsND;

class CATHLRTopology;
class CATHLREdge;
class CATHLRProjection;
class CATHLRGeometry2DFactory;

struct CATHLRLissageData
{
  CATLONG32                  nSegments;
  CATMathPoint        * points;
  CATLISTP(CATGeometry) pcurves;
};

class ExportedByHLRProject CATHLRLissage 
{
public:
  /** Constructor
   */
  CATHLRLissage(CATHLRPlanarProjection*iProjection, 
                double iSag=0.);

  /** Destructor
   */
  ~CATHLRLissage();

  /** Adds edge or face data
   * iHLRCell     is an HLREdge or an HLRFace
   * iNSeg        is the number of segments
   * iPoints      is an array of segment extremities and is 2*iNSeg points CATLONG32
   * isVisible    tells if the segments are visible (1) or hidden (0)
   * isSilhouette tells if the segments are part of a silhouette 
   *              and must be 1 if iHLRCell is a HLRFace
   */
  void Add(CATHLRTopology * iHLRCell, 
           CATLONG32             iNSegments, 
           CATMathPoint   * iPoints, 
           int              iIsVisible=1, 
           int              iIsSilhouette=0);

  /** Retrieves all the created pcurves
   */
  void GetResult(CATLISTP(CATGeometry)&oPCurves);

  /** Retrieves the pcurves associated to an element
   */
  void GetResult(CATHLRTopology       * iHLRCell, 
                 CATLISTP(CATGeometry)& oVisibleCurves,
                 CATLISTP(CATGeometry)& oVisibleSilhouettes,
                 CATLISTP(CATGeometry)& oHiddenCurves,
                 CATLISTP(CATGeometry)& oHiddenSilhouettes);

  /** Removes inacurate geometry from projection overlaps
   */
  void Rasage();

  /** For debugging
   */
  static int DebugLissage;
  
protected:  

  CATHLRPlanarProjection  *_planarProjection;
  CATHLRGeometry2DFactory *_factory2D;
  // CATHLRProjection        *_projection;
  
#ifdef PLATEFORME_DS64
  CATListPV                _segments;
#else
  CATListOfInt             _segments;
#endif
  double                   _resolution;
  double                   _sag;
  CATHLRObjectLinker       _visibleCurves;
  CATHLRObjectLinker       _silhouetteCurves;

  void BuildSegments(CATLONG32 iNSegments, CATMathPoint*iPts);

  void SplitSegments();

  void ChainSegments();

  void EraseSegments();

#ifdef PLATEFORME_DS64
  void LisseSegments(const CATListPV&iSegments, 
                     const CATListOfInt&iSides, 
                     int   iIdxClose);

  int  AddSegmentsToChain(const CATListPV&   iSegments, 
                          CATListPV&         ioChain, 
                          CATListOfInt&      ioSides, 
                          int                iFromSide);
#else
  void LisseSegments(const CATListOfInt&iSegments, 
                     const CATListOfInt&iSides, 
                     int   iIdxClose);

  int  AddSegmentsToChain(const CATListOfInt&iSegments, 
                          CATListOfInt&      ioChain, 
                          CATListOfInt&      ioSides, 
                          int                iFromSide);
#endif


  void CreatePLines  (const CATMathSetOfPointsND & iPoints);

  void RelimitEdgeProjection(const CATMathSetOfPointsND& iSetOfPts, int iIsClosed);
  
  int  IsVisible(CATPCurve * iPCurve);
  int  IsSilhouette(CATPCurve * iPCurve);
  void PCurveIsVisible(CATPCurve * iPCurve, int iFlag);
  void PCurveIsSilhouette(CATPCurve * iPCurve, int iFlag);
  void MergePCirclesOnEdge(CATHLREdge * iEdge);
  
  CATListPV          _hlrElements;
  CATHLRObjectLinker _hlrElementsData;
  CATHLRTopology    *_curElement;
  int                _curIsVisible;
  int                _curIsSilhouette;
  CATPCurve         *_curPCurve;
  int                _curPCurveShouldBeCloned;
};

#endif

