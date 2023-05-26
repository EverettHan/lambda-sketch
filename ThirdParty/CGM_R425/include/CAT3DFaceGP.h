#ifndef CAT3DFaceGP_H
#define CAT3DFaceGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DFaceGP
//                  CAT3DBoundingGP
//                    CATGraphicPrimitive
//                      CATBaseUnknown (SYSTEM framework)
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DBoundingGP.h"
#include "CATBoundingNormal.h"
#include "CATIAV5Level.h"
#include "CATVizGlobals.h"
#include "CATVizMacForMetaClass.h"
#include "CATUnicodeString.h"

class CATStreamer;
class CATTextureCoordinate;
class CATViz3DFace;
class CATVizVertexBuffer;
class CATMathPolyBuffers;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DFace;
class CAT3DFaceGPIVisSG3DFaceBOAImpl;
//-- SGCAAPlan

class CAT3DFaceGPEditHelper;
class CATXMLMeshContentHandler;

/**
 * Class to create the graphic primitive of a 3D face.<br>
 * <b>Role</b>: Class to describe the standard tessellation of a face.
 * A face is made of triangles, triangle strips, and triangle fans.
 * This is one of the most common encountered graphic primitive.<br>
 *  Main Methods:<br>
 *    Drawing and texturing.<br>
 *    Retrieve the tessellation parameters.
 */
class ExportedBySGInfra CAT3DFaceGP : public CAT3DBoundingGP
{
  friend class CAT3DFaceGPEditHelper;
  friend class CATMarshallable3DFaceGP;
  friend class CATDmuStreamSurfacicRep;
  friend class CATSurfacicRep;
  friend class CATXMLMeshContentHandler;
  friend class SGCGRNodesFactoryA;

  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DFaceGP, IVisSG3DFace, CAT3DFaceGPIVisSG3DFaceBOAImpl);
  
