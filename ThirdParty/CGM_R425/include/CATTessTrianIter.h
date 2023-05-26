#ifndef CATTessTrianIter_H
#define CATTessTrianIter_H


// COPYRIGHT DASSAULT SYSTEMES  1999

/**
 * @level Protected
 * @usage U1
 */ 

#include "TessAPI.h"

// On ne peut pas inclure "CATTessDebug.h" car il est dans ProtectedInterface
//#define MNATriangPP2D

#include "CATCGMNewArray.h"
#include "CATDataType.h"
#include "CATCGMTessTrianIter.h"

class CATTessFace;
class CATTessAssCont;
class CATTessContour;

/**
 * Class defining the iterator on the triangles resulting from a Tessellation operator.
 * <br> Such iterator is directly created by the @href CATBodyTessellator#GetFace
 * or @href CATCellTessellator#GetFace methods. Its deletion is managed at the
 * CATBodyTessellator and CATCellTessellator deletion. 
 * <br> Use it according to the following scheme:
 * <ul>
 * <li> Retrieve the number of triangles 
 * <li> Go the next result
 * <li> Retrieve the result
 * <li> Optionally, reset to begin again.
 * </ul>
 * <p> This class also allows you to directly retrieve the results in an array that 
 * you have to allocate and deallocate after use.
 */
class ExportedByTessAPI CATTessTrianIter: public CATCGMTessTrianIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATTessTrianIter();

  /**
   * Destructor
   */
  virtual ~CATTessTrianIter();

  /** @nodoc */
  CATCGMNewClassArrayDeclare;
  
  /**
   * Returns the number of triangles.
   * @return
   * The number of triangles.
   */
  inline CATLONG32 GetNbTrian() const;

#ifndef PLATEFORME_DS64
  /**
   * Retrieves the points ranks (as CATLONG32) defining the current triangle.
   * @param iNuPts
   * The array [3] allocated by the caller.
   */
  virtual void GetTrianNuPts(CATLONG32 iNuPts[3]) const;
#endif

   /**
   * Retrieves the points ranks (as int) defining the current triangle.
   * @param iNuPts
   * The array [3] allocated by the caller.
   */
  virtual void GetTrianNuPts(int  iNuPts[3]) const;

  /**
   * Globally retrieves the points ranks for all the triangles.
   * @param ioNuPts[][3]
   * The array of the point numbers. The allocation has to be managed by
   * the caller:  its dimension: <tt>3* (strip->GetNbTrian())</tt>.
   */
  virtual void GetTrianAllNuPts(int iNuPts[][3]) const;

   /**
   * Skips to the next triangle.
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
  CATLONG32        _NbTrian;
#ifdef MNATriangPP2D
  CATLONG32        _NbTrianCurrent;
  CATLONG32        _IdxTriPP2DCurrent;
#endif

};
 
inline CATLONG32 CATTessTrianIter::GetNbTrian() const
{
  return _NbTrian;
}

#endif
