// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSPoint2D.h
// Header definition of CATCSPoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSPoint2D_H
#define CATCSPoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSPoint.h"

class CATCSSketch;

//-----------------------------------------------------------------------

/**
 * A geometry representing a point in two-dimensional space.
 */
class ExportedBySolverInterface CATCSPoint2D : public CATCSPoint
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSPoint2D();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  CATCSPoint2D(const double iaCoord[2]);

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iX
   *   x coordinate.
   * @param iY
   *   y coordinate.
   */
  CATCSPoint2D(CATCSSketch *ipSketch, double iX, double iY);

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  CATCSPoint2D(CATCSSketch *ipSketch, const double iaCoord[2]);

  virtual ~CATCSPoint2D();

  /**
   * Retrieves type of the geometry.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the geometry is matched to a specific type. The geometry
   * can be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Applies an affine transformation to the geometry.
   * @param iMatrix
   *   A matrix containing a rotation in two-dimensional space as 2x2
   *   submatrix and a translation at the last column. The last row of the
   *   matrix is dummy.
   */
  virtual void ApplyTransformation2D(double iMatrix[3][3]);

  /**
   * Applies an affine transformation to the geometry.
   * @param iMatrix
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Retrieves coordinates of the geometry.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetCoord2D(double &oX, double &oY);

  virtual void SetCoord2D(double iX, double iY);

  /**
   * Retrieves coordinates of the geometry.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCoord(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to two for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[2]) CATCDSOverride;

   /**
  * Get a bounding box for the geometry (AABB type)
  * @param oBox
  *   the bounding box
  */
  virtual void GetBoundingBox(CATCDSBox *& oBox) CATCDSOverride;

private:
  double _aCoord[2];
};

//-----------------------------------------------------------------------

#endif