public :
    
  /**
   * Default constructor.
   */
  CAT3DFaceGP (void);

  /**
   * Constructs a 3D face graphic primitive from the face vertices coordinates list,
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
   *    Array made of normals coordinates. It is organized like <tt>iVertices</tt> : one vertex has exactly
   *    one normal at the same field entry.
   * @param iNormalsArraySize
   *    The size, in floats, of the <tt>iNormal</tt> array. Equal to three times the number
   *    of normals.
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
   *    <b>CAUTION</b>: The CAT3DFaceGP is an immutable object. GET_***** alloc mode only avoid an expensive copy
   *    Modifying the iVertices pointer used with GET_VERTICES, the iNormals pointer used with GET_NORMALS, 
   *    or the iTextureCoord pointer with GET_TEXTURES won't update the CAT3DFaceGP's data. 
   *    You need to create a new GP, or recycle the old one with CAT3DFaceGPEditHelper, even if you used GET_****** alloc mode.
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>ALLOCATE_VERTICES</dt>
   *        <dd>Vertex array is the property of the face and
   *        is to be deleted with it.</dd>
   *   </dl>
   *   <dl>
   *      <dt>GET_VERTICES</dt>
   *        <dd>Vertex array is not duplicated at the face creation, but
   *        is to be deleted during the object deletion.</dd>
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
   *   <dl>
   *      <dt> ALLOCATE_TEXTURES</dt>
   *        <dd>Texture coordinates array is the property of the face and is to be deleted with it.
   *        This mode is suitable for computing new texture coordinates</dd>
   *   </dl>
   *   <dl>
   *      <dt> GET_TEXTURES</dt>
   *        <dd>Texture coordinates array is not duplicated at the face creation
   *        although, as for vertices, it will be destroyed in the same time the object
   *        is deleted. In this mode, the texture format is 3.</dd>
   *   </dl>
   */
  
  //    Marshalling this object will fail when reading it back when data is not
  //    holded by the object. In this case, an other object should take in
  //    charge the unmarshalling step of the face from an external point of view
  //    and resolve references problems.
  CAT3DFaceGP (const float  iVertices[],
               const int    iVerticesArraySize,
               const float  iNormals[],
               const int    iNormalsArraySize,
               const int    iTriangleIndices[],
               const int    iNbTriangle,
               const int    iTriangleStripIndices[],
               const int    iNbTriangleStrip,
               const int    iNbVertexPerTriangleStrip[],
               const int    iTriangleFanIndices[],
               const int    iNbTriangleFan,
               const int    iNbVertexPerTriangleFan[],
               const float *iTextureCoord=NULL,
               const int    iTextureFormat=3,
               const char   iAllocMode=ALLOCATE_VERTICES | ALLOCATE_NORMALS | ALLOCATE_TEXTURES,
               const float  *tanBinormal=NULL,
               const float  *iUV=NULL);
    
  /**
   * Constructs a 3D face graphic primitive from the face vertices coordinates list,
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
   *    Array made of normals coordinates. It is organized like <tt>iVertices</tt> : one vertex has exactly
   *    one normal at the same field entry.
   * @param iNormalsArraySize
   *    The size, in floats, of the <tt>iNormal</tt> array. Equal to three times the number
   *    of normals.
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
   *    <b>CAUTION</b>: The CAT3DFaceGP is an immutable object. GET_***** alloc mode only avoid an expensive copy
   *    Modifying the iVertices pointer used with GET_VERTICES, the iNormals pointer used with GET_NORMALS, 
   *    or the iTextureCoord pointer with GET_TEXTURES won't update the CAT3DFaceGP's data. 
   *    You need to create a new GP, or recycle the old one with CAT3DFaceGPEditHelper, even if you used GET_****** alloc mode.
   * <br><b>Legal values</b>:
   *   <dl>
   *      <dt>ALLOCATE_VERTICES</dt>
   *        <dd>Vertex array is the property of the face and
   *        is to be deleted with it.</dd>
   *   </dl>
   *   <dl>
   *      <dt>GET_VERTICES</dt>
   *        <dd>Vertex array is not duplicated at the face creation, but
   *        is to be deleted during the object deletion.</dd>
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
   *   <dl>
   *      <dt> ALLOCATE_TEXTURES</dt>
   *        <dd>Texture coordinates array is the property of the face and is to be deleted with it.
   *        This mode is suitable for computing new texture coordinates</dd>
   *   </dl>
   *   <dl>
   *      <dt> GET_TEXTURES</dt>
   *        <dd>Texture coordinates array is not duplicated at the face creation
   *        although, as for vertices, it will be destroyed in the same time the object
   *        is deleted. In this mode, the texture format is 3.</dd>
   *   </dl>
   */

  //    Marshalling this object will fail when reading it back when data is not
  //    holded by the object. In this case, an other object should take in
  //    charge the unmarshalling step of the face from an external point of view
  //    and resolve references problems.
  CAT3DFaceGP (const float  iVertices[],
               const int    iVerticesArraySize,
               const float  iNormals[],
               const int    iNormalsArraySize,
               const int    iTriangleIndices[],
               const int    iNbTriangle,
               const int    iTriangleStripIndices[],
               const int    iNbTriangleStrip,
               const int    iNbVertexPerTriangleStrip[],
               const int    iTriangleFanIndices[],
               const int    iNbTriangleFan,
               const int    iNbVertexPerTriangleFan[],
               const float *iTextureCoord,
               const int    iTextureFormat,
               const char   iAllocMode,
               const float  *tanBinormal,
               const float iToleranceScale,
               const float  *iUV = NULL);

  /**
   *@nodoc
   * Constructs a 3D face graphic primitive from CATMathPolyBuffers
   */
  CAT3DFaceGP(const CATMathPolyBuffers* iFacePolyBuffers,
		          const float  iToleranceScale);

  /**
   *@nodoc
   *With this ctor, iVB will not be owned by the GP
   */
  CAT3DFaceGP (CATVizVertexBuffer* iVB,
               const int    iTriangleIndices[],
               const int    iNbTriangle,
               const int    iTriangleStripIndices[],
               const int    iNbTriangleStrip,
               const int    iNbVertexPerTriangleStrip[],
               const int    iTriangleFanIndices[],
               const int    iNbTriangleFan,
               const int    iNbVertexPerTriangleFan[],
               const float* iPlanarNormal = NULL);
  /**
   * @nodoc
   * With this ctor, iVB will not be owned by the GP
   * iPrim is adopted, you don't have to call release.
   */
  CAT3DFaceGP (CATVizVertexBuffer* iVB,
               CATVizPrimitive* iPrim);

  /**
   *@nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSavetype=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& iStr);



  /**
   * Retrieves the tessellation information from the face.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * int allocate;
   * float const* vertices;
   * ...
   * GetReadOnly(&allocate, &vertices, ...);
   * </pre></tt><br>
   * @param oAllocate
   *    Flag specifiying whether retrieved data is copied or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>retrieved data is copied.</dd>
   *        <dt>0</dt>
   *          <dd>retrieves references on data.</dd>
   *      </dl>
   *    oAllocate flag is always returned equal to 0: Get() only
   *    retrieves references on stored data.
   * @param oVertices
   *    Retrieves an array made of face vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face vertices number.
   * @param oVerticesArraySize
   *    Retrieves the size, in floats, of the <tt>oVertices</tt> array. Equal to three times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   * @param oNormals
   *    Retrieves an array made of normals coordinates. It is organized as <tt>oVertices</tt> : one vertex has exactly
   *    one normal at the same field entry.
   * @param oNormalsArraySize
   *    Retrieves The size, in floats, of the <tt>oNormal</tt> array. Equal to three times the number
   *    of normals.
   *    If information on normals is shared with another element,
   *    returned size for this parameter is equal to 0.
   * @param oTriangleIndices
   *    Retrieves the array used to store the single triangles vertices. Each of its field represents
   *    a vertex index, in the <tt>oVertices</tt> array.
   *    As,  we find, in the <tt>*oVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    So, the first three indices of the *oTriangleIndices array, are the indices of the face first
   *    single triangle three vertices.
   *    <pre>
   *
   *                 -----------------       
   *                |*oTriangleIndices |
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
   *    which coordinates are X = *oVertices[ij0], Y = *oVertices[ij0+1] and Z = *oVertices[ij0+2], and
   *    which normal has coordinates Nx = *oNormals[ij0], Ny = *oNormals[ij0+1] and Nz = *oNormals[ij0+2].
   * @param oNbTriangle
   *    Retrieves the number of single triangles in the face. 
   * @param oTriangleStripIndices
   *    Retrieves the array used to store the face triangles strips vertices. Each field contains a
   *    vertex index, belonging to one of the strips, in the oVertices array.  As, we find, in the
   *    <tt>oVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | oTriangleStripIndices |
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
   *    wich coordinates are X = *oVertices[ij0], Y = *oVertices[ij0 + 1] and Z = *oVertices[ij0 + 2], and
   *    which normal coordinates are Nx = *oNormals[ij0], Ny = *oNormals[ij0 + 1] and Nz = *oNormals[ij0 + 2].
   * @param oNbTriangleStrip
   *    Retrieves the number of face triangles strips.
   * @param oNbVertexPerTriangleStrip
   *    Retrieves an array containing the number of vertices for each face triangles strip.
   *    The size of this array is equal to <tt>*oNbTriangleStrip</tt>. For example, the first strip
   *    is made with <tt>*oNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               |*oNbVertexPerTriangleStrip|
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle strips(*oNbTriangleStrip)
   *               |             nm           |   nm = number of vertices of the m-th strip. (*oNbVertexPerTriangleStrip[m]
   *                --------------------------    
   *
   *   </pre>
   * @param oTriangleFanIndices
   *    Retrieves the array used to store the face triangles fans vertices. Each field contains a
   *    vertex index, belonging to one of the fans, in the <tt>oVertices</tt> array.  As, we find, in the
   *    <tt>oVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   *    <pre>
   *
   *
   *                   ----------------------
   *                  | *oTriangleFanIndices  |
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
   *    wich coordinates are X = *oVertices[ij0], Y = *oVertices[ij0 + 1] and Z = *oVertices[ij0 + 2], and
   *    which normal coordinates are Nx = *oNormals[ij0], Ny = *oNormals[ij0 + 1] and Nz = *oNormals[ij0 + 2].
   *    Each ij0, j in [0, jn], represents the j-th fan center.
   * @param oNbTriangleFan
   *    Retrieves the number of face triangles fans.
   * @param oNbVertexPerTriangleFan
   *    Retrieves the array containing the number of vertices for each face triangles fan.
   *    The size of this array is equal to <tt>*oNbTriangleFan</tt>. For example, the first fan
   *    is made with <tt>*oNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               | *oNbVertexPerTriangleFan |
   *                --------------------------
   *               |             n1           |
   *               |             .            |
   *               |             .            |   m = Number of triangle fans(*oNbTriangleFan)
   *               |             nm           |   nm = number of vertices of the m-th fan. (*oNbVertexPerTriangleFan[m]
   *                --------------------------    
   *
   *   </pre>
   */
  void GetReadOnly (int          * oAllocate,
                    float const ** oVertices,
                    int          * oVerticesArraySize,
                    float const ** oNormals,
                    int          * oNormalsArraySize,
                    int   const ** oTriangleIndices,
                    int          * oNbTriangle,
                    int   const ** oTriangleStripIndices,
                    int          * oNbTriangleStrip,
                    int   const ** oNbVertexPerTriangleStrip,
                    int   const ** oTriangleFanIndices,
                    int          * oNbTriangleFan,
                    int   const ** oNbVertexPerTriangleFan,
                    float const ** oTextureCoord = NULL,
                    int          * oTextureCoordArraySize = NULL,
                    int          * oTextureCoordDimension = NULL)const;

  void GetReadOnly (int          * oAllocate,
                    float const ** oVertices,
                    int          * oVerticesArraySize,
                    float const ** oNormals,
                    int          * oNormalsArraySize,
                    int   const ** oTriangleIndices,
                    int          * oNbTriangle,
                    int   const ** oTriangleStripIndices,
                    int          * oNbTriangleStrip,
                    int   const ** oNbVertexPerTriangleStrip,
                    int   const ** oTriangleFanIndices,
                    int          * oNbTriangleFan,
                    int   const ** oNbVertexPerTriangleFan,
                    void        ** oRenderData)const;

  /**
   * Retrieves face vertices.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it must be called like this :<br>
   * <tt><pre>
   * int allocate;
   * float const* vertices;
   * ...
   * GetVerticesReadOnly(&allocate, &vertices, ...);
   * </pre></tt><br>
   * @param oAllocate
   *    Flag specifiying whether retrieved data is copied or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>retrieved data is copied.</dd>
   *        <dt>0</dt>
   *          <dd>retrieves references on data.</dd>
   *      </dl>
   *    oAllocate flag is always returned equal to 0: <tt>GetVertices</tt> only
   *    retrieves references on stored data.
   * @param oVertices
   *    Retrieves an array made of face vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face vertices number.
   * @param oVerticesArraySize
   *    Retrieves the size, in floats, of the <tt>oVertices</tt> array. Equal to three times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   */
  virtual void GetVerticesReadOnly (int          * oAllocate,
                                    float const ** oVertices,
                                    int          * oVerticesArraySize)const;

  /**
   * Tests whether the face is owner of its vertices informations.
   * @return
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>The face is owner of its vertices informations</dd>
   *        <dt>0</dt>
   *          <dd>The face is not owner of its vertices informations</dd>
   *      </dl>
   */
  inline int HasVertices (void);
  
  /**
   * Tests whether the face is owner of its normals informations.
   * @return
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>The face is owner of its normals informations</dd>
   *        <dt>0</dt>
   *          <dd>The face is not owner of its normals informations</dd>
   *      </dl>
   */
  inline int HasNormals  (void);

  /**
   * Tests whether the face is owner of its texture coordinates informations.
   * @return
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>The face is owner of its texture coordinates informations</dd>
   *        <dt>0</dt>
   *          <dd>The face is not owner of its texture coordinates informations</dd>
   *      </dl>
   */
  int HasTextures  (void);


  /**
   * @nodoc
   * In favor of GetTextureCoordinates (float ** oTextureCoord, int * oDimension).
   * Retrieves the texture coordinates.
   * This method must be used like this:
   * <br><tt><pre>
   * float * textureCoord;
   * GetTextureCoord(&textureCoord);
   * <br></pre></tt>
   * @param oTextureCoord
   *    Retrieves the array of texture coordinates.
   *    Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   */
  virtual void GetTextureCoordinatesReadOnly     (float const ** oTextureCoord)const;

  
  /**
   * Retrieves the texture coordinates.
   * This method must be used like this:
   * <br><tt><pre>
   * float * textureCoord;
   * GetTextureCoord(&textureCoord);
   * <br></pre></tt>
   * @param oTextureCoord
   *    Retrieves the array of texture coordinates.
   *    Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices. 
   * @param oDimension
   *    Retrieve the number of coordinates per vertex.
   */
  virtual void GetTextureCoordinatesReadOnly     (float const ** oTextureCoord, int * oDimension)const;

  /**
   * @nodoc
   *    ComputeTextureCoordinates: Textures coordinates can't be computed if
   *    the face doesn't hold it's texture coordinates.
   */
  virtual void ComputeTextureCoordinates (const CATMappingOperator& op);

  /**
    * @nodoc
    *    ComputeTextureCoordinates: Textures coordinates can't be computed if
    *    the face doesn't hold it's texture coordinates.
    *    string 'tcKey' identifies the set in which texture coordinates will be computed
    */
  virtual void ComputeTextureCoordinates (const CATMappingOperator& op, const CATUnicodeString& tcKey);

  /**
   * @nodoc
   *    ComputeTextureCoordinates: Textures coordinates can't be computed if
   *    the face doesn't hold it's texture coordinates.
   */
  virtual void ComputeTextureCoordinates (const CATMappingOperator* op, const CATBaseUnknown* cell);

  /**
   * @nodoc
   *    ComputeTextureCoordinates: Textures coordinates can't be computed if
   *    the face doesn't hold it's texture coordinates.
   *    string 'tcKey' identifies the set in which texture coordinates will be computed
   */
  virtual void ComputeTextureCoordinates (const CATMappingOperator* op, const CATBaseUnknown* cell, const CATUnicodeString& tcKey);


  /**
   * Retrieves the face surfacic mesh parameters.
   * @param oAllocate
   *    Flag specifiying whether retrieved data is copied or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>retrieved data is copied.</dd>
   *        <dt>0</dt>
   *          <dd>retrieves references on data.</dd>
   *      </dl>
   *    oAllocate flag is always returned equal to 0: GetUV() only
   *    retrieves references on stored data.
   * @param oUV
   *    Retrieves the UV array. Each vertex has an associated UV couple.
   * @param oUVArraySize
   *    Retrieves the size of the UV array. 
   *    Equals 0 if the mesh is shared with another element or if the array is NULL, two times the number
   *    of vertices elsewhere. 
   */
  virtual void GetUVReadOnly (int          * oAllocate,
                              float const ** oUV,
                              int          * oUVArraySize)const;

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the face.
   * @param iRender
   *   The render through which the face is drawn.
   */
  virtual void Draw   (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;

  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);
    
  /**
   * @nodoc
   *    ComputeBox: Updates information for the parent class (box and sphere
   *    parameters).
   */
  virtual void ComputeBox (void);

  /**
   * Performs a multi-dimensionnal sort on vertices and normals, and updates
   * all tessellation parameters.
   * Vertices may be spatially sorted using the SortAndStrip method. Meshing
   * information is kept up to date. <br>
   * Sort is:
   * <pre>
   *          P1 < P2 ==> P1.x < P2.x ||
   *                      P1.x = P2.x && P1.y < P2.y ||
   *                      P1.x = P2.x && P1.y = P2.y && P1.z <= P2.z
   * </pre>
   */
  virtual void SortAndStrip (void);

  /**
   * @nodoc
   * Retrieves the normals cone as array of bounding normals.
   */
