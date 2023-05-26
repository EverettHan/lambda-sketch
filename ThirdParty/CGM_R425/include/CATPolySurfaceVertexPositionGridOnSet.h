//=============================================================================
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Filter that sets and gets gridded vertex positions.
//
//=============================================================================
// 2008-07-21   NDO: New
//=============================================================================
#ifndef CATPolySurfaceVertexPositionGridOnSet_H
#define CATPolySurfaceVertexPositionGridOnSet_H

#include "CATPolyGriddingTools.h"
#include "CATPolyGriddedPositions.h"
#include "CATErrorDef.h"

class CATPolyExactArithmetic;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurfaceVertexIterator;


class ExportedByCATPolyGriddingTools CATPolySurfaceVertexPositionGridOnSet : 
  public CATPolyGriddedPositions
{

public:

  // Construct an instance of the filter.
  // The positions of the vertices returned by the iterator are gridded in this process by the instance
  // of exact arithmetic.
  CATPolySurfaceVertexPositionGridOnSet (const CATPolyExactArithmetic& iExactArithmetic,
                                         CATIPolySurfaceVertexPositionLayer& iPositionLayer,
                                         CATIPolySurfaceVertexIterator& iIterator);

  virtual ~CATPolySurfaceVertexPositionGridOnSet ();

public:

  // Set the coordinates of a vertex.  The coordinates are gridded when they are set in the layer.
  HRESULT Set (int v, double x, double y, double z);

  // Get the coordinates of a vertex.
  HRESULT Get (int v, double &x, double &y, double &z) const;

private:

  CATIPolySurfaceVertexPositionLayer& _PositionLayer;

};

#endif // !CATPolySurfaceVertexPositionGridOnSet_H
