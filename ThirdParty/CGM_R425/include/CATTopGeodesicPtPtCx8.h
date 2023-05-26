//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2001 
//=========================================================================
//
// CATGeodesicPtPtCx8:
// Implementation of the Geodesic Point Point.
//
//=========================================================================
//
// Usage notes:
//
//========================================================================= 
// October 01     Creation                       AOV JHN
//=========================================================================

#ifndef CATTopGeodesicPtPtCx8_H
#define CATTopGeodesicPtPtCx8_H

#include "CATTopGeodesicPtPt.h"
#include "CATMathVector.h"
#include "CATListOfCATSurParams.h"
#include "AdvTopoSketchLight.h"

class CATDomain;
class CATLISTP(CATFace);
class CATWire;
class CATMathVector;
class CATMathPoint;
class CATSurParam;
class CATPoint;
class CATFace;

//-----------------------------------------------------------------------------
class ExportedByAdvTopoSketchLight CATTopGeodesicPtPtCx8 : public CATTopGeodesicPtPt
{
public :

  CATTopGeodesicPtPtCx8(CATGeoFactory * iFacto, CATTopData *iData, CATBody * iPtOrig, CATBody * iPtFin, CATBody * iShellSupport);
  virtual              ~CATTopGeodesicPtPtCx8()  ;

  virtual int          Run();
  virtual CATBody *    GetResult(CATCGMJournalList * iJourn) ;
  virtual CATBody *    GetResult() ;

  virtual int          SetParam(CATMathVector & ivect,double ilength,CATLONG32 iinversion);
  virtual int          GetParam(CATMathVector & ioDir,double & ioLength,CATLONG32 & ioinversion);

  virtual int          SetLength(double ilength1=0,double ilength2=0);

  // EQT
  virtual void         SetTolerance(double itolerance);

  //IZE
  void                 SetMeasureCrossedGaps(int iMeasureCrossedGaps);
  void                 SetCrossedGaps(double * ioCrossedGaps);

  //KY1 : 10-12-2010
  /**	@nodoc @nocgmitf */ 
  static const  CATString  *GetDefaultOperatorId();

protected:

  /**	@nodoc @nocgmitf */
  int RunOperator();
  /**	@nodoc @nocgmitf */
  static  CATString  _OperatorId;
  /**	@nodoc @nocgmitf */
  const  CATString  *GetOperatorId();
  /** @nodoc @nocgmitf */
  void   RequireDefinitionOfInputAndOutputObjects();

private :

  CATError *  ComputeInit(CATGeoFactory * iFacto, CATTopData * iData,
                          CATBody * iOrig,CATBody * iFin,CATBody * iOrigPose,CATBody * iFinPose,
                          CATBody *& oResult);

  CATError *  CompleteIntersectionByBoundary(CATGeoFactory * iFacto, CATTopData * iData,
                                             CATBody * iOrig, CATBody * iFin,
                                             CATBody * iOrigPose,CATBody * iFinPose,
                                             CATBody *& oResult, CATBody *& point2,
                                             CATBody *& BoundWire,CATBody *& bodywire2);

  CATError *  SplitGeodesic(CATGeoFactory * iFacto,CATTopData * iData,
                            CATBody * iOrig,CATBody * iFinPose,CATMathPoint & iMathOrig,
                            CATBody * iNewBody,CATBody *& oResult);

  CATError *  AlgoGeodesicPtPt(CATGeoFactory * iFacto, CATTopData * iData,
                               CATBody * iOrig,CATBody * iFin,
                               CATBody * iOrigPose,CATBody * iFinPose, 
                               CATBody *& oResult,CATPoint *& oPointOfBestGeod,
                               CATBody *& oBestGeod,double & obestdistance);

  CATError * SearchBestPoints(CATGeoFactory * iFacto,CATTopData * iData,
                              CATBody * iResultInter1,CATBody * iResultInter2, CATBody * iSupport,
                              CATDomain *& ioDom1,CATDomain *& ioDom2,double & length);

  int        ComputeSmallestDisconnect(CATGeoFactory * iFacto,CATTopData * iData,CATDomain * iPt1,
                                       CATDomain * iPt2,CATBody * iBodyToDisconnect,CATBody *& oSplitBody,
                                       double & lengthwire);

  int        ComputeLengthWire(CATTopData * iData,CATDomain * iWireResult,double & olengthwire);

  int        RetrieveSurParam(CATGeoFactory * iFacto, CATTopData * iData, 
                              CATBody * iOrig,CATLISTP(CATFace) & oListOfFaces,
                              CATSurParam *& oListOfPtParam);

  int        ComputeTangentOfWire(CATWire * iLine,CATBody * iOrig,CATBody * iFin,
                                  CATMathVector & oResultTangent);

  int        ComputeGeodesic(CATGeoFactory * iFacto,CATTopData * iData,
                             CATMathVector & iTangent,double ilength,CATGeometry * iFace,
                             CATSurParam & iParam,CATBody * iFin,CATBody *& oResult,
                             double &odist,CATPoint *& oPtResult,CATBody * iOrig=NULL);

  void       BuildJourn(CATCGMJournalList * iJourn);

  CATError * NewAlgoGeodesicPtPt(CATGeoFactory * iFacto, CATTopData * iData,
                                 CATBody * iOrig, CATBody * iFin,
                                 CATBody * iOrigPose,CATBody * iFinPose,
                                 CATBody *& oResult,double & obestdistance);

  CATError * NewComputeGeodesic(CATGeoFactory * iFacto,CATTopData * iData,
                                CATMathVector & iTangent,double ilength,
                                CATGeometry * iFace,CATSurParam & iParam,
                                CATBody * iIntersectBody,CATBody * iPoint,
                                CATBody *& oResult,double &olength,CATPoint *& oPtResult,
                                CATBody * WiretoIntersect=NULL);

  CATError * AlgoNewton(CATGeoFactory * iFacto,CATTopData * iData,
                        CATBody * iOrig, CATBody * iFin,
                        CATBody * iOrigPose,CATBody * iFinPose,
                        CATMathVector & NormaleOrig,
                        CATFace * iFace,CATSurParam & iPtParam,int InitSens,
                        CATBody *& ioBestGeod ,CATPoint *& ioPointOfBestGeod, 
                        double & ioBestDistance);

  CATBody * IntersectShellByPlane(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iOrig,
                                  CATBody * iFin,CATBody * iOrigPose);

  CATBody * RelimitateIntersection(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iOrig,
                                   CATBody * iOrigPose,CATBody * iFinPose,CATBody * volatile bodywire[2],
                                   CATBody * volatile & SplitBody);



  CATBody           * _Orig;
  CATBody           * _Fin;
  CATBody           * _Support;
  CATCGMJournalList * _JournResult;
  CATMathVector       _StartTangent;
  CATMathVector       _BestInit;
  double              _LengthOfGeod;
  double              _Resolution;
  CATLONG32           _IsGetted;
  CATLONG32           _IsInsert;
  CATLONG32           _IsInit;//si la premiere direction a ete initialisee IsInit=1
  CATLONG32           _IsCV;//si l'algorithme converge IsCV=1 sinon IsCV=0 pour lancer l'algorithme dans l'autre sens
  CATLONG32           _Split;
  CATLONG32           _Inversion;
  int                 _MeasureCrossedGaps;
  double            * _CrossedGaps;
};

#endif


