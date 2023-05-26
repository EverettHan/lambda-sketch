#ifndef CATTessPolyIter_H
#define CATTessPolyIter_H

// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATDataType.h"
#include "TessAPI.h"
#include "CATCGMNewArray.h"
#include "CATCGMTessPolyIter.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;

/**
 * Class defining the iterator on the polygons resulting from a Tessellation operator.
 * <br> Such iterator is directly created by the @href CATBodyTessellator#GetFace
 * or @href CATCellTessellator#GetFace methods. Its deletion is managed at the
 * CATBodyTessellator and CATCellTessellator deletion. 
 * <br> Use it according to the following scheme:
 * <ul>
 * <li> Retrieve the number of polygons 
 * <li> Go the next result
 * <li> Retrieve the result
 * <li> Optionally, reset to begin again.
 * </ul>
 * <p> If the polygon is closed, the first and last point of the polygon are different. 
 * <p> This class also allows you to directly retrieve the results in an array that 
 * you have to allocate and deallocate after use.
 */
class ExportedByTessAPI CATTessPolyIter: public CATCGMTessPolyIter
{
public:

  /**
   * @nodoc
	 * Default constructor.
	 */
  CATTessPolyIter();

  /**
   * Destructor
   */
  virtual ~CATTessPolyIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
 /**
   * Returns the number of polygons.
   * @param ioNbPtsAll
   * The sum of the number of points for the definition of all the polygons.
   * @return
   * The number of polygons.
   */
  //inline CATLONG32 GetNbPoly( CATLONG32 & ioNbPtsAll ) const;
  virtual CATLONG32 GetNbPoly( CATLONG32 & ioNbPtsAll ) const;

  
  /**
  * Returns the number of points of the current polygon.
  * @return
  * The number of points.
  */
  virtual CATLONG32 GetPolyNbPts() const;
   
#ifndef PLATEFORME_DS64
  /**
   * Retrieves the points ranks (as CATLONG32) defining the current polygon.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetPolyNbPts</tt> for its dimension.
   */
  virtual void GetPolyNuPts(CATLONG32 iNuPts[]) const;
#endif
  
  /**
   * Retrieves the points ranks (as int) defining the current polygon.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetPolyNbPts</tt> for its dimension.
   */
  virtual void GetPolyNuPts(int  oNuPts[]) const;

   /**
   * Globally retrieves the points ranks for all the polygons.
   * @param ioNbPts[]
   * The array of the number of points for each polygon. The allocation has to be managed by
   * the caller: use </tt>GetNbPoly</tt> for its dimension.
   * @param oNuPts[]
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>oNbPtsAll</tt> for its dimension.
   */
  virtual void GetPolyAllNuPts(int oNbPts[], int oNuPts[]) const;

   /**
   * Skips to the next polygon.
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
   * Internal use.
   */
  virtual void Initialize(CATTessFace * iFace);

 protected:
  /** @nodoc */ 
  CATTessFace    * _Face;
   /** @nodoc */
  CATTessAssCont * _AssContCurrent;
   /** @nodoc */
  CATTessContour * _ContourCurrent;

   /** @nodoc */
  CATLONG32        _NbPoly;
   /** @nodoc */
  CATLONG32        _NbPtsAll;
  
};

/*
inline CATLONG32 CATTessPolyIter::GetNbPoly( CATLONG32 & NbPtsAll ) const
{
  NbPtsAll = _NbPtsAll;
  return _NbPoly;
}
*/

#endif




