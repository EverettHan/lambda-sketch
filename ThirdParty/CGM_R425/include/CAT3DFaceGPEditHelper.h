#ifndef CAT3DFaceGPEditHelper_H_
#define CAT3DFaceGPEditHelper_H_

// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Abstract: Helper class to edit CAT3DFaceGP.
//------------------------------------------------------------------------------


#include "SGInfra.h"
#include "CATGraphicPrimitiveEditHelper.h"
#include "CATSysErrorDef.h"

class CATRep;
class CATViz3DFace;
class CAT3DFaceGP;
class CAT3DPlanarFaceGP;

class CATVizVertexBuffer;
class CATViz3DFaceMutable;
class l_CATVizVertexBufferEditHelper;

/**
 * Class to edit CAT3DFaceGP and CAT3DPlanarFace graphic primitive.
 * CATGraphicPrimitive must be edited in context, this class handles edition authorization.
 * NB : Do not keep EditHelper alive wore than necessary. Edition context notifcation is done on destruction. 
 * That's why heap allocation is forbidden.
 */
class ExportedBySGInfra CAT3DFaceGPEditHelper : public CATGraphicPrimitiveEditHelper
{  
public:

  static const unsigned int EnsureVBEditionPossible;
  static const unsigned int ReplaceByDuplicateIfMultiAggreg;
  static const unsigned int DoNotUpdateBoundingElement;

  /**
   * Constructor.
   * Construct an empty helper.
   * Use the Reset methods to be able to use it.
   */
  CAT3DFaceGPEditHelper();

  /**
   * Destructor.
   * If the EditHelper is not empty, the edition context is notified.
   */
  ~CAT3DFaceGPEditHelper();

  /**
   * Get the currently edited CAT3DFaceGP.
   * @return
   *  The currently edited CAT3DFaceGP.
   *  If the EditHelper was empty, NULL is returned.
   */
  CAT3DFaceGP* GetFace();

