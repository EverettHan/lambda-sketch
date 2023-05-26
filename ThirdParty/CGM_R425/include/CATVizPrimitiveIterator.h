#ifndef CATVizPrimitiveIterator_H
#define CATVizPrimitiveIterator_H

// Base class
#include "CATVizIterator.h"

#include "CATVizIterators.h"

class CATVizIteratorVisitor;
class CATVizMeasurableIterator;
class CATVizMetaClass;
class CATMathPointf;
class CATMathVectorf;

class ExportedByCATVisFoundationIterators CATVizPrimitiveIterator : public CATVizIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizPrimitiveIterator);

public:

   // Visitor pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // If measurement data available, returns an iterator on available data
   virtual CATVizMeasurableIterator * GetMeasurableIterator();

   // PlaneSupport
   virtual HRESULT IsOnPlaneSupport(const CATMathPointf & iPoint, const CATMathVectorf & iNormal);

};

#endif
