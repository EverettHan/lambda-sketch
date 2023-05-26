#ifndef CAT3DCylinderGP_H
#define CAT3DCylinderGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DCylinderGP
//                  CAT3DBoundingGP
//                    CATGraphicPrimitive
//                      CATBaseUnknown (SYSTEM framework) 
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DBoundingGP.h"

class CATCylinderNormalCollector;
class CATStreamer;
class CAT3DCylinderGPEditHelper;

/**
 * Class to create the graphic primitive of a 3D cylinder.
 * <b>Role</b>:
 * Tesselation is stored the simplest way: 2 fans for extremal sections, 1 strip for the
 * body of the cylinder. We only store vertices for the base section, and we
 * dynamically generate tesselation during the draw.
 */
class ExportedBySGInfra CAT3DCylinderGP : public CAT3DBoundingGP
{
  friend class CATMarshallable3DCylinderGP;
  friend class CAT3DCylinderGPEditHelper;
  friend class SGCGRStreamerFor3DCylinderGP;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;  
public:

  /**
   * Default constructor.
   */
  CAT3DCylinderGP (void);

   /**
   * Constructs a 3D cylinder from its bottom face center coordinates, its extusion 
   * vector, its radius and the sag used for tesselation.
   * @param iCenter
   *   Array made with the three coordinates of the cylinder bottom extremal face center.
   * @param iExtrusion
   *   Array made with the extrusion vector coordinates. Indeed, a cylinder is the extrusion
   *   of a circle along a vector. The length of the <tt>iExtrusion</tt> vector is the
   *   length of the cylinder. this array size is equal to three.
   * @param iRadius
   *   The radius of the cylinder.
   * @param iSag
   *   This parameter defines the number of vertices along the cylinder,
   *   and means the chordal deviation along the base circle.
   */
  CAT3DCylinderGP (float *iCenter,      
                   float *iExtrusion,   
                   float iRadius,       
                   float iSag);         
    
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
    * Draws the cylinder.
    * @param iRender
    *   The render through which the cylinder is drawn.
    */
  virtual void Draw (CATRender &iRender) GP_FUNC_OVERRIDE_FINAL;
    
