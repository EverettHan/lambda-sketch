//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Filter that sets and gets gridded vertex positions.
//
//=============================================================================
// 2008-07-21   NDO: New
//=============================================================================
#ifndef CATPolySurfaceVertexPositionGridOnGet_H
#define CATPolySurfaceVertexPositionGridOnGet_H

#include "CATPolyGriddingTools.h"
#include "CATPolyGriddedPositions.h"
#include "CATErrorDef.h"

class CATPolyExactArithmetic;
class CATIPolySurfaceVertexPositionLayer;


class ExportedByCATPolyGriddingTools CATPolySurfaceVertexPositionGridOnGet :
  public CATPolyGriddedPositions
{

public:

  // Construct an instance of the filter.
  // The positions of the vertices returned by the iterator are gridded in this process by the instance
  // of exact arithmetic.
  CATPolySurfaceVertexPositionGridOnGet (const CATPolyExactArithmetic& iExactArithmetic, 
                                         CATIPolySurfaceVertexPositionLayer& iPositionLayer);

  virtual ~CATPolySurfaceVertexPositionGridOnGet ();

public:

  // Set the coordinates of a vertex in the layer.
  HRESULT Set (int v, double x, double y, double z);

  // Get the gridded coordinates of a vertex.  The coordinates are fetched from the layer and gridded.
  HRESULT Get (int v, double &x, double &y, double &z) const;

private:

  CATIPolySurfaceVertexPositionLayer& _PositionLayer;

};

#endif // !CATPolySurfaceVertexPositionGridOnGet_H
