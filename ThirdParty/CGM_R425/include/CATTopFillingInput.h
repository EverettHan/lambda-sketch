/* -*-C++-*- */
#ifndef CATTopFillingInput_H
#define CATTopFillingInput_H

//=============================================================================
// Copyright Dassault Systemes 1997-2012, all rights reserved
//=============================================================================
//
// CATTopFillingInput :
//
//=============================================================================
// Usage notes:
//=============================================================================
// 23/11/12 HLN Modif. versionnee de la tolerance de detection des intersections profile/guide dans CheckSensOfDir
//  20 09 02  MNA : Ajout des methodes relatives au passage de la courbe de decoupe au powerFill
//                  - Decoupe des profils
//                  -Determination de la courbe de decoupe
//                  -Recuperation de la courbe
//
//=============================================================================

#include "Ribbon.h"
#include "CATTopRibObject.h"
#include "CATMathDef.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATBody.h"
#include "CATListOfInt.h"
#include "CATCGMNewArray.h"

class CATGeoFactory;
class CATBody;
class CATSoftwareConfiguration;
class CATCGMJournalList;
class CATListPtrCATGeometry;
class CATPointOnEdgeCurve;
class CATPointOnCurve;
class CATPCurve;
class CATSurface;
class CATPlane;
class CATCurve;
class CATPoint;

class CATMathPlane;
class CATMathPoint2D;
class CATMathPoint;
class CATMathDirection;
class CATProjectionPtCrv;

class CATCGMProgressBar;

#include "CATSafe.h"
CATSafeDefine(CATTopFillingInput);

class ExportedByRibbon CATTopFillingInput : public CATTopRibObject

{
  
  public:
  
  enum CATSideType {unknown=0, profile, guide, any};
  
  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  CATTopFillingInput(CATBody* iBody, CATSoftwareConfiguration* iConfig);
  CATTopFillingInput(CATBody* iBody, CATSoftwareConfiguration* iConfig,
                     const int iEdgesCount, CATEdge* iEdges[], CATFace* iFaces[]);
  CATCGMNewClassArrayDeclare;        // Pool allocation
  ~CATTopFillingInput();
  void Clean();
  
  //------------------------------------------------------------------------------
  // Returns the ordered list of edges with regards to a logical side. 1<=iLogicalSideNumber<=GetSidesCount.
  // Orientation = -1 / +1.
  // If CATSideType==any, whatever is iLogicalSideNumber, Returns the unordered whole contour, 
  // whatever are the edges types.
  //------------------------------------------------------------------------------
  int GetSidesCount(CATSideType iLogicalSideType) const;
  void GetEdges(CATSideType iLogicalSideType, int iLogicalSideNumber, 
                CATLISTP(CATEdge) & oEdges, CATListOfInt & oEdgesOrientation, CATLISTP(CATFace) & oFaces);
  double GetContourMaxGap() const;
  //MNA : Cette methode permet de recuperer les edges permettant de regenerer les Fill 
  CATLONG32 GetSplitEdge(CATLISTP(CATBody) & oSplitEdges);
  CATLONG32 GetComputeFillAlso();
  CATLONG32 GetComputedOfCuttingCurve();
  //MNA Mode Force
  
  void ForceComputeOfCuttingCurve(CATLONG32 iForce=1);

  //------------------------------------------------------------------------------
  // Append a new Edge to the contour (iLogicalSidetype=any is not supported)
  //------------------------------------------------------------------------------
  void Append(CATEdge* iEdge, int iEdgeOrientation, CATFace* iFace=NULL, 
              const CATSideType iLogicalSidetype=unknown, const int iLogicalSideNumber=0);

  //------------------------------------------------------------------------------
  // MNA : Cette methode permet de calculer une courbe de decoupe de couper les profils 
  // sur lesquels la courbe s'appuie, et de disconnecter les faces correspondantes
  // le CATLONG32 renvoye indique le niveau de l'erreur:
  // Rc = 0 => Pb au niveau des donnes d'entrees
  // Rc = 1 => Run Fully Successfull!!!
  // Rc = -1 => Zone de Twist invalide
  // Rc = -2 => Pb pour le cacul des extremites de la parabole (Pb de min dist multiple ou trp petite)
  // Rc = -3 => Probleme au niveau du Split des edges
  // Rc = -4 => Pb au niveau du calcul de la parabole (direc. imposee non conforme...)
  //------------------------------------------------------------------------------

  int ComputeCuttingCurveSplitEdgesThenDisconnect();
  //------------------------------------------------------------------------------
  void EvaluateGaps(CATPositiveLength &oActualGap, CATAngle &oActualSharpness);
  void SaveNCGM() const;
  void Dump( CATCGMOutput& ioOS );
  void Check(); 

  void SetProgressBar(CATCGMProgressBar* iProgressBar);
  CATCGMProgressBar* GetProgressBar() const;

  void SetFillForDraftReorder(CATBoolean iValue = TRUE);
  