    /**
   * Retrieves the tesselation information from the cylinder.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * int allocate;
   * float const* vertices;
   * ...
   * GetReadOnly(&allocate, &vertices, ...);
   * </pre></tt><br>
   * @param oAllocate
   *    Flag specifying whether retrieved data is copied or not.
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
   *    Retrieves an array made of cylinder vertices coordinates: XYZXYZXYZ...
   *    If we have NCirclePoints to describe the base cylinder circle, the size of this array
   *    is equal to 3 * 4 * NCirclePoints.
   *    This array is structured like this:
   *    Its first NCirclePoints*3 fields contain the bottom circle vertices coordinates.
   *    Then, are stored respectively, the bottom circle first vertex coordinates, the top circle
   *    corresponding vertex coordinates, the bottom circle second vertex coordinates, the top circle
   *    corresponding vertex coordinates ... Finally, the last NCirclePoints*3 coordinates correspond to
   *    the top circle vertices coordinates. This kind of organization allows the drawing of the cylinder
   *    body thanks to triangles strips, by taking the points
   *    in the order they are stored.
   *    For example, let's assume that our bottom circle is tesselated thanks to 4 vertices. Let's call
   *    the bottom circle BC and the top circle TC. If the notation BC.P1 designates the first vertex of the
   *    bottom circle, the oVertices array will look like this :
   *   <pre>
   *      
   *                               -----------
   *                              | oVertices |
   *                               -----------
   *                           {  |   BC.P1   |  
   *      bottom circle points {  |   BC.P2   |   
   *                           {  |   BC.P3   |   
   *                           {  |   BC.P4   |   
   *                              |   BC.P1   | }
   *                              |   TC.P1   | }
   *                              |   BC.P2   | }
   *                              |   TC.P2   | } 
   *                              |   BC.P3   | } intermediate cylinder body
   *                              |   TC.P3   | }
   *                              |   BC.P4   | }
   *                              |   TC.P4   | }
   *                            { |   TC.P1   |
   *          top circle points { |   TC.P2   |
   *                            { |   TC.P3   |
   *                            { |   TC.P4   |   
   *                               -----------
   *                
   *
   *   </pre>
   * Of course, for each point we have in reality 3 fields in the array, corresponding to
   * this point's coordinates.
   * @param oVerticesArraySize
   *   the oVertices array size. This size is equal to three times the number of vertices used
   *   to describe the bottom circle cross four.
   * @param oNormals
   *   Retrieves an array made of normals coordinates. It is organized as <tt>oVertices</tt> : one vertex has exactly
   *   one normal at the same field entry.
   * @param oNormalsArraySize
   *   Retrieves The size, in floats, of the <tt>oNormal</tt> array. Equal to three times the number
   *   of normals and equals to oVerticesArraySize.
   * @param oTriangleIndices
   *   Indices of cylinder single triangles vertices. 
   *    Always equal to NULL.
   * @param oNbTriangle
   *   Number of cylinder single triangles. 
   *   Always equal to 0.
   * @param oTriangleStripIndices
   *    Retrieves the array used to store the cylinder triangles strip. There is only one
   *    triangles strip, used to describe the cylinder body. Each field contains a
   *    vertex index, belonging to the strip, in the oVertices array.  As, we find, in the
   *    <tt>oVertices</tt> array, the XYZ coordinates for each
   *    vertex, the indices used to designate the vertices are multiples of three.
   * @param oNbTriangleStrip
   *    Retrieves the number of triangles strips used to describe the cylinder body.
   *    Always equal to 1.
   * @param oNbVertexPerTriangleStrip
   *    Retrieves an array, which size is one, containing the number of vertices
   *    used in the strip. If NCirclePoints is the number of vertices used to describe the 
   *    cylinder bottom circle, the number of vertices belonging to the strip is equal to
   *    2*NCirclePoints*3 + 2.
   * @param oTriangleFanIndices
   *   Retrieves the array used to store the cylinder triangles fans vertices indices. There is only 2 triangles fans
   *   in a cylinder: one for each extremities circle.
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
   *   For example, index i10 allows to access the cylinder second fan first vertex
   *   wich coordinates are X = *oVertices[i10], Y = *oVertices[i10 + 1] and Z = *oVertices[i10 + 2], and
   *   which normal coordinates are Nx = *oNormals[i10], Ny = *oNormals[i10 + 1] and Nz = *oNormals[i10 + 2].
   * @param oNbTriangleFan
   *    Retrieves the number of cylinder triangles fans. Always equal to 2.
   * @param oNbVertexPerTriangleFan
   *    Retrieves the array containing the number of vertices for each cylinder triangles fan.
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
   * Retrieves the cylinder vertices coordinates.<br>
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
   *    Retrieves an array made of cylinder vertices coordinates: XYZXYZXYZ...
   *    If we have NCirclePoints to describe the base cylinder circle, the size of this arrsy
   *    is equal to 3 * 4 * NCirclePoints.
   *    This array is structured like this:
   *    Its first NCirclePoints*3 fields contain the bottom circle vertices coordinates.
   *    Then, are stored respectively, the bottom circle first vertex coordinates, the top circle
   *    corresponding vertex coordinates, the bottom circle second vertex coordinates, the top circle
   *    corresponding vertex coordinates ... Finally, the last NCirclePoints*3 coordinates correspond to
   *    the top circle vertices coordinates. This kind of organization allows the drawing of the cylinder
   *    body thanks to triangles strips, by taking the points
   *    in the order they are stored.
   *    For example, let's assume that our bottom circle is tesselated thanks to 4 vertices. Let's call
   *    the bottom circle BC and the top circle TC. If the notation BC.P1 designates the first vertex of the
   *    bottom circle, the oVertices array will look like this :
   *   <pre>
   *      
   *                               -----------
   *                              | oVertices |
   *                               -----------
   *                           {  |   BC.P1   |  
   *      bottom circle points {  |   BC.P2   |   
   *                           {  |   BC.P3   |   
   *                           {  |   BC.P4   |   
   *                              |   BC.P1   | }
   *                              |   TC.P1   | }
   *                              |   BC.P2   | }
   *                              |   TC.P2   | } 
   *                              |   BC.P3   | } intermediate cylinder body
   *                              |   TC.P3   | }
   *                              |   BC.P4   | }
   *                              |   TC.P4   | }
   *                            { |   TC.P1   |
   *          top circle points { |   TC.P2   |
   *                            { |   TC.P3   |
   *                            { |   TC.P4   |   
   *                               -----------
   *                
   *
   *   </pre>
   * Of course, for each point we have in reality 3 fields in the array, corresponding to
   * this point's coordinates.
   * @param oVerticesArraySize
   *   the oVertices array size. This size is equal to three times the number of vertices used
   *   to describe the bottom circle cross four.
   */
  void GetVerticesReadOnly (int          * oAllocate,
                            float const ** oVertices,
                            int          * oVerticesArraySize)const;
    

