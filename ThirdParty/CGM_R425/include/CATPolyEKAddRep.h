// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKAddRep.h
// Header definition of CATPolyEKAddRep
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKAddRep_H
#define CATPolyEKAddRep_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKUnstream.h"
#include "CATBVHTreeRepBuilder.h"

// Visu
class CAT3DRep;

// Math
class CATMathTransformation;


class ExportedByPolyEKNodes CATPolyEKAddRep : public CATPolyEKUnstream
{
public:
  /** Cast method */
  virtual CATPolyEKAddRep * CastToAddRep(){return this;}

  /** Takes ownership of the rep */
  CATPolyEKAddRep(int setid, int objectid, CAT3DRep * object, const CATMathTransformation * pPos, CATBVHTreeRepBuilder::EntityType entitytypes);

protected:
  ~CATPolyEKAddRep();
public:
  int m_setid;
  int m_objectid;
  CAT3DRep * m_object;
  CATMathTransformation * m_pPos;
  CATBVHTreeRepBuilder::EntityType m_entitytypes;
};

#endif
