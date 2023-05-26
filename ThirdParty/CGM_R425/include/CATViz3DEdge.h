#ifndef CATViz3DEdge_H
#define CATViz3DEdge_H

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
//                CATViz3DEdge
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

#include "CATVizPrimitive.h"
#include "IUnknown.h"
#include "CATVizIndexType.h"
//#include "CATSupport.h"
#include "CATVizArrayPool.h"
#include "CATVizMacForMetaClass.h"
#include "CATBoolean.h"
#include "CATVisMacroForInterfaces.h"


class IVisSG3DPolyline;
class CATViz3DEdgeIVisSG3DPolylineBOAImpl;

class CATVizVertexBuffer;
class CATStreamer;
class CATViz3DFace;
class CATUVCompressedTangent;
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
class ExportedBySGInfra CATViz3DEdge : public CATVizPrimitive
{
   friend class CATViz3DEdgeIndicesIterator;
   friend class CATDmuStreamSurfacicRep;
   friend class SGCGRStreamerForCATViz3DEdge;
   friend class SGCGRNodesFactoryA;
   CATVizDeclareClass;
   
public:

   CATVisDeclarePublicInterfaceAdhesion(CATViz3DEdge, IVisSG3DPolyline, CATViz3DEdgeIVisSG3DPolylineBOAImpl);
   
   // Building:
   // ---------
   //   Vertex information is shared on the FIRST face of the building method.
   //   The second face information can be set to NULL if it doesn't exist.
   
   /**
   * Default constructor.
   */
   CATViz3DEdge (void);
   CATViz3DEdge (const CATViz3DEdge & toCopy);
   
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
   CATViz3DEdge(const unsigned int iVerticesIndices[], const unsigned int iNbVerticesIndices, CATVizIndexType iIndexType = CATVizUIntType, CATVizAllocMode iAllocMode = CATVizAllocModeAllocate);
   
   /** @nodoc */
   CATViz3DEdge(const void * iVerticesIndices, const unsigned int iNbVerticesIndices, CATVizIndexType iIndexType, CATBoolean iPacked, CATVizAllocMode iAllocMode = CATVizAllocModeAllocate, CATBoolean optimizePointer = 0,CATBoolean poolAllocated = 0);

   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();

   /** @nodoc */
   virtual size_t Allocate(const unsigned int iNbVerticesIndices,
                           void * &           oIndicesOnFace1,
                           CATVizIndexType    iIndexType,
                           CATBoolean         iPacked);
   /** @nodoc */
   virtual size_t Allocate( const unsigned int iNbVerticesIndices,
                            void * &           oIndicesOnFace1,
                            void * &           oIndicesOnFace2,
                            CATVizIndexType    iIndexType,
                            CATBoolean         iPacked);

   /** @nodoc */
   virtual void Draw(CATRender &iRender);

   /** @nodoc */
   virtual int DetailCulling(CATRender *render);

   /**
   * @nodoc
   * Streaming
   */
   virtual void Stream(CATStreamer& oStr,int iSaveType=0);
   INLINE virtual unsigned char GetStreamId() const;
   
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
   * CATViz3DEdge::Skip(str);
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
   */
   inline void GetReadOnly (void const* & oIndices, unsigned int & oIndicesSize, CATVizIndexType & indexType, int unpack = 1)const;
   
   /** @nodoc */
//   virtual HRESULT ComputeTangents(float *& oTangents, unsigned int & oTangentArraySize,unsigned int & oArrayToDelete, CATVizVertexBuffer *iBuffer=NULL);
   virtual HRESULT ComputeTangents(float *& oTangents, unsigned int & oNbTangents, unsigned int & oArrayToDelete, CATVizVertexBuffer *iBuffer=NULL, int allocate = 1, CATViz3DFace *iFace=NULL);
   virtual HRESULT ComputeTangents(CATUVCompressedTangent *& oTangents, unsigned short *& coef, unsigned int & oNbTangents, unsigned int & oArrayToDelete, CATVizVertexBuffer *iBuffer=NULL, int allocate = 1);

   /** @nodoc */
   virtual HRESULT ConvertIndicesTo(CATVizIndexType iIndexType, int checkValidity = 1);
   
   /** @nodoc */
   CATVizIndexType CompressIndices();
   
   /** Gets the edge vertices number */
   inline unsigned int  GetSize (void);    
   
   /** @nodoc */
   inline CATVizIndexType GetIndexType();

   /** @nodoc */
   virtual CATVizVertexBuffer* GetVertexBuffer();
   
   /** @nodoc */
   virtual void Empty();

   /** @nodoc */
   inline int IsPacked() const;

   //++ CAA
   /** @nodoc */
   inline void SetDynamic(CATBoolean isDyn);

   /** @nodoc */
   inline CATBoolean IsDynamic();
   //-- CAA

   /** @nodoc */
   virtual void Unpack();

   /** @nodoc */
   CATBoolean IsSeam();

   /** @nodoc */
   void SetSeam(CATBoolean isSeam);
   
