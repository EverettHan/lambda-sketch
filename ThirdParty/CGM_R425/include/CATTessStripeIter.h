#ifndef CATTessStripeIter_H
#define CATTessStripeIter_H


// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"

#include "CATCGMNewArray.h"
#include "CATDataType.h"

#include "CATIACGMLevel.h"
#include "CATCGMTessStripeIter.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;
/**
 * Class defining the iterator on the strips resulting from a Tessellation operator.
 * <br> Such iterator is directly created by the @href CATBodyTessellator#GetFace
 * or @href CATCellTessellator#GetFace methods. Its deletion is managed at the
 * CATBodyTessellator and CATCellTessellator deletion. 
 * <br> Use it according to the following scheme:
 * <ul>
 * <li> Retrieve the number of strips 
 * <li> Go the next result
 * <li> Retrieve the result
 * <li> Optionally, reset to begin again.
 * </ul>
 * <p> If the strip is closed, the first and last point of the strip are different. 
 * <p> This class also allows you to directly retrieve the results in an array that 
 * you have to allocate and deallocate after use.
 */
class ExportedByTessAPI CATTessStripeIter: public CATCGMTessStripeIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATTessStripeIter();
  
#ifdef CATIACGMV5R20
  /**
   * Destructor
   */
  virtual ~CATTessStripeIter();
#endif
  /** @nodoc */
  CATCGMNewClassArrayDeclare;

  /**
   * Returns the number of strips.
   * @param ioNbPtsAll
   * The sum of the number of points for the definition of all the strips.
   * @return
   * The number of strips.
   */
  inline CATLONG32 GetNbStri( CATLONG32 & ioNbPtsAll ) const;

 
#if defined (CATIACGMV5R17)
   /**
   * FROM CATIA V5R17
   * Returns the number of points of the current strip.
   * @return
   * The number of points of the current strip.
   */
  virtual CATLONG32 GetStriNbPts();
#else
   /**
   * UP TO CATIA V5R17
   * Returns the number of points of the current strip.
   * @return
   * The number of points of the current strip.
   */
  virtual CATLONG32 GetStriNbPts() const;
#endif

#ifndef PLATEFORME_DS64
  /**
   * Retrieves the points ranks (as CATLONG32) defining the current strip.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetStriNbPts</tt> for its dimension.
   */
  virtual void GetStriNuPts(CATLONG32 iNuPts[]) const;
#endif

  /**
   * Retrieves the points ranks (as int) defining the current strip.
   * @param iNuPts[] 
   * The array of the points ranks. The allocation has to be managed by
   * the caller: use </tt>GetStriNbPts</tt> for its dimension.
   */
  virtual void GetStriNuPts(int  iNuPts[]) const;
 
  /**
   * Globally retrieves the points ranks for all the strips.
   * @param iNbPts[]
   * The array of number of points for each strip. The allocation has to be managed by
   * the caller: use </tt>GetNbStri</tt> for its dimension.
   * @param iNuPts[]
   * The array of the point ranks. The allocation has to be managed by
   * the caller: use </tt>oNbPtsAll</tt> for its dimension.
   */
  virtual void GetStriAllNuPts(int iNbPts[], int iNuPts[]) const;

  /**
   * Skips to the next strip.
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
  CATLONG32        _NbStri;
  /** @nodoc */
  CATLONG32        _NbPtsAll;
#if defined (CATIACGMV5R17)
  /** @nodoc */
  // Nombre de Point pour le Stripe courant
  CATLONG32        _NbPts;
#endif
};
 
inline CATLONG32 CATTessStripeIter::GetNbStri( CATLONG32 & NbPtsAll ) const
{
  NbPtsAll = _NbPtsAll;
  return _NbStri;
}

#endif
