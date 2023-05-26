#ifndef CATVizCurveIterator_H
#define CATVizCurveIterator_H

// Base class
#include "CATVizPrimitiveIterator.h"

#include "CATVizIterators.h"

class CATVizEdgeIterator;

class ExportedByCATVisFoundationIterators CATVizCurveIterator : public CATVizPrimitiveIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizCurveIterator);

public:

   // Visitor Pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // Node information
   enum CATVizLineStyle
   {
      CATVizLines,
      CATVizLineStrip,
      CATVizLineLoop
   };

   enum CATVizCurveType
   {
      CATVizCurveBoundary,
      CATVizCurveInternalSharp = 1,
      CATVizCurveInternalSmooth = 2,
      CATVizCurveWire = 8,
      CATVizCurveV4,
      CATVizCurveUnknown,
   };

   virtual HRESULT GetTopologicalType(CATVizCurveType & oType);
   virtual HRESULT GetLineStyle(CATVizLineStyle & oStyle);

   // Vertices iteration
   typedef void * CATVizCurveContext;
   struct CATVizCurveItem
   {
      const float * position;
      const float * tangent;
   };

   enum CATVizCurveOptions
   {
      FETCH_POSITIONS   = 0x1,
      FETCH_TANGENTS    = 0x2,
      THREAD_SAFE       = 0x4,
   };

   virtual HRESULT StartIteration   (CATVizCurveContext & context, unsigned int options = FETCH_POSITIONS | FETCH_TANGENTS);
   virtual HRESULT GetNext          (CATVizCurveContext context, CATVizCurveItem & oItem);
   virtual HRESULT EndIteration     (CATVizCurveContext context);
};

#endif
