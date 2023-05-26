#ifndef CAT3DBoundingGP_H
#define CAT3DBoundingGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DBoundingGP
//                  CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//
//******************************************************************************

#include "SGInfra.h"
#include "CATGraphicPrimitive.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;
class CATVizVertexBuffer;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DMesh;
class CAT3DBoundingGPIVisSG3DMeshBOAImpl;
//-- SGCAAPlan

/**
 * Class to create a graphic primitive which geometry is enclosed
 * in a bounding element.
 * <b>Role</b>:
 *    The box can either be an Axis Aligned Bounding Box
 *    (AABB) or an Object Bounding Box (OBB).
 *     - The AABB is aligned on the 3D axis system and so, of easy use with the GP coordinates 
 *       system, that can be obtained by reading the Representation tree.
 *     - The OBB is the best bounding box enclosing an object, and it is built
 *       through the use of the convex hull of the GP.
 *
 *    Presently, the box is computed in the GP axis coordinate system
 *    and is an AABB.
 *
 *    We although store a Bounding Sphere. Box and sphere are separately
 *    computed and have no common parameters, but are both enclosing the GP's
 *    geometry.
 *
 *    Don't worry about how to build it... The GP that inherits from this GP
 *    have to update the box included in this object, with the provided methods.
 *    As for the children, we have a provided method to retrieve tesselation
 *    parameters. This method will only be efficient in the subclasses that
 *    have overloaded it.
 *
 */
class ExportedBySGInfra CAT3DBoundingGP : public CATGraphicPrimitive
{
  friend class CATMarshallable3DBoundingGP;
  friend class CAT3DCurvedPipeGP;
  friend class CAT3DCylinderGP;
  friend class CAT3DFaceGP;

  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DBoundingGP, IVisSG3DMesh, CAT3DBoundingGPIVisSG3DMeshBOAImpl);
  
public:
    
BEGIN_MIGRATE_GP_CTOR_PRIVATE
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Do not derive this class" )
#endif
    /**
   * Constructs a boxed graphic primitive.
   */
  CAT3DBoundingGP (void);
