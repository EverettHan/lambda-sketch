// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATCSCone.h
// Header definition of CATCSCone
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2007  Creation:                     Ilia IVANOV
//===================================================================
#ifndef CATCSCone_H
#define CATCSCone_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a cone in three-dimensional space.
 */
class ExportedBySolverInterface CATCSCone : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSCone();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an apex.
   *   The second three ones define an axis direction.
   * @param iAngle
   *   An angle of the cone.
   */
  CATCSCone(const double iaCoord[6], double iAngle);

  virtual ~CATCSCone();

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
   * Retrieves coordinates of the cone apex.
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
   * Sets angle of the cone.
   * @param iAngle
   *   An angle of the cone.
   * @see #GetAngle
   */
  virtual void SetAngle(double iAngle);

  /**
   * Retrieves angle of the cone.
   * @return
   *   An angle of the cone.
   * @see #SetAngle
   */
  virtual double GetAngle();

private:
  double _aCoord[6];
  double _Angle;
};

//-----------------------------------------------------------------------

#endif
