#ifndef CATVizUV3DEdge_H
#define CATVizUV3DEdge_H

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
//                CATVizUV3DEdge
//                  CATViz3DEdge
//                    CATGraphicPrimitive
//                      CATBaseUnknown (SYSTEM framework)
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

#include "CATViz3DEdge.h"
#include "IUnknown.h"
#include "CATVizIndexType.h"
#include "CATVizMacForMetaClass.h"

#include "CATVisMacroForInterfaces.h"
#include "IVisSG3DPolyline.h"

class CATVizUV3DEdgeIVisSG3DPolylineBOAImpl;

class CATVizVertexBuffer;

class CATVizUV3DFace;

template <class T> class CATVizTinyPtrList;

class ExportedBySGInfra CATVizUV3DEdge : public CATViz3DEdge
{
   CATVizDeclareClass;
   
public:
   CATVisDeclarePublicInterfaceAdhesion(CATVizUV3DEdge, IVisSG3DPolyline, CATVizUV3DEdgeIVisSG3DPolylineBOAImpl);

   /** @nodoc */
   CATVizUV3DEdge (void);
   /** @nodoc */
   CATVizUV3DEdge (const CATVizUV3DEdge & toCopy);
   
   /** @nodoc */
   //CATVizUV3DEdge(CATVizUV3DFace *iFace1, CATVizUV3DFace *iFace2, const unsigned int iVerticesIndices[], const unsigned int iNbVerticesIndices, CATVizIndexType iIndexType = CATVizUIntType, CATVizAllocMode iAllocMode = CATVizAllocModeAllocate);
   
   /** @nodoc */
   //CATVizUV3DEdge(CATVizUV3DFace *iFace1, CATVizUV3DFace *iFace2, const void * iVerticesIndices1, const void * iVerticesIndices2, const unsigned int iNbVerticesIndices, CATVizIndexType iIndexType, CATBoolean iPacked, CATVizAllocMode iAllocMode = CATVizAllocModeAllocate);

   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();
   
   /** @nodoc */
   virtual size_t Allocate( const unsigned int iNbVerticesIndices,
                            void * &           oIndicesOnFace1,
                            void * &           oIndicesOnFace2,
                            CATVizIndexType    iIndexType,
                            CATBoolean         iPacked);

   /** @nodoc */
   virtual void Empty();

   /** @nodoc */
   inline void SetId(unsigned int id);

   /** @nodoc */
   virtual unsigned int GetId();

   /** @nodoc */
	virtual void Draw(CATRender &iRender);

   /** @nodoc */
   virtual void Draw(CATRender &iRender, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

   /** @nodoc */
   virtual HRESULT ConvertIndicesTo(CATVizIndexType iIndexType, int checkValidity = 1);

   /** @nodoc */
   virtual void Unpack();

   /** @nodoc */
   HRESULT SetAdjacentFaces(CATVizUV3DFace * face1, CATVizUV3DFace * face2);

   /** @nodoc */
   virtual HRESULT GetAdjacentFaces(CATViz3DFace * & face1, CATViz3DFace * & face2);

	/** @nodoc */
	void SetFace1(CATVizUV3DFace *face);
	
   /** @nodoc */
	void SetFace2(CATVizUV3DFace *face);
	
   /** @nodoc */
	CATViz3DFace *GetFace1();
	
   /** @nodoc */
	CATViz3DFace *GetFace2();

   /** @nodoc */
  CATViz3DFace *GetFace(unsigned int index);

   /** @nodoc */
  unsigned int GetNumberOfFaces();

   /** @nodoc */
  void AddFace(CATVizUV3DFace *face);

   /** @nodoc */
  void RemoveFace(CATVizUV3DFace *face);

   /** @nodoc */
	const void *GetIndicesInFace2();

   /** @nodoc */
   virtual CATVizVertexBuffer* GetVertexBuffer();

   virtual HRESULT ChangeIndices(const void * iIndices, unsigned int iNbIndices, CATVizIndexType iIndexType);

   HRESULT ChangeIndicesInFace2(const void * iIndices, CATVizIndexType iIndexType);

   void GetIndicesInFace(CATVizUV3DFace *borderFace, const void * & oIndices, unsigned int & oIndicesSize, CATVizIndexType & indexType);
	
	virtual CATBoolean HasExplicitTangents();

  unsigned int GetRefinementLevel();

protected:

   /** @nodoc */
   virtual unsigned int GetMaxIndex();


   /** @nodoc */
   void FreeIndicesInFace2();

   /** @nodoc */
   virtual ~CATVizUV3DEdge();
   
	 void *           _indicesInFace2;

   CATVizUV3DFace * _face1;
   union
   {
     CATVizUV3DFace * _face2;
     CATVizTinyPtrList<CATVizUV3DFace> * _listFaces;
   };
   unsigned int _id;
};

inline void CATVizUV3DEdge::SetId(unsigned int id)
{
	_id = id;
}

#endif
