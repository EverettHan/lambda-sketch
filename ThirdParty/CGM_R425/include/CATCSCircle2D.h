// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSCircle2D.h
// Header definition of CATCSCircle2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSCircle2D_H
#define CATCSCircle2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSCircle.h"

class CATCSSketch;
class CATCDSBox;

//-----------------------------------------------------------------------

/**
 * A geometry representing a circle in two-dimensional space.
 */
class ExportedBySolverInterface CATCSCircle2D: public CATCSCircle
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSCircle2D();

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iaCoord
   *   An array of coordinates of the circle center.
   * @param iRadius
   *   A radius of the circle.
   */
  CATCSCircle2D(CATCSSketch *ipSketch, const double iaCoord[2], double iRadius);

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iX
   *   x coordinate of the circle center.
   * @param iY
   *   y coordinate of the circle center.
   * @param iRadius
   *   A radius of the circle.
   */
  CATCSCircle2D(CATCSSketch *ipSketch, double iX, double iY, double iRadius);

  virtual ~CATCSCircle2D();

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
   * Retrieves coordinates of the circle center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetCenter2D(double &oX, double &oY);

  /**
   * Retrieves coordinates of the circle center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void SetCenter2D(double iX, double iY);

  /**
   * Retrieves coordinates of the circle center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
   * Retrieves coordinates of the circle normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ) CATCDSOverride;

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

  /**
  * Evaluate the curve point or/and derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oaPoint
  *    Evaluated coordinates (no evaluation is done if null)
  * @param oaFirstDeriv
  *    Evaluated first derivative (no evaluation is done if null)
  * @param oaSecondDeriv
  *    Evaluated second derivative (no evaluation is done if null)
  * @param oaThirdDeriv
  *    Evaluated third derivative (no evaluation is done if null)
  */
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0) CATCDSOverride;
/**
  * Evaluate the circle point or/and derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oaPoint
  *    Evaluated coordinates (no evaluation is done if null)
  * @param oaFirstDeriv
  *    Evaluated first derivative (no evaluation is done if null)
  * @param oaSecondDeriv
  *    Evaluated second derivative (no evaluation is done if null)
  * @param oaThirdDeriv
  *    Evaluated third derivative (no evaluation is done if null)
  */
  virtual void Evaluate(double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv = 0) CATCDSOverride;

private:
  double _aCoord[2];

};

//-----------------------------------------------------------------------

#endif
