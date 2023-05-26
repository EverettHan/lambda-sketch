// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSCylinder.h
// Header definition of CATCSCylinder
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2004  Creation:             Konstantin Kucheryavy
//===================================================================
#ifndef CATCSCylinder_H
#define CATCSCylinder_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a cylinder in three-dimensional space.
 */
class ExportedBySolverInterface CATCSCylinder : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSCylinder();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an axis
   *   origin. The second three ones define an axis direction.
   * @param iRadius
   *   A radius of the cylinder.
   */
  CATCSCylinder(const double iaCoord[6], double iRadius);

  /**
   * Constructs an instance of the geometry.
   * @param iX
   *   x coordinate of cylinder origin.
   * @param iY
   *   y coordinate of cylinder origin.
   * @param iZ
   *   z coordinate of cylinder origin.
   * @param iDX
   *   x coordinate of cylinder direction.
   * @param iDY
   *   y coordinate of cylinder direction.
   * @param iDZ
   *   z coordinate of cylinder direction.
   * @param iRadius
   *   A radius of the cylinder.
   */
  CATCSCylinder(double iX, double iY, double iZ, double iDX, double iDY, double iDZ, double iRadius);

  virtual ~CATCSCylinder();

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
   *   A matrix representing a rotation in three-dimensional space.
   * @param iTranslation
   *   A vector representing a translation in three-dimensional space.
   */
  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Retrieves coordinates of the axis origin.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisOrigin(double &oX, double &oY, double &oZ);

  virtual void SetAxisOrigin(double iX, double iY, double iZ);

  /**
   * Retrieves coordinates of the axis direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetAxisDirection(double &oX, double &oY, double &oZ);

  virtual void SetAxisDirection(double iX, double iY, double iZ);

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

  /**
   * Sets radius of the cylinder.
   * @param iRadius
   *   A radius of the cylinder.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius);

  /**
   * Retrieves radius of the cylinder.
   * @return
   *   A radius of the cylinder.
   * @see #SetRadius
   */
  virtual double GetRadius();

private:
  double _aCoord[6];
  double _Radius;
};

//-----------------------------------------------------------------------

#endif
