//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//=============================================================================
//
// CATPolyBodySolidOrientationChecker
//
// Check surfaces orientation consistency of a solid (geometrically and topologically)
// closed polyhedral body
//
//=============================================================================
// 2014-10-21 JXO: New.
//=============================================================================
#ifndef CATPolyBodySolidOrientationChecker_H
#define CATPolyBodySolidOrientationChecker_H

#include "CATPolyBoundingVolumeOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolyBody;
class CATTolerance;

/**
 * This class checks surfaces orientation consistency of a solid (geometrically and topologically)
 * closed polyhedral body. Surfaces should point outward.
 */

class ExportedByCATPolyBoundingVolumeOperators CATPolyBodySolidOrientationChecker
{

public:
  /** Constructor 
   *  @param iTolerance
   *         Tolerance to be used for computations
   */
  CATPolyBodySolidOrientationChecker(const CATTolerance & iTolerance);
  /** Destructor */
  ~CATPolyBodySolidOrientationChecker();

public:

/** @name Main Method
    @{ */

  /**
   * Checks surfaces orientation
   * @param iBody
   *        Poly body to check. It should be geometrically and topologically closed.
   *        If not, result may be unpredictable. 
   * @param nbtries
   *        DEPRECATED. Not used.
   * @return
   *         S_OK: surfaces are correctly oriented (they point outward)
   *         S_FALSE: One or more surface is not correctly oriented
   *         E_FAIL: Something failed
   */
  HRESULT Run(const CATPolyBody& iBody, int nbtries = 1) const;

  /** @} */

private:
  const CATTolerance & m_tol;

};

#endif // !CATPolyBodySolidOrientationChecker_H
