#ifndef CATCGMTessellatePointIter_H
#define CATCGMTessellatePointIter_H

#include "ExportedByTessellateCommon.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMathVector.h"

class ExportedByTessellateCommon CATCGMTessellatePointIter
{
public:
  CATCGMTessellatePointIter();
  virtual ~CATCGMTessellatePointIter();

public:

  ///////////////////////////////////////
  // Best performance methods:
  ///////////////////////////////////////

  /**
   * Returns the number of computed points.
	 * @return
	 * The number of computed points.
   */
  virtual CATULONG32 GetNbPoint() const = 0;

  /**
   * Globally retrieves the Cartesian coordinates of all the points.
   * @param iCoordinates[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointXyzAll(float ioCoordinates[][3]) const = 0;

  /**
   * Globally retrieves the Cartesian coordinates of all the points.
   * @param iCoordinates[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointXyzAll(double ioCoordinates[][3]) const = 0;

  /**
   * Globally retrieves the normal at each point.
   * @param iNormals[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointNorAll(float ioNormals[][3]) const = 0;
  
  /**
   * Globally retrieves the normal at each point.
   * @param iNormals[][3]
   * The array of the coordinates. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointNorAll(double ioNormals[][3]) const = 0;
  
   /**
   * Globally retrieves the parameters of all the points (in case of a face or a surface).
   * @param iUv[][2]
   * The array of the parameters. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointUvAll(float ioUv[][2]) const = 0;
 
   /**
   * Globally retrieves the parameters of all the points (in case of a face or a surface).
   * @param iUv[][2]
   * The array of the parameters. The allocation has to be managed by
   * the caller: use </tt>GetNbPoint</tt> for its dimension.
	 * @return
   * S_OK on success or E_FAIL on failure.
   */
  virtual HRESULT GetPointUvAll(double ioUv[][2]) const = 0;


  ///////////////////////////////////////
  // Low performance methods:
  ///////////////////////////////////////

  /**
  * Returns the rank of the current point.
  * @return
  * The rank of the current point.
  */
  virtual CATULONG32 GetPointNu() const = 0;
  
  /**
   * Returns the Cartesian coordinates of the current point.
	 * @return
	 * The array of the Cartesian coordinates.
   */
  virtual double const * GetPointXyz() const = 0;
  
   /**
   * Retrieves a pointer to the normal at the current point.
	 * @param oNor
	 * The pointer to the normal.
   */
  virtual CATBoolean GetPointNor(CATMathVector const *& oNor) = 0;
 
   /**
   * Returns the parameters of the current point (in case of a face or a surface).
	 * @return
	 * The array of parameters.
   */
  virtual double const * GetPointUv() const = 0;

   /**
   * Skips to the next point.
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
