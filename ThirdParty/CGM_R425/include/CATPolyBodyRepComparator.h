//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATPolyBodyRepComparator
//
// Compare a macro polyhedral body to a graphical rep
//
//=============================================================================
// 2007-07-26   BPG: New.
//=============================================================================
#ifndef CATPolyBodyRepComparator_H
#define CATPolyBodyRepComparator_H

#include "CATErrorDef.h"

#include "CATPolyMacroTopologyFwd.h"
#include "PolyVizUtils.h"

//
class CATRep;
class CATCGMHashTableWithAssoc;

//
class ExportedByPolyVizUtils CATPolyBodyRepComparator
{
public:
  CATPolyBodyRepComparator();
  ~CATPolyBodyRepComparator();

public:
  HRESULT Compare(CATPolyBody &iBody, CATRep &iRep, CATCGMHashTableWithAssoc *iVizFaceToPolyFace) const;
};

// ----------------------------------------------------------------------------

inline
CATPolyBodyRepComparator::CATPolyBodyRepComparator()
{}

inline
CATPolyBodyRepComparator::~CATPolyBodyRepComparator()
{}

#endif // !CATPolyBodyRepComparator_H
