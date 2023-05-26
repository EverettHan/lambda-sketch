/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATPointsIter :
//    Generic Iterator on CATPoints list
//      
//------------------------------------------------------------------------------
// Usage Notes:
//------------------------------------------------------------------------------
// Inheritance:
//------------------------------------------------------------------------------
//
#ifndef CATPointsIter_h
#define CATPointsIter_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
#include "CATPoints.h"
#include "CATCGMVirtual.h"

class ExportedByPBELight CATPointsIter : public CATCGMVirtual
{
  public:
  CATPointsIter(const CATPoints& list);
  CATPointsIter(const CATPoints& list,CATPoint* init);
  
  //virtual CATPoint* Next();

  // Set at beginning
  void Reset();
  // Update current Iter if List has been changed
  void Update();
  void SetTo(CATPoint*);
  CATPoint* Next();
  CATPoint* GetValue(int index);
  CATPoint* First();
  CATPoint* Last();
  
  private:
  CATPoint* GetUnprotectedValue(int index);
  
  protected:
  const CATPoints& _list;
  CATPoint*    _body;
  int         _size;
  int         _pos;
}; 
     
#endif