   /**
    * Retrieves the edge's adjacent faces.<br>
    * May not be implemented. In this case will return E_NOT_IMPL.
    */
   virtual HRESULT GetAdjacentFaces(CATViz3DFace * & face1, CATViz3DFace * & face2);
  
   /** @nodoc */
   virtual HRESULT ChangeIndices(const void * iIndices, unsigned int iNbIndices, CATVizIndexType iIndexType);

   /** @nodoc */
  virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

   CATVizDeclareTinyRefCount(5); // 5 bits refCount

protected:
  void Swap(CATViz3DEdge* iOther);

  virtual unsigned int GetMaxIndex();
  inline void *GetIndicesPointer();
  inline void const* GetIndicesPointer()const;
  inline void FreeIndices();

   /** @nodoc */
   virtual ~CATViz3DEdge();
  
   unsigned int _isSeam : 1; // [SWX] Seam edges...
   //unsigned int _nbIndices     : 19; // 27 bits were used when TinyRefCount did not exist
   //----- 5 bits reserved for RefCount
   unsigned int _nbIndices     ; // NHD - HF-373538-3DEXPERIENCER2014x_. We now use full 32 bits
   unsigned int _poolAllocated : 1;
   unsigned int _optimizeIndicesPointer : 1;
   CATVizIndexType _indexType : 2;
   unsigned int _isPacked     : 1;
   unsigned int _isManifold   : 1;
   unsigned int _isDynamic    : 1;
   void *       _indices;
};

class ExportedBySGInfra CATViz3DEdgeIndicesIterator
{
public :
   
   CATViz3DEdgeIndicesIterator(CATViz3DEdge & iEdge);
   virtual ~CATViz3DEdgeIndicesIterator();

   void SetVerticesIndicesAsPosInArray(int iOnOff);
   int  AreVerticesIndicesAsPosInArray();

   unsigned int GetNbIndices();
   unsigned int GetIndex(unsigned int iIndex);
   void         SetIndex(unsigned int iIndex, unsigned int iValue);

protected :

   void InitDataFromEdge();
   void CheckIndexType(unsigned int iValue);

   void const*       _indices;
   unsigned int      _nbIndices;
   CATVizIndexType   _indexType; /** @win64 fbq : 64-bit structure padding **/

   CATViz3DEdge &    _edge;

   unsigned int      _isPacked:1;
   unsigned int      _verticesIndicesAsPosInArray:1;

private :

   CATViz3DEdgeIndicesIterator(const CATViz3DEdgeIndicesIterator &);
   CATViz3DEdgeIndicesIterator & operator = (const CATViz3DEdgeIndicesIterator &);
};


INLINE unsigned char CATViz3DEdge::GetStreamId() const
{
	return VIZEDGE;
}

inline void CATViz3DEdge::GetReadOnly(void const* & index, unsigned int & index_size, CATVizIndexType & indexType, int unpack)const
{
    //UGLY
   if(unpack) ((CATViz3DEdge*)this)->Unpack();
   index      = GetIndicesPointer();
   index_size = _nbIndices;
   indexType  = _indexType;
}

inline CATVizIndexType CATViz3DEdge::GetIndexType()
{
   return _indexType;
}

inline unsigned int CATViz3DEdge::GetSize (void)
{
   return _nbIndices;
}

inline int CATViz3DEdge::IsPacked() const
{
   return _isPacked;
}

inline void CATViz3DEdge::SetDynamic(CATBoolean isDyn)
{
  _isDynamic = isDyn;
}

inline CATBoolean CATViz3DEdge::IsDynamic()
{
  return _isDynamic;
}

inline void *CATViz3DEdge::GetIndicesPointer()
{
  if (_optimizeIndicesPointer)
    return &_indices;
  else
    return _indices;
}

inline void const *CATViz3DEdge::GetIndicesPointer()const
{
  if (_optimizeIndicesPointer)
    return &_indices;
  else
    return _indices;
}

inline void CATViz3DEdge::FreeIndices()
{
  if (_optimizeIndicesPointer)
  {
    _optimizeIndicesPointer = 0;
    _indices = NULL;
  }
  else
  {
    if (_poolAllocated)
    {
      unsigned int size = 0;
      switch (_indexType)
      {
        case CATVizUIntType:
          size = _nbIndices * sizeof(unsigned int);
          break;
        case CATVizUShortType:
          size = _nbIndices * sizeof(unsigned short);
          break;
        case CATVizUCharType:
          size = _nbIndices * sizeof(unsigned char);
          break;
      }
      CATVizArrayPool::FreeArray(size,_indices);
    }
	else
	{
		/* CDK2: Replaced delete[] _indices with delete[] after appropriate cast. 
		This is done to avoid deleting a void pointer which is not a good coding practice.*/
		switch (_indexType)
		{
		case  CATVizUIntType:
		{
			delete[](unsigned int *)_indices;
			break;
		}
		case  CATVizUShortType:
		{
			delete[](unsigned short *)_indices;
			break;
		}
		case  CATVizUCharType:
		{
			delete[](unsigned char *)_indices;
			break;
		}
		}
	}
    
    _indices = NULL;
  }
}


#endif
