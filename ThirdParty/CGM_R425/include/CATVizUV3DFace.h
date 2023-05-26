#ifndef CATVizUV3DFace_H
#define CATVizUV3DFace_H

// COPYRIGHT DASSAULT SYSTEMES 2006

#include "SGInfra.h"

#include "CATViz3DFace.h"
#include "IUnknown.h"
#include "CATVizIndexType.h"
#include "CATVizMacForMetaClass.h"
#include "CATVizTinyPtrList.h"
class CATVizUV3DEdge;


class ExportedBySGInfra CATVizUV3DFace : public CATViz3DFace
{
   CATVizDeclareClass;
   // SGCAAPlan
public:
   CATVisDeclarePublicInterfaceAdhesion(CATVizUV3DFace, IVisSG3DFace, CATVizUV3DFaceIVisSG3DFaceBOAImpl);

   /** @nodoc */
   CATVizUV3DFace (void);

   /** @nodoc */
   CATVizUV3DFace (const CATVizUV3DFace & toCopy);

   /** @nodoc */
   CATVizUV3DFace (const unsigned int iTriangleIndices[],
                   const unsigned int iNbTriangle,
                   const unsigned int iTriangleStripIndices[],
                   const unsigned int iNbTriangleStrip,
                   const unsigned int iNbVertexPerTriangleStrip[],
                   const unsigned int iTriangleFanIndices[],
                   const unsigned int iNbTriangleFan,
                   const unsigned int iNbVertexPerTriangleFan[],
                   const float *      iPlanarNormal = NULL,
                   CATBoolean         iVBExist = FALSE,
                   const CATVizVertexBuffer * iVB = NULL);

   /** @nodoc */
   CATVizUV3DFace (const void *       iTriangleIndices,
                   const unsigned int iNbTriangle,
                   const void *       iTriangleStripIndices,
                   const unsigned int iNbTriangleStrip,
                   const unsigned int iNbVertexPerTriangleStrip[],
                   const void *       iTriangleFanIndices,
                   const unsigned int iNbTriangleFan,
                   const unsigned int iNbVertexPerTriangleFan[],
                   CATVizIndexType    iIndexType,
                   const float *      iPlanarNormal = NULL,
                   CATBoolean         iPacked = FALSE,
						       char *sudvisionCodes = NULL,
                   CATBoolean         iVBExist = FALSE,
                   const CATVizVertexBuffer * iVB = NULL);

   /** @nodoc */
   void SetId(unsigned int id);

   /** @nodoc */
   inline unsigned int GetId();

   /** @nodoc */
   virtual CATVizPrimitive * Duplicate();

   /** @nodoc */
   virtual void Draw(CATRender &iRender);

	/** @nodoc */
   virtual void Draw(CATRender &iRender, CAT3DViewpoint *viewpoint, CAT3DViewport *viewport);

   /** @nodoc */
   virtual void Empty();

   /** @nodoc */
   void AddEdge(CATVizUV3DEdge *edge);

   /** @nodoc */
   void RemoveEdge(CATVizUV3DEdge *edge);

   /** @nodoc */
   void SetNumberOfEdges(unsigned int nbEdges);

   /** @nodoc */
   virtual HRESULT GetBorderEdges(unsigned int & oNbEdges, CATViz3DEdge** & oEdges);

   /** @nodoc */
   inline CATVizUV3DEdge **GetEdges(unsigned int & nbEdges);
  
   inline void SetRefinementLevel(unsigned int refinementLevel);

   /** @nodoc */
   inline unsigned int GetRefinementLevel();

   /** @nodoc */
   void DisconnectFromAdjacentCells();

   /** @nodoc */
   inline CATVizTinyPtrList<CATVizUV3DEdge> *GetEdges();

   /** @nodoc */
   inline void SetDynamic(CATBoolean isDyn);

   /** @nodoc */
   inline CATBoolean IsDynamic();

   /** @nodoc */
   virtual bool IsVBOFace();


protected:

   /** @nodoc */
   virtual ~CATVizUV3DFace();

	

   unsigned int _id;
   unsigned int _refinementLevel : 3;
   unsigned int _isDynamic : 1;
   unsigned int _orientation : 1; // used by derivedClass CATVizUV3DCanonicalFace 0 <-> -1, 1 <-> 1

   CATVizTinyPtrList<CATVizUV3DEdge> _edges;
};

inline CATVizUV3DEdge **CATVizUV3DFace::GetEdges(unsigned int & nbEdges)
{
	return _edges.GetTable(nbEdges);
}

inline CATVizTinyPtrList<CATVizUV3DEdge> *CATVizUV3DFace::GetEdges()
{
	return &_edges;
}

inline unsigned int CATVizUV3DFace::GetId()
{
	return _id;
}

inline void CATVizUV3DFace::SetDynamic(CATBoolean isDyn)
{
  _isDynamic = isDyn;
}

inline CATBoolean CATVizUV3DFace::IsDynamic()
{
  return _isDynamic;
}

inline void CATVizUV3DFace::SetRefinementLevel(unsigned int refinementLevel)
{
  _refinementLevel = refinementLevel;
}

inline unsigned int CATVizUV3DFace::GetRefinementLevel()
{
  return _refinementLevel;
}

#endif
