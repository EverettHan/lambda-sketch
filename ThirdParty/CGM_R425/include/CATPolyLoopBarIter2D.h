// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyLoopBarIter2D.h
//
//===================================================================
// April 2007 Creation: ndo
//===================================================================
#ifndef CATPolyLoopBarIter2D_H
#define CATPolyLoopBarIter2D_H

#include "PolygonalModel.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyLoop2D;
class CATPolyBar2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;


/**
Iterates through all the pairs (vertex, bar) of a loop of a CATPolyPolygon2D object where 
"vertex" is the start vertex of the bar.
*/
class ExportedByPolygonalModel CATPolyLoopBarIter2D
{

public :

  CATPolyLoopBarIter2D(const CATPolyLoop2D& iLoop);
  CATPolyLoopBarIter2D (const CATPolyLoop2D* iLoop);


  /**
   * Resets the operator at the beginning of a sequence (vertex, bar) for a loop.
   */
  HRESULT Reset (const CATPolyLoop2D* iLoop);

  /**
   * Cycles through the next pair (vertex, bar) of a loop.
   * The vertex is the start vertex of the bar in the direction of the loop.
   * For a loop associated to a full vertex, a vertex without a bar is returned.
   */
  CATPolyBar2D* Next (CATPolyVertex2D*& vertex);

  /**
   * Returns the next bar of a loop.
   */
  inline CATPolyBar2D* Next ();

  /**
   *  Returns the next cobar of a loop
   */
  CATPolyCoBar2D * NextCoBar(CATPolyVertex2D *& vertex);

  inline CATPolyCoBar2D * NextCoBar();

private :

  CATPolyCoBar2D* _CoBar;

};


inline CATPolyBar2D* CATPolyLoopBarIter2D::Next ()
{
  CATPolyVertex2D* vertex = 0;
  return Next (vertex);
}

inline CATPolyCoBar2D * CATPolyLoopBarIter2D::NextCoBar()
{
  CATPolyVertex2D* vertex = 0;
  return NextCoBar (vertex);
}

#endif
