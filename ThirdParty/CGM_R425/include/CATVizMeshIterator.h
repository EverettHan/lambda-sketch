#ifndef CATVizMeshIterator_H
#define CATVizMeshIterator_H

// Base class
#include "CATVizPrimitiveIterator.h"

#include "CATVizIterators.h"

class CATVizMeshData;
class CAT3DBoundingSphere;

class ExportedByCATVisFoundationIterators CATVizMeshIterator : public CATVizPrimitiveIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizMeshIterator);

public:

   // Visitor pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // Node data
   virtual HRESULT GetBoundingSphere(CAT3DBoundingSphere & oBS);
   virtual HRESULT GetBoundingBox   (float oCenter[3], float oHalfSizes[3]);

   virtual HRESULT ComputeBoundingSphere(CAT3DBoundingSphere & oBS);
   virtual HRESULT ComputeBoundingBox   (float oCenter[3], float oHalfSizes[3]);

   /////////////////////////
   // Triangles iteration //
   /////////////////////////
   // Sample use :
   //
   // CATVizMeshIterator::CATVizMeshContext context;
   // if(SUCCEEDED(iterator->StartIteration(context)))
   // {
   //    CATVizMeshIterator::CATVizMeshItem item;
   //    while(SUCCEEDED(iterator->GetNext(context, item)))
   //    {
   //       Do something with the returned triangle
   //    }
   //    iterator->EndIteration(context);
   // }
   //

   typedef void * CATVizMeshContext;
   struct CATVizMeshItem
   {
      const float * p1;
      const float * p2;
      const float * p3;
      
      const float * n1;
      const float * n2;
      const float * n3;
   };

   enum CATVizMeshOptions
   {
      FETCH_POSITIONS   = 0x1,
      FETCH_NORMALS     = 0x2,
      THREAD_SAFE       = 0x4,
   };

   virtual HRESULT StartIteration   (CATVizMeshContext & context, unsigned int options = FETCH_POSITIONS | FETCH_NORMALS);
   virtual HRESULT GetNext          (CATVizMeshContext context, CATVizMeshItem & oItem);
   virtual HRESULT EndIteration     (CATVizMeshContext context);

   // Retrieves a data structure containing a copy of all data that can be pointed
   // by the user for an undefined time.
   virtual CATVizMeshData * GetPrivateCopy(); 

};

#endif
