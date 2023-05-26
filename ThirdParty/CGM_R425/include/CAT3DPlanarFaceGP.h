#ifndef CAT3DPlanarFaceGP_H
#define CAT3DPlanarFaceGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DPlanarFaceGP
//                  CAT3DFaceGP
//                    CAT3DBoundingGP
//                      CATGraphicPrimitive
//                        CATBaseUnknown (SYSTEM framework)
//
//******************************************************************************
//  Main Methods:
//  -------------
//    Drawing.
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DFaceGP.h"
class CATStreamer;

/**
 * Class to create the graphic primitive of a 3D planar face.
 * <b>Role</b>: Special face with only one normal for every vertices.
 * To be used like a CAT3DFaceGP, but with only one normal.
 */
class ExportedBySGInfra CAT3DPlanarFaceGP :public CAT3DFaceGP
{

  friend class CATMarshallable3DPlanarFaceGP;
  CATDeclareClass;
  
  
public:
    
  /**
   * Default constructor
   */
  CAT3DPlanarFaceGP (void);

  /**
   * Constructs a 3D planar face graphic primitive from the face vertices coordinates list,
   * and their texture coordinates.  Relying on the allocation mode, parameter data may have to be freed
   * after the face is created. Set, strip and fan information is always
   * duplicated at the face creation. Texture information can be provided
   * at this stage when the texture coordinates have already been computed.
   * @param iVertices
   *    Array made of vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face vertices number.
   * @param iVerticesArraySize
   *    The size, in floats, of the <tt>iVertices</tt> array. Equal to three times the
   *    vertices number.
   * @param iNormals
   *    Array made of the normal coordinates. Its size is always equal to three. 
   * @param iTriangleIndices
   *    This array is used to store the single triangles vertices. Each of its field represents
   *    a vertex index in the <tt>iVertices</tt> array.
   *    As we find, in the <tt>iVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    So, the first three indices of the <tt>iTriangleIndices</tt> array, are the three vertices indices of the face first
   *    single triangle.
   *    <pre>
   *
   *                 -----------------       
   *                | iTriangleIndices|
   *                 -----------------
   *                |       i00       |   }
   *                |       i01       |   } triangle 0 defined by index i00, i01 and i02
   *                |       i02       |   }
   *                |        .        |
   *                |        .        |
   *                |       ij0       |   }
   *                |       ij1       |   } triangle j defined by index ij0, ij1 and ij2. 
   *                |       ij2       |   }
   *                |        .        |
   *                |        .        |
   *                 -----------------
   *
   *   </pre>
   *    For example, index ij0 enables access to the face j-th single triangle first vertex,
   *    which coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal has coordinates Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   * @param iNbTriangle
   *    The number of single triangles in the face. 
   * @param iTriangleStripIndices
   *    Array used to store the face triangles strips vertices. Each field contains a
   *    vertex index, in the <tt>iVertices</tt> array.  As, we find, in the
   *    iVertices array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | iTriangleStripIndices|
   *                   ----------------------
   *                  |          i00         |   }
   *                  |          i01         |   } first triangle strip defined
   *                  |           .          |   } by the first n1 indices
   *                  |           .          |   }
   *                  |          i0n1        |   }
   *                  |           .          |
   *                  |           .          |
   *                  |           .          |   
   *                  |          ij0         |   }
   *                  |          ij1         |   }
   *                  |           .          |   } triangle strip j
   *                  |           .          |   } with nj vertices
   *                  |          ijnj        |   }
   *                   ----------------------
   *
   *
   *    </pre> 
   *    For example, index ij0 allows to access to the face j-th strip first vertex 
   *    wich coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal coordinates are Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   * @param iNbTriangleStrip
   *    The number of face triangles strips.
   * @param iNbVertexPerTriangleStrip
   *    Array containing the number of vertices for each face triangles strip.
   *    The size of this array is equal to <tt>iNbTriangleStrip</tt>. For example, the first strip
   *    is made with <tt>iNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               |iNbVertexPerTriangleStrip |
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle strips(iNbTriangleStrip)
   *               |             nm           |   nm = number of vertices of the m-th strip. (iNbVertexPerTriangleStrip[m]
   *                --------------------------    
   *
   *   </pre>
   * @param iTriangleFanIndices
   *    Array used to store the face triangles fans vertices. Each field contains a
   *    vertex index, in the iVertices array.  As, we find, in the
   *    <tt>iVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | iTriangleFanIndices   |
   *                   ----------------------
   *                  |          i00         |   }
   *                  |          i01         |   } first triangle fan defined
   *                  |           .          |   } by the first n1 indices
   *                  |           .          |   }
   *                  |          i0n1        |   }
   *                  |           .          |
   *                  |           .          |
   *                  |           .          |   
   *                  |          ij0         |   }
   *                  |          ij1         |   }
   *                  |           .          |   } triangle fan j
   *                  |           .          |   } with nj vertices
   *                  |          ijnj        |   }
   *                   ----------------------
   *
   *
   *    </pre> 
   *    For example, index ij0 allows to access to the face j-th fan first vertex
   *    wich coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal coordinates are Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   *    Each ij0, j in [0, jn], represents the j-th fan center.
   * @param iNbTriangleFan
   *    The number of face triangles fans.
   * @param iNbVertexPerTriangleFan
   *    Array containing the number of vertices for each face triangles fan.
   *    The size of this array is equal to <tt>iNbTriangleFan</tt>. For example, the first fan
   *    is made with <tt>iNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               | iNbVertexPerTriangleFan  |
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle fans(iNbTriangleFan)
   *               |             nm           |   nm = number of vertices of the m-th fan. (iNbVertexPerTriangleFan[m]
   *                --------------------------    
   *
   *   </pre>
   * @param iTextureCoord
   *    Array of texture coordinates. Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   *    Because vertex and normal information is being sorted at the face
   *    creation, texture coordinates are to be generated with the tessellation
   *    parameters that are retrieved after the face creation (ie with
   *    properly translated indices). Nevertheless, a mapping operator can be
   *    applied at anytime, when the face is the owner of it's vertex data.
   *    If computed before the face creation, texture coordinates can be given
   *    at the face construction method. In this case, coordinates order is
   *    rearranged in parallel with vertices coordinates.
   * @param iTextureFormat
   *    <tt>iTextureFormat</tt> is the number of fields associated to one vertex in the <tt>iTextureCoord</tt> array.
   *    It is also the number of texture coordinates associated to each vertex.
   *    Indeed, each vertex has associated coordinates in the texture map. The
   *    number of coordinates depends on the map dimension: the texture map
   *    may be in 1D, 2D or 3D. 
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>1</dt>
   *        <dd>The texture map is a one dimension map. Each vertex has a single associated texture coordinate</dd>
   *      <dt>2</dt>
   *        <dd>The texture map is a two-dimension map. Each vertex has two associated texture coordinates</dd>
   *      <dt>3</dt>
   *        <dd>The texture map is a three-dimension map. Each vertex has three associated texture coordinates</dd>
   *   </dl>
   * @param iAllocMode
   *    The CAT3DFaceGP, and it's planar inherited object, the CAT3DPlanarFaceGP
   *    have allocation flags ruling their memory comsumption for vertices and
   *    normals:
   *    The default value is ALLOCATE_VERTICES | ALLOCATE_NORMALS.
   *    <b>CAUTION</b>: The CAT3DPlanarFaceGP is an immutable object. GET_***** alloc mode only avoid an expensive copy
   *    Modifying the iVertices pointer used with GET_VERTICES or the iNormals pointer used with GET_NORMALS won't update the CAT3DPlanarFaceGP's data. 
   *    You need to create a new GP, or recycle the old one with CAT3DFaceGPEditHelper, even if you used GET_****** alloc mode.
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>ALLOCATE_VERTICES</dt>
   *        <dd>Vertex array is the property of the face and
   *        is to be deleted with it. If textures are defined, texture coordinates
   *        are to be destroyed too.</dd>
   *   </dl>
   *   <dl>
   *      <dt>GET_VERTICES</dt>
   *        <dd>Vertex array is not duplicated at the face creation, but
   *        is to be deleted during the object deletion. Texture coordinates are
   *        to be shared, but in this case, their format must be 3.</dd>
   *   </dl>
   *   <dl>
   *      <dt> ALLOCATE_NORMALS</dt>
   *        <dd>Normal array is the property of the face and
   *        is to be deleted with it. Planar faces always allocate their normals.</dd>
   *   </dl>
   *   <dl>
   *      <dt> GET_NORMALS</dt>
   *        <dd>Normal array is not duplicated at the face creation
   *        although, as for vertices, it will be destroyed in the same time the object
   *        is deleted.</dd>
   *   </dl>
   */
  CAT3DPlanarFaceGP(const float  iVertices[],
                    const int    iVerticesArraySize,
                    const float  iNormals[],
                    const int    iTriangleIndice[],
                    const int    iNbTriangle,
                    const int    iTriangleStripIndice[],
                    const int    iNbTriangleStrip,
                    const int    iNbVertexPerTriangleStrip[],
                    const int    iTriangleFanIndice[],
                    const int    iNbTriangleFan,
                    const int    iNbVertexPerTriangleFan[],
                    const float *iTextureCoord=NULL,
                    const int    iTextureFormat=3,
                    const char   iAllocMode = ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES,
                    const float *iTanBinorm=NULL,
                    const float *iUV=NULL);
    
