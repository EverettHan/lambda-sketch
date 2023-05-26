// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSVertexCurvature.h
// Header definition of CATCSVertexCurvature
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2011  Creation:                  Roman Plotnikov
//===================================================================
#ifndef CATCSVertexCurvature_H
#define CATCSVertexCurvature_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomDimConstraint.h"

//-----------------------------------------------------------------------

/**
 * A constraint specifying curvature of a curve at its vertex.
 */
class ExportedBySolverInterface CATCSVertexCurvature : public CATCSGeomDimConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSVertexCurvature();

  virtual ~CATCSVertexCurvature();

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
   * Retrieves value of the curvature.
   * @param oCurvature
   *   A value of the curvature.
   * @see #SetCurvature
   */
  virtual void GetCurvature(double &oCurvature);

  /**
   * Sets value of the curvature.
   * @param iCurvature
   *   A value of the curvature.
   * @see #GetCurvature
   */
  virtual void SetCurvature(const double iCurvature);

  CATCDSInline double GetDimValue() const CATCDSOverride {return _Curvature;}

  CATCDSInline void SetDimValue(const double iValue) CATCDSOverride {SetCurvature(iValue);}

private:
  double _Curvature;
};

//-----------------------------------------------------------------------

#endif