#ifdef _AIX_SOURCE
  void  GetBoundingNormal(  CAT3DBoundingNormal **oBNSurface );
#endif

  /**
   * @nodoc
   */
  unsigned int GetNVert(void);
#ifdef _SUNOS_SOURCE
  /**
   * @nodoc
   */
  inline void  SetRenderData (void *iRenderData);

  /**
   * @nodoc
   */
  inline void* GetRenderData (void);
#endif

  /**
   * @nodoc
   */
  inline char   GetOrientation (void);

  /**
   * @nodoc
   */
  inline void   SetOrientation (char iOrientation);

  /**
   * @nodoc
   * Retreive the texture coordinates set associated with iOperator.
   */
  void GetTextureCoordinates(const CATMappingOperator& iOperator, float*& oCoordinates, int& oDimension);

  /**
   * @nodoc
   * Used only by the render which cleans textures.
   */
  virtual void ResetTextureCoordinatesFlag();


  /**
   * @nodoc
   * Used only by the render which cleans textures.
   */
  virtual void FlagTextureCoordinates(const CATMappingOperator& iOperator);

  /**
   * @nodoc
   */
  virtual void CleanUnflaggedTextureCoordinates();

  /**
   * @nodoc
   */
  virtual CATVizVertexBuffer * GetVertexBuffer();

  /**
   * @nodoc
   */
  virtual CATVizPrimitive * GetVizPrimitive(int &oAllocateMode);

  /**
   * @nodoc
   */
  inline void SetAllocMode(char iAllocMode);

  /**
   * @nodoc
   */
  inline char GetAllocMode();

  /**
   * @nodoc
   */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

  /**
   * @nodoc
   */
  inline void SetStorageID(unsigned int iStorageID);
  /**
   * @nodoc
   */
  inline unsigned int GetStorageID();
   
  /**
   * @nodoc
   */
  inline unsigned int StorageIDisValid() const;

  /**
   * @nodoc
   */
  inline unsigned int GetIsEmpty();

  /**
   * @nodoc
   */
  void EmptyVBO();

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const override;

