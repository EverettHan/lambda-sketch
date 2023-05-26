// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyFromTrianglesBuilder.h
//
//===================================================================
// August 2014  Creation: JXO
//===================================================================
#ifndef CATPolyBodyFromTrianglesBuilder_H
#define CATPolyBodyFromTrianglesBuilder_H

#include "PolyBodyDecimate.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATPolyBodyBarGraph;
class CATMathPoint;
class CATPolyBarGraphNodePositionLayer;
#include "CATMapOfFloatsToInt.h"
#include "CATMapOfIntToInt.h"


/**
 * This operator constructs a poly body from a list of triangles defined by three points
 * without any reference to a vertex number.  It uses internally a hash table to match 
 * the point to a vertex index for construction of a poly body.
 * There are no tolerances involved.  Only points that have identical coordinates will map to
 * the same vertex.
 * Once all the vertices and triangles are added, contiguous and manifold surfaces are 
 * constructed.
 */
class ExportedByPolyBodyDecimate CATPolyBodyFromTrianglesBuilder
{

public :

  CATPolyBodyFromTrianglesBuilder ();

  ~CATPolyBodyFromTrianglesBuilder ();

  /**
   * Adds a triangle and returns its index.
   * @param iIdxVertices
   * The indices of the three vertices.
   * @param oIdxTriangle
   * The index of the added triangle.
   * @return
   * S_OK if the triangle is added successfully.
   * E_FAIL otherwise.
   */
  HRESULT AddTriangle (const CATMathPoint iIdxVertices[3], int &oIdxTriangle);

  /**
   * Returns constructed CATPolyBody. To be released by caller
   * @param iAngleForSmoothEdges
   *   If set to a positive (or null) value, any face bar with a dihedral angle superior or equal to this value will be considered sharp, hence an edge bar.
   */
  HRESULT GetPolyBody (CATPolyBody *& oPolyBody, double iAngleForSmoothEdges = -1. /*CATPIBY4*/);

private:

  void Clear();
  CATPolyBodyBarGraph * m_BarGraph;
  CATPolyBarGraphNodePositionLayer * m_PositionsLayer;
  CATMapOfFloatsToInt m_Vertices;
  int m_mainface;
};

#endif
