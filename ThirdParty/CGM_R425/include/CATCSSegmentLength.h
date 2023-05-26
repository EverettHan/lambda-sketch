// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCSSegmentLength.h
// Header definition of CATCSSegmentLength
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Apr 2010  Creation:              Andrey KHARITONCHIK
//===================================================================
#ifndef CATCSSegmentLength_H
#define CATCSSegmentLength_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

class CATCSGeometry;

//-----------------------------------------------------------------------

/**
 * A constraint specifying length of a geometry segment.
 */
class ExportedBySolverInterface CATCSSegmentLength : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSSegmentLength();

  virtual ~CATCSSegmentLength();

  /**
   * Retrieves type of the constraint.
   * @return
   *   Type of the geometry.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
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
   * Retrieves value of the length.
   * @param oLength
   *   A value of the length.
   * @see #SetLength
   */
  virtual void GetLength(double &oLength);

  /**
   * Sets value of the length.
   * @param iLength
   *   A value of the length.
   * @see #GetLength
   */
  virtual void SetLength(const double iLength);

  /**
   * Retrieves direction. The direction has to be represented by a line.
   * @return
   *   A pointer to the direction.
   * @see #SetDirection
   */
  virtual CATCSGeometry *GetDirection();

  /**
   * Sets direction. The direction has to be represented by a line.
   * @param ipDirection
   *   A pointer to the direction.
   * @see #GetDirection
   */
  virtual void SetDirection(CATCSGeometry *ipDirection);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Length;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetLength(iValue);}

private:
  double _Length;
  CATCSGeometry *_pDirection;
};

//-----------------------------------------------------------------------

#endif
