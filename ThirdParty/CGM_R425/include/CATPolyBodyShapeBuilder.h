// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyShapeBuilder.h
//
//===================================================================
// April 2015  Creation: JXO
//===================================================================
#pragma once

#include "PolyBodyTools.h"
#include "CATErrorDef.h"  // HRESULT

// Poly
class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;

// Math
class CATMathPoint;
class CATMathVector;


namespace Poly
{

  enum Topology
  {
    Topology4V4E3F = 0,
    TopologyNV4E3F = 1,
    Topology2V2E3F = 2,
    TopologyNV2E3F = 3,
    Topology0V2E3F = 4,
    Topology0V0E1F = 5,
    Topology4V5E3F = 6,
    Topology4V6E4F = 7,
    Topology2V3E3F = 8
  };

  /**
   * Make a solid CATPolyBody representing a hexahedron.
   * The CATPolyBody returned should be released by the caller.
   * 
   * @param iPoints
   *   The eight points defining the six faces of the hexahedron:
   *     * Face 1: 0, 1, 2, 3
   *     * Face 2: 1, 5, 3, 7
   *     * Face 3: 5, 4, 7, 6
   *     * Face 4: 4, 0, 6, 2
   *     * Face 5: 2, 3, 6, 7
   *     * Face 6: 4, 5, 0, 1
   * 
   *    If the geometry of the faces is planar, the hexadron becomes a parallelepiped
   *    as follows:
   * 
   *     4------5
   *    /|     /|
   *   0 ---- 1 |
   *   | |    | |
   *   | 6  - | 7
   *   |/     |/
   *   2------3
   */
  ExportedByPolyBodyTools CATPolyBody* NewHexahedron (const CATMathPoint iPoints[8], bool iWithSupports, bool iWithUVLayers, bool iWithTextLayers, 
    bool isSolid = true);

  ExportedByPolyBodyTools HRESULT AddHexahedron (CATPolyBody& B, const CATMathPoint iPoints[8], bool iWithSupports, bool iWithUVLayers, bool iWithTextLayers,
    bool isSolid = true);

  /**
   * Append a hexadron to a solid CATPolyBody by addition of a volume from a chosen face.
   * A new volume VLM is added to the CATPolyBody in this operation.
   *
   * @param B
   *   The input CATPolyBody.  The hexahedron volume is added to this CATPolyBody.
   * @param F
   *   The face from the input body for construction of the new hexahedron.
   *   The face must contain four edges.
   * @param iPoints
   *   The four points for definition of the five new faces of the new volume.
   *     * Face 1: a, b, 1, 0
   *     * Face 2: 0, 1, 2, 3
   *     * Face 3: 3, 2, c, d
   *     * Face 4: a, 0, 3, d
   *     * Face 5: c, 2, b, 1
   *   The points abcd are in those from the sequence of the CATPolyFaceLoopEdgeIterator.
   * 
   *   If the geometry of the faces is planar, the hexadron added is a parallelepiped:
   *
   *     +------d------------3
   *    /|     /|           /|
   *   + ---- a------------0 |
   *   | |    |F|  VLM     | |
   *   | +  - | c - - - - -|-2
   *   |/     |/           |/
   *   +------b------------1
   */
  ExportedByPolyBodyTools HRESULT AppendHexahedron (CATPolyBody& B, CATPolyFace& F, const CATMathPoint iPoints[4], bool iWithSupports, bool iWithUVLayers, bool iWithTextLayers);

  ExportedByPolyBodyTools CATPolyBody* NewCylinder (const CATMathPoint iPoints[2], double iRadius1, double iRadius2, double iAngle,
    bool iWithSupports, bool iWithUVLayers, bool iWithTextLayers, bool isSolid = true,
    Poly::Topology iTopo = Poly::Topology4V4E3F);

}


class ExportedByPolyBodyTools CATPolyBodyShapeBuilder
{
public:
  /**
   *
   *     4------5
   *    /|     /|
   *   0 ---- 1 |
   *   | |    | |
   *   | 6  - | 7
   *   |/     |/
   *   2------3
   *
   * To be released by caller
   * Cuboid will contain support layers, uv and texture layers
   */
  static CATPolyBody * BuildCuboid(const CATMathPoint iPoints[8], bool isSolid = true); 
  /**
   * @param iAngle
   *        Angle (in degrees) between two vertices on the sphere. Rounded to have clean division of the 360 degrees.
   *        Default is 10 degrees.
   * To be released by caller
   * Ellipsoid will contain support layers, uv and texture layers
   */
  static CATPolyBody * BuildEllipsoid(const CATMathPoint & iCenter, const CATMathVector iAxis[3], bool isSolid, double iAngle, bool iCylindricProjection); 
  /**
   *   
   *        ^
   *     3--|---2
   *    /   |  /
   *   0------1
   *
   * To be released by caller
   * Quad will contain support layers, uv and texture layers
   */
  static CATPolyBody * BuildQuad(const CATMathPoint iPoints[4]);

  /**
   *
   *     4------5
   *    /|     /|
   *   0 ---- 1 |
   *   | |    | |
   *   | 6  - | 7
   *   |/     |/
   *   2------3
   *
   * Construct an editable (CATPolyMeshImpl) cuboid.
   * To be released by caller
   */
  static CATIPolyMesh * BuildCuboidMesh(const CATMathPoint iPoints[8]);

  /**
   * NOT IMPLEMENTED YET
   * @param iAngle
   *        Angle (in degrees) between two vertices on the sphere. Rounded to have clean division of the 360 degrees.
   *        Default is 10 degrees.
   *
   * To be released by caller
   */
  static CATPolyBody * BuildCylinder(const CATMathPoint iPoints[2], double iRadius1, double iRadius2, bool isSolid, double iAngle, bool iWithSupports, bool iWithUVLayers, bool iWithTextLayers);


protected:
  CATPolyBodyShapeBuilder(){}
  ~CATPolyBodyShapeBuilder(){}
};

