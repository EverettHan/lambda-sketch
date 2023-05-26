/* -*-C++-*-*/
#ifndef CATImplicitCanonics_H
#define CATImplicitCanonics_H

#include "SFTypes.h"
#include "GMScalarFieldsOperators.h"
#include "CATListOfDouble.h"
#include "CATTPMSType.h"
#include "DSYString.h"
#include "CATTolerance.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathTransformation.h"

#include "CATCGMStreamVersion.h"
#include "CATCGMVersionDefinition.h"

class ExportedByGMScalarFieldsOperators CATImplicitCanonics
  {
  public :

  /**
   * Convenience method to build the expression of a solid Cube of specified side length at the specified
   * position.
   *
   * @param iCenter, addre of 3 floats
   * @param iSideLength
   * @param the expression to be filled with the one of a cube
   *
   * @return S_OK if everything went fine.
   */
  static HRESULT Cube(const double* iCenter,  const double iSideLength, SF::SFExpression& oExpression);

  /**
   * Convenience method to build the expression of a solid Sphere of specified radius and center.
   *
   * @param iCenter, addre of 3 floats
   * @param iRadius
   * @param the expression to be filled with the one of a sphere
   *
   * @return S_OK if everything went fine.
   */
  static HRESULT Sphere(const double* iCenter, const double iRadius, SF::SFExpression& oExpression);

  /**
   *
   */
  static HRESULT TestCylinder(SF::SFExpression& oExpression);

  /**
   *
   */
  static HRESULT TestGyroid(SF::SFExpression& oExpression);
  private:

  };

#endif // CATImplicitCanonics_H
