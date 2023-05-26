//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOptimizeTools
//
//===================================================================
// 28/11/18 F1Z : Creation
// DD/MM/YY
//===================================================================
#ifndef CATPolyBodyOptimizeTools_H
#define CATPolyBodyOptimizeTools_H

// PolyhedralBodyOperators
#include "CATIPolyBodyBarCache.h"

#include "PolyBodyRegularize.h"
#include "CATPolyBodyBarFlip.h"
#include "CATPolyBodySplitRefiner.h"

// std
#include <vector>

class CATPolyBody;

/**
 * Toolkits for advanced use of optimize operators
 */
namespace CATPolyBodyOptimizeTools
{
  HRESULT ExportedByPolyBodyRegularize GetLengthInitInformation(const CATPolyBody & iPolyBody ,
                                                                      double      & oMaxLength);


  /**
   * Filter to avoid testing good shape factor triangles (useful for better performances)
   */
  class ExportedByPolyBodyRegularize MaxShapeFactorFilter : public CATPolyBodyBarFlip::Filter
  {
  public:

    MaxShapeFactorFilter(const double iMaxShapeFactor) : _maxShapeFactor(iMaxShapeFactor) {};
    ~MaxShapeFactorFilter() {};

    bool IsAFuturCandidate(const int                                iIdFace,
                           const CATPolyBodyBarFlip::TriangleFlip & iTriangle);

    bool IsFlipValid(const int          iIdFace       ,
                     const int          iIdVertices[4],
                     const CATMathPoint iPt        [4],
                     const int          iPtValence [4]) { return true; };

  private:
    const double _maxShapeFactor;
  };

  /**
   * Observer to register all the final new bars after a split refiner run
   */
  class ExportedByPolyBodyRegularize RecordNewBars : public CATPolyBodySplitRefiner::Observer
  {
  public:
    RecordNewBars(CATIPolyBodyBarCache * iBarCacheToFill) : _barCache(iBarCacheToFill) { if(_barCache) _barCache->AddRef(); };
    ~RecordNewBars(){ if(_barCache) _barCache->Release(); _barCache = 0; };

    HRESULT ReactToSplitBar(const CATIPolyBodyBarCache::Bar_Data                 & iBarSplit,
                            const std::vector<CATIPolyBodyBarCache::Bar_Data * > & iNewBars );

  private:
    CATIPolyBodyBarCache * _barCache;
  };
};

#endif

