// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSimpleJoint.h
// Header definition of CATCSSimpleJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSSimpleJoint_H
#define CATCSSimpleJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSRigidSet;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSSimpleJoint : public CATCSJoint
{
public:
  CATCSSimpleJoint();
  virtual ~CATCSSimpleJoint();
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  //virtual void GetRigidSets(CATCSRigidSet *& opRigidSet1, CATCSRigidSet *& opRigidSet2);
  virtual void GetGeometries(CATCSGeometryLeaf *& opGeom1, CATCSGeometryLeaf *& opGeom2, CATCSGeometryLeaf *& opGeom3);
  
  /**
   * Checks whether an argument is leading.
   * @param iArgIdx
   *   An index of the argument.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the argument is leading,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   * @see #SetArgLeading
   */
  virtual CATCDSBoolean IsArgLeading(int iArgIdx);

  /**
   * Sets leading status of an argument.
   * @param iArgIdx
   *   An index of the argument.
   * @param iLeading
   *   <ul>
   *     <li><tt>TRUE</tt> - if the argument is leading,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   * @see #IsArgLeading
   */
  virtual void SetArgLeading(int iArgIdx, CATCDSBoolean iLeading);

  /**
   * @nodoc for internal use only
   */
  virtual void SetGeometries(CATCSGeometryLeaf *ipGeom1, CATCSGeometryLeaf *ipGeom2, CATCSGeometryLeaf *ipGeom3);
  virtual CATCDSBoolean GetOwnsVariables() const CATCDSOverride;

protected:
  CATCDSBoolean _bOwnsVariables;
  //CATCSRigidSet *_pRigidSet1, *_pRigidSet2;
  CATCSGeometryLeaf *_pGeom1, *_pGeom2, *_pGeom3;
  CATCDSBoolean _aIsArgLeading[3];
};

//-----------------------------------------------------------------------

#endif
