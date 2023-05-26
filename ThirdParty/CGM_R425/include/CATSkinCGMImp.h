//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATSkinCGMImp.h
// Implementation of CATSkinCGMImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                           FCX
//===================================================================
// Janv 2009  Perfo : On garde le PtFaceOperator en cours         JSX
// Aout 2009  ParamOutsideDomainFace et ParamOutsideDomainEdge remplaces les 2 ParamOutsideDomains
//            Ajout de GetClosePointFromBoundray qui permet de faire marcher GetClose point meme 
//            quand le point d'oeirgine est sur le bord d'une face
//            ==>syndrome, on ne detect pas d'intersection avec la face, et donc on chemine a l'exterieur
//            => Model CGMReplay_Sweep_CDS_01 case l_xxxxx 
//            suppression de _TestMode utilisé pour peindre en vert un indicateur
//            Factorisation de CheckPointInFace

#ifndef CATSkinCGMImp_H
#define CATSkinCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "SkinWireImp.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATMathVector.h"
#include "CATMath3x3Matrix.h"

class CATBody;
class CATShell;
class CATSoftwareConfiguration;
class CATSkinParamCGMImp;
class CATEdge;
class CATFace;
class CATVertex;
class CATMathPoint;
class CATGeoFactory;
class CATDomain;
class CATPositionPtFaceOperator;
class CATCell;
class CATTransfoManager;
class CATMathTransformation;
class CATCGMStream;
class CATMathPlane;
class CATMathLine;
class CATPoint;

enum CATStopCommandCGM
{
  CATCGMStopOnG0,
  CATCGMNoStop
};

