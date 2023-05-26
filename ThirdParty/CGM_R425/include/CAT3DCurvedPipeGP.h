#ifndef CAT3DCurvedPipeGP_H
#define CAT3DCurvedPipeGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DCurvedPipeGP
//                  CAT3DBoundingGP
//                    CATGraphicPrimitive
//                      CATBaseUnknown (SYSTEM framework) 
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DBoundingGP.h"
class CATStreamer;
class CAT3DCurvedPipeGPEditHelper;

#define INVALID_STORAGEID      0x7fffffff  //max value for a 31 bits unsigned int 


/**
 * Class to create the graphic primitive of a 3D curved pipe.
 * <b>Role</b>: A 3D curved pipe can be assimilated to the extrusion
 * of a circle along a main 3D curve.
 */
class ExportedBySGInfra CAT3DCurvedPipeGP : public CAT3DBoundingGP
{
  
  friend class CATMarshallable3DCurvedPipeGP;
  friend class CAT3DCurvedPipeGPEditHelper;
  friend class SGCGRStreamerFor3DCurvedPipeGP;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  
public:
    
    // Construction method (locked destruction method):
    // ------------------------------------------------

  /**
   * Default constructor.
   */
  CAT3DCurvedPipeGP (void);

  /**
   * Constructs a 3D curved pipe from tesselation informations
   * on the main curve and on circles belonging to the curved pipe.
   * @param iCurveVertices
   *   Array made of main curve vertices coordinates: XYZXYZXYZ...
   *   Its size is equal to three times the number of vertices
   *   used to describe the main curve.
   * @param iNbCurveVertices
   *   The number of vertices used to describe the main curve.
   * @param iCirclesVertices
   *   Array made of curved pipe's circles coordinates. There is
   *   one circle per curve vertex, and a constant number of vertices
   *   to describe each of these circles.So, this array size is equal to
   *   <tt>iNbCurveVertices * iNbVerticesPerCircle * 3</tt>.
   *   For example, if we choose to describe each circle of the pipe with
   *   20 points, the pipe second circle first point coordinates are :
   *   <tt>x = iCirclesVertices[3*iNbVerticesPerCircle], y = iCirclesVertices[3*iNbVerticesPerCircle+1] and
   *   z = iCirclesVertices[3*iNbVerticesPerCircle+2].
   * @param iNbVerticesPerCircle
   *   The number of vertices used to describe every circles of the pipe.
   * @param iBaseNormal
   *   Array of curved pipe base circle normal coordinates. Its size is three
   * @param iEndNormal
   *   Array of curved pipe end circle normal coordinates. Its size is three
   * @param iPipeRadius
   *   The global pipe radius. 
   */
  CAT3DCurvedPipeGP (float* iCurveVertices,         
                     int    iNbCurveVertices,         
                     float* iCirclesVertices,        
                     int    iNbVerticesPerCircle,       
                     float* iBaseNormal,         
                     float* iEndNormal,          
                     float  iPipeRadius);              
    
  //Streaming
  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& iStr,int iSaveType=0);
  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& iStr);

  /**
   * @nodoc
   *    Computing bounding box and bounding sphere. 
   */
  virtual void ComputeBox (void);
        
