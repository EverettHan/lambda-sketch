//===================================================================
// COPYRIGHT Dassault Systemes Provence 2019
//===================================================================
// CATPolyLongestPathInBasinOper.h
//===================================================================
//
// Usage notes: Compute the longest water path lying into a given basin
//
//===================================================================
// HISTORIQUE :
// 13/02/2019 : NUA : Creation
//===================================================================


#ifndef CATPolyLongestPathInBasinOper_h__
#define CATPolyLongestPathInBasinOper_h__



#include "CATPolyWatershedSegmentationData.h"
#include "CATPolyDropPathOnTerrainOperator.h"
#include "ExportedByCATPolyWatershedOperators.h"

#include "CATIPolyMesh.h"
#include "CATErrorDef.h"


class CATPolyWatershedSegmentationOperator;
class CATPolyWatershedPathExtender;

class ExportedByCATPolyWatershedOperators CATPolyLongestPathInBasinOper
{
public:

  // si iFlowOpe != NULL, cet opérateur sera utilise pour calculer les chemins 
  // - a utiliser pour éviter que les water path ne sortent des bassins
  // - si les bassins ont ete fusionnes, il faut indiquer aussi l'opérateur d'extension iExtenderOpe

  // - variante 1 : precalcul de tous les bassins, le get ne fait pas de calcul
  static CATPolyLongestPathInBasinOper * CreateInstance(const CATIPolyMesh & Mesh, const CATTolerance & iTol, const std::vector<int> & iAllBottoms, CATPolyWatershedSegmentationOperator * iSegmentationOpe, CATPolyDropPathOnTerrainOperator * iFlowOpe /*= NULL*/, CATPolyWatershedPathExtender * iExtenderOpe /*= NULL*/);

  // - variante 2 : le plus long chemin de chaque bassin est calcule a la volee
  static CATPolyLongestPathInBasinOper * CreateInstance(const CATIPolyMesh & Mesh, const CATTolerance & iTol, const std::vector<int> & iAllBottoms, CATPolyWatershedSegmentationOperator * iSegmentationOpe, CATPolyDropPathOnTerrainOperator * iFlowOpe /* = NULL */, const CATPolyWatershedSegmentationData_t & iAllBasins, CATPolyWatershedPathExtender * iExtenderOpe);

  // - variante 3 : calcul a la volee du plus long chemin d'un bassin
  static CATPolyLongestPathInBasinOper * CreateInstance3(const CATIPolyMesh & Mesh, const CATTolerance & iTol, const std::vector<int> & iAllBottoms, CATPolyWatershedSegmentationOperator * iSegmentationOpe, CATPolyDropPathOnTerrainOperator * iFlowOpe /*= NULL*/, CATPolyWatershedPathExtender * iExtenderOpe /*= NULL*/);


  virtual ~CATPolyLongestPathInBasinOper() {}

  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  // if ioBasins is != null_ptr -> the m_LongestPath member field of all the ::Cell_t class will be filled 
  virtual HRESULT Init(CATPolyWatershedSegmentationData_t * ioBasins = nullptr) = 0;

  // callback for monitoring the the longest path computation of a given basin
  virtual HRESULT Run(const CATPolyWatershedSegmentationData::Cell_t & iBasin, CATPolyDropPathOnTerrainOperator::WaterFlow_t & oPath, CATPolyWatershedCallback * iCB = nullptr) const = 0;
  virtual HRESULT Run(int NumBasin, CATPolyDropPathOnTerrainOperator::WaterFlow_t & oPath, CATPolyWatershedCallback * iCB = nullptr) const = 0;
};


#endif // CATPolyLongestPathInBasinOper_h__
