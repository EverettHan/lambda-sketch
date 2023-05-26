// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSSimpleJoint2D.h
// Header definition of CATCSSimpleJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSSimpleJoint2D_H
#define CATCSSimpleJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSRigidSet;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSSimpleJoint2D : public CATCSJoint
{
public:
  CATCSSimpleJoint2D();
  virtual ~CATCSSimpleJoint2D();
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void GetGeometries(CATCSGeometryLeaf *& opGeom1, CATCSGeometryLeaf *& opGeom2, CATCSGeometryLeaf *& opGeom3);
  
  /**
   * @nodoc for internal use only
   */
  virtual void SetGeometries(CATCSGeometryLeaf *ipGeom1, CATCSGeometryLeaf *ipGeom2, CATCSGeometryLeaf *ipGeom3);
  virtual CATCDSBoolean GetOwnsVariables() const CATCDSOverride;

protected:
  CATCDSBoolean _bOwnsVariables;
  CATCSGeometryLeaf *_pGeom1, *_pGeom2, *_pGeom3;
};

//-----------------------------------------------------------------------

#endif
