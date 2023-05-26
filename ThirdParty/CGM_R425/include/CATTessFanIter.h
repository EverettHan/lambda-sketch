#ifndef CATTessFanIter_H
#define CATTessFanIter_H


// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "CATDataType.h"
#include "TessAPI.h"
#include "CATCGMNewArray.h"

#include "CATIACGMLevel.h"
#include "CATCGMTessFanIter.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;
/**
 * Class defining the iterator on the fans resulting from a Tessellation operator.
 * <br> Such iterator is directly created by the @href CATBodyTessellator#GetFace
 * or @href CATCellTessellator#GetFace methods. Its deletion is managed at the
 * CATBodyTessellator and CATCellTessellator deletion. 
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
class ExportedByTessAPI CATTessFanIter: public CATCGMTessFanIter
{
public:
  /**
   * @nodoc
	 * Default constructor.
	 */
  CATTessFanIter();
  
  /**
   * Destructor
   */
  virtual ~CATTessFanIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;

   /**
   * Returns the number of fans.
   * @param ioNbPtsAll
   * The sum of the number of points for the definition of all the fans.
   * @return
   * The number of fans.
   */
  inline CATLONG32 GetNbFan( CATLONG32 & ioNbPtsAll ) const;

  
#if defined (CATIACGMV5R17)
  /**
  * FROM CATIA V5R17
  * Returns the number of points of the current fan.
  * @return
  * The number of points of the current fan.
  */
  virtual CATLONG32 GetFanNbPts();
#else
  /**
  * UP TO CATIA V5R17
  * Returns the number of points of the current fan.
  * @return
  * The number of points of the current fan.
  */
  virtual CATLONG32 GetFanNbPts() const;
#endif

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
   /** @nodoc */
  CATTessAssCont * _AssContCurrent;

   /** @nodoc */
  CATLONG32        _NbFan;
  /** @nodoc */
  CATLONG32        _NbPtsAll;
#if defined (CATIACGMV5R17)
  /** @nodoc */
  // Nombre de Point pour le fan courant
  CATLONG32        _NbPts;
#endif
};

 
inline CATLONG32 CATTessFanIter::GetNbFan( CATLONG32 & NbPtsAll ) const
{
  NbPtsAll = _NbPtsAll;
  return _NbFan;
}

#endif

