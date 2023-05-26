//============================================================================================
// Copyright Dassault Systemes 2021, All Rights Reserved
//============================================================================================
//
// CATPolyPolygonShuffleOper2D.h
//
//============================================================================================
//
// Usage notes : Operator to copy and shuffle a polygon inside an
//               existing one.  Inspired by CATPolyCloneOper2D, which
//               has inspired CATPolyCopyOper2D as well, but this
//               latter uses deprecated interfaces and actually
//               doesn't work. I know, it's bad to duplicate code, but
//               I needed to shuffle a polygon and I saw no other
//               solution. (Shrugging...)
//               And yes, it is for tests, but in code
//               framework... But it has to know about
//               CATPolyVertex/Bar/Face2D, which are only privately
//               available in this framework.
//
//============================================================================================
// 2021 : XXC : It's not plagiarism. I cited the original artwork!
//============================================================================================
#ifndef CATPolyPolygonShuffleOper2D_H
#define CATPolyPolygonShuffleOper2D_H

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.

class CATPolyPolygon2D;
class CATPolyVertex2D;
class CATPolyBar2D;
class CATPolyLoop2D;
class CATPolyFace2D;

/**
 This operator clones a CATPolyPolygon2D object.
*/
class ExportedByPolygonalOperators CATPolyPolygonShuffleOper2D
{

public:

  /**
   * Observer to catch mapping events between an entity from the input polygon
   * to an entity from the output polygon.
   */
  class ExportedByPolygonalOperators Observer
  {
  public:

    virtual void Map (const CATPolyVertex2D* iVertex, const CATPolyVertex2D* oVertex) {}

    virtual void Map (const CATPolyBar2D* iBar, const CATPolyBar2D* oBar) {}

    virtual void Map (const CATPolyLoop2D* iLoop, const CATPolyLoop2D* oLoop) {}

    virtual void Map (const CATPolyFace2D* iFace, const CATPolyFace2D* oFace) {}

  };

public:

  CATPolyPolygonShuffleOper2D () {}

  ~CATPolyPolygonShuffleOper2D () {}

  /*
   * Copies an input polygon "iPolygon" into the another polygon: "oPolygon".
   * @param obs
   *   An optional observer to catch the mapping events.
   */
static HRESULT Run (const CATPolyPolygon2D& iPolygon, CATPolyPolygon2D& oPolygon, unsigned int iSeed = 0, Observer* obs = 0);

};

#endif
