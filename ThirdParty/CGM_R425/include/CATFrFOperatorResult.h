#ifndef CATFrFOperatorResult_H
#define CATFrFOperatorResult_H

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "FrFOpeUtil.h"
#include "CATCGMVirtual.h"

class ExportedByFrFOpeUtil CATFrFOperatorResult : public CATCGMVirtual
{
 protected:
   CATFrFOperatorResult * _Next;
 public:
//
//- Constructor
//
   CATFrFOperatorResult(CATFrFOperatorResult * ptr=0);
//
//- Methods
//
   virtual CATFrFOperatorResult * GetNext() const;
   virtual void                   SetNext(CATFrFOperatorResult * iNext);
};

#endif
