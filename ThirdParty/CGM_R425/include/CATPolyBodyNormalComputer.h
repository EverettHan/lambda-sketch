// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyNormalComputer.h
// Header definition of CATPolyBodyNormalComputer
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2009 Creation ZFI
//===================================================================
#ifndef CATPolyBodyNormalComputer_H
#define CATPolyBodyNormalComputer_H

#include "PolyBodyServices.h"
#include "CATErrorDef.h"  // Definition of HRESULT.

#include "CATMathConstant.h"

class CATPolyBody;
class CATPolyEdge;
class CATPolyVertex;

class ExportedByPolyBodyServices CATPolyBodyNormalComputer
{
public:

  CATPolyBodyNormalComputer ();
  virtual ~CATPolyBodyNormalComputer ();

public: 
  /** 
   * Recomputes the vertex normals of a CATPolyBody, by summing the normals to the triangles around each vertex, weighted by the triangle angles.
   * @param ioPolyBody
   *        Editable CATPolyBody whose normals will computed. Normal layers are added if none is present
   * @param iAngleForSmoothEdges
   *        If set to a positive value, will be used as the minimum value (Radian) for the normals around an edge vertex to be considered sharp.
   *        Any smaller value and the edge vertex will be considered smooth.
   */
  static HRESULT ComputeVertexNormals(CATPolyBody& ioPolyBody, double iAngleForSmoothEdges = -1. /*CATPIBY4*/);

  /** 
   * Recomputes the vertex normals of the two CATIPolySurface along a common CATPolyEdge. CATPolyBody needs to be editable, and CATIPolySurface's need normal layers.
   * @param ioPolyEdge
   *        Input poly edge, along which normals are to be computed.
   * @param iAngleForSmoothEdge
   *        Will be used as the minimum value (Radian) for the normals around an edge vertex to be considered sharp.
   *        Any smaller value and the edge vertex will be considered smooth.
   *        If set to a negative value, then this method does nothing.
   * @param iTreatStartAndEndVertex
   *        If set to FALSE, start and end vertex won't be treated.
   *        If set to TRUE, start and end vertex are treated but only for this particular edge.
   */
  static HRESULT ComputeVertexNormals(CATPolyEdge& ioPolyEdge, double iAngleForSmoothEdge = CATPIBY4, CATBoolean iTreatStartAndEndVertex = TRUE);

  /** 
   * Recomputes the vertex normals of all the CATIPolySurface incident to a common CATPolyVertex. CATPolyBody needs to be editable, and CATIPolySurface's need normal layers.
   * @param ioPolyVertex
   *        Input poly vertex, where normals are to be computed.
   * @param iAngleForSmoothEdge
   *        Will be used as the minimum value (Radian) for the normals for each side of an edge to be considered sharp.
   *        Any smaller value and the edge will be considered smooth.
   *        If set to a negative value, then this method does nothing.
   */
  static HRESULT ComputeVertexNormals(CATPolyVertex& ioPolyVertex, double iAngleForSmoothEdges = CATPIBY4);

};

#endif
