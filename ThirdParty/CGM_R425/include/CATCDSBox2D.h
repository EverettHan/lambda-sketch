// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCDSBox2D2D.h
// Header definition of CATCDSBox2D2D
//
//===================================================================
//
// Usage notes:
// Class representing a 2D box, parallel to the canonical axis.
//
//===================================================================
//
//  Jun 2011  Creation:                                         KUB
//===================================================================

#ifndef CATCDSBox2D_H
#define CATCDSBox2D_H
#include "CATCDSVirtual.h"
#include "SolverUtilities.h"

#include "CATCDSBoolean.h"
#include "CATCDSBox.h"

class CATCDS3Vector;
class CATCDS3Point;


class ExportedBySolverUtilities CATCDSBox2D CATCDSFinal : public CATCDSBox
{

public:

  /**
  * default constructor
  */
  CATCDSBox2D();

  /**
 * Constructs a CATCDSBox2D from its extremities.
 *<br>No verification is performed.
 */

  CATCDSBox2D(double iXmin, double iYmin, double iXmax, double iYmax);

  /**
  * Copy Constructor.
  */
  CATCDSBox2D(const CATCDSBox2D &iBoxToCopy);
  
  CATCDSBox2D& operator=(const CATCDSBox2D &iBoxToCopy);

  /**
  / Destructor
  */
  virtual ~CATCDSBox2D();


  /**
 * Returns <tt>TRUE</tt> if <tt>this</tt> CATCDSBox2D is intersecting an another one,
 * with a given tolerance.
 *<br> Note that if the intersection is a point or a line, the
 * result is true.
 */
  CATCDSBoolean IsIntersecting(const CATCDSBox2D &iBox, double iTolerance) const;

/**
 * Returns <tt>TRUE</tt> if <tt>this</tt> CATMathBox2D is intersecting the line
 * (iP1,iv)
 *<br> Note that if the intersection is a point or a line, the
 * result is true.
 * Z coordinates are supposed to be null
 */
  virtual CATCDSBoolean IsIntersecting(const CATCDS3Point &iP1, const CATCDS3Vector &iv, double iAngularTolerance, double iLinearTolerance) const CATCDSOverride;

/**
 * Returns <tt>TRUE</tt> if <tt>this</tt> CATCDSBox2D is containing a CATCDS3Point.
  * Z coordinates are supposed to be null
 */
  virtual CATCDSBoolean IsContaining(const CATCDS3Point &iPoint, double iTolerance) const CATCDSOverride;


};

#endif
