//============================================================================================
// Copyright Dassault Systemes Provence 2016, All Rights Reserved
//============================================================================================
//
// CATPolyCopyOper2D.h
//
//============================================================================================
//
// Usage notes : Operator to copy a polygon inside an existing one.
//               Inspired by CATPolyCloneOper2D
//
//============================================================================================
// 18.11.2016 : RAQ : Creation
//============================================================================================
#ifndef CATPolyCopyOper2D_H
#define CATPolyCopyOper2D_H

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
class ExportedByPolygonalOperators CATPolyCopyOper2D
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

  CATPolyCopyOper2D () {}

  ~CATPolyCopyOper2D () {}

  /*
   * Copies an input polygon "iPolygon" into the another polygon: "oPolygon".
   * @param obs
   *   An optional observer to catch the mapping events.
   */
  static HRESULT Run (const CATPolyPolygon2D& iPolygon, CATPolyPolygon2D& oPolygon, Observer* obs = 0);

};

#endif
