#ifndef CATTessDegenFanIter_H
#define CATTessDegenFanIter_H


//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2010
// CATTessDegenFanIter
//
//=============================================================================
//
// Feb. 2010 MPX Creation            
//
//=============================================================================

#include "CATDataType.h"
#include "TessAPI.h"
#include "CATCGMNewArray.h"

#include "CATIACGMLevel.h"
#include "CATCGMTessFanIter.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;
/**
 * Class defining the iterator on the degenerate fans resulting from a Tessellation operator.
 * This class is used only in the context of incremental tessellation
 * <br> Use it according to the following scheme:
 * <ul>
 * <li> Retrieve the number of fans 
 * <li> Go the next result
 * <li> Retrieve the result
 * <li> Optionally, reset to begin again.
 * </ul>
 * <p> If the fan is closed, the first and last point of the fan are different. 
 * <p> This class also allows you to directly retrieve the results in an array that 
 * you have to allocate and deallocate after use.
 */
class ExportedByTessAPI CATTessDegenFanIter: public CATCGMTessFanIter
{
public:
  /**
   * @nodoc
	 * Default constructor.
	 */
  CATTessDegenFanIter();
  
  /**
   * Destructor
   */
  virtual ~CATTessDegenFanIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

   /**
   * Returns the number of fans.
   * @param ioNbPtsAll
   * The sum of the number of points for the definition of all the fans.
   * @return
   * The number of fans.
   */
  CATLONG32 GetNbFan( CATLONG32 & ioNbPtsAll ) const;

  
  /**
  * Returns the number of points of the current fan.
  * @return
  * The number of points of the current fan.
  */
  virtual CATLONG32 GetFanNbPts();

#ifndef PLATEFORME_DS64
  /**
   * Retrieves the points ranks (as CATLONG32) defining the current fan.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetFanNbPts</tt> for its dimension.
   */
  virtual void GetFanNuPts(CATLONG32 iNuPts[]) const;
#endif

   /**
   * Retrieves the points ranks (as int) defining the current fan.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetFanNbPts</tt> for its dimension.
   */
  virtual void GetFanNuPts(int  iNuPts[]) const;
  
   /**
   * Globally retrieves the points ranks for all the fans.
   * @param iNbPts[]
   * The array of number of points for each fan. The allocation has to be managed by
   * the caller: use </tt>GetNbFan</tt> for its dimension.
   * @param iNuPts[]
   * The array of the point ranks. The allocation has to be managed by
   * the caller: use </tt>oNbPtsAll</tt> for its dimension.
   */
  virtual void GetFanAllNuPts(int iNbPts[], int iNuPts[]) const;

  /**
   * Skips to the next fan.
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
  int _CurrFan;
};
 
#endif

