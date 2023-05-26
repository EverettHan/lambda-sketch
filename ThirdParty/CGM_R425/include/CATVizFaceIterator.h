#ifndef CATVizFaceIterator_H
#define CATVizFaceIterator_H

// Base class
#include "CATVizMeshIterator.h"

#include "CATVizIterators.h"

class CATMathPointf;
class CATMathVectorf;

class ExportedByCATVisFoundationIterators CATVizFaceIterator : public CATVizMeshIterator
{
   CATVizDeclareClass;
   CATVizDeclareIterator(CATVizFaceIterator);

public:

   // Visitor Pattern
   virtual void Accept(CATVizIteratorVisitor & iVisitor, void * iReservedData);

   // Planar information
   virtual HRESULT GetPlane(CATMathPointf & oPoint, CATMathVectorf & oNormal);
};

#endif
