#ifndef CATTessPointIter_H
#define CATTessPointIter_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"

#include "CATMathDef.h"
#include "CATMathVector.h"
#include "CATCGMNewArray.h"
#include "CATCGMTessPointIter.h"

class CATTessFace;
class CATTessPoint;
/**
 * Class defining the iterator on the points resulting from a Tessellation operator.
 * <br> Such iterator is directly created by the @href CATBodyTessellator#GetFace
 * or @href CATCellTessellator#GetFace methods. Its deletion is managed at the
 * CATBodyTessellator and CATCellTessellator deletion. 
 * Use it according to the following scheme:
 * <ul>
 * <li> Retrieve the number of points 
 * <li> Go the next result
 * <li> Retrieve the result
 * <li> Optionally, reset to begin again.
 * </ul>
 * <p> This class also allows you to directly retrieve the results in an array that 
 * you have to allocate and deallocate after use.
 */
class ExportedByTessAPI CATTessPointIter: public CATCGMTessPointIter
{
public:
  /**
   * @nodoc
	 * Default constructor.
	 */
  CATTessPointIter();

  /**
   * Destructor
   */
  virtual ~CATTessPointIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  /**
   * Returns the number of computed points.
	 * @return
	 * The number of computed points.
   */
  inline CATLONG32 GetNbPoint() const;

  /**
  * Returns the rank of the current point.
	 * @return
     * The rank of the current point.
  */
  virtual CATLONG32 GetPointNu() const;
  
  /**
   * Returns the Cartesian coordinates of the current point.
	 * @return
	 * The array of the Cartesian coordinates.
   */
  virtual double const * GetPointXyz() const;
  
  /**
   * Globally retrieves the Cartesian coordinates of all the points.
   * @param iCoordinates[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
   */
  virtual void GetPointXyzAll(float iCoordinates[][3]) const;

   /**
   * Retrieves a pointer to the normal at the current point.
	 * @param oNor
	 * The pointer to the normal.
   */
  virtual CATBoolean GetPointNor(CATMathVector const *& oNor);
 
  /**
   * Globally retrieves the normal at each point.
   * @param iNormals[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
   */
  virtual void GetPointNorAll(float iNormals[][3]) const;
  
   /**
   * Returns the parameters of the current point (in case of a face or a surface).
	 * @return
	 * The array of parameters.
   */
  virtual double const * GetPointUv() const;

   /**
   * Globally retrieves the parameters of all the points (in case of a face or a surface).
   * @param iUv[][2]
   * The array of the parameters. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
   */
  virtual void GetPointUvAll(float iUv[][2]) const;
 
   /**
   * Skips to the next point.
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
   * Internal Use.
   */
  virtual void Initialize(CATTessFace * iFace);

  /**
   * @nodoc
   * Internal use.
   */
  inline CATTessFace * GetTessFace();

  
protected:
  /** @nodoc */
  CATTessFace  * _Face;
  /** @nodoc */
  CATTessPoint * _PointCurrent;

  /** @nodoc */
  CATLONG32      _NbPoint;
};


inline CATLONG32 CATTessPointIter::GetNbPoint() const
{
  return _NbPoint;
}

inline CATTessFace * CATTessPointIter::GetTessFace()
{
  return _Face;
}

  
#endif