enum CATClosePointDiagnosticsCGM 
{
  CATCGMClosePointSucceded,
  CATCGMClosePointFailedW,
  CATCGMClosePointFailedU,
  CATCGMClosePointFailedV,
  CATCGMClosePointFailedUV
};

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATSkinCGMImp
{
public:

  // Object management
  CATSkinCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATBody * ipBody);
  //CATSkinCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATShell * ipShell, int iSkinOrientation = 1);
  //CATSkinCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATFace * ipFace, CATBody * ipBody);
  CATSkinCGMImp(const CATSkinCGMImp & iSkinCGMImp);
  CATSkinCGMImp();
  virtual ~CATSkinCGMImp();

  // Implementation methods

  int Evaluate( const CATSkinParamCGMImp * iPointOnSkinImp, 
                double* oaPoint,
                double* oaDU,
                double* oaDV,
                double* oaD2U,
                double* oaDUDV,
                double* oaD2V);

  int EvaluateOnWire( const CATSkinParamCGMImp * iPointOnSkinImp, 
                      double* oaPoint,
                      double* oaDW,
                      double* oaD2W);

  int EvaluateOnVertex( const CATSkinParamCGMImp * iPointOnSkinImp, double* oaPoint);

  int GetClosePoint( CATSkinParamCGMImp * iPointOnSkinImp,
                     double iDeltaU,
                     double iDeltaV,
                     CATStopCommandCGM iStopCommand,
                     CATSkinParamCGMImp * oPointOnSkinImp,
                     CATClosePointDiagnosticsCGM & oDiagnostics,
                     double & oAppliedDeltaU,
                     double & oAppliedDeltaV);

  int GetClosePointOnWire( CATSkinParamCGMImp * iPointOnSkinImp,
                           double iDeltaW,
                           CATStopCommandCGM iStopCommand,
                           CATSkinParamCGMImp * oPointOnSkinImp,
                           CATClosePointDiagnosticsCGM & oDiagnostics,
                           double & oAppliedDeltaW);
  
  void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]);

  // curvilinear mode

  int EvaluateNormalize( const CATSkinParamCGMImp * iPointOnSkinImp,
                         double             * oaPoint,
                         double             * oaDU,
                         double             * oaDV,
                         double             * oaD2U,
                         double             * oaDUDV,
                         double             * oaD2V);

  int GetClosePointByLength( CATSkinParamCGMImp          * iPointOnSkinImp,
                             double                        iDirectionUV[2],
                             double                        iLength,
                             CATStopCommandCGM             iStopCommand,
                             CATSkinParamCGMImp          * oPointOnSkinImp,
                             CATClosePointDiagnosticsCGM & oDiagnostics,
                             double                      & oAppliedLength);

  // ComputeDistanceMin wit math objects

  int ComputeDistanceMin(CATMathPoint & iPoint, CATSkinParamCGMImp * oPointOnSkinImp);
  int ComputeDistanceMin(CATMathPlane & iPlane, CATSkinParamCGMImp * oPointOnSkinImp);
  int ComputeDistanceMin(CATMathLine & iLine, CATSkinParamCGMImp * oPointOnSkinImp);

  // ComputeDistanceMin wit other skin

  int ComputeDistanceMin(CATSkinCGMImp * iOtherSkinImp, CATSkinParamCGMImp * oPointOnThisSkinImp, CATSkinParamCGMImp * oPointOnTheOtherSkinImp);

  // Specific methods of CATSkinCGMImp
  CATBoolean IsEdgeOnBorder(CATEdge * iEdge);
  int NextEdgeFromFace(CATFace * iFace, double iU, double iV, CATEdge * iEdge, double & oW);
  int NextFaceFromEdge(CATEdge * iEdge, double iW, CATFace * iPreviousFace,                       CATFace *& oNextFace, double & oU, double & oV);
  int NextFaceFromEdge(CATEdge * iEdge,            CATFace * iPreviousFace, double iU, double iV, CATFace *& oNextFace, double & oU, double & oV);
  int GetInformationOnVertex(CATVertex * iVertex, int & oNbOfWires, int & oNbOfFaces);
  int NextEdgeFromVertex(CATVertex * iVertex, CATEdge * iPreviousEdge, CATEdge *& oNextEdge, double & oW);
  int NextFaceFromVertex(CATVertex * iVertex, CATFace * iPreviousFace, CATFace *& oNextFace, double & oU, double & oV);
  CATDomain* GetDomain(); 
  CATBody* GetBody();
  int GetOrientation();

  // FCX 09.2010
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, CATBody *& oSkinBody, unsigned int & ioIndex, CATBoolean iForceIndex = FALSE);
  void StreamSP(CATSkinParamCGMImp * iPointOnSkinImp, const char* iDebugDir, const char* iDebugName, unsigned int & ioIndex, CATBoolean iForceIndex = FALSE);

  // FCX 07.2014 : new stream architecture for EK
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  inline CATGeoFactory* GetGeoFactory() {return _pFactory;}
  inline CATSoftwareConfiguration* GetConfiguration() {return _pConfig;}

  // FCX 12.2011
  CATFace * GetFace(int iIndex);
  CATEdge * GetEdge(int iIndex);
  CATVertex * GetVertex(int iIndex);
  CATLONG32 FindVertex(CATVertex * iVertex);
  CATLONG32 FindEdge(CATEdge * iEdge);
  CATLONG32 FindFace(CATFace * iFace);

  // FCX 06.2014
  CATBoolean ConvertSkinParam(const CATSkinParamCGMImp *ipPointOnSkinImp, CATSkinParamCGMImp *opPointOnSkinImpToInitialize);

