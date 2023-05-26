/* -*-C++-*-*/
#ifndef CATTessPolyVertexIter_H
#define CATTessPolyVertexIter_H


// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"
#include "CATTessVertexIter.h"

#include "CATFace.h"
#include "CATCGMNewArray.h"

#include "CATThrowForNullPointer.h"
#include "CATCGMTessVertexIter.h"

class CATTessPoint;
class CATTessVertex;

class CATMacroPoint;
class CATPointOnEdgeCurve;

/**
 * Class that outputs the point tessellation numbers corresponding to the
 * the points on a given vertex.
 * <br>The points are given relatively to one bounded (or adjacent) face.
 * <br> Such class is directly created by the @href CATBodyTessellator#GetVertex method. 
 * Its deletion is managed at the
 * CATBodyTessellator deletion. 
 * <br> Use it according to the following scheme:
 * <ul> 
 * <li> Retrieve the number of points for a given vertex, with regards to a given face. 
 * <li> Allocate the array of numbers
 * <li> Retrieve the result
 * <li> Delete the array.
 * </ul>
 */
class ExportedByTessAPI CATTessPolyVertexIter: public CATTessVertexIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATTessPolyVertexIter();

  /**
   * Destructor
   */
  virtual ~CATTessPolyVertexIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  /**
   * Returns the number of faces.
   * @return
   * The number of faces.
   */
  inline CATLONG32 GetNbFace() const;

  /**
   * Returns the pointer to the current face.
   * @return
   * The pointer to the current face.
   */
  CATFace * GetFace() const;

  /**
   * Returns the pointer to a PointOnEdgeCurve for the current face.
   * @return
   * The pointer to the corresponding PointOnEdgeCurve.
   */
  inline CATPointOnEdgeCurve * GetPoec() const;

  /**
   * Retrieves the points ranks (as int) defining the current face.
   * @param oNuPts
   * The point ranks.
   */
  virtual void GetVertexNuPts(int & oNuPts) const;
  
   /**
   * Globally retrieves the points ranks for all the faces.
   * @param oNuPts[]
   * The array of the point numbers. The allocation has to be managed by
   * the caller: use </tt>GetNbFace()</tt> for its dimension.
   */
  virtual void GetVertexAllNuPts(int oNuPts[]) const;

  /**
   * Returns the Cartesian coordinates of the current point.
   * @return
   * The array of the Cartesian coordinates.
   */
  virtual double const * GetVertexXyz() const;

  /**
   * Skips to the next face.
   */
  virtual void GoToNext();

  /**
   * Resets the iterator to the beginning.
   */
  virtual void Reset();

  /**
   * Tests whether the list is completed.
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>1</tt> if the list is completed, <tt>0</tt> otherwise.
   */
  virtual CATLONG32 IsExhausted() const;

  /** 
   * @nodoc 
   * Initializes the iterator for one vertex.
   */
  virtual void Initialize(CATTessVertex *  iVertex,
			  CATLONG32        iOutFace);

protected:
  
};

//=============================================================================
// INLINE IMPLEMENTATIONS 
//=============================================================================
inline CATLONG32 CATTessPolyVertexIter::GetNbFace() const
{
  return _NbFace;
}

inline CATPointOnEdgeCurve * CATTessPolyVertexIter::GetPoec() const
{
  return _Poec;
}
#endif
