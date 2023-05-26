// COPYRIGHT Dassault Systemes 2021
//===================================================================
//
// VisStreamlineHelper.h
// Header definition of VisStreamlineHelper
//
//===================================================================
//
// Usage notes:
//
//===================================================================

#ifndef VisStreamlineHelper_H
#define VisStreamlineHelper_H

#include "SGInfra.h"
#include "CATMathDirectionf.h"
#include "CATMathPointf.h"
#include "CATSysErrorDef.h"
#include "vector"
#include "memory"
#include "cstdint"

class VisStreamlineTubeBuilder;
class VisRawBuffer;

namespace VisStreamlineHelper
{
  //////////////////   TUBE TESS ALGO V1 (START) : TO BE REMOVED AFTER MIGRATING TO V2  ///////////////////////
  enum class ExportedBySGInfra TextureCoordinateDimension : uint8_t
  {
    eNoTexture = 0,
    e1D = 1,
    e2D = 2,
    e3D = 3
  };

  /**
  * Line strip which optionally can have texture coordinate set(s)
  */
  class ExportedBySGInfra LineStrip
  {
  public:
    // vertex coordinates (x, y, z)
    // size = number of vertices * 3
    std::vector<float> vertices;

    // primary texture coordinate set (optional)
    // size = _vertices.size()/3 * _textureDimension
    TextureCoordinateDimension textureDimension = TextureCoordinateDimension::eNoTexture;
    std::vector<float> textureCoordinates; 

    // secondary texture coordinate set (optional)
    // size = _vertices.size()/3 * _auxTextureDimension
    TextureCoordinateDimension auxTextureDimension = TextureCoordinateDimension::eNoTexture;
    std::vector<float> auxTextureCoordinates;
  };
  //////////////////////////   TUBE TESS ALGO V1 (END)   /////////////////////////////////////////////

  /**
  * Tessellated tube closed at both ends made up of triangles 
  */
  class ExportedBySGInfra Tube
  {
  public:
    //////////////////   TUBE TESS ALGO V1 (START) : TO BE REMOVED AFTER MIGRATING TO V2  ///////////////////////
    // vertex coordinates (x, y, z)
    // size = number of vertices * 3
    std::vector<float> vertices;

    // per vertex normals (x, y, z)
    // size = _vertices.size()
    std::vector<float> normals;

    // primary texture coordinate set 
    // size = _vertices.size()/3 * _textureDimension
    TextureCoordinateDimension textureDimension = TextureCoordinateDimension::eNoTexture;
    std::vector<float> textureCoordinates;

    // secondary texture coordinate set 
    // size = _vertices.size()/3 * _auxTextureDimension
    TextureCoordinateDimension auxTextureDimension = TextureCoordinateDimension::eNoTexture;
    std::vector<float> auxTextureCoordinates;

    // trianlge indices array (3 indices per triangle)
    // size % 3 = 0
    std::vector<unsigned int> triangleIndices;

    // triangle strip array (each strip may contain variable number of indices)
    std::vector<unsigned int> nbIndicesPerTriangleStrip;
    // size = SUM { _nbIndicesPerTriangleStrip[...] }
    std::vector<unsigned int> triangleStripIndices;
    //////////////////////////   TUBE TESS ALGO V1 (END)   /////////////////////////////////////////////

    //////////////////////////   TUBE TESS ALGO V2 (START)   /////////////////////////////////////////////
    /**
    * Class tube is created with basic parameters needed to compute resulting number of vertices and triangles.
    * These parameters are necessary for execution of all class functions. Their validity will be checked in all of them.
    * - iNbLineStripVertices: number of vertices in line strip. At least two vertices are needed to generate tube.
    * - iRadius: radius of tube. Must be > 0.f
    * - iNumSegsOnCircle: Defines how fine or coarse circular tube cross section should be. Can be == 0 or > 2.
    *     If it is 0, number is calculated from current 3D accuracy setting. (min 3)
    */

    Tube(size_t iNbLineStripVertices, float iRadius, size_t iNumSegsOnCircle = 0);

    ~Tube();

    /**
    * Get number of vertices of the tube based on parameters passed in constructor.
    */
    size_t GetNumberOfVertices();

    /**
    * Get number of triangles of the tube based on parameters passed in constructor.
    */
    size_t GetNumberOfTriangles();

