#ifndef CATPolyWatershedSegmentationDataData_h__
#define CATPolyWatershedSegmentationDataData_h__

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyWatershedSegmentationDataData.h : data structure describing cacthment basins given by watersheds
//
//===================================================================
// 01/10/2019 : NUA : calcul des aires 2D des bassins versants
// 13/09/2019 : NUA : fallback pour le calcul du perimetre/profondeur des bassins sans frontiere
// 03/12/2018 : NUA : evite de ne rendre aucun resultat si un bassin a une profondeur < 0 (warning tjs present) + fct pour modif z du terrain d'entree
// January 2018  Creation NUA
//===================================================================



// watershed
#include "CATPolyDropPathOnTerrainOperator.h"
#include "CATPolyCriticalMorseIndexOperator.h"
#include "CATPolyWatershedCallback.h"

// PolyhedralOperators
#include "CATIPolyMesh.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATCGMOutput.h"
#include "CATMathPoint2D.h"

#include "CATMathVector2D.h"

#include "CATIPolySurfaceVertexFacetNeighborhood.h"
#include "CATIPolySurfaceVertexIterator.h"

// STL
#include <vector>
#include <set>
#include <map>
#include <array>
#include <memory>

// les bassins versants segmentent le mesh suivant un graph
// - les cellules du graph (Cell_t) sont les bassins versants, et referencent l'indice du sommet qui est le fond du bassin (exutoire)
// - les bords des cellules (Edge_t) sont des chemin de pente maximale passant par des cols. Le bord est constitue d'une sequence de paire d'indices de sommet
// - les sommets du graph (Vertex_t) sont les extremites des Edge_t


////////////////////////////////////////////////////////////////
// namespace du graph
namespace CATPolyWatershedSegmentationData
{

  // pour le suivi du decoupage des triangles par le bord des bassins
  typedef std::map<int, std::vector<int> > JournalSplitTriangle_t;

  // definition du sommet du graph
  // pour l'instant, simplement un sommet du maillage
  struct Vertex_t
  {
    int m_Indx;

    Vertex_t(int v) : m_Indx(v) {}
    Vertex_t() : m_Indx(-1) {}
  };

  // forward declaration
  struct Cell_t;

  // structure definissant le bord entre 2 bassins versants
  // le bord de 2 bassins versants est constitue d'un ensemble d'arêtes de maillage qui sont partagees par 2 triangles de 2 bassins differents
  // Edge_t possede 2 extremites, qui sont des vertices du graph
  struct Edge_t
  {
    // liste des aretes du maillage sur l'edge
    std::vector<std::array<int, 2 > > m_AllPaths;

    // les extremites de l'edge
    Vertex_t m_Vertex0, m_Vertex1;

    // le numero du sommet le plus bas sur l'edge
    int m_NumLowestPoint;

    // pour le merge de bassin : permet de conserver les numeros des exutoires d'origine qui entourent l'edge
    int m_OriginalOutlet1 = -1, m_OriginalOutlet2 = -1;

    // les cellules du graph incidentes
    // les bassins versant autour de cette edge
    Cell_t * m_Cell0, *m_Cell1;

    Edge_t()
    {
      m_Cell0 = m_Cell1 = NULL;
      m_NumLowestPoint = -1;
    }

    double ComputeLength(const CATIPolyMesh & iMesh) const
    {
      double Result = 0.;
      for (const auto & I : m_AllPaths)
      {
        CATMathPoint P1, P2;
        if (!SUCCEEDED(iMesh.GetVertexPosition(I[0], P1)) || !SUCCEEDED(iMesh.GetVertexPosition(I[1], P2)))
          return -1.;

        Result += P1.DistanceTo(P2);
      }
      return Result;
    }

    double ComputeLength2D(const CATIPolyMesh & iMesh) const
    {
      double Result = 0.;
      for (const auto & I : m_AllPaths)
      {
        CATMathPoint P1, P2;
        if (!SUCCEEDED(iMesh.GetVertexPosition(I[0], P1)) || !SUCCEEDED(iMesh.GetVertexPosition(I[1], P2)))
          return -1.;

        CATMathPoint2D P1_2D(P1.GetX(), P1.GetY()), P2_2D(P2.GetX(), P2.GetY());


        Result += P1_2D.DistanceTo(P2_2D);
      }
      return Result;
    }

  };



