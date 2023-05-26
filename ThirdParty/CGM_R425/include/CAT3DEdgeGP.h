#ifndef CAT3DEdgeGP_H
#define CAT3DEdgeGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

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
#include "CATGraphicPrimitive.h"
#include "CAT3DBoundingGP.h"
#include "CATVizMacForMetaClass.h"

class CATStreamer;
class CATViz3DEdge;

//++ SGCAAPlan
#include "CATVisMacroForInterfaces.h"
class IVisSG3DPolyline;
class CAT3DEdgeGPIVisSG3DPolylineBOAImpl;
class CAT3DEdgeGPEditHelper;
//-- SGCAAPlan

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
class ExportedBySGInfra CAT3DEdgeGP : public CATGraphicPrimitive
{
  
  // Marshalling information:
  // ------------------------
  friend class CAT3DEdgeGPEditHelper;
  friend class CATMarshallable3DEdgeGP;
  friend class CATDmuStreamSurfacicRep;
  friend class CATSurfacicRep;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;
  CATVizDeclareClass;
  CATVisDeclarePublicInterfaceAdhesion(CAT3DEdgeGP, IVisSG3DPolyline, CAT3DEdgeGPIVisSG3DPolylineBOAImpl);
  
public:

    // Building:
    // ---------
    //   Vertex information is shared on the FIRST face of the building method.
    //   The second face information can be set to NULL if it doesn't exist.

  /**
   * Default constructor.
   */
  CAT3DEdgeGP (void);

  /**
   * Constructs a 3D edge graphic primitive from the two faces it belongs to,
   * its vertices indices and their number.
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
   */
  CAT3DEdgeGP (CAT3DBoundingGP *iFace1,CAT3DBoundingGP *iFace2,
               int const*iVerticesIndices,int iNbVertices);

  
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

  /**
   * @nodoc
   * Skips the unstreaming of a 3D Edge.
   * <br><b>Role:</b>: This method can be used when you do not want
   * to unstream an edge. It is used like this :<br>
   * CAT3DEdgeGP::Skip(str);
   * @param iStr
   *   The streamer used to unstream the 3D edges.
   */
  static void Skip(CATStreamer & iStr);

  
  /**
   * Retrieves edge's vertices and faces informations.<br>
   * <b>Role</b>: As this method is designed to return values on its
   * parameters, it has to be called like this :<br>
   * <tt><pre>
   * CAT3DBoundingGP * fref1, *fref2;
   * float const* verticesFref1;
   * ...
   * GetReadonly(&fref1, &fref2, &verticesFref1, ...);
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
   */
  void GetReadOnly (CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
                    float const**oVerticesFref1,int const**oIndices,int *oIndicesSize)const;


  /**
   * @nodoc
   */
  void GetReadOnly (CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2,
                    float const**oVerticesFref1,int const**oIndices,int *oIndicesSize,
                    void **oRenderData)const;
  
  /**
   * @nodoc
   */
  inline void GetBoundingGPs(CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2);
    
  /**
   * Gets the edge vertices number. 
   */
  int  GetSize (void);    

#if defined(REMOVE_USELESS_INCLUDE)
#pragma message(" BADREM : AZX 27102022 " __FILE__ " Its forbiden to override Draw function.")
#endif
  /**
   * Draws the 3D edge.
   * @param iRender
   *   The render through which the edge is drawn.
   */
  virtual void Draw (CATRender & iRender) GP_FUNC_OVERRIDE_FINAL;

  /**
   * @nodoc
   */
  virtual void DrawM (CATRender &, CAT3DEdgeGP** geomL, int n, int m);

  /**
   * @nodoc
   */
  void Empty();

  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

#ifdef _SUNOS_SOURCE
  /**
   * @nodoc
   */
  inline void SetRenderData (void *renderData);

  /**
   * @nodoc
   */
  inline void* GetRenderData (void);
#endif

  /**
   * @nodoc
   */
  virtual CATVizPrimitive * GetVizPrimitive(int &oAllocateMode);

  /**
   * @nodoc
   */
  inline CATVizVertexBuffer * GetVertexBuffer();

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
  virtual HRESULT GetCrvParamsReadOnly(float const** oCrvParams)const;

  /**
   * @nodoc
   */
  virtual HRESULT GetTangentsReadOnly(float const**tangents)const;

  /** @nodoc */
  void SetSeam(CATBoolean isSeam);

  /** @nodoc */
  CATBoolean IsSeam();

  /**
   * @nodoc
   */
  virtual void Visit(CATIGPVisitor& iVisitor) const final;

protected:
  /**
   * @nodoc
   */
  virtual void SetVizPrimitive(CATVizPrimitive* iPrimitive, int iAllocateMode);

  /**
   * @nodoc :deprecated R216
   */
  virtual HRESULT SetTangents(float* tangents, int copy);

  // Destruction:
  // ------------
  
  virtual ~CAT3DEdgeGP (void);
    
  /**
   * @nodoc
   */
  virtual void ResetStorage();
    
  // Face information:
  // -----------------
  
  CAT3DBoundingGP *_fref1,*_fref2;
  CATViz3DEdge    * _vizEdge;

  unsigned int _StorageID;
  
#ifdef _SUNOS_SOURCE
  void *_SUNrenderData;
#endif
};




//******************************************************************************
//*** INLINED FUNCTIONS: *******************************************************
//******************************************************************************


#ifdef _SUNOS_SOURCE
inline void CAT3DEdgeGP::SetRenderData (void *renderData)
{
  _SUNrenderData = renderData;
}

inline void* CAT3DEdgeGP::GetRenderData (void)
{
  return(_SUNrenderData);
}
#endif

inline CATVizVertexBuffer * CAT3DEdgeGP::GetVertexBuffer()
{
  if(_fref1)
  {
     return _fref1->GetVertexBuffer();
  }
  else
  {
     return NULL;
  }
}

inline void CAT3DEdgeGP::GetBoundingGPs(CAT3DBoundingGP **oFref1,CAT3DBoundingGP **oFref2)
{
  *oFref1 = _fref1;
  *oFref2 = _fref2;
}

inline void CAT3DEdgeGP::SetStorageID(unsigned int iStorageID)
{
  _StorageID = iStorageID;
}

inline unsigned int CAT3DEdgeGP::GetStorageID() 
{
  return _StorageID;
}

inline unsigned int CAT3DEdgeGP::StorageIDisValid() const
{
  if (_StorageID == 0 || _StorageID == INVALID_STORAGEID)
    return 0;
  else
    return 1;
}

#endif
