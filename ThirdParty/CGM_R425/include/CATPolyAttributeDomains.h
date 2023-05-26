// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAttributeDomains.h
// Header definition of CATPolyAttributeDomains
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// January 2006 Creation: ndo
//===================================================================
#ifndef CATPolyAttributeDomains_H
#define CATPolyAttributeDomains_H

#include "CATPolyAnalyzeOperators.h"
#include "CATErrorDef.h"  // Definition of HRESULT.
#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATMapOfIntToInt.h"
#include "CATPolyRefCounted.h"


/*
Implementation class for domain attributes. 
*/
class ExportedByCATPolyAnalyzeOperators CATPolyAttributeDomains : public CATPolyRefCounted
{

public :

  CATPolyAttributeDomains (int) {}

  ~CATPolyAttributeDomains ();

  /**
   * Adds a new domain and return its domain index.
   */
  int AddDomain ();

  /**
   * Adds a triangle into a domain.
   */
  HRESULT AddTriangleIntoDomain (const int iTriangle, const int iDomain);

  /**
   * Returns the number of domains.  The domains are numbered from 1 to the number of domains.
   */
  int GetNbDomains () const;

  /**
   * Returns the list of triangle indices composing the ith domain.
   * @param iDomain
   *   The domain index between 1 and GetNbDomains () inclusive.
   * @return 
   *   A list of triangles indices in the ith domain.
   */
  const CATListOfInt& GetTrianglesFromDomain (const int iDomain) const;

  /**
   * Given a triangle index, returns the index of the domain the triangle belongs to.
   * @param iDomain
   *   The index of the domain.
   * @return
   *   The index of the domain (between 1 and GetNbDomains () inclusive) or 0 if the 
   *   triangle is invalid and does not belong to any domain.
   */
  int GetDomainFromTriangle (const int iTriangle) const;

  /**
   * Clears all the attributes and the domains.
   */
  void Clear ();

private:

  CATListPV _Domains;
  CATMapOfIntToInt _MapTriangleToDomain;

private:

  void MapTriangleToDomain (const int iTriangle, const int iDomain);

};

#endif