  CATBoolean IsFillForDraftReorder() {return _FillForDraftReorder;}

  void SetAdvancedParabola(const CATBoolean iValue);

  //------------------------------------------------------------------------------
  // Internal utility: split an edge (bounded or not by one Face) into two parts.
  // Output edges are ordered according to initial edge orientation.
  // Returns whether split was successfull.
  //------------------------------------------------------------------------------
 
  static CATBoolean SplitEdge(CATBody*                  iBody, 
                              CATSoftwareConfiguration* iConfig,
                              CATCGMJournalList*        iJournal,           // can be NULL
                              CATEdge*                  iEdgeToSplit, 
                              CATPointOnEdgeCurve*      iSplitLocation, 
                              CATFace*                  iBoundedFace,       // can be NULL
                              CATEdge*   &              oEdge1,
                              CATEdge*   &              oEdge2         );
  
  //------------------------------------------------------------------------------
  //MNA:
  //This following methods allow us to compute the cutting curve to add to build
  //A better powerFill than before.
  //------------------------------------------------------------------------------

  //------------------------------------------------------------------------------
  // Contour can be reduced by trivial faces
  //------------------------------------------------------------------------------
  CATFace* ComputeTrivialFace(CATLISTP(CATEdge) &iSimplifiableEdges, CATListOfInt &iRound);

private:
  void RemoveValue(CATEdge* iEdge);

  CATBoolean ComputePointWhereToSplitProfile(CATLISTP(CATGeometry) &iListOfTwoProfileCurves,CATPointOnEdgeCurve* &oRightExtremity,CATPointOnEdgeCurve* &oLeftExtremity,
                                             CATMathDirection &oDirOnFirstEdge,CATMathDirection &oDirOnSecondEdge,CATPlane* &oParabolaPlane,
                                             CATLISTP(CATFace)& iListOfBoundingFaces);

  CATBoolean ComputeMiddleCurveForDetwist(CATPointOnEdgeCurve* &iRightExtremity,CATPointOnEdgeCurve* &iLeftExtremity,
                                  CATMathDirection &iDir1, CATMathDirection &iDir2,CATPlane * iParabolaPlane,CATPCurve* &oPParabol);

  CATBoolean CheckExtremity(CATCurve *iCurve,CATPoint *iPoint);

  CATBoolean ComputeMeanPlane(CATCurve * iCurve, CATMathPlane &oPlaneTocompute, 
                              CATMathDirection& oNormale);

  CATBoolean NewComputeMeanPlane(CATCurve* iProfile, CATFace* iSupport, CATPointOnCurve* PointOnProfile,
                                 CATMathPlane &oPlaneTocompute, CATMathDirection& oNormale);

  void Compute2DpointFromPoint(CATSurface *iSurface,CATMathPoint & iMathPoint,CATMathPoint2D & oPoint2D);

  void ReplaceEdges(CATEdge *iEdgeToReplace,CATLISTP(CATEdge)& iNewEdge); 
  void CheckSensOfDir(CATCurve * iProfileCurve,CATLISTP(CATGeometry) &iListOfGuideCurves,
                      CATLISTP(CATEdge) &iListOfGuideEdges ,CATMathDirection &ioDir);

  CATBoolean CheckZone(CATCurve * iCurve1,CATCurve * iCurve2,CATPoint * iPointOnFirstEdge,CATPoint * iPointOnSecondEdge);

  void ClearData(CATPointOnCurve *& iPoint1,CATPointOnCurve *& iPoint2,CATPointOnCurve *& iPointRef,
                 CATPointOnCurve *& iPtProjectOnPlnInter1, CATPointOnCurve*& iPtProjectOnPlnInter2,
                 CATCurve *& iIntersectPln1Pln2);

  void InitVersionning();
  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private: 
  CATBody*                  _Body;
  CATGeoFactory *           _Factory;
  CATSoftwareConfiguration* _Config;
  CATLISTP(CATEdge)         _Edges;
  CATListOfInt              _EdgesOrientation;
  CATListOfInt              _SplitEdgesOrientation;
  CATLISTP(CATFace)         _Faces;
  CATListOfInt              _Types;
  CATListOfInt              _Positions;
  CATLISTP(CATBody)         _ListOfBodyContainSplitEdges;
  int                       _ComputeFillAlso; //Cette variable me permet de savoir si au7 cas ou le calcul de la parabole echoue
                                              //je lance un Fill quand meme.
  double                    _ContourMaxGap;
  int                       _ComputedOfCuttingCurveAsked;
  int                       _Force;
  CATBoolean                _FillForDraftReorder; 
  CATCGMProgressBar*        _ProgressBar;

  struct OptionConfigData  // CCK Les options liees a la config => au niveau
  {
    CATBoolean             _Versioning_NewParabola ;
    CATBoolean             _Versioning_NewParabola2;
    CATBoolean             _Versioning_IncreaseTolerance;
    int                    _LevelToExecute;
  } ;
  OptionConfigData _Options ;
};
#endif