  /**
   * Get if the edition of the given graphic primitive is possible, and if not, why.
   * @param iFace
   *   The face to be edited
   * @param iRep
   *   The Rep which should contain the face
   * @return
   *  A CATGraphicPrimitiveEditHelper::EditAuthorization value, depending of the context.
   */
  static GPEditAuthorization IsEditionPossible(CAT3DFaceGP* iFace, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DFaceGP with its edition context
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DFaceGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DFaceGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the face is not contained in any Rep, this parameter can be NULL
   * @return
   *   If the face can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   It should be noted that if the face is contained in more than one Rep, it will always fail.
   *   If the face is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT Reset(CAT3DFaceGP* iFace, CATRep* iRep);

  /**
   * Set the currenlty edited CAT3DFaceGP with its edition context. Compared to Reset, this methods supports additional flags
   * which can perform operation to ensure that some edition features will be supported.
   * CAUTION : using these flags can result in duplicate elements and can cause memory issues.
   * In case of success, if the EditHelper is not empty, the old edition context is notified.
   * @param iFace
   *   The CAT3DFaceGP instance which will be edited.
   * @param iRep
   *   The Rep containing the CAT3DFaceGP. Currently supported rep are CATSurfacicRep and CAT3DCustomRep.
   *   If the face is not contained in any Rep, this parameter can be NULL
   * @param iFlags
   *   Additional flags which will perform operation needed to access some edition features.
   *     -EnsureVBEditionPossible : If the face's vertex buffer is referenced by several face, edition on vertices won't be available.
   *                                This flag will create a new VertexBuffer if needed to allow edition.
   *     -ReplaceByDuplicateIfMultiAggreg : If the face is aggregated in more than one Rep, this flag will make a copy of the face and replace the 
   *                                        original face in the rep. The face's VertexBuffer will also be duplicated.
   * @return
   *   If the face can be edited in the provided context, S_OK, otherwise, E_FAIL
   *   If the face is contained in a Stripped SurfacicRep, it will fail.
   */
  HRESULT ResetExtended(CAT3DFaceGP* iFace, CATRep* iRep, unsigned int iFlag);

  /**
   * Retrieves the tessellation information from the face.
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
  void GetIndices (int   ** oTriangleIndices,
                   int    * oNbTriangle,
                   int   ** oTriangleStripIndices,
                   int    * oNbTriangleStrip,
                   int   ** oNbVertexPerTriangleStrip,
                   int   ** oTriangleFanIndices,
                   int    * oNbTriangleFan,
                   int   ** oNbVertexPerTriangleFan);

  /**
   * Retrieves face vertices.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it must be called like this :<br>
   * <tt><pre>
   * float* vertices;
   * ...
   * GetVertices(&vertices, ...);
   * </pre></tt><br>
   * @param oVertices
   *    Retrieves an array made of face vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face vertices number.
   * @param oVerticesArraySize
   *    Retrieves the size, in floats, of the <tt>oVertices</tt> array. Equal to three times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   */
  void GetVertices (float ** oVertices,
                    int    * oVerticesArraySize);

  /**
   * Retrieves face normals.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it must be called like this :<br>
   * <tt><pre>
   * float* normals;
   * ...
   * GetNormals(&normals, ...);
   * </pre></tt><br>
   * @param oNormals
   *    Retrieves an array made of face normals coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the face normals number, if the face was not a planar face, 3 otherwise.
   * @param oNormalsArraySize
   *    Retrieves the size, in floats, of the <tt>oVertices</tt> array. Equal to three times the
   *    vertices number if the face was not a planar face, 3 otherwise.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   */
  void GetNormals (float ** oNormals,
                   int    * oNormalsArraySize);

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
  void GetTextureCoordinates(float ** oTextureCoord, int * oDimension);

  /**
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
  void SetTextureCoordinates(float const* iTextureCoord, unsigned int iTextureFormat);

  /**
   * Retrieves the face surfacic mesh parameters.
   * @param oUV
   *    Retrieves the UV array. Each vertex has an associated UV couple.
   * @param oUVArraySize
   *    Retrieves the size of the UV array. 
   *    Equals 0 if the mesh is shared with another element or if the array is NULL, two times the number
   *    of vertices elsewhere. 
   */
  void GetUV (float ** oUV,
              int    * oUVArraySize);

  /**
   * Sets the UV array.
   * @param iUV
   *    Array of UV parameters. Its size is equal to 2/3 the vertices array size.
   *    The  management of this array follows the vertices array management concerning
   *    the allocation mode.    
   */
  void SetUV(float const* iUV);

  /**
   * @nodoc
   * CAUTION : iBuffer will be released. No VB sharing can be done with this call.
   * iBuffer is adopted and released.
   * If iBuffer is NULL, nothing is done.
   */
  HRESULT AdoptVertexBuffer(CATVizVertexBuffer* iBuffer);

  /**
   * @nodoc
   * iBuffer is meant to be shared among multiple faces. (GetVertices, GetUV, GetTextureCoordinates and GetNormals(if not planar) will fail).
   * Can be used to set the face's VB to NULL.
   */
  void SetVertexBuffer(CATVizVertexBuffer* iBuffer);

  /**
   * @nodoc
   * iBuffer will be copied and the resulting buffer will be adopted by the face.
   * If iBuffer is NULL, nothing is done.
   */
  HRESULT CopyVertexBuffer(CATVizVertexBuffer const* iBuffer);

  /**
   * @nodoc
   * CAUTION : iFace will be released
   */
  void AdoptVizPrimitive(CATViz3DFace* iFace);

  /**
   * @nodoc
   */
  void CopyVizPrimitive(CATViz3DFace const* iFace);

  /**
   * @nodoc
   */
  void GetIndicesRaw(void*          & oTriangleIndices,
                     unsigned int   & oNbTriangle,
                     void*          & oTriangleStripIndices,
                     unsigned int   & oNbTriangleStrip,
                     unsigned int*  & oNbVertexPerTriangleStrip,
                     void*          & oTriangleFanIndices,
                     unsigned int   & oNbTriangleFan,
                     unsigned int*  & oNbVertexPerTriangleFan,
                     unsigned int   & oIndexType,
                     int unpack = 1);



protected:

  CAT3DFaceGP*   m_CurrentFace;

  l_CATVizVertexBufferEditHelper* m_VBHelper;
  CATViz3DFaceMutable* m_VizFace;
  int m_UpdateBE;

private:
  CAT3DFaceGPEditHelper(CAT3DFaceGPEditHelper const& iOther);
  CAT3DFaceGPEditHelper& operator=(CAT3DFaceGPEditHelper const& iOther);
};


#endif
