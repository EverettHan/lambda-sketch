// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKModifyPosition.h
// Header definition of CATPolyEKModifyPosition
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKModifyPosition_H
#define CATPolyEKModifyPosition_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKUnstream.h"

// Math
class CATMathTransformation;


class ExportedByPolyEKNodes CATPolyEKModifyPosition : public CATPolyEKUnstream
{
public:
  /** Cast method */
  virtual CATPolyEKModifyPosition * CastToModifyPosition(){return this;}

  /** Constructor */
  CATPolyEKModifyPosition(int setid, int objectid, const CATMathTransformation * pPos);

protected:
  ~CATPolyEKModifyPosition();
public:
  int m_setid;
  int m_objectid;
  CATMathTransformation * m_pPos;
};

#endif
