//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBVHTreeFilterHidden.h
//
//=============================================================================
// 2009-05-12   JXO
//      * New
//=============================================================================
#ifndef CATPolyBVHTreeFilterHidden_H
#define CATPolyBVHTreeFilterHidden_H

#include "CATSysBoolean.h"
#include "CATPolyBVHTreeVisualizationFilter.h"
#include "PolyVisuBVH.h"

class CATRep;
class CATGraphicPrimitive;
class CATVizPrimitive;

//------------------------------------------------------------------

/**
 * This class filters out hidden reps and GP
 */
class ExportedByPolyVisuBVH CATPolyBVHTreeFilterHidden : public CATPolyBVHTreeVisualizationFilter
{
public:
  CATPolyBVHTreeFilterHidden(){};
  virtual ~CATPolyBVHTreeFilterHidden(){};

public:
  virtual CATBoolean Filter(CATRep * pRep) const;
  virtual CATBoolean Filter(CATGraphicPrimitive * pGP) const;
  virtual CATBoolean Filter(CATVizPrimitive * pVP) const;

};

#endif // !CATPolyBVHTreeFilterHidden_H
