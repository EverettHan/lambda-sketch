/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// CATHybEdgesIter :
//    Iterator on CATHybEdges list
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: CATHybCellsIter
//------------------------------------------------------------------------------
//
#ifndef CATHybEdgesIter_h
#define CATHybEdgesIter_h

//#include "ExportedByCATTopImpl.h"
//#include "ExportedByPBE.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybCellsIter.h"

class CATHybEdge;
class CATHybCells;

class CATHybEdgesIter : public CATHybCellsIter
{
public:

  CATHybEdgesIter(const CATHybCells& list);
  ~CATHybEdgesIter();
  CATCGMNewClassArrayDeclare;
  
  CATHybEdge* Next();

private:

  CATHybEdge* GetUnprotectedValue(int index);

}; 
     
#endif
