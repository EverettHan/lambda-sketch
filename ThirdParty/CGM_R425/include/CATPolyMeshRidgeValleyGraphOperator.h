#ifndef CATPolyMeshRidgeValleyGraphOperator_h__
#define CATPolyMeshRidgeValleyGraphOperator_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshRidgeValleyGraphOperator.h
//
//===================================================================
//
// Usage notes: concatenate valley and ridge segments computed by CATPolyMeshRidgeValleyOperator into polylines and produce a graph formed by these polylines
//
//===================================================================
// 02/06/2017 : Add callback
// May 2017  Creation: NUA
//===================================================================
#ifdef _WINDOWS_SOURCE

// watershed
#include "CATPolyMeshWatershedOperators.h"
#include "CATPolyMeshRidgeValleyGraph.h"


// stl
#include <set>
#include <limits>
#include <memory>

class CATTolerance;
class CATIPolyMesh;
class CATPolyMeshRidgeValleyOperator;
class CATPolyMeshDropPathOnTerrainOperator;

struct CATPolyMeshWatershedCallback;

class ExportedByCATPolyMeshWatershedOperators CATPolyMeshRidgeValleyGraphOperator
{

public:

  struct ExtensionParameters_t
  {
    bool m_NeedToExtendExtremities;
    bool m_NeedToConnectArcs;
    size_t m_NbMaxElemInExtension;

    ExtensionParameters_t() : m_NeedToExtendExtremities(true), m_NeedToConnectArcs(true), m_NbMaxElemInExtension(std::numeric_limits<size_t>::max()) {}
  };

  struct ExtensionParametersNew_t
  {
    // specifie les extremites des cretes et des vallees a etendre
    // par defaut : rien
    std::set<CATPolyMeshRidgeValleyGraph::KindOfArcElem_t> m_NeedToExtendExtremities;

    // specifie la longueur minimale (cumulee) des cretes et des vallees qu'une extension doit recouvrir pour etre valide
    // le test de recouvrement est effectue AVANT la troncation
    // par defaut : pas de minimum (toute les extensions sont valides)
    bool m_FilterByCovering ;
    double m_MinLengthCovering ;

    // specifie la longueur maximale d'une extension. L'extenstion est tronquee au dela de cette longueur
    // par defaut : pas de max (pas de troncation)
    bool m_FilterByLength ;
    double m_MinLengthExtension ; // NUA : 9/11/2017 : new parameters for filetering by length 
    double m_MaxLengthExtension ; // NUA : 9/11/2017 : obsolete parameter, remplace by m_MinLengthExtension

    // retire au graph resultat les cretes et les vallees originales
    // faux par defaut
    // Rq : si les extensions sont calculees, c'est utile de passer ce booleen a true - surtout avec des filtres actives
    bool m_RemoveOriginalArcs ;


    ExtensionParametersNew_t()
      : m_FilterByCovering(false), m_MinLengthCovering (0.), m_FilterByLength (false)
      , m_MinLengthExtension(std::numeric_limits<double>::max())
      , m_MaxLengthExtension(std::numeric_limits<double>::max())
      , m_RemoveOriginalArcs (false)
    {
    }
  };

  static std::unique_ptr<CATPolyMeshRidgeValleyGraphOperator> CreateInstance(const CATPolyMeshRidgeValleyOperator & iRidgeValleyOpe, const CATIPolyMesh & iMesh, const CATTolerance & iTol);
  static std::unique_ptr<CATPolyMeshRidgeValleyGraphOperator> CreateInstanceNew(const CATPolyMeshRidgeValleyOperator & iRidgeValleyOpe, const CATIPolyMesh & iMesh, const CATTolerance & iTol);

  virtual ~CATPolyMeshRidgeValleyGraphOperator() {}
  // if iParameters is set to NULL, no extension will be computed
  virtual HRESULT Run(const ExtensionParameters_t * iParameters = NULL) = 0;
  virtual HRESULT Run(const ExtensionParametersNew_t * iParameters = NULL) = 0;

  virtual CATPolyMeshRidgeValleyGraph GetGraph() = 0;

  // reuse existing opes
  virtual void SetWaterFlowOpe(CATPolyMeshDropPathOnTerrainOperator * iOpe) = 0;

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyMeshWatershedCallback * iCB) = 0;

};

#endif // _WINDOWS_SOURCE
#endif // CATPolyMeshRidgeValleyGraphOperator_h__