END_MIGRATE_GP_CTOR


  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSaveType=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& str);


  /**
   * Gets the box center coordinates.
   * @return
   *   returns the array containing the box center coordinates.
   *   This array size is equal to three.
   */
  inline float *GetBoxCenter     (void);

  /**
   * Gets the X,Y,Z half box spans.
   * @return
   *   returns the array containing the half box
   *   spans coordinates. Its size is equal to three.
   */
  inline float *GetBoxDimensions (void);

  /**
   * Sets the box center coordinates.
   * @param iNewCenter
   *   Array containing the new center coordinates: XYZ.
   *   Its size is equal to three.
   */
  inline void   SetBoxCenter     (float * iNewCenter);
  
  /**
   * Sets the X,Y,Z half box spans.
   * @param iNewDimensions
   *   Array containing the half box spans new coordinates.
   *   Its size is equal to three.
   */
  inline void   SetBoxDimensions (float * iNewDimensions);
    
    
  /**
   * Gets the bounding sphere center coordinates.
   * @return
   *   returns a 3 fields array containing the sphere center coordinates.
   */
  inline float *GetSphereCenter (void);

  /**
   * Gets the bounding sphere radius.
   */
  inline float  GetSphereRadius (void);

  /**
   * Sets the bounding sphere center.
   * @param iNewCenter
   *   3 fields array containing the sphere center coordinates. 
   */
  inline void   SetSphereCenter (float * iNewCenter);

  /**
   * Sets the bounding sphere radius.
   * @param iNewRadius
   *   The new bounding sphere radius. 
   */
  inline void   SetSphereRadius (float iNewRadius);
    
    
  /**
   * Box and sphere computation method prototype.
   */
  virtual void ComputeBox (void);
    

  /**
   * Retrieves the tesselation information from the 3D bounding GP.<br>
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
   *    Its size is equal to three times the 3D bounding GP vertices number.
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
   *    So, the first three indices of the *oTriangleIndices array, are the indices of the 3D bounding GP first
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
   *    For example, index ij0 enables access to the 3D bounding GP j-th single triangle first vertex,
   *    which coordinates are X = *oVertices[ij0], Y = *oVertices[ij0+1] and Z = *oVertices[ij0+2], and
   *    which normal has coordinates Nx = *oNormals[ij0], Ny = *oNormals[ij0+1] and Nz = *oNormals[ij0+2].
   * @param oNbTriangle
   *    Retrieves the number of single triangles in the 3D bounding GP. 
   * @param oTriangleStripIndices
   *    Retrieves the array used to store the 3D bounding GP triangles strips vertices. Each field contains a
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
   *    For example, index ij0 allows to access to the 3D bounding GP j-th strip first vertex 
   *    wich coordinates are X = *oVertices[ij0], Y = *oVertices[ij0 + 1] and Z = *oVertices[ij0 + 2], and
   *    which normal coordinates are Nx = *oNormals[ij0], Ny = *oNormals[ij0 + 1] and Nz = *oNormals[ij0 + 2].
   * @param oNbTriangleStrip
   *    Retrieves the number of 3D bounding GP triangles strips.
   * @param oNbVertexPerTriangleStrip
   *    Retrieves an array containing the number of vertices for each 3D bounding GP triangles strip.
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
   *    Retrieves the array used to store the 3D bounding GP triangles fans vertices. Each field contains a
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
   *    For example, index ij0 allows to access to the 3D bounding GP j-th fan first vertex
   *    wich coordinates are X = *oVertices[ij0], Y = *oVertices[ij0 + 1] and Z = *oVertices[ij0 + 2], and
   *    which normal coordinates are Nx = *oNormals[ij0], Ny = *oNormals[ij0 + 1] and Nz = *oNormals[ij0 + 2].
   *    Each ij0, j in [0, jn], represents the j-th fan center.
   * @param oNbTriangleFan
   *    Retrieves the number of 3D bounding GP triangles fans.
   * @param oNbVertexPerTriangleFan
   *    Retrieves the array containing the number of vertices for each 3D bouning GP triangles fan.
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
   * @param oTextureCoord
   *    Retrieves an array made of face texture coordinates: UUUU... or UVUVUVUV... or UVWUVWUVWUVW...
   *    Its size is equal to <tt>oTextureCoordDimension</tt> times the 3D bounding GP vertices number.
   * @param oTextureCoordArraySize
   *    Retrieves the size, in floats, of the <tt>oTextureCoord</tt> array. Equal to <tt>oTextureCoordDimension</tt> times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   * @param oTextureCoordDimension
   *    Retrieve the number of texture coordinates per vertex.
   *
   */

  virtual void GetReadOnly (int          * oAllocate,
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
                            int          * oTextureCoordDimension = NULL) const;


  /**
   * Retrieves 3D bounding GP vertices.<br>
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
   *    Retrieves an array made of 3D bounding GP vertices coordinates: XYZXYZXYZ...
   *    Its size is equal to three times the 3D bounding GP vertices number.
   * @param oVerticesArraySize
   *    Retrieves the size, in floats, of the <tt>oVertices</tt> array. Equal to three times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   */

  virtual void GetVerticesReadOnly (int          * oAllocate,
                                    float const ** oVertices,
                                    int          * oVerticesArraySize) const;

    /**
   * Retrieves the 3D bounding GP surfacic mesh parameters.
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
  virtual void GetUVReadOnly(int *          oAllocate,
                             float const ** oUV,
                             int          * oUVArraySize)const;

  /**
   * Clears tesselation data  by deallocating memory.
   * The following parameters description does not explain in detail
   * each of them. It is only an overview of these parameters regarding to
   * the <tt>Clear</tt> method.
   * The full description can be found in the @href CAT3DBoundingGP#Get method comments.
   * @param iAllocate
   *   Flag to specify whether the data you are passing on were
   *   allocated by this 3D bounding GP or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>passed data were allocated by this 3D bounding GP and must be deallocated</dd>
   *        <dt>0</dt>
   *          <dd>passed data were not allocated by this 3D bounding GP and nothing is done</dd>
   *      </dl>
   * @param iVertices
   *   Array of 3D bounding GP vertices coordinates.
   * @param iVerticesArraySize
   *   Size of <tt>iVertices</tt> array. If equal to zero, <tt>iVertices</tt> is not deleted.
   * @param iNormals
   *   Array of 3D bounding GP normals coordinates.
   * @param iNormalsArraySize
   *   Size of <tt>iNormals</tt> array. If equal to zero, <tt>iNormals</tt> is not deleted.
   * @param iTriangleIndices
   *   Array of 3D bounding GP single triangles vertices coordinates.
   * @param iNbTriangle
   *   The number of single triangles in the 3D bounding GP. If equal to zero, <tt>iTriangleIndices</tt>
   *   is not deleted.
   * @param iTriangleStripIndices
   *   Array of 3D bounding GP strips triangles vertices coordinates.
   * @param iNbTriangleStrip
   *   The number of triangles strips in the 3D bounding GP. If equal to zero, <tt>iTriangleStripIndices</tt> and
   *   <tt>iNbVertexPerTriangleStrip</tt> are not deleted.
   * @param iNbVertexPerTriangleStrip
   *   Array containing the number of vertices for each 3D bounding GP triangles strip. 
   * @param iTriangleFanIndices
   *   Array of 3D bounding GP fans triangles vertices coordinates.
   * @param iNbTriangleFan
   *   The number of triangles fans in the 3D bounding GP. If equal to zero, <tt>iTriangleFanIndices</tt> and
   *   <tt>iNbVertexPerTriangleFan</tt> are not deleted.
   * @param iNbVertexPerTriangleFan
   *   Array containing the number of vertices for each 3D bounding GP triangles fan. 
   */
  void Clear (int          * iAllocate,
              float const ** iVertices,
              int          * iVerticesArraySize,
              float const ** iNormals,
              int          * iNormalsArraySize,
              int   const ** iTriangleIndices,
              int          * iNbTriangle,
              int   const ** iTriangleStripIndices,
              int          * iNbTriangleStrip,
              int   const ** iNbVertexPerTriangleStrip,
              int   const ** iTriangleFanIndices,
              int          * iNbTriangleFan,
              int   const ** iNbVertexPerTriangleFan);


  /**
   * Clears vertices data structure by deallocating memory.
   * The following parameters description does not explain in detail
   * each of them. It is only an overview of these parameters regarding to
   * the <tt>ClearVertices</tt> method.
   * The full description can be found in the @href CAT3DBoundingGP#GetVertices method comments.
   * @param iAllocate
   *   Flag to specify whether the data you are passing on were
   *   allocated by this 3D bounding GP or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>passed data were allocated by this 3D bounding GP and must be deallocated</dd>
   *        <dt>0</dt>
   *          <dd>passed data were not allocated by this 3D bounding GP and nothing is done</dd>
   *      </dl>
   * @param iVertices
   *   Array of 3D bounding GP vertices coordinates.
   * @param iVerticesArraySize
   *   Size of <tt>iVertices</tt> array. If equal to zero, <tt>iVertices</tt> is not deleted.
   */
  void ClearVertices (int          * iAllocate,
                      float const ** iVertices,
                      int          * iVerticesArraySize);
    

  /**
   * Clears surfacic mesh parameters data structure by deallocating memory.
   * The following parameters description does not explain in detail
   * each of them. It is only an overview of these parameters regarding to
   * the <tt>ClearUV</tt> method.
   * The full description can be found in the @href CAT3DBoundingGP#GetUV method comments.
   * @param iAllocate
   *   Flag to specify whether the data you are passing on were
   *   allocated by this 3D bounding GP or not.
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>passed data were allocated by this 3D bounding GP and must be deallocated</dd>
   *        <dt>0</dt>
   *          <dd>passed data were not allocated by this 3D bounding GP and nothing is done</dd>
   *      </dl>
   * @param iUV
   *    UV array. Each vertex has an associated UV couple.
   * @param iUVArraySize
   *    UV array size. If equal to 0, <tt>iUVArray</tt> is not deleted.
   */
  void ClearUV (int          * iAllocate,
                float const ** iUV,
                int          * iUVArraySize);
    
  /**
   * Tests whether the 3D bounding GP is owner of its vertices informations.
   * @return
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>The 3D bounding GP is owner of its vertices informations</dd>
   *        <dt>0</dt>
   *          <dd>The 3D bounding GP is not owner of its vertices informations</dd>
   *      </dl>
   */
  virtual int HasVertices (void);

  /**
   * Tests whether the 3D bounding GP is owner of its normals informations.
   * @return
   *    <br><b>Legal values</b>:
   *      <dl>
   *        <dt>1</dt>
   *          <dd>The 3D bounding GP is owner of its normals informations</dd>
   *        <dt>0</dt>
   *          <dd>The 3D bounding GP is not owner of its normals informations</dd>
   *      </dl>
   */
  virtual int HasNormals  (void);
    
    
  /**
   * @nodoc : deprecated V5R14
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
   *    the 3D bounding GP doesn't hold it's vertices.
   */
  virtual void ComputeTextureCoordinates (const CATMappingOperator & iMappingOperator);
    
    
  /**
   * Draws the 3D bounding GP.
   * @param iRender
   *   The render through which the 3D bounding GP is drawn.
   */
  virtual void Draw (CATRender &);
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);
    
  /**
   * @nodoc
   */
  virtual CATVizVertexBuffer * GetVertexBuffer();

  /**
   * @nodoc
   */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);
  
  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const override;