  // une cellule du graph est un bassin versant
  // il contient :
  // - l'indice du points le plus bas (l'exutoire)
  // - la profondeur du bassin
  // - une liste d'edges qui sont les bords de ce bassin avec ses voisins
  // - un ensemble de triangles. Une goutte posee dans chaque triangle s'ecoulera jusqu'a l'exutoire de ce bassin
  struct Cell_t
  {
    // indice exutoire
    int m_BottomIdx;

    CATPolyCriticalMorseIndexOperator::KindOfVertex m_KindOfOutlet = CATPolyCriticalMorseIndexOperator::K_Undef;

    // index of the lowest sadlle located on the boundary of the cell
    int m_LowestSaddle = 0;

    // liste des bords de ce bassin
    std::vector<std::shared_ptr< Edge_t > > m_BoundaryEdges;

    // ensemble des triangles du maillage appartenant a ce bassin
    std::set<int> m_TriangleIndxs;

    // TODO : remplir ces champs au fur et a mesure
    double m_Depth ;
    double m_Volume;
    double m_Area ;
    double m_Area2D;
    double m_Perimeter;
    double m_Perimeter2D;
    std::vector<CATMathPoint> m_LongestPath;

    std::array<unsigned char, 4> m_Color;

    Cell_t() : m_Depth(0.), m_Area(0.), m_Perimeter(0.), m_Volume(0.), m_Area2D(0.), m_Perimeter2D(0.)
    {
      m_Color[0] = m_Color[1] = m_Color[2] = m_Color[3] = 0;
    }

    std::set < std::array<int, 2> > GetCellBoundary(const CATIPolyMesh & iRefinedMesh) const
    {
      std::set < std::array<int, 2> > Result;
      for (int NumT : m_TriangleIndxs)
      {
        int NumV[3];
        if (!SUCCEEDED(iRefinedMesh.GetTriangle(NumT, NumV)))
          return Result;

        for (int k = 0; k < 3; k++)
        {
          std::array<int,2> Elem
          {
            std::min<int>(NumV[k], NumV[(k + 1) % 3]),
            std::max<int>(NumV[k], NumV[(k + 1) % 3])
          };

          auto It = Result.insert(std::move(Elem));
          if (!It.second)
            Result.erase(It.first);
        }
      }

      return Result;
    }

