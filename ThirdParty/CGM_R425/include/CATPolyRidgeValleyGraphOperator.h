#ifndef CATPolyRidgeValleyGraphOperator_h__
#define CATPolyRidgeValleyGraphOperator_h__

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRidgeValleyGraphOperator.h
//
//===================================================================
//
// Usage notes: concatenate valley and ridge segments computed by CATPolyRidgeValleyOperator into polylines and produce a graph formed by these polylines
//
//===================================================================
// 31/10/2018 : Change the meaning of the slope parameter . Now it refers to PERCENTAGE between 0 and 1 (more precisely it's the ratio)
// 17/09/2018 : NUA : Add new filters (slope and sharpness)
// 02/06/2017 : NUA : Add callback
// May 2017  Creation: NUA
//===================================================================


// watershed
#include "ExportedByCATPolyWatershedOperators.h"
#include "CATPolyRidgeValleyGraph.h"


// stl
#include <set>
#include <limits>
#include <memory>

class CATTolerance;
class CATIPolyMesh;
class CATPolySteepestSlopeOperator;
class CATPolyRidgeValleyOperator;
class CATPolyDropPathOnTerrainOperator;

struct CATPolyWatershedCallback;

class ExportedByCATPolyWatershedOperators CATPolyRidgeValleyGraphOperator
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
    std::set<CATPolyRidgeValleyGraph::KindOfArcElem_t> m_NeedToExtendExtremities;

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

    bool m_FilterBySlope;
    double m_MinSlope; // NUA (31/10/2018) : Filter according to the slope (ie the percentage - 0 .. 1) of the extension

    // NUA (27/09/2018) : non pertinent filter
    //bool m_FilterBySharpness;
    //CATAngle m_MinSharpnessAngle; // NUA (10/09/2018) new parameters for meaningfull parameters

    // retire au graph resultat les cretes et les vallees originales
    // faux par defaut
    // Rq : si les extensions sont calculees, c'est utile de passer ce booleen a true - surtout avec des filtres actives
    bool m_RemoveOriginalArcs ;


    ExtensionParametersNew_t()
      : m_FilterByCovering(false), m_MinLengthCovering (0.), m_FilterByLength (false)
      , m_MinLengthExtension(std::numeric_limits<double>::max())
      , m_MaxLengthExtension(std::numeric_limits<double>::max())
      , m_RemoveOriginalArcs (false)
      , m_MinSlope (0.)
      /*, m_MinSharpnessAngle(0.)*/
      , m_FilterBySlope(false)
      /*, m_FilterBySharpness(false)*/
    {
    }
  };

  static std::unique_ptr<CATPolyRidgeValleyGraphOperator> CreateInstance(const CATPolyRidgeValleyOperator & iRidgeValleyOpe, const CATIPolyMesh & iMesh, const CATTolerance & iTol);
  static std::unique_ptr<CATPolyRidgeValleyGraphOperator> CreateInstanceNew(const CATPolyRidgeValleyOperator & iRidgeValleyOpe, const CATIPolyMesh & iMesh, const CATTolerance & iTol);

  virtual ~CATPolyRidgeValleyGraphOperator() {}
  // if iParameters is set to NULL, no extension will be computed
  virtual HRESULT Run(const ExtensionParameters_t * iParameters = NULL) = 0;
  virtual HRESULT Run(const ExtensionParametersNew_t * iParameters = NULL) = 0;

  virtual CATPolyRidgeValleyGraph GetGraph() = 0;

  // reuse existing opes
  virtual void SetWaterFlowOpe(CATPolyDropPathOnTerrainOperator * iOpe) = 0;

  // Enable to know the current computation state 
  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

};


#endif // CATPolyRidgeValleyGraphOperator_h__
