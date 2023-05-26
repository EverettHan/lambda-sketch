#ifndef CATICDSJoint_H
#define CATICDSJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSConstraint.h"

class CATICDSAxis;

/**
 * Joint is a type of constraint which connects two or more rigid geometries.
 * Generally all allowed degrees of freedom are connected with variables. Thus
 * it is possible to control movement between the geometries.
 */
class ExportedByCDSInterface CATICDSJoint : public CATICDSConstraint
{
public:
  virtual ~CATICDSJoint() {}
};

#endif