    HRESULT FillBasinInfos(const CATIPolyMesh & iRefinedMesh , std::map<int,double> * iZWithPerturbation)
    {
      double zOutlet = 0.;
      if (iZWithPerturbation)
      {
        zOutlet = iZWithPerturbation->at(m_BottomIdx);
      }
      else
      {
        CATMathPoint POutlet;
        iRefinedMesh.GetVertexPosition(m_BottomIdx, POutlet);
        zOutlet = POutlet.GetZ();
      }
      //
      double zBoundary = std::numeric_limits<double>::infinity();

      for (const auto & ItBoundary : m_BoundaryEdges)
      {
        double zTemp = 0.;
        if (iZWithPerturbation)
        {
          zTemp = iZWithPerturbation->at(ItBoundary->m_NumLowestPoint);
        }
        else
        {
          CATMathPoint PMinBoundary;
          iRefinedMesh.GetVertexPosition(ItBoundary->m_NumLowestPoint, PMinBoundary);
          zTemp = PMinBoundary.GetZ();
        }
        

        if (zBoundary > zTemp)
        {
          zBoundary = zTemp;
          m_LowestSaddle = ItBoundary->m_NumLowestPoint;
        }
      }
      // NUA (23/08/2018) il faut aussi prendre en compte le bord du terrain
      // NUA (24/09/2018) : non, danger avec la profondeur resultante apres merge de bassin 
      // -> il faut trouver comment mieux definir les points critiques sur le bord, et comment calculer la profondeur sur le bord du mesh
      // A OPTIMISER
      //for (const auto & I : m_TriangleIndxs)
      //{
      //  int NumV[3];
      //  iRefinedMesh.GetTriangle(I, NumV);

      //  for (int k = 0; k < 3; k++)
      //  {
      //    // sur le bord ?
      //    if (iVoisinOpe && iVoisinOpe->IsBoundaryVertex(NumV[k]))
      //    {
      //      CATMathPoint PBoundary;
      //      iRefinedMesh.GetVertexPosition(NumV[k], PBoundary);
      //      if (zBoundary > PBoundary.GetZ())
      //      {
      //        zBoundary = PBoundary.GetZ();
      //      }
      //    }
      //  }
      //}

      // si l'outlet est sur le bord du terrain -> profondeur nulle
      if (m_KindOfOutlet == CATPolyCriticalMorseIndexOperator::K_BoundaryBottom)
      {
        m_Depth = 0.;
      }
      else
      {
        // cacul de la profondeur
        m_Depth = zBoundary - zOutlet;
      }
      if (m_Depth < 0.)
      {
        cgmout << __FUNCTION__ << " : bad depth value (" << m_Depth << ")" << cgmendl;
        //return E_FAIL;
      }

      // calcul de l'aire
      double BasinArea = 0.;
      double BasinArea2D = 0.;
      for (const auto & I : m_TriangleIndxs)
      {
        CATMathPoint P1, P2, P3;
        iRefinedMesh.GetTrianglePoints(I, P1, P2, P3);
        if (iZWithPerturbation)
        {
          int NumV[3];
          iRefinedMesh.GetTriangle(I, NumV);
          P1.SetZ(iZWithPerturbation->at(NumV[0]));
          P2.SetZ(iZWithPerturbation->at(NumV[1]));
          P3.SetZ(iZWithPerturbation->at(NumV[2]));
        }
        const CATMathVector N = (P2 - P1) ^ (P3 - P1);
        
        CATMathPoint2D P1_2D(P1.GetX(), P1.GetY());
        CATMathPoint2D P2_2D(P2.GetX(), P2.GetY());
        CATMathPoint2D P3_2D(P3.GetX(), P3.GetY());

        const double N_2D = (P2_2D - P1_2D) ^ (P3_2D - P1_2D);

        BasinArea2D += std::abs(N_2D);
        BasinArea += N.Norm();
      }
      m_Area = 0.5*BasinArea;
      m_Area2D = 0.5*BasinArea2D;

      // calcul du perimetre
      // WARNING
      // Le perimetre du bord du bassin ne tient pas compte de la portion (eventuellement vide) sur le bord terrain
      double Perimeter = 0.;
      double Perimeter2D = 0.;
      for (const auto & IterBoundary : m_BoundaryEdges)
      {
        Perimeter += IterBoundary->ComputeLength(iRefinedMesh);
        Perimeter2D += IterBoundary->ComputeLength2D(iRefinedMesh);
      }

      m_Perimeter = Perimeter;
      m_Perimeter2D = Perimeter2D;

      // pour traiter les bassins sans m_BoundaryEdges
      if (m_BoundaryEdges.empty())
      {
        double zMinBoundary = std::numeric_limits<double>::infinity();
        auto Frontier = GetCellBoundary(iRefinedMesh);
        for (const auto & E : Frontier)
        {
          CATMathPoint P1, P2;
          iRefinedMesh.GetVertexPosition(E[0], P1);
          iRefinedMesh.GetVertexPosition(E[1], P2);


          m_Perimeter += P1.DistanceTo(P2);
          double z1 = P1.GetZ();
          double z2 = P2.GetZ();

          zMinBoundary = std::min<double>(zMinBoundary, z1);
          zMinBoundary = std::min<double>(zMinBoundary, z2);
        }

        // si l'outlet est sur le bord du terrain -> profondeur nulle
        if (m_KindOfOutlet == CATPolyCriticalMorseIndexOperator::K_BoundaryBottom)
        {
          m_Depth = 0.;
        }
        else
        {
          // cacul de la profondeur
          m_Depth = zMinBoundary - zOutlet;
        }
      }

      return S_OK;
    }
  };

  struct PathFromSaddle
  {
    std::vector<CATPolyDropPathOnTerrainOperator::PointOnPath_t> m_Points;
    CATPolyDropPathOnTerrainOperator::WaterFlow_t m_Path;
    double m_HeightDiff = 0.;
    int m_NumStart = -1;
    int m_NumEnd = -1;
  };



  inline void ApplyZModif(CATIPolyMesh & ioMesh, const std::map<int, double> & iZMap)
  {
    CATIPolySurfaceVertexIterator * VIter = NULL;
    if (!SUCCEEDED(ioMesh.GetVertexIterator(VIter)) || !VIter)
      return;
    for (VIter->Begin(); !VIter->End(); ++(*VIter))
    {
      int NumV = VIter->Get();
      CATMathPoint P;
      ioMesh.GetVertexPosition(NumV, P);
      P.SetZ(iZMap.at(NumV));
      ioMesh.SetVertexPosition(NumV, P);
    }
    VIter->Release(); VIter = NULL;
  }

}

