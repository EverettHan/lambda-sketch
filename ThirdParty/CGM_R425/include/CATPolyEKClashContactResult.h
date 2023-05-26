// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKClashContactResult.h
// Header definition of CATPolyEKClashContactResult
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKClashContactResult_H
#define CATPolyEKClashContactResult_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATPolyEKUnstream.h"
class CATPolyInterferenceList;

class ExportedByPolyEKNodes CATPolyEKClashContactResult : public CATPolyEKUnstream
{
public:
  /** Returns the result of a clash. Release list after use. */
  CATPolyInterferenceList * GetResult();

  /** Cast method */
  virtual CATPolyEKClashContactResult * CastToClashContactResult(){return this;}

  /** Takes ownership of the list */
  CATPolyEKClashContactResult(CATPolyInterferenceList * pList);

protected:
  ~CATPolyEKClashContactResult();
private:
  CATPolyInterferenceList * m_pList;
};

#endif
