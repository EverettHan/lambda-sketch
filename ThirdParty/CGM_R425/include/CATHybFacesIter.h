/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybFacesIter :
//    Iterator on CATHybFaces list
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance: CATHybCellsIter
//------------------------------------------------------------------------------
//
#ifndef CATHybFacesIter_h
#define CATHybFacesIter_h

//#include "ExportedByCATTopImpl.h"
//#include "ExportedByPBE.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATHybCellsIter.h"

class CATHybFace;
class CATHybCells;

class CATHybFacesIter : public CATHybCellsIter
{
  public:
  CATHybFacesIter(const CATHybCells& list);
  ~CATHybFacesIter();
  CATCGMNewClassArrayDeclare;
  
  CATHybFace* Next();

  private:
  CATHybFace* GetUnprotectedValue(int index);
}; 
     
#endif