  /**
   * Constructs a 3D planar face graphic primitive from the face vertices coordinates list,
   * and their texture coordinates.  Relying on the allocation mode, parameter data may have to be freed
   * after the face is created. Set, strip and fan information is always
   * duplicated at the face creation. Texture information can be provided
   * at this stage when the texture coordinates have already been computed.
   * @param iVertices
   *    Array made of vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face vertices number.
   * @param iVerticesArraySize
   *    The size, in floats, of the <tt>iVertices</tt> array. Equal to three times the
   *    vertices number.
   * @param iNormals
   *    Array made of the normal coordinates. Its size is always equal to three. 
   * @param iTriangleIndices
   *    This array is used to store the single triangles vertices. Each of its field represents
   *    a vertex index in the <tt>iVertices</tt> array.
   *    As we find, in the <tt>iVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    So, the first three indices of the <tt>iTriangleIndices</tt> array, are the three vertices indices of the face first
   *    single triangle.
   *    <pre>
   *
   *                 -----------------       
   *                | iTriangleIndices|
   *                 -----------------
   *                |       i00       |   }
   *                |       i01       |   } triangle 0 defined by index i00, i01 and i02
   *                |       i02       |   }
   *                |        .        |
   *                |        .        |
   *                |       ij0       |   }
   *                |       ij1       |   } triangle j defined by index ij0, ij1 and ij2. 
   *                |       ij2       |   }
   *                |        .        |
   *                |        .        |
   *                 -----------------
   *
   *   </pre>
   *    For example, index ij0 enables access to the face j-th single triangle first vertex,
   *    which coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal has coordinates Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   * @param iNbTriangle
   *    The number of single triangles in the face. 
   * @param iTriangleStripIndices
   *    Array used to store the face triangles strips vertices. Each field contains a
   *    vertex index, in the <tt>iVertices</tt> array.  As, we find, in the
   *    iVertices array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | iTriangleStripIndices|
   *                   ----------------------
   *                  |          i00         |   }
   *                  |          i01         |   } first triangle strip defined
   *                  |           .          |   } by the first n1 indices
   *                  |           .          |   }
   *                  |          i0n1        |   }
   *                  |           .          |
   *                  |           .          |
   *                  |           .          |   
   *                  |          ij0         |   }
   *                  |          ij1         |   }
   *                  |           .          |   } triangle strip j
   *                  |           .          |   } with nj vertices
   *                  |          ijnj        |   }
   *                   ----------------------
   *
   *
   *    </pre> 
   *    For example, index ij0 allows to access to the face j-th strip first vertex 
   *    wich coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal coordinates are Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   * @param iNbTriangleStrip
   *    The number of face triangles strips.
   * @param iNbVertexPerTriangleStrip
   *    Array containing the number of vertices for each face triangles strip.
   *    The size of this array is equal to <tt>iNbTriangleStrip</tt>. For example, the first strip
   *    is made with <tt>iNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               |iNbVertexPerTriangleStrip |
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle strips(iNbTriangleStrip)
   *               |             nm           |   nm = number of vertices of the m-th strip. (iNbVertexPerTriangleStrip[m]
   *                --------------------------    
   *
   *   </pre>
   * @param iTriangleFanIndices
   *    Array used to store the face triangles fans vertices. Each field contains a
   *    vertex index, in the iVertices array.  As, we find, in the
   *    <tt>iVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | iTriangleFanIndices   |
   *                   ----------------------
   *                  |          i00         |   }
   *                  |          i01         |   } first triangle fan defined
   *                  |           .          |   } by the first n1 indices
   *                  |           .          |   }
   *                  |          i0n1        |   }
   *                  |           .          |
   *                  |           .          |
   *                  |           .          |   
   *                  |          ij0         |   }
   *                  |          ij1         |   }
   *                  |           .          |   } triangle fan j
   *                  |           .          |   } with nj vertices
   *                  |          ijnj        |   }
   *                   ----------------------
   *
   *
   *    </pre> 
   *    For example, index ij0 allows to access to the face j-th fan first vertex
   *    wich coordinates are X = iVertices[ij0], Y = iVertices[ij0 + 1] and Z = iVertices[ij0 + 2], and
   *    which normal coordinates are Nx = iNormals[ij0], Ny = iNormals[ij0 + 1] and Nz = iNormals[ij0 + 2].
   *    Each ij0, j in [0, jn], represents the j-th fan center.
   * @param iNbTriangleFan
   *    The number of face triangles fans.
   * @param iNbVertexPerTriangleFan
   *    Array containing the number of vertices for each face triangles fan.
   *    The size of this array is equal to <tt>iNbTriangleFan</tt>. For example, the first fan
   *    is made with <tt>iNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               | iNbVertexPerTriangleFan  |
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle fans(iNbTriangleFan)
   *               |             nm           |   nm = number of vertices of the m-th fan. (iNbVertexPerTriangleFan[m]
   *                --------------------------    
   *
   *   </pre>
   * @param iTextureCoord
   *    Array of texture coordinates. Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   *    Because vertex and normal information is being sorted at the face
   *    creation, texture coordinates are to be generated with the tessellation
   *    parameters that are retrieved after the face creation (ie with
   *    properly translated indices). Nevertheless, a mapping operator can be
   *    applied at anytime, when the face is the owner of it's vertex data.
   *    If computed before the face creation, texture coordinates can be given
   *    at the face construction method. In this case, coordinates order is
   *    rearranged in parallel with vertices coordinates.
   * @param iTextureFormat
   *    <tt>iTextureFormat</tt> is the number of fields associated to one vertex in the <tt>iTextureCoord</tt> array.
   *    It is also the number of texture coordinates associated to each vertex.
   *    Indeed, each vertex has associated coordinates in the texture map. The
   *    number of coordinates depends on the map dimension: the texture map
   *    may be in 1D, 2D or 3D. 
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>1</dt>
   *        <dd>The texture map is a one dimension map. Each vertex has a single associated texture coordinate</dd>
   *      <dt>2</dt>
   *        <dd>The texture map is a two-dimension map. Each vertex has two associated texture coordinates</dd>
   *      <dt>3</dt>
   *        <dd>The texture map is a three-dimension map. Each vertex has three associated texture coordinates</dd>
   *   </dl>
   * @param iAllocMode
   *    The CAT3DFaceGP, and it's planar inherited object, the CAT3DPlanarFaceGP
   *    have allocation flags ruling their memory comsumption for vertices and
   *    normals:
   *    The default value is ALLOCATE_VERTICES | ALLOCATE_NORMALS.
   *    <b>CAUTION</b>: The CAT3DPlanarFaceGP is an immutable object. GET_***** alloc mode only avoid an expensive copy
   *    Modifying the iVertices pointer used with GET_VERTICES or the iNormals pointer used with GET_NORMALS won't update the CAT3DPlanarFaceGP's data. 
   *    You need to create a new GP, or recycle the old one with CAT3DFaceGPEditHelper, even if you used GET_****** alloc mode.
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>ALLOCATE_VERTICES</dt>
   *        <dd>Vertex array is the property of the face and
   *        is to be deleted with it. If textures are defined, texture coordinates
   *        are to be destroyed too.</dd>
   *   </dl>
   *   <dl>
   *      <dt>GET_VERTICES</dt>
   *        <dd>Vertex array is not duplicated at the face creation, but
   *        is to be deleted during the object deletion. Texture coordinates are
   *        to be shared, but in this case, their format must be 3.</dd>
   *   </dl>
   *   <dl>
   *      <dt> ALLOCATE_NORMALS</dt>
   *        <dd>Normal array is the property of the face and
   *        is to be deleted with it. Planar faces always allocate their normals.</dd>
   *   </dl>
   *   <dl>
   *      <dt> GET_NORMALS</dt>
   *        <dd>Normal array is not duplicated at the face creation
   *        although, as for vertices, it will be destroyed in the same time the object
   *        is deleted.</dd>
   *   </dl>
   */
  CAT3DPlanarFaceGP(const float  iVertices[],
                    const int    iVerticesArraySize,
                    const float  iNormals[],
                    const int    iTriangleIndice[],
                    const int    iNbTriangle,
                    const int    iTriangleStripIndice[],
                    const int    iNbTriangleStrip,
                    const int    iNbVertexPerTriangleStrip[],
                    const int    iTriangleFanIndice[],
                    const int    iNbTriangleFan,
                    const int    iNbVertexPerTriangleFan[],
                    const float *iTextureCoord,
                    const int    iTextureFormat,
                    const char   iAllocMode,
                    const float *iTanBinorm,
                    const float  iToleranceScale,
                    const float *iUV = NULL);