  /**
   * @nodoc
   * Retrieves the cylinder bottom face vertices coordinates,
   * the normals to the cylinder and the extrusion parameters.
   * @param oBottomFaceVertices
   *    Retrieves an array made of cylinder bottom face coordinates: XYZXYZXYZ...
   *    This array size is equal to three times oNbVertices.
   * @param oNbVertices
   *    Retrieves the number of vertices used to describe the bottom circle.
   * @param oBodyNormals
   *    Retrieves an array containing the cylinder normals. 
   * @param oExtrusion
   *    Retrieves the extrusion vector coordinates. This vector norm is equal to the cylinder
   *    length. <tt>oExtrusion</tt> vector is equal to norm(oExtrusion)*oDirection. This array size is
   *    equal to three.
   * @param oDirection
   *    Retrieves the normalized cylinder extrusion direction.
   */
  void Get (float ** oBottomFaceVertices,
            int    * oNbVertices,
            float ** oBodyNormals,
            float  * oExtrusion,
            float  * oDirection);

  /**
   * @nodoc
   * Retrieves the extrusion vector, the base vectors of the plan
   * containing the cylinder bottom circle, the cylinder length and
   * the bottom circle center coordinates.
   * @param oExtrusionVector
   *    Retrieves the extrusion vector coordinates. This vector norm is equal to the cylinder
   *    length. This array size is equal to three.
   * @param oAxis_x
   *    Retrieves one of the two vectors constituing a base for
   *    the plan containing the cylinder bottom circle.
   * @param oAxis_y
   *    Retrieves the second vector constituing a base for
   *    the plan containing the cylinder bottom circle.
   * @param oLength
   *    Retrieves the cylinder length. 
   * @param oCenter
   *    Retrieves the array made of the cylinder bottom circle center coordinates.
   */
  void Get (float *oExtrusionVector,
            float *oAxis_x,
            float *oAxis_y,
            float *oLength,
            float *oCenter);
    
    


  /**
   * @nodoc
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
  inline void GetTextureCoordinatesReadOnly (float const** oTextureCoord)const;


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
  inline void GetTextureCoordinatesReadOnly (float const** oTextureCoord, int * oDimension)const;

  /**
   * @nodoc
   */
  void ComputeTextureCoordinates (const CATMappingOperator &iOper);
  
  /**
   * @nodoc
   */
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

  /**
   * @nodoc
   */
   static unsigned int GetNormalCollectorSizeInBytes(int iIncludeStructuralSize = 1); 

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;
    
protected:
  /**
   * @nodoc
   * See CAT3DCylinderGPEditHelper
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

  void Swap(CAT3DCylinderGP* iOther);
    
    // Destruction:
    // ------------
    
  virtual ~CAT3DCylinderGP (void);
    
    
  // Reduced tesselation information:
  // --------------------------------
  
  int     _NbVertices;         // Number of vertices around the circle.
  float   _Longueur;           // 1/long extrusion memorized only to optimize.
  float   _Extrusion[3];       // Direction and length defining the cylinder.
  int     _IndexNormalRef;     // Reference to a common normal array.
  float  *_BottomFaceVertices; // Vertices used as bottom face tesselation.
  float  *_TextureCoordinates; // Texture coordonnates.
  int     _NumberOfTC;         // Number of texture coordonnates.
  
  static CATCylinderNormalCollector _cylnor;        // Body normals database.
};




//******************************************************************************
//*** INLINED METHODS: *********************************************************
//******************************************************************************

inline void CAT3DCylinderGP::GetTextureCoordinatesReadOnly (float const** texture_coord)const
{
  *texture_coord=_TextureCoordinates;  
}

inline void CAT3DCylinderGP::GetTextureCoordinatesReadOnly (float const** oTextureCoord, int * oDimension)const
{
  *oTextureCoord=_TextureCoordinates;
  *oDimension = 3;
}

#endif
