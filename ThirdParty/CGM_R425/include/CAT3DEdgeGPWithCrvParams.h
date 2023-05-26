#ifndef CAT3DEdgeGPWithCrvParams_H
#define CAT3DEdgeGPWithCrvParams_H

// COPYRIGHT DASSAULT SYSTEMES 1999


//******************************************************************************
//  Abstract:
//  ---------
//    Representation of an edge on an element, generally an exact solid.
//    The edge shares the data of the two faces it belongs to (in fact, only
//    the vertices of the first face are being used).
//    The adresses of the faces are stored to complete the topological informa-
//    tion on the element. Beware of any modification in the architecture.
//    It is designed to be used by the CATSurfacicRep.
//
//    The edge is a 3d polyline, with chained vertices references.
//
//******************************************************************************
//  Usage:   
//  ------
//    Needed building information:
//      - Faces adresses (CAT3DBoundingGP children),
//      - Indices making the edge (use 0 3 6... not vertices numbers).
//    The reference of the vertices array is being stored at the creation, using
//    the tessellation Get method provided on the CAT3DBoundingGP.
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DEdgeGP
//                  CATGraphicPrimitive
//                    CATBaseUnknown (SYSTEM framework)
//
//******************************************************************************
//
//  Main Methods:
//  -------------
//    Construction,
//    Get,
//    Draw.
//    DrawM.
//
//******************************************************************************

#include "SGInfra.h"
#include "CAT3DEdgeGP.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;
class CAT3DEdgeGPEditHelper;

/**
 * Class to create the graphic primitive of a 3D edge.
 * <b>Role</b>:
 *    Representation of an edge on an element, generally an exact solid.
 *    The edge shares the data of the two faces it belongs to (in fact, only
 *    the vertices of the first face are being used).
 *    The adresses of the faces are stored to complete the topological informa-
 *    tion on the element.
 *    It is designed to be used by the CATSurfacicRep.
 *    The edge is a 3d polyline, with chained vertices references.
 */
class ExportedBySGInfra CAT3DEdgeGPWithCrvParams final : public CAT3DEdgeGP
{
    
  CATDeclareClass;
  CATVizDeclareClass;
  
  friend class CAT3DEdgeGPEditHelper;
  
  public:
    
    // Building:
    // ---------
    //   Vertex information is shared on the FIRST face of the building method.
    //   The second face information can be set to NULL if it doesn't exist.

  /**
   * Default constructor.
   */
    CAT3DEdgeGPWithCrvParams (void);

  /**
   * Constructs a 3D edge graphic primitive from the two faces it belongs to,
   * its vertices indices their number, and their coordinates along the edge curve.
   * @param iFace1
   *    The first face the edge belongs to. This face shares vertices
   *    informations with the edge.
   * @param iFace2
   *    The second face the edge belongs to. This face can be set to NULL if
   *    doesn't exist.
   * @param iVerticesIndices
   *    Edge vertices indices array, taken from the first face. This means that these
   *    indices allow to access vertices coordinates only through first face data.
   * @param iNbVertices
   *    The number of vertices in the edge.
   * @param iCrvParams
   *    An array of float containing the parameters of the edge points along the curve.
   */
    CAT3DEdgeGPWithCrvParams (CAT3DBoundingGP *iFace1,CAT3DBoundingGP *iFace2,
     int const*iVerticesIndices,int iNbVertices, float const*iCrvParams);

  /**
   * Retrieves edge's vertices and faces informations.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * CAT3DBoundingGP * fref1, *fref2;
   * float * verticesFref1;
   * ...
   * Get(&fref1, &fref2, &verticesFref1, ...);
   * </pre></tt><br>
   * @param oFref1
   *    Retrieves a pointer to the edge first face.
   * @param oFref2
   *    Retrieves a pointer to the edge second face.
   * @param oVerticesFref1
   *    Retrieves the first face vertices coordinates array: XYZXYZXYZ...
   *    The edge vertices can be retrieved from this array thanks to their
   *    indices stored in *oIndices.
   * @param oIndices
   *    Retrieves the array of edge vertices indices. These indices allow the
   *    the access to vertices coordinates thanks to the *oVerticesFref1 array.
   *    For example, to get the edge first vertex coordinates, one must use
   *    the *oVerticesFref1 array combined with the *oIndices array, like this :
   *    v0.x = (*oVerticesFref1)[(*oIndices)[0]], v0.y = (*oVerticesFref1)[(*oIndices)[0]+1], v0.z = (*oVerticesFref1)[(*oIndices)[0]+2].
   * @param oIndicesSize
   *    Retrieves the oIndices array size.
   * @param oCrvParams
   *    Retrieves the float coordinates of the edge points along the edge curve
   */
    void GetReadOnly (CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
                      float const**oVerticesFref1,int const**oIndices,int *oIndicesSize, float const**oCrvParams)const;

  virtual HRESULT GetCrvParamsReadOnly(float const**oCrvParams)const;
  virtual HRESULT GetTangentsReadOnly(float const**tangents)const;

   /**
   * @nodoc
   * Streaming
   */
   virtual void Stream(CATStreamer& oStr,int iSaveType=0);

   /**
   * @nodoc
   * Streaming
   */
   virtual void UnStream(CATStreamer& iStr);

  protected:
  virtual HRESULT SetTangents(float *tangents, int copy);
  virtual HRESULT SetTangents(float const *tangents);
    
    // Destruction:
    // ------------
    
    virtual ~CAT3DEdgeGPWithCrvParams (void);
    
  /**
  * @nodoc
  */
  
  float *_crvParams;
  float *_tangents;
};


#endif