  /**
   *@nodoc
   * Constructs a 3D planar face graphic primitive from CATMathPolyBuffers
   */
  CAT3DPlanarFaceGP(const CATMathPolyBuffers* iFacePolyBuffers,
		            const float  iToleranceScale);

  /**
   * @nodoc
   * With this ctor, iVB will not be owned by the GP
   */
  CAT3DPlanarFaceGP (CATVizVertexBuffer* iVB,
                     const float* iPlanarNormal,
                     const int    iTriangleIndices[],
                     const int    iNbTriangle,
                     const int    iTriangleStripIndices[],
                     const int    iNbTriangleStrip,
                     const int    iNbVertexPerTriangleStrip[],
                     const int    iTriangleFanIndices[],
                     const int    iNbTriangleFan,
                     const int    iNbVertexPerTriangleFan[]);

  /**
   * @nodoc
   * With this ctor, iVB will not be owned by the GP
   * iPrim is adopted, you don't have to call Release.
   */
  CAT3DPlanarFaceGP (CATVizVertexBuffer* iVB,
                     CATVizPrimitive* iPrim);

  /**
   * @nodoc
   * Streaming
   */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);
  
  /**
   * Draws the face.
   * @param iRender
   *   The render through which the face is drawn.
   */    
  virtual void Draw (CATRender & iRender);

  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const override;

protected :

  // Destruction:
  // ------------
  
  virtual ~CAT3DPlanarFaceGP ();
};


#endif
