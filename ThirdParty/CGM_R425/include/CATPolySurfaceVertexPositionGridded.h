//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Filter that sets and gets gridded vertex positions.
//
//=============================================================================
// 2008-07-21   NDO: New
//=============================================================================
#ifndef CATPolySurfaceVertexPositionGridded_H
#define CATPolySurfaceVertexPositionGridded_H

#include "CATPolyGriddingTools.h"
#include "CATPolyGriddedPositions.h"
#include "CATErrorDef.h"

class CATPolyExactArithmetic;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurface;


class ExportedByCATPolyGriddingTools CATPolySurfaceVertexPositionGridded : 
  public CATPolyGriddedPositions
{

public:

  // Construct an instance of the filter with a layer of vertex positions that have already been gridded.
  CATPolySurfaceVertexPositionGridded (const CATPolyExactArithmetic& iExactArithmetic,
                                       CATIPolySurfaceVertexPositionLayer& iPositionLayer);

  // Construct an instance of the filter with CATIPolySurface whose vertices have already been gridded.
  CATPolySurfaceVertexPositionGridded (const CATPolyExactArithmetic& iExactArithmetic,
                                       CATIPolySurface& iPolySurface);

  virtual ~CATPolySurfaceVertexPositionGridded ();

public:

  // Set the coordinates of a vertex.
  HRESULT Set (int v, double x, double y, double z);

  // Get the coordinates of a vertex.
  HRESULT Get (int v, double &x, double &y, double &z) const;

private:

  CATIPolySurfaceVertexPositionLayer* _PositionLayer;

};

#endif // !CATPolySurfaceVertexPositionGridded_H