#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the curved pipe.
   * @param iRender
   *   The render through which the curved pipe is drawn.
   */
  virtual void Draw (CATRender &iRender) GP_FUNC_OVERRIDE_FINAL;

  /**
   * Retrieves the tesselation information from the curved pipe.<br>
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
   *    oAllocate flag is always returned equal to 1: <tt>GetVertices</tt> always
   *    allocates the returned arrays.
   * @param oVertices
   *   Retrieves an array made of curved pipe vertices coordinates: XYZXYZXYZ...
   *   If we have a pipe made
   *   with NCircles circles and that each circle is described with NCirclePoints points,
   *   <tt>oVertices</tt> array size is equal to NCircles * NCirclePoints * 3 * 2.
   *   The array is structured like this:
   *   the first NCirclePoints*3 coordinates stored correspond to the NCirclePoints points of
   *   the first circle of the pipe. Then, are stored, respectively, the first point of the first circle,
   *   its corresponding point on the next circle, the second point of the first circle, its corresponding
   *   point on the next circle, ... Finally, the last NCirclePoints*3 coordinates correspond to the last circle.
   *   This kind of organization allows the drawing of the curved pipe body thanks to triangles strips, by taking the points
   *   in the order they are stored.
   *   For example, let's assume that we have a curved pipe made with a 3 vertices curve and 4 vertices circles.
   *   We have 3 circles called C1, C2 and C3. If we use the notation C1.P1 to designate the first point of the first
   *   circle, the array will look like this :
   *   <pre>
   *      
   *                               -----------
   *                              | oVertices |
   *                               -----------
   *                           {  |   C1.P1   |  
   *       first circle points {  |   C1.P2   |   
   *                           {  |   C1.P3   |   
   *                           {  |   C1.P4   |   
   *                              |   C1.P1   | }
   *                              |   C2.P1   | }
   *                              |   C1.P2   | }
   *                              |   C2.P2   | } 
   *                              |   C1.P3   | }
   *                              |   C2.P3   | }
   *                              |   C1.P4   | }
   *                              |   C2.P4   | }
   *                              |   C2.P1   | } intermediate pipe body
   *                              |   C3.P1   | }
   *                              |   C2.P2   | }
   *                              |   C3.P2   | }
   *                              |   C2.P3   | }
   *                              |   C3.P3   | }
   *                              |   C2.P4   | }
   *                              |   C3.P4   | }
   *                            { |   C3.P1   |
   *         last circle points { |   C3.P2   |
   *                            { |   C3.P3   |
   *                            { |   C3.P4   |   
   *                               -----------
   *                
   *
   *   </pre>
   * Of course, for each point we have in reality 3 fields in the array, corresponding to
   * this point's coordinates. 
   * @param oVerticesArraySize
   *   the oVertices array size. This size is equal to three times the number of vertices
   *   used to describe the main curve, cross the number of vertices used to describe each circle,
   *   cross two.
   * @param oNormals
   *   Retrieves an array made of normals coordinates. It is organized as <tt>oVertices</tt> : one vertex has exactly
   *   one normal at the same field entry.
   * @param oNormalsArraySize
   *   Retrieves The size, in floats, of the <tt>oNormal</tt> array. Equal to three times the number
   *   of normals.
   * @param oTriangleIndices
   *   Indices of pipe single triangles vertices. 
   *    Always equal to NULL.
   * @param oNbTriangle
   *   Number of pipe single triangles. 
   *   Always equal to 0.
   * @param oTriangleStripIndices
   *    Retrieves the array used to store the pipe triangles strips vertices. The pipe body is made
   *    with triangles strips. Each field contains a
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
   *    For example, index ij0 allows to access to the pipe j-th strip first vertex 
   *    wich coordinates are X = *oVertices[ij0], Y = *oVertices[ij0 + 1] and Z = *oVertices[ij0 + 2], and
   *    which normal coordinates are Nx = *oNormals[ij0], Ny = *oNormals[ij0 + 1] and Nz = *oNormals[ij0 + 2].   
   * @param oNbTriangleStrip
   *    Retrieves the number of triangles strips used to describe the pipe body.
   * @param oNbVertexPerTriangleStrip
   *    Retrieves an array containing the number of vertices for each pipe triangles strip.
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
   *   Retrieves the array used to store the pipe triangles fans vertices indices. There is only 2 triangles fans
   *   in a curved pipe: one for each extremities circle.
   *   Each field contains a
   *   vertex index, belonging to one of the fans, in the <tt>oVertices</tt> array.  As, we find, in the
   *   <tt>oVertices</tt> array, the XYZ coordinates for each
   *   vertex, the indices used to designate the vertices are multiples of three.
   *   <pre>
   *
   *
   *                   ----------------------
   *                  | *oTriangleFanIndices  |
   *                   ----------------------
   *                  |          i00         |   }
   *                  |          i01         |   } first triangle fan defined
   *                  |           .          |   } by the first n0 indices
   *                  |           .          |   }
   *                  |          i0n0        |   }
   *                  |                      |
   *                  |          i10         |   }
   *                  |          i11         |   }
   *                  |           .          |   } second triangle fan 
   *                  |           .          |   } with n1 vertices
   *                  |          i1n1        |   }
   *                   ----------------------
   *
   *
   *   </pre> 
   *   For example, index i10 allows to access the pipe second fan first vertex
   *   wich coordinates are X = *oVertices[i10], Y = *oVertices[i10 + 1] and Z = *oVertices[i10 + 2], and
   *   which normal coordinates are Nx = *oNormals[i10], Ny = *oNormals[i10 + 1] and Nz = *oNormals[i10 + 2].
   * @param oNbTriangleFan
   *    Retrieves the number of pipe triangles fans. Always equal to 2.
   * @param oNbVertexPerTriangleFan
   *    Retrieves the array containing the number of vertices for each pipe triangles fan.
   *    The size of this array is equal to 2. For example, the first fan
   *    is made with <tt>*oNbVertexPerTriangleStrip[0]</tt> vertices.
   *    <pre>
   *                --------------------------
   *               | *oNbVertexPerTriangleFan |
   *                --------------------------
   *               |             n0           |
   *               |             n1           |   n1 = number of vertices of the second fan. (*oNbVertexPerTriangleFan[1]
   *                --------------------------    
   *
   *   </pre>
   * @param oTextureCoord
   *    Retrieves an array made of face texture coordinates: UUUU... or UVUVUVUV... or UVWUVWUVWUVW...
   *    Its size is equal to three times the 3D bounding GP vertices number.
   * @param oTextureCoordArraySize
   *    Retrieves the size, in floats, of the <tt>oTextureCoord</tt> array. Equal to <tt>oTextureCoordDimension</tt> times the
   *    vertices number.
   *    If information on vertices is shared with another element,
   *    returned size for this parameter is equal to 0.
   * @param oTextureCoordDimension
   *    Retrieve the number of texture coordinates per vertex.
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



  /**
   * Retrieves curved pipe vertices coordinates.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * int allocate;
   * float * vertices;
   * ...
   * GetVertices(&allocate, &vertices, ...);
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
   *    oAllocate flag is always returned equal to 1: <tt>GetVertices</tt> always
   *    allocates the returned arrays.
   * @param oVertices
   *   Retrieves an array made of curved pipe vertices coordinates: XYZXYZXYZ...
   *   If we have a pipe made
   *   with NCircles circles and that each circle is described with NCirclePoints points,
   *   <tt>oVertices</tt> array size is equal to NCircles * NCirclePoints * 3 * 2.
   *   The array is structured like this:
   *   the first NCirclePoints*3 coordinates stored correspond to the NCirclePoints points of
   *   the first circle of the pipe. Then, are stored, respectively, the first point of the first circle,
   *   its corresponding point on the next circle, the second point of the first circle, its corresponding
   *   point on the next circle, ... Finally, the last NCirclePoints*3 coordinates correspond to the last circle.
   *   This kind of organization allows the drawing of curved pipe thanks to triangles strips, by taking the points
   *   in the order they are stored.
   *   For example, let's assume that we have a curved pipe made with a 3 vertices curve and 4 vertices circles.
   *   We have 3 circles called C1, C2 and C3. If we use the notation C1.P1 to designate the first vertex of the first
   *   circle, the array will look like this :
   *   <pre>
   *      
   *                               -----------
   *                              | oVertices |
   *                               -----------
   *                           {  |   C1.P1   |  
   *       first circle points {  |   C1.P2   |   
   *                           {  |   C1.P3   |   
   *                           {  |   C1.P4   |   
   *                              |   C1.P1   | }
   *                              |   C2.P1   | }
   *                              |   C1.P2   | }
   *                              |   C2.P2   | } 
   *                              |   C1.P3   | }
   *                              |   C2.P3   | }
   *                              |   C1.P4   | }
   *                              |   C2.P4   | }
   *                              |   C2.P1   | } intermediate pipe body
   *                              |   C3.P1   | }
   *                              |   C2.P2   | }
   *                              |   C3.P2   | }
   *                              |   C2.P3   | }
   *                              |   C3.P3   | }
   *                              |   C2.P4   | }
   *                              |   C3.P4   | }
   *                            { |   C3.P1   |
   *         last circle points { |   C3.P2   |
   *                            { |   C3.P3   |
   *                            { |   C3.P4   |   
   *                               -----------
   *                
   *
   *   </pre>
   * Of course, for each point we have in reality 3 fields in the array, corresponding to
   * this point's coordinates.
   * @param oVerticesArraySize
   *   the oVertices array size. This size is equal to three times the number of vertices
   *   used to describe the main curve, cross the number of vertices used to describe each circle,
   *   cross two.
   */
  void GetVerticesReadOnly (int          * oAllocate,
                            float const ** oVertices,
                            int          * oVerticesArraySize)const;
    
  /**
   * Retrieves the attributes of the class.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * float * curveVertices;
   * int nCurveVertices;
   * ...
   * Get(&curveVertices, &nCurveVertices, ...);
   * </pre></tt><br>
   * @param oCurveVertices
   *   Retrieves an array made of main curve vertices coordinates: XYZXYZXYZ...
   *   Its size is equal to three times the number of vertices
   *   used to describe the main curve.
   * @param oNbCurveVertices
   *   Retrieves the number of vertices used to describe the main curve.
   * @param oCirclesVertices
   *   Retrieves an Array made of curved pipe's circles coordinates. There is
   *   one circle per curve vertex, and a constant number of vertices
   *   to describe each of these circles. So, this array size is equal to
   *   <tt>oNbCurveVertices * oNbVerticesPerCircle * 3</tt>.
   *   For example, if we choose to describe each circle of the pipe with
   *   20 points, the pipe second circle first point coordinates are :
   *   <tt>x = oCirclesVertices[3*oNbVerticesPerCircle], y = oCirclesVertices[3*oNbVerticesPerCircle+1] and
   *   z = oCirclesVertices[3*oNbVerticesPerCircle+2].
   * @param oNbVerticesPerCircle
   *   Retrieves the number of vertices used to describe every circles of the pipe.
   * @param oBaseNormal
   *   Retrieves the array made of curved pipe base circle normal coordinates. Its size is three.
   * @param oEndNormal
   *   Retrieves the array made of curved pipe end circle normal coordinates. Its size is three.
   * @param iPipeRadius
   *   Retrieves the global pipe radius. 
   */
  void Get (float ** oCurveVertex,
            int    * oNbCurveVertex,
            float ** oCircleVertex,
            int    * oNbCircleVertex,
            float ** oBaseNormal,
            float ** oEndNormal,
            float  * oRadiusInverse);

  
   
  /**
   * @nodoc : deprecated 
   * in favor of GetTextureCoordinates (float ** oTextureCoord, int * oDimension)
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
    inline void GetTextureCoordinatesReadOnly     (float const ** oTextureCoord)const;

  
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
    inline void GetTextureCoordinatesReadOnly     (float const ** oTextureCoord, int * oDimension)const;

  /**
   * @nodoc
   */
  void ComputeTextureCoordinates (const CATMappingOperator &iOper);
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);
    
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
  inline unsigned int StorageIDisValid();
    
  /**
   * @nodoc
   */
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);
    
  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;

