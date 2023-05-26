// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKRemoveRep.h
// Header definition of CATPolyEKRemoveRep
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKRemoveRep_H
#define CATPolyEKRemoveRep_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKUnstream.h"

class ExportedByPolyEKNodes CATPolyEKRemoveRep : public CATPolyEKUnstream
{
public:
  /** Cast method */
  virtual CATPolyEKRemoveRep * CastToRemoveRep(){return this;}

  /** Constructor */
  CATPolyEKRemoveRep(int setid, int objectid);

protected:
  ~CATPolyEKRemoveRep();
public:
  int m_setid;
  int m_objectid;
};

#endif