protected:
  /**
   * @nodoc
   * see derived classes.
   * Sets the texture coordinates.
   * If the 3D bounding GP shares its vertices, it also shares its
   * texture coordinates.
   * @param iTextureCoord
   *    Array of texture coordinates. Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices.
   *    Because vertex and normal information is being sorted at the 3D bounding GP
   *    creation, texture coordinates are to be generated with the tessellation
   *    parameters that are retrieved after the 3D bounding GP creation (ie with
   *    properly translated indices). Nevertheless, a mapping operator can be
   *    applied at anytime, when the 3D bounding GP is the owner of it's vertex data.
   *    If computed before the 3D bounding GP creation, texture coordinates can be given
   *    at the construction method. In this case, coordinates order is
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
  virtual void SetTextureCoordinates(float* iTextureCoord, int iTextureFormat);

  /**
   * @nodoc
   */
  virtual void SetVertexBuffer(CATVizVertexBuffer* iVB);

  // Destruction:
  // ------------
  
  virtual ~CAT3DBoundingGP (void);
  
  
  // Box parameters:
  // ---------------
  //   The box dimensions are expressed from the center position.
  
  float _box_center[3];
  float _box_dim[3];
  
  
  // Sphere parameters:
  // ------------------
  
  float _sphere_center[3];
  float _sphere_radius;
    
private:
    
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************


inline float *CAT3DBoundingGP::GetBoxCenter (void)
{
  return _box_center;
}


inline float *CAT3DBoundingGP::GetBoxDimensions (void)
{
  return _box_dim;
}


inline void CAT3DBoundingGP::SetBoxCenter (float *new_center)
{
  _box_center[0]=new_center[0];
  _box_center[1]=new_center[1];
  _box_center[2]=new_center[2];
}


inline void CAT3DBoundingGP::SetBoxDimensions (float *new_dimensions)
{
  _box_dim[0]=new_dimensions[0];
  _box_dim[1]=new_dimensions[1];
  _box_dim[2]=new_dimensions[2];
}


inline float *CAT3DBoundingGP::GetSphereCenter (void)
{
  return _sphere_center;
}


inline float CAT3DBoundingGP::GetSphereRadius (void)
{
  return _sphere_radius;
}


inline void CAT3DBoundingGP::SetSphereCenter (float *new_center)
{
  _sphere_center[0]=new_center[0];
  _sphere_center[1]=new_center[1];
  _sphere_center[2]=new_center[2];
}


inline void CAT3DBoundingGP::SetSphereRadius (float new_radius)
{
  _sphere_radius=new_radius;
}

#endif
