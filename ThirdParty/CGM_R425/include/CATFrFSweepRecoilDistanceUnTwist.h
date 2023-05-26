// COPYRIGHT DASSAULT SYSTEMES 2003
//==========================================================================
//
// CATFrFSweepRecoilDistanceUnTwist:
//
//==========================================================================
//
//  Renvoie les zones de recul autour d'une zone de rebroussement
//  dans le cas du Sweep Segment uniquement dans un premier temps
//  (pour l'offset curve 3D et le UnTwist pour le sweep segment)
//
//
// Usage notes:
//   - iNbWrapIntervals est un tableau de CATLONG32 de longueur NbSweep dans la Shape
//       iWrapDomains[i] = n ou n est le nbre de rebroussement sur le Sweep i
//   - iNbSurfBySweep est un tableau de CATLONG32 de longueur NbSweep dans la Shape
//       qui donne le nombre de Surface par Sweep de la Shape
//   - iWrapInitParamMF est un tableau de CATListOfDouble (init des intervalles
//       de rebroussement) de de longueur NbSweep dans la Shape
//       iWrapInitParamMF[iWrapIndexDomain][0] est le premier parametre du premier 
//       intervalle de rebroussement du domaine iWrapIndexDomain. Est defini si
//       iWrapDomain[iWrapIndexDomain]=1
//
//  REMARQUE : La liste de parametres en sortie peut etre de longueur inferieure
//             a la liste de parametres de rebroussement en entree
//
//==========================================================================
// February 03     Creation                   Celine Chatelet
//==========================================================================

#ifndef CATFrFSweepRecoilDistanceUnTwist_H
#define CATFrFSweepRecoilDistanceUnTwist_H

#include "FrFAdvancedObjects.h"
#include "CATCGMVirtual.h"

class CATGeoFactory;
class CATMathSetOfPointsND;
class CATFrFMovingFrame;
class CATFrFNurbsMultiForm;
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATMathVector.h"
class CATPlane;
class CATMathDirection;
class CATFrFShapeResult;
class CATSplineCurve;
class CATSoftwareConfiguration;
class CATPCurve;
class CATCornerPCrvPCrv;
class CATCrvParam;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFSweepRecoilDistanceUnTwist: public CATCGMVirtual
{
  public :
    
    //-------------------------
    // Constructor & Destructor
    //-------------------------
    CATFrFSweepRecoilDistanceUnTwist(CATGeoFactory* iFactoryToUse,
                                     CATFrFShapeResult* iMyShapeResult,
                                     CATLONG32* iNbSurfBySweep,
                                     CATLONG32 iNbSweep,
                                     CATLONG32* iNbWrapIntervals,
                                     double** iWrapInitParam,
                                     double** iWrapEndParam,
                                     const CATListOfInt & iInitWrapDomain,
                                     const CATListOfInt & iEndWrapDomain,
                                     int** iWrapCurveNber,
                                     CATFrFMovingFrame* iMF);

    void SetRadiusCorner(double iRadius);  // vaut 0.1 par defaut

    // TOUJOURS faire ce set
    void SetSoftwareConfig(CATSoftwareConfiguration* iSoftwareConfiguration);

    ~CATFrFSweepRecoilDistanceUnTwist();
    
    //------------------------------
    //  Getting & Setting attributes
    //------------------------------

    // parametres du moving frame
    void GetWrapInitParamMFWithRecoilDist(CATListOfDouble& oWrapInitParRD);

    // parametres du moving frame
    void GetWrapEndParamMFWithRecoilDist(CATListOfDouble& oWrapEndParRD);

    //------------------------------
    //  Run : 
    //  renvoie : 1 si impossible car rayon trop grand
    //            2 si pb lors le la proj sur le plan de la ViewingDir
    //            3 si sweep en debut ou en fin de longueur < 100*resolution
    //            -1 si erreur dans les donnees de la ShapeResult => pas d'initialisation
    //            -2 si entre 2 PCurve, on ne trouve pas de corner
    //------------------------------
    int Run();

    int Init();


  protected :

  CATSplineCurve** Compute3DSpline(int& oNbTotalSpline,
                                   CATLONG32*& IndexSweepSpline,
                                   CATLONG32*& IndexWrapPrevSpline,
                                   CATLONG32 iNbWrap);

  // Cette methode modifie (desalloue et realloue les donnees privees
  // _WorkParams, _ParamsBis, _WorkPoints, _PointsBis, _WorkTangents,
  // _TangentsBis, _WorkDers2, _Ders2Bis
  CATLONG32 ComputeSetFor3dSpline(CATSplineCurve* SplineSweep,
                             double iCurrInitWrapParam,
                             double iCurrEndWrapParam,
                             CATLONG32 PrevIndiceParam,
                             CATLONG32 NextIndiceParam,
                             CATLONG32 index);

  CATLONG32 WhichPCurveNearIntersectionPoint(CATLONG32 i, CATLONG32& FirstIndex, 
                                        CATLONG32& NextIndex, CATLONG32 NbTotalSpline);

