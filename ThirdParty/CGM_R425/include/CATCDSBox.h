// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCDSBox.h
// Header definition of CATCDSBox
//
//===================================================================
//
// Usage notes:
// Class representing a 3D box, parallel to the canonical axis.
//
//===================================================================
//
//  Jun 2011  Creation:                                         KUB
//===================================================================

#ifndef CATCDSBox_H
#define CATCDSBox_H

#include "CATCDSUtilities.h"
#include "CATCDS3Point.h"
#include "CATCDSBoolean.h"

class CATCDS3Vector;

class ExportedByCATCDSUtilities CATCDSBox
{

public:

  /**
  * default constructor
  */
  CATCDSBox();

  /**
 * Constructs a CATCDSBox from its extremities.
 *<br>No verification is performed.
 */

  CATCDSBox(double iXmin, double iYmin, double iZmin, double iXmax, double iYmax, double iZmax);

  /**
  * Constructs the union CATCDSBox from two CATCDSBox
  */

  CATCDSBox(CATCDSBox const &iBox1, CATCDSBox const &iBox2);

  /**
  * Copy Constructor.
  */
  CATCDSBox(const CATCDSBox &iBoxToCopy);

  CATCDSBox& operator=(const CATCDSBox &iBoxToCopy);

  /**
  * Destructor
  */
  virtual ~CATCDSBox();

  /**
  * Returns <tt>TRUE</tt> if <tt>this</tt> CATCDSBox is empty,
  */
  CATCDSBoolean IsEmpty();


  /**
  * Returns <tt>TRUE</tt> if <tt>this</tt> CATCDSBox is intersecting an another one,
  * with a given tolerance.
  *<br> Note that if the intersection is a point or a line, the
  * result is true.
  */
  CATCDSBoolean IsIntersecting(const CATCDSBox &iBox, double iTolerance = 0) const;

  /**
  * Returns <tt>TRUE</tt> if <tt>this</tt> CATMathBox2D is intersecting the line
  * (iP1,iv)
  *<br> Note that if the intersection is a point or a line, the
  * result is true.
  */
  virtual CATCDSBoolean IsIntersecting(const CATCDS3Point &iP1, const CATCDS3Vector &iv, double iAngularTolerance, double iLinearTolerance) const;

  /**
  * Returns <tt>TRUE</tt> if <tt>this</tt> CATCDSBox is containing a CATCDS3Point.
  */
  virtual CATCDSBoolean IsContaining(const CATCDS3Point &iPoint, double iTolerance) const;

  /**
  * Merge with box (creates the minimal box that includes the current box and the parameter)
  */
  void Merge(CATCDSBox const &iBox);

  /**
  * Creates the minimal box that includes the current box and the point
  */
  void AddPoint(CATCDS3Point const &iPoint);

  /**
  * Get box coordinates
  */
  void GetCoordinates(double& oXmin, double& oYmin, double& oZmin, double& oXmax, double& oYmax, double& oZmax) const;

  /**
  * Get box size
  */
  double Size() const;

  CATCDS3Point const & GetMinCorner() const;
  CATCDS3Point const & GetMaxCorner() const;

  CATCDSBox& operator+=(CATCDS3Vector const &iVector);
  CATCDSBox& operator-=(CATCDS3Vector const &iVector);

protected:
  CATCDS3Point _min, _max;
  CATCDSBoolean _Empty;
};

inline CATCDS3Point const & CATCDSBox::GetMinCorner() const
{
  return _min;
}

inline CATCDS3Point const & CATCDSBox::GetMaxCorner() const
{
  return _max;
}

inline CATCDSBox operator+(CATCDSBox const &iBox, CATCDS3Vector const &iVector)
{
  CATCDSBox box(iBox);
  box += iVector;
  return box;
}

inline CATCDSBox operator-(CATCDSBox const &iBox, CATCDS3Vector const &iVector)
{
  CATCDSBox box(iBox);
  box -= iVector;
  return box;
}

#endif
