// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSLine2D.h
// Header definition of CATCSLine2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSLine2D_H
#define CATCSLine2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSLine.h"

class CATCSSketch;

//-----------------------------------------------------------------------

/**
 * A geometry representing a line in two-dimensional space.
 */
class ExportedBySolverInterface CATCSLine2D : public CATCSLine
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSLine2D();

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first two coordinates define an origin.
   *   The second two ones define a direction.
   */
  CATCSLine2D(CATCSSketch *ipSketch, const double iaCoord[4]);

  /**
   * Constructs an instance of the geometry.
   * @param ipSketch
   *   A sketch of the geometry.
   * @param iX
   *   x coordinate of the origin.
   * @param iY
   *   y coordinate of the origin.
   * @param iDX
   *   x coordinate of the direction.
   * @param iDY
   *   y coordinate of the direction.
   */
  CATCSLine2D(CATCSSketch *ipSketch, double iX, double iY, double iDX, double iDY);

  virtual ~CATCSLine2D();

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
   * Retrieves coordinates of the line origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetOrigin2D(double &oX, double &oY);

  virtual void SetOrigin2D(double iX, double iY);

  /**
   * Retrieves coordinates of the line origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
   * Retrieves coordinates of the line direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   */
  virtual void GetDirection2D(double &oX, double &oY);

  virtual void SetDirection2D(double iX, double iY);

  /**
   * Retrieves coordinates of the line direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ) CATCDSOverride;

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to four for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[4]) CATCDSOverride;

  /**
  * Evaluate the line point or/and derivative at given parameter's value
  * @param iT
  *    Evaluation parameter. If the origin is O and the direction vector is V, then the parameter of point M is the scalar product OM.V
  * @param oaPoint
  *    Evaluated coordinates (no evaluation is done if null)
  * @param oaFirstDeriv
  *    Evaluated first derivative (no evaluation is done if null), returns direction vector V
  * @param oaSecondDeriv
  *    Evaluated second derivative (no evaluation is done if null), returns a null vector
  * @param oaThirdDeriv
  *    Evaluated third derivative (no evaluation is done if null), returns a null vector
  */
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0) CATCDSOverride ;

  /**
  * Evaluate the line point or/and derivative at given parameter's value
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
  double _aCoord[4];
};

//-----------------------------------------------------------------------

#endif
