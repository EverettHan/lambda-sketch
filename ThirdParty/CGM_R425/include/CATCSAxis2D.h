// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSAxis2D.h
// Header definition of CATCSAxis2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSAxis2D_H
#define CATCSAxis2D_H

#include "CATCDS.h"
#include "CATCSAxis.h"
#include "CATCDSVirtual.h"

class CATCSSketch;

//-----------------------------------------------------------------------

/**
 * A geometry representing an axis in three-dimensional space.
 */
class ExportedBySolverInterface CATCSAxis2D : public CATCSAxis
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSAxis2D();

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first two coordinates define an origin.
   *   The next four define directions of vectors.
   */
  CATCSAxis2D(CATCSSketch *ipSketch, const double iaCoord[6]);

  virtual ~CATCSAxis2D();

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
   * Retrieves coordinates of the axis origin.
   * @param oX
   *   Abscissa of the origin.
   * @param oY
   *   Ordinate of the origin.
   */
  virtual void GetOrigin2D(double &oX, double &oY) const;

  virtual void SetOrigin2D(double iX, double iY);

  /**
   * Retrieves coordinates of the axis origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
   * Retrieves coordinates of the axis vectors.
   * @param oX1
   *   An abscissa of the first vector.
   * @param oY1
   *   An ordinate of the first vector.
   * @param oX2
   *   An abscissa of the second vector.
   * @param oY2
   *   An ordinate of the second vector.
   */
  virtual void GetVectors2D(double &oX1, double &oY1, double &oX2, double &oY2) const;

  virtual void SetVectors2D(double iX1, double iY1, double iX2, double iY2);

  /**
   * Retrieves coordinates of the axis vectors.
   * @param oX1
   *   An abscissa of the first vector.
   * @param oY1
   *   An ordinate of the first vector.
   * @param oZ1
   *   An applicate of the first vector.
   * @param oX2
   *   An abscissa of the second vector.
   * @param oY2
   *   An ordinate of the second vector.
   * @param oZ2
   *   An applicate of the second vector.
   * @param oX3
   *   An abscissa of the third vector.
   * @param oY3
   *   An ordinate of the third vector.
   * @param oZ3
   *   An applicate of the third vector.
   */
  virtual void GetVectors(double &oX1, double &oY1, double &oZ1, double &oX2, double &oY2, double &oZ2, double &oX3, double &oY3, double &oZ3) CATCDSOverride;

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

private:
  double _aCoord[6];
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSAxis2D, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
