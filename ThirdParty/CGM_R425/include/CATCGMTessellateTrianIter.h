#ifndef CATCGMTessellateTrianIter_H
#define CATCGMTessellateTrianIter_H

#include "ExportedByTessellateCommon.h"
#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class ExportedByTessellateCommon CATCGMTessellateTrianIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATCGMTessellateTrianIter();

  /**
   * @nodoc
   * Destructor.
   */
  virtual ~CATCGMTessellateTrianIter();

public:

  ///////////////////////////////////////////////
  // Best Performance methods
  ///////////////////////////////////////////////

  /**
   * Returns the number of triangles.
   * @return
   * The number of triangles.
   */
  virtual CATULONG32 GetNbTrian() const = 0;

  /**
   * Returns TRUE if the triangles orientation is aligned with the CATFace
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>1</tt> if the triangles orientation is aligned with the CATFace, <tt>0</tt> otherwise.
   */
  virtual CATBoolean AreTrianglesAlignedWithFace() const = 0;

  /**
   * Globally retrieves the points ranks for all the triangles.
   * @param ioNuPts[][3]
   * The array of the point numbers. The allocation has to be managed by
   * the caller:  its dimension: <tt>3* (strip->GetNbTrian())</tt>.
   */
  virtual HRESULT GetTrianAllNuPts(CATULONG32 iNuPts[][3]) const = 0;


  ///////////////////////////////////////////////
  // Low Performance methods
  ///////////////////////////////////////////////

   /**
   * Retrieves the points ranks (as int) defining the current triangle.
   * @param iNuPts
   * The array [3] allocated by the caller.
   */
  virtual HRESULT GetTrianNuPts(CATULONG32 iNuPts[3]) const = 0;

   /**
   * Skips to the next triangle.
   */
  virtual void GoToNext() = 0;

  /**
   * Resets the iterator to the beginning.
   */
  virtual void Reset() = 0;

  /**
   * Tests whether the list is completed.
   * @return
   * The result of the test.
   * <br><b>Legal values</b>: <tt>1</tt> if the list is completed, <tt>0</tt> otherwise.
   */
  virtual CATBoolean IsExhausted() const = 0;
};

#endif