    /*
    * Generate TRIANGLES representing a tube formed by sweeping a circle of given radius along the given path.
    * Both ends of the tube are closed.
    * Inputs:
    * - ipLineStripVertexCoord: float array interpreted as consecutive line strip coordinates
    *     P1.xyz, P2.xyz, ...
    *     size >= iNbLineStripVertices * 3 
    * Outputs:
    * - iopTubeVertices: raw buffer to store tube vertices with interleaved point coordinates and normals
    *     V1.xyz, N1.xyz, V2.xyz, N2.xyz, ...
    *   Caller need to allocate buffer with sufficient memory before calling this function.
    *   Size in bytes >= GetNumberOfVertices() * 6 * sizeof(float)
    * - iopTubeTrianglesIndices: raw buffer of integers representing vertex indices forming serier of simple triangles 
    *   Size in bytes >= GetNumberOfTriangles() * 3 * sizeof(unsigned int) 
    *   Can be null. In this case, only vertices are updated.
    * Return:
    * - S_OK: success
    * - E_INVALIDARG: ipLineStripVertexCoord is null or iNbPts < 2
    * - E_OUTOFMEMORY: output buffers have insufficient memory allocation
    * - E_FAIL: Tube object is not constructed correctly. See arguments passed to be constructor.
    */
    HRESULT GenerateTriangles(const float* ipLineStripVertexCoord, 
      VisRawBuffer* opTubeVertices, VisRawBuffer* opTubeTrianglesIndices);

    /**
    * Copy data from line strip vertices to corresponding tube vertices (all vertices on circular profile)
    * Useful for transferring data like texture coordinates from a line strip to tube vertices.
    * Inputs:
    * - ipLineStripData: raw buffer containing consecutive data for line strip vertices
    *     size in bytes >= iNbLineStripVertices * iBytesToCopy
    * - iBytesToCopy: size in bytes of data per vertex. Can’t be 0. 
    * Example: for 2D texture coordinates
    *   iBytesToCopy = ‘2 * sizeof(float)’ 
    *   ipLineStripData = array of float of size (iNbLineStripVertices * 2).. u1,v1, u2,v2, ... 
    * Outputs:
    * - opTubeData: raw buffer representing data for tube vertices
    *   Caller need to allocate buffer with sufficient memory before calling this function.
    *   Size in bytes >= GetNumberOfVertices() * iBytesToCopy
    * Return:
    * - S_OK: success
    * - E_INVALIDARG: iLineStripData is null or iBytesToCopy is zero or opTubeData is null
    * - E_OUTOFMEMORY: opTubeData have insufficient memory allocation
    * - E_FAIL: Tube object is not constructed correctly. See arguments passed to be constructor.
    */
    HRESULT CopyData(const void* ipLineStripData, size_t iBytesToCopy,
      VisRawBuffer*& opTubeData);

  private:
    size_t m_NbLineStripVertices = 0;
    size_t m_NumSegsOnCircle = 0;
    float m_Radius = 0.f;

    VisStreamlineTubeBuilder* m_pBuilder = nullptr;
    int GetNumberOfSegments(float iRad);
    //////////////////////////   TUBE TESS ALGO V2 (END)   /////////////////////////////////////////////
  };

  //////////////////   TUBE TESS ALGO V1 (START) : TO BE REMOVED AFTER MIGRATING TO V2  ///////////////////////
  /**
  * Helper function to create tessellated tube from line strip and radius.
  * Input: 
  *   iLine: line strip with optional texture coordinate sets
  *     Conditions checked:
  *     - Needs to have at least 2 points 
  *     - Texture coordinate size can be of 0 if no texture coordinates are to be considered.
  *       But, in case size is not zero, size should be = (_vertices.size() / 3) * textureDim
  *   iRadius must be > 0.f
  *   iNumSegsOnCircle: Defines how fine or coarse circular tube cross section should be
  *     Can be 0, in this case number is calculated from 3D accuracy setting
  *     Otherwise, must be > 2.
  * Return:
  *   Tessellated tube defined by vertices and triangle (strip) indices 
  *   (provided texture coordinates are copied to corresponding vertices of tube)
  */
  ExportedBySGInfra std::unique_ptr<Tube> CreateTube(const LineStrip &iLine,
    float iRadius, int iNumSegsOnCircle = 0);
  //////////////////////////   TUBE TESS ALGO V1 (END)   /////////////////////////////////////////////

  /* Internal functions */
  std::vector<float> GetPointsOnCircle(const CATMathPointf& iCenter,
    const CATMathDirectionf& iNormal, float iRadius, size_t iNumSegsOnCircle);

};


#endif
