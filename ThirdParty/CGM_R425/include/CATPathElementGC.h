#ifndef CATPathElementGC_h
#define CATPathElementGC_h

// COPYRIGHT DASSAULT SYSTEMES 2002-2008

#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATListOfCATString.h"
#include "CATBoolean.h"

class CATPathElement;

#include "CATVisItf.h"
class ExportedByCATVisItf CATPathElementGC
{

public:

  CATPathElementGC ();
  ~CATPathElementGC ();
  
  void Add (CATPathElement * iPathElement, int iIndex);
  void Remove (CATPathElement * iPathElement);
  static int AddComment (CATPathElement * iPathElement, const CATString & iComment);
    
private:

  CATBoolean _isActive;
  CATListPV _pathElementList;
  CATListOfInt _indexList;
  CATListOfCATString _commentList;

};

#endif
