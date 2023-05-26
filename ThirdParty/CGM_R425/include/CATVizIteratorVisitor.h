#ifndef CATVizIteratorVisitor_H
#define CATVizIteratorVisitor_H

#include "CATVizIterators.h"

#include "CATVizMetaClassList.h"

#include "CATVizFaceIterator.h"
#include "CATVizCurveIterator.h"
#include "CATVizPointIterator.h"

class CATRep;
class CATVizSceneGraphIterator;
class CATVizCollectionIterator;
class CATVizBodyIterator;
class CATVizBoundingIterator;
class CATVizEdgeIterator;
class CATVizPrimitiveIterator;
class CATVizGraphicPropertiesIterator;

enum CATVizIteratorRC
{
   CATVizIteratorContinue   = 0,
   CATVizIteratorStopBranch = 1,
   CATVizIteratorStopAll    = 2
};

class ExportedByCATVisFoundationIterators CATVizIteratorVisitor
{
public :

   CATVizIteratorVisitor();
   virtual ~CATVizIteratorVisitor();

   // Launch the visitor pattern on specified rep
   void Visit(CATRep & iRep);
   void StopIteration();

   // Defines a filter list
   void SetFilters(unsigned int iNbFilters, const IID * iFilters);
   void GetFilters(unsigned int & oNbFilters, const IID * & oFilters) const;

   // Push/Pop reference when going down one rank.
   // You MUST return the Visitor that will be used in order to continue the iteration.
   // Default implementation return 'this'
   // Destruction (if needed) must been done on PopReference
   virtual CATVizIteratorVisitor * PushReference();
   virtual void                    PopReference(CATVizIteratorVisitor * iVisitor);

   // Scene Graph node
   virtual CATVizIteratorRC VisitSceneGraph   (CATVizSceneGraphIterator & iSceneGraph, void * & iUserData);
   virtual void             EndVisitSceneGraph(CATVizSceneGraphIterator & iSceneGraph, void *   iUserData);

   // Collection node
   virtual CATVizIteratorRC VisitCollection   (CATVizCollectionIterator & iCollection, void * & iUserData);
   virtual void             EndVisitCollection(CATVizCollectionIterator & iSceneGraph, void *   iUserData);

   // Body node
   virtual CATVizIteratorRC VisitBody         (CATVizBodyIterator & iBody, void * & iUserData);
   virtual void             EndVisitBody      (CATVizBodyIterator & iBody, void *   iUserData);

   // Collection iteration
   virtual void VisitFace      (CATVizFaceIterator       & iFace);
   virtual void VisitMesh      (CATVizMeshIterator       & iMesh);
   virtual void VisitEdge      (CATVizEdgeIterator       & iEdge);
   virtual void VisitCurve     (CATVizCurveIterator      & iCurve);
   virtual void VisitPoint     (CATVizPointIterator      & iPoint);
   virtual void VisitPrimitive (CATVizPrimitiveIterator  & iPrimitive);

   // Body iteration
   virtual const int VisitBodyFace                (CATVizFaceIterator  & iFace);
   virtual const int VisitBodyEdge                (CATVizEdgeIterator  & iEdge);
   virtual const int VisitBodyBoundaryEdge        (CATVizCurveIterator & iCurve);
   virtual const int VisitBodyInternalSharpEdge   (CATVizCurveIterator & iCurve);
   virtual const int VisitBodyInternalSmoothEdge  (CATVizCurveIterator & iCurve);
   virtual const int VisitBodyBoundaryPoint       (CATVizPointIterator & iPoint);
   virtual const int VisitBodyInternalSharpPoint  (CATVizPointIterator & iPoint);
   virtual const int VisitBodyInternalSmoothPoint (CATVizPointIterator & iPoint);
   virtual const int VisitBodySurfacicPoint       (CATVizPointIterator & iPoint);
   virtual const int VisitBodyFreePoint           (CATVizPointIterator & iPoint);
   virtual const int VisitBodyWireEdge            (CATVizCurveIterator & iCurve);

   CATVizGraphicPropertiesIterator * GetCurrentGraphicProperties();

   virtual void VisitTriangle(const CATVizMeshIterator::CATVizMeshItem & triangle);

   inline void       ThreadSafe  (const CATBoolean iOnOff)  { _threadSafety = iOnOff; };
   inline CATBoolean ThreadSafe  () const                   { return _threadSafety; };

   inline void  SetNeededBodySag(const float iNeededSag);
   inline float GetNeededBodySag() const;
   
   inline void       VisitLeafs(const CATBoolean iOnOff);
   inline CATBoolean VisitLeafs() const;

   inline void       VisitSubElements(const CATBoolean iOnOff);
   inline CATBoolean VisitSubElements() const;

   inline void       VisitTriangles(const CATBoolean iOnOff);
   inline CATBoolean VisitTriangles() const;

   inline void       Visit1D  (const CATBoolean iOnOff)  { _visit1D = iOnOff; };
   inline CATBoolean Visit1D  () const                   { return _visit1D; };
   inline void       Visit2D  (const CATBoolean iOnOff) { _visit2D = iOnOff; };
   inline CATBoolean Visit2D  () const                   { return _visit2D; };
   inline void       Visit3D  (const CATBoolean iOnOff) { _visit3D = iOnOff; };
   inline CATBoolean Visit3D  () const                   { return _visit3D; };

protected:

   unsigned int   _stop              : 1;
   unsigned int   _visitLeafs        : 1;
   unsigned int   _visitSubElements  : 1;
   unsigned int   _visitTriangles    : 1;

   unsigned int   _visit1D           : 1;
   unsigned int   _visit2D           : 1;
   unsigned int   _visit3D           : 1;

   unsigned int   _threadSafety      : 1;

   CATVizGraphicPropertiesIterator * _currentProperties;
   
   unsigned int   _nbFilters;
   IID *          _filters;
   
   float          _bodySag;
};

inline void CATVizIteratorVisitor::SetNeededBodySag(const float iNeededSag)
{
   _bodySag = iNeededSag;
}

inline float CATVizIteratorVisitor::GetNeededBodySag() const
{
   return _bodySag;
}

inline void CATVizIteratorVisitor::VisitLeafs(const CATBoolean iOnOff)
{
   _visitLeafs = iOnOff;
}

inline CATBoolean CATVizIteratorVisitor::VisitLeafs() const
{
   return _visitLeafs;
}

inline void CATVizIteratorVisitor::VisitSubElements(const CATBoolean iOnOff)
{
   _visitSubElements = iOnOff;
}

inline CATBoolean CATVizIteratorVisitor::VisitSubElements() const
{
   return _visitSubElements;
}

inline void CATVizIteratorVisitor::VisitTriangles(const CATBoolean iOnOff)
{
   _visitTriangles = iOnOff;
}

inline CATBoolean CATVizIteratorVisitor::VisitTriangles() const
{
   return _visitTriangles;
}

#endif