protected:
  /**
   * @nodoc : deprecated R216
   * see CAT3DCurvedPipeGPEditHelper
   * Sets the texture coordinates.
   * @param iTextureCoord
   *    Array of texture coordinates. Each vertex has an associated position
   *    in the texture map. The number of texture coordinates groups is always equal to the number of
   *    vertices.
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
   */
  void SetTextureCoordinates(float* iTextureCoord, int iFormat);

  /**
   * @nodoc
   */
  void SetTextureCoordinates(float const* iTextureCoord, int iFormat);

  void Swap(CAT3DCurvedPipeGP* iOther);
    
    // Destruction:
    // ------------
    
  virtual ~CAT3DCurvedPipeGP (void);
    
    
  // Reduced tesselation information:
  // --------------------------------
  
  float *_curve_vertex;
  int    _nb_curve_vertex;
  float *_circle_vertex;
  int    _nb_circle_vertex; //Number of vertices per circle
  float  _base_normal[3];
  float  _end_normal[3];
  float  _radius_inverse;
  float *_TextureCoordinates; // Texture coordonnates.
  int _NumberOfTC;		//Number of texture coordinate.
  unsigned int _StorageID;
};
//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline void CAT3DCurvedPipeGP::GetTextureCoordinatesReadOnly (float const **texture_coord)const
{
  *texture_coord=_TextureCoordinates;  
}

inline void CAT3DCurvedPipeGP::GetTextureCoordinatesReadOnly (float const ** oTextureCoord, int * oDimension)const
{
  *oTextureCoord=_TextureCoordinates;
  *oDimension = 3;
}

inline void CAT3DCurvedPipeGP::SetStorageID(unsigned int iStorageID)
{
  _StorageID = iStorageID;
}

inline unsigned int CAT3DCurvedPipeGP::GetStorageID()
{
  return _StorageID;
}

inline unsigned int CAT3DCurvedPipeGP::StorageIDisValid()
{
  if (_StorageID==0 || _StorageID==INVALID_STORAGEID)
    return 0;
  else
    return 1;
}

#endif
