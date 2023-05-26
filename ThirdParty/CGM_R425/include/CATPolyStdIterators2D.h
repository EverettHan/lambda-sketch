#ifndef CATPolyStdIterators2D_H
#define CATPolyStdIterators2D_H

#include "CATPolyStdIteratorsUtilities2D.h"

namespace Poly
{

  /*
   * Construct a class implementing C++ range interface for iterating over polygon faces
   * CATPolyPolygonFaceRange2D::Iterator::operator* returns a CATPolyFace2D &
   */
  inline CATPolyPolygonFaceRange2D Faces(CATPolyPolygon2D const &iPolygon, bool iSkipHoleFaces = true)
  {
    return CATPolyPolygonFaceRange2D(iPolygon, iSkipHoleFaces);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over polygon loops
   * CATPolyPolygonLoopRange2D::Iterator::operator* returns a CATPolyLoop2D &
   */
  inline CATPolyPolygonLoopRange2D Loops(CATPolyPolygon2D const &iPolygon)
  {
    return CATPolyPolygonLoopRange2D(iPolygon);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over polygon bars
   * CATPolyPolygonBarRange2D::Iterator::operator* returns a CATPolyBar2D &
   */
  inline CATPolyPolygonBarRange2D Bars(CATPolyPolygon2D const &iPolygon, bool iIncludeFullVertex = false, bool iIncludeSegments = true, bool iIncludeArcs = true)
  {
    return CATPolyPolygonBarRange2D(iPolygon, iIncludeFullVertex, iIncludeSegments, iIncludeArcs);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over polygon vertices
   * CATPolyPolygonVertexRange2D::Iterator::operator* returns a CATPolyVertex2D &
   */
  inline CATPolyPolygonVertexRange2D Vertices(CATPolyPolygon2D const &iPolygon)
  {
    return CATPolyPolygonVertexRange2D(iPolygon);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over polygon wires
   * CATPolyPolygonFaceRange2D::Iterator::operator* returns a CATPolyWire2D &
   */
  inline CATPolyPolygonWireRange2D Wires(CATPolyPolygon2D const& iPolygon)
  {
    return CATPolyPolygonWireRange2D(iPolygon);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over face loops
   * CATPolyFaceLoopRange2D::Iterator::operator* returns a CATPolyLoop2D &
   */
  inline CATPolyFaceLoopRange2D Loops(CATPolyFace2D const &iFace)
  {
    return CATPolyFaceLoopRange2D(iFace);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over loop vertices
   * CATPolyPolygonVertexRange2D::Iterator::operator* returns a CATPolyVertex2D &
   */
  inline CATPolyLoopVertexRange2D Vertices(CATPolyLoop2D const &iLoop)
  {
    return CATPolyLoopVertexRange2D(iLoop);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over loop bars
   * CATPolyLoopBarRange2D::Iterator::operator* returns a CATPolyBar2D &
   */
  inline CATPolyLoopBarRange2D Bars(CATPolyLoop2D const &iLoop)
  {
    return CATPolyLoopBarRange2D(iLoop);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over loop (vertex, bar) pairs
   * CATPolyLoopBarRange2D::Iterator::operator* returns a std::pair<CATPolyVertex2D &, CATPolyBar2D &>
   */
  inline CATPolyLoopVertexBarRange2D VerticesBars(CATPolyLoop2D const &iLoop)
  {
    return CATPolyLoopVertexBarRange2D(iLoop);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over wire vertices
   * CATPolyPolygonVertexRange2D::Iterator::operator* returns a CATPolyVertex2D &
   */
  inline CATPolyWireVertexRange2D Vertices(CATPolyWire2D const& iWire)
  {
    return CATPolyWireVertexRange2D(iWire);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over wire bars
   * CATPolyLoopBarRange2D::Iterator::operator* returns a CATPolyBar2D &
   */
  inline CATPolyWireBarRange2D Bars(CATPolyWire2D const& iWire)
  {
    return CATPolyWireBarRange2D(iWire);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over loop (vertex, bar) pairs
   * CATPolyLoopBarRange2D::Iterator::operator* returns a std::pair<CATPolyVertex2D &, CATPolyBar2D &>
   */
  inline CATPolyWireVertexBarRange2D VerticesBars(CATPolyWire2D const& iWire)
  {
    return CATPolyWireVertexBarRange2D(iWire);
  }

  /*
   * Construct a class implementing C++ range interface for iterating over vertex bars
   * CATPolyVertexBarRange2D::Iterator::operator* returns a CATPolyBar2D &
   */
  inline CATPolyVertexBarRange2D Bars(CATPolyVertex2D const& iVertex)
  {
    return CATPolyVertexBarRange2D(iVertex);
  }
}

#endif
