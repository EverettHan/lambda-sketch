//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSCurveCGMImp.h
// Implementation of CATCSCurveCGMImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// June 2005  Creation                                          FCX
//===================================================================

#ifndef CATCSCurveCGMImp_H
#define CATCSCurveCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"
#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATCrvLimits.h"
#include "CATMathVector.h"
#include "CATMath3x3Matrix.h"
#include "CATCSSkinWireImpEnums.h"

class CATSoftwareConfiguration;
class CATEdge;
class CATBody;
class CATEdgeCurve;
class CATVertex;
class CATGeoFactory;
class CATCurve;
class CATMathPoint;
class CATCGMStream;

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATCSCurveCGMImp
{
public:

  // Object management

  // iPropagationMode   0 : G0 propagation (only on wire)
  //                    1 : G1 propagation
  //                    2 : G2 propagation
  //                    3 : G1 propagation on bifurcation, G0 propagation otherwise

  CATCSCurveCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATEdge * iEdge, CATBody * iBody, int iPropagationMode, int iTestMode = 0);
  CATCSCurveCGMImp(const CATCSCurveCGMImp & iCurveCGMImp);
  virtual ~CATCSCurveCGMImp();

  // Implementation methods

  CATCSCrvParamType GetLimits(double &oLow, double &oUp);

  CATBoolean IsPlanar(double oPlaneCoords[6], double iTolerance);

  void Evaluate(double iT,
                double* oaPoint,
                double* oaFirstDeriv,
                double* oaSecondDeriv,
                double* oaThirdDeriv = 0);

  int GetNbOfDiscontinuities();

  void GetDiscontinuitiesParams(double *oaValues);

  void EvaluateAtDiscontinuity(int iIdx,
                               CATCSDiscontinuitySide iSide,
                               double iT,
                               double* oaPoint,
                               double* oaFirstDeriv,
                               double* oaSecondDeriv,
                               double* oaThirdDeriv = 0);

  void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]);

  // Specific methods of CATCSCurveCGMImp

  int ComputeDistanceMin(CATMathPoint * iPoint, double & oParam);
  int ComputeDistanceMin(CATCSCurveCGMImp * iCrv, double & oParam1, double & oParam2);
  int ComputeDistanceMin(CATCurve * iCrv, CATCrvLimits & iLimits, double & oParam, double & oLocalCrvParam, double & ioDMin);

  inline CATGeoFactory* GetGeoFactory() {return _pFactory;}

  // FCX 10.2010 : for debug only
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, int & oNbCurves, CATCurve **& oCurveTable, unsigned int & oIndex);

  // FCX 07.2014 : new stream architecture for EK
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

private:

  void ComputeDataModel();
  void ComputeDiscontinuities();
  void GlobalToLocalParam(double iGlobalT, double & oLocalT, CATLONG32 & oCurveNumber);
  void LobalToGlobalParam(double iLocalT, CATLONG32 iCurveNumber, double & oGlobalT);
  CATLONG32 FindVertex(CATVertex * iVertex, CATVertex ** iVertexList,CATLONG32 iNbVertices);
  CATLONG32 FindEdge(CATEdge * iEdge, CATEdge ** iEdgeList, CATLONG32 iNbEdges);

  void AddInLinkedEdgesTable( CATLONG32 iEdge, int iOrientation, CATLONG32 & ioNbEdges,
                              CATLONG32 *& ioEdgeList, int *& ioOrientationList);

  CATBoolean NextPropagationEdge( int & ioDirection, CATLONG32 & ioEdgeIndex,
                                  CATLONG32 * iIndexVertexS, CATLONG32 * iIndexVertexE,
                                  CATLONG32 * iNbLinkedEdges, CATLONG32 ** iLinkedEdges,
                                  int ** iLinkedEdgesOrient, 
                                  CATEdge ** iEdgeList, CATVertex ** iVertexList);

  CATBoolean CheckPropagation( CATEdge * iEdge1, int o1, CATEdge * iEdge2, int o2);

  int ComputeConnexionContinuity(CATEdgeCurve * iEC1, double iW1, int iOrientation1, CATEdgeCurve * iEC2, double iW2, int iOrientation2);

  // Debug methods

  void Dbg_DisplayDataModelInformation(CATEdge ** iEdgeTable);

  // Data

  CATSoftwareConfiguration  * _pConfig;
  CATGeoFactory             * _pFactory;
  CATBody                   * _pBody;
  CATEdge                   * _pEdge;

  CATEdgeCurve ** _pCurveTable;
  int           * _pOrientationTable;
  double        * _pCurveLowTable;
  double        * _pCurveHighTable;
  double        * _pGlobalParamTable;
  int           * _pContinuity;
  CATLONG32       _NbCurves;
  CATLONG32       _NbDiscontinuities;

  CATBoolean      _Closed;

  int    _PropagationMode; // 0 : G0, 1 : G1, 2 : G2, 3 : G0 + G1 on bifurcations
  double _G1Tolerance;
  double _G1ToleranceGeo;

  // Positionning transformation
  CATMathVector     _T;
  CATMath3x3Matrix  _R;

  int _TestMode;
};

//-----------------------------------------------------------------------

#endif
#endif