protected :
  /**
   * @nodoc
   * Use CAT3DFaceGPEditHelper to edit the face.
   * Sets the texture coordinates.
   * If the face shares its vertices, it also shares its
   * texture coordinates.
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
   *    iTextureFormat is the number of fields associated to one vertex in the <tt>iTextureCoord</tt> array.
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
   *    If data is shared, the format for the given texture coordinates must be three.
   */
  virtual void SetTextureCoordinates(float* iTextureCoord, int iTextureFormat, char iAllocMode = ALLOCATE_TEXTURES);

  /**
 * @nodoc
 * Use CAT3DFaceGPEditHelper to edit the face.
 * Sets the UV array.
 * @param iUV
 *    Array of UV parameters. Its size is equal to 2/3 the vertices array size.
 *    The  management of this array follows the vertices array management concerning
 *    the allocation mode.
 */
  virtual void SetUV(float* iUV);

  /**
   * @nodoc
   * For the moment the dimension MUST be 3.
   */
  virtual void AddTextureCoordinates(float* iCoordinates, int iDimension, const CATMappingOperator& iOperator);

  /**
   * @nodoc
   */
  virtual void RemoveTextureCoordinates(const CATMappingOperator& iOperator);

  /**
   * @nodoc
   */
  void Empty();

  /**
   * @nodoc
   */
  virtual void SetVertexBuffer(CATVizVertexBuffer* iVB);

  /**
   * @nodoc
   */
  virtual void SetVizPrimitive(CATVizPrimitive* iPrimitive, int iAllocateMode);


  // Destruction:
  // ------------
    
  virtual ~CAT3DFaceGP (void);
    
  /**
   * @nodoc
   */
  virtual void ResetStorage();

  /*
  // Internal construction functions:
  // --------------------------------
  
  void BuildTriangles (const int iTriangleIndices[],const int iNbTriangle);
  void BuildStrips    (const int iTriangleStripIndices[],
                       const int iNbTriangleStrip,
                       const int iNbVertexPerTriangleStrip[]);
  void BuildFans      (const int iTriangleFanIndices[],
                       const int iNbTriangleFan,
                       const int iNbVertexPerTriangleFan[]);
  */
  
  // Tessellation parameters:
  // -----------------------
  
  CATVizVertexBuffer *_vertexBuffer;
  CATViz3DFace       *_vizFace;
  
  //const CATMathPolyBuffers* _FacePolyBuffers;
	
  unsigned int _StorageID:31;
  unsigned int _b_isEmpty:1; //this boolean is only useful for CATVizVertexBufferForBufferedFace to prevent a crash in the VBO creation