// segmentation du maillage du terrain en bassins versants
// - associe un exutoire a un bassin versant
// - associe chaque triangle a un exutoire 
struct CATPolyWatershedSegmentationData_t
{
  CATPolyWatershedSegmentationData::JournalSplitTriangle_t m_SplitJournal;

  std::map<int, std::unique_ptr<CATPolyWatershedSegmentationData::Cell_t> > m_BottomToBasin;

  std::map<int, int> m_TriangleToBasin;

  // internal use
  // vertices height in the refined mesh (with/without z-perturbation)
  std::map<int, double> m_RefinedZWithoutPerturbation, m_RefinedZWithPerturbation;

  //Constructeur par copie
  CATPolyWatershedSegmentationData_t(const CATPolyWatershedSegmentationData_t &obj)
  {
    *this = obj;
  }

  // renvoie la liste des outlets
  std::vector<int> GetOutlets() const
  {
    std::vector<int> Result;
    Result.reserve(m_BottomToBasin.size());
    for (const auto & I : m_BottomToBasin)
      Result.push_back(I.first);
    return Result;
  }

  //Operateur d'assignation =
  CATPolyWatershedSegmentationData_t & operator =(const CATPolyWatershedSegmentationData_t &obj)
  {
    if (this == &obj) return *this;

    // z maps
    m_RefinedZWithoutPerturbation = obj.m_RefinedZWithoutPerturbation;
    m_RefinedZWithPerturbation = obj.m_RefinedZWithPerturbation;

    //Map pointant sur les anciens (cle) et nouveaux (valeur) bassins
    std::map<CATPolyWatershedSegmentationData::Cell_t *, CATPolyWatershedSegmentationData::Cell_t *> OldToNewCell;
    //Map pointant sur les anciennes (cle) et nouvelles (valeur) edges
    std::map< std::shared_ptr<CATPolyWatershedSegmentationData::Edge_t>, std::shared_ptr<CATPolyWatershedSegmentationData::Edge_t >> OldToNewEdge;


    //Creation de la nouvelle map m_BottomToBasin avec de nouvelles cells vides
    for (auto & itBasins : obj.m_BottomToBasin)
    {
      //Remplissage de map m_BottomToBasin
      auto ResInsertNewCell = m_BottomToBasin.insert
      (
        std::make_pair
        (
          itBasins.first,
          std::unique_ptr<CATPolyWatershedSegmentationData::Cell_t>(new CATPolyWatershedSegmentationData::Cell_t())
        )
      );

      CATPolyWatershedSegmentationData::Cell_t * NewCell = ResInsertNewCell.first->second.get();

      //Remplissage des donnees des cells crees
      NewCell->m_BottomIdx = itBasins.second->m_BottomIdx;
      NewCell->m_TriangleIndxs = itBasins.second->m_TriangleIndxs;

      // attributes
      NewCell->m_Depth = itBasins.second->m_Depth;
      NewCell->m_Area = itBasins.second->m_Area;
      NewCell->m_Area2D = itBasins.second->m_Area2D;
      NewCell->m_Color = itBasins.second->m_Color;
	    NewCell->m_Perimeter = itBasins.second->m_Perimeter;
      NewCell->m_Perimeter2D = itBasins.second->m_Perimeter2D;
      NewCell->m_LowestSaddle = itBasins.second->m_LowestSaddle;
      NewCell->m_LongestPath = itBasins.second->m_LongestPath;

      ////Remplissage de map OldToNewCell
      OldToNewCell.insert
      (
        std::make_pair
        (
          itBasins.second.get(), NewCell
        )
      );

      //Remplissage de map OldToNewEdge
      for (auto & itEdge : itBasins.second->m_BoundaryEdges)
      {
        auto CurrentEdge = itEdge;
        auto ResFindEdge = OldToNewEdge.find(CurrentEdge);
        if (ResFindEdge == OldToNewEdge.end())
        {
          //Creation de la nouvelle edge
          std::shared_ptr< CATPolyWatershedSegmentationData::Edge_t > edge = std::make_shared< CATPolyWatershedSegmentationData::Edge_t>();
          edge->m_AllPaths = itEdge->m_AllPaths;
          edge->m_NumLowestPoint = itEdge->m_NumLowestPoint;
          edge->m_Vertex0 = itEdge->m_Vertex0;
          edge->m_Vertex1 = itEdge->m_Vertex1;
          edge->m_OriginalOutlet1 = itEdge->m_OriginalOutlet1;
          edge->m_OriginalOutlet2 = itEdge->m_OriginalOutlet2;

          ResFindEdge = OldToNewEdge.insert(std::make_pair(itEdge, edge)).first;
        }

        NewCell->m_BoundaryEdges.push_back(ResFindEdge->second);
      }
    }

    for (auto & IterE : OldToNewEdge)
    {
      CATPolyWatershedSegmentationData::Cell_t * NewCoBord0 = OldToNewCell[IterE.first->m_Cell0];
      CATPolyWatershedSegmentationData::Cell_t * NewCoBord1 = OldToNewCell[IterE.first->m_Cell1];
      //
      IterE.second->m_Cell0 = NewCoBord0;
      IterE.second->m_Cell1 = NewCoBord1;
    }

    //Copie de la map m_TriangleToBasin
    m_TriangleToBasin = obj.m_TriangleToBasin;
    m_SplitJournal = obj.m_SplitJournal;

    return *this;
  }

