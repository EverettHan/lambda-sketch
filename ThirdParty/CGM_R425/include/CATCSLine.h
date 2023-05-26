// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCSLine.h
// Header definition of CATCSLine
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSLine_H
#define CATCSLine_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSMonoParametric.h"

//-----------------------------------------------------------------------

/**
 * A geometry representing a line in three-dimensional space.
 */
class ExportedBySolverInterface CATCSLine : public CATCSMonoParametric
{
public:
  /**
   * Constructs an instance of the geometry.
   */
  CATCSLine();

  /**
   * Constructs an instance of the geometry.
   * @param iaCoord
   *   An array of coordinates. The first three coordinates define an origin.
   *   The second three ones define a direction.
   */
  CATCSLine(const double iaCoord[6]);
  
  /**
   * Constructs an instance of the geometry.
   * @param iX
   *   x coordinate of line origin.
   * @param iY
   *   y coordinate of line origin.
   * @param iZ
   *   z coordinate of line origin.
   * @param iDX
   *   x coordinate of line direction.
   * @param iDY
   *   y coordinate of line direction.
   * @param iDZ
   *   z coordinate of line direction.
   */
  CATCSLine(double iX, double iY, double iZ, double iDX, double iDY, double iDZ);

  virtual ~CATCSLine();

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
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   */
  virtual CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

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
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetOrigin(double &oX, double &oY, double &oZ);

  virtual void SetOrigin(double iX, double iY, double iZ);

  /**
   * Retrieves coordinates of the line direction.
   * @param oX
   *   An abscissa axis.
   * @param oY
   *   An ordinate axis.
   * @param oZ
   *   An applicate axis.
   */
  virtual void GetDirection(double &oX, double &oY, double &oZ);

  virtual void SetDirection(double iX, double iY, double iZ);

  /**
   * Updates coordinates of the geometry. Length of the array depends on the
   * geometry type. It is equal to six for this geometry.
   * @param iaCoord
   *   An array of coordinates.
   */
  virtual void UpdateCoordinates(const double iaCoord[6]) CATCDSOverride;

  /**
   * Compute line length between two parameters
   * @param iStart
   *    Start parameter
   * @param iEnd
   *    End parameter
   * @param oLength
   *    Computed length
   * @return
   *    FALSE if computation failed
   */
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  /**
  * Compute curve curvature at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvature
  *    Computed curvature
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvature(double iT, double &oCurvature) CATCDSOverride;

  /**
  * Compute curve curvature derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvatureDeriv
  *    Computed curvature deriv
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvatureDeriv(double iT, double &oCurvatureDeriv) CATCDSOverride;

private:
  double _aCoord[6];
};

//-----------------------------------------------------------------------

#endif