#ifdef _SUNOS_SOURCE
  void   *_SUNrenderData;
#endif    
    
  char   _alloc_mode;
  char   _orientation; // we stock the orientation of the topological face
                       // to know whether we need to invert the triangles or not
                       // when loading from the tessellation cache

  // Bounding cone information:
  // --------------------------
#ifdef _AIX_SOURCE
  CAT3DBoundingNormal  *_bounding_cone;
#endif

  private:
  /**
   * Box and sphere computation method prototype.
   */
  virtual void ComputeBox (float iToleranceScale);
};


//******************************************************************************
//*** Inlined methods: *********************************************************
//******************************************************************************

inline int CAT3DFaceGP::HasVertices (void)
{
  if( (_alloc_mode & ALLOCATE_VERTICES) || (_alloc_mode & GET_VERTICES) )
    return 1;
  else
    return 0;
}

inline int CAT3DFaceGP::HasNormals (void)
{
  if( (_alloc_mode & ALLOCATE_NORMALS) || (_alloc_mode & GET_NORMALS) )
    return 1;
  else
    return 0;
}

inline char CAT3DFaceGP::GetAllocMode()
{
    return _alloc_mode;
}

#ifdef _SUNOS_SOURCE
inline void CAT3DFaceGP::SetRenderData (void *renderData) 
{
  _SUNrenderData = renderData;
}

inline void* CAT3DFaceGP::GetRenderData (void)
{
  return(_SUNrenderData);
}
#endif

inline char CAT3DFaceGP::GetOrientation (void)
{
   return _orientation;
}

inline void CAT3DFaceGP::SetOrientation (char iOrientation)
{
   _orientation = iOrientation;
}

inline void CAT3DFaceGP::SetAllocMode(char iAllocMode)
{
   _alloc_mode = iAllocMode;
}

inline void CAT3DFaceGP::SetStorageID(unsigned int iStorageID)
{
  _StorageID = iStorageID;
}

inline unsigned int CAT3DFaceGP::GetStorageID()
{
  return _StorageID;
}

inline unsigned int CAT3DFaceGP::GetIsEmpty()
{
  return _b_isEmpty;
}

inline unsigned int CAT3DFaceGP::StorageIDisValid() const
{
  if (_StorageID==0 || _StorageID==INVALID_STORAGEID)
    return 0;
  else
    return 1;
}
#endif

