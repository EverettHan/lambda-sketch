// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATCSTorus.h
// Header definition of CATCSTorus
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2008  Creation:                     Ilia IVANOV
//===================================================================
#ifndef CATCSTorus_H
#define CATCSTorus_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a torus in three-dimensional space.
 */
class ExportedBySolverInterface CATCSTorus : public CATCSGeometryLeaf
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSTorus();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define a center.
   *   The second three ones define a normal.
   * @param iMajorRadius
   *   A major radius of the torus.
   * @param iMinorRadius
   *   A minor radius of the torus.
   */
  CATCSTorus(const double iaCoord[6], double iMajorRadius, double iMinorRadius);

  virtual ~CATCSTorus();

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
   * Retrieves coordinates of the torus center.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetCenter(double &oX, double &oY, double &oZ);

  virtual void SetCenter(double iX, double iY, double iZ);
  
  /**
   * Retrieves coordinates of the torus normal.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetNormal(double &oX, double &oY, double &oZ);

  virtual void SetNormal(double iX, double iY, double iZ);
  
  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

  /**
   * Sets major radius of the torus.
   * @param iRadius
   *   A major radius of the torus.
   * @see #GetMajorRadius
   */
  virtual void SetMajorRadius(double iRadius);

  /**
   * Sets minor radius of the torus.
   * @param iRadius
   *   A minor radius of the torus.
   * @see #GetMinorRadius
   */
  virtual void SetMinorRadius(double iRadius);

  /**
   * Retrieves major radius of the torus.
   * @return
   *   A major radius of the torus.
   * @see #SetMajorRadius
   */
  virtual double GetMajorRadius();

  /**
   * Retrieves minor radius of the torus.
   * @return
   *   A minor radius of the torus.
   * @see #SetMinorRadius
   */
  virtual double GetMinorRadius();

private:
  double _aCoord[6];
  double _MajorRadius;
  double _MinorRadius;
};

//-----------------------------------------------------------------------

#endif
