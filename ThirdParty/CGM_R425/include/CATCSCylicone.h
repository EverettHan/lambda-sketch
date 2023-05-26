// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSCylicone.h
// Header definition of CATCSCylicone
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2009  Creation:             Andrey KHARITONCHIK
//===================================================================
#ifndef CATCSCylicone_H
#define CATCSCylicone_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing an object which can be transformed in cylinder or
 * cone in three-dimensional space.
 */
class ExportedBySolverInterface CATCSCylicone : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSCylicone();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an axis
   *   origin. The second three ones define an axis direction.
   * @param iRadius
   *   A radius of the cylicone.
   * @param iAngle
   *   An angle of the cylicone.
   */
  CATCSCylicone(const double iaCoord[6], double iRadius, double iAngle);

  virtual ~CATCSCylicone();

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
   * Sets radius of the cylicone.
   * @param iRadius
   *   A radius of the cylicone.
   * @see #GetRadius
   */
  virtual void SetRadius(double iRadius);

  /**
   * Sets angle of the cylicone.
   * @param iAngle
   *   An angle of the cylicone.
   * @see #GetAngle
   */
  virtual void SetAngle(double iAngle);

  /**
   * Retrieves radius of the cylicone.
   * @return
   *   A radius of the cylicone.
   * @see #SetRadius
   */
  virtual double GetRadius();

  /**
   * Retrieves angle of the cylicone.
   * @return
   *   An angle of the cylicone.
   * @see #SetAngle
   */
  virtual double GetAngle();

private:
  double _aCoord[6];
  double _Radius;
  double _Angle;
};

//-----------------------------------------------------------------------

#endif
