#include "CATIAV5Level.h"
#if defined(CATIAR420) && !defined(CATPolyBodyIntersectionAnomalyList_h)
#define CATPolyBodyIntersectionAnomalyList_h

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
// CATPolyBodyIntersectionAnomalyList.h
//===================================================================
// A list of information about intersection anomalies
// to be passed to mesh cleaning operations
//===================================================================
// Nov 2018 Creation: MMN12.
//===================================================================
#include "CATLISTV_CATMathPoint.h"
#include "CATPolyBodyCheckedEditor.h"
#include "PolyBodyCheckedEditor.h"
#include <memory>
class CATPolyBody;
class CATPolyBodyCheckedEditor;
class CATPolyFace;


// Allows users to populate a list of intersection anomalies for use by
// CATPolyBodyRemoveIntersectingSlivers and CATPolyBodyRemeshPatches.
class ExportedByPolyBodyCheckedEditor CATPolyBodyIntersectionAnomalyList
{
public:

  CATPolyBodyIntersectionAnomalyList();

  HRESULT AddPair(int facetIndex1,
                  CATPolyFace *face1,
                  int facetIndex2,
                  CATPolyFace *face2);
  HRESULT AddPair(int facetIndex1,
                  CATPolyFace *face1,
                  int facetIndex2,
                  CATPolyFace *face2,
                  const CATLISTV(CATMathPoint) & iIntersection);

  class Impl;
  // For local usage only.
  const Impl* GetImpl() const;

  ~CATPolyBodyIntersectionAnomalyList();

private:
  std::unique_ptr<Impl> _impl;
};
#endif