  CATLONG32 IsZOrIntersection(CATLONG32 IndexWrapPrevSpline);

  CATCornerPCrvPCrv* CreateCorner(CATLONG32 iInitIndex, CATLONG32 iEndIndex);

  // Si on n'a pas trouve de corner, renvoie un pointeur null
  CATCornerPCrvPCrv* FindAPossibleCorner(CATLONG32 iNbTotalSpline,
                                         CATLONG32 iInitIndex, CATLONG32 iEndIndex,
                                         CATLONG32& oNewInitIndex, CATLONG32& oNewEndIndex);


  CATLONG32 ComputeIntersection(CATLONG32 iNewInitIndex, CATLONG32 iNewEndIndex,
                           CATLONG32& oSensToGo,
                           double & oCumulLengthBefore, double& oCumulLengthAfter);

  double ComputeLengthIfSegment(CATLONG32 iIndex);

  // les trois methodes qui suivent sont en concurrence pour le calcul de tgt et d2
  // aux points de rebroussement
  CATLONG32 TgtETd2ParCATMathHermiteQuinticTgtETd2DecalesEnParam(double* LesWorkParams, CATLONG32 index,
                                                            CATLONG32 PrevIndiceParam, CATLONG32 NextIndiceParam,
                                                            double iCurrInitWrapParam, double iCurrEndWrapParam,
                                                            double* WrapInitPt, double* WrapEndPt,
                                                            double* WrapInitTgt, double* WrapEndTgt,
                                                            double* WrapInitd2, double* WrapEndd2);

  CATLONG32 TgtETd2ParCATMathHermiteQuintic(double* LesWorkParams, CATLONG32 index,
                                       CATLONG32 PrevIndiceParam, CATLONG32 NextIndiceParam,
                                       double iCurrInitWrapParam, double iCurrEndWrapParam,
                                       double* WrapInitPt, double* WrapEndPt,
                                       double* WrapInitTgt, double* WrapEndTgt,
                                       double* WrapInitd2, double* WrapEndd2);

//  CATLONG32 TgtETd2ParCATCreateCrvQuinticInterpolation(CATLONG32 IsInit, CATSplineCurve* SplineSweep,
//                                                  CATLONG32 index,
//                                                  double WrapParam, double* WrapPt, 
//                                                  double* WrapTgt, double* Wrapd2);


  // si on travaille au point init de rebroussement, iIsStart = 1
  // sinon, iIsStart = 0
  void ApproxWrapTgt(CATLONG32 iIndicePCrv, CATLONG32 iIsStart, 
                     CATMathPoint& iWrapPoint, CATMathVector& oWrapTgt);


  void MergeCorners(CATListOfInt& ioFirstIndexList, CATListOfInt& ioNextIndexList, CATLONG32* ioTypeOfWrap);

  void ComputeRecoilParamMF(CATLONG32* TypeOfWrap);


  private :

  CATGeoFactory*           _Factory;
  CATSoftwareConfiguration* _SoftwareConfiguration;

  CATLONG32                     _NbDomains;
  CATFrFShapeResult*       _MyShapeResult;
  CATLONG32                     _NbSweep;
  CATLONG32                     _NbForms;
  CATFrFNurbsMultiForm**   _Forms;
  CATMathSetOfPointsND**   _Points;
  CATMathSetOfPointsND**   _Tangents;
  CATMathSetOfPointsND**   _Ders2;
  CATMathSetOfPointsND**   _Params;
  CATLONG32*                    _NbWrapIntervals;
  double**                 _WrapInitParam;
  double**                 _WrapEndParam;
  CATListOfInt             _InitWrapDomain;
  CATListOfInt             _EndWrapDomain;
  int                      _WrapCurveNber;
  CATListOfDouble          _WrapInitParRD;
  CATListOfDouble          _WrapEndParRD;
  CATMathVector            _ViewingDir;
  CATPlane*                _ViewingDirPlane;
  CATLONG32*                    _NbSurfBySweep;

  // Toutes ces donnees sont des donnees de travail
  // amenees a etre allouees et detruites en permanence
  CATMathSetOfPointsND*    _WorkParams;
  CATMathSetOfPointsND*    _ParamsBis;
  CATMathSetOfPointsND*    _WorkPoints;
  CATMathSetOfPointsND*    _PointsBis;
  CATMathSetOfPointsND*    _WorkTangents;
  CATMathSetOfPointsND*    _TangentsBis;
  CATMathSetOfPointsND*    _WorkDers2;
  CATMathSetOfPointsND*    _Ders2Bis;


  double                   _Radius;

  int                      _NbSpline;
  CATSplineCurve**         _SplineCrv;
  CATLONG32                     _IsClosed;
  CATPCurve**              _ProjCurve;
  CATCrvParam*             _InitWP2D;
  CATCrvParam*             _EndWP2D;

  CATFrFMovingFrame*       _MF;
};

#endif


