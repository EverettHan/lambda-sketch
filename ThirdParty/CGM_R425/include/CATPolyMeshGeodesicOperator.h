//=================================================================================
// Copyright Dassault Systemes Provence 2011, All Rights Reserved
//=================================================================================
//
// CATPolyMeshGeodesicOperator.h
//
//=================================================================================
//
// Usage notes: Opérateur de calcul de plus court chemin sur un CATCldPolygon
//
//================================================================================= 
// Fev,    2011 : ANR : D'apres CATSmgMeshGeodesicOperator de RAQ
//                      Plus de Factory, ni de CldScan/CldPolygon
//=================================================================================
#ifndef CATPolyMeshGeodesicOperator_H
#define CATPolyMeshGeodesicOperator_H

//Pour l'export
#include "CATPolyAnalyzeOperators.h"

//Divers
#include "CATStdLib.h"
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATLISTV_CATMathPoint.h" 

#ifdef _WINDOWS_SOURCE
  #define GEODESIC_OPE_USE_STL_PRIORITY_QUEUE
  #include <queue>
  #include <vector> 
#endif  //_WINDOWS_SOURCE
  
class CATPolyPointOnGeodesic;
class CATIPolyMesh;
class CATPolyTopoUtil;
class CATPolyGeoUtil;


class ExportedByCATPolyAnalyzeOperators CATPolyMeshGeodesicOperator
{
public:

  //Constructeurs 
  CATPolyMeshGeodesicOperator(CATIPolyMesh* iPolyMesh);

  //Destructeur
  virtual ~CATPolyMeshGeodesicOperator();

  //Set des vertex extrémités du chemin
  void SetStartExtremity(const int iStartVertexNum);
  void SetEndExtremity(const int iEndVertexNum);

  //Dijkstra amélioré
  void SetUseExtendedDijkstra();

  //Calcul d'une géodésique plutôt qu'un Dijkstra
  void SetComputeGeodesic();

  //Run de l'opérateur: calcul d'un plus court chemin entre les deux vertex
  int Run();

  //Longueur du chemin
  double GetShortestPathLength() const;

  //Obtention du chemin
  const CATLISTV(CATMathPoint)& GetGeodesic(double* oPathLength = 0);
  const CATListOfInt& GetShortestPath(double* oPathLength = 0);
 
  //DEBUG: prints
  void SetVerbose();

  //DEBUG: Création forcée du scan
  void SetForceScanCreation();

private:

  //Initialisations
  void Initialize();
  int InitOperator();

  //Calcul d'un plus court chemin à la mode Dijkstra
  int ComputeShortestPath();

  //Calcul d'une géodésique
  int RunComputeGeodesic();

  //Création des points sur la géodésique
  int CreatePointsOnGeodesic();

  //Raffinement de la géodésique
  int CorrectGeodesic();

  //Correction d'un point sur une edge
  int CorrectPointOnEdge(CATPolyPointOnGeodesic* iPoint, const int iLocateInList, double* ioVertexError = 0);

  //Correction d'un point sur un vertex
  int CorrectPointOnVertex(CATPolyPointOnGeodesic* iCurrentPoint, const int iLocateInList, CATListPV& oNewCreatedPoints, double* ioVertexError = 0);

  //Distance entre deux point du CATCldPolygon
  double GetDistance(const int iVertexNum1, const int iVertexNum2);

  //Mise à jour des distances de tous les points voisins d'un point donné
  int UpdateDistancesAroundVertex(const int iVertexNum);

  //Détection du vertex qui réalise la distance minimale
  int FindMinDistanceVertex(int& oMinDistanceVertex);

  //Suppression des points sur la géodésique
  void RemovePointsOnGeodesic();

  //Suppression des tableaux utilisés par Dijkstra
  void CleanDijkstraArrays();

  //Recherche du troisième sommet d'un triangle
  int GetThirdVertex(const int iTriangle, const int iVertex1, const int iVertex2);

  //Calcul du OneRing ordonné autour d'un vertex
  int GetOneRing(const int iVertexNum, CATListOfInt& oOneRingOfVertices,
                        CATListOfInt& oOneRingOfTriangles, CATBoolean& oIsOpen);

  //Angle entre deux vecteurs
  double GetAngle(double* iVect1, double* iVect2);

  //Création du scan résultat
  int CreateGeodesicScan();


  //------ Data:
  int _Error; 
  CATIPolyMesh* _PolyMesh;
  int _StartVertexNum, _EndVertexNum;
  CATBoolean _OperatorHasBeenInitialized, _UseExtendedDijkstra, _MustComputeGeodesic, _MustVerbose, _ForceScanCreation;
  CATListOfInt _ShortestPath;
  double _ShortestPathLength;
  CATLISTV(CATMathPoint) _GeodesicPoints;
  CATPolyTopoUtil* _topologyUtil;
  CATPolyGeoUtil* _geometryUtil; 

  int _NbVertices;
  int* _PreviousVertex;
  double* _ShortestDistance;

#ifdef GEODESIC_OPE_USE_STL_PRIORITY_QUEUE
  struct DisjkstraElement
  {
    DisjkstraElement(const int iVertexIndex, const double iDistance)
    {
      _VertexIndex=iVertexIndex;
      _Distance=iDistance;
    }

    int _VertexIndex;
    double _Distance;
  };
  
  struct DisjkstraElementComparator
  {
    bool operator()(const DisjkstraElement& iDisjkstraElement1, const DisjkstraElement& iDisjkstraElement2) const
    {
      //return (iDisjkstraElement1._Distance < iDisjkstraElement2._Distance) ? true : false;
      return (iDisjkstraElement1._Distance > iDisjkstraElement2._Distance) ? true : false; //on inverse: la plus grande priorité est pour la plus petite distance
    }
  };

  /*#pragma warning(push) //Pour supprimer les warning C4251, C4530
  #pragma warning(disable: 4251)
  #pragma warning(disable: 4530)
  std::priority_queue<DisjkstraElement, std::vector<DisjkstraElement>, DisjkstraElementComparator> _DijkstraElementPriorityQueue;
  #pragma warning(pop)*/
  std::priority_queue<DisjkstraElement, std::vector<DisjkstraElement>, DisjkstraElementComparator>* _DijkstraElementPriorityQueue;
#endif  //GEODESIC_OPE_USE_STL_PRIORITY_QUEUE

  //Infos binaires sur les points du chemin
  // Bit 0x01: sur le chemin (1) / pas sur le chemin (0)
  // Bit 0x02: distance calculée (1) / distance non calculée (0)
  // Bit 0x04: point non directement lié au précédent (1) / point directement lié (0)
  unsigned char* _VerticesState;

  CATListPV _PointsOnGeodesic;
};

#endif



