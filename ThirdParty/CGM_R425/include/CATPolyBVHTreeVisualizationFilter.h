//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBVHTreeVisualizationFilter.h
//
//=============================================================================
// 2009-01-26   JXO
//      * New
//=============================================================================
#ifndef CATPolyBVHTreeVisualizationFilter_H
#define CATPolyBVHTreeVisualizationFilter_H

#include "CATBoolean.h"

#include "PolyVisuBVH.h"

class CATRep;
class CATGraphicPrimitive;
class CATVizPrimitive;
class CATMathTransformation;

//------------------------------------------------------------------

/**
 * This class defines an interface to filter out reps or GP when constructing
 * a CATPolyBVHTree from a scene graph.
 * <br />Applications should derive and implement this class.
 * <br />See CATBVHTreeRepBuilder for further explanations.
 */
class ExportedByPolyVisuBVH CATPolyBVHTreeVisualizationFilter
{
public:
  CATPolyBVHTreeVisualizationFilter():_Ref(1){};
  virtual ~CATPolyBVHTreeVisualizationFilter(){};

public:
  /*
   * Returns TRUE if Rep is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(CATRep * pRep) const = 0;
  /*
   * Returns TRUE if Graphic Primitive is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(CATGraphicPrimitive * pGP) const = 0;
  /*
   * Returns TRUE if Viz Primitive is NOT to be taken into account, FALSE otherwise.
   */
  virtual CATBoolean Filter(CATVizPrimitive * pVP) const = 0;
  
public:
  inline void AddRef(){++_Ref;}
  void Release();

private:
  unsigned int _Ref;
};

#endif // !CATPolyBVHTreeVisualizationFilter_H
