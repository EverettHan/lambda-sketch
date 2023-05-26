#ifndef CATVizPointIterator_H
#define CATVizPointIterator_H

// Base class
#include "CATVizPrimitiveIterator.h"

#include "CATVizIterators.h"

class ExportedByCATVisFoundationIterators CATVizPointIterator : public CATVizPrimitiveIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizPointIterator);

public:

   // Visitor Pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // Node information
   virtual unsigned int    GetNbPoints();
   virtual float const*    GetVertex(unsigned int iIndex);
};

#endif
