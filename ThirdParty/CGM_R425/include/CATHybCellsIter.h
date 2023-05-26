/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybCellsIter :
//    Generic Iterator on CATHybCells list
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
//
#ifndef CATHybCellsIter_h
#define CATHybCellsIter_h

//#include "ExportedByCATTopImpl.h"
//#include "ExportedByPBE.h"
#include "ExportedByPBELight.h"

#include "CATCGMNewArray.h"
#include "CATCGMVirtual.h"

//------------------------------------------------------------------------------
class CATHybCell;
class CATHybCells;

class CATHybCellsIter : public CATCGMVirtual
{
  public:
  CATHybCellsIter(const CATHybCells& list);
  virtual ~CATHybCellsIter();
   CATCGMNewClassArrayDeclare;

  // Set at beginning
  void Reset();

  // Update current Iter if List has been changed
  void SetTo(CATHybCell*);

  protected:
  const CATHybCells& _list;
  CATHybCell*        _body;
  int                _size;
  int                _pos;

}; 
     
#endif

