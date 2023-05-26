// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyArcPolygon2DTessellator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// October 2012  Creation: jxo
//===================================================================
#ifndef CATPolyArcPolygon2DTessellator_h
#define CATPolyArcPolygon2DTessellator_h

// ExportedBy
#include "PolygonalOperators.h"

// Poly
class CATPolyArcPolygon2D;
class CATPolyPolygon2D;

// System
#include "CATErrorDef.h"  // HRESULT

/**
* A streaming utility to dump arc polygons
*/
class ExportedByPolygonalOperators CATPolyArcPolygon2DTessellator
{

public :

  CATPolyArcPolygon2DTessellator();
  ~CATPolyArcPolygon2DTessellator();

public:

  /**
   * Tessellates arc polygon into a new CATPolyPolygon2D
   * @param iPoly
   *        Input CATPolyArcPolygon2D to be tessellated
   * @param oPoly
   *        To be deleted by caller.
   */
  static HRESULT Tessellate(const CATPolyArcPolygon2D & iPoly, CATPolyPolygon2D* & oPoly, double sag);

};

#endif