private:
  
  void Initialize();
  void ComputeDataModel();
  void ClearInternalData();

  CATBoolean CheckPointInFace(double ioU,double ioV, CATFace *iFace,CATEdge *&oCloseEdge);

  CATBoolean ParamOutsideDomainFace(CATFace * iFace, double iStartU, double iStartV, double & ioU, double & ioV,
                                CATEdge *& oCloseEdge, CATVertex *& oCloseVertex);
  CATBoolean ParamOutsideDomainEdge(CATEdge * iEdge, double & ioW, CATVertex *& oCloseVertex);
  void AddInLinkedEdgesTable(CATLONG32 iEdgeIndex, int iOrientation, CATLONG32 iVertexIndex);
  void AddInLinkedFacesTable(CATLONG32 iFaceIndex, CATLONG32 iEdgeIndex);
  int FindFaceFromEdge(CATEdge * iEdge, CATFace * iPreviousFace, CATFace *& oNextFace);

  CATBoolean GetClosePointOneStep( CATSkinParamCGMImp * iPointOnSkinImp,
                                   double iDeltaU,
                                   double iDeltaV,
                                   CATSkinParamCGMImp * oPointOnSkinImp,
                                   CATClosePointDiagnosticsCGM & oDiagnostics,
                                   double & oAppliedDeltaU,
                                   double & oAppliedDeltaV,
                                   CATEdge*&CloseEdge);

  int GetContinuity(CATSkinParamCGMImp * iPointOnSkin1, CATSkinParamCGMImp * iPointOnSkin2);
  CATBoolean ConvertVector(int iContinuity, CATSkinParamCGMImp * iPointOnSkin1, CATSkinParamCGMImp * iPointOnSkin2,
                           double & ioDeltaU, double & ioDeltaV);

  int GetClosePointFromBoundray(CATSkinParamCGMImp * iPointOnSkinImp,
                                   double iDeltaU,
                                   double iDeltaV,
                                   CATSkinParamCGMImp * oPointOnSkinImp,
                                   CATClosePointDiagnosticsCGM & oDiagnostics,
                                   double & oAppliedDeltaU,
                                   double & oAppliedDeltaV,
                                   CATEdge*&CloseEdge);

  // FCX 09.2010
  unsigned int DbgFindTag(CATCell * iCell);

  // FCX 07.2011
  void ComputeLinkedFaces2(int iVtxIndex);

  void SetCurvilinearMode(CATBoolean iCurvilinearMode); 
  CATBoolean GetCurvilinearMode(); 

  //void ComputeDistanceMin(CATDomain * iDomain, CATSkinParamCGMImp * oPointOnSkinImp, CATSkinParamCGMImp * oPointOnTheOtherSkinImp = 0);
  void ComputeDistanceMin(CATBody * iBody, CATSkinParamCGMImp * oPointOnSkinImp, CATSkinParamCGMImp * oPointOnTheOtherSkinImp = 0);
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // Data

  CATSoftwareConfiguration  * _pConfig;
  CATGeoFactory             * _pFactory;
  CATBody                   * _pBody;
  CATDomain                 * _pDomain;

  double _InclusionTol;

  // Bufferization (FCX 2006W30)

  CATSkinParamCGMImp * _pPreviousSkinParam;     // for Evaluate
  double _aEvaluateBuffer[18];
  CATSkinParamCGMImp * _pPreviousSkinParam2;    // for GetClosePoint
  double _PrevDeltaU, _PrevDeltaV;
  CATStopCommandCGM _PrevStopCommand;
  CATSkinParamCGMImp * _pPrevResultSkinParam;
  CATClosePointDiagnosticsCGM _PrevResultDiag;
  double _PrevResultDeltaU, _PrevResultDeltaV;

  // Data model

  CATLONG32 _NbF;
  CATLONG32 _NbE;
  CATLONG32 _NbV;

  CATFace   ** _pFaceList;
  CATEdge   ** _pEdgeList;
  CATVertex ** _pVertexList;

  CATLONG32 *  _pFaceTagList;
  CATLONG32 *  _pEdgeTagList;
  CATLONG32 *  _pVertexTagList;

  int       *  _pNbLinkedEdges;
  CATLONG32 ** _pLinkedEdges;
  int       ** _pLinkedEdgesOrient;
  int       *  _pNbLinkedFaces;
  CATLONG32 ** _pLinkedFaces;
  int       *  _pNbLinkedFaces2;
  CATLONG32 ** _pLinkedFaces2;

  double _G1Tolerance;

  // Positionning transformation
  CATMathVector     _T;
  CATMath3x3Matrix  _R;

  int _SkinOrientation; // FCX 07.2010

  // Perfo Position faces
  int _CurrentFaceIndex;
  CATPositionPtFaceOperator ** _TabPPF;
  CATPositionPtFaceOperator * _pPPF;
  CATFace ** _TabCurFace;
  CATFace * _CurFace;

  // FCX 09.2010 : for stream
  CATTransfoManager * _TransfoManager;
  CATMathTransformation * _Transfo;
  CATBoolean _UnstreamFactoryCreated;

  // FCX 10.2013
  CATBoolean _CurvilinearMode;
};

//-----------------------------------------------------------------------

#endif
#endif
