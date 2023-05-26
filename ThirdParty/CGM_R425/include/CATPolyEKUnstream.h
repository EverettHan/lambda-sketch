// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKUnstream.h
// Header definition of CATPolyEKUnstream
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKUnstream_H
#define CATPolyEKUnstream_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyRefCounted.h"

class CATPolyEKClashContactResult;
class CATPolyEKAddRep;
class CATPolyEKRemoveRep;
class CATPolyEKModifyPosition;

class ExportedByPolyEKNodes CATPolyEKUnstream : public CATPolyRefCounted
{
public:
  /** Cast method */
  virtual CATPolyEKClashContactResult * CastToClashContactResult(){return 0;}
  /** Cast method */
  virtual CATPolyEKAddRep * CastToAddRep(){return 0;}
  /** Cast method */
  virtual CATPolyEKRemoveRep * CastToRemoveRep(){return 0;}
  /** Cast method */
  virtual CATPolyEKModifyPosition * CastToModifyPosition(){return 0;}
protected:
  CATPolyEKUnstream(){}
  ~CATPolyEKUnstream(){}
};

#endif