  CATPolyWatershedSegmentationData_t()
  {
  }


  // fill 
  // - area 
  // - depth
  HRESULT FillBasinInfos(const CATIPolyMesh & iRefinedMesh, CATPolyWatershedCallback * iCB, bool Usecache = true)
  {
    if (iCB)
    {
      iCB->SetCurrentStageName("CATPolyWatershedSegmentationOperatorImpl", "ComputeAttributes");
      iCB->SetProgress(0., "CATPolyWatershedSegmentationOperatorImpl::ComputeAttributes");
    }

    int CurrentElemBoundary = 0;
    const double TotalNbBasins(static_cast<double>(m_BottomToBasin.size()));

    for (auto & IterBasin : m_BottomToBasin)
    {
      CATPolyWatershedSegmentationData::Cell_t * CurrentBasin = IterBasin.second.get();
      if (CurrentBasin)
      {
        HRESULT hr = CurrentBasin->FillBasinInfos(iRefinedMesh, (Usecache) ? &m_RefinedZWithPerturbation : nullptr);
        if (!SUCCEEDED(hr))
        {
          if (iCB) iCB->SetError(CATPolyWatershedCallback::K_InvalidBasin);
          return E_FAIL;
        }
          
      }
    }

    if (iCB)
    {
      if (iCB->CancelOperation())
        return S_OK;
      iCB->SetProgress(static_cast<double>(CurrentElemBoundary++) / TotalNbBasins, "CATPolyWatershedSegmentationOperatorImpl::ComputeAttributes");
    }

    return S_OK;
  }

  CATPolyWatershedSegmentationData::Cell_t * GetContainingCell(const CATIPolyMesh & iMesh, const CATPolyWatershedSegmentationData_t & iSegmentation, const CATPolyDropPathOnTerrainOperator::PointPosInVertex_t & iPoint) const
  {
    CATIPolySurfaceVertexFacetNeighborhood * VoisinOpe = NULL;
    iMesh.GetVertexFacetNeighborhood(VoisinOpe);
    
    if (!VoisinOpe)
      return NULL;
    {
      {
        CATListOfInt AroundV;
        VoisinOpe->GetFacetNeighborsOfVertex(iPoint.m_VertexIdx, AroundV);

        int NumOutlet = -1;
        /* CHECK
        */
        bool IsOK = true;
        for (int k = 1; k <= AroundV.Size(); k++)
        {
          int NumT = AroundV[k];
          auto It = iSegmentation.m_TriangleToBasin.find(NumT);
          if (It == iSegmentation.m_TriangleToBasin.end())
            return nullptr;
          if (NumOutlet < 0)
            NumOutlet = It->second;
          else if (NumOutlet != It->second)
          {
            cgmout << __FUNCTION__ << " : # basin > 1" << cgmendl;
            return nullptr;
          }
        }
        /* FIN CHECK
        */

        if (NumOutlet < 0)
        {
          cgmout << __FUNCTION__ << " : # basin < 1" << cgmendl;
          return nullptr;
        }
        auto It2 = iSegmentation.m_BottomToBasin.find(NumOutlet);
        if (It2 == iSegmentation.m_BottomToBasin.end())
        {
          cgmout << __FUNCTION__ << " : can not retrieve basin" << cgmendl;
          return nullptr;
        }
        return It2->second.get();

      }
    }

    VoisinOpe->Release(); VoisinOpe = NULL;
    return nullptr;
  }

};




#endif // CATPolyWatershedSegmentationDataData_h__
