#ifndef CATCGMTessellateFaceEdgeIter_H
#define CATCGMTessellateFaceEdgeIter_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATEdge;

class ExportedByTessellateCommon CATCGMTessellateFaceEdgeIter
{
public:
  /**
   * @nodoc
   * Default constructor.
   */
  CATCGMTessellateFaceEdgeIter();

  /**
   * @nodoc
   * Destructor.
   */
  virtual ~CATCGMTessellateFaceEdgeIter();

  /**
   * Returns the number of tesselation points for the edge relative to the face.
   * @return
   * The number of tessellation points for the edge relative the face.
   */
  virtual CATULONG32 GetEdgeNbPts() const = 0;

  /**
   * Returns the number of tesselation points for the edge relative to the face.
   * @return
   * The number of tessellation points for the edge relative the face.
   */
  virtual CATEdge* GetEdge() const = 0;

  /**
   * Returns the tessellation point numbers for the edge relative to the face.
   * The sequence of points is along the edge direction.
   * @param ioNuPts
   * The array of the tessellation point numbers. This array must be allocated and deallocated
   * by the caller. Its dimension is given by the @href CATCGMTessellateFaceEdgeIter#GetEdgeNbPts method.
   */
  virtual HRESULT GetEdgeNuPts(CATULONG32 ioNuPts[]) const = 0;

  /**
   * Returns the tessellation point parameters for the edge relative to the face.
   * The sequence of points is along the edge direction.
   * @param ioCrvParam
   * The array of the tessellation point parameters (as a CATCrvParam on the underlying edge curve)
   * The array must be allocated and deallocated by the caller. 
   * Its dimension is given by the @href CATCGMTessellateFaceEdgeIter#GetEdgeNbPts method.
   */
  virtual HRESULT GetEdgeW(double ioCrvParam[]) const = 0;

   /**
   * Skips to the next edge.
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
