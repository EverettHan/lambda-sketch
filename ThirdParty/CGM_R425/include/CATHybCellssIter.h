/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybCellssIter :
//    Generic Iterator on CATHybCells list
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
//
#ifndef CATHybCellssIter_h
#define CATHybCellssIter_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATCGMNewArray.h"
#include "CATCGMVirtual.h"

//------------------------------------------------------------------------------
class CATHybCells;
class CATHybCellss;

class ExportedByPBELight CATHybCellssIter : public CATCGMVirtual
{
  public:

  CATHybCellssIter(const CATHybCellss& list);
  virtual ~CATHybCellssIter();
   CATCGMNewClassArrayDeclare;

  virtual CATHybCells* Next();

  // Set at beginning
  void Reset();
  // Update current Iter if List has been changed
  void Update();

  int Size();
  int Position();
  
  protected:
  const CATHybCellss& _list;
  CATHybCells*    _body;
  int         _size;
  int         _pos;
}; 
     
#endif

